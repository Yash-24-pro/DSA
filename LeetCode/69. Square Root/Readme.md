# 69. Sqrt(x)

## Platform

LeetCode

## Difficulty

Easy

## Topics

Binary Search

## Problem Link

https://leetcode.com/problems/sqrtx/

## Problem Summary

Given a non-negative integer `x`, return the square root of `x` rounded down to the nearest integer.

Built-in square root or exponent functions such as `sqrt()` or `pow()` cannot be used.

## Examples

### Example 1

**Input:**

```text
x = 4
```

**Output:**

```text
2
```

### Example 2

**Input:**

```text
x = 8
```

**Output:**

```text
2
```

**Explanation:**
√8 ≈ 2.828, and rounding down gives `2`.

## Constraints

* `0 <= x <= 2³¹ - 1`

## Approach

Use **Binary Search** to find the largest integer `mid` such that:

```text
mid × mid <= x
```

1. Set `low = 1` and `high = x`.
2. Calculate the middle value using:

   ```cpp
   mid = low + (high - low) / 2;
   ```
3. If `mid <= x / mid`, then `mid² <= x`, so `mid` can be the answer. Store it and search the right half.
4. Otherwise, `mid` is too large, so search the left half.
5. Return the stored answer.

`mid <= x / mid` is used instead of `mid * mid <= x` to avoid integer overflow.

## Complexity Analysis

* **Time Complexity:** `O(log x)`
* **Space Complexity:** `O(1)`

## What I Learned

* How to apply binary search to problems where the answer lies within a numerical range.
* Why `low + (high - low) / 2` is safer than `(low + high) / 2`.
* How to avoid integer overflow using division instead of multiplication.
* How to find the floor of a square root without using built-in functions.

## Solution

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;

        int low = 1;
        int high = x;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid <= x / mid) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
```
