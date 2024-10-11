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
vector<int> res[1005];
int a[1005][1005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                res[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto j : res[i])
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}