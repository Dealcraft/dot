//
// Created by David Loh on 08.04.23.
//

#include "TokenException.h"

TokenException::TokenException(const char* msg) : DotException(msg), message(msg) {}

const char* TokenException::what() {
    return DotException::what();
}