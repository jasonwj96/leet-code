#pragma once

#include <vector>

class Solution {
  static void print_vector(std::vector<int> &stones);

public:
  static int lastStoneWeight(std::vector<int> &stones);

  static int findShortestSubArray(std::vector<int> &nums);
};
