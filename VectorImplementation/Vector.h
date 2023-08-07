#pragma once

template <typename T>
class Vector {
   private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;

    void ReAlloc(const size_t&& newCapacity) {
        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

        if (newCapacity < m_Size)
            m_Size = newCapacity;

        for (size_t i = 0; i < m_Size; i++)
            newBlock[i] = std::move(m_Data[i]);
        for (size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        ::operator delete(m_Data, m_Capacity * sizeof(T));

        m_Data = newBlock;
        m_Capacity = newCapacity;
    }

   public:
    Vector() {
        ReAlloc(2);
    }

    ~Vector() {
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    void Clear() {
        for (size_t i = 0; i < m_Size; i++) {
            m_Data[i].~T();
        }

        m_Size = 0;
    }

   public:
    void PushBack(const T& value) {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity * .5f);

        m_Data[m_Size++] = std::move(value);
    }

    void PushBack(T&& value) {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity * .5f);

        m_Data[m_Size++] = std::move(value);
    }

    template <typename... Args>
    T& EmplaceBack(Args... args) {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity * .5f);

        new (&m_Data[m_Size]) T(std::forward<Args>(args)...);

        return m_Data[m_Size++];
    }

    void PopBack() {
        if (m_Size > 0) {
            m_Size--;
            m_Data[m_Size].~T();
        }
    }

    size_t Size() const { return m_Size; }

    const T& operator[](size_t index) const {
        return m_Data[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vector) {
        for (size_t i = 0; i < vector.Size(); i++)
            os << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << ", " << std::endl;

        std::cout << std::endl;
        return os;
    }
};
