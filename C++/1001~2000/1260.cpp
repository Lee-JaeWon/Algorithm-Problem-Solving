#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(int start, vector<vector<int>> v, bool check[]) {
    if (check[start] == true) {
        return;
    }
    check[start] = true;
    cout << start << " ";

    for (int i = 0; i < v[start].size(); i++) {
        int next = v[start][i];

        if (!(check[next]))
            dfs(next, v, check);
    }
}
void bfs(int start, vector<vector<int>> v, bool check[]) {
    queue<int> q;

    q.push(start);
    check[start] = true;

    while (!q.empty()) {
        int res = q.front();
        q.pop();
        cout << res << " ";

        for (int i = 0; i < v[res].size(); i++) {
            if (check[v[res][i]] == false) {
                q.push(v[res][i]);
                check[v[res][i]] = true;
            }
        }
    }
}

int main() {

    int n, m, start;
    cin >> n >> m >> start;

    //2차원 배열 vector 선언
    vector<vector<int>> v(n + 1);
    bool* check = new bool[n + 1];
    fill_n(check, n + 1, false);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    //sort
	for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
 
    //dfs
    dfs(start, v, check);
    fill_n(check, n + 1, false); //방문 초기화
    cout << endl;
    //bfs
    bfs(start, v, check);

    delete[] check;
}
