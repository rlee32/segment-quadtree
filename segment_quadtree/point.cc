#include "point.hh"

#include <cmath>

namespace segment_quadtree {

double Point::distance(const Point &other) const {
    auto dx = other.x_ - x_;
    auto dy = other.y_ - y_;
    return std::sqrt(dx * dx + dy * dy);
}

} // namespace segment_quadtree
