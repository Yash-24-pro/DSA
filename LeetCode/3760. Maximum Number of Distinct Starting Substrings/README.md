# 3760. Maximum Number of Distinct Starting Substrings

**Platform:** LeetCode  
**Difficulty:** Medium  
**Topics:** String

---

## Problem Link

https://leetcode.com/problems/maximum-substrings-with-distinct-start/

---

## Problem Overview

Given a string consisting of lowercase English letters, split it into the maximum possible number of substrings such that every substring begins with a unique character.

The task is to return the maximum number of such substrings.

---

## Examples

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

The two substrings start with different characters (`a` and `b`).

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

Each substring starts with a different character.

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

## Constraints

- `1 <= s.length <= 10^5`
- `s` contains only lowercase English letters.

---

## Approach

The idea is to maintain a string containing only the distinct starting characters encountered so far.

For every character in the input string:

- Check whether it already exists in the distinct-character string.
- If it exists, move to the next character.
- Otherwise, append it to the string.

The final size of this string represents the maximum number of substrings that can have distinct starting characters.

---

## Complexity Analysis

| Complexity | Value |
| :--------- | :---: |
| **Time** | **O(n²)** |
| **Space** | **O(n)** |

---

## Possible Optimization

This solution performs a linear search for every character, resulting in **O(n²)** time complexity.

Using an `unordered_set<char>` (or a boolean array of size `26`) allows constant-time lookups and reduces the overall time complexity to **O(n)**.

---

## C++ Solution

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

---

## Notes

- This is a straightforward brute-force implementation.
- A boolean flag is used to determine whether the current character has already been encountered.
- The `break` statement avoids unnecessary comparisons once a match is found.
- This solution is easy to understand and serves as a good starting point before moving to the optimized `unordered_set` approach.
