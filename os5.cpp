#include <iostream>
#include <vector>

using namespace std;

// Function to implement FIFO page replacement
void fifoPageReplacement(vector<int> &pages, int n, int capacity)
{
    vector<int> pageQueue(capacity, -1);
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
                cout << "Page " << pageQueue[front] << " replaced by " << page << endl;
                front = (front + 1) % capacity;
                pageQueue[rear++] = page;
            }
        }
    }
}

// Function to implement LRU page replacement
void lruPageReplacement(vector<int> &pages, int n, int capacity)
{
    vector<int> pageList(capacity, -1);
    vector<int> pageMap(100, -1); // Initialize with -1

    for (int i = 0; i < n; ++i)
    {
        int page = pages[i];
        int found = pageMap[page];

        if (found != -1)
        {
            for (int j = found; j > 0; --j)
            {
                pageList[j] = pageList[j - 1];
            }
        }
        else
        {
            if (capacity > 0)
            {
                --capacity;
            }
            else
            {
                cout << "Page " << pageList[capacity - 1] << " replaced by " << page << endl;
            }
        }

        pageList[0] = page;
        pageMap[page] = 0;
    }
}

// Function to implement Optimal page replacement
void optimalPageReplacement(vector<int> &pages, int n, int capacity)
{
    vector<int> pageIndices(capacity, -1);
    vector<int> nextIndex(100, n); // Initialize with n

    for (int i = n - 1; i >= 0; --i)
    {
        int page = pages[i];
        nextIndex[page] = i;
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

                cout << "Page " << pageIndices[index] << " replaced by " << page << endl;
                pageIndices[index] = page;
            }
        }
    }
}

int main()
{
    cout << "Samarth Khorate  SE AIDS A2 [22539]" << endl;
    vector<int> pages = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int n = pages.size();
    int capacity = 3;

    cout << "FIFO Page Replacement:" << endl;
    fifoPageReplacement(pages, n, capacity);

    cout << "\nLRU Page Replacement:" << endl;
    lruPageReplacement(pages, n, capacity);

    cout << "\nOptimal Page Replacement:" << endl;
    optimalPageReplacement(pages, n, capacity);

    return 0;
}
