//
// Created by David Loh on 08.04.23.
//

#ifndef DOT_LANG_CLISTATICCOMMANDS_H
#define DOT_LANG_CLISTATICCOMMANDS_H

using namespace std;

class CliStaticCommands {
public:
    static void help() {
        cout << "Usage: dot [options] [arguments]" << endl;
        cout << "Options:" << endl;
        cout << "\t-h, --help\t Displays this help message" << endl;
        cout << "\t-v, --version\t Displays the version of the compiler" << endl;
        cout << endl;
        cout << "Arguments:" << endl;
        cout << "\t-i [filepath]\t Defines the input file" << endl;
        cout << "\t-o [filepath]\t Defines the output file" << endl;
    }
    static void version() {
        cout << "v0.0.1-beta" << endl;
    }
};

#endif //DOT_LANG_CLISTATICCOMMANDS_H
