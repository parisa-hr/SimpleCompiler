#include <stdio.h>
#include <stdlib.h>
#include "compiler.h"


struct compilerprocess *compiler_process_create(const char* filename,const char* filenameout,int flags)
{
    FILE *file = fopen(filename,"r");
    if (!file)
    {
        return NULL;
    }
    FILE *out_file = NULL;
    if(filenameout) 
    {
        out_file = fopen(filenameout,"w");
        if (!out_file)
        {
            return NULL;
        }

    }

    struct compile_process* process = calloc(1, sizeof(struct compile_process));
    process->flags = flags;
    process->cfile.fp = file;
    process->ofile = out_file;

    return process;

}
