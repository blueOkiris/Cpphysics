#pragma once

#include <vector>
#include <Collision.hpp>

namespace cpphysics {
    class Body2 {
        private:
            std::vector<Collision2> _collisions;
            double _mass;
        
        public:
            Body2(std::vector<Collision2> collisions, double mass);
    };
}