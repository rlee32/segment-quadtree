#include "segment_quadtree.hh"

#include <algorithm>

namespace segment_quadtree {

namespace {

Box get_box(const std::vector<Segment> &segments) {
    double xmin{segments[0].a_.x_};
    double ymin{segments[0].a_.y_};
    double xmax{segments[0].a_.x_};
    double ymax{segments[0].a_.y_};
    for (const auto &s : segments) {
        for (const auto &p : {s.a_, s.b_}) {
            xmin = std::min(xmin, p.x_);
            ymin = std::min(ymin, p.y_);
            xmax = std::max(xmax, p.x_);
            ymax = std::max(ymax, p.y_);
        }
    }
    constexpr double FUDGE{1e-6}; // small padding to ensure all point fall within root node box.
    return Box({xmin - FUDGE, ymin - FUDGE}, {xmax + FUDGE, ymax + FUDGE});
}

} // namespace

SegmentQuadtree::SegmentQuadtree(const std::vector<Segment> &segments)
    : segments_(segments)
    , root_(get_box(segments_)) {
}

} // namespace segment_quadtree
