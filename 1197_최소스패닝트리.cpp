#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 10000 + 1
using namespace std;

int Vertex, E, Answer;
int Parent[MAX];
vector<pair<int, pair<int, int>>> V;

int Find(int x)
{
    if (Parent[x] == x) return x;
    else return Parent[x] = Find(Parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x != y) Parent[y] = x;
}

bool SameParent(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y) return true;
    else return false;
}

int main(void)
{
    cin >> Vertex >> E;
    for (int i = 0; i < E; i++)
    {
        int From, To, Cost;
        cin >> From >> To >> Cost;

        V.push_back(make_pair(Cost, make_pair(From, To)));
    }

    sort(V.begin(), V.end());

    for (int i = 1; i <= Vertex; i++)
    {
        Parent[i] = i;
    }

    for (int i = 0; i < E; i++)
    {
        if (SameParent(V[i].second.first, V[i].second.second) == false)
        {
            Union(V[i].second.first, V[i].second.second);
            Answer = Answer + V[i].first;
        }
    }

    cout << Answer << endl;

    return 0;
}