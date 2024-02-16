//
// Created by David Loh on 17.02.24.
//

#ifndef DOT_LANG_NUMERICVALUE_H
#define DOT_LANG_NUMERICVALUE_H


#include "../Expression.h"
#include "Value.h"

class NumericValue : Value<int> {
public:
    NumericValue(int value);
};


#endif //DOT_LANG_NUMERICVALUE_H
