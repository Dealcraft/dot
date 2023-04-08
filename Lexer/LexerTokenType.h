//
// Created by David Loh on 07.04.23.
//

#ifndef DOT_LANG_LEXERTOKENTYPE_H
#define DOT_LANG_LEXERTOKENTYPE_H

#include <string>
#include <map>

using namespace std;

enum TokenType {
    Whitespace,
    Keyword,
    GroupDivider,
    Logical,
    Numeric,
    Text,
    Variable,
    Operator,
    Comment
};

const map<TokenType, string> LexerTokenType = {
        {TokenType::Whitespace, R"(([\s\t\n\r]))"},
        {TokenType::Keyword, "(if|then|end|print|input|struct|arg|new)"},
        {TokenType::GroupDivider, "(\\[|\\])"},
        {TokenType::Logical, "(true|false)"},
        {TokenType::Numeric, "([0-9]+)"},
        {TokenType::Text, R"(("|')([^("|')]*)("|'))"},
        {TokenType::Variable, "([a-zA-Z_]+[a-zA-Z0-9_]*)"},
        {TokenType::Operator, R"((\+|\-|\>|\<|\={1,2}|\!|\.))"},
        {TokenType::Comment, R"((\/\/.+(?=$|\n)|\/\*[^\*\/]*\*\/))"}
};

#endif //DOT_LANG_LEXERTOKENTYPE_H
