# 628. Maximum Product of Three Numbers

## 📌 Platform
- **LeetCode**
- **Difficulty:** Easy
- **Topics:** Array, Sorting, Math

---

## 🔗 Problem Link

https://leetcode.com/problems/maximum-product-of-three-numbers/

---

## 📝 Problem Summary

Given an integer array `nums`, find the maximum possible product that can be obtained by multiplying any **three** numbers from the array.

The array may contain **negative numbers**, so simply choosing the three largest elements does not always produce the maximum product.

---

## 💡 Examples

### Example 1

**Input**
```text
nums = [1,2,3]
```

**Output**
```text
6
```

---

### Example 2

**Input**
```text
nums = [1,2,3,4]
```

**Output**
```text
24
```

---

### Example 3

**Input**
```text
nums = [-1,-2,-3]
```

**Output**
```text
-6
```

---

## 📋 Constraints

- `3 <= nums.length <= 10^4`
- `-1000 <= nums[i] <= 1000`

---

## 🚀 Approach

1. Sort the array in ascending order.
2. Compute two possible products:
   - Product of the **three largest** numbers.
   - Product of the **two smallest (most negative)** numbers and the **largest** number.
3. Return the maximum of these two values.

### Why does this work?

- The three largest positive numbers usually give the maximum product.
- However, if the array contains two very small negative numbers, their product becomes positive. Multiplying this positive value with the largest positive number may produce an even larger product.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n log n)` (Sorting the array)
- **Space Complexity:** `O(1)` (Ignoring sorting space)

---

## 📚 What I Learned

- Negative numbers can significantly affect the maximum product.
- While solving optimization problems involving multiplication, always consider how negative values interact.
- Sorting can simplify comparison between multiple candidate solutions.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int product1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int product2 = nums[0] * nums[1] * nums[n - 1];

        return max(product1, product2);
    }
};
```

---

## ✅ Key Takeaway

The maximum product can come from either:
- The **three largest numbers**, or
- The **two smallest (negative) numbers** together with the **largest positive number**.

Always compare both possibilities before returning the answer.
