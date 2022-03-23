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

typedef struct freeListAllocator
{
    Buffer *buffer;
    void **items;
    unsigned int *itemSizes;
    void **freePositions;
    unsigned int *freeSizes;
} FreeListAllocator;

Buffer AllocateBuffer(unsigned int limit);
Buffer UseAsBuffer(void *location, unsigned int limit);
void DeallocateBuffer(const Buffer &b);

StackAllocator CreateStack(Buffer *b, unsigned int estimatedCount);
void DestroyStack(StackAllocator &allocator);

PoolAllocator CreatePool(Buffer *b, unsigned int itemSize, unsigned int estimatedCount);
void DestroyPool(PoolAllocator &pool);

FreeListAllocator CreateFreeList(Buffer *b, unsigned int estimatedCount);
void DestroyFreeList(FreeListAllocator &freeList);

#endif
