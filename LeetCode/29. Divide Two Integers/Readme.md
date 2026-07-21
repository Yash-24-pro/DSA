# 29. Divide Two Integers

**Platform:** LeetCode
**Difficulty:** 🔴 Medium
**Topics:** Math

---

## 🔗 Problem Link

https://leetcode.com/problems/divide-two-integers/

---

## 📝 Problem Summary

Given two integers `dividend` and `divisor`, divide the two numbers and return the quotient.

The quotient should be **truncated toward zero**. If the result exceeds the 32-bit signed integer range, return `INT_MAX`.

---

## 📌 Examples

### Example 1

**Input:**

```text
dividend = 10, divisor = 3
```

**Output:**

```text
3
```

---

### Example 2

**Input:**

```text
dividend = 7, divisor = -3
```

**Output:**

```text
-2
```

---

## 📋 Constraints

* `-2³¹ <= dividend <= 2³¹ - 1`
* `-2³¹ <= divisor <= 2³¹ - 1`
* `divisor != 0`

---

## 💡 Approach

1. Check for the special overflow case where:

   * `dividend == INT_MIN`
   * `divisor == -1`
2. In this case, the result exceeds the maximum value of a 32-bit signed integer, so return `INT_MAX`.
3. Otherwise, perform normal integer division using the `/` operator.
4. Return the quotient.

> **Note:** This solution uses the division operator (`/`), which is **not allowed** according to the original problem statement. It is intended only to demonstrate the overflow handling logic.

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(1)`
* **Space Complexity:** `O(1)`

---

## 📚 What I Learned

* Integer overflow can occur when dividing `INT_MIN` by `-1`.
* The maximum value a 32-bit signed integer can store is `INT_MAX`.
* Special edge cases should be handled before performing arithmetic operations.
* Runtime errors can occur due to undefined behavior even when using built-in operators.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        else {
            int n = dividend / divisor;
            return n;
        }
    }
};
```
