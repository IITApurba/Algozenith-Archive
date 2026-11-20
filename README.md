<div align="center">

# 🧠 Algozenith Archive

**My complete C++ problem-solving journey through the Algozenith DSA & Competitive Programming course, plus CSES and the Codeforces Ladder.**

![Language](https://img.shields.io/badge/language-C%2B%2B17-blue?logo=cplusplus)
![Solutions](https://img.shields.io/badge/solutions-380%2B-brightgreen)
![Phases](https://img.shields.io/badge/phases-0%E2%80%935-orange)
![Status](https://img.shields.io/badge/status-in%20progress-yellow)

</div>

---

## 📖 About

This repository is my personal archive of every problem I solved while working through the **Algozenith** curriculum. It is organised the way the course is taught: **six phases** that build from basic maths and prefix sums up to bitmask DP, tries, string algorithms and balanced BSTs.

Alongside the course I also practise from:

- the **[CSES Problem Set](https://cses.fi/problemset/)**: Dynamic Programming and Graph sections
- the **Codeforces Ladder**: Div 2A and Div 2B problems
- **VVIMP-Questions**: a curated list of the most important interview / CP problems, in three difficulty tiers

Each problem is a standalone `.cpp` file named after the problem (Codeforces problems keep their index prefix, e.g. `C_Kefa_and_Park.cpp`).

---

## 📑 Table of contents

- [Repository at a glance](#-repository-at-a-glance)
- [Phase 0: Foundations](#phase-0--foundations)
- [Phase 1: Core techniques](#phase-1--core-techniques)
- [Phase 2: Searching, backtracking & graphs](#phase-2--searching-backtracking--graphs)
- [Phase 3: DP, trees & advanced data structures](#phase-3--dp-trees--advanced-data-structures)
- [Phase 4: Advanced DP & strings](#phase-4--advanced-dp--strings)
- [Phase 5: Linked lists & BSTs](#phase-5--linked-lists--bsts)
- [VVIMP-Questions](#-vvimp-questions)
- [CSES Problem Set](#-cses-problem-set)
- [Codeforces Ladder](#-codeforces-ladder)
- [Template & debugging](#%EF%B8%8F-template--debugging)
- [How to run](#-how-to-run)

---

## 📊 Repository at a glance

| Section | Focus | Solutions |
| --- | --- | :---: |
| [`Phase 0`](Phase%200) | Pattern printing, prefix sums, number theory basics | 19 |
| [`Phase 1`](Phase%201) | Brute force, recursion, STL, combinatorics, contribution technique | 32 |
| [`Phase 2`](Phase%202) | Binary search, backtracking, BFS/DFS, topological sort, cycles | 47 |
| [`Phase 3`](Phase%203) | Dynamic programming, trees, segment tree, DSU, bits, shortest paths | 146 |
| [`Phase 4`](Phase%204) | Bitmask DP, digit DP, DP on trees, tries, string algorithms | 42 |
| [`Phase 5`](Phase%205) | Linked lists, binary trees, BSTs | 29 |
| [`CSES`](CSES) | CSES DP & Graph sections | 23 |
| [`Codeforces Ladder`](Codeforces%20Ladder) | Div 2A / 2B ladder | 40 |
| [`VVIMP-Questions`](VVIMP-Questions) | Curated must-do list (Minimal / Standard / Achiever) | 101 listed, *in progress* |

> Counts leave out helper and scratch files (`debug.cpp`, `x.cpp`, `tempCodeRunnerFile.cpp`).

---

## Phase 0: Foundations

| Topic | What's covered | Example files |
| --- | --- | --- |
| **Pattern Printing** | Nested loops, star/number patterns | `1.cpp` … `7.cpp` |
| **Prefix Sum** | 1D prefix sums, partial sums / difference arrays | `prefixSum.cpp`, `PartialSum.cpp` |
| **2D Prefix Sum** | Sub-matrix sum queries | `PrefixSum.cpp` |
| **Euclidean GCD & LCM** | Euclid's algorithm | `GCD.cpp` |
| **Factorisation Techniques** | Primality test, divisors in √n, prime factorisation | `IsPrime.cpp`, `Divisors.cpp`, `PrimeFactorisation.cpp` |
| **Modulo Arithmetic** | Modular properties, fast exponentiation, modular inverse | `ModularPower.cpp`, `InversesModulo.cpp` |
| **2048 Game** | Simulation / implementation exercise | `2048Game.cpp` |

## Phase 1: Core techniques

| Topic | What's covered | Example files |
| --- | --- | --- |
| **Brute Force** | Exhaustive search, bounding the search space | `A_Flipping_Game.cpp`, `A_System_of_Equations.cpp`, `D_I_hate_Factorization.cpp` |
| **Recursion** | Recursive thinking, Tower of Hanoi | `Tower_of_Hanoi.cpp`, `palindrome.cpp` |
| **STL** | `lower_bound`, containers & algorithms | `lowerbound.cpp` |
| **Prefix Sum** | Range updates, difference arrays on CF problems | `B_Karen_and_Coffee.cpp`, `C_Little_Girl_and_Maximum_Sum.cpp` |
| **2D Prefix Sum** | Rectangle sum queries | `Rectangle_Sum_Query.cpp` |
| **Contribution Technique** | Sum of products / pairs / subarrays, inversions | `SOP.cpp`, `POP.cpp`, `POS.cpp`, `inversion.cpp`, `D_Sum_of_difference.cpp` |
| **Combinatorics** | Counting, nCr, CF 1300–1800 problems | `D_Divisible_Pairs.cpp`, `E_Two_Round_Dances.cpp`, `D_Colored_Balls.cpp` |
| **Modulo** | Modular arithmetic practice | `Modulo.cpp` |
| **Drill Session** | Mixed practice, nCr table | `nCr_table.cpp`, `A_EhAb_AnD_gCd.cpp`, `C_The_World_is_a_Theatre.cpp` |

## Phase 2: Searching, backtracking & graphs

### Binary Search & Backtracking

| Topic | What's covered | Example files |
| --- | --- | --- |
| **Binary Search** | Lower bound, rotated & bitonic arrays, binary search on the answer | `rotated_array.cpp`, `biotonic_array.cpp`, `C_Cellular_Network.cpp`, `D_Multiplication_Table.cpp` |
| **Backtracking** | N-Queens, balanced bracket generation | `nQueens.cpp`, `brackating.cpp` |
| **Recursion & Backtracking** | Generating permutations | `Gen_permutation.cpp` |

### Graphs

| Topic | What's covered | Example files |
| --- | --- | --- |
| **DFS** | Connected components, bipartite check, cycle detection, CF problems | `bipartite.cpp`, `cycledetection.cpp`, `Easy_Graph_Queries.cpp`, `C_Kefa_and_Park.cpp` |
| **BFS** | Shortest path in unweighted graphs, grids, knight moves | `Labyrinth.cpp`, `Maze_solver.cpp`, `knight.cpp`, `KWALK.cpp` |
| **Multisource BFS** | Spreading from many sources at once | `MSBFS.cpp`, `Save_Yourself.cpp` |
| **DFS Tree & Cycle Detection (Directed)** | Back edges, printing a cycle, Round Trip | `Print_Cycle.cpp`, `Round_Trip.cpp`, `Round_Trip_II.cpp` |
| **Topological Ordering (BFS)** | Kahn's algorithm, lexicographically smallest order | `KAHNS_Algo.cpp`, `lexo_smallest.cpp` |
| **Topological Ordering (DFS)** | DFS topo sort, longest path in a DAG | `topological_ordering_dfs.cpp`, `longest_path_DAG.cpp` |
| **Drill** | Mixed graph practice | `Journey_to_the_Moon.cpp`, `C_Peaks.cpp` |

## Phase 3: DP, trees & advanced data structures

The largest phase, with **146 solutions**.

### Dynamic Programming

| Sub-topic | What's covered | Example files |
| --- | --- | --- |
| **Moving from Recursion to DP** | Memoisation, recursion → DP conversion | `DP1.cpp`, `N_Queens.cpp` |
| **How to Solve DP Problems** | State / transition design, multi-choice forms | `form1.cpp`, `k_items.cpp`, `multichoice_form1.cpp` |
| **Form 1: Knapsack Style** | 0/1 knapsack, subset sum queries | `D_Knapsack_1.cpp`, `C_Vacation.cpp`, `Subset_Sum_Queries.cpp` |
| **Form 2: LIS Style** | Single-index states, LIS counting | `B_Frog_2.cpp`, `Count_LIS.cpp`, `LCS_of_3_Strings.cpp` |
| **Form 2: Grid Based** | Paths and squares in grids | `H_Grid_1.cpp`, `Maximum_Area_of_Square.cpp`, `The_Witcher_II.cpp` |
| **Form 3: Two Sequences** | LCS, edit distance, longest common substring | `F_LCS.cpp`, `Edit_Distance.cpp`, `Longest_Common_Substring.cpp` |
| **Form 4: Interval DP** | Matrix chain multiplication, merging, Zuma | `B_Zuma.cpp`, `L_Deque.cpp`, `Merge_Elements_1.cpp` |
| **Form 5: Game DP** | Winning / losing states | `K_Stones.cpp`, `Subtraction_Game.cpp` |
| **Learning New Ideas** | LIS in O(n log n), polygon triangulation | `LIS.cpp`, `Convex_Polygon_Triangulation.cpp` |
| **Building a Stronghold on DP** | Bracket sequences, distinct subsequences, max K subarrays | `Balanced_Bracket_Sequence.cpp`, `LIS_nLogN.cpp`, `Distinct_Subsequence.cpp` |
| **Level 1 / 2 / 3** | Graded practice sets | `Word_Break.cpp`, `Maximum_Product_Subarray.cpp`, `Scrambled_String.cpp`, `Mountain_Array_II.cpp` |
| **DP Optimisation** | Multi-agent grid DP | `cherry_pickup.cpp` |

### Trees

| Sub-topic | What's covered | Example files |
| --- | --- | --- |
| **Fundamental Ideas** | Diameter, centre, centroid, sum of distances | `Tree_Diameter_I.cpp`, `Center_of_Tree.cpp`, `Finding_a_Centroid.cpp`, `Sum_of_Distances.cpp` |
| **Binary Lifting & LCA** | k-th ancestor, lowest common ancestor | *(notes / in progress)* |
| **CSES Trees** | Subordinates | `Subordinates.cpp` |
| **Mixed In-depth Ideas** | Diameter variants | `Tree_Diameter_II.cpp` |

### Data structures & techniques

| Topic | What's covered | Example files |
| --- | --- | --- |
| **Segment Tree** | Build / query / point & range update, CSES range queries | `implementation.cpp`, `Dynamic_Range_Minimum_Queries.cpp`, `Hotel_Queries.cpp`, `Range_Update_Queries.cpp` |
| **Union Find** | DSU with path compression & union by size | `union_find.cpp` |
| **Two Pointers** | 2-Sum, 3-Sum, container with most water, OA problems | `2sum.cpp`, `3Sum.cpp`, `container_water.cpp`, `google_OA.cpp` |
| **Bit Manipulation** | Bit tricks, bitsets, contribution technique on bits, 10 frequent interview questions | `Bit_Magic_I.cpp`, `bitset.cpp`, `XOR_AND_OR_Query.cpp`, `Max_AND_Subsequences.cpp` |

### Shortest paths (SSSP & APSP)

| Algorithm | Example files |
| --- | --- |
| **0-1 BFS** | `01BFS.cpp`, `Edge_Reverse.cpp`, `One_Piece.cpp` |
| **Dijkstra** | `Dijkstra.cpp`, `C_Dijkstra.cpp`, `Shortest_Routes_I.cpp` |
| **Floyd–Warshall** | `FloydWarshall.cpp`, `negativecycle.cpp`, `shortestCycle.cpp`, `findtransitiveclouser.cpp`, `diameterofagraph.cpp` |
| **Formulation practice** | `uberQuestion.cpp`, `Vertical_Grid.cpp` |

## Phase 4: Advanced DP & strings

| Topic | What's covered | Example files |
| --- | --- | --- |
| **Bitmask DP** | Assignment problems, counting cycles, DAG edge deletion, tiling (5 applications) | `Students_Happiness.cpp`, `Cycles_in_a_graph.cpp`, `Minimum_Edge_Deletion_to_make_DAG.cpp`, `Tiling.cpp` |
| **Digit DP** | Counting numbers by digit properties | `S_Digit_Sum.cpp` |
| **DP on Trees** | In-out DP (rerooting), knapsack on trees, parent-maintained states | `InoutDP.cpp`, `Knapsack_On_Tree.cpp`, `Tree_Distance.cpp`, `K_Coloring_Tree.cpp` |
| **String Algorithms** | KMP, Z-algorithm, Manacher, string periods | `KMP.cpp`, `ZAlgo.cpp`, `ManacherAlgo.cpp`, `Period_of_String.cpp` |
| **String Trie** | Insert / search, auto-suggestion, search recommendations | `String_Trie_Algos.cpp`, `Auto_Suggestion.cpp`, `search_recomendation.cpp` |
| **Bit Trie** | Binary trie structure for XOR queries | `structure.cpp` |

## Phase 5: Linked lists & BSTs

| Topic | What's covered | Example files |
| --- | --- | --- |
| **Linked List** | Singly, doubly and circular lists, reversal, rotation, stack / deque using lists, `std::list` | `Reverse_Linked_list.cpp`, `Remove_Nth_Node_From_End.cpp`, `Rotate_List.cpp`, `Deque_DLL.cpp` |
| **Binary Tree Traversals** | Pre / in / level / zig-zag / diagonal order | `Level_Order_Traversal.cpp`, `ZigZag_Level_Order_Traversal.cpp`, `Diagonal_Level_Order_Traversal.cpp` |
| **BST & Balanced BST** | Validate BST / BBST, k-th element, median, mirror | `IsBst.cpp`, `isBBST.cpp`, `Kth_element_of_BST.cpp`, `Median_of_BST.cpp` |
| **Recover Tree** | Build from inorder + preorder / postorder | `In+Pre.cpp`, `In+Pre_Stack.cpp`, `Tree_from_inorder_and_postoder.cpp` |

---

## ⭐ VVIMP-Questions

A curated list of **must-do problems**, split into three difficulty tiers. Each set has 5–9 problems, and each file is numbered in the recommended solving order.

> 🚧 **In progress.** All problem files are in place, and solutions are being added set by set.

<details>
<summary><b>🟢 Minimal</b> (3 sets, 24 problems)</summary>

| Set | Problems |
| --- | --- |
| **Set 1** | Palindrome · ONLYREP · Combination Sum II · Combination Sum I · Sudoku Solver · Hakuna Matata · Bilkul ricks nhi lena ka · Bit Magic II |
| **Set 2** | WeekDay · Moving Zeros · COLORSORT · REVBIT · SQUARE · SWAPBIT · CELEB · STOI · String Compression |
| **Set 3** | Buy and Sell Stock 1 · Buy and Sell Stock 2 · Finish in Time · String Compare · Nearly Sorted Arrays · Longest Palindromic Substring (Easy) · KTHELE |

</details>

<details>
<summary><b>🟡 Standard</b> (5 sets, 41 problems)</summary>

| Set | Problems |
| --- | --- |
| **Set 1** | Non Consecutive Sum · Stone Jumps · Buy and Sell Stock 3 · Buy and Sell Stock 4 · Tallest Stack · Largest Rectangle · Rain Water · Message Decoding |
| **Set 2** | Android Unlock Pattern · Josephus Problem · Next Permutation · TWOREP · Quickselect · Grid Queries · Matrix Rotation · BLAWHI |
| **Set 3** | Super Frequent Number · KSUM · Minimum Platforms · Max Vials · MATMED · ONEZERO · INTBREAK · Maximum Sum in Grid |
| **Set 4** | Non Zero Digit · Big Factorial · Tricky Sum · Snakes and Ladders · Minimum Swaps Palindrome · Word Break · Maximum Product Subarray · Awesome · Entropy |
| **Set 5** | Binary Palindrome · Hard Division · Subset Sum Queries · Scrambled String · Longest Common Substring · LCS of 3 Strings · Make Palindrome · Shortest Common Supersequence |

</details>

<details>
<summary><b>🔴 Achiever</b> (5 sets, 36 problems)</summary>

| Set | Problems |
| --- | --- |
| **Set 1** | SLICES I · SLICES II · Infected People · Interleaved Strings · Consecutive Numbers · KWALK · Course Scheduling · Building the Sum |
| **Set 2** | Longest Consecutive Sequence · COUNTBIT · GRAPHADJ · Egg Drop · Rock Paper Scissor · Skyline · K Lists Range |
| **Set 3** | Word Boggle · Bubbles · Swaps and Permutation · Mother Vertex · The Witcher II · Weighted Job Scheduling · Count LIS · Mountain Array II |
| **Set 4** | Matrix Rank Transform · Merge Elements 3 · Balance · Array Queries · Round Trip II · One Piece · Shortest Transformation Sequences · Longest Palindromic Substring (Hard) |
| **Set 5** | Distinct Subsequences III · Inverse Pairs Permutation · Uncommon Subsequences · Sum Partition · The Witcher |

</details>

---

## 🏁 CSES Problem Set

<details>
<summary><b>Dynamic Programming</b> (14 problems)</summary>

Dice Combinations · Minimizing Coins · Coin Combinations I · Coin Combinations II · Removing Digits · Grid Paths · Book Shop · Array Description · Counting Towers · Edit Distance · Longest Common Subsequence · Rectangle Cutting · Money Sums · Removal Game

</details>

<details>
<summary><b>Graph Algorithms</b> (9 problems)</summary>

Counting Rooms · Labyrinth · Building Roads · Message Route · Building Teams · Round Trip · Monsters · Shortest Routes I · High Score

</details>

CSES Tree and Range Query problems are solved inside **Phase 3** (`Trees/CSES TREES`, `Segment Tree/CSES`).

---

## 🪜 Codeforces Ladder

| Ladder | Count | A few problems |
| --- | :---: | --- |
| [**Div 2A**](Codeforces%20Ladder/Div%202A) | 37 | Way Too Long Words · Beautiful Matrix · Stones · Desorting · Forked · Rigged · Two Permutations · Regular Bracket Sequences · Min Or Sum |
| [**Div 2B**](Codeforces%20Ladder/Div%202B) | 3 | Notepad · Ugu · XOR Average |

---

## 🛠️ Template & debugging

Every solution starts from [`template/template.cpp`](template/template.cpp):

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

| Feature | Why |
| --- | --- |
| `#define int long long` | Avoids integer overflow by default; `main` is therefore declared `signed main()` |
| Fast I/O (`sync_with_stdio(0)`, `cin.tie(0)`) | Needed for large inputs on online judges |
| Multi-test loop | Most Codeforces / Algozenith problems have `t` test cases |
| `#ifndef ONLINE_JUDGE` | Online judges define `ONLINE_JUDGE`, so the debug header is only included locally |

### `debug.cpp`

[`debug.cpp`](debug.cpp) is a local-only debugging helper. It prints **any variable or STL container** (vectors, sets, maps, pairs, nested containers…) to `stderr` with the variable's name, in colour:

- 🔵 variable names in **blue**
- 🟢 values in **green**
- 🔴 brackets / separators in **red**

Colour output can be turned off by setting `I_want_colored_output = false`.

---

## 🚀 How to run

**Prerequisites:** `g++` with C++17 support (GCC 9+ or Clang with `bits/stdc++.h` available).

```bash
# 1. Clone
git clone https://github.com/IITApurba/Algozenith-Archive.git
cd Algozenith-Archive

# 2. Compile a solution
g++ -std=c++17 -O2 -Wall -o sol "Phase 3/DP/LEVEL 2/Word_Break.cpp"

# 3. Run with input from a file
./sol < input.txt
```

> **⚠️ Note on `debug.cpp`:** the template includes it from the absolute path `D:/debug.cpp` (Windows). On another machine, either
> - change the include to the path of [`debug.cpp`](debug.cpp) in this repo, **or**
> - compile with `-DONLINE_JUDGE` to skip the debug header:
>   ```bash
>   g++ -std=c++17 -O2 -DONLINE_JUDGE -o sol file.cpp
>   ```

---

## 🗂️ Topics covered

`Pattern Printing` · `Prefix Sums` · `Difference Arrays` · `GCD / LCM` · `Prime Factorisation` · `Modular Arithmetic` · `Brute Force` · `Recursion` · `STL` · `Combinatorics` · `Contribution Technique` · `Binary Search` · `Backtracking` · `DFS` · `BFS` · `Multisource BFS` · `Topological Sort` · `Cycle Detection` · `Two Pointers` · `Bit Manipulation` · `Union-Find` · `Segment Tree` · `Tree Diameter / Centre / Centroid` · `Binary Lifting & LCA` · `0-1 BFS` · `Dijkstra` · `Floyd–Warshall` · `Knapsack DP` · `LIS / LCS` · `Grid DP` · `Interval DP` · `Game DP` · `Bitmask DP` · `Digit DP` · `DP on Trees / Rerooting` · `KMP` · `Z-Algorithm` · `Manacher` · `Tries` · `Linked Lists` · `Binary Trees` · `BST / Balanced BST`

---

## 🙏 Acknowledgements

- **[Algozenith](https://algozenith.com/)** for the curriculum, phases and problem sets
- **[CSES Problem Set](https://cses.fi/problemset/)** for classic practice problems
- **[Codeforces](https://codeforces.com/)** for the ladder problems

---

<div align="center">

⭐ **If this archive helps you, consider giving it a star!** ⭐

</div>
