//
// Created by David Loh on 07.04.23.
//

#include <string>
#include <regex>
#include <iostream>
#include "Lexer.h"

Token::Token(TokenType type, std::string value) {
    this->type = type;
    this->value = value;
}

Lexer::Lexer(string sourceCode) {
    this->source = sourceCode;
    std::cout << this->source << std::endl;
}

int Lexer::nextToken(int position) {
    std::string nextToken = (this->source).substr(position);

    for (const auto& [type, tokenRegex] : LexerTokenType) {
        std::regex pattern('^' + tokenRegex);
        std::smatch matches;

        if(std::regex_search(nextToken, matches, pattern)) {
            if (type != TokenType::Whitespace) {
                string value = matches.size() > 2 ? matches[2] : matches[1];
                Token token = Token(type, value);
                this->tokens.push_back(token);
            }

            return matches[0].length();
        }
    }
}

list<Token> Lexer::parse() {
    int position = 0;

    while (position < this->source.size()) {
        position += this->nextToken(position);
    }

    return this->tokens;
}
