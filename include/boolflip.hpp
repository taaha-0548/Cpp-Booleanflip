// boolflip.hpp - Prototype for Postfix Boolean Flip Operator
// Note: This is a SIMULATION of the proposed feature.
// C++ does not currently allow postfix operator~ - that's what P3883R1 proposes to add!
#pragma once

struct flip_bool {
    bool value;
    
    explicit flip_bool(bool v = false) : value(v) {}
    
    // The proposed feature would allow: flag~;
    // Since we can't actually implement postfix ~ in current C++,
    // we provide a toggle() method to simulate the behavior.
    void toggle() { value = !value; }
    
    // Conversion to bool for use in conditions
    operator bool() const { return value; }
    
    // Assignment from bool
    flip_bool& operator=(bool v) { 
        value = v; 
        return *this; 
    }
    
    // We could overload prefix ~, but that's different from the proposal
    // The proposal wants POSTFIX ~, which isn't possible in current C++
    // Uncommenting this would allow: ~flag; (but that's prefix, not postfix)
    // void operator~() { value = !value; }
};
