*This project has been created as part of the 42 curriculum by nkato, kkajikaw.*

# push_swap

## Description

`push_swap` is a C program that sorts a list of unique integers in ascending order.
It does not move values freely: it must generate a sequence composed only of the
11 operations allowed by the subject and operate on two stacks, `a` and `b`.

The first argument is the top of stack `a`, and stack `b` starts empty. The program
writes only sorting operations to standard output. Its main purpose is to compare
algorithmic complexity using the number of generated Push_swap operations as the
cost model.

This implementation contains all four required strategies:

| Strategy | Option | Algorithm | Operation upper bound |
|---|---|---|---|
| Simple | `--simple` | Minimum extraction / selection sort | O(n²) |
| Medium | `--medium` | √n-sized chunk sort | O(n√n) |
| Complex | `--complex` | Binary LSD radix sort | O(n log n) |
| Adaptive | `--adaptive` | Selects a strategy from the initial disorder | Depends on the selected regime |

`--adaptive` is used when no strategy option is given.

## Instructions

### Build

Requirements are a C compiler, `make`, and a POSIX-like environment.

```sh
make
```

The Makefile builds the `push_swap` executable with `cc` and the flags
`-Wall -Wextra -Werror`.

Other available rules are:

```sh
make clean   # Remove object files
make fclean  # Remove object files and the executable
make re      # Rebuild the project from scratch
```

### Run

```sh
./push_swap [--bench] [--simple|--medium|--complex|--adaptive] <integer ...>
```

The benchmark and strategy options may appear in either order, but they must come
before the integers. A benchmark option or strategy option cannot be repeated, and
only one strategy may be selected.

Examples:

```sh
./push_swap 2 1 3 6 5 8
./push_swap --simple 5 4 3 2 1
./push_swap --complex --bench 4 67 3 87 23
./push_swap --bench --adaptive -3 8 0 -10 4
```

With no arguments, the program prints nothing. Invalid integers, values outside the
`int` range, duplicate values, unknown options, or conflicting options produce
`Error\n` on standard error and a non-zero exit status.

### Validate the operation stream

When a compatible checker supplied for evaluation is available, the output can be
validated as follows:

The following command relies on POSIX `sh`/Bash word splitting. In zsh, replace
each `$ARG` with `${=ARG}`.

```sh
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG
```

A correctly sorted stack produces `OK` from the checker.

## Allowed operations

| Operation | Effect |
|---|---|
| `sa`, `sb` | Swap the first two elements of `a` or `b` |
| `ss` | Execute `sa` and `sb` together |
| `pa`, `pb` | Push the top element onto `a` or `b` |
| `ra`, `rb` | Rotate `a` or `b`; the first element becomes the last |
| `rr` | Execute `ra` and `rb` together |
| `rra`, `rrb` | Reverse-rotate `a` or `b`; the last element becomes the first |
| `rrr` | Execute `rra` and `rrb` together |

Each generated operation is followed by `\n`; no diagnostic text is mixed into the
standard-output operation stream.

## Algorithm design and rationale

### Coordinate compression

Before sorting, each node receives a rank from `0` to `n - 1` according to its value.
The original integer values remain unchanged, while the ranks provide a compact,
non-negative range for chunk boundaries and bitwise radix sorting. This also allows
negative values and the complete `int` range to be handled uniformly.

### Disorder metric

Disorder is measured before any operation is executed. For every pair `i < j`, the
pair counts as a mistake when `a[i] > a[j]`:

```text
disorder = number_of_inversions / number_of_pairs
```

It lies between `0` and `1`: `0` is already sorted and `1` is reverse-sorted. The
calculation examines every pair, so its C-side analysis time is O(n²), but it emits no
Push_swap operation.

### Simple: minimum extraction

The Simple strategy repeatedly finds the minimum value remaining in `a`. It chooses
`ra` or `rra`, whichever brings that value to the top with fewer operations, then
pushes it to `b` with `pb`. Once the remaining part of `a` is sorted, all saved values
are restored with `pa`.

At most O(n) rotations are needed for each of O(n) extracted values, giving an O(n²)
upper bound in the Push_swap operation model. This strategy was selected as a clear
baseline with simple invariants and predictable behavior.

### Medium: chunk sort

The Medium strategy uses chunks whose width is approximately `√n` ranks. It scans
`a` once for each rank interval: values in the current interval are pushed to `b`, and
other values are rotated in `a`. After all chunks have been transferred, the maximum
remaining value in `b` is brought to the top with the shorter of `rb` and `rrb`, then
pushed back to `a`.

There are O(√n) chunks and each distribution scan costs at most O(n) operations.
Values belonging to the same chunk remain grouped in `b`, bounding the restoration
work by O(√n) rotations per value. The resulting operation upper bound is O(n√n).
This provides a middle ground between the baseline and radix strategies.

### Complex: binary LSD radix sort

The Complex strategy processes compressed ranks from the least-significant bit to the
most-significant bit. For each bit, a zero bit is sent to `b` with `pb`, while a one bit
is kept in `a` with `ra`. All values in `b` are then returned with `pa` before the next
bit is processed.

Ranks from `0` to `n - 1` require O(log n) bits, and every bit pass performs O(n)
operations. The operation upper bound is therefore O(n log n). Radix sort was chosen
because its cost is stable even for highly disordered inputs.

### Adaptive strategy

The Adaptive strategy uses the mandatory disorder boundaries:

| Initial disorder | Internal strategy | Operation upper bound |
|---|---|---|
| `disorder < 0.2` | Simple | O(n²) |
| `0.2 <= disorder < 0.5` | Medium | O(n√n) |
| `disorder >= 0.5` | Complex | O(n log n) |

Inputs of at most three values use a dedicated small-sort path. For larger inputs,
low-disorder data uses the straightforward baseline, medium-disorder data uses chunk
partitioning, and high-disorder data uses the input-order-independent radix passes.
These thresholds satisfy the regimes specified by the subject while selecting the
more scalable strategy as disorder increases.

All strategies store the input as linked-list nodes, so total program storage is O(n).
The sorting procedures allocate no additional array proportional to `n`; excluding the
input stacks, their auxiliary space is O(1).

## Benchmark mode

`--bench` leaves the operation stream on standard output and writes metrics to
standard error after sorting. It reports:

- Initial disorder as a percentage with two decimal places.
- Selected strategy and the corresponding theoretical complexity class.
- Total generated operation count.
- Individual counts for `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`,
  `rrb`, and `rrr`.

Example that keeps the two streams separate:

This example also targets POSIX `sh`/Bash. In zsh, replace each `$ARG` with
`${=ARG}`.

```sh
ARG="4 67 3 87 23"
./push_swap --bench --complex $ARG 2> bench.txt | ./checker_linux $ARG
cat bench.txt
```

The subject's required performance thresholds for random inputs are:

| Input size | Minimum requirement | Good | Excellent |
|---|---:|---:|---:|
| 100 | fewer than 2000 operations | fewer than 1500 | fewer than 700 |
| 500 | fewer than 12000 operations | fewer than 8000 | fewer than 5500 |

## Resources
- [基数ソート - Wikipedia](https://ja.wikipedia.org/wiki/%E5%9F%BA%E6%95%B0%E3%82%BD%E3%83%BC%E3%83%88) —
  Radix Sortの基本概念

- [Push swapアルゴリズム実装メモ：座標圧縮の活用](https://qiita.com/jiku0730/items/f5ba2878b03bf967dd33) —
  座標圧縮の考え方

- [push_swap MoriP Sort 42Tokyo #1](https://qiita.com/MoriP-K/items/54ee96dc634148cf40a8) —
  Push_swapにおけるソート設計

- [APG4b: 計算量](https://atcoder.jp/contests/apg4b/tasks/APG4b_w?lang=ja) —
  Big-O記法と計算量

- *Push_swap subject, version 1.1* — 本課題の要件

### Use of AI

- AI was used to help understand code written by teammates and assist with test
  execution.

- AI was used to help choose variable names, understand sorting concepts, and learn
  Git workflows.

- AI was used to summarize and translate the assignment requirements.

- AI was used as a supplementary tool for design discussions, code improvements, and
  brainstorming.

- AI was used to extract the README requirements from the subject PDF and help
  structure this document against the implemented code and Git history.

We use generative AI strictly for auxiliary purposes, and whenever we use AI, we discuss the generated content as appropriate, compare it with the source code, and verify it as necessary using local tools. Both team members continue to bear the responsibility for understanding and explaining
all submitted code and documentation.


## Team contributions

The contribution summary below is based on the repository's Git history. Both members
also participated in integration, review, minor changes to the source code, debugging, Norm compliance, and testing.

| Login | Main contributions |
|---|---|
| `nkato` | Initial stack/list foundation, input parsing and validation, early disorder calculation, Medium chunk-sort implementation, context integration, implementation of `ft_printf`, option-order handling, final integration fixes, and README development. |
| `kkajikaw` | Rotate/reverse-rotate operations, rank-based coordinate compression, Simple and Complex strategies, small-input and Adaptive dispatch, benchmark/statistics output, disorder formatting, Norm refactoring, and README development. |
