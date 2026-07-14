# 7. Reverse Integer

**Platform:** LeetCode  
**Difficulty:** 🟡 Medium  
**Topics:** Math, Integer

---

## 🔗 Problem Link

https://leetcode.com/problems/reverse-integer/

---

## 📝 Problem Summary

Given a signed 32-bit integer `x`, return `x` with its digits reversed.

If reversing `x` causes the value to go outside the signed 32-bit integer range **[-2³¹, 2³¹ - 1]**, return `0`.

**Note:** You are not allowed to use any 64-bit integer type (`long long`).

---

## 💡 Examples

### Example 1

**Input**
```text
x = 123
```

**Output**
```text
321
```

---

### Example 2

**Input**
```text
x = -123
```

**Output**
```text
-321
```

---

### Example 3

**Input**
```text
x = 120
```

**Output**
```text
21
```

---

## 📌 Constraints

```text
-2³¹ <= x <= 2³¹ - 1
```

---

## 🚀 Approach

- Initialize an integer variable `rev` to store the reversed number.
- Traverse the digits of `x` until it becomes `0`.
- Extract the last digit using `% 10`.
- Remove the last digit using `/ 10`.
- Before appending the digit to `rev`, check whether `rev * 10 + digit` would overflow the 32-bit signed integer range.
- If overflow or underflow is detected, return `0`.
- Otherwise, append the digit and continue.
- Return the final reversed integer.

---

## 📊 Complexity Analysis

| Complexity | Value |
|------------|-------|
| **Time** | **O(log₁₀ n)** |
| **Space** | **O(1)** |

---

## 🧠 What I Learned

- How to reverse an integer digit by digit using modulo (`%`) and division (`/`).
- How to detect integer overflow **before** it occurs.
- Why `INT_MAX / 10` and `INT_MIN / 10` are used for overflow checking.
- How to solve the problem without using any 64-bit integer type.
- The importance of handling negative numbers without writing separate logic.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
                return 0;

            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
                return 0;

            rev = rev * 10 + digit;
        }

        return rev;
    }
};
```
