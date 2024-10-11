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
        cout << i.first << ' ' << i.second << endl;
    }
}