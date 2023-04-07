#include <iostream>
#include "lexer/Lexer.h"

using namespace std;

int main() {
    string test = "if ] true 09 \"Test\" az + /* Test Comment */";

    Lexer testLexer(test);
    list<Token> tokenList = testLexer.parse();

    for(Token token : tokenList) {
        cout << endl;
        cout << "Token type: " << token.type << endl;
        cout << "Token value: " << token.value << endl;
    }
    return 0;
}
