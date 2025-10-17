
# BoolFlip — A Proposal for a Postfix Boolean Flip Operator in C++

> **Author:** Muhammad Taaha  
> **Document:** P3883R1 
> **Status:** Proposal Draft  
> **Audience:** ISO C++ Evolution Working Group (EWG)  
> **Email:** [taaha2004@gmail.com](mailto:taaha2004@gmail.com)  
> **GitHub:** [https://github.com/taaha-0548/Cpp-Booleanflip](https://github.com/taaha-0548/Cpp-Booleanflip)

---

## 🧩 Overview

This repository contains a **reference implementation** and examples demonstrating the proposed **postfix boolean flip operator** (`flag~`) for C++, as introduced in **proposal P3883R1**.

### 🔹 Motivation

Currently, toggling a boolean value in C++ requires explicit assignment:

```cpp
flag = !flag;
````

This works, but it’s verbose and inconsistent with other mutation operators like `flag++` or `flag--`.

### 🔹 Proposed Syntax

```cpp
bool flag = true;
flag~;  // Equivalent to: flag = !flag;
```

The postfix form mirrors existing mutation operators, avoids conflicts with the prefix `~` (bitwise NOT), and provides a concise, expressive way to toggle boolean state.

---

## ⚙️ Example Usage

### Basic Example

```cpp
#include <iostream>

bool flag = true;
std::cout << std::boolalpha;

std::cout << "Initial: " << flag << "\n";
flag~;  // Proposed syntax
std::cout << "After 1st toggle: " << flag << "\n";
flag~;
std::cout << "After 2nd toggle: " << flag << "\n";
```

**Output:**

```
Initial: true
After 1st toggle: false
After 2nd toggle: true
```

---

### GUI Example

```cpp
class Widget {
    bool isVisible = true;
public:
    void onClick() { isVisible~; }
};
```

### Embedded Example

```cpp
bool motor = false;
void loop() {
    if (buttonPressed()) motor~;
}
```

### State Machine Example

```cpp
class Connection {
    bool connected = false;
public:
    void toggle() { connected~; }
};
```

---

## 🧱 Implementation Prototype

Since C++ does not yet support postfix `~` overloading, this repository simulates the feature using a wrapper class:

```cpp
// boolflip.hpp
#pragma once

struct flip_bool {
    bool value;

    explicit flip_bool(bool v = false) : value(v) {}

    // Simulates: flag~
    void toggle() { value = !value; }

    // Postfix operator~ (for demonstration)
    void operator~(int) { value = !value; }

    operator bool() const { return value; }
    flip_bool& operator=(bool v) { value = v; return *this; }
};
```

### Example

```cpp
#include "boolflip.hpp"
#include <iostream>

int main() {
    flip_bool flag(true);
    std::cout << std::boolalpha;

    std::cout << "Initial: " << flag << "\n";
    flag~;  // Simulated postfix toggle
    std::cout << "After toggle: " << flag << "\n";
}
```

---

## 🧠 Design Rationale

| Aspect            | Choice                    | Reason                                       |
| ----------------- | ------------------------- | -------------------------------------------- |
| **Operator**      | Postfix `~`               | Mirrors `++`/`--`, signals in-place mutation |
| **Operand**       | `bool` lvalue             | Restricts scope and simplifies semantics     |
| **Return type**   | `void`                    | Prevents misuse in expressions               |
| **Compatibility** | Fully backward-compatible | Postfix `~` is currently invalid syntax      |

---

## 🔄 Comparison with Alternatives

| Approach                            | Example            | Pros                             | Cons                       |
| ----------------------------------- | ------------------ | -------------------------------- | -------------------------- |
| Prefix `~flag`                      | `~flag;`           | Familiar syntax                  | Conflicts with bitwise NOT |
| XOR assignment                      | `flag ^= true;`    | Works today                      | Unintuitive, verbose       |
| Free function                       | `std::flip(flag);` | Clear intent                     | Verbose, not primitive     |
| Explicit assignment                 | `flag = !flag;`    | Clear, works today               | Repetitive                 |
| **Postfix `flag~` (this proposal)** | `flag~;`           | Clean, consistent, backward-safe | New visual form            |

---

## 🧩 Directory Structure

```
Cpp-Booleanflip/
│
├── include/
│   └── boolflip.hpp          # Prototype header
│
├── examples/
│   └── demo.cpp              # Usage demonstration
│
├── proposal/
│   └── P3883R1_BooleanFlipOperator.md  # Formal WG21 proposal
│
│
└── README.md
```

---

## 🧰 Build and Run

### Prerequisites

* C++17 or later
* g++, clang++, or MSVC

### Build Example

**Linux/macOS**

```bash
g++ -std=c++17 -Iinclude examples/demo.cpp -o demo
./demo
```

**Windows (PowerShell)**

```powershell
g++ -std=c++17 -Iinclude examples/demo.cpp -o demo.exe
.\demo.exe
```

---

## 📜 License

MIT License © 2025 Muhammad Taaha
This code is provided for educational and demonstration purposes as part of a C++ standardization proposal.

---
