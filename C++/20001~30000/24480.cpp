#include <iostream>
#include <vector>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

std::vector<std::vector<int>> vec;
int visited[100001] = {
    0,
};
int cnt = 0;

void dfs(int R)
{
    // std::cout << R << "\n";
    if (visited[R] != 0)
    {
        return;
    }

    cnt++;
    visited[R] = cnt;
    for (int i = 0; i < vec[R].size(); i++)
    {
        dfs(vec[R][i]);
    }
}

int main(int argc, char **argv)
{
    fastio;

    int N, M, R;
    std::cin >> N >> M >> R;

    vec.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        std::cin >> a >> b;

        // 양방향 간선
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        std::sort(vec[i].begin(), vec[i].end(), std::greater<int>());
    }

    dfs(R);

    for (int i = 1; i <= N; i++)
    {
        std::cout << visited[i] << "\n";
    }

    return 0;
}