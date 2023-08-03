/*
Copyright (C) 2023 Lysus
See end of file for extended copyright information
*/

#pragma once

#include "lexer.h"

class Translator
{
public:
    Translator(const Lexer&);
    Translator(Lexer&);

    std::string translateTokensCpp();
//    const char* translateTokensX86();
//    const char* translateTokensMIPS();
private:
    std::vector<Token> m_TokensVec;
};

/*
Copyright (C) 2023 Lysus

BF_Compiler

A 2 stage brainfuck compiler made in CPP. It will first translate the source code to C++ then use the g++ compiler to compile it to an executable

This code is licensed under the GNU General Public License v3.0.
Please see the LICENSE file in the root directory of this project for the full license details.
*/
