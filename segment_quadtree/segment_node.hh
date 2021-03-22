#pragma once

#include "box.hh"

#include <algorithm>
#include <array>
#include <memory>
#include <vector>

namespace segment_quadtree {

class SegmentNode {
public:
    SegmentNode(const Box &box);

private:
    // Children are ordered ccw by quadrant:
    // 0: +x, +y
    // 1: -x, +y
    // 2: -x, -y
    // 3: +x, -y
    std::array<std::unique_ptr<SegmentNode>, 4> children_;

    // IDs of segments in this node. Only leaf nodes may hold segments.
    std::vector<int> segments_;

    // Box representing physical coverage of this node.
    const Box box_;
};

} // namespace segment_quadtree
