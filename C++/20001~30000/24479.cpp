#include <iostream>
#include <vector>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int visited[100001] = {
    0,
};
std::vector<std::vector<int>> graph;
int cnt = 0;

void dfs(int x)
{
    if (visited[x] != 0)
    {
        return;
    }
    cnt++;
    visited[x] = cnt; // 방문

    for (int i = 0; i < graph[x].size(); i++)
    {
        dfs(graph[x][i]);
    }
}

int main(void)
{
    fastio;

    int N, M, R;
    std::cin >> N >> M >> R;

    graph.resize(N + 1);

    int u, v;
    for (int i = 0; i < M; i++)
    {
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i < N; i++)
    {
        std::sort(graph[i].begin(), graph[i].end());
    }

    dfs(R);

    for (int i = 1; i <= N; i++)
    {
        std::cout << visited[i] << "\n";
    }

    return 0;
}