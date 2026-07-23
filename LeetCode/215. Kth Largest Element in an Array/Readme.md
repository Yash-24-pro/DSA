# 215. Kth Largest Element in an Array

## 📌 Platform
- **Platform:** LeetCode
- **Difficulty:** Medium
- **Topics:** Array, Sorting

---

## 🔗 Problem Link
https://leetcode.com/problems/kth-largest-element-in-an-array/

---

## 📝 Problem Summary

Given an integer array `nums` and an integer `k`, return the **kth largest element** in the array.

> **Note:** It is the kth largest element in the sorted order, **not** the kth distinct element.

---

## 📖 Examples

### Example 1
**Input**
```text
nums = [3,2,1,5,6,4], k = 2
```

**Output**
```text
5
```

**Explanation**

After sorting:

```text
[1,2,3,4,5,6]
```

The 2nd largest element is **5**.

---

### Example 2

**Input**

```text
nums = [3,2,3,1,2,4,5,5,6], k = 4
```

**Output**

```text
4
```

**Explanation**

After sorting:

```text
[1,2,2,3,3,4,5,5,6]
```

The 4th largest element is **4**.

---

## 🔒 Constraints

- `1 <= k <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

---

## 💡 Approach

### Sorting Approach

1. Sort the array in **ascending order**.
2. The kth largest element will be located at index:
   ```cpp
   nums.size() - k
   ```
3. Return the element at that index.

### Why this works?

After sorting in ascending order, the largest element is at the last index, the second largest is at the second last index, and so on. Therefore, the kth largest element is found at `n - k`, where `n` is the size of the array.

---

## ⏱ Complexity Analysis

| Operation | Complexity |
|-----------|------------|
| Sorting | **O(n log n)** |
| Accessing Answer | **O(1)** |
| **Overall** | **O(n log n)** |
| Space Complexity | **O(1)** *(Ignoring the sorting algorithm's internal stack space)* |

---

## 📚 What I Learned

- How sorting can simplify selection problems.
- Finding the kth largest element after sorting only requires indexing with `n - k`.
- Although sorting is easy to implement, it is not the most optimal solution for this problem.
- More efficient approaches include **Quickselect (O(n) average)** and **Heap (O(n log k))**.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
```



---
