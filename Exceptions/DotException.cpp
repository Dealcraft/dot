//
// Created by David Loh on 08.04.23.
//

#include "DotException.h"

DotException::DotException(const char* msg) : message(msg) {}

const char* DotException::what() {
    return message;
}
