#include <cstdlib>
#include <cstdio>
#include <cstdarg>

#include "simple_logger.h"

FILE * __log_file = nullptr;

void close_logger()
{
    if (__log_file != nullptr)
    {
        fclose(__log_file);
        __log_file = nullptr;
    }
}

void init_logger(const char *log_file_path)
{
    if (log_file_path == nullptr)
    {
        __log_file = fopen("output.log","a");
    }
    else
    {
        __log_file = fopen(log_file_path,"a");
    }
    atexit(close_logger);
}

void _slog(char *f,int l,char *msg,...)
{
    va_list ap;
    /*echo all logging to stdout*/
    va_start(ap,msg);
    fprintf(stdout,"%s:%i: ",f,l);
    vfprintf(stdout,msg,ap);
    fprintf(stdout,"\n");
    va_end(ap);
    if (__log_file != nullptr)
    {
        va_start(ap,msg);
        fprintf(__log_file,"%s:%i: ",f,l);
        vfprintf(__log_file,msg,ap);
        fprintf(__log_file,"\n");
        va_end(ap);
    }
}