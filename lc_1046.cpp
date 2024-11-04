#include <iostream>
#include <vector>
#include "default_header.h"

#include <queue>

/*

1046. Last Stone Weight

You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash
them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.


Example 1:

Input: stones = [2,7,4,1,8,1]

Output: 1

Explanation:
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.

Example 2:

Input: stones = [1]
Output: 1

Constraints:

1 <= stones.length <= 30
1 <= stones[i] <= 1000
 *
 */

void Solution::print_vector(std::vector<int> &stones) {
  std::cout << "[";

  for (const int &stone: stones) {
    std::cout << stone << ",";
  }

  std::cout << "]" << std::endl;
}

int Solution::lastStoneWeight(std::vector<int> &stones) {
  print_vector(stones);

  // Create a max heap (using a priority queue with negative values)
  std::priority_queue<int> max_heap(stones.begin(), stones.end());

  // While there is more than one stone
  while (max_heap.size() > 1) {
    // Take the two heaviest stones
    const int stone1 = max_heap.top();
    max_heap.pop();

    const int stone2 = max_heap.top();
    max_heap.pop();

    // If the stones have different weights, push the difference back
    if (stone1 != stone2) {
      max_heap.push(stone1 - stone2);
    }
    // If stone1 == stone2, both stones are destroyed
  }

  // If there is one stone left, return its weight, otherwise return 0
  return max_heap.empty() ? 0 : max_heap.top();
}
