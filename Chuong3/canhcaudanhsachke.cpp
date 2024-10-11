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

int n, m, s, t;
vector<int> ke[1005];
bool visited[1005];
vector<pair<int, int>> res;
void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while (ss >> tmp)
        {
            ke[i].push_back(stoi(tmp));
            if (stoi(tmp) > i)
            {
                res.push_back({i, stoi(tmp)});
            }
        }
    }
    memset(visited, false, sizeof(visited));
}
void DFS(int u)
{
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        visited[v] = true;
        for (int i : ke[v])
        {
            if ((v == s && i == t) || (v == t && i == s))
                continue;
            if (!visited[i])
            {
                q.push(i);
            }
        }
    }
}
int tplt2()
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
    int lthong = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            DFS(i);
            lthong++;
        }
    }
    int dem = lthong;
    for (pair<int, int> i : res)
    {
        s = i.first, t = i.second;
        memset(visited, false, sizeof(visited));
        if (dem < tplt2())
        {
            cout << s << ' ' << t << ' ';
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
        s = -1, t = -1;
        nhap();
        check();
        memset(ke, 0, sizeof(ke));
        res.clear();
    }
}