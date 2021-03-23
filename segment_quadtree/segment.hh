#pragma once

#include "point.hh"
#include "box.hh"

namespace segment_quadtree {

struct Segment {
public:
    // Constructs a segment from 2 points.
    Segment(const Point &a, const Point &b);

    // Returns true if this segment intersects with another segment.
    // If the segment is co-linear and overlapping, also returns true.
    bool intersects(const Segment &other) const;

    // Returns true if this segment intersects with the provided box, or
    // if the segment is inside the box.
    bool intersects(const Box &box) const;

    auto length() const { return length_; }

    Point a_;
    Point b_;

    // x and y change from a to b.
    double dx_{0};
    double dy_{0};

    double length_{0};

    // Performs a 2D cross product with the provided point (w.r.t. to a_) and b_ (w.r.t. to a_).
    double cross(const Point &point) const;
};

} // namespace segment_quadtree

