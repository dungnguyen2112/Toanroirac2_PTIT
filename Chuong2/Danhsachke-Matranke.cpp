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
vector<pair<int, int>> res;    
int a[1005][1005];
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        string tmp;
        stringstream ss(s);
        while (ss >> tmp)
        {
            if (stoi(tmp) > i)
            {
                res.push_back({i, stoi(tmp)});
            }
        }
    }
    sort(res.begin(), res.end());

    for (auto i : res)
    {
        a[i.first][i.second] = 1;
        a[i.second][i.first] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}