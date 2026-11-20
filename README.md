# Algozenith Archive

My solutions to problems from the Algozenith DSA/CP course, along with some CSES and Codeforces practice. Everything is in C++.

The folders follow the order of the course (Phase 0 to Phase 5), and inside each phase there's one folder per topic. Each file is a single problem, usually named after the problem title. Codeforces problems keep their letter prefix, like `C_Kefa_and_Park.cpp`.

## Layout

```
Phase 0/             basics
Phase 1/             core techniques
Phase 2/             binary search, backtracking, graphs
Phase 3/             DP, trees, segment tree, DSU, bits, shortest paths
Phase 4/             bitmask/digit DP, DP on trees, strings, tries
Phase 5/             linked lists, binary trees, BSTs
VVIMP-Questions/     important-problems list (in progress)
CSES/                CSES DP and Graph sections
Codeforces Ladder/   Div 2A and Div 2B
template/            starting template for every problem
debug.cpp            local debug printer
```

## What each phase covers

**Phase 0**
- Pattern printing
- 1D and 2D prefix sums, difference arrays
- GCD/LCM, primality, divisors, prime factorisation
- Modular arithmetic, fast power, modular inverse
- A 2048 game simulation

**Phase 1**
- Brute force
- Recursion
- STL
- Prefix sums on Codeforces problems
- Contribution technique (sum over pairs/subarrays, inversions)
- Combinatorics (CF 1300–1800)
- Modulo
- A drill session

**Phase 2**
- Binary search: rotated and bitonic arrays, binary search on the answer
- Backtracking: N-Queens, bracket generation, permutations
- Graphs:
  - DFS: components, bipartite check, cycle detection
  - BFS on grids
  - Multisource BFS
  - Cycle detection in directed graphs
  - Topological sort, with both Kahn's algorithm and DFS, plus longest path in a DAG

**Phase 3** (the biggest phase)
- DP, organised the way the course teaches it:
  - Recursion to DP
  - Knapsack style
  - LIS style
  - Grid DP
  - Two-string DP (LCS, edit distance)
  - Interval DP (matrix chain, Zuma)
  - Game DP
  - Graded practice in Levels 1–3
- Trees: diameter, centre, centroid, sum of distances. Binary lifting / LCA isn't done yet.
- Segment tree: basic implementation, plus the CSES range query problems
- Union-find
- Two pointers
- Bit manipulation, including the contribution technique on bits
- Shortest paths: 0-1 BFS, Dijkstra, Floyd–Warshall (negative cycles, shortest cycle, transitive closure)

**Phase 4**
- Bitmask DP (five application sets)
- Digit DP
- DP on trees: in-out / rerooting, knapsack on trees
- String algorithms: KMP, Z-function, Manacher, string periods
- String tries and bit tries

**Phase 5**
- Linked lists: singly, doubly, circular, reversal, rotation, stack and deque built on lists
- Tree traversals: pre, in, level, zig-zag, diagonal
- Checking whether a tree is a BST / balanced BST
- k-th element and median of a BST
- Building a tree from inorder + preorder/postorder

## VVIMP-Questions

A list of problems I want to make sure I've solved, split into three levels:
- Minimal: 3 sets
- Standard: 5 sets
- Achiever: 5 sets

The files are numbered in the order I plan to solve them. Most are still empty, and I'm filling them in set by set.

## CSES and Codeforces

- `CSES/` has 14 problems from the Dynamic Programming section and 9 from Graph Algorithms. The CSES tree and range query problems are inside Phase 3.
- `Codeforces Ladder/` has around 40 problems, mostly from Div 2A.

## Template

Every solution starts from `template/template.cpp`:

```cpp
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <D:/debug.cpp>
#endif

#define int long long

void solve() {
    int n;
    cin >> n;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
```

The template defines `int` as `long long` so I don't have to think about overflow. The debug header is only included locally, because online judges define `ONLINE_JUDGE`.

`debug.cpp` prints variables and STL containers (vectors, maps, sets, pairs, nested containers) to stderr in colour. To turn the colour off, set `I_want_colored_output = false` at the top of the file.

## Running

```bash
g++ -std=c++17 -O2 -o sol "Phase 3/DP/LEVEL 2/Word_Break.cpp"
./sol < input.txt
```

The include path `D:/debug.cpp` only works on my Windows setup. Anywhere else, either change it to point at `debug.cpp` in this repo, or compile with `-DONLINE_JUDGE` to skip it.
