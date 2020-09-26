#pragma once

#include <Vector.hpp>

namespace cpphysics {
    template<typename T>
    bool segmentsIntersect(
        const Vector2<T> &p1, const Vector2<T> &p2,
        const Vector2<T> &p3, const Vector2<T> &p4
    );

    template<typename T>
    struct Rect2 {
        Vector2<T> topLeft;
        Vector2<T> bottomRight;
        Rect2(const Vector2<T> &tl, const Vector2<T> &tr);
        bool intersects(const Rect2<T> &other) const;
    };
    
    template<typename T>
    struct Triangle2 {
        Vector2<T> points[3];
        Triangle2(
            const Vector2<T> &p1, const Vector2<T> &p2, const Vector2<T> &p3
        );
        bool contains(const Vector2<T> &point) const;
        bool intersects(const Triangle2<T> &other) const;
    };
}
