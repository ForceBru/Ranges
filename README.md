# Ranges
Smart ranges for C++11 range-for loops.

##How to use

First do `#include "Ranges.hpp"` and `using Range;`.

 1. Loop forward
  
   ```
   for (const auto& i: 0_r, 9_r) /* [0, 9) */
       std::cout << i << ' ';
   ```
   
   Output: `0 1 2 3 4 5 6 7 8 `
 2. Loop backward

   ```
   for (const auto& i: 9_r, 0_r) /* [9, 0) */
       std::cout << i << ' ';
   ```
   
   Output: `9 8 7 6 5 4 3 2 1 `
 3. Use negative numbers
 
   ```
   for (const auto& i: -9_r, 0_r) /* [-9, 0) */
       std::cout << i << ' ';
   ```
   
   Output: `-9 -8 -7 -6 -5 -4 -3 -2 -1 `
   
   
As you can see, a range is constructed with the following syntax: `(begin, end)` (parentheses are optional in some cases) and can be iterated over with the range-for loop. You can also create a standalone range object: `auto a = (1_r, 6_r);`.

In order to use a number as a beginning or an end of a range, add the `_r` suffix to it: `6_r` or `-5_r` or `0_r`.
