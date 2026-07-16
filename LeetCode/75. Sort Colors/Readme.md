# 75. Sort Colors

**Platform:** LeetCode
**Difficulty:** 🟡 Medium
**Topics:** Array, Two Pointers, Sorting

## 🔗 Problem Link

https://leetcode.com/problems/sort-colors/

## 📝 Problem Summary

Given an array `nums` with `n` objects colored red, white, or blue, sort them **in-place** so that objects of the same color are adjacent.

We use the integers:

* `0` → Red
* `1` → White
* `2` → Blue

You must solve this problem **without using the library's `sort()` function**.

---

## 💡 Examples

### Example 1

**Input**

```text
nums = [2,0,2,1,1,0]
```

**Output**

```text
[0,0,1,1,2,2]
```

### Example 2

**Input**

```text
nums = [2,0,1]
```

**Output**

```text
[0,1,2]
```

---

## 📌 Constraints

* `n == nums.length`
* `1 <= n <= 300`
* `nums[i]` is either `0`, `1`, or `2`

---

## 🚀 Approach

This solution uses the **Selection Sort** algorithm to sort the array in-place.

1. Traverse the array from the first element to the second-last element.
2. Assume the current element is the minimum (`minIndex = i`).
3. Search the remaining unsorted part of the array to find the smallest element.
4. Update `minIndex` whenever a smaller element is found.
5. After completing the search, swap the current element with the minimum element (only if they are different).
6. Repeat the process until the entire array is sorted.

This approach avoids using the built-in `sort()` function and correctly sorts the colors in ascending order (`0`, `1`, `2`).

---

## 📊 Complexity Analysis

| Complexity | Value     |
| ---------- | --------- |
| **Time**   | **O(n²)** |
| **Space**  | **O(1)**  |

---

## 🧠 What I Learned

* How the **Selection Sort** algorithm works.
* Why Selection Sort performs only **one swap per iteration** after finding the minimum element.
* The importance of separating the **search phase** from the **swap phase**.
* How to sort an array **in-place** without using the library's `sort()` function.
* Although this solution is accepted, the optimal solution for this problem is the **Dutch National Flag Algorithm**, which solves it in **O(n)** time using constant extra space.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            int minIndex = i;

            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }

            if (minIndex != i) {
                swap(nums[i], nums[minIndex]);
            }
        }
    }
};
```
