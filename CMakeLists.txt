cmake_minimum_required(VERSION 3.25)
project(dot_lang)

set(CMAKE_CXX_STANDARD 17)

add_executable(dot_lang main.cpp Lexer/Lexer.cpp Lexer/Lexer.h Lexer/LexerTokenType.h CliParser/CliParser.cpp CliParser/CliParser.h CliParser/CliStaticCommands.h Exceptions/TokenException.cpp Exceptions/TokenException.h Exceptions/DotException.cpp Exceptions/DotException.h
        Expressions/literalExpressions/NumericValue.cpp
        Expressions/literalExpressions/NumericValue.h
        Expressions/literalExpressions/TextValue.cpp
        Expressions/literalExpressions/TextValue.h
        Expressions/Expression.cpp
        Expressions/Expression.h
        Expressions/literalExpressions/Value.cpp
        Expressions/literalExpressions/Value.h)
add_executable(dot main.cpp Lexer/Lexer.cpp Lexer/Lexer.h Lexer/LexerTokenType.h CliParser/CliParser.cpp CliParser/CliParser.h CliParser/CliStaticCommands.h Exceptions/TokenException.cpp Exceptions/TokenException.h Exceptions/DotException.cpp Exceptions/DotException.h
        Expressions/literalExpressions/NumericValue.cpp
        Expressions/literalExpressions/NumericValue.h
        Expressions/literalExpressions/TextValue.cpp
        Expressions/literalExpressions/TextValue.h
        Expressions/Expression.cpp
        Expressions/Expression.h
        Expressions/literalExpressions/Value.cpp
        Expressions/literalExpressions/Value.h)
