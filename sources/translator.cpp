/*
Copyright (C) 2023 Lysus
See end of file for extended copyright information
*/

#include "../includes/translator.h"

Translator::Translator(Lexer& lexer) : m_TokensVec(lexer.getTokensVec()) { }

std::string Translator::translateTokensCpp()
{
    std::string code = "";
    for(int i = 0; i < m_TokensVec.size(); i++)
    {
        switch(m_TokensVec[i].m_Type)
        {
            case (TokenType)0:
                code += "Increment(tape, ptr); ";
                break;
            case (TokenType)1:
                code += "Decrement(tape, ptr); ";
                break;
            case (TokenType)2:
                code += "RightShift(ptr); ";
                break;
            case (TokenType)3:
                code += "LeftShift(ptr); ";
                break;
            case (TokenType)4:
                code += "tape[ptr] = Input(); ";
                break;
            case (TokenType)5:
                code += "Output(tape, ptr); ";
                break;
            case (TokenType)6:
                code += "while(tape[ptr]) { ";
                break;
            case (TokenType)7:
                code += "}";
                break;
        }
    }
    return code;
}

/*
Copyright (C) 2023 Lysus

BF_Compiler

A 2 stage brainfuck compiler made in CPP. It will first translate the source code to C++ then use the g++ compiler to compile it to an executable

This code is licensed under the GNU General Public License v3.0.
Please see the LICENSE file in the root directory of this project for the full license details.
*/
