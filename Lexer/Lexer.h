//
// Created by David Loh on 07.04.23.
//

#ifndef DOT_LANG_LEXER_H
#define DOT_LANG_LEXER_H

#include <string>
#include <list>
#include <regex>
#include <algorithm>

#include "LexerTokenType.h"
#include "../Exceptions/TokenException.h"

using namespace std;

struct Token {
    Token(TokenType type, string value);

    TokenType type;
    string value;
};

class Lexer {
private:
    string source;
    list<Token> tokens;

    int nextToken(int position);
    static int lineNumber(const string& str, int position);

public:
    Lexer(string sourceCode);
    list<Token> parse();
};

#endif //DOT_LANG_LEXER_H
