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

typedef pair<int, int> ii;
int n, m, s;
vector<ii> adj[1005];
void nhap()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void dijkstra()
{
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s});
    vector<int> d(n + 1, 1e9);
    d[s] = 0;
    while (!q.empty())
    {
        ii t = q.top();
        q.pop();
        int dis = t.first, u = t.second;
        if (dis > d[u])
            continue;
        for (ii e : adj[u])
        {
            int v = e.first, w = e.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << ' ';
    }
}

int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        nhap();
        dijkstra();
        memset(adj, 0, sizeof(adj));
        cout << endl;
    }
}