#include <iostream>
#include <vector>
#include <queue>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

#define Arr_SIZE 100001

int visited[Arr_SIZE] = {
    0,
};

void bfs(const std::vector<std::vector<int>> &vec, const int R)
{
    std::fill_n(visited, Arr_SIZE, -1); // -1 초기화
    visited[R] = 0;                     // 방문 표시

    std::queue<int> Q;
    Q.push(R);

    while (!Q.empty())
    {
        // 요소 삭제하기
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < vec[u].size(); i++)
        {
            int neigh = vec[u][i];
            if (visited[neigh] == -1)
            {
                visited[neigh] = visited[u] + 1;
                Q.push(neigh);
            }
        }
    }
}

int main(int argc, char **argv)
{
    fastio;

    int N, M, R;
    std::cin >> N >> M >> R;

    std::vector<std::vector<int>> vec;
    vec.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        std::cin >> a >> b;

        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    bfs(vec, R);

    for (int i = 1; i <= N; i++)
    {
        std::cout << visited[i] << "\n";
    }

    return 0;
}