# BoolFlip — A Proposal for a Postfix Boolean Flip Operator in C++



This repository contains a reference implementation demonstrating the proposed postfix boolean flip operator (`flag~`) for C++, as detailed in proposal P3883R1.> **Author:** Muhammad Taaha  

> **Document:** P3883R1  

## Overview> **Status:** Proposal Draft  

> **Audience:** ISO C++ Evolution Working Group (EWG)  

The boolean flip operator provides an intuitive syntax for toggling boolean values:

---

```cpp

bool flag = false;## 🧩 Overview

flag~;  // Proposed syntax: flag becomes true

flag~;  // flag becomes false`BoolFlip` proposes introducing a **postfix Boolean flip operator** into C++.  

```Currently, toggling a boolean value requires explicit assignment:



Since this operator is not yet part of the C++ standard, this repository provides a prototype using a wrapper class to simulate the behavior.```cpp

flag = !flag;

## Motivation```



Boolean flipping is a common operation in many programming domains:This proposal introduces a concise postfix operator `flag~;` for in-place boolean inversion:

- GUI state management (checkboxes, toggles)

- State machines and finite automata```cpp

- Embedded systems and hardware controlbool flag = true;

- Game development (state flags)flag~;  // flag becomes false

flag~;  // flag becomes true

The proposed postfix `~` operator offers:```

- **Clarity**: Expresses "toggle this flag" directly

- **Brevity**: Reduces `flag = !flag` to `flag~`The postfix position mirrors `flag++` and `flag--`, providing consistency with other mutating operators while avoiding conflicts with the existing prefix `~` (bitwise NOT) operator.

- **Safety**: Postfix syntax prevents accidental use in expressions

- **Consistency**: Aligns with other postfix operators (`++`, `--`)---



## Project Structure## ⚙️ Example Usage



``````cpp

cpp-booleanflip/#include <iostream>

├── include/

│   └── boolflip.hpp          # Prototype implementationint main() {

├── examples/    bool flag = true;

│   └── demo.cpp              # Usage demonstrations    std::cout << std::boolalpha;

├── proposal/    

│   └── P3883R1_BooleanFlipOperator.md  # Formal WG21 proposal    std::cout << "Initial: " << flag << "\n";  // true

└── README.md                 # This file    

```    flag~;  // Proposed syntax

    std::cout << "After first toggle: " << flag << "\n";  // false

## Implementation Details    

    flag~;

### Prototype Class    std::cout << "After second toggle: " << flag << "\n";  // true

}

The `flip_bool` class simulates the proposed `flag~` operator:```



```cpp**Note:** The above syntax is the *proposed* feature. See the prototype section for current working code.

struct flip_bool {

    bool value;---

    

    explicit flip_bool(bool v = false) : value(v) {}## 🎯 Motivation

    

    // Simulates: flag~C++ supports shorthand for numeric mutation (`++`, `--`) but not for logical inversion.  

    void toggle() { value = !value; }The postfix `flag~;` operator would:

    

    // Implicit conversion to bool* **Improve readability** in state-toggling contexts

    operator bool() const { return value; }* **Reduce verbosity** compared to `flag = !flag;`

    * **Maintain consistency** with existing mutating operators

    // Assignment from bool* **Eliminate confusion** — no conflict with prefix `~` (bitwise NOT)

    flip_bool& operator=(bool v) { value = v; return *this; }

};Common use cases:

```

```cpp

**Note**: True postfix `~` syntax (`void operator~(int)`) is **not possible** in current C++ because the language only allows postfix overloading for `operator++` and `operator--`. This limitation is precisely what the proposal aims to address.// GUI state toggles

isVisible~;

### Usage ExampleisEnabled~;



```cpp// Game development

#include "boolflip.hpp"debugMode~;

isPaused~;

flip_bool active(false);

std::cout << "Active: " << active << "\n";  // Prints: 0// Embedded systems

motorState~;

active.toggle();  // Simulates: active~ledStatus~;

std::cout << "Active: " << active << "\n";  // Prints: 1

```// State machines

connected~;

## Building and Runningactive~;

```

### Requirements

- C++17 compatible compiler (g++, clang++, or MSVC)---

- No external dependencies

## 🧱 Implementation Prototype

### Compile and Run Demo

A minimal header-only prototype demonstrates the proposed behavior:

**Windows (PowerShell):**

```powershell```cpp

g++ -std=c++17 -I include examples/demo.cpp -o demo// boolflip.hpp

.\demo.exe#pragma once

```

struct flip_bool {

**Linux/macOS:**    bool value;

```bash    

g++ -std=c++17 -I include examples/demo.cpp -o demo    explicit flip_bool(bool v = false) : value(v) {}

./demo    

```    // Postfix operator~ (int parameter is C++ convention for postfix)

    void operator~(int) { value = !value; }

## Formal Proposal    

    // Helper method for demonstration

This implementation accompanies the formal WG21 proposal **P3883R1: Postfix Boolean Flip Operator**. The proposal includes:    void toggle() { value = !value; }

    

- Detailed motivation and use cases    // Conversion to bool for use in conditions

- Comparison with alternative approaches    operator bool() const { return value; }

- Proposed standard wording with BNF grammar    

- Implementation considerations    // Assignment from bool

- Impact analysis on existing code    flip_bool& operator=(bool v) { 

        value = v; 

See the full proposal in [`proposal/P3883R1_BooleanFlipOperator.md`](proposal/P3883R1_BooleanFlipOperator.md)        return *this; 

    }

## Why Not Use Existing Syntax?};

```

| Approach | Syntax | Issues |

|----------|--------|--------|**Usage:**

| Negation + Assignment | `flag = !flag` | Verbose, repeats identifier |```cpp

| XOR Assignment | `flag ^= true` | Non-obvious intent |flip_bool flag(true);

| Prefix Bitwise NOT | `~flag` | Confusing (bitwise vs boolean), context-dependent |flag.toggle();  // Simulates: flag~

| **Postfix Flip** | `flag~` | **Clear, brief, unambiguous** ✓ |```



## Contributing**Note:** This prototype uses a wrapper type. The actual language feature would apply directly to the built-in `bool` type.



This is a reference implementation for a standards proposal. Feedback and suggestions are welcome:---



- **Email**: taaha2004@gmail.com## 🧠 Design Rationale

- **GitHub**: https://github.com/taaha-0548/Cpp-Booleanflip

| Aspect          | Choice                | Reason                                                  |

## License| --------------- | --------------------- | ------------------------------------------------------- |

| **Position**    | Postfix (`flag~`)     | Consistent with `++`/`--`, no conflict with prefix `~`  |

This code is provided for educational and demonstration purposes as part of a C++ standardization proposal.| **Operator**    | `~`                   | Already means "inversion", visually intuitive           |

| **Return type** | `void`                | Prevents misuse in expressions, clarifies intent        |

## Further Reading| **Scope**       | `bool` lvalues only   | Clear semantics, no type confusion                      |

| **Impact**      | Zero breaking changes | Postfix `~` is currently invalid syntax                 |

- [P3883R1 Proposal Document](proposal/P3883R1_BooleanFlipOperator.md)

- [C++ Operator Overloading](https://en.cppreference.com/w/cpp/language/operators)---

- [WG21 Papers](https://wg21.link/)

## 🔄 Comparison with Alternatives

| Approach           | Syntax              | Pros                      | Cons                                    |
| ------------------ | ------------------- | ------------------------- | --------------------------------------- |
| **Postfix `~`**    | `flag~;`            | Clean, consistent, safe   | Novel visual form                       |
| Prefix `~` (stmt)  | `~flag;`            | Familiar                  | Context-dependent, confusing semantics  |
| XOR assignment     | `flag ^= true;`     | Works today               | Non-intuitive, verbose, looks like bits |
| Free function      | `std::flip(flag);`  | Clear intent              | Verbose, needs include, not primitive   |
| Explicit assign    | `flag = !flag;`     | Clear, works today        | Repetitive, inconsistent with `++`      |
| New keyword        | `flip flag;`        | Unambiguous               | Breaks compatibility, high bar          |

**Conclusion:** Postfix `~` provides the best balance of clarity, consistency, and backward compatibility.

---

## 🧩 Directory Structure

```
cpp-booleanflip/
├── include/
│   └── boolflip.hpp       # Prototype header with flip_bool
├── examples/
│   └── demo.cpp           # Usage demonstration
├── proposal/
│   └── PXXXXR0_BooleanFlipOperator.md  # WG21-style proposal
└── README.md
```
---

## 🚀 Building and Running

### Prerequisites

- C++17 or later
- Any standard-compliant compiler (g++, clang++, MSVC)

### Compilation

**Using g++:**
```bash
g++ -std=c++17 -Iinclude -Wall -Wextra examples/demo.cpp -o demo
./demo
```

**Using clang++:**
```bash
clang++ -std=c++17 -Iinclude -Wall -Wextra examples/demo.cpp -o demo
./demo
```

**Using MSVC (Windows):**
```cmd
cl /std:c++17 /EHsc /I include examples\demo.cpp /Fe:demo.exe
demo.exe
```

### Expected Output

```
=== Postfix Boolean Flip Operator Demo ===

Initial: true
After first toggle: false
After second toggle: true

--- GUI Toggle Example ---
isVisible: true
After toggle: false

--- State Machine Example ---
connected: false
After connect: true
After disconnect: false

--- Multiple Toggles ---
debugMode initial: false
  After toggle 1: true
  After toggle 2: false
  After toggle 3: true
  After toggle 4: false
  After toggle 5: true

=== Note ===
This prototype uses .toggle() to demonstrate the concept.
With the proposed language feature (P3883R1), you would write:
  flag~;      // instead of flag.toggle();
  isVisible~; // instead of isVisible.toggle();

The postfix ~ operator would work directly with built-in bool:
  bool myFlag = true;
  myFlag~;  // toggles to false
```

---

## 📚 API Reference

### `flip_bool`

A lightweight wrapper around `bool` that provides postfix toggle functionality via `operator~(int)`.

```cpp
struct flip_bool {
    bool value;
    explicit flip_bool(bool v = false);   // Constructor
    void operator~(int);                   // Postfix toggle operator
    void toggle();                         // Helper method for demo
    operator bool() const;                 // Implicit conversion to bool
    flip_bool& operator=(bool v);          // Assignment from bool
};
```

### Usage Patterns

```cpp
#include "boolflip.hpp"

// Using the prototype
flip_bool flag(true);
flag.toggle();  // Simulates: flag~

// State machine
flip_bool isActive(false);
isActive.toggle();  // Simulates: isActive~

// GUI toggle
flip_bool isVisible(true);
if (user_clicked_button) {
    isVisible.toggle();  // Simulates: isVisible~
}
```

**With the proposed language feature:**
```cpp
// Would work directly with built-in bool
bool flag = true;
flag~;  // toggles to false
flag~;  // toggles to true
```
~flag;  // Now false
~flag;  // Now true

// State machine example
flip_bool isActive = false;
~isActive;  // Activate
// ... do work ...
~isActive;  // Deactivate

// UI toggle pattern
flip_bool isVisible = true;
if (user_clicked_button) {
    ~isVisible;  // Toggle visibility
}
```

---


### Backward Compatibility

- The `~` operator is currently **undefined** for `bool` in standard C++
- Defining it would **not break** any valid existing code
- Similar patterns exist: `++` modifies integers, `~` flips bits for integral types

---


## � License

MIT License © 2025 Muhammad Taaha

---


**Note**: This is a proof-of-concept demonstration. The `~` operator for built-in `bool` is not part of standard C++ and would require language standardization to implement natively.
