# Postfix Expression Evaluator (C++)

## Overview
A C++ program that evaluates mathematical expressions written in **Postfix Notation** using the Standard Template Library (STL) `stack` container.

In postfix notation, operators are written after their operands instead of between them.

For example:
- Infix: `5 + 3`
- Postfix: `53+`

## Features
- Evaluates postfix mathematical expressions.
- Uses the STL `stack` container to manage operands.
- Supports the following arithmetic operators:

| Operator | Operation |
|---|---|
| `+` | Addition |
| `-` | Subtraction |
| `*` | Multiplication |
| `/` | Division |
| `^` | Exponentiation |

## How It Works

The program evaluates an expression by scanning it from left to right.

1. If the current character is an operand, it is converted into an integer and pushed onto the stack.
2. If the current character is an operator:
   - Pop the top two operands from the stack.
   - Perform the corresponding operation.
   - Push the result back onto the stack.
3. After processing the entire expression, the final result is at the top of the stack.

**Important:** The second operand is popped first (`op2`), followed by the first operand (`op1`). This preserves the correct order for subtraction, division, and exponentiation.

## Example Expressions

| Postfix Expression | Result |
|---|---:|
| `53+` | 8 |
| `27-` | -5 |
| `234*+` | 14 |
| `623+-382/+*2^3+` | 52 |
| `23^` | 8 |
| `51^` | 5 |
| `50^` | 1 |

## Technologies Used
- C++
- Standard Template Library (STL)
- `iostream`
- `stack`

## Limitations
- Supports single-digit operands only (0–9).
- Expressions must be valid postfix expressions.
- Division uses integer arithmetic.
- Division by zero is not handled.
- Exponentiation doesn't support non-negative integer exponents.

## Compilation and Execution

Compile using a C++ compiler:

```bash
g++ main.cpp -o postfix
```

Run the executable:

```bash
./postfix
```

## Learning Objectives
- Understanding postfix notation.
- Applying stack operations (`push`, `pop`, and `top`).
- Evaluating mathematical expressions using stacks.
- Understanding operator precedence through postfix evaluation.
