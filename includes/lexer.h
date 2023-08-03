/*
Copyright (C) 2023 Lysus
See end of file for extended copyright information
*/

#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#define Log(x) (std::cout << x << std::endl)
#define NewLine std::cout << std::endl

// Enumerate class of Token types
enum class TokenType
{
    Increment,  // +
    Decrement,  // -
    RightShift, // >
    LeftShift,  // <
    Input,      // ,
    Output,     // .
    StartLoop,  // [
    EndLoop     // ]
};

struct Token
{
    TokenType m_Type;
    size_t m_Position;
};

class Lexer {
public:
    Lexer();

    void readCode(const char*);
    void readFile(const char*);
    int size();
    std::vector<Token>* getTokensVecAddress();
    std::vector<Token> getTokensVec();

    Token operator[](size_t);
private:
    std::vector<Token> tokenizeCode( const std::string&);

private:
    std::string m_Code;
    size_t m_Size;
    std::vector<Token> m_TokensVec;
    const char* m_Filename;
    std::ifstream m_CodeFile;
};

/*
Copyright (C) 2023 Lysus

BF_Compiler

A 2 stage brainfuck compiler made in CPP. It will first translate the source code to C++ then use the g++ compiler to compile it to an executable

This code is licensed under the GNU General Public License v3.0.
Please see the LICENSE file in the root directory of this project for the full license details.
*/
