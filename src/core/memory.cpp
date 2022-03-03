#include "core/memory.h"
#include "pch.h"

void *CreateMemCache(int size)
{
    return malloc(size);
}

void DeleteMemCache(void *cache)
{
    free(cache);
}
