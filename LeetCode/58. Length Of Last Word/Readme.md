# 58. Length of Last Word

## 📌 Platform
- **Platform:** LeetCode
- **Difficulty:** 🟢 Easy
- **Topics:** String, Traversal

---

## 🔗 Problem Link
https://leetcode.com/problems/length-of-last-word/

---

## 📝 Problem Summary

Given a string `s` consisting of words and spaces, return the **length of the last word** in the string.

A **word** is defined as a maximal substring consisting of non-space characters only.

---

## 💡 Examples

### Example 1

**Input**
```text
s = "Hello World"
```

**Output**
```text
5
```

**Explanation**

The last word is `"World"` which has a length of **5**.

---

### Example 2

**Input**
```text
s = "   fly me   to   the moon  "
```

**Output**
```text
4
```

**Explanation**

After ignoring the trailing spaces, the last word is `"moon"` with a length of **4**.

---

### Example 3

**Input**
```text
s = "luffy is still joyboy"
```

**Output**
```text
6
```

**Explanation**

The last word is `"joyboy"` which has a length of **6**.

---

## 📋 Constraints

- `1 <= s.length <= 10⁴`
- `s` consists only of English letters and spaces `' '`.
- There is at least one word in the string.

---

## 🚀 Approach

The idea is to traverse the string **from the end**.

1. Start from the last character of the string.
2. Skip all trailing spaces.
3. Count each non-space character until another space or the beginning of the string is reached.
4. Return the count.

This approach avoids creating any extra strings and scans the input only once.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
  - In the worst case, we may traverse the entire string once.

- **Space Complexity:** `O(1)`
  - No extra space is used.

---

## 📚 What I Learned

- How to traverse a string in reverse.
- The importance of checking array/string bounds **before** accessing an index.
- How short-circuit evaluation (`&&`) prevents out-of-bounds access.
- Efficient string processing without using extra memory or built-in split functions.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.size() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};
```
