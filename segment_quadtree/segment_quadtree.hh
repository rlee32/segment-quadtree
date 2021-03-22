#pragma once

#include "segment.hh"
#include "segment_node.hh"

#include <vector>

namespace segment_quadtree {

class SegmentQuadtree {
public:
    SegmentQuadtree(const std::vector<Segment> &segments);

private:
    const std::vector<Segment> &segments_;
    SegmentNode root_;

};

} // namespace segment_quadtree

