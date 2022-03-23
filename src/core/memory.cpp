#include "core/memory.h"
#include "pch.h"

Buffer AllocateBuffer(unsigned int limit)
{

}

Buffer UseAsBuffer(void *location, unsigned int limit)
{

}

void DeallocateBuffer(const Buffer &b)
{

}


StackAllocator CreateStack(Buffer *b, unsigned int estimatedCount)
{

}

void DestroyStack(StackAllocator &allocator)
{

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

