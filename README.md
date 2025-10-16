# 🔄 BoolFlip — A Boolean Flip Operator in C++

---

## 🧩 Overview

`BoolFlip` explores the idea of introducing a **Boolean flip operator** into C++.  
Currently, toggling a boolean value requires explicit assignment:

```cpp
flag = !flag;
```

While concise, this pattern is inconsistent with the mutating idioms of C++ such as `++x` or `--x`.  
This project proposes an intuitive unary operator `~` for boolean variables:

```cpp
~flag;  // flips `flag` in-place
```

This mirrors existing operator semantics while improving expressiveness in codebases that frequently toggle states (e.g., GUIs, flags, and embedded systems).

---

## ⚙️ Example Usage

```cpp
#include <iostream>
#include "boolflip.hpp"

int main() {
    flip_bool flag = true;

    std::cout << std::boolalpha;
    std::cout << "Initial: " << flag << "\n";

    ~flag;
    std::cout << "After first flip: " << flag << "\n";

    ~flag;
    std::cout << "After second flip: " << flag << "\n";
}
```

**Output:**

```
Initial: true
After first flip: false
After second flip: true
```

---

## 🧱 Implementation

A minimal header-only prototype that demonstrates the proposed behavior.

```cpp
// boolflip.hpp
#pragma once

struct flip_bool {
    bool value;
    explicit flip_bool(bool v = false) : value(v) {}

    // Proposed flip operator
    void operator~() { value = !value; }

    // Allow implicit conversion to bool
    operator bool() const { return value; }
};
```

This library does not modify the C++ language — it simulates how the proposed operator might behave.

---

## 🎯 Motivation

C++ supports shorthand for numeric mutation (`++`, `--`) but not for logical inversion.  
Adding a dedicated flip operator would:

* Improve **readability** in state-toggling contexts
* Reduce **verbosity** for simple flag inversions
* Maintain **consistency** with existing operator semantics

For example:

```cpp
if (enabled) ~enabled;  // more expressive than `enabled = !enabled;`
```

---

## 🧠 Design Notes

| Aspect          | Choice                | Reason                                                  |
| --------------- | --------------------- | ------------------------------------------------------- |
| **Operator**    | `~`                   | Consistent with inversion semantics, visually intuitive |
| **Return type** | `void`                | Avoids chaining misuse                                  |
| **Scope**       | Only `bool`           | Prevents confusion with bitwise semantics               |
| **Impact**      | None on existing code | Safe backward compatibility                             |

---

## 🧩 Directory Structure

```
cpp-booleanflip/
├── include/
│   └── boolflip.hpp
├── examples/
│   └── demo.cpp
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

---

## 📚 API Reference

### `flip_bool`

A lightweight wrapper around `bool` that provides toggle functionality via `operator~()`.

```cpp
struct flip_bool {
    bool value;
    explicit flip_bool(bool v = false);  // Constructor
    void operator~();                     // Toggle operator
    operator bool() const;                // Implicit conversion to bool
};
```

### Usage Patterns

```cpp
#include "boolflip.hpp"

// Basic usage
flip_bool flag = true;
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
