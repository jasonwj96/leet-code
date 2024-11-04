#include <iostream>
#include <vector>
#include "default_header.h"

int main() {
  std::vector nums{1, 2, 2, 3, 1};
  std::cout << Solution::findShortestSubArray(nums);

  return 0;
}
