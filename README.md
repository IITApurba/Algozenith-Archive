# Algozenith Archive

My C++ solutions from the Algozenith DSA/CP course, plus CSES and Codeforces practice. There are about 380 solved problems, sorted by topic in the order the course teaches them.

If you're doing the course yourself, preparing for interviews, or just looking for a clean solution to a classic problem (knapsack, Dijkstra, segment tree, KMP, rerooting DP and so on), this should help.

**[Browse the full problem index →](PROBLEMS.md)**

## How to use this repo

- **If you're following the course:** go phase by phase. Each phase builds on the one before it. Phase 3 (DP, trees, segment trees, shortest paths) is the biggest and the most important.
- **If you're revising for interviews:** start with `VVIMP-Questions`. It's a shortlist of the problems that come up most, split into three levels.
- **If you're looking for a specific problem:** open [PROBLEMS.md](PROBLEMS.md) and use Ctrl+F. Every solution is linked there.

Try a problem yourself before you open the code. You'll get far more out of it.

## Layout

```
Phase 0/             basics: patterns, prefix sums, number theory
Phase 1/             brute force, recursion, STL, combinatorics, contribution technique
Phase 2/             binary search, backtracking, graphs
Phase 3/             DP, trees, segment tree, DSU, bits, shortest paths
Phase 4/             bitmask/digit DP, DP on trees, strings, tries
Phase 5/             linked lists, binary trees, BSTs
VVIMP-Questions/     must-do shortlist (in progress)
CSES/                CSES DP and Graph sections
Codeforces Ladder/   Div 2A and Div 2B
template/            starting template for every problem
debug.cpp            local debug printer
tools/               script that builds PROBLEMS.md
```

Each file is one problem, named after the problem title. Codeforces problems keep their letter prefix, so `C_Kefa_and_Park.cpp` is problem C.

## What each phase covers

**Phase 0**
- Pattern printing
- 1D and 2D prefix sums, difference arrays
- GCD/LCM, primality, divisors, prime factorisation
- Modular arithmetic, fast power, modular inverse

**Phase 1**
- Brute force, recursion, STL
- Prefix sums on Codeforces problems
- Contribution technique (sums over pairs and subarrays, inversions)
- Combinatorics (CF 1300–1800)

**Phase 2**
- Binary search: rotated and bitonic arrays, binary search on the answer
- Backtracking: N-Queens, bracket generation, permutations
- Graphs:
  - DFS: components, bipartite check, cycle detection
  - BFS on grids
  - Multisource BFS
  - Cycles in directed graphs
  - Topological sort (Kahn's algorithm and DFS), longest path in a DAG

**Phase 3**
- DP, split the way the course teaches it:
  - Recursion to DP
  - Knapsack style
  - LIS style
  - Grid DP
  - Two-string DP (LCS, edit distance)
  - Interval DP (matrix chain, Zuma)
  - Game DP
  - Graded practice in Levels 1–3
- Trees: diameter, centre, centroid, sum of distances
- Segment tree: implementation, plus the CSES range query problems
- Union-find, two pointers
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

A shortlist of 101 problems I want to have solved before interviews, in three levels:

| Level | Sets | What it's for |
| --- | --- | --- |
| Minimal | 3 | The bare minimum. If you're short on time, do these. |
| Standard | 5 | The usual interview range: DP, stacks, greedy, maths |
| Achiever | 5 | Harder graph, DP and string problems |

Files are numbered in the order to solve them. I'm working through it now (5 of 101 done), and [PROBLEMS.md](PROBLEMS.md) shows which ones are solved.

## CSES and Codeforces

- `CSES/` has 14 problems from the Dynamic Programming section and 9 from Graph Algorithms. The CSES tree and range query problems are in Phase 3.
- `Codeforces Ladder/` has about 40 problems, mostly from Div 2A.

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

The template defines `int` as `long long` so overflow is never a worry. The debug header only gets included locally, because online judges define `ONLINE_JUDGE`.

`debug.cpp` prints variables and STL containers (vectors, maps, sets, pairs, nested containers) to stderr in colour, so you can see what's going on without writing print loops. Feel free to take it for your own setup.

## Running a solution

```bash
g++ -std=c++17 -O2 -o sol "Phase 3/DP/LEVEL 2/Word_Break.cpp"
./sol < input.txt
```

The include path `D:/debug.cpp` only works on my Windows machine. On yours, either change it to point at `debug.cpp` in this repo, or compile with `-DONLINE_JUDGE` to skip it.

## Updating the index

`PROBLEMS.md` is generated, so don't edit it by hand. After adding solutions, run:

```bash
python3 tools/gen_index.py
```

## Found a bug?

If a solution is wrong, or you have a cleaner approach, open an issue or a PR. Both are welcome.

If the repo helped you, a star is always appreciated.
