# 189. Rotate Array

**Platform:** LeetCode
**Difficulty:** 🟡 Medium
**Topics:** Array, Math, Two Pointers

---

## 🔗 Problem Link

https://leetcode.com/problems/rotate-array/

---

## 📝 Problem Summary

Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is a non-negative integer.

The rotation should be performed **in-place** using **O(1)** extra space.

---

## 💡 Examples

### Example 1

**Input**

```text
nums = [1,2,3,4,5,6,7], k = 3
```

**Output**

```text
[5,6,7,1,2,3,4]
```

**Explanation**

```text
Rotate 1 step: [7,1,2,3,4,5,6]
Rotate 2 steps: [6,7,1,2,3,4,5]
Rotate 3 steps: [5,6,7,1,2,3,4]
```

---

### Example 2

**Input**

```text
nums = [-1,-100,3,99], k = 2
```

**Output**

```text
[3,99,-1,-100]
```

**Explanation**

```text
Rotate 1 step: [99,-1,-100,3]
Rotate 2 steps: [3,99,-1,-100]
```

---

## 📌 Constraints

* `1 <= nums.length <= 10⁵`
* `-2³¹ <= nums[i] <= 2³¹ - 1`
* `0 <= k <= 10⁵`

---

## 🚀 Approach

Use the **Reversal Algorithm** to rotate the array in-place.

1. Compute the effective number of rotations using `k = k % n`.
2. Reverse the entire array.
3. Reverse the first `k` elements.
4. Reverse the remaining `n - k` elements.

Reversing the entire array brings the last `k` elements to the front (in reverse order). Reversing the first `k` elements restores their correct order, and reversing the remaining elements restores the order of the rest of the array.

---

## 📊 Complexity Analysis

| Complexity | Value    |
| ---------- | -------- |
| Time       | **O(n)** |
| Space      | **O(1)** |

---

## 🧠 What I Learned

* How to rotate an array efficiently without using an extra array.
* How the reversal algorithm converts a rotation problem into three simple reverse operations.
* Why `k % n` is necessary when `k` is greater than the array size.
* How helper functions improve code readability and eliminate repeated logic.
* How the two-pointer technique can reverse an array in-place with constant extra space.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};
```
