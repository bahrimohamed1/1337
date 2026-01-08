*This project has been created as part of the 42 curriculum by mbahri.*

# push_swap (+ checker)

## Description
`push_swap` is a sorting project where you must sort a stack of integers (stack A) using a constrained set of stack operations and an auxiliary stack (stack B). The challenge is to output the shortest possible sequence of valid operations to sort the input in ascending order.

You will provide:
- `push_swap`: reads numbers from the command line and prints the sequence of operations to sort them.
- `checker` (bonus): reads the same numbers, then reads operations from standard input and applies them; it prints `OK` if A is sorted and B is empty, otherwise `KO`. It must print `Error` on invalid input or instruction.

Allowed external functions:
- `read`, `write`, `malloc`, `free`, `exit`
- `ft_printf` (or any equivalent you wrote)
- `get_next_line` (for the checker’s stdin reading)

Libft is authorized.

### Input format
- The program accepts a list of integers via argv. Arguments may be provided as:
  - Separate tokens: `./push_swap 3 2 1`
  - Space-separated strings: `./push_swap "3 2" "1"`
- Duplicates, non-integers, and out-of-`int`-range values are errors.
- No output if no arguments are provided.

### Operations
You can only use these operations (printed by `push_swap`, executed silently by `checker`):
- Swaps: `sa`, `sb`, `ss`
- Pushes: `pa`, `pb`
- Rotations: `ra`, `rb`, `rr`
- Reverse rotations: `rra`, `rrb`, `rrr`

## Instructions

### Build
- Build `push_swap`:
  - `make`
- Build `checker` (bonus):
  - `make bonus`
- Clean objects (if your Makefile uses them):
  - `make clean`
- Remove binaries:
  - `make fclean`
- Rebuild:
  - `make re`

### Run
- Generate instructions:
  ```bash
  ./push_swap 2 1 3 6 5 8
  ```
- Validate with the checker:
  ```bash
  ./push_swap "2 1 3 6 5 8" | ./checker "2 1 3 6 5 8"
  # -> OK or KO
  ```
- Large random test (Linux/macOS with `seq`, `shuf`):
  ```bash
  ARG=$(seq 1 100 | shuf | tr '\n' ' ')
  ./push_swap $ARG | ./checker $ARG
  ```
- Error cases:
  - Non-integer, duplicate, or out-of-range → program must print `Error\n` to stderr and exit.

## Technical choices

### Sorting strategy
- Small N (`<= 3`/`<= 5`): specialized routines with minimal moves.
- General case: index compression + chunk-based approach:
  - Push range-based chunks from A to B.
  - Keep B roughly ordered by rotating while pushing.
  - Push back from B to A in descending index order.
- Chunk sizing is tunable (e.g., `size/5` for ~100, `size/10..12` for ~500, and a general fallback like `size/13`). Choose based on benchmarks.

### Checker
- Reads instructions from `stdin` using `get_next_line`.
- Executes operations without printing (pass a print-flag `0` to ops).
- On invalid instruction: print `Error\n` to stderr, free stacks, exit(1).
- At EOF: print `OK\n` if A is sorted and B is empty, else `KO\n`.

## Usage examples

```bash
# Basic
./push_swap 3 2 1
# Validate
./push_swap 3 2 1 | ./checker 3 2 1

# Quoted multi-arg inputs (same behavior)
./push_swap "3 2" "1" | ./checker "3 2" "1"

# Count number of moves
ARG="3 2 5 1 4"
OPS=$(./push_swap $ARG)
echo "$OPS" | wc -l
echo "$OPS" | ./checker $ARG
```

## Resources

### Classic references
- 42 subject: Push_swap (sorting with restricted operations)
- 42 Norm: coding style specification
- Man pages: `man 2 read`, `man 2 write`, `man 3 malloc`, `man 3 free`, `man 3 exit`
- Coordinate compression / indexing: commonly used to normalize values for chunking
- `get_next_line` pattern for reading stdin line by line

### How AI was used
- Assisted in:
  - Suggesting chunk-size heuristics and benchmarking considerations.
  - Writing this README examples.

## Testing tips
- Random tests:
  ```bash
  for n in 10 50 100; do
    ARG=$(seq 1 $n | shuf | tr '\n' ' ')
    ./push_swap $ARG | ./checker $ARG || echo "KO at n=$n"
  done
  ```
- Known edge cases:
  - Already sorted input
  - Reverse sorted input
  - Duplicates (must error)
  - Min/max int boundaries (`-2147483648`, `2147483647`)
- Benchmarks: compare move counts for different chunk sizes at N=100 and N=500.

## Notes
- No output when there are no arguments (subject requirement).
- `checker` prints to stdout (`OK\n`/`KO\n`) and prints `Error\n` to stderr on any invalid input or instruction.
- Ensure your operations accept a “print” flag so `push_swap` can print moves while `checker` stays silent.
