//
// Created by David Loh on 17.02.24.
//

#ifndef DOT_LANG_VALUE_H
#define DOT_LANG_VALUE_H

#include "../Expression.h"

template<typename T>
class Value : Expression {
private:
    T value;

public:
    Value(T val);
};


#endif //DOT_LANG_VALUE_H
