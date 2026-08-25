<div align="center">
  <h1> 🏁 ready set boole
  </h1>
</div>

---

Ready set boole is a 42 project where you have to create easy operation only using bitwise operator.

This project is aimed around math and is an introduction to Boolean Algebra.

![Static Badge](https://img.shields.io/badge/language-c%2B%2B17-blue)

## Summary

- [Use the Library](#use-the-library)
- [Run Locally the Tester](#run-locally-the-tester)
- [Functions](#functions)
- [Documentation](#documentation)
  - [Adder](#adder)
  - [Multiplier](#multiplier)
  - [Gray Code](#gray-code)
  - [Boolean Evaluation](#boolean-evaluation)
  - [Truth Table](#truth-table)
  - [Negation Normal Form](#negation-normal-form)
  - [Conjonctive Normal Form](#conjonctive-normal-form)
- [Sources](#sources)

## Use the Library

Clone the project

```bash
  git clone https://github.com/drabiot/ready_set_boole.git
```

Include the lib

```bash
  ./ready_set_boole/inc/boollib.hpp
```

## Run Locally the Tester

Clone the project

```bash
  git clone https://github.com/drabiot/ready_set_boole.git
```

Go to the project directory

```bash
  cd ready_set_boole
```

Compile the project

```bash
  make -j
```

Open the project

```bash
  //Run all the Test
  ./tester
```

## Functions

| Function | Description |
| -------- | ----------- |
| [Adder](#adder) | Add two natural numbers |
| [Multiplier](#multiplier) | Multiply two natural numbers |
| [Gray Code](#gray-code) | Generate the gray code of a natural number |
| [Boolean Evaluation](#boolean-evaluation) | Return the result of a reverse polish notation binary formula |
| [Truth Table](#truth-table) | Print the truth table of a reverse polish notation formula |
| [Negation Normal Form](#negation-normal-form) | Return the negation normal form of a reverse polish notation formula |
| [Conjonctive Normal Form](#conjonctive-normal-form) | Return the conjontive normal form of a reverse polish notation formula |

## Documentation

### ADDER
Add two natural numbers together an return the value.

```cpp
int	adder(int a, int b);
```

| Time complexity | Space complexity |
|---|---|
| O(1) | O(1) |

```cpp
sum = adder(21, 12); // sum = 33
```

Use of &(bitwise AND), ^(bitwise XOR).

```math
0 + 0 =  0
```

```math
0 + 1 =  1
```

```math
1 + 1 = 10
```

```math
\begin{array}{r cccc}
\text{\tiny (carry)} & & \mathbf{1} & & \\
& 1 & 0 & 1 & 0 \\
+ & \underline{0} & \underline{0} & \underline{1} & \underline{0} \\
= & 1 & 1 & 0 & 0
\end{array}
```

The idea is to mimic the manual process of binary addition, where we calculate the carry and add it to the sum of a and b. Using bitwise operations, the XOR (a ^ b) gives the sum without carry, and the AND (a & b) identifies the carry, which is then shifted left. The recursion continues until the carry becomes 0, ensuring complete addition.

### MULTIPLIER
Multiply two natural numbers together an return the value.

```cpp
int	multiplier(int a, int b);
```

| Time complexity | Space complexity |
|---|---|
| O(1) | O(1) |

```cpp
res = multiplier(14, 6); // res = 84
```

Use of &(bitwise AND).

The idea is to break multiplication into a series of additions using the Russian Peasant Algorithm. Instead of directly multiplying a and b, we repeatedly halve b and double a, leveraging the fact that multiplication can be rewritten as repeated addition. If b is odd at any step, we add a to the result since that part of the multiplication cannot be handled by doubling alone. This process continues until b becomes zero.

### GRAY CODE
Generate the gray code of a natural number.

```cpp
int	gray_code(int n);
```

| Time complexity | Space complexity |
|---|---|
| O(1) | O(1) |

```cpp
std::cout << gray_code(6) << std::endl;	//5
```

Use of ^(bitwise XOR).

### BOOLEAN EVALUATION
Return the result of a reverse polish notation binary formula.

```cpp
bool	eval_formula(const str &formula);
```

| Time complexity | Space complexity |
|---|---|
| O(n) | O(n) |

```cpp
std::cout << eval_formula("10&") << std::endl;		// false
std::cout << eval_formula("10|") << std::endl;		// true
std::cout << eval_formula("11>") << std::endl;		// true
std::cout << eval_formula("10=") << std::endl;		// false
std::cout << eval_formula("1011||=") << std::endl;	// true
std::cout << eval_formula("1!") << std::endl;		// false
std::cout << eval_formula("1011||=!") << std::endl;	// false
```

### TRUTH TABLE
Print the truth table of a reverse polish notation formula.

```cpp
void	print_truth_table(const str &formula);
```

| Time complexity | Space complexity |
|---|---|
| O(2^n) | O(n) |

```cpp
print_truth_table("AB&C|")

// | A | B | C | = |
// |---|---|---|---|
// | 0 | 0 | 0 | 0 |
// | 0 | 0 | 1 | 1 |
// | 0 | 1 | 0 | 0 |
// | 0 | 1 | 1 | 1 |
// | 1 | 0 | 0 | 0 |
// | 1 | 0 | 1 | 1 |
// | 1 | 1 | 0 | 1 |
// | 1 | 1 | 1 | 1 |
```

### NEGATION NORMAL FORM
Return the negation normal form of a reverse polish notation formula.

```cpp
str	negation_normal_form(const str &formula);
```

| Time complexity | Space complexity |
|---|---|
| O(N) | O(N) |

```cpp
nnf = negation_normal_form("AB&!")	// nnf = A!B!|
nnf = negation_normal_form("AB|!")	// nnf = A!B!&
```

The goal of the NNF is to right the negation mark before a variable & not used for an expression.
Moreover, ⊕ ⇒ ⇔, are not allowed in a NNF formula and can be replaced with other expression.

| Symbol | Math Equivalent | Negation Equivalent |
| -------- | ----------------- | --------------------- |
| A...Z | A...Z | A...Z |
| !A  | ¬A | ¬A |
| !!A  | ¬¬A | A |
| !(A & B) | ¬(A ∧ B) | A ∨ B |
| !(A \| B) | ¬(A ∨ B) | A ∧ B |
| A ˆ B | A ⊕ B | (A ∧ ¬B) ∨ (¬A ∧ B) |
| A > B | A ⇒ B |  ¬A ∨ B  |
| A = B | A ⇔ B | (A ∧ B) ∨ (¬A ∧ ¬B) |

### CONJONCTIVE NORMAL FORM
Return the conjonctive normal form of a reverse polish notation formula.

```cpp
str	conjonctive_normal_form(const str &formula);
```

| Time complexity | Space complexity |
|---|---|
| O(2^N) | O(2^N) |

```cpp
cnf = conjonctive_normal_form("AB&!")	// cnf = A!B!|
cnf = conjonctive_normal_form("AB|!")	// cnf = A!B!&
```

To transforn a RPN into a CNF expression, we need to pass it through the NNF converter to put the negation sign on the ight spot and remove unwanted sign.
The the goal is to add distributivity. For example:

```cpp
P ∨ (Q ∧ R) ≡ (P ∨ Q) ∧ (P ∨ R)
```

## Sources

- Bitwise operation explained https://en.wikipedia.org/wiki/Bitwise_operation
- Calculate the sum of two natural zith only bitwise operator https://www.geeksforgeeks.org/dsa/bitwise-recursive-addition-two-integers/
- Compute multiplication with the Russian peasent algorithm https://www.geeksforgeeks.org/dsa/russian-peasant-multiply-two-numbers-using-bitwise-operators/
- Compute Gray code of a natural number https://recognitionphysics.org/encyclopedia/patterns-gray-code-axioms-gray-code-one-bit-property/
- Learn what's a truth table https://sites.millersville.edu/bikenaga/math-proof/truth-tables/truth-tables.html
- Truth table generator https://web.stanford.edu/class/cs103/tools/truth-table-tool/
- Converting CNF https://personal.cis.strath.ac.uk/robert.atkey/cs208/converting-to-cnf.html
