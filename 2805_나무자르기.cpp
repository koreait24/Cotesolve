#pragma warning (disable:4996)
#include <stdio.h>
#include <vector>
using namespace std;

int main(void) {

    long long N, M, TREE;
    long long max = 0, treeH = 0;
    vector<int> tree;
    scanf("%lld %lld", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%lld", &TREE);
        tree.push_back(TREE);
        max = max < tree[i] ? tree[i] : max;
    }
    long long left = 0;
    long long right = max;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long total = 0;
        for (int i = 0; i < N; i++)
            if (mid < tree[i])
                total += tree[i] - mid;

        if (total >= M) {
            if (treeH < mid)
                treeH = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }

    printf("%lld\n", treeH);

    return 0;
}