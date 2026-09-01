class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
  // Approach :- Parentheses
  // Time :- O(N)
  // Space :- O(1)
         
        int depth = 0;
        vector<int> ans(seq.length());

        for(int i = 0; i < seq.length(); i++) {
            if(seq[i] == '(') {
                depth++;
                ans[i] = depth % 2;
            }
            else {
                ans[i] = depth % 2;
                depth--;
            }
        }

        return ans;
    }
};

/* 
    ## approach to solve this question 

    **Problem Deconstruction**

You are given a valid parentheses string `seq`. You need to divide all its characters into two groups, `A` (marked as `0`) and `B` (marked as `1`), such that both subsequences are valid parentheses strings, and the **maximum nesting depth** between `A` and `B` is minimized.

* Nesting depth simply means how deeply nested a pair of brackets is at any given index.
* To minimize the maximum depth of both subsequences, the optimal strategy is to **split the depth evenly** between `A` and `B`.

---

**Core Insight & Pattern**

Instead of building complex subsets, look at the nesting level (depth) of each character:

* If a parenthesis is at an **even depth**, assign it to group `0` (`A`).
* If a parenthesis is at an **odd depth**, assign it to group `1` (`B`).

By alternating assignments based on parity (odd/even):

* Half of the depth levels go to `A`, and half go to `B`.
* Every open bracket `(` at depth $d$ will automatically pair with its matching `)` at the exact same depth $d$, guaranteeing both `A` and `B` remain valid parentheses strings.

---

**Step-by-Step Algorithm**

Maintain a single integer `depth = 0` and an answer array/vector initialized to size `seq.length()`:

1. **Traverse the string character by character:**
* **If `seq[i] == '('`:**
* Increment `depth++`.
* Assign `ans[i] = depth % 2` (or `depth & 1`).


* **If `seq[i] == ')'`:**
* Assign `ans[i] = depth % 2` (or `depth & 1`).
* Decrement `depth--`.





> **Note on Ordering:** For `'('`, update depth **before** taking the modulo (or update after, as long as matching pairs share parity). For `')'`, take modulo at the current matching depth **before** decreasing `depth`.

---

**Dry-Run Example**

Consider `seq = "(()())"`:

| Index `i` | Char `s[i]` | Action | Current Depth | Assigned `depth % 2` | Group |
| --- | --- | --- | --- | --- | --- |
| `0` | `(` | `depth++` | 1 | `1 % 2 = 1` | B (1) |
| `1` | `(` | `depth++` | 2 | `2 % 2 = 0` | A (0) |
| `2` | `)` | `ans = depth % 2`, `depth--` | 2 $\rightarrow$ 1 | `2 % 2 = 0` | A (0) |
| `3` | `(` | `depth++` | 2 | `2 % 2 = 0` | A (0) |
| `4` | `)` | `ans = depth % 2`, `depth--` | 2 $\rightarrow$ 1 | `2 % 2 = 0` | A (0) |
| `5` | `)` | `ans = depth % 2`, `depth--` | 1 $\rightarrow$ 0 | `1 % 2 = 1` | B (1) |

* Result array: `[1, 0, 0, 0, 0, 1]` (Equally valid as `[0, 1, 1, 1, 1, 0]`).
* Subsequence `A`: `"()()"` (depth = 1).
* Subsequence `B`: `"()"` (depth = 1).
* Max depth is $\max(1, 1) = 1$, which is the minimum possible.

---

**Complexity**

* **Time Complexity:** $O(N)$ — Single pass over `seq`.
* **Space Complexity:** $O(1)$ auxiliary space (excluding the output vector).

*/