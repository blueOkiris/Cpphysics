#include <Collision.hpp>
#include <Body.hpp>

using namespace cpphysics;

Body2::Body2(std::vector<Collision2> collisions, double mass) :
        _collisions(collisions), _mass(mass) {
}
