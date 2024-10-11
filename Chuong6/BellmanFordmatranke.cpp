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

struct edge
{
    int x, y, w;
};
const int INF = (int)1e9;
int n, m, s;
vector<edge> E;
int d[1005];
int a[1005][1005];
void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] > 0)
            {
                E.push_back((edge){i, j, a[i][j]});
            }
        }
    }
}
void BellmanFord()
{
    fill(d + 1, d + n + 1, INF);
    d[s] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (edge e : E)
        {
            int u = e.x, v = e.y, w = e.w;
            if (d[u] < INF)
            {
                d[v] = min(d[v], d[u] + w);
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
    nhap();
    BellmanFord();
    cout << endl;
}
int n, s, a[100][100], d[100], e[100], vs[100];
void Dijkstra(int s)
{
    int u, v;
    for (v = 1; v <= n; v++)
    {
        d[v] = a[s][v];
        e[v] = s;
        vs[v] = 0
    }
    d[s] = 0;
    e[s] = 0;
    vs[s] = 1;
    while (1)
    {
        int u = 0, mind = 32767;
        for (v = 1; v <= n; v++)
            if (vs[v] == 0 && d[v] < mind)
            {
                u = v;
                mind = d[v];
            }
        if (u == 0)
            return;
        vs[u] = 1;
        for (v = 1; v <= n; v++)
            if (vs[v] == 0 && d[v] > d[u] + a[u][v])
            {
                d[v] = d[u] + a[u][v];
                e[v] = u;
            }
    }
}
