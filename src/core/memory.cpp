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
    stack.maxItems = estimatedCount;
    stack.itemPointers = (void**)malloc(sizeof(void*) * estimatedCount);

    return stack;
}

void DestroyStack(StackAllocator &allocator)
{
    free(stack.itemPointers);
}

void *AllocateInStack(StackAllocator &stack, unsigned int size)
{
    void *result = nullptr;

    if (stack.buffer->size + size >= stack.buffer->limit)
        return result;

    result = stack.buffer->data + stack.buffer->size;
    stack.buffer->size += size;
    
    if (stack.count >= stack.maxItems)
    {
        stack.itemPointers = realloc(stack.itemPointers, 2 * stack.maxItems);
        stack.maxItems *= 2;
    }

    stack.itemPointers[stack.count] = result;
    stack.count++;

    return result;
}

void PopFromStack(StackAllocator &stack)
{
    if (stack.count == 0)
        return;
    
    stack.itemPointers[stack.count - 1] = nullptr;
    stack.count--;
}



PoolAllocator CreatePool(Buffer *b, unsigned int itemSize, unsigned int estimatedCount)
{
    PoolAllocator pool;

    pool.buffer = b;
    pool.itemsize = itemSize;
    pool.count = 0;
    pool.items = (void**)malloc(sizeof(void*) * estimatedCount);
    for (int i = 0; i < estimatedCount; ++i)
        pool.items[i] = nullptr;
    pool.freePositions = (void**)malloc(sizeof(void*) * estimatedCount);
    for (int i = 0; i < estimatedCount; ++i)
        pool.freePositions[i] = nullptr;
    pool.freePositions[0] = pool.buffer->data;

    return pool;
}

void DestroyPool(PoolAllocator &pool)
{
    free(pool.items);
    free(pool.freePositions);
}

void *AllocateInPool(PoolAllocator &pool)
{
    void *result = nullptr;

    if (pool.buffer->size + pool.itemSize >= pool.buffer->limit)
        return result;
    
    int freeItemCount = (pool.buffer->size / pool.itemSize) - pool.count;

    

    return result;
}

void DeallocateFromPool(PoolAllocator &pool, void *location)
{

}
