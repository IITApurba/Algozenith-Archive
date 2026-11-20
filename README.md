# Algozenith Archive

My C++ solutions from the **Algozenith** DSA & Competitive Programming course, plus practice from the **CSES Problem Set** and the **Codeforces Ladder**.

The repo holds **500+ solutions**, arranged in the order I learned the topics, from basic maths up to advanced DP and data structures.

![Language](https://img.shields.io/badge/language-C%2B%2B-blue)
![Problems](https://img.shields.io/badge/solutions-500%2B-brightgreen)

---

## Repository structure

| Folder | What's inside |
| --- | --- |
| [`Phase 0`](Phase%200) | Foundations: pattern printing, prefix sums (1D & 2D), GCD/LCM, factorisation, modular arithmetic |
| [`Phase 1`](Phase%201) | Brute force, recursion, STL, combinatorics, contribution technique, modulo, drill sessions |
| [`Phase 2`](Phase%202) | Binary search, recursion & backtracking, graphs (BFS, DFS, multisource BFS, topological sort, cycle detection) |
| [`Phase 3`](Phase%203) | Dynamic programming (all forms & levels), DP optimisation, trees, binary lifting & LCA, segment trees, union-find, two pointers, bit manipulation, shortest paths (Dijkstra, 0-1 BFS, Floyd–Warshall) |
| [`Phase 4`](Phase%204) | Bitmask DP, digit DP, DP on trees, string algorithms, string tries, bit tries |
| [`Phase 5`](Phase%205) | Linked lists, binary search trees & balanced BSTs, building a tree from preorder + inorder |
| [`VVIMP-Questions`](VVIMP-Questions) | Most important practice sets, in three tiers: **Minimal**, **Standard**, **Achiever** *(in progress)* |
| [`CSES`](CSES) | CSES Problem Set: Dynamic Programming and Graph sections |
| [`Codeforces Ladder`](Codeforces%20Ladder) | Codeforces Div 2A and Div 2B ladder problems |
| [`template`](template) | The starter template I use for every problem |
| [`debug.cpp`](debug.cpp) | Local debug helper that prints variables and STL containers in colour |

---

## Template

Every solution starts from [`template/template.cpp`](template/template.cpp):

```cpp
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

void solve() {
    // ...
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
```

- `#define int long long` guards against integer overflow by default.
- `debug.cpp` is only included locally. Online judges define `ONLINE_JUDGE`, so the debug code never reaches a submission.

---

## Running a solution

```bash
g++ -std=c++17 -O2 -Wall -o sol "Phase 3/DP/LEVEL 1/<file>.cpp"
./sol < input.txt
```

> **Note:** the template includes `debug.cpp` from `D:/debug.cpp`. If you compile locally on another machine, change that path to point at [`debug.cpp`](debug.cpp) in this repo, or compile with `-DONLINE_JUDGE` to skip it.

---

## Topics at a glance

`Prefix Sums` · `GCD & Modular Arithmetic` · `Combinatorics` · `Recursion` · `Backtracking` · `Binary Search` · `BFS / DFS` · `Topological Sort` · `Cycle Detection` · `Two Pointers` · `Bit Manipulation` · `Union-Find` · `Segment Tree` · `Binary Lifting / LCA` · `Dijkstra` · `0-1 BFS` · `Floyd–Warshall` · `Dynamic Programming` · `Bitmask DP` · `Digit DP` · `DP on Trees` · `Tries` · `String Algorithms` · `Linked Lists` · `BST`

---

## Acknowledgements

- [Algozenith](https://algozenith.com/) for the course structure and problem sets
- [CSES Problem Set](https://cses.fi/problemset/)
- [Codeforces](https://codeforces.com/)

---

⭐ If this archive helps you, consider giving it a star!
