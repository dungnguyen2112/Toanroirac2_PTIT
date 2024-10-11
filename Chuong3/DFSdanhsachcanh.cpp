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

vector<int> ke[100005];
bool visited[100005];

void DFS1(int u)
{
    cout << u << ' ';
    visited[u] = true;
    for (auto i : ke[u])
    {
        if (!visited[i])
        {
            DFS(i)
        }
    }
}

void DFS2(int u)
{
    visited[u] = 1;
    stack<int> s;
    s.push(u);
    cout << u << ' ';
    while (s.size())
    {
        int v = s.top();
        s.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i])
            {
                visited[i] = 1;
                cout << i << ' ';
                s.push(v);
                s.push(i);
                break;
            }
        }
    }
}

int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        int n, m, u;
        cin >> n >> m >> u;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        memset(visited, false, sizeof(visited));
        DFS(u);
        memset(ke, 0, sizeof(ke));
        cout << endl;
    }
}