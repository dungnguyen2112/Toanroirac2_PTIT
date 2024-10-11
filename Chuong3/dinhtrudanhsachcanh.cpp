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

int n, m;
vector<int> ke[1005];
bool visited[1005];
void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void DFS(int u)
{
    visited[u] = true;
    for (auto i : ke[u])
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }
}
int tplt()
{
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dem++;
            DFS(i);
        }
    }
    return dem;
}
void check()
{
    int dem = tplt();
    for (int i = 1; i <= n; i++)
    {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        if (dem < tplt())
        {
            cout << i << ' ';
        }
    }
    cout << endl;
}
int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        nhap();
        check();
        memset(ke, 0, sizeof(ke));
    }
}