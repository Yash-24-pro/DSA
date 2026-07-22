# 169. Majority Element

## 📌 Platform
- **Platform:** LeetCode
- **Difficulty:** Easy
- **Topics:** Array, Hash Table, Divide and Conquer, Sorting, Counting

## 🔗 Problem Link
https://leetcode.com/problems/majority-element/

---

## 📝 Problem Summary

Given an integer array `nums` of size `n`, return the **majority element**.

The majority element is the element that appears **more than ⌊n / 2⌋ times** in the array.

It is guaranteed that the majority element always exists.

---

## 💡 Examples

### Example 1
**Input**
```text
nums = [3,2,3]
```

**Output**
```text
3
```

---

### Example 2

**Input**
```text
nums = [2,2,1,1,1,2,2]
```

**Output**
```text
2
```

---

## 📋 Constraints

- `n == nums.length`
- `1 <= n <= 5 × 10⁴`
- `-10⁹ <= nums[i] <= 10⁹`
- The majority element always exists.

---

## 🚀 Approach (Sorting)

1. Sort the given array.
2. Since the majority element appears more than half the time, it will always occupy the middle position after sorting.
3. Return the element at index `n / 2`.

---

## ⏱ Complexity Analysis

- **Time Complexity:** `O(n log n)` (Sorting)
- **Space Complexity:** `O(1)` *(Ignoring the internal space used by `sort()`)*

---

## 📚 What I Learned

- A majority element occupying more than half of the array must always appear at the middle index after sorting.
- `std::sort()` in C++ uses **Introsort**, which provides efficient `O(n log n)` performance.
- There can be multiple approaches to solve the same problem, each with different time complexities.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
```



