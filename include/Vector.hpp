#pragma once

namespace cpphysics {
    template<typename T>
    class Vector2 {
        private:
            T _x, _y;
            
        public:
            Vector2(const T &x, const T &y);
            
            T x() const;
            T y() const;

            Vector2<T> operator+(const Vector2<T> &other) const;
            Vector2<T> operator-(const Vector2<T> &other) const;
            bool operator==(const Vector2<T> &other) const;
    };
}
