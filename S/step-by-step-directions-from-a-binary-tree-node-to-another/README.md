# Step-By-Step Directions From a Binary Tree Node to Another
## Solutions 

### LCA + DFS
#### Time Complexity: O(n)
The `dfs` method is called twice, once for the start node and once for the
destination node. Each call may traverse the entire tree in the worst case
(skewed tree), making the time complexity 2 * O(n), which simplifies to 
O(n).

#### Space Complexity: O(n)
The recursive call stack of the `dfs` method can have a space complexity
of O(n) in the worst case. The variables `startPath`, `destinationPath`, 
`startToCommonAncestor` and `commonAncestorToDest` can each have a length
equal to the height of the tree, which is n in the worst case (skewed tree).
Thus, the total space complexity of the algorithm is 5 * O(n), which 
simplifies to O(n).
