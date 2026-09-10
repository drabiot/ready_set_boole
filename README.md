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
  - [SAT](#sat)
  - [Powerset](#powerset)
  - [Set Evaluation](#set-evaluation)
  - [Curve](#curve)
  - [Inverse Function](#inverse-function)
- [Sources](#sources)

## Use the Library

Clone the project

```bash
  git clone https://github.com/drabiot/ready_set_boole.git
```

Go to the project directory

```bash
  cd ready_set_boole
```

Generate the lib

```bash
  make lib
```

And then include the archive to your compilation

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
| [SAT](#sat) | Return true if one of a the combination of the formula can be true. Else return false |
| [Powerset](#powerset) | Return the powerset of a list of integer |
| [Set Evaluation](#set-evaluation) | Take a RPN formula and sets & return the resulting set |
| [Curve](#curve) | Take 2 values and return an unique floating value with it |
| [Inverse Function](#inverse-function) | Take a float value and return an unique pair of value  |

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
| O(n^3) | O(n) |

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
| O(n) | O(n) |

```cpp
nnf = negation_normal_form("AB&!");	// nnf = A!B!|
nnf = negation_normal_form("AB|!");	// nnf = A!B!&
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
| O(n) | O(n) |

```cpp
cnf = conjonctive_normal_form("AB&!");	// cnf = A!B!|
cnf = conjonctive_normal_form("AB|!");	// cnf = A!B!&
```

To transforn a RPN into a CNF expression, we need to pass it through the NNF converter to put the negation sign on the ight spot and remove unwanted sign.
The the goal is to add distributivity. For example:

```cpp
P ∨ (Q ∧ R) ≡ (P ∨ Q) ∧ (P ∨ R)
```

### SAT
Return true if one of a the combination of the formula can be true. Else return false.

```cpp
bool	sat(const str &formula);
```

| Time complexity | Space complexity |
|---|---|
| O(n) | O(n) |

```cpp
sat("AB&!");	// true
sat("AA^");		// false
```

This function is like the [Truth Table](#truth-table) but without the graphical aspect.

### POWERSET
Return the powerset of a list of integer.

```cpp
std::vector<std::vector<int>>	powerset(std::vector<int> set);
```

| Time complexity | Space complexity |
|---|---|
| O(n^2) | O(n^2) |

```cpp
std::vector<int>				test = {1,2,3};
std::vector<std::vector<int>>	test_powerset = powerset(test);

//test_powerset = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}}
```

A powerset always have n^2 subset. So if you have a list of 3 element, you have 3^2 (8) subset.
The goal of the powerset is to create all subset possible, without forgetting the null list and the full list.

### SET EVALUATION
Take a RPN formula and sets & return the resulting set.

```cpp
std::vector<int>	eval_set(const str &formula, std::vector<std::vector<int>> sets);
```

| Time complexity | Space complexity |
|---|---|
| O(n^2) | O(n) |

```cpp
std::vector<std::vector<int>> sets = {
		{0, 1, 2},
		{0, 3, 4},
	};
std::vector<int> result = eval_set("AB&", sets);

//result = {0}
```

The goal is to use sets and perform the operation.

| Sign | Meaning |
|:-:|---|
| & | Intersection: elements present in both sets |
| \| | Union: elements present in either set |
| ! | Complement: elements not present in the set |
| ^ | Symmetric difference: elements present in one set but not both |
| > | Implication: elements outside the first set or inside the second set |
| = | Equivalence: elements present in both sets or in neither set |

### CURVE
Take 2 values and return a unique floating value with it.

```cpp
double	map(uint16_t x, uint16_t y);
```

| Time complexity | Space complexity |
|---|---|
| O(1) | O(1) |

```cpp
std::cout << map(0, 0) << endl;			//0
std::cout << map(65535, 65535) << endl;	//1
std::cout << map(1, 0) << endl;			//2.32831e-10
std::cout << map(0, 1) << endl;			//4.65661e-10
```

We can use a lot of algorithm to realize this exercice. I used Z-order Curve algo.
The goal is to transform the value into a 16 bit value then divide the result by 4294967295. Then you have a unique value between 0 & 1.


### INVERSE FUNCTION
Take a float value and return an unique pair of value.

```cpp
std::pair<uint16_t, uint16_t>	reverse_map(double n);
```

| Time complexity | Space complexity |
|---|---|
| O(n) | O(1) |

```cpp
std::cout << reverse_map(0) << endl;					//{0, 0}
std::cout << reverse_map(1) << endl;					//{65535, 65535}
std::cout << reverse_map(0,000000000232831) << endl;	//{1, 0}
std::cout << reverse_map(0,000000000465661) << endl;	//{0, 1}
```

This is the inverse of the previous exercice [Curve](#curve). Instead of encoding a value, we decode the value we encode earlier.

## Sources

- Bitwise operation explained https://en.wikipedia.org/wiki/Bitwise_operation
- Calculate the sum of two natural zith only bitwise operator https://www.geeksforgeeks.org/dsa/bitwise-recursive-addition-two-integers/
- Compute multiplication with the Russian peasent algorithm https://www.geeksforgeeks.org/dsa/russian-peasant-multiply-two-numbers-using-bitwise-operators/
- Compute Gray code of a natural number https://recognitionphysics.org/encyclopedia/patterns-gray-code-axioms-gray-code-one-bit-property/
- Learn what's a truth table https://sites.millersville.edu/bikenaga/math-proof/truth-tables/truth-tables.html
- Truth table generator https://web.stanford.edu/class/cs103/tools/truth-table-tool/
- Converting CNF https://personal.cis.strath.ac.uk/robert.atkey/cs208/converting-to-cnf.html
- What's a powerset https://youtu.be/0XNSBoqG-1s
- Bitwise operator in powerset computing https://youtu.be/LqKaUv1G3_I
- Meaning and usage of operator in eval_set https://github.com/jmcheon/ready_set_boole#ex09
- Using z-curve to flatern a 3D curve https://stackoverflow.com/questions/12157685/z-order-curve-coordinates
