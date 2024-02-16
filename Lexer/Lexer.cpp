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
}

int Lexer::nextToken(int position) {
    std::string nextToken = (this->source).substr(position);

    for (const auto& [type, tokenRegex] : LexerTokenType) {
        std::regex pattern('^' + tokenRegex);
        std::smatch matches;

        if(std::regex_search(nextToken, matches, pattern)) {
            if (type != TokenType::Whitespace) {
                string value = matches[1];
                if(matches.size() > 5) {
                    value = matches[5] != "" ? matches[5] : matches[2];
                }
                Token token = Token(type, value);
                this->tokens.push_back(token);
            }

            return matches[0].length();
        }
    }

    string message = "Invalid token at line " + std::to_string(lineNumber(source, position));
    throw TokenException(std::strcpy(new char[message.length() + 1], message.c_str()));
}

int Lexer::lineNumber(const string& str, int position) {
    return std::count(str.begin(), str.begin() + position, '\n') + 1;
}

list<Token> Lexer::parse() {
    int position = 0;

    while (position < this->source.size()) {
        position += this->nextToken(position);
    }

    return this->tokens;
}
