#include <Vector.hpp>

using namespace cpphysics;

template<typename T>
Vector2<T>::Vector2(const T &x, const T &y) :
        _x(x), _y(y) {
}

template<typename T>
T Vector2<T>::x() const {
    return _x;
}

template<typename T>
T Vector2<T>::y() const {
    return _y;
}

template<typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T> &other) const {
    return Vector2<T>(_x + other.x(), _y + other.y());
}

template<typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T> &other) const {
    return Vector2<T>(_x - other.x(), _y - other.y());
}

template<typename T>
bool Vector2<T>::operator==(const Vector2<T> &other) const {
    return (_x == other.x()) && (_y == other.y());
}
