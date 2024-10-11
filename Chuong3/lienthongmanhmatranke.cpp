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

const int MAX = 1005;
int n, m;
int ke[MAX][MAX];
bool visited[MAX];

void nhap()
{
    cin >> n;
    memset(ke, 0, sizeof(ke)); // Khởi tạo ma trận kề với giá trị 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u)
{
    visited[u] = true;
    for (int v = 1; v <= n; v++)
    {
        if (ke[u][v] && !visited[v])
        { // Nếu có cạnh từ u đến v và v chưa được thăm
            DFS(v);
        }
    }
}

bool isConnected()
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            return false; // Nếu tồn tại một đỉnh chưa được thăm, không phải là connected graph
        }
    }
    return true;
}

int main()
{
    faster() int x;
    cin >> x;
    while (x--)
    {
        nhap();
        memset(visited, false, sizeof(visited));

        int dem = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                DFS(i);
                dem++;
            }
        }

        if (dem == 1 && isConnected())
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}
