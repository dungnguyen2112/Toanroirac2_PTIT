#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define faster()                           \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL);

using namespace std;

const int MAX = 1005;
int n, m, s, t;
int ke[MAX][MAX];
bool visited[MAX];
vector<pair<int, int>> res;

void nhap() {
    cin >> n;
    cin.ignore(); // Bỏ qua ký tự '\n' sau khi nhập số n
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ke[i][j]; // Đọc ma trận kề từ input
            if (ke[i][j] && i < j) {
                res.push_back({i, j}); // Lưu các cặp đỉnh có cạnh
            }
        }
    }
    memset(visited, false, sizeof(visited));
}

void BFS(int u) {
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        visited[v] = true;
        for (int i = 1; i <= n; i++) {
            if ((v == s && i == t) || (v == t && i == s))
                continue;
            if (ke[v][i] && !visited[i]) {
                q.push(i);
            }
        }
    }
}

int countComponents() {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            BFS(i);
            count++;
        }
    }
    return count;
}

void check() {
    int lthong = countComponents();
    int dem = lthong;
    for (pair<int, int> i : res) {
        s = i.first, t = i.second;
        memset(visited, false, sizeof(visited));
        if (dem < countComponents()) {
            cout << s << ' ' << t << ' ';
        }
    }
    cout << endl;
}

int main() {
    faster()
    int x;
    cin >> x;
    while (x--) {
        s = -1, t = -1;
        nhap();
        check();
        res.clear();
    }
    return 0;
}
