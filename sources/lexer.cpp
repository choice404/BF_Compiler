/*
Copyright (C) 2023 Lysus
See end of file for extended copyright information
*/

#include "../includes/lexer.h"

Lexer::Lexer()
{
    Log("Lexer: lexical Analyzer start");
    NewLine;
}

void Lexer::readCode(const char* code)
{
    Log("Lexer: Reading code: " << code);
    m_Code = code;
    m_TokensVec = tokenizeCode(m_Code);
}

void Lexer::readFile(const char* filename)
{
    Log("Lexer: Open file " << filename);
    m_CodeFile.open(filename);
    std::string tempCode;
    while(m_CodeFile >> tempCode)
        m_Code += tempCode;
    m_TokensVec = tokenizeCode(m_Code);
}

std::vector<Token> Lexer::tokenizeCode(const std::string& code)
{
    Log("Lexer: Tokenize code");
    NewLine;
    Log("Code: " << m_Code);
    NewLine;
    std::vector<Token> tokens;
    Token token;
    size_t position = 1;
    for(int i = 0; i < code.size(); i++)
    {
        switch(code[i])
        {
            case '+':
                Log("Lexer: Position " << position << " - Increment token added");
                token.m_Type = TokenType::Increment;
                break;
            case '-':
                Log("Lexer: Position " << position << " - Decrement token added");
                token.m_Type = TokenType::Decrement;
                break;
            case '>':
                Log("Lexer: Position " << position << " - RightShift token added");
                token.m_Type = TokenType::RightShift;
                break;
            case '<':
                Log("Lexer: Position " << position << " - LeftShift token added");
                token.m_Type = TokenType::LeftShift;
                break;
            case ',':
                Log("Lexer: Position " << position << " - Input token added");
                token.m_Type = TokenType::Input;
                break;
            case '.':
                Log("Lexer: Position " << position << " - Output token added");
                token.m_Type = TokenType::Output;
                break;
            case '[':
                Log("Lexer: Position " << position << " - StartLoop token added");
                token.m_Type = TokenType::StartLoop;
                break;
            case ']':
                Log("Lexer: Position " << position << " - EndLoop token added");
                token.m_Type = TokenType::EndLoop;
                break;
        }
        token.m_Position = position++;
        tokens.push_back(token);
    }
    return tokens;
}

int Lexer::size() { return m_TokensVec.size(); }
Token Lexer::operator[](size_t index) { return m_TokensVec[index]; }
std::vector<Token> Lexer::getTokensVec() { return m_TokensVec; }

std::vector<Token>* Lexer::getTokensVecAddress() { return &m_TokensVec; }

/*
Copyright (C) 2023 Lysus

BF_Compiler

A 2 stage brainfuck compiler made in CPP. It will first translate the source code to C++ then use the g++ compiler to compile it to an executable

This code is licensed under the GNU General Public License v3.0.
Please see the LICENSE file in the root directory of this project for the full license details.
*/
