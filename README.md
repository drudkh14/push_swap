*This project has been created as part of the 42 curriculum by zbohdanc, kateslia*

# push_swap

## Description

`push_swap` is an algorithmic project from the 42 curriculum. The goal is to sort a stack of random, unique integers into ascending order using a second, empty stack as temporary space, a restricted set of stack operations, and as few operations as possible.

The program takes a list of integers as arguments (as a single string or as several arguments), pushes them onto stack `a`, and outputs — one per line, to standard output — the exact sequence of operations required to sort stack `a` in ascending order, using stack `b` only as intermediate storage. Only the following operations are allowed: `pa`, `pb`, `sa`, `sb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

The project has two evaluation dimensions:
- **Correctness** — the input must be validated and the output must actually sort the stack, including on edge cases (empty input, already sorted input, duplicates, non-numeric characters, integer overflow, etc.).
- **Efficiency** — for large inputs (100 and 500 numbers), the number of operations produced must stay under project-defined thresholds, which pushes the choice of sorting strategy far beyond a naive algorithm like insertion or selection sort.

A companion `checker` program (provided by 42) reads a sequence of operations from standard input and applies them to the initial stack to confirm whether the result is correctly sorted.

## Instructions

### Compilation

```bash
make
```

This builds the `push_swap` executable (and `checker`, if included in the repository) using the project's `Makefile`.

Other Makefile targets:

```bash
make clean  # removes object files
make fclean # removes object files and the binary
make re     # rebuilds everything from scratch
```

### Execution

```bash
./push_swap "2 1 3 6 5 8"
```

or, equivalently:

```bash
./push_swap 2 1 3 6 5 8
```

The program prints the list of operations needed to sort the stack, one per line, to standard output. On invalid input (non-numeric characters, duplicates, or integer overflow), it prints `Error` to standard error and exits.

#### Flags

| Flag          | Description                                        | Complexity                   |
| ------------- | -------------------------------------------------- | ---------------------------- |
| `--simple`    | Simple sorting strategy                            | `O(n²)`                      |
| `--medium`    | Medium-complexity sorting strategy                 | `O(n√n)`                     |
| `--complex`   | Advanced sorting strategy                          | `O(n log n)`                 |
| `--adaptive`  | Automatically chooses a strategy based on disorder | Depends on selected strategy |
| `--benchmark` | Prints additional sorting statistics to `stderr`   | —                            |

Flags must appear **before the input numbers**.

For example:

```bash
./push_swap --benchmark --adaptive 7 2 9 1 5 3
```

### Checking a Sort

```bash
ARG="2 1 3 6 5 8"
./push_swap $ARG | ./checker $ARG
```

`checker` prints `OK` if the operations correctly sort the stack, `KO` otherwise.

### Measuring Operation Count

```bash
shuf -i 0-9999 -n 500 > args.txt ; ./Push_swap --bench $(cat argc.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
```

## Operations

| Operation | Description |
|-----------|-------------|
| `pa` | Push top of `b` to top of `a` |
| `pb` | Push top of `a` to top of `b` |
| `sa` | Swap the first two elements of `a` |
| `sb` | Swap the first two elements of `b` |
| `ss` | `sa` and `sb` simultaneously |
| `ra` | Rotate `a` up (first element becomes last) |
| `rb` | Rotate `b` up (first element becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Rotate `a` down (last element becomes first) |
| `rrb` | Rotate `b` down (last element becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

## Example

Given the following input:

```bash
./push_swap 3 5 1 4 2
```

The program outputs a sequence of allowed operations, for example:

```text
pb
pb
sa
pa
pa
...
```

The exact sequence depends on the selected sorting algorithm.

The final state of Stack A must be:

```text
1 2 3 4 5
```

## Algorithms

The project contains several sorting algorithms corresponding to the available sorting modes.

### Simple — `O(n²)`

### Insertion Sort

#### Main Idea

The algorithm repeatedly extracts the **smallest element** from Stack A and moves it to Stack B. This continues until only five elements remain in A.

The remaining elements are sorted using specialized algorithms for small stacks. Finally, all elements from B are pushed back to A.

```text
A: [unsorted]       B: []

        ↓ extract minimum

A: [remaining]      B: [minimums]

        ↓ sort A

A: [sorted]         B: [minimums]

        ↓ pa

A: [sorted]         B: []
```

#### Implementation

For each minimum element, `find_index_minimum()` finds its position in A.

`ext_to_b()` then chooses the shortest rotation:

* `ra` if the element is in the first half;
* `rra` if the element is in the second half;
* `pb` moves it to B.

For an element at index `i` in a stack of size `n`, the cost is:

```text
min(i, n - i) + 1
```

where `+1` is the `pb` operation.

When five or fewer elements remain, `sort_small()` uses a specialized algorithm. The elements stored in B are then returned to A using `pa`.

---

#### Complexity in `push_swap` Operations

The complexity is measured by the number of generated `push_swap` instructions.

##### Already Sorted

Before selecting the sorting algorithm, the program calculates the disorder of the input.

If:

```text
disorder = 0
```

the stack is already sorted, so `insertion_sort()` is not executed.

```text
0 push_swap operations
```

##### Best Case

When sorting is required, the best case occurs when the minimum elements are already at or close to the top of A.

If every extracted minimum is already at index `0`, each extraction costs only:

```text
pb
```

There are `n - 5` extractions and the same number of `pa` operations when restoring B:

```text
2(n - 5) = O(n)
```

Therefore:

```text
Best case: O(n)
```

##### Average and Worst Case

The important part of the cost is the number of rotations.

Suppose the stack currently contains `k` elements. In the worst case, extracting one minimum requires approximately:

```text
k / 2 rotations
```

The algorithm performs this extraction while the stack size decreases from `n` to `6`.

Therefore, the total number of rotations is bounded by:

```text
n/2 + (n-1)/2 + (n-2)/2 + ... + 6/2
```

which can be written as:

```text
1/2 × (6 + 7 + 8 + ... + n)
```

Using the sum of consecutive integers:

```text
1/2 × (n(n + 1)/2 - 15)
```

The dominant term is:

```text
n² / 4
```

Therefore:

```text
Rotations = O(n²)
```

The `pb` operations during extraction and the `pa` operations used to restore the elements contribute only:

```text
2(n - 5) = O(n)
```

When only **4 or 5 elements** remain, `sort_four_five()` handles them using a fixed number of operations. Since the number of elements is constant, its cost is:

```text
O(1)
```

The final `sort_small()` phase therefore does not affect the overall asymptotic complexity.

Consequently:

```text
O(n²) + O(n) + O(1) = O(n²)
```

Therefore:

| Case           | `push_swap` operations |
| -------------- | ---------------------: |
| Already sorted |                  **0** |
| Best case      |               **O(n)** |
| Average case   |              **O(n²)** |
| Worst case     |              **O(n²)** |

#### Advantages

* Simple and predictable.
* Chooses the shortest rotation direction.
* Efficient for small or nearly sorted inputs.
* Produces no operations when the input is already sorted.

#### Limitations

* Quadratic average and worst-case complexity.
* Repeated minimum searches and rotations become expensive for large inputs.
* Less efficient than algorithms with `O(n√n)` or `O(n log n)` complexity.

### Medium — `O(n√n)`

### Chunk Sort

#### Main Idea

The algorithm divides the elements into **chunks** of approximately `√n` elements.

Before sorting, `index_stack()` replaces the original values with their relative indices from `0` to `n - 1`. This allows the algorithm to work with the relative order of the elements rather than their actual values.

The chunk size is calculated as:

```text
chunk_size = √n
```

This creates approximately `√n` chunks, each containing approximately `√n` elements.

The main idea is to move elements from A to B in a **partially ordered way**, so that they can later be extracted from B with fewer rotations.

---

#### Implementation

The variable `i` represents the current position in the sorted order. The algorithm processes elements belonging to the current range:

```text
[i, i + chunk_size)
```

For each element at the top of A, there are three cases.

If:

```c
value <= i
```

the element belongs to an already processed part of the sequence. It is pushed to B and immediately rotated:

```text
pb
rb
```

The `rb` moves this smaller element to the bottom of B. It is not needed immediately, so keeping it at the bottom prevents it from occupying the top position.

If:

```c
value < i + chunk_size
```

the element belongs to the current chunk and is simply pushed to B:

```text
pb
```

It therefore remains near the top of B.

If the element does not belong to the current chunk:

```text
ra
```

is used to continue scanning A.

After an element from the current range is pushed, `i` is incremented. This moves the lower boundary of the processed range forward and allows the algorithm to gradually progress through the sorted order.

As a result, B becomes partially organized:

```text
top
 ↓
larger / currently useful elements
...
smaller / already processed elements
 ↓
bottom
```

The purpose is not to completely sort B, but to arrange it in a way that makes the next phase cheaper.

---

#### Extracting Elements from B

After all elements have been moved from A to B, the algorithm rebuilds A using `ext_to_a()`.

For each required element, `ext_to_a()` receives its index in B and chooses the shorter rotation direction:

After the required element reaches the top of B, it is moved to A with:

```text
pa
```

Therefore, extracting one element costs:

```text
min(index, b->len - index) + 1
```

where `+1` is the `pa` operation.

The organization created during the first phase is important here. Smaller elements are deliberately moved towards the bottom of B with `rb`, while elements from the current chunk remain closer to the top. This increases the probability that the element required next can be reached with a relatively small number of rotations.

Thus, the algorithm performs some additional `rb` operations while filling B in order to reduce the rotation cost when `ext_to_a()` later extracts the elements.

> **B is not completely sorted. Instead, it is partially organized to make `ext_to_a()` more efficient.**

---

#### Why `√n`?

Let `k` be the chunk size.

The number of chunks is approximately:

```text
n / k
```

A very small chunk creates many chunks and requires more processing, while a very large chunk puts too many elements into B without providing enough separation between them.

Choosing:

```text
k = √n
```

gives:

```text
n / √n = √n chunks
```

with approximately `√n` elements per chunk.

This provides a practical balance between scanning A and organizing B.

#### Complexity in `push_swap` Operations

For `n > 5`, each element is pushed from A to B exactly once:

```text
pb = O(n)
```

Each element satisfying `value <= i` also causes one `rb`, so:

```text
rb = O(n)
```

The main cost of the first phase comes from `ra`. With approximately `√n` chunks and potentially a linear scan of A for each chunk:

```text
O(n) × O(√n) = O(n√n)
```

The extraction phase uses `ext_to_a()` to move every element from B to A. Each element requires one `pa`, while the chunk organization reduces the amount of rotation needed to reach the next element.

The overall operation count is therefore bounded by:

```text
O(n√n)
```

For `n ≤ 5`, `sort_small()` is used and has constant cost:

```text
O(1)
```

### Complexity Summary

| Case         | `push_swap` operations |
| ------------ | ---------------------: |
| `n ≤ 5`      |               **O(1)** |
| Best case    |             **O(n√n)** |
| Average case |             **O(n√n)** |
| Worst case   |             **O(n√n)** |

#### Advantages

* Better scalability than the `O(n²)` insertion strategy.
* Uses `√n`-sized chunks to balance processing and chunk size.
* Partially organizes B during the first phase.
* Uses `ext_to_a()` to select the shortest rotation direction when extracting elements.
* The organization of B reduces unnecessary rotations during extraction.

#### Limitations

* Still requires a significant number of rotations.
* Performance depends on the chosen chunk size.
* Usually produces more operations than a well-optimized `O(n log n)` strategy.

### Complex — `O(n log n)`

### Quick Sort

#### Main Idea

This algorithm is based on **Quick Sort**, adapted to the two-stack structure and the limited `push_swap` instruction set.

Instead of using a single pivot, the algorithm uses **two pivots** to divide the elements into three approximately equal groups:

```text
                 values
                    │
          ┌─────────┼─────────┐
          │         │         │
        small     middle     large
          │         │         │
         < p1     p1 .. p2    >= p2
```

The pivots are selected at approximately the `1/3` and `2/3` positions of the sorted values:

```c
p1 = arr[n / 3];
p2 = arr[n * 2 / 3];
```

This allows the algorithm to recursively work with smaller groups instead of repeatedly processing the whole stack.

Before starting the recursive partitioning, the algorithm checks the disorder of the current part. If it is already sorted, no operations are performed.

---

#### Partitioning

`partition_a()` and `partition_b()` divide the current part of a stack using the two pivots.

When partitioning Stack A:

* values `>= p2` remain in A and are rotated with `ra`;
* values `>= p1` and `< p2` are pushed to B and organized using `rb`;
* values `< p1` are pushed to B as another group.

The algorithm keeps track of how many elements belong to each group using `t_part_res`.

The same idea is applied in the opposite direction by `partition_b()` when processing Stack B.

The goal is to obtain three logically separated groups that can be processed independently by recursive calls.

---

#### Optimizing Rotations

The algorithm uses the combined operations `rr` and `rrr` whenever both stacks need to be rotated in the same direction.

For example:

```text
ra + rb → rr
rra + rrb → rrr
```

Instead of generating two instructions, one combined instruction performs both rotations.

This does not change the asymptotic complexity, but it can significantly reduce the actual number of `push_swap` operations.

The `restore_stacks_a()` and `restore_stacks_b()` functions use the same idea when undoing rotations after partitioning.

---

#### Recursive Structure

After partitioning, the algorithm recursively sorts the resulting groups.

For Stack A:

```c
quick_sort_a(a, b, get_rotated(n, part_res), operations);
quick_sort_b(a, b, part_res->pushed_rotated, operations);
quick_sort_b(a, b, part_res->pushed, operations);
```

For Stack B, the process works in the opposite direction.

The partition divides the elements into approximately three groups of size `n / 3`. Therefore, the recursive structure can be represented as:

```text
                    n
              ┌─────┼─────┐
              ↓     ↓     ↓
             n/3   n/3   n/3
              │     │     │
             ...   ...   ...
```

Although there are three recursive branches, the important property is that **every element belongs to exactly one branch**. Therefore, the total amount of data processed at each recursion level remains proportional to `n`.

---

#### Why Is the Recursion Depth `O(log n)`?

At every recursion step, the largest subproblem is reduced by a constant factor. In this implementation, it is bounded by approximately:

```text
2n / 3
```

After one level, the largest possible subproblem has size:

```text
n × (2/3)
```

After two levels:

```text
n × (2/3)²
```

After `k` levels:

```text
n × (2/3)^k
```

The recursion stops when the size becomes constant:

```text
n × (2/3)^k ≤ 1
```

Solving for `k`:

```text
(2/3)^k ≤ 1/n

k = O(log n)
```

Therefore, the recursion has logarithmic depth because the size of the largest subproblem decreases by a constant factor at every level.

---

#### Complexity Proof

The complexity here is measured by the number of generated `push_swap` instructions.

For one partitioning level, every element of the current part is processed at most once. Each element causes only a constant number of operations such as:

```text
ra
rb
pa
pb
rr
rrr
```

Therefore, one partitioning level costs:

```text
O(n)
```

Restoring the stacks also processes only the rotations recorded during partitioning. Its cost is bounded by the number of elements in the current parts, so it is also:

```text
O(n)
```

Thus, the total work on one recursion level remains:

```text
O(n)
```

The recursion has `O(log n)` levels. Therefore:

```text
O(n) × O(log n)
        ↓
   O(n log n)
```

This can also be expressed using the recurrence:

```text
T(n) = 3T(n/3) + O(n)
```

where the three recursive subproblems contain approximately `n/3` elements each.

Using the Master Theorem:

```text
a = 3
b = 3
f(n) = O(n)

n^(log_b(a))
= n^(log_3(3))
= n
```

Since `f(n) = Θ(n)`, the recurrence gives:

```text
T(n) = Θ(n log n)
```

Therefore, the sorting algorithm has:

```text
O(n log n)
```

complexity in terms of `push_swap` operations.

The `rr` and `rrr` optimizations reduce the actual number of instructions by combining two rotations into one, but they do not change the asymptotic complexity.

---

#### Small Inputs and Early Exits

For `n <= 5`, the algorithm uses `sort_small()`. Since the number of elements is fixed, this requires:

```text
O(1)
```

operations.

Before performing recursive partitioning, `quick_sort_a()` and `quick_sort_b()` also check the disorder of the current part.

If a part is already sorted, the algorithm immediately returns without generating any operations for that part.

For Stack B, additional checks handle already reversed or appropriately ordered parts directly.

These optimizations can significantly reduce the number of operations for already or partially sorted inputs, while the worst-case asymptotic complexity remains `O(n log n)`.

---

#### Pivot Calculation

The pivots are calculated by copying the current values into an array and sorting it:

```c
quick_sort(arr, 0, n - 1);
```

This operation is used only to determine the pivot values and does **not** generate `push_swap` instructions.

Therefore, its computational complexity should be considered separately from the complexity of the sorting algorithm measured in `push_swap` operations.

---

### Complexity Summary

| Case         | `push_swap` operations |
| ------------ | ---------------------: |
| `n <= 5`     |               **O(1)** |
| Best case    |               **O(n)** |
| Average case |         **O(n log n)** |
| Worst case   |         **O(n log n)** |

The main advantage of this algorithm is that it combines **recursive three-way partitioning**, **optimized stack rotations**, and **early disorder checks** to achieve `O(n log n)` asymptotic complexity while keeping the number of generated `push_swap` instructions relatively low.

---

## Team & Task Distribution

### Infrastructure, Parsing & Memory Management (kateslia)

- **Input Parsing & Validation** — Handled both single-string and multi-argument input formats (`ft_split`), with strict validation for non-numeric characters, duplicate values, and `INT_MAX` / `INT_MIN` overflow.
- **Data Structure & Stack Operations** — Designed the doubly-linked list backing the stacks and implemented all 11 core operations (`pa`, `pb`, `sa`, `sb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`), each running in O(1).
- **Memory Management & Error Handling** — Built leak-free cleanup routines (`free_stack`, `free_matrix`) and safe error handling that exits cleanly with `Error` printed to `stderr`.
- **Small Sets Optimization** — Wrote dedicated, hardcoded sorting logic for small stacks (≤ 3 elements).

### Algorithm & Optimization (zbondanc)

- **Large Stack Sorting** — Implemented the main sorting algorithm (Turk Sort) for handling 100- and 500-element stacks efficiently.
- **Cost Calculation Engine** — Built the target-node lookup and cost-evaluation logic to determine the cheapest element to push at each step.
- **Dual Rotation Optimization** — Combined simultaneous rotations (`rr` / `rrr`) to reduce the total number of operations.
- **Disorder Metric** — Implemented `compute_disorder` to measure how unsorted a stack is and adapt the sorting strategy accordingly.

## Resources

- [42 push_swap subject (topic overview and constraints)](https://cdn.intra.42.fr/pdf/pdf/44300/en.subject.pdf)
- Wikipedia: [Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- Wikipedia: [Quicksort](https://en.wikipedia.org/wiki/Quicksort) — background for the 3-way pivot partitioning used for heavily shuffled stacks
- Wikipedia: [Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort) — background for the chunk/range-based distribution used for moderately shuffled stacks
- Wikipedia: [Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort) — background for the strategy used on nearly-sorted stacks
- Wikipedia: [Inversion (discrete mathematics)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)) — relevant to the disorder/inversion-counting metric used to choose a strategy

### AI Usage

AI (Claude, by Anthropic) was used only for documentation, not for implementation:

- Drafting and structuring this README.md (Description, Instructions, Resources, and Algorithms sections), based on notes and a contribution breakdown provided by the team.
- Rephrasing the team's own descriptions of their contributions for clarity and consistency.
- Help with understanding the subject (Gemini, ChatGPT).

All parsing, data structures, stack operations, sorting algorithm, cost calculation, and memory management code were designed and written by the team members listed above without AI assistance.
