#include "core/memory.h"
#include "pch.h"

Buffer AllocateBuffer(unsigned int limit)
{
    Buffer buffer;

    buffer.data = malloc(limit);
    buffer.limit = limit;
    buffer.size = 0;

    return buffer;
}

Buffer UseAsBuffer(void *location, unsigned int limit)
{
    Buffer buffer;

    buffer.data = location;
    buffer.limit = limit;
    buffer.size = 0;

    return buffer;
}

void DeallocateBuffer(const Buffer &b)
{
    free(b.data);
}


StackAllocator CreateStack(Buffer *b, unsigned int estimatedCount)
{
    StackAllocator stack;

    stack.buffer = b;
    stack.count = 0;
    stack.itemPointers = (void**)malloc(sizeof(void*) * estimatedCount);

    return stack;
}

void DestroyStack(StackAllocator &allocator)
{
    free(stack.itemPointers);
}


PoolAllocator CreatePool(Buffer *b, unsigned int itemSize, unsigned int estimatedCount)
{
    
}

void DestroyPool(PoolAllocator &pool)
{

}


FreeListAllocator CreateFreeList(Buffer *b, unsigned int estimatedCount)
{

}

void DestroyFreeList(FreeListAllocator &freeList)
{

}

