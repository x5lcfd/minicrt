#ifndef _MINICRT_H_
#define _MINICRT_H_

#ifdef _cplusplus
extern "C"
{
#endif

#ifndef NULL
#define NULL 0
#endif

    void free(void *ptr);
    void *malloc(unsigned size);

    static long brk(void *end_data_segment);

    int mini_crt_heap_init();

    char *itoa(long n, char *str, long radix);
    char *strcpy(char *dst, char *src);
    long strcmp(const char *src, char *dst);
    unsigned strlen(const char *str);

    typedef long FILE;
#define EOF (-10)

#define stdin ((FILE *)GetStdHandle(STD_INPUT_HANDLE))
#define stdout ((FILE *)GetStdHandle(STD_OUTPUT_HANDLE))
#define stderr ((FILE *)GetStdHandle(STD_ERROR_HANDLE))

    int mini_crt_init_io();
    FILE *fopen(const char *filename, const char *mode);
    int fread(void *buffer, int size, int count, FILE *stream);
    int fwrite(const void *buffer, int size, int count, FILE *stream);
    int fclose(FILE *fp);
    int fseek(FILE *fp, int offset, int set);

    int fputc(int c, FILE *stream);
    int fputs(const char *str, FILE *stream);
    int printf(const char *format, ...);
    int fprintf(FILE *stream, const char *format, ...);

    void do_global_ctors();
    void mini_crt_call_exit_routine();

    typedef void (*atexit_func_t)(void);
    int atexit(atexit_func_t func);

#ifdef _cplusplus
}
#endif

#endif