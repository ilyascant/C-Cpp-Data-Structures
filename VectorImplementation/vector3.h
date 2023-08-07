#pragma once

struct Vector3 {
   public:
    float x = .0f, y = .0f, z = .0f;

    Vector3() = default;
    Vector3(float scaler)
        : x(scaler), y(scaler), z(scaler) {}
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z){};
    Vector3(const Vector3& other)
        : x(other.x), y(other.y), z(other.z) {}
    Vector3(const Vector3&& other)
        : x(other.x), y(other.y), z(other.z) {}

    Vector3& operator=(const Vector3& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    Vector3& operator=(Vector3&& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    ~Vector3() {}
};
