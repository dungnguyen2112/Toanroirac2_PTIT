#include <bits/stdc++.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#define faster()                           \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL);
using namespace std;
using std::string;

const int maxn = 1005;
int n, m;
vector<pair<int, int>> adj[1005];
bool visited[1005];

void nhap()
{
    cin >> n;
    int a[n + 5][n + 5];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                adj[i].push_back({j, a[i][j]});
                adj[j].push_back({i, a[i][j]});
            }
        }
    }
}
void Prim(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    visited[s] = true;
    int d = 0;
    for (pair<int, int> x : adj[s])
    {
        if (!visited[x.first])
        {
            q.push({x.second, x.first});
        }
    }
    while (!q.empty())
    {
        pair<int, int> top = q.top();
        q.pop();
        int u = top.second, w = top.first;
        if (!visited[u])
        {
            d += w;
            visited[u] = true;
            for (pair<int, int> x : adj[u])
            {
                if (!visited[x.first])
                {
                    q.push({x.second, x.first});
                }
            }
        }
    }
    cout << d << endl;
}

int main()
{
    nhap();
    Prim(1);
}