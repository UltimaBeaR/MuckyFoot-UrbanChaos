// Alert.hpp
// Guy Simmons, 11th April 1997.

#pragma once

#include "CtrlSet.hpp"
#include "Primativ.hpp"

class Alert : public EdRect {
private:
    ControlSet AlertSet;

public:
    Alert();
    Alert(CBYTE* text1, CBYTE* text2);
    ~Alert();
    BOOL HandleAlert(CBYTE* text1, CBYTE* text2);
};
