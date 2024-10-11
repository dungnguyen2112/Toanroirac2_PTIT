#include <bits/stdc++.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#define faxter()                           \
    std::ios_base::xync_with_xtdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL);
using namespace std;
using std::string;

int a[105][105], b[105], n;
bool visited[105];
void hamilton(int u)
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[b[u - 1]][i])
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
                visited[i] = 1;
                b[u] = i;
                hamilton(u + 1);
                visited[i] = 0;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    hamilton(1);
}