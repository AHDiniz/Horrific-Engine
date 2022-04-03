#ifndef MEMORY_H_

#define MEMORY_H_

typedef struct buffer
{
    void *data;
    unsigned int size;
    unsigned int limit;
};

typedef struct stackAllocator
{
    Buffer *buffer;
    unsigned int count;
    unsigned int maxItems;
    void **itemPointers;
} StackAllocator;

typedef struct poolAllocator
{
    Buffer *buffer;
    unsigned int count;
    unsigned int itemSize;
    void **items;
    void **freePositions;
} PoolAllocator;

Buffer AllocateBuffer(unsigned int limit);
Buffer UseAsBuffer(void *location, unsigned int limit);
void DeallocateBuffer(const Buffer &b);

StackAllocator CreateStack(Buffer *b, unsigned int estimatedCount);
void DestroyStack(StackAllocator &allocator);
void *AllocateInStack(StackAllocator &stack, unsigned int size);
void PopFromStack(StackAllocator &stack);

PoolAllocator CreatePool(Buffer *b, unsigned int itemSize, unsigned int estimatedCount);
void DestroyPool(PoolAllocator &pool);
void *AllocateInPool(PoolAllocator &pool);
void DeallocateFromPool(PoolAllocator &pool, void *location);

#endif
