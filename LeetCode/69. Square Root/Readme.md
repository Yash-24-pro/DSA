# 69. Sqrt(x)

## 📌 Platform

* **Platform:** LeetCode
* **Difficulty:** Easy
* **Topics:** Binary Search, Math

## 🔗 Problem Link

https://leetcode.com/problems/sqrtx/

---

## 📝 Problem Summary

Given a non-negative integer `x`, return the **square root of `x` rounded down to the nearest integer**.

You must not use any built-in exponent function or operator such as `sqrt()` or `pow()`.

For example:

* √4 = 2 → return `2`
* √8 ≈ 2.828 → return `2`

---

## 💡 Examples

### Example 1

**Input**

```text
x = 4
```

**Output**

```text
2
```

**Explanation**

The square root of `4` is `2`, so we return `2`.

---

### Example 2

**Input**

```text
x = 8
```

**Output**

```text
2
```

**Explanation**

The square root of `8` is approximately `2.828`, and since we round down to the nearest integer, `2` is returned.

---

## 📋 Constraints

* `0 <= x <= 2³¹ - 1`

---

## 🚀 Approach (Binary Search)

1. Use **Binary Search** to search for the square root between `1` and `x`.
2. Calculate the middle value using:

   ```cpp
   mid = low + (high - low) / 2;
   ```
3. Check whether `mid` can be the square root.
4. If `mid² <= x`, store `mid` as the possible answer and search in the **right half** for a larger value.
5. If `mid² > x`, search in the **left half**.
6. Return the largest value whose square is less than or equal to `x`.
7. To prevent integer overflow, use `mid <= x / mid` instead of `mid * mid <= x`.

---

## ⏱ Complexity Analysis

* **Time Complexity:** `O(log x)`
* **Space Complexity:** `O(1)`

---

## 📚 What I Learned

* Binary Search can be used to find an answer within a numerical range.
* `low + (high - low) / 2` is safer than `(low + high) / 2` because it prevents integer overflow.
* We can avoid multiplication overflow by comparing `mid <= x / mid`.
* When the exact square root does not exist, we need to return the **largest integer whose square is less than or equal to `x`**.

---

## 💻 Solution (C++)

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
