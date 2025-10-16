// boolflip.hpp
#pragma once

struct flip_bool {
    bool value;
    flip_bool(bool v = false) : value(v) {}

    void operator~() { value = !value; }
    operator bool() const { return value; }
};
