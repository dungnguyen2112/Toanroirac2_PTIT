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
int a[105][105], n;
void eulervohuong(int u)
{
    stack<int> s;
    vector<int> v;
    s.push(u);
    while (s.size())
    {
        int t = s.top(), kt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[t][i])
            {
                kt = 1;
                a[t][i] = a[i][t] = 0;
                s.push(i);
                break;
            }
        }
        if (kt == 0)
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
        int t = s.top(), kt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[t][i])
            {
                kt = 1;
                a[t][i] = 0;
                s.push(i);
                break;
            }
        }
        if (kt == 0)
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
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    euler(1);
}