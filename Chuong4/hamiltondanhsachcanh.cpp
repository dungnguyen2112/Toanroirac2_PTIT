#include <bits/stdc++.h>
#define faster()                           \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL);
using namespace std;

const int MAXN = 105;
int a[MAXN][MAXN], b[MAXN], n, m;
bool visited[MAXN];
vector<int> ke[MAXN];
void hamilton(int u)
{
    for (auto i : ke[u - 1])
    {
        if (u == n + 1 && i == b[1])
        {
            for (int j = 1; j <= n; ++j)
                cout << b[j] << ' ';
            cout << b[1] << endl;
            return;
        }
        else if (!visited[i])
        {
            visited[i] = true;
            b[u] = i;
            hamilton(u + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    faster();
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    b[1] = 1;
    visited[1] = true;
    hamilton(2);
    return 0;
}