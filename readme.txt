C++ implementation of a quadtree that holds line segments.

Segments are essentially discretized into quadtree nodes.
To facilitate efficient discretization, a 'split threshold' is used, which serves as a trigger for subdividing a node, and is currently implemented as a compile-time constant.
A quadtree node will not be split if the number of segments contained in that node is less than or equal to the split threshold.
If three segments converged to a point and the split threshold is 2, the intersection will propagate until the maximum quadtree depth.
Therefore too many occurences of intersections between more lines that the split threshold can result in a quadtree with more nodes than necessary.
As split threshold increases, less quadtree nodes are generated, but search queries may become less efficient, as search queries may return more segments than with a lower split threshold.
Generally one should seek to minimize the split threshold, but high enough to prevent excessive quadtree nodes.
For a set of segments where no intersections are expected, split threshold of 1 could be a good choice.
For a set of segments that represents a cycle with no crossings between segments (a graph where each node has a degree of 2, e.g. 2-optimal TSP tour), a minimum split threshold of 2 should be used.

This is meant to be a lib, and the executable here is just usage example.

Implementation notes:
1. To keep it simple, only 'double' is used for floating-point values, and only 'int' is used for integers.

