#include "segment.hh"

#include <cmath>

namespace segment_quadtree {

namespace {

// Returns true if value is zero or close to zero.
bool is_zero(double value) {
    return std::abs(value) <= 1e-10;
}

// Returns true if a and b are both positive or both negative.
// Returns false if a or b are zero.
bool same_sign(double a, double b) {
    return (a > 0 and b > 0) or (a < 0 and b < 0);
}

} // namespace


Segment::Segment(const Point &a, const Point &b)
    : a_(a)
    , b_(b)
    , dx_(b.x_ - a.x_)
    , dy_(b.y_ - a.y_)
    , length_(std::sqrt(dx_ * dx_ + dy_ * dy_)) {
}

bool Segment::intersects(const Segment &other) const {
    // First check cross w.r.t. this segment.
    auto cross_a = cross(other.a_);
    if (is_zero(cross_a)) {
        return true;
    }
    auto cross_b = cross(other.b_);
    if (is_zero(cross_b)) {
        return true;
    }
    if (same_sign(cross_a, cross_b)) {
        return false;
    }

    // Now check cross w.r.t. other segment.
    cross_a = other.cross(a_);
    if (is_zero(cross_a)) {
        return true;
    }
    cross_b = other.cross(b_);
    if (is_zero(cross_b)) {
        return true;
    }
    return not same_sign(cross_a, cross_b);
}

double Segment::cross(const Point &point) const {
    auto dx = point.x_ - a_.x_;
    auto dy = point.y_ - a_.y_;
    return dx * dy_ - dy * dx_;
}


} // namespace segment_quadtree
