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
int dem, dem1;
void check(int s, int t)
{
    memset(visited, false, sizeof(visited));
    DFS(s);
    if (visited[t])
    {
        dem++;
    }
    else
    {
        dem1++;
    }
}
int main()
{
    faster() int x;
    cin >> x;
    while (x--)
    {
        dem = dem1 = 0;
        nhap();
        for (int i = 1; i <= n; i++)
        {
            DFS(i);
            bool ok = false;
            for (int j = 1; j <= n; j++)
            {
                if (!visited[j])
                {
                    ok = true;
                    break;
                }
            }
            if (ok)
            {
                dem1++;
                break;
            }
        }
        if (dem1)
        {
            cout << "NO";
        }
        else
            cout << "YES";
        memset(ke, 0, sizeof(ke));
        cout << endl;
    }
}