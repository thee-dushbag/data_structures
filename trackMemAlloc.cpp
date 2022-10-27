#ifndef TRACK_MEM_ALLOC
#define TRACK_MEM_ALLOC 1

#include <iostream>

int MyMemCounter = 0;

void *operator new(size_t size)
{
	MyMemCounter++;
	std::cout << "\x1b[31;1mNew Memory | MemCounter : " << MyMemCounter << "\x1b[0m\n";
	return malloc(size);
}

void operator delete(void *addr)
{
	MyMemCounter--;
	std::cout << "\x1b[32;1mMemory Freed         | MemCounter : " << MyMemCounter << "\x1b[0m\n";
	free(addr);
}

#endif