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

vector<vector<int>> adj_matrix;
vector<bool> visited;

void DFS1(int u, int n) {
    cout << u << ' ';
    visited[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (adj_matrix[u][v] && !visited[v]) {
            DFS1(v, n);
        }
    }
}

void DFS2(int u, int n) {
    visited[u] = true;
    stack<int> s;
    s.push(u);
    cout << u << ' ';
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        for (int i = 1; i <= n; ++i) {
            if (adj_matrix[v][i] && !visited[i]) {
                visited[i] = true;
                cout << i << ' ';
                s.push(v);
                s.push(i);
                break;
            }
        }
    }
}

int main() {
    int n; // số đỉnh của đồ thị
    // Đọc số đỉnh của đồ thị
    cin >> n;
    // Khởi tạo ma trận kề và visited
    adj_matrix.resize(n + 1, vector<int>(n + 1, 0));
    visited.resize(n + 1, false);
    
    // Đọc ma trận kề
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> adj_matrix[i][j];
        }
    }

    // Gọi DFS1 từ đỉnh 1
    cout << "DFS1: ";
    DFS1(1, n);
    cout << endl;

    // Đặt lại visited để sử dụng cho DFS2
    visited.assign(n + 1, false);

    // Gọi DFS2 từ đỉnh 1
    cout << "DFS2: ";
    DFS2(1, n);
    cout << endl;

    return 0;
}