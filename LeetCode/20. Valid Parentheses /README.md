# 20. Valid Parentheses

**Platform:** LeetCode
**Difficulty:** 🟢 Easy
**Topics:** Stack, String

---

## 🔗 Problem Link

https://leetcode.com/problems/valid-parentheses/

---

## 📝 Problem Summary

Given a string `s` containing only the characters `'('`, `')'`, `'{'`, `'}'`, `'['`, and `']'`, determine whether the string is valid.

A string is considered valid if:

* Every opening bracket has a corresponding closing bracket of the same type.
* Opening brackets are closed in the correct order.
* Every closing bracket has a matching opening bracket.

Return `true` if the string is valid; otherwise, return `false`.

---

## 💡 Examples

### Example 1

**Input**

```text
s = "()"
```

**Output**

```text
true
```

### Example 2

**Input**

```text
s = "()[]{}"
```

**Output**

```text
true
```

### Example 3

**Input**

```text
s = "(]"
```

**Output**

```text
false
```

### Example 4

**Input**

```text
s = "([])"
```

**Output**

```text
true
```

### Example 5

**Input**

```text
s = "([)]"
```

**Output**

```text
false
```

---

## 📌 Constraints

* `1 <= s.length <= 10⁴`
* `s` consists only of the characters `'('`, `')'`, `'{'`, `'}'`, `'['`, and `']'`.

---

## 🚀 Approach

* Create a `vector<char>` to simulate a stack that stores the order of opening brackets.
* Traverse each character in the string.
* If an opening bracket is found:

  * Push its corresponding identifier (`'a'`, `'b'`, or `'c'`) into the stack.
  * Increment its respective counter.
* If a closing bracket is encountered:

  * Check if the stack is empty or if the top element does not match the expected opening bracket.
  * If either condition is true, return `false`.
  * Otherwise, pop the top element and decrement the corresponding counter.
* After processing the entire string, ensure all counters are zero.
* If no unmatched brackets remain, return `true`; otherwise, return `false`.

---

## 📊 Complexity Analysis

| Complexity | Value    |
| ---------- | -------- |
| **Time**   | **O(n)** |
| **Space**  | **O(n)** |

---

## 🧠 What I Learned

* How to validate parentheses using a **stack-based approach**.
* How a `vector` can be used as a stack with `push_back()` and `pop_back()`.
* Why checking the most recently opened bracket (`back()`) is necessary for maintaining the correct order.
* How to immediately detect invalid bracket sequences without traversing the remaining characters.
* The importance of ensuring that all opening brackets are matched before returning `true`.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    bool isValid(string s) {
        int a = 0;
        int b = 0;
        int c = 0;
        vector<char> last_opened;

        for(char ch : s){
            if(ch == '('){
                a += 1;
                last_opened.push_back('a');
            }
            else if(ch == '{'){
                b += 1;
                last_opened.push_back('b');
            }
            else if(ch == '['){
                c += 1;
                last_opened.push_back('c');
            }
            else if(ch == ')'){
                if(last_opened.empty() || last_opened.back() != 'a'){
                    return false;
                }
                a--;
                last_opened.pop_back();
            }
            else if(ch == '}'){
                if(last_opened.empty() || last_opened.back() != 'b'){
                    return false;
                }
                b--;
                last_opened.pop_back();
            }
            else if(ch == ']'){
                if(last_opened.empty() || last_opened.back() != 'c'){
                    return false;
                }
                c--;
                last_opened.pop_back();
            }
        }

        return a == 0 && b == 0 && c == 0;
    }
};
```
