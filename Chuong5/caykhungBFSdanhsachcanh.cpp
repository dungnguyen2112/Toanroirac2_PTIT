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

bool visited[100005];
vector<vector<int>> ke;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    ke.resize(n + 1, {});
    vector<pair<int, int>> v;
    queue<int> q;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    int dem1 = 0;
    bool check = true;
    q.push(k);
    visited[k] = true;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto i : ke[u])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
                v.push_back({u, i});
            }
        }
    }
    if (v.size() == n - 1)
        for (auto i : v)
            cout << i.first << " " << i.second << endl;
    else
        cout << "-1" << endl;
    ke.clear();
}

int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        solve();
    }
}