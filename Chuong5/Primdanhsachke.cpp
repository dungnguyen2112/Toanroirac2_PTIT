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
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    memset(visited, false, sizeof(visited));
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
    vector<pair<int, int>> v;
    while (!q.empty())
    {
        pair<int, int> top = q.top();
        q.pop();
        int u = top.second, w = top.first;
        if (!visited[u])
        {
            d += w;
            v.push_back({u, 0});
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
    for (auto i : v)
    {
        cout << i.first << ' ' << i.second << endl;
    }
    cout << d << endl;
}

int main()
{
    nhap();
    Prim(2);
}