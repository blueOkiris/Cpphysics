#pragma once

#include <vector>
#include <Shapes.hpp>
#include <Vector.hpp>

namespace cpphysics {
    class Collision2 {
        private:
            Vector2<double> _center;
            std::vector<Vector2<double>> _polygon;
        
        public:
            Collision2(
                const Vector2<double> &center,
                const std::vector<Vector2<double>> &polygonPoints
            );
            bool collidesWith(const Collision2 &other) const;
            std::vector<Triangle2<double>> triangles() const;
    };
}
