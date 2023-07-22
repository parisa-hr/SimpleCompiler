#pragma once

#include <stdio.h>
#include <stdbool.h>


// These are used to indicate the result of the compilation process.
enum
{
    COMPILER_FILE_COMPILED_OK,
    COMPILER_FAILED_WITH_ERRORS
};

/*
This enumeration lists various token types that can be encountered during 
the process of tokenization in a compiler. Each constant represents
a different type of token, such as identifiers, keywords, operators,
symbols, numbers, strings, comments, and newlines.
*/
enum
{
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_TYPE_KEYWORD,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_SYMBOL,
    TOKEN_TYPE_NUMBER,
    TOKEN_TYPE_STRING,
    TOKEN_TYPE_COMMENT,
    TOKEN_TYPE_NEWLINE
};

// This structure represents a position in a source file.
struct pos
{
    int line;
    int col;
    const char * filename;

};


struct token
{
    int type;
    int flags;

    struct pos pos;


    union
    {
        char cval;
        const char *sval;
        unsigned int inum;
        unsigned long lnum;
        unsigned long long llnum;
        void *any;
    };

    struct token_number
    {
        int type;
    } num;

    // True if their is whitespace between the token and the next token
    // i.e * a for operator token * would mean whitespace would be set for token "a"
    bool whitespace;

    // (5+10+20)
    const char *between_brackets;

    // Anything between function call arguments. ABC(hello world)
    const char* between_arguments;
};

struct compile_process
{
    //The flags in regards to how this file should be compiled
    int flags;
    struct compile_process_input_file
    {
        FILE *fp;
        const char *abs_path;
    } cfile;

    FILE *ofile;

};


int compile_file (const char* filename,const char* filenameout,int flags);
struct compilerprocess *compiler_process_create(const char* filename,const char* filenameout,int flags);


