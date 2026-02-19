#pragma once
#include <math.h>
#include <cmath>

struct Vector3 {
    union {
        struct { float x; float y; float z; };
        float data[3];
    };

    inline Vector3() : x(0), y(0), z(0) {}
    inline Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    
    static inline Vector3 zero() { return Vector3(0, 0, 0); }
    static inline Vector3 One() { return Vector3(1, 1, 1); }
    
    static inline float Dot(Vector3 lhs, Vector3 rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    static inline float Magnitude(Vector3 v) {
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    static inline Vector3 Normalized(Vector3 v) {
        float mag = Magnitude(v);
        if (mag == 0) return Vector3::zero();
        return Vector3(v.x / mag, v.y / mag, v.z / mag);
    }

    static inline float Distance(Vector3 a, Vector3 b) {
        return Magnitude(a - b);
    }

    inline Vector3 operator+(const Vector3 rhs) const { 
        return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); 
    }
    inline Vector3 operator-(const Vector3 rhs) const { 
        return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); 
    }
    inline Vector3 operator*(const float rhs) const { 
        return Vector3(x * rhs, y * rhs, z * rhs); 
    }
    inline Vector3 operator/(const float rhs) const { 
        return Vector3(x / rhs, y / rhs, z / rhs); 
    }
    inline bool operator==(const Vector3 rhs) const { 
        return x == rhs.x && y == rhs.y && z == rhs.z; 
    }
    inline bool operator!=(const Vector3 rhs) const { 
        return !(*this == rhs); 
    }
};
