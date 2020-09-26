#include <Vector.hpp>
#include <Shapes.hpp>

using namespace cpphysics;

template<typename T>
bool cpphysics::segmentsIntersect(
        const Vector2<T> &p1, const Vector2<T> &p2,
        const Vector2<T> &p3, const Vector2<T> &p4) {
    double denominator =
        (p4.y - p3.y) * (p2.x - p1.x)
        - (p4.x - p3.x) * (p2.y - p1.y);
    
    // parallel lines
    if(denominator == 0) {
        return false;
    }

    float uA =
        ((p4.x - p3.x) * (p1.y - p3.y) - (p4.y - p3.y) * (p1.x - p3.x))
        / denominator;
    float uB =
        ((p2.x - p1.x) * (p1.y - p3.y) - (p2.y - p1.y) * (p1.x - p3.x))
        / denominator;
    if(uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
        return true;
    }

    return false;
}

template<typename T>
Rect2<T>::Rect2(const Vector2<T> &tl, const Vector2<T> &tr) {
    topLeft = tl;
    bottomRight = tr;
}

template<typename T>
bool Rect2<T>::intersects(const Rect2<T> &other) const {
    if(topLeft.x() > other.bottomRight.x()) {
        return false;
    } else if(other.topLeft.x() > bottomRight.x()) {
        return false;
    } else if(topLeft.y() > other.bottomRight.y()) {
        return false;
    } else if(other.topLeft.y() > other.bottomRight.y()) {
        return false;
    }

    return true;
}

template<typename T>
Triangle2<T>::Triangle2(
        const Vector2<T> &p1,
        const Vector2<T> &p2,
        const Vector2<T> &p3) {
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
}

template<typename T>
bool Triangle2<T>::contains(const Vector2<T> &point) const {
    double denominator =
        (points[1].y - points[2].y) * (points[0].x - points[2].x)
        + (points[2].x - points[1].x) * (points[0].y - points[2].y);
    double a =
        ((points[1].y - points[2].y) * (point.x - points[2].x)
        + (points[2].x - points[1].x) * (point.y - points[2].y)) / denominator;
    double b =
        ((points[2].y - points[0].y) * (point.x - points[2].x)
        + (points[0].x - points[2].x) * (point.y - points[2].y)) / denominator;
    double c = 1 - a - b;
    if(a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1) {
        return true;
    }
    return false;
}

template<typename T>
bool Triangle2<T>::intersects(const Triangle2<T> &other) const {
    const Rect2<T> boundingBox(
        Vector2<T>(
            min(points[0].x, min(points[1].x, points[2].x)),
            min(points[0].y, min(points[1].y, points[2].y))
        ), Vector2<T>(
            max(points[0].x, max(points[1].x, points[2].x)),
            max(points[0].y, max(points[1].y, points[2].y))
        )
    );
    const Rect2<T> otherBoundingBox(
        Vector2<T>(
            min(other.points[0].x, min(other.points[1].x, other.points[2].x)),
            min(other.points[0].y, min(other.points[1].y, other.points[2].y))
        ), Vector2<T>(
            max(other.points[0].x, max(other.points[1].x, other.points[2].x)),
            max(other.points[0].y, max(other.points[1].y, other.points[2].y))
        )
    );
    if(!boundingBox.intersects(otherBoundingBox)) {
        return false;
    }
    
    const Vector2<T> lineSegments[3][2] = {
        { points[0], points[1] },
        { points[1], points[2] },
        { points[2], points[0] }
    };
    const Vector2<T> otherLineSegments[3][2] = {
        { other.points[0], other.points[1] },
        { other.points[1], other.points[2] },
        { other.points[2], other.points[0] }
    };
    for(const auto &lineSegment : lineSegments) {
        for(const auto &otherLineSegment : otherLineSegments) {
            if(segmentsIntersect(
                    lineSegment[0], lineSegment[1],
                    otherLineSegment[0], otherLineSegment[1])) {
                return true;
            }
        }
    }

    if(other.contains(points[0])) {
        return true;
    } else if(contains(other.points[0])) {
        return true;
    }

    return false;   
}
