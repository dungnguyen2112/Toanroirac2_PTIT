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

vector<vector<int>> ke;
vector<bool> visited;

void DFS1(int u)
{
    cout << u << ' ';
    visited[u] = true;
    for (int v : ke[u])
    {
        if (!visited[v])
        {
            DFS1(v);
        }
    }
}

void DFS2(int u)
{
    visited[u] = true;
    stack<int> s;
    s.push(u);
    cout << u << ' ';
    while (!s.empty())
    {
        int v = s.top();
        s.pop();
        for (int i : ke[v])
        {
            if (!visited[i])
            {
                visited[i] = true;
                cout << i << ' ';
                s.push(v);
                s.push(i);
                break;
            }
        }
    }
}

int main()
{
    int n; // số đỉnh của đồ thị
    cin >> n;
    ke.resize(n + 1);
    visited.resize(n + 1, false);
    cin.ignore();
    for (int i = 1; i <= n; ++i)
    {
        string s;
        getline(cin, s);
        string tmp;
        stringstream ss(s);
        while (ss >> tmp)
        {
            ke[i].push_back(stoi(tmp));
        }
    }

    DFS1(1);
    cout << endl;
    visited.assign(n + 1, false);
    DFS2(1);
    cout << endl;

    return 0;
}