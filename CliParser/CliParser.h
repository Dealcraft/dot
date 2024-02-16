//
// Created by David Loh on 08.04.23.
//

#ifndef DOT_LANG_CLIPARSER_H
#define DOT_LANG_CLIPARSER_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class CliParser {
private:
    bool error_ = false;
    bool file = false;
    void error(int i, string* arg);
    map<string, string> args;

public:
    CliParser(int argc, char* argv[]);
    bool hasError();
    string getArgument(string arg);
    bool hasFlag(string arg);
    map<string, string> getArguments();
};




#endif //DOT_LANG_CLIPARSER_H
