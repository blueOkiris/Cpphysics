#include <vector>
#include <Shapes.hpp>
#include <Vector.hpp>
#include <Collision.hpp>

using namespace cpphysics;

Collision2::Collision2(
            const Vector2<double> &center,
            const std::vector<Vector2<double>> &polygonPoints
        ) : _center(center), _polygon(polygonPoints) {
}

bool Collision2::collidesWith(const Collision2 &other) const {
    const auto otherTris = other.triangles();
    const auto tris = triangles();
    
    for(const auto &tri : tris) {
        for(const auto &otherTri : otherTris) {
            if(tri.intersects(otherTri)) {
                return true;
            }
        }
    }
    
    return false;
}

std::vector<Triangle2<double>> Collision2::triangles() const {
    std::vector<Triangle2<double>> tris;
    for(size_t ind = 0; ind < _polygon.size(); ind++) {
        if(ind + 1 == _polygon.size()) {
            tris.push_back(Triangle2(_center, _polygon[ind], _polygon[0]));
        } else {
            tris.push_back(
                Triangle2(_center, _polygon[ind], _polygon[ind + 1])
            );
        }
    }
    return tris;
}
