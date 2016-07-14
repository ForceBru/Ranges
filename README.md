# Ranges
Smart ranges for C++11 range-for loops.

##How to use

First do `#include "Ranges.hpp"` and `using Range;`.

 1. Loop forward
  
   ```
   for (const auto& i: 0_r, 9) /* [0, 9) */
       std::cout << i << ' ';
   ```
   
   Output: `0 1 2 3 4 5 6 7 8 `
 2. Loop backward

   ```
   for (const auto& i: 9_r, 0) /* [9, 0) */
       std::cout << i << ' ';
   ```
   
   Output: `9 8 7 6 5 4 3 2 1 `
 3. Use negative numbers
 
   ```
   for (const auto& i: -9_r, 0) /* [-9, 0) */
       std::cout << i << ' ';
   ```
   
   Output: `-9 -8 -7 -6 -5 -4 -3 -2 -1 `
 4. Use steps
   ```
   for (const int& i: 0_r, 9, 2) /* [0, 2, ..., 8] */
       cout << i << ' ';
   ```
   
   Output: `0 2 4 6 8 `
   
##Syntax
```
for (const int& i: start, stop, step)

    // is almost the same as
    
for (int i = start; i < stop; i += step)

```

 1. `start` - any number to start from. Must be followed by `_r`: `-2_r`, `0_r`, `2_r`.
 2. `stop` - any number to stop at (will never be included in the output).
 3. `step` (optional) - any number added to `start` at each iteration.
 
You can also create a standalone range object: 
```
Range<int> a = (1_r, 6);
Range<long> b = (1_r, 6, 2);
```

You may also use `auto` instead of `Range<type>`, of course.
