#include <iostream>
#include <fstream>
#include <sstream>

#include "Exceptions/DotException.h"
#include "Lexer/Lexer.h"
#include "CliParser/CliParser.h"
#include "CliParser/CliStaticCommands.h"

using namespace std;

int main(int argc, char* argv[]) {
    CliParser parser(argc, argv);

    if(parser.hasError()) {
        return 1;
    }

    if(
        parser.hasFlag("--version") ||
        parser.hasFlag("-v")
    ) {
        CliStaticCommands::version();
        return 0;
    }
    if(
            parser.hasFlag("--help") ||
            parser.hasFlag("-h")
            ) {
        CliStaticCommands::help();
        return 0;
    }

    if (!parser.hasFlag("-i")) {
        cout << "Required argument \"-i\" not found. Please provide a filepath" << endl;
        return 1;
    }

    ifstream inputFile(parser.getArgument("-i"));
    if(!inputFile.is_open()) {
        cout << "Failed opening input filestream \"" << parser.getArgument("-i") << "\"" << endl;
        return 1;
    }
    stringstream buffer;
    buffer << inputFile.rdbuf();
    inputFile.close();

    list<Token> tokenList;
    try {
        Lexer testLexer(buffer.str());
        tokenList = testLexer.parse();
    } catch (DotException& e) {

        cout << "There was a problem lexing the source code: " << e.what() << endl;
        return 1;
    }

    string outFilepath = parser.getArgument("-o").empty() ? "a.tokens" : parser.getArgument("-o");
    ofstream outputFile(outFilepath);

    if(!outputFile.is_open()) {
        cout << "Failed opening output filestream \"" << outFilepath << "\"" << endl;
        return 1;
    }

    for(Token token : tokenList) {
        outputFile << endl;
        outputFile << "Token type: " << token.type << endl;
        outputFile << "Token value: " << token.value << endl;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
