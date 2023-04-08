//
// Created by David Loh on 08.04.23.
//

#include "CliParser.h"

CliParser::CliParser(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];

        if(arg[0] != '-') {
            error(i, &arg);
            return;
        }

        if(i + 1 < argc) {
            i++;
            string nextArg = argv[i];
            args.insert(make_pair(arg, nextArg));
        } else {
            args.insert(make_pair(arg, ""));
        }
    }
}

void CliParser::error(int i, string *arg) {
    error_ = true;
    cout << "Unknown argument at position " << i << ": " << *arg << endl;
}

bool CliParser::hasError() {
    return error_;
}

string CliParser::getArgument(string arg) {
    if(args.find(arg) != args.end()) return args[arg];
    else return {};
}

bool CliParser::hasFlag(string arg) {
    if(args.find(arg) != args.end()) return true;
    return false;
}

map<string, string> CliParser::getArguments() {
    return args;
}
