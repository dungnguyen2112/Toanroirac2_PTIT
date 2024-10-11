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
using namespace std;

int n, m;
vector<int> ke[1005];
bool visited[1005];
void nhap()
{
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while (ss >> tmp)
        {
            ke[i].push_back(stoi(tmp));
        }
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
void check(int s, int t)
{
    memset(visited, false, sizeof(visited));
    DFS(s);
    if (visited[t])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        nhap();
        cout << tplt() << endl;
        memset(ke, 0, sizeof(ke));
    }
}