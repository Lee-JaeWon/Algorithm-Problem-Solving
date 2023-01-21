#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

std::vector<std::vector<int>> graph;
std::vector<int> visited;
int cnt = 0;

void DFS(int n)
{
    std::queue<int> que;
    que.push(n);

    cnt++;
    visited[n] = cnt; // 방문

    int u, graphsize;
    while (que.size() != 0)
    {
        u = que.front();
        que.pop();
        graphsize = graph[u].size();

        for (int i = 0; i < graphsize; i++)
        {
            if (visited[graph[u][i]] == 0) // 방문하지 않았다면
            {
                cnt++;
                visited[graph[u][i]] = cnt;
                que.push(graph[u][i]);
            }
        }
    }
}

int main(void)
{
    fastio;

    int N, M, R;
    std::cin >> N >> M >> R;

    graph.resize(N + 1);
    visited.resize(N + 1);

    int u, v;
    for (int i = 0; i < M; i++)
    {
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= N; i++)
    {
        std::sort(graph[i].begin(), graph[i].end());
    }

    DFS(R);

    for (int i = 1; i <= N; i++)
    {
        std::cout << visited[i] << "\n";
    }

    return 0;
}