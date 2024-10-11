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

int maxn = 1005;
int n, m;
vector<edge> E;
int parent[1005], sz[1005];

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edge e{x, y, w};
        E.push_back(e);
    }
}

void init()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = i;
    }
}

int Find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v)
        return false;
    if (sz[u] < sz[v])
        swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
    return true;
}

void Kruskal()
{
    vector<edge> MST;
    int d = 0;
    sort(E.begin(), E.end(), [](edge x, edge y) -> bool
         { return x.w < y.w; });
    for (edge e : E)
    {
        if (MST.size() == n - 1)
            break;
        if (Union(e.x, e.y))
        {
            MST.push_back(e);
            d += e.w;
        }
    }
    if (MST.size() < n - 1)
    {
        cout << "Do thi khong lien thong !\n";
    }
    else
    {
        cout << d << endl;
        for (edge e : MST)
        {
            cout << e.x << ' ' << e.y << ' ' << endl;
        }
    }
}

int main()
{
    nhap();
    init();
    Kruskal();
}