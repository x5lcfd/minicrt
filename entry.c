#include "minicrt.h"

#include <Windows.h>

static void crt_fatal_error(const char *msg)
{
    // printf("fatal error: %s\n", msg);
    exit(1);
}

void mini_crt_entry(void)
{
    int ret;

    int flag = 0;
    int argc = 0;
    char *argv[16];
    char *cl = GetCommandLineA();

    argv[0] = cl;
    argc++;

    while (*cl)
    {
        if (*cl == '\"')
        {
            flag = flag == 0 ? 1 : 0;
        }
        else if (*cl == ' ' && flag == 0)
        {
            if (*(cl + 1))
            {
                argv[argc] = cl + 1;
                argc++;
            }

            *cl = '\0';
        }
        else
        {
            flag = 0;
        }
    }

    if (!mini_crt_heap_init())
        crt_fatal_error("heap initialize failed");

    if (!mini_crt_io_init())
        crt_fatal_error("IO initialize failed");

    ret = main(argc, argv);
    exit(ret);
}

void exit(int exitcode)
{
    mini_crt_call_exit_routine();

    ExitProcess(exitcode);
}