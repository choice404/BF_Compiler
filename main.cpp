/*
Copyright (C) 2023 Lysus
See end of file for extended copyright information
*/

#include "./includes/includes.h"

int main(int argc, const char* argv[])
{
    if(!argc)
    {
        std::cout << "ERROR: No file to compile or arguments given" << std::endl;
        return 1;
    }
    Lexer lexer;
    if(argc == 3 && static_cast<std::string>(argv[1]) == "-r")
    {
        lexer.readCode(argv[2]);
    }
    else if(argc == 2)
    {
        lexer.readFile(argv[1]);
    }
    Translator translator(lexer);
    std::ofstream bfOutput("brainfuck.cpp");
    bfOutput << "#include <iostream>\n"
                << "void Increment(char[], int);" << std::endl
                << "void Decrement(char[], int);" << std::endl
                << "void RightShift(int&);" << std::endl
                << "void LeftShift(int&);" << std::endl
                << "char Input();" << std::endl
                << "void Output(char[], int);" << std::endl
                << "int main() { char tape[200] = {}; int ptr = 0; " << std::endl;
    bfOutput << translator.translateTokensCpp();
    bfOutput << "return 0; } " << std::endl
                << "void Increment(char tape[], int ptr) {" << std::endl
                    << "if((int)tape[ptr] == 255) { tape[ptr] = 0; }" << std::endl
                    << "else { tape[ptr]++; }" << std::endl
                << "}" << std::endl
                << "void Decrement(char tape[], int ptr) {" << std::endl
                    << "if(tape[ptr] == 0) { tape[ptr] = (char)255; }" << std::endl
                    << "else { tape[ptr]--; }" << std::endl
                << "}" << std::endl
                << "void RightShift(int& ptr) { ptr++; }" << std::endl
                << "void LeftShift(int& ptr) { ptr--; }" << std::endl
                << "char Input() {" << std::endl
                    << "std::string input = \"\";" << std::endl
                    << "std::getline(std::cin, input);" << std::endl
                    << "return input[0];" << std::endl
                << "}" << std::endl
                << " void Output(char tape[], int ptr) { std::cout << tape[ptr] << std::endl; }" << std::endl;

    system("g++ brainfuck.cpp -o bf.out");
    remove("brainfuck.cpp");

};

/*
Copyright (C) 2023 Lysus

BF_Compiler

A 2 stage brainfuck compiler made in CPP. It will first translate the source code to C++ then use the g++ compiler to compile it to an executable

This code is licensed under the GNU General Public License v3.0.
Please see the LICENSE file in the root directory of this project for the full license details.
*/
