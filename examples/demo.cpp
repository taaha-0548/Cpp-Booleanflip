// Demo - Postfix Boolean Flip Operator Prototype
// Note: This demonstrates the proposed flag~ syntax using a wrapper type
#include <iostream>
#include "../include/boolflip.hpp"

int main() {
    std::cout << std::boolalpha;
    
    std::cout << "=== Postfix Boolean Flip Operator Demo ===\n\n";
    
    flip_bool flag(true);
    std::cout << "Initial: " << flag << "\n";
    
    // Using the toggle() method to simulate: flag~
    flag.toggle();
    std::cout << "After first toggle: " << flag << "\n";
    
    flag.toggle();
    std::cout << "After second toggle: " << flag << "\n";
    
    // Example: GUI toggle pattern
    std::cout << "\n--- GUI Toggle Example ---\n";
    flip_bool isVisible(true);
    std::cout << "isVisible: " << isVisible << "\n";
    isVisible.toggle();  // Simulates: isVisible~
    std::cout << "After toggle: " << isVisible << "\n";
    
    // Example: State machine
    std::cout << "\n--- State Machine Example ---\n";
    flip_bool connected(false);
    std::cout << "connected: " << connected << "\n";
    connected.toggle();  // Simulates: connected~ (connect)
    std::cout << "After connect: " << connected << "\n";
    connected.toggle();  // Simulates: connected~ (disconnect)
    std::cout << "After disconnect: " << connected << "\n";
    
    // Example: Multiple toggles
    std::cout << "\n--- Multiple Toggles ---\n";
    flip_bool debugMode(false);
    std::cout << "debugMode initial: " << debugMode << "\n";
    for (int i = 0; i < 5; ++i) {
        debugMode.toggle();  // Simulates: debugMode~
        std::cout << "  After toggle " << (i+1) << ": " << debugMode << "\n";
    }
    
    std::cout << "\n=== Note ===\n";
    std::cout << "This prototype uses .toggle() to demonstrate the concept.\n";
    std::cout << "With the proposed language feature (P3883R1), you would write:\n";
    std::cout << "  flag~;      // instead of flag.toggle();\n";
    std::cout << "  isVisible~; // instead of isVisible.toggle();\n";
    std::cout << "\nThe postfix ~ operator would work directly with built-in bool:\n";
    std::cout << "  bool myFlag = true;\n";
    std::cout << "  myFlag~;  // toggles to false\n";
    
    return 0;
}
