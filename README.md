# push_swap - @42Born2Code

## 💡 About

**Push_swap** is a highly efficient algorithm project where the goal is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

The project forces you to manipulate various sorting algorithms and choose the most appropriate solution for optimized data sorting.

> "Because $O(n^2)$ is simply not an option when you have 500 numbers to sort."

---

## 📋 The Rules

The game is composed of two stacks, **A** and **B**.

* **Stack A**: Contains a random amount of negative and/or positive numbers which cannot be duplicated.
* **Stack B**: Is empty at the beginning.

### The Operations

To manipulate the stacks, you are allowed the following operations:

* `sa` / `sb` / `ss` : **Swap** the first 2 elements at the top of a stack.
* `pa` / `pb` : **Push** the first element from one stack to the top of the other.
* `ra` / `rb` / `rr` : **Rotate** all elements of a stack upwards by 1 (the first becomes the last).
* `rra` / `rrb` / `rrr` : **Reverse rotate** all elements of a stack downwards by 1 (the last becomes the first).

---

## 📈 Performance Targets

To pass with maximum points, the project requires:

* **100 numbers**: Less than 700 operations.
* **500 numbers**: Less than 5500 operations.

---

## 🚀 Usage

### Compilation

To compile the program, run:

```bash
make

```

### Execution

The program will output the list of instructions to sort the given numbers:

```bash
./push_swap 2 1 3 6 5 8

```

To check if the sorting is correct and count the operations:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

```

---

## 🧪 Visualizing

Visualizing the stacks helps a lot in understanding how the algorithm behaves:

* **Visualizer**: [Push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)

---
