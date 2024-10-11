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
int parent[1005];

void DFS(int u)
{
    visited[u] = true;
    for (int v = 1; v <= n; ++v)
    {
        if (ke[u][v] && !visited[v])
        {
            DFS(v);
            parent[v] = u;
        }
    }
}

void check(int s, int t)
{
    DFS(s);
    if (!visited[t])
    {
        cout << -1 << endl;
    }
    else
    {
        vector<int> res;
        while (t != s)
        {
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);
        reverse(res.begin(), res.end());
        for (auto i : res)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        cin >> n >> m >> s >> t;
        memset(ke, 0, sizeof(ke)); // Khởi tạo ma trận kề với giá trị mặc định là 0 (không có cạnh)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        memset(visited, false, sizeof(visited)); // Khởi tạo mảng visited cho DFS
        memset(parent, 0, sizeof(parent));       // Khởi tạo mảng parent cho việc lưu đường đi
        check(s, t);                             // Kiểm tra và in đường đi từ đỉnh s đến đỉnh t
    }
    return 0;
}