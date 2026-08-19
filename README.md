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

## Sources

- Bitwise operation explained https://en.wikipedia.org/wiki/Bitwise_operation
- Calculate the sum of two natural zith only bitwise operator https://www.geeksforgeeks.org/dsa/bitwise-recursive-addition-two-integers/
- Compute multiplication with the Russian peasent algorithm https://www.geeksforgeeks.org/dsa/russian-peasant-multiply-two-numbers-using-bitwise-operators/
- Compute Gray code of a natural number https://recognitionphysics.org/encyclopedia/patterns-gray-code-axioms-gray-code-one-bit-property/
