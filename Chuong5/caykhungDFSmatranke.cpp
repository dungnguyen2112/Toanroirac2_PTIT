#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

#define faster()                           \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL);

using namespace std;

bool visited[100005];
vector<vector<int>> ke;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    ke.resize(n + 1, vector<int>(n + 1, 0));
    vector<pair<int, int>> v;
    stack<int> st;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x][y] = ke[y][x] = 1; // Đánh dấu có cạnh giữa x và y
    }
    memset(visited, false, sizeof(visited));
    int dem1 = 0;
    bool check = true;
    st.push(k);
    visited[k] = true;
    while (st.size())
    {
        int u = st.top();
        st.pop();
        for (int i = 1; i <= n; i++)
        {
            if (ke[u][i] && !visited[i])
            {
                visited[i] = true;
                v.push_back({u, i});
                st.push(u);
                st.push(i);
                break;
            }
        }
    }
    if (v.size() == n - 1)
        for (auto i : v)
            cout << i.first << " " << i.second << endl;
    else
        cout << "-1" << endl;
    ke.clear();
}

int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        solve();
    }
}
