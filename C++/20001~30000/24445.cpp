//  i번째 줄에는 정점 i의 방문 순서를 출력한다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

std::vector<std::vector<int>> vec;

int visited[100001] = {
    0,
};
int result[100001] = {
    0,
};
int cnt = 0;

void bfs(int R)
{
    visited[R] = 1;
    std::queue<int> Q;
    Q.push(R);
    while (!Q.empty())
    {
        int temp = Q.front();

        cnt++;
        result[temp] = cnt;

        Q.pop();
        int size = vec[temp].size();
        for (int i = 0; i < size; i++)
        {
            int v = vec[temp][i];
            if (visited[v] != 1)
            {
                visited[v] = 1;
                Q.push(v);
            }
        }
    }
}

int main(int argc, char **argv)
{
    fastio;

    int N, M, R;
    std::cin >> N >> M >> R;

    vec.resize(N + 1);

    int u, v;
    for (int i = 0; i < M; i++)
    {
        std::cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for (int i = 0; i < vec.size(); i++)
    {
        std::sort(vec[i].begin(), vec[i].end(), std::greater<int>());
    }

    bfs(R);

    for (int i = 1; i <= N; i++)
    {
        std::cout << result[i] << "\n";
    }

    return 0;
}