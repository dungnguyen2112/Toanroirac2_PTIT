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
int a[105][105], n, m;
vector<vector<int>> ke;
bool visited[105];
void eulervohuong(int u)
{
    stack<int> s;
    vector<int> v;
    s.push(u);
    while (s.size())
    {
        int t = s.top(), check = 0;
        for (int i = 0; i < ke[t].size(); ++i)
        {
            int b = ke[t][i];
            if (b != -1)
            {
                check = 1;
                ke[t][i] = ke[b][i] = -1;
                s.push(b);
                break;
            }
        }
        if (!check)
        {
            v.push_back(t);
            s.pop();
        }
    }
    reverse(v.begin(), v.end());
    for (int i : v)
        cout << i << " ";
}

void eulercohuong(int u)
{
    stack<int> s;
    vector<int> v;
    s.push(u);
    while (s.size())
    {
        int t = s.top(), check = 0;
        for (int i = 0; i < ke[t].size(); ++i)
        {
            int b = ke[t][i];
            if (b != -1)
            {
                check = 1;
                ke[t][i] = -1;
                s.push(b);
                break;
            }
        }
        if (!check)
        {
            v.push_back(t);
            s.pop();
        }
    }
    reverse(v.begin(), v.end());
    for (int i : v)
        cout << i << " ";
}

int main()
{
    cin >> n;
    ke.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while (ss >> tmp)
        {
            ke[i].push_back(stoi(tmp));
        }
    }
    memset(visited, false, sizeof(visited));
    euler(1);
}