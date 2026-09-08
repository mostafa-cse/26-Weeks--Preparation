# 26 Weeks Preparation

A focused C++ practice repository for preparing for ICPC-style problem solving.
The study flow is inspired by the [ICPC Preparation 16-week plan](https://mostafa-cse.github.io/icpc-preparation/): learn one small group of techniques, solve representative problems, review mistakes, and track progress consistently.

## Goals

- Build strong fundamentals before moving to advanced algorithms.
- Practice recognizing common problem patterns under time pressure.
- Keep short, readable C++ solutions that can be reviewed later.
- Turn every failed attempt into a note, a corrected solution, or a new test case.

## Roadmap

This repository uses a 26-week schedule so the shorter website plan can be expanded with more implementation and review time.

| Weeks | Focus | Target outcome |
| --- | --- | --- |
| 1-2 | C++ toolkit, input/output, complexity, debugging | Write and test a clean solution quickly |
| 3-4 | Arrays, strings, sorting, custom comparators | Identify ordering and simulation patterns |
| 5-6 | Stacks, queues, deques, priority queues | Choose the right container for each operation |
| 7-8 | Sets, maps, multisets, coordinate compression | Maintain frequencies and ordered data |
| 9-10 | Prefix sums, two pointers, sliding window | Reduce repeated work in array problems |
| 11-12 | Binary search and greedy algorithms | Prove a monotonic or locally optimal choice |
| 13-14 | Recursion, backtracking, bit manipulation | Enumerate states without losing control of complexity |
| 15-16 | Trees, heaps, disjoint set union | Model hierarchical and connectivity problems |
| 17-18 | Graph traversal: BFS, DFS, shortest paths | Build and traverse graph models confidently |
| 19-20 | Dynamic programming fundamentals | Define states, transitions, and base cases |
| 21-22 | Advanced DP, range techniques, number theory | Expand the contest toolkit |
| 23-24 | Mixed virtual contests | Practice pacing and problem selection |
| 25 | Weak-topic repair and targeted sets | Close the largest knowledge gaps |
| 26 | Final review and contest simulation | Solve a full set under contest conditions |

## Current Progress

### Week 1: Foundation and Toolkit

| Status | Practice |
| --- | --- |
| Done | Palindrome checking with string reversal |
| Done | Min-heap behavior using `priority_queue` |
| Done | Sorting records with multiple tie-breakers |
| Done | Josephus simulation with PBDS order statistics |
| Next | Queue arrangement implementation |

Solutions are currently grouped in [`1_Foundation_and_Toolkit`](1_Foundation_and_Toolkit/).

## Repository Structure

```text
.
├── 1_Foundation_and_Toolkit/
│   ├── P_1160_Queue_Arrangement.cpp
│   ├── P_1996_约瑟夫问题.cpp
│   ├── Palindromes_easy_version.cpp
│   ├── 堆.cpp
│   └── 奖学金.cpp
├── .gitignore
└── README.md
```

## Practice Workflow

1. Select the next topic from the roadmap or the website plan.
2. Solve the problem without looking at an editorial first.
3. Test edge cases and estimate time and memory complexity.
4. Save the solution using the problem identifier and a descriptive filename.
5. Review the solution after the practice session and record the key idea or mistake.
6. Revisit failed problems during the weekly review day.

## Building a Solution

The solutions use GNU C++17-style headers and are intended for competitive-programming judges.

```bash
g++ -std=c++17 -O2 -Wall -Wextra \
	1_Foundation_and_Toolkit/Palindromes_easy_version.cpp \
	-o /tmp/palindrome
/tmp/palindrome
```

Replace the source path with the problem you want to test. Some solutions use GNU extensions such as PBDS, so compile with `g++` rather than a strictly portable C++ compiler.

## Progress Tracking

Use the [ICPC preparation website](https://mostafa-cse.github.io/icpc-preparation/) as the weekly planning and progress dashboard. Use this repository for the corresponding source code, experiments, and review material. A week is complete when the topic has been studied, the planned problems have been attempted, and the mistakes have been reviewed.

## License

This is a personal practice repository. Problem statements and platform-specific test data remain the property of their respective platforms.
