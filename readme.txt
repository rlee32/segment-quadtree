C++ implementation of a quadtree that holds line segments.

Segments are essentially discretized into quadtree nodes. A simple rule is employed to guide discretization to a depth that is neither too fine nor too coarse:
No quadrant shall have more than 1 leaf node that contains more than 1 segment.

This rule allows for coarse discretization around segment intersections.

This is meant to be a lib, and the executable here is just usage example.

Implementation notes:
1. To keep it simple, only 'double' is used for floating-point values, and only 'int' is used for integers.

