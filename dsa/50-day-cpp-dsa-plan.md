# Ryan's 50-Day C++ DSA Interview Plan

**Goal:** By the time fall recruiting starts, be able to walk into a screen or technical interview, recognize what kind of problem it is, and code a correct, reasonably idiomatic C++ solution under time pressure — comfortable enough with the language that syntax isn't what's slowing you down.

**Budget:** ~10 hrs/week × 7 weeks ≈ 70 hours.

**Starting point (your words, lightly translated):** You took all of DSA and it didn't stick, so concepts are ~40% — you've *seen* everything but can't yet *produce* it on demand. C++ syntax is ~70–80%, with the STL being the weak part. You learn by coding, not reading, and you want to be writing code from day one even before it's LeetCode-shaped.

---

## Read this first: what your file actually is, and the one honest caveat

The PDF you uploaded is the **Goodrich & Tamassia *Data Structures and Algorithms in C++*** lecture series — the exact slide deck Purdue's CS251 is built on. Good news: it's comprehensive and it's the right source to *rebuild your foundation*, which is the real problem (the 40%). The 1008 pages are scrambled, every deck is duplicated, and there's a corrupted/blank stretch in the middle — so I've re-sequenced the topics into a real learning order, and the page map at the bottom tells you where to find each one in your PDF.

**The caveat, because it matters:** a university DS&A course and an *interview* curriculum are not the same thing, and your deck leans academic. Two consequences:

1. **It over-invests in things interviews basically never ask you to implement** — red-black trees, (2,4) trees, Floyd-Warshall, suffix tries, Huffman coding, regular expressions / finite automata. You should *understand* what they are at a sentence level, but do **not** spend your 70 hours mastering red-black tree deletion. I've marked these "skim" or "skip."
2. **It's missing things interviews ask constantly.** The big one is **dynamic programming** — there is no DP deck in your file at all, and it's a whole section of any interview prep. It also doesn't teach the named LeetCode *patterns* (two pointers, sliding window, backtracking, monotonic stack) as techniques, because those are interview folklore, not textbook chapters. I'm sourcing those from the **NeetCode 150** framework you're already using, and weaving them in next to the matching data structure.

So this plan = **your deck (rebuild the foundation, the right way, in the right order) + NeetCode patterns layered on top (so you're training the actual interview muscle).**

**One expectation-setting note, straight:** 70 focused hours from a shaky foundation gets you genuinely solid on **easy + medium** problems across all the core patterns — which is what the large majority of internship and new-grad screens actually test. It will *not* make hard DP or advanced graph problems comfortable; that's a later phase and that's fine. We're aiming at "passes most interviews," not "wins competitive programming." That's a realistic, reachable target in this window.

---

## How we work together (the feedback loop)

You said you learn from feedback and need to be coding often. Here's the loop:

- **You attempt first, always.** Even a broken attempt. Struggling for 10–15 min before help is where the learning happens — a clean solution you read does almost nothing for recall.
- **You paste me your code.** I have a C++17 compiler on my side, so I'll actually **compile it, run it against test cases including edge cases, and tell you what breaks** — not just guess. Then I review four things every time: **(1) correctness, (2) time/space complexity, (3) C++ idiom / STL use, (4) what an interviewer would push on.**
- **We track position by name.** Just tell me "Week 3, Day 2" or "the linked-list day" and I'll know where we are. I'm keeping the plan in memory, so you don't have to re-explain the program each session.
- **When you're stuck:** ask for a *hint*, not the answer. I'll give you the smallest nudge that unblocks you. Getting the full solution handed over is the fastest way to feel productive and learn nothing.

**Suggested per-session shape (~1.5–2 hrs):** 20 min read/watch the day's concept → 15 min reimplement the structure or pattern from scratch (no looking) → rest on problems → paste me the hardest one for review.

**Rhythm:** the plan is laid out as 7 weeks of ~10 hrs. Inside a week, split it however your Lynco schedule allows — five ~2hr evenings, or two big weekend blocks, whatever. The early weeks are deliberately light on LeetCode and heavy on *building things and STL reps*, exactly because you asked to code before it's interview-shaped. The problem count ramps up as your foundation comes back.

A `[stretch]` tag means: skip it if you're short on time that week, it's the bonus rep.

---

## Week 1 — Foundations: C++/STL fluency + Big-O

**Why first:** everything downstream assumes you can reason about complexity and reach for the right STL container without thinking. We fix the STL gap and the complexity gap simultaneously, by building.

- **Read (your PDF):** Analysis of Algorithms / Big-Oh (pp. 964–994) — the seven functions, Big-Oh notation, asymptotic analysis, prefix-averages example. Then Array Lists (pp. 953–963) — array-based implementation and the **doubling vs. incremental growth** analysis.
- **C++/STL focus:** `vector`, `string`, `unordered_map`, `unordered_set`, `pair`, `sort`, range-`for`, `auto`, and — important — **references vs. copies** (`for (auto& x : v)` vs `for (auto x : v)`) and when you're accidentally copying. Learn `mp[key]++`, `mp.count(key)`, `mp.find(key)`, `s.insert`, `s.count`.
- **Build (from scratch, no STL):** your own `DynArray` class — an `int*` buffer, `push_back` that doubles capacity when full, `size`, `get(i)`. Then explain to me *why* push_back is amortized O(1) even though some pushes are O(n). This is the Array Lists slides made concrete.
- **Problems (easy — these are STL warmups as much as anything):**
  - LC 1 — Two Sum *(hash map)*
  - LC 217 — Contains Duplicate *(set)*
  - LC 242 — Valid Anagram *(frequency count)*
  - LC 121 — Best Time to Buy and Sell Stock *(single pass, running min)*
  - LC 26 — Remove Duplicates from Sorted Array *(in-place, two indices)*
- **Checkpoint:** you can state the Big-O of a loop nest on sight, and you can choose vector vs. unordered_map vs. unordered_set for a problem without hesitating.

---

## Week 2 — Arrays & strings: two pointers, sliding window, prefix sums

**Why here:** this is where the *largest* share of easy/medium interview questions live, and none of these patterns are in your textbook by name. Pure pattern-building on top of Week 1's container fluency.

- **Read (your PDF):** light week — skim Iterators / Containers / Sequence ADT (pp. 402–412) so STL iterators (`begin()`, `end()`, `it++`, `*it`) stop being mysterious.
- **Patterns:** two pointers (converging + fast/slow), sliding window (fixed + variable), prefix sums.
- **Build:** write a reusable **sliding-window template** and a **two-pointer template** as commented snippets you keep. Naming the skeleton makes it recallable under pressure.
- **Problems:**
  - Two pointers: LC 125 — Valid Palindrome · LC 167 — Two Sum II · LC 15 — 3Sum · LC 11 — Container With Most Water
  - Sliding window: LC 3 — Longest Substring Without Repeating Characters · LC 424 — Longest Repeating Character Replacement · LC 76 — Minimum Window Substring `[stretch — this one's genuinely hard]`
  - Prefix: LC 238 — Product of Array Except Self
- **Checkpoint:** given a "subarray/substring with property X" problem, you reach for sliding window automatically and can argue why it's O(n) not O(n²).

---

## Week 3 — Stacks, queues, linked lists, binary search

**Why here:** the first batch of "real" data structures, plus binary search (which trips up more people than it should). You'll *implement* the structures from the slides and *use* them on problems the same week.

- **Read (your PDF):** Stacks (pp. 59–79, incl. parentheses-matching and span) · Queues (pp. 256–265) · Linked Lists (pp. 385–401: Position/Node ADT, then singly-linked insert/remove at head/tail).
- **Patterns:** stack (including **monotonic stack**), linked-list pointer manipulation, binary search (incl. on rotated/2D).
- **Build:** a singly linked list (`insertHead`, `insertTail`, `reverse`) and a stack **from scratch** (array-backed). Ties directly to the Stacks and Linked Lists decks — and reversing a linked list by hand now means LC 206 is trivial later.
- **Problems:**
  - Stack: LC 20 — Valid Parentheses · LC 155 — Min Stack · LC 150 — Evaluate RPN · LC 739 — Daily Temperatures *(monotonic)*
  - Linked list: LC 206 — Reverse Linked List · LC 21 — Merge Two Sorted Lists · LC 141 — Linked List Cycle *(fast/slow)* · LC 19 — Remove Nth Node From End · LC 143 — Reorder List `[stretch]`
  - Binary search: LC 704 — Binary Search · LC 74 — Search a 2D Matrix · LC 153 — Find Minimum in Rotated Sorted Array · LC 33 — Search in Rotated Sorted Array
- **Checkpoint:** you can write a correct binary search (the `left <= right`, `mid`, `left = mid+1` boilerplate) without off-by-one bugs, and you recognize when "next greater element" means monotonic stack.

---

## Week 4 — Trees & recursion

**Why here:** trees are the gateway to thinking recursively, which then unlocks backtracking, graphs, and DP. Heavy interview territory.

- **Read (your PDF):** Trees / traversals (pp. 41–58: pre/in/post-order, binary trees, expression trees) · Binary Search Trees (pp. 890–899: search, insert, delete) · AVL Trees (pp. 922–932) — **skim** AVL, understand "self-balancing via rotations" conceptually, don't memorize the rotation cases.
- **Patterns:** tree DFS (recursive), tree BFS (queue / level-order), divide-and-return recursion.
- **Build:** a BST class — `insert`, `search`, and an **inorder traversal** that prints sorted order. This is the BST deck made real and explains *why* inorder of a BST is sorted.
- **Problems:**
  - Core DFS: LC 226 — Invert Binary Tree · LC 104 — Maximum Depth · LC 100 — Same Tree · LC 110 — Balanced Binary Tree · LC 543 — Diameter of Binary Tree
  - BFS: LC 102 — Level Order Traversal · LC 199 — Right Side View
  - BST: LC 700 — Search in a BST · LC 235 — LCA of a BST · LC 98 — Validate BST · LC 230 — Kth Smallest in a BST
  - LC 105 — Construct Tree from Preorder & Inorder `[stretch]`
- **Checkpoint:** you can write a recursive tree function by asking "what do I return from a node given its children's answers?" and you can do level-order with a queue without looking it up.

---

## Week 5 — Heaps, priority queues, backtracking

**Why here:** heaps unlock the entire "top-K / Kth largest" family (extremely common), and backtracking is the recursion pattern behind subsets/permutations/combinations.

- **Read (your PDF):** Priority Queues (pp. 266–276, incl. selection & insertion sort as PQ-sorts) · Heaps (pp. 413–441: upheap/downheap, heap-sort, **bottom-up heap construction**).
- **Patterns:** heap / top-K, backtracking (the choose → recurse → un-choose skeleton).
- **Build:** a binary **min-heap** from scratch (`push` with upheap, `pop` with downheap). Then compare against `std::priority_queue` and learn the `priority_queue<int, vector<int>, greater<int>>` incantation for a *min*-heap (this exact line shows up constantly and is easy to forget).
- **Problems:**
  - Heap: LC 703 — Kth Largest in a Stream · LC 1046 — Last Stone Weight · LC 215 — Kth Largest Element in an Array · LC 347 — Top K Frequent Elements · LC 973 — K Closest Points to Origin
  - Backtracking: LC 78 — Subsets · LC 39 — Combination Sum · LC 46 — Permutations · LC 90 — Subsets II · LC 79 — Word Search `[stretch]`
- **Checkpoint:** "Kth largest / smallest / closest" → heap, reflexively, and you can write the backtracking template (path, choices, base case, un-choose) on a blank page.

---

## Week 6 — Graphs: BFS/DFS, topological sort, union-find

**Why here:** graphs feel scary but most interview graph problems are just BFS/DFS on a grid. We build the representation, then drill the patterns.

- **Read (your PDF):** Graphs / representations (pp. 458–470: edge list, adjacency list, adjacency matrix) · DFS (pp. 605–619) · BFS (pp. 900–910) · DAGs & Topological Sort (pp. 547–560) · Union-Find (pp. 1–14) · Shortest Paths (pp. 123–139) — **skim** Dijkstra/Bellman-Ford, understand the idea, only the `[stretch]` problem requires coding it.
- **Patterns:** grid/graph BFS & DFS, topological sort (Kahn's / DFS), union-find with path compression.
- **Build:** a graph as an **adjacency list** (`vector<vector<int>>` or `unordered_map<int, vector<int>>`) with both BFS and DFS traversal; plus a **union-find** with `find` (path compression) and `union`. The union-find directly mirrors the Union-Find deck and makes LC 684 a 10-minute problem.
- **Problems:**
  - Grid BFS/DFS: LC 200 — Number of Islands · LC 695 — Max Area of Island · LC 994 — Rotting Oranges · LC 417 — Pacific Atlantic Water Flow `[stretch]`
  - Graph DFS: LC 133 — Clone Graph
  - Topo sort: LC 207 — Course Schedule · LC 210 — Course Schedule II
  - Union-find: LC 323 — Number of Connected Components · LC 684 — Redundant Connection
  - LC 743 — Network Delay Time *(Dijkstra)* `[stretch]`
- **Checkpoint:** you can set up an adjacency list from an edge list, run BFS or DFS over it without looking, and you recognize "are these things connected / how many groups" → union-find or DFS.

---

## Week 7 — Dynamic programming, greedy, intervals + mock review

**Why last:** DP is the hardest pattern and builds on the recursion you've now drilled for three weeks. This is the section *missing from your deck entirely*, so it's all NeetCode-sourced. We close with timed mock problems to simulate the real thing.

- **Read:** your deck is thin here — skim Merge Sort (pp. 341–357) and Quick-Sort (pp. 222–238) for the divide-and-conquer mindset, which is DP's cousin. The DP learning is from NeetCode's "1-D / 2-D Dynamic Programming" sections.
- **Patterns:** 1-D DP (the "what's the recurrence + memoize" move), 2-D DP intro, greedy, intervals.
- **Build:** take **one** problem (LC 70 Climbing Stairs) and solve it **three ways** — naive recursion, top-down memoized, bottom-up table — so you *feel* what DP is doing rather than memorizing it.
- **Problems:**
  - 1-D DP: LC 70 — Climbing Stairs · LC 198 — House Robber · LC 213 — House Robber II · LC 322 — Coin Change · LC 300 — Longest Increasing Subsequence · LC 139 — Word Break
  - 2-D DP intro: LC 62 — Unique Paths · LC 1143 — Longest Common Subsequence
  - Greedy: LC 53 — Maximum Subarray *(Kadane)* · LC 55 — Jump Game
  - Intervals: LC 56 — Merge Intervals · LC 57 — Insert Interval · LC 435 — Non-overlapping Intervals
- **Mock finale:** two **blind** medium problems (ones not on this list — I'll pick) under a **35-minute timer each**, talking through your approach out loud as if I'm the interviewer. Then a full debrief.
- **Checkpoint:** given a "count the ways / min cost / longest X" problem you can ask "what's the subproblem and the recurrence?", and you can sit a timed medium without freezing.

---

## After Day 50 — where you'll be and what's next

You'll have built every core structure by hand, solved ~70 problems across all the major patterns, and gotten comfortable enough with C++ that the language isn't the bottleneck. That's interview-ready for the easy/medium screens that dominate fall recruiting.

Natural continuations when you're ready: a second DP pass (it always needs two), the advanced graph algorithms you skimmed (Dijkstra/Bellman-Ford properly), and **timed mock interviews** — the single highest-leverage thing once the patterns are in. Spaced repetition matters too: re-solve a problem from 3 weeks ago cold and you'll see what actually stuck.

---

## Appendix: topic → page map for your PDF

Your PDF is scrambled and every deck is duplicated; these are the **first occurrence** of each topic. Pages ~634–865 and several blank stretches are corrupted/embedded junk — ignore them.

| Topic | Pages | Plan week |
|---|---|---|
| Analysis of Algorithms / Big-Oh | 964–994 | 1 |
| Array Lists (dynamic arrays, doubling) | 953–963 | 1 |
| Iterators / Containers / Sequence ADT | 402–412 | 2 |
| Stacks | 59–79 | 3 |
| Queues | 256–265 | 3 |
| Linked Lists | 385–401 | 3 |
| Trees / traversals | 41–58 | 4 |
| Binary Search Trees | 890–899 | 4 |
| AVL Trees *(skim)* | 922–932 | 4 |
| Priority Queues | 266–276 | 5 |
| Heaps | 413–441 | 5 |
| Maps | 375–384 | (ref) |
| Hash Tables | 442–457 | (ref) |
| Dictionaries | 596–604 | (ref) |
| Graphs / representations | 458–470 | 6 |
| Depth-First Search | 605–619 | 6 |
| Breadth-First Search | 900–910 | 6 |
| DAGs / Topological Sort | 547–560 | 6 |
| Union-Find | 1–14 | 6 |
| Shortest Paths *(skim)* | 123–139 | 6 |
| Minimum Spanning Trees | 307–323 | (ref) |
| Merge Sort | 341–357 | 7 |
| Quick-Sort | 222–238 | 7 |
| Bucket / Radix Sort | 204–212 | (ref) |
| Sorting Lower Bound | 80–89 | (ref) |
| C++ Templates | 866–889 | (ref) |
| **Skip for interviews:** Red-Black Trees | 162–203 | — |
| **Skip:** (2,4) Trees | 995–1008 | — |
| **Skip:** Tries / Suffix Tries / Huffman | 15–40 | — |
| **Skip:** Pattern Matching (KMP/Boyer-Moore) | 277–302 | — |
| **Skip:** Regular Expressions / Finite Automata | 484–525 | — |
| **Skip:** Floyd-Warshall / Directed-graph closure | 526–546 | — |
| **Skip:** Sets / Generic Merge | 157–161 | — |

*("ref" = useful background you can read if curious, but not on the critical interview path.)*
