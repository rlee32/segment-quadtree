#pragma once

#include "segment.hh"
#include "segment_node.hh"

#include <vector>
#include <unordered_set>

namespace segment_quadtree {

class SegmentQuadtree {
public:
    SegmentQuadtree(const std::vector<Segment> &segments);

    // Performs various checks to validate construction of the quadtree. Throws if any checks fail.
    void validate();

private:
    const std::vector<Segment> &segments_;
    SegmentNode root_;

    // Impl of validate().
    void validate(const SegmentNode &node);

    // validation-related members.
    std::unordered_set<int> seen_segment_ids_;
    int node_count_{0};
    int max_residency_{0};
    int avg_residency_{0};
    int max_depth_{0};
    int leaves_{0};
};

} // namespace segment_quadtree


