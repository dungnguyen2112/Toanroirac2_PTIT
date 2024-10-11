#include <iostream>
#include <vector>
#include <cstring>

#define faster()                           \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL);

using namespace std;

const int MAX = 1005;
int n, m;
bool ke[MAX][MAX];
bool visited[MAX];

void nhap()
{
    cin >> n;
    memset(ke, false, sizeof(ke)); // Khởi tạo ma trận kề với giá trị false
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ke[i][j];
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
        { // Nếu có cạnh giữa u và v và v chưa được thăm
            DFS(v);
        }
    }
}

int countComponents()
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i);
            count++;
        }
    }
    return count;
}

void check()
{
    int count = countComponents();
    for (int i = 1; i <= n; i++)
    {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        if (count < countComponents())
        {
            cout << i << ' ';
        }
    }
    cout << endl;
}

int main()
{
    faster() int x;
    cin >> x;
    while (x--)
    {
        nhap();
        check();
    }
    return 0;
}
