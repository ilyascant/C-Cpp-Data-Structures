#include <iostream>

template<typename T>
class Vector
{

public:
    Vector()
    {
        ReAlloc(2);
    }
    
    ~Vector()
    {
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }


    void PushBack(const T& value)
    {
        if(m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity * .5f);

        m_Data[m_Size++] = value;
    }

    void PushBack(T&& value)
    {
        if(m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity * .5f);
            
        // std::move -> Returns an rvalue reference to arg.
        m_Data[m_Size++] = std::move(value);
    }
    
    template<typename... Args>
    T& EmplaceBack(Args&&... args)
    {
         if(m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity * .5f);
            
        // std::forward -> Returns an rvalue if arg is not an lvalue 
        // OR Returns an lvalue
        // https://stackoverflow.com/questions/28828159/usage-of-stdforward-vs-stdmove
        // m_Data[m_Size] = T(std::forward<Args>(args)...);
        
        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
        
        return m_Data[m_Size++];
    }

    size_t Size() const
    {
        return m_Size;
    }
    
    void PopBack()
    {
        if(m_Size > 0)
        {
            m_Size--;
            m_Data[m_Size].~T();
        }
    }
    
    void Clear()
    {
        for(size_t i = 0; i < m_Size; i++)
        {
            m_Data[i].~T();
        }
        
        m_Size = 0;
    }

private:
    void ReAlloc(const size_t&& newCapacity)
    {
        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

        if(newCapacity < m_Size)
            m_Size = newCapacity;


        for(size_t i = 0; i < m_Size; i++)
            newBlock[i] = std::move(m_Data[i]);

        for(size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        ::operator delete(m_Data, m_Capacity * sizeof(T));
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }

private:
    T* m_Data = nullptr;

    size_t m_Size = 0;
    size_t m_Capacity = 0;

public:
    const T& operator[](size_t index) const
    {
        return m_Data[index];
    }

    T& operator[](size_t index)
    {
        return m_Data[index];
    }

};

struct Vector3 {
    float x = 0.f, y = 0.f, z = 0.f;

    Vector3() {};
    Vector3(float scaler) :
        x(scaler), y(scaler), z(scaler) {};
    Vector3(float x, float y, float z) :
        x(x), y(y), z(z) {};

    Vector3(const Vector3& other):
        x(other.x), y(other.y), z(other.z){};

    Vector3(Vector3&& other):
        x(other.x), y(other.y), z(other.z){};


    ~Vector3(){};

    Vector3& operator=(const Vector3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    Vector3& operator=(Vector3&& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vector)
{
    for(size_t i = 0; i < vector.Size(); i++)
        os << vector[i] << std::endl;

    std::cout << std::endl;

    return os;
};

template<>
std::ostream& operator<<(std::ostream& os, const Vector<Vector3>& vector)
{
    for(size_t i = 0; i < vector.Size(); i++)
        os << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << ", " << std::endl;

    std::cout << std::endl;

    return os;
};



int main()
{
    Vector<Vector3> vector;

    vector.PushBack(Vector3());
    vector.PushBack(Vector3(3.f));
    vector.PushBack(Vector3(4.f, 6.f, 9.f));
    
    vector.EmplaceBack<>();
    vector.PopBack();
    vector.EmplaceBack<float>(5.f);
    vector.EmplaceBack<float>(1.f, 4.f, 3.f);

    // vector.Clear();
    std::cout << vector;

    return 0;
}