// DFS일듯

#include <iostream>
#include <vector>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int visited[1001] = {
    0,
};
std::vector<std::vector<int>> vec;

void dfs(int start)
{
    visited[start] = true;
    // std::cout << start << "\n";
    for (int i = 0; i < vec[start].size(); i++)
    {
        int next = vec[start][i];
        if (visited[next] == 0)
        {
            dfs(next);
        }
    }
}

int main(int argc, char **argv)
{
    fastio;

    int N, M;
    std::cin >> N >> M;

    vec.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        std::cin >> u >> v;
        // 양방향
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        std::sort(vec[i].begin(), vec[i].end());
    }

    int start;
    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 0)
        {
            start = i;
            dfs(start);
            result++;
        }
    }

    std::cout << result;

    return 0;
}