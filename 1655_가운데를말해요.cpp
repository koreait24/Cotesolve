#pragma warning (disable:4996)

#include <stdio.h>
#include <queue>
#include <vector>

int main()
{
    std::priority_queue<int> maxheap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;
    int res[100000];
    int n, count = 0;
    scanf("%d", &n);

    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        if (maxheap.size() == 0) {
            maxheap.push(x);
        }
        else {

            if (maxheap.size() > minheap.size()) {
                minheap.push(x);
            }
            else {
                maxheap.push(x);
            }

            if (maxheap.top() > minheap.top()) {
                int maxtop = maxheap.top();
                int mintop = minheap.top();
                maxheap.pop();
                minheap.pop();
                maxheap.push(mintop);
                minheap.push(maxtop);
            }
        }
        res[count] = maxheap.top();
        count++;
    }

    for (int i = 0; i < count; i++) {
        printf("%d\n", res[i]);
    }

    return 0;
}