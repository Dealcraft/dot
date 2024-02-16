//
// Created by David Loh on 17.02.24.
//

#ifndef DOT_LANG_TEXTVALUE_H
#define DOT_LANG_TEXTVALUE_H


#include "Value.h"
#include <iostream>

using namespace std;

class TextValue : Value<std::string> {
public:
    TextValue(string val);
};


#endif //DOT_LANG_TEXTVALUE_H
