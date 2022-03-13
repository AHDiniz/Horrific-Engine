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

typedef struct vector2i
{
    union
    {
        struct
        {
            int x, y;
        };
        int data[2];
    };
} Vector2i;

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

typedef struct vector3i
{
    union
    {
        struct
        {
            int x, y, z;
        };
        int data[3];
    };
} Vector3i;

typedef struct vector4
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        float data[4];
    };
} Vector4;

typedef struct vector4i
{
    union
    {
        struct
        {
            int x, y, z, w;
        };
        int data[4];
    };
} Vector4i;

typedef struct vector4ui
{
    union
    {
        struct
        {
            unsigned int x, y, z, w;
        };
        unsigned int data[4];
    };
} Vector4ui;

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

inline float Angle(const Vector2 &a, const Vector2 &b)
{
    float sla = SquaredLength(a);
    float slb = SquaredLength(b);

    if (sla <= EPSILON || slb <= EPSILON)
        return .0f;
    
    float dot = a * b;
    float len = sqrtf(sla) * sqrtf(slb);
    return acosf(dot / len);
}

inline Vector2 Projection(const Vector2 &a, const Vector2 &b)
{
    Vector2 p;
    p.x = 0;
    p.y = 0;
    float lenB = Length(b);
    if (lenB <= EPSILON)
        return p;
    float scale = (a * b) / lenB;
    return b * scale;
}

inline Vector2 Rejection(const Vector2 &a, const Vector2 &b)
{
    Vector2 p = Projection(a, b);
    return a - p;
}

inline Vector2 Reflection(const Vector2 &a, const Vector2 &b)
{
    Vector2 r;
    r.x = r.y = 0;
    float lenB = Length(b);
    if (lenB <= EPSILON)
        return r;
    float scale = (a * b) / lenB;
    Vector2 p2 = b * (scale * 2);
    r = a - p2;
    return r;
}

inline Vector2 Lerp(const Vector2 &a, const Vector2 &b, const float t)
{
    Vector2 l;
    l.x = a.x + (b.x - a.x) * t;
    l.y = a.y + (b.y - a.y) * t;
    return l;
}

inline Vector2 Slerp(const Vector2 &a, const Vector2 &b, const float t)
{
    if (t < .01f)
        return Lerp(a, b, t);
    
    Vector2 from = Normalized(a);
    Vector2 to = Normalized(b);

    float theta = Angle(from, to);
    float sinTheta = sinf(theta);

    float a = sinf((1.0f - t) * theta) / sinTheta;
    float b = sinf(t * theta) / sinTheta;

    return from * a + to * b;
}

inline Vector2 NormalLerp(const Vector2 &a, const Vector2 &b, const float t)
{
    return Normalized(Lerp(a, b, t));
}

inline bool operator == (const Vector2 &a, const Vector2 &b)
{
    Vector2 diff = a - b;
    return Length(diff) <= EPSILON;
}

inline bool operator != (const Vector2 &a, const Vector2 &b)
{
    return !(a == b);
}

inline Vector2i operator + (const Vector2i &a, const Vector2i &b)
{
    Vector2i s;
    for (int i = 0; i < 2; ++i)
        s.data[i] = a.data[i] + b.data[i];
    return s;
}

inline Vector2i operator - (const Vector2i &a, const Vector2i &b)
{
    Vector2i s;
    for (int i = 0; i < 2; ++i)
        s.data[i] = a.data[i] + b.data[i];
    return s;
}

inline Vector2i operator * (const Vector2i &a, const int c)
{
    Vector2i s;
    for (int i = 0; i < 2; ++i)
        s.data[i] = a.data[i] * c;
    return s;
}

inline Vector2i operator * (const int c, const Vector2i &a)
{
    return a * c;
}

inline int operator * (const Vector2i &a, const Vector2i &b)
{
    int d = 0;
    for (int i = 0; i < 2; ++i)
        d += a.data[i] * b.data[i];
    return d;
}

inline Vector2i NonUniformMultiply(const Vector2i &a, const Vector2i &b)
{
    Vector2i m;
    for (int i = 0; i < 2; ++i)
        m.data[i] = a.data[i] * b.data[i];
    return m;
}

inline int SquaredLength(const Vector2i &a)
{
    int l = 0;
    for (int i = 0; i < 2; ++i)
        l += a.data[i] * a.data[i];
    return l;
}

inline int Length(const Vector2i &a)
{
    int sl = 0;
    for (int i = 0; i < 2; ++i)
        sl += a.data[i] * a.data[i];
    return (int)sqrtf(sl);
}

inline void Normalize(Vector2i &a)
{
    int sl = SquaredLength(a);
    if (sl == 0)
        return;
    int il = 1 / (int)sqrtf(sl);
    for (int i = 0; i < 2; ++i)
        a.data[i] *= il;
}

inline Vector2i Normal(const Vector2i &a)
{
    Vector2i n;
    for (int i = 0; i < 2; ++i)
        n.data[i] = a.data[i];
    Normalize(n);
    return n;
}

inline bool operator == (const Vector2i &a, const Vector2i &b)
{
    Vector2i diff = a - b;
    return Length(diff) == 0;
}

inline bool operator != (const Vector2i &a, const Vector2i &b)
{
    return !(a == b);
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

inline float Angle(const Vector3 &a, const Vector3 &b)
{
    float sla = SquaredLength(a);
    float slb = SquaredLength(b);

    if (sla <= EPSILON || slb <= EPSILON)
        return .0f;
    
    float dot = a * b;
    float len = sqrtf(sla) * sqrtf(slb);
    return acosf(dot / len);
}

inline Vector3 Projection(const Vector3 &a, const Vector3 &b)
{
    Vector3 p;
    p.x = 0;
    p.y = 0;
    p.z = 0;
    float lenB = Length(b);
    if (lenB <= EPSILON)
        return p;
    float scale = (a * b) / lenB;
    return b * scale;
}

inline Vector3 Rejection(const Vector3 &a, const Vector3 &b)
{
    Vector3 p = Projection(a, b);
    return a - p;
}

inline Vector3 Cross(const Vector3 &a, const Vector3 &b)
{
    Vector3 c;
    c.x = a.y * b.z - a.z * b.y;
    c.y = a.x * b.z - a.z * b.x;
    c.z = a.x * b.y - a.y * b.x;
    return c;
}

inline Vector3 Lerp(const Vector3 &a, const Vector3 &b, const float t)
{
    Vector3 l;
    l.x = a.x + (b.x - a.x) * t;
    l.y = a.y + (b.y - a.y) * t;
    l.z = a.z + (b.z - a.z) * t;
    return l;
}

inline Vector3 Slerp(const Vector3 &a, const Vector3 &b, const float t)
{
    if (t < .01f)
        return Lerp(a, b, t);
    
    Vector3 from = Normalized(a);
    Vector3 to = Normalized(b);

    float theta = Angle(from, to);
    float sinTheta = sinf(theta);

    float a = sinf((1.0f - t) * theta) / sinTheta;
    float b = sinf(t * theta) / sinTheta;

    return from * a + to * b;
}

inline Vector3 NormalLerp(const Vector3 &a, const Vector3 &b, const float t)
{
    return Normalized(Lerp(a, b, t));
}

inline bool operator == (const Vector3 &a, const Vector3 &b)
{
    Vector3 diff = a - b;
    return Length(diff) <= EPSILON;
}

inline bool operator != (const Vector3 &a, const Vector3 &b)
{
    return !(a == b);
}

inline Vector3i operator + (const Vector3i &a, const Vector3i &b)
{
    Vector3i s;
    for (int i = 0; i < 3; ++i)
        s.data[i] = a.data[i] + b.data[i];
    return s;
}

inline Vector3i operator - (const Vector3i &a, const Vector3i &b)
{
    Vector3i s;
    for (int i = 0; i < 3; ++i)
        s.data[i] = a.data[i] - b.data[i];
    return s;
}

inline Vector3i operator * (const Vector3i &a, const int c)
{
    Vector3i s;
    for (int i = 0; i < 3; ++i)
        s.data[i] = a.data[i] * c;
    return s;
}

inline Vector3i operator * (const int c, const Vector3i &a)
{
    return a * c;
}

inline int operator * (const Vector3i &a, const Vector3i &b)
{
    int d = 0;
    for (int i = 0; i < 3; ++i)
        d += a.data[i] * b.data[i];
    return d;
}

inline Vector3i NonUniformMultiply(const Vector3i &a, const Vector3i &b)
{
    Vector3i m;
    for (int i = 0; i < 3; ++i)
        m.data[i] = a.data[i] * b.data[i];
    return m;
}

inline int SquaredLength(const Vector3i &a)
{
    int sl = 0;
    for (int i = 0; i < 3; ++i)
        sl += a.data[i] * a.data[i];
    return sl;
}

inline int Length(const Vector3i &a)
{
    int sl = 0;
    for (int i = 0; i < 3; ++i)
        sl += a.data[i] * a.data[i];
    return (int)sqrtf(sl);
}

inline void Normalize(Vector3i &a)
{
    int l = Length(a);
    if (l == 0)
        return;
    int il = 1 / l;
    for (int i = 0; i < 3; ++i)
        a.data[i] *= il;
}

inline Vector3i Normal(const Vector3i &a)
{
    Vector3i n;
    for (int i = 0; i < 3; ++i)
        n.data[i] = a.data[i];
    Normalize(n);
    return n;
}

inline bool operator == (const Vector3i &a, const Vector3i &b)
{
    Vector3i diff = a - b;
    return Length(diff) == 0;
}

inline bool operator != (const Vector3i &a, const Vector3i &b)
{
    return !(a == b);
}

inline Vector4 operator + (const Vector4 &a, const Vector4 &b)
{
    Vector4 s;
    for (int i = 0; i < 4; ++i)
        s.data[i] = a.data[i] + b.data[i];
    return s;
}

inline Vector4 operator - (const Vector4 &a, const Vector4 &b)
{
    Vector4 s;
    for (int i = 0; i < 4; ++i)
        s.data[i] = a.data[i] - b.data[i];
    return s;
}

inline Vector4 operator * (const Vector4 &a, const float c)
{
    Vector4 s;
    for (int i = 0; i < 4; ++i)
        s.data[i] = a.data[i] * c;
    return s;
}

inline Vector4 operator * (const float c, const Vector4 &a)
{
    return a * c;
}

inline float operator * (const Vector4 &a, const Vector4 &b)
{
    float d = 0;
    for (int i = 0; i < 4; ++i)
        d += a.data[i] * b.data[i];
    return d;
}

inline Vector4 NonUniformMultiply(const Vector4 &a, const Vector4 &b)
{
    Vector4 m;
    for (int i = 0; i < 4; ++i)
        m.data[i] = a.data[i] * b.data[i];
    return m;
}

inline float SquaredLength(const Vector4 &a)
{
    float l = 0;
    for (int i = 0; i < 4; ++i)
        l += a.data[i] * a.data[i];
    return l;
}

inline float Length(const Vector4 &a)
{
    float sl = 0;
    for (int i = 0; i < 4; ++i)
        sl += a.data[i] * a.data[i];
    if (sl <= EPSILON)
        return .0f;
    return sqrtf(sl);
}

inline void Normalize(Vector4 &a)
{
    float sl = SquaredLength(a);
    if (sl < EPSILON)
        return;
    float il = 1.0f / sqrtf(sl);
    for (int i = 0; i < 4; ++i)
        a.data[i] *= il;
}

inline Vector4 Normal(const Vector4 &a)
{
    Vector4 n;
    for (int i = 0; i < 4; ++i)
        n.data[i] = a.data[i];
    Normalize(n);
    return n;
}

inline float Angle(const Vector4 &a, const Vector4 &b)
{
    float sla = SquaredLength(a);
    float slb = SquaredLength(b);

    if (sla <= EPSILON || slb <= EPSILON)
        return .0f;
    
    float dot = a * b;
    float len = sqrtf(sla) * sqrtf(slb);
    return acosf(dot / len);
}

inline Vector4 Projection(const Vector4 &a, const Vector4 &b)
{
    Vector4 p;
    p.x = 0;
    p.y = 0;
    p.z = 0;
    p.w = 0;
    float lenB = Length(b);
    if (lenB <= EPSILON)
        return p;
    float scale = (a * b) / lenB;
    return b * scale;
}

inline Vector4 Rejection(const Vector4 &a, const Vector4 &b)
{
    Vector4 p = Projection(a, b);
    return a - p;
}

inline Vector4 Lerp(const Vector4 &a, const Vector4 &b, const float t)
{
    Vector4 l;
    l.x = a.x + (b.x - a.x) * t;
    l.y = a.y + (b.y - a.y) * t;
    l.z = a.z + (b.z - a.z) * t;
    l.w = a.w + (b.w - a.w) * t;
    return l;
}

inline Vector4 Slerp(const Vector4 &a, const Vector4 &b, const float t)
{
    if (t < .01f)
        return Lerp(a, b, t);
    
    Vector4 from = Normalized(a);
    Vector4 to = Normalized(b);

    float theta = Angle(from, to);
    float sinTheta = sinf(theta);

    float a = sinf((1.0f - t) * theta) / sinTheta;
    float b = sinf(t * theta) / sinTheta;

    return from * a + to * b;
}

inline Vector4 NormalLerp(const Vector4 &a, const Vector4 &b, const float t)
{
    return Normalized(Lerp(a, b, t));
}

inline bool operator == (const Vector4 &a, const Vector4 &b)
{
    Vector4 diff = a - b;
    return Length(diff) <= EPSILON;
}

inline bool operator != (const Vector4 &a, const Vector4 &b)
{
    return !(a == b);
}

inline Vector4i operator + (const Vector4i &a, const Vector4i &b)
{
    Vector4i s;
    for (int i = 0; i < 4; ++i)
        s.data[i] = a.data[i] + b.data[i];
    return s;
}

inline Vector4i operator - (const Vector4i &a, const Vector4i &b)
{
    Vector4i s;
    for (int i = 0; i < 4; ++i)
        s.data[i] = a.data[i] - b.data[i];
    return s;
}

inline Vector4i operator * (const Vector4i &a, const int c)
{
    Vector4i s;
    for (int i = 0; i < 4; ++i)
        s.data[i] = a.data[i] * c;
    return s;
}

inline Vector4i operator * (const int c, const Vector4i &a)
{
    return a * c;
}

inline int operator * (const Vector4i &a, const Vector4i &b)
{
    int d = 0;
    for (int i = 0; i < 4; ++i)
        d += a.data[i] * b.data[i];
    return d;
}

inline Vector4i NonUniformMultiply(const Vector4i &a, const Vector4i &b)
{
    Vector4i m;
    for (int i = 0; i < 4; ++i)
        m.data[i] = a.data[i] * b.data[i];
    return m;
}

inline int SquaredLength(const Vector4i &a)
{
    int sl = 0;
    for (int i = 0; i < 4; ++i)
        sl += a.data[i] * a.data[i];
    return sl;
}

inline int Length(const Vector4i &a)
{
    int sl = 0;
    for (int i = 0; i < 4; ++i)
        sl += a.data[i] * a.data[i];
    return (int)sqrtf(sl);
}

inline void Normalize(Vector4i &a)
{
    int l = Length(a);
    if (l == 0)
        return;
    int il = 1 / l;
    for (int i = 0; i < 4; ++i)
        a.data[i] *= il;
}

inline Vector4i Normal(const Vector4i &a)
{
    Vector4i n;
    for (int i = 0; i < 3; ++i)
        n.data[i] = a.data[i];
    Normalize(n);
    return n;
}

inline bool operator == (const Vector4i &a, const Vector4i &b)
{
    Vector4i diff = a - b;
    return Length(diff) == 0;
}

inline bool operator != (const Vector4i &a, const Vector4i &b)
{
    return !(a == b);
}

inline Vector4ui operator + (const Vector4ui &a, const Vector4ui &b)
{
    Vector4ui s;
    for (int i = 0; i < 4; ++i)
        s.data[i] = a.data[i] + b.data[i];
    return s;
}

inline Vector4ui operator - (const Vector4ui &a, const Vector4ui &b)
{
    Vector4ui s;
    for (int i = 0; i < 4; ++i)
        s.data[i] = a.data[i] - b.data[i];
    return s;
}

inline Vector4ui operator * (const Vector4ui &a, const int c)
{
    Vector4ui s;
    for (int i = 0; i < 4; ++i)
        s.data[i] = a.data[i] * c;
    return s;
}

inline Vector4ui operator * (const int c, const Vector4ui &a)
{
    return a * c;
}

inline unsigned int operator * (const Vector4ui &a, const Vector4ui &b)
{
    unsigned int d = 0;
    for (int i = 0; i < 4; ++i)
        d += a.data[i] * b.data[i];
    return d;
}

inline Vector4ui NonUniformMultiply(const Vector4ui &a, const Vector4ui &b)
{
    Vector4ui m;
    for (int i = 0; i < 4; ++i)
        m.data[i] = a.data[i] * b.data[i];
    return m;
}

inline unsigned int SquaredLength(const Vector4ui &a)
{
    unsigned int sl = 0;
    for (int i = 0; i < 4; ++i)
        sl += a.data[i] * a.data[i];
    return sl;
}

inline unsigned int Length(const Vector4ui &a)
{
    unsigned int sl = 0;
    for (int i = 0; i < 4; ++i)
        sl += a.data[i] * a.data[i];
    return (unsigned int)sqrtf(sl);
}

inline void Normalize(Vector4ui &a)
{
    unsigned int l = Length(a);
    if (l == 0)
        return;
    unsigned int il = 1 / l;
    for (int i = 0; i < 4; ++i)
        a.data[i] *= il;
}

inline Vector4ui Normal(const Vector4ui &a)
{
    Vector4ui n;
    for (int i = 0; i < 3; ++i)
        n.data[i] = a.data[i];
    Normalize(n);
    return n;
}

inline bool operator == (const Vector4ui &a, const Vector4ui &b)
{
    Vector4ui diff = a - b;
    return Length(diff) == 0;
}

inline bool operator != (const Vector4ui &a, const Vector4ui &b)
{
    return !(a == b);
}

#endif
