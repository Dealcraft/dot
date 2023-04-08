//
// Created by David Loh on 08.04.23.
//

#ifndef DOT_LANG_TOKENEXCEPTION_H
#define DOT_LANG_TOKENEXCEPTION_H


#include "DotException.h"

class TokenException : public DotException {
private:
    const char* message;
public:
    TokenException(const char* msg);
    const char* what();
};


#endif //DOT_LANG_TOKENEXCEPTION_H
