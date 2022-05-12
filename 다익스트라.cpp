#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int v, e, s, x, y, z, d[20002];

vector<vector<pair<int, int>>> vt;

int main() {
    scanf("%d%d%d", &v, &e, &s);
    vt.resize(v + 1);

    for (int i = 0; i < e; i++) {
        scanf("%d%d%d", &x, &y, &z);
        vt[x].push_back({ y,z });
    }    //��������Ʈ�� �׷����� ����

    memset(d, -1, sizeof(d));//�Ÿ��� ��� �迭 d�� ���� �� ���� ��(-1)�� �ʱ�ȭ
    priority_queue<pair<int, int>> pq;//������ ���� ��(�Ÿ�,����)
    pq.push({ 0,s });//���������� ������ ����
    while (pq.size()) {//pq�� �� ������ ���ͽ�Ʈ�� �˰��� ����
        int here = pq.top().second;//���� Ȯ���ϴ� ����
        int cost = -pq.top().first;//�Ÿ�(���) -�� ���̴� ������ pq�� minheap���� ����ϱ� ����
        pq.pop();
        if (d[here] != -1)
            continue;//�̹� ���Ǿ��ٸ� �Ѿ
        d[here] = cost;//�ִܰŸ� ������ ����
        for (auto it : vt[here]) {
            int next = it.first;//���� ����
            int acost = -it.second - cost;//���� �� �Ÿ�
            if (d[next] != -1)
                continue;//�̹� ���Ǿ��ٸ� �Ѿ
            pq.push({ acost,next });
        }
    }
    for (int i = 1; i <= v; i++) {
        if (d[i] == -1)puts("INF");
        else printf("%d\n", d[i]);
    }//�ִܰŸ� ���
    return 0;
}