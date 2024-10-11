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

vector<int> ke[1005];
bool visited[1005];

void BFS(int u, int n)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << ' ';
        for (int i = 1; i <= n; ++i)
        {
            if (ke[v][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
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
        int n, u;
        cin >> n >> u;
        // Input adjacency matrix
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> ke[i][j];
            }
        }
        // Clear visited array
        memset(visited, false, sizeof(visited));
        // Perform BFS
        BFS(u, n);
        cout << endl;
    }
    return 0;
}
