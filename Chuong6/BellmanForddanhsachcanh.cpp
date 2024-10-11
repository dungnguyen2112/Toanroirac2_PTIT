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
void nhap()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        E.push_back((edge){x, y, w});
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