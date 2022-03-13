#ifndef MATH_H_

#define MATH_H_

#define EPSILON 0.000001f

#include "pch.h"

typedef struct vector2
{
    union
    {
        struct
        {
            float x, y;
        };
        float data[2];
    };
} Vector2;

typedef struct vector3
{
    union
    {
        struct
        {
            float x, y, z;
        };
        float data[3];
    };
} Vector3;

inline Vector2 operator + (const Vector2 &a, const Vector2 &b)
{
    Vector2 s;
    for (int i = 0; i < 2; ++i)
        s.data[i] = a.data[i] + b.data[i];
    return s;
}

inline Vector2 operator - (const Vector2 &a, const Vector2 &b)
{
    Vector2 s;
    for (int i = 0; i < 2; ++i)
        s.data[i] = a.data[i] + b.data[i];
    return s;
}

inline Vector2 operator * (const Vector2 &a, const float c)
{
    Vector2 s;
    for (int i = 0; i < 2; ++i)
        s.data[i] = a.data[i] * c;
    return s;
}

inline Vector2 operator * (const float c, const Vector2 &a)
{
    return a * c;
}

inline float operator * (const Vector2 &a, const Vector2 &b)
{
    float d = 0;
    for (int i = 0; i < 2; ++i)
        d += a.data[i] * b.data[i];
    return d;
}

inline Vector2 NonUniformMultiply(const Vector2 &a, const Vector2 &b)
{
    Vector2 m;
    for (int i = 0; i < 2; ++i)
        m.data[i] = a.data[i] * b.data[i];
    return m;
}

inline float SquaredLength(const Vector2 &a)
{
    float l = 0;
    for (int i = 0; i < 2; ++i)
        l += a.data[i] * a.data[i];
    return l;
}

inline float Length(const Vector2 &a)
{
    float sl = 0;
    for (int i = 0; i < 2; ++i)
        sl += a.data[i] * a.data[i];
    if (sl <= EPSILON)
        return .0f;
    return sqrtf(sl);
}

inline void Normalize(Vector2 &a)
{
    float sl = SquaredLength(a);
    if (sl < EPSILON)
        return;
    float il = 1.0f / sqrtf(sl);
    for (int i = 0; i < 2; ++i)
        a.data[i] *= il;
}

inline Vector2 Normal(const Vector2 &a)
{
    Vector2 n;
    for (int i = 0; i < 2; ++i)
        n.data[i] = a.data[i];
    Normalize(n);
    return n;
}

inline Vector3 operator + (const Vector3 &a, const Vector3 &b)
{
    Vector3 s;
    for (int i = 0; i < 3; ++i)
        s.data[i] = a.data[i] + b.data[i];
    return s;
}

inline Vector3 operator - (const Vector3 &a, const Vector3 &b)
{
    Vector3 s;
    for (int i = 0; i < 3; ++i)
        s.data[i] = a.data[i] - b.data[i];
    return s;
}

inline Vector3 operator * (const Vector3 &a, const float c)
{
    Vector3 s;
    for (int i = 0; i < 3; ++i)
        s.data[i] = a.data[i] * c;
    return s;
}

inline Vector3 operator * (const float c, const Vector3 &a)
{
    return a * c;
}

inline float operator * (const Vector3 &a, const Vector3 &b)
{
    float d = 0;
    for (int i = 0; i < 3; ++i)
        d += a.data[i] * b.data[i];
    return d;
}

inline Vector3 NonUniformMultiply(const Vector3 &a, const Vector3 &b)
{
    Vector3 m;
    for (int i = 0; i < 3; ++i)
        m.data[i] = a.data[i] * b.data[i];
    return m;
}

inline float SquaredLength(const Vector3 &a)
{
    float l = 0;
    for (int i = 0; i < 3; ++i)
        l += a.data[i] * a.data[i];
    return l;
}

inline float Length(const Vector3 &a)
{
    float sl = 0;
    for (int i = 0; i < 3; ++i)
        sl += a.data[i] * a.data[i];
    if (sl <= EPSILON)
        return .0f;
    return sqrtf(sl);
}

inline void Normalize(Vector3 &a)
{
    float sl = SquaredLength(a);
    if (sl < EPSILON)
        return;
    float il = 1.0f / sqrtf(sl);
    for (int i = 0; i < 3; ++i)
        a.data[i] *= il;
}

inline Vector3 Normal(const Vector3 &a)
{
    Vector3 n;
    for (int i = 0; i < 3; ++i)
        n.data[i] = a.data[i];
    Normalize(n);
    return n;
}

#endif
