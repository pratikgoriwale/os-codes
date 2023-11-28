#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100

// Function to find the index of a page in the page frame
int findPage(int page, int pageFrame[], int capacity) {
    for (int i = 0; i < capacity; ++i) {
        if (pageFrame[i] == page) {
            return i;
        }
    }
    return -1; // Page not found in the page frame
}

// Function to implement LRU page replacement algorithm
void lruPageReplacement(int pages[], int n, int capacity) {
    int pageFrame[capacity];
    int pageOrder[MAX_PAGES] = {0};
    int pageFaults = 0;
    int time = 0;

    for (int i = 0; i < n; ++i) {
        int page = pages[i];
        int pageIndex = findPage(page, pageFrame, capacity);

        if (pageIndex == -1) {
            if (time < capacity) {
                pageFrame[time] = page;
                pageOrder[time] = page;
                ++time;
            } else {
                int lruIndex = 0;

                for (int j = 1; j < capacity; ++j) {
                    if (pageOrder[j] < pageOrder[lruIndex]) {
                        lruIndex = j;
                    }
                }

                pageFrame[lruIndex] = page;
                pageOrder[lruIndex] = time;
            }

            ++pageFaults;
        } else {
            pageOrder[pageIndex] = time;
        }

        ++time;
    }

    printf("LRU Page Replacement:\n");
    printf("Page Faults: %d\n", pageFaults);
}

// Function to implement Optimal page replacement algorithm
void optimalPageReplacement(int pages[], int n, int capacity) {
    int pageFrame[capacity];
    int pageOrder[MAX_PAGES] = {0};
    int pageFaults = 0;
    int time = 0;

    for (int i = 0; i < n; ++i) {
        int page = pages[i];
        int pageIndex = findPage(page, pageFrame, capacity);

        if (pageIndex == -1) {
            if (time < capacity) {
                pageFrame[time] = page;
            } else {
                int farthestIndex = 0;

                for (int j = 0; j < capacity; ++j) {
                    int k;
                    for (k = i + 1; k < n; ++k) {
                        if (pageFrame[j] == pages[k]) {
                            break;
                        }
                    }

                    if (k == n) {
                        farthestIndex = j;
                        break;
                    }
                }

                pageFrame[farthestIndex] = page;
            }

            ++pageFaults;
        }

        ++time;
    }

    printf("Optimal Page Replacement:\n");
    printf("Page Faults: %d\n", pageFaults);
}

int main() {
    printf("Samarth Khorate SE AIDS A2 [22539]\n");
    int pages[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    lruPageReplacement(pages, n, capacity);
    optimalPageReplacement(pages, n, capacity);

    return 0;
}
