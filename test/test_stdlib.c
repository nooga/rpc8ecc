#include <stdlib.h>
#include "test.h"


// void* malloc (size_t size);
// void* calloc (size_t count, size_t size);
// void* realloc (void* block, size_t size);
// void free (void* block);
// void _heapadd (void* mem, size_t size);
// size_t _heapblocksize (const void* block);
// size_t _heapmemavail (void);
// size_t _heapmaxavail (void);
// int rand (void);
// void srand (unsigned seed);
// void _randomize (void);        
// void abort (void);
//// int abs (int val);
// long labs (long val);
//// int atoi (const char* s);
// long atol (const char* s);
// int atexit (void (*exitfunc) (void));
// void* bsearch (const void* key, const void* base, size_t n, size_t size, int (*cmp) (const void*, const void*));
// div_t div (int numer, int denom);
// void exit (int ret);
// char* getenv (const char* name);
// void qsort (void* base, size_t count, size_t size, int (*compare) (const void*, const void*));
// long strtol (const char* nptr, char** endptr, int base);
// unsigned long strtoul (const char* nptr, char** endptr, int base);
// int system (const char* s);
// void _swap (void* p, void* q, size_t size);
//// char* itoa (int val, char* buf, int radix);
// char* utoa (unsigned val, char* buf, int radix);
// char* ltoa (long val, char* buf, int radix);
// char* ultoa (unsigned long val, char* buf, int radix);
// int putenv (char* s);


void main()
{
	char temp[5];

	init_tests();

	TEST("abs", 1 		== abs(-1));
	TEST("abs", 0xFAF 	== abs(0xFAF));

	TEST("itoa-atoi", 257 == atoi(itoa(257, temp, 10)));
}