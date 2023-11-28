#include <stdio.h>
#include <stdlib.h>

// Function to implement FIFO page replacement
void fifoPageReplacement(int pages[], int n, int capacity)
{
    int pageQueue[capacity];
    int front = 0, rear = 0;

    for (int i = 0; i < n; ++i)
    {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < capacity; ++j)
        {
            if (pageQueue[j] == page)
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            if (rear < capacity)
            {
                pageQueue[rear++] = page;
            }
            else
            {
                printf("Page %d replaced by %d\n", pageQueue[front], page);
                front = (front + 1) % capacity;
                pageQueue[rear++] = page;
            }
        }
    }
}

// Function to implement LRU page replacement
void lruPageReplacement(int pages[], int n, int capacity)
{
    int pageList[capacity];
    int pageMap[100] = {0}; // Assuming pages are numbered from 1 to 100

    for (int i = 0; i < n; ++i)
    {
        int page = pages[i];
        int found = pageMap[page];

        if (found)
        {
            int j;

            for (j = 0; j < found - 1; ++j)
            {
                pageList[j] = pageList[j + 1];
            }

            pageList[j] = page;
        }
        else
        {
            if (capacity > 0)
            {
                for (int j = capacity - 1; j > 0; --j)
                {
                    pageList[j] = pageList[j - 1];
                }

                pageList[0] = page;
                pageMap[page] = 1;
                --capacity;
            }
            else
            {
                printf("Page %d replaced by %d\n", pageList[capacity - 1], page);
                for (int j = capacity - 1; j > 0; --j)
                {
                    pageList[j] = pageList[j - 1];
                }

                pageList[0] = page;
            }
        }
    }
}

// Function to implement Optimal page replacement
void optimalPageReplacement(int pages[], int n, int capacity)
{
    int pageIndices[capacity];
    int nextIndex[100] = {0}; // Assuming pages are numbered from 1 to 100

    for (int i = n - 1; i >= 0; --i)
    {
        int page = pages[i];

        if (nextIndex[page] == 0)
        {
            nextIndex[page] = i;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < capacity; ++j)
        {
            if (pageIndices[j] == page)
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            if (capacity > 0)
            {
                pageIndices[capacity - 1] = page;
                --capacity;
            }
            else
            {
                int farthest = -1, index;

                for (int j = 0; j < capacity; ++j)
                {
                    if (nextIndex[pageIndices[j]] > farthest)
                    {
                        farthest = nextIndex[pageIndices[j]];
                        index = j;
                    }
                }

                printf("Page %d replaced by %d\n", pageIndices[index], page);
                pageIndices[index] = page;
            }
        }
    }
}

int main()
{
    printf("\nPratik Goriwale SE AIDS A2 [22535]");
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    printf("\nFIFO Page Replacement:\n");
    fifoPageReplacement(pages, n, capacity);

    printf("\nLRU Page Replacement:\n");
    lruPageReplacement(pages, n, capacity);

    printf("\nOptimal Page Replacement:\n");
    optimalPageReplacement(pages, n, capacity);

    return 0;
}
