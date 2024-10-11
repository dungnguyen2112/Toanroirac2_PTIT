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
int ke[1005][1005];
bool visited[1005];

void nhap()
{
    cin >> n;
    memset(ke, false, sizeof(ke)); // Khởi tạo ma trận kề với giá trị false (không có cạnh)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ke[i][j];
        }
    }
    memset(visited, false, sizeof(visited)); // Khởi tạo mảng visited cho DFS
}

void DFS(int u)
{
    visited[u] = true;           // Đánh dấu đỉnh u đã được thăm
    for (int v = 1; v <= n; ++v) // Duyệt qua tất cả các đỉnh kề của u
    {
        if (ke[u][v] && !visited[v]) // Nếu có cạnh nối từ u đến v và v chưa được thăm
        {
            DFS(v); // Tiến hành DFS từ v
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
            DFS(i); // Bắt đầu DFS từ mỗi đỉnh chưa được thăm
        }
    }
    return dem;
}

void check(int s, int t)
{
    memset(visited, false, sizeof(visited));
    DFS(s); // Bắt đầu DFS từ đỉnh s
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
        cout << tplt() << endl; // In ra số lượng thành phần liên thông
    }
    return 0;
}