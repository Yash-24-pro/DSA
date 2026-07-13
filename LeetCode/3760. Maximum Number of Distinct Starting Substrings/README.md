# 3760. Maximum Number of Distinct Starting Substrings

> **Platform:** LeetCode  
> **Difficulty:** 🟡 Medium  
> **Topics:** String

---

## 🔗 Problem Link

https://leetcode.com/problems/maximum-substrings-with-distinct-start/

---

## 📝 Problem Summary

Given a string `s` consisting of lowercase English letters, split it into the **maximum number of substrings** such that each substring starts with a **distinct character**.

Return the maximum possible number of such substrings.

---

## 💡 Examples

### Example 1

**Input**
```text
s = "abab"
```

**Output**
```text
2
```

**Explanation**
```text
"a" | "bab"
```

---

### Example 2

**Input**
```text
s = "abcd"
```

**Output**
```text
4
```

**Explanation**
```text
"a" | "b" | "c" | "d"
```

---

### Example 3

**Input**
```text
s = "aaaa"
```

**Output**
```text
1
```

---

## 📌 Constraints

- `1 <= s.length <= 10^5`
- `s` consists of lowercase English letters.

---

## 🚀 Approach

- Store the distinct characters encountered so far in a separate string.
- Traverse the original string from left to right.
- For each character, check whether it already exists in the distinct-character string.
- If it is not present, append it using `push_back()`.
- The size of the distinct-character string is the required answer.

---

## 📊 Complexity Analysis

| Complexity | Value |
|------------|------:|
| **Time** | **O(n²)** |
| **Space** | **O(n)** |

---

## 🧠 What I Learned

- Using a boolean flag to check whether an element already exists.
- How `break` exits only the current loop.
- Building a string of unique characters using `push_back()`.
- This approach can be optimized to **O(n)** using a boolean array or `unordered_set`.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int maxDistinct(string s) {
        string s1;
        s1.push_back(s[0]);

        for (int i = 1; i < s.size(); i++) {
            bool found = false;

            for (int j = 0; j < s1.size(); j++) {
                if (s[i] == s1[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                s1.push_back(s[i]);
            }
        }

        return s1.size();
    }
};
```
