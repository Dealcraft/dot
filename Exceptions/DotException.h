//
// Created by David Loh on 08.04.23.
//

#ifndef DOT_LANG_DOTEXCEPTION_H
#define DOT_LANG_DOTEXCEPTION_H

#include <exception>
#include <string>


class DotException : public std::exception {
private:
    const char* message;

public:
    DotException(const char* msg);
    const char* what();
};


#endif //DOT_LANG_DOTEXCEPTION_H
