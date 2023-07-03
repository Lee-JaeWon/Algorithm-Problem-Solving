// 입력
// 첫째 줄에 정점의 수 N (5 ≤ N ≤ 100,000), 간선의 수 M (1 ≤ M ≤ 200,000), 시작 정점 R (1 ≤ R ≤ N)이 주어진다.
// 다음 M개 줄에 간선 정보 u v가 주어지며 정점 u와 정점 v의 가중치 1인 양방향 간선을 나타낸다. (1 ≤ u < v ≤ N, u ≠ v) 모든 간선의 (u, v) 쌍의 값은 서로 다르다.

// 출력
// 첫째 줄부터 N개의 줄에 정수를 한 개씩 출력한다. i번째 줄에는 정점 i의 방문 순서를 출력한다. 시작 정점의 방문 순서는 1이다. 시작 정점에서 방문할 수 없는 경우 0을 출력한다.

#include <iostream>
#include <vector>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int visited[100000] = {
    0,
};
int cnt = 1;

void dfs(size_t R, const std::vector<std::vector<int>> &vec)
{
    visited[R] = cnt; // 시작 정점 R을 방문 했다고 표시한다.
    cnt++;
    for (int i = 0; i < vec[R].size(); i++)
    {
        // std::cout << vec[R][i] << "\n";
        if (visited[vec[R][i]] == 0)
        {
            dfs(vec[R][i], vec);
        }
    }
}

int main(int argc, char **argv)
{
    fastio;

    size_t N, M, R;
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

    for (int i = 1; i <= N; i++)
    {
        std::sort(vec[i].begin(), vec[i].end(), std::greater<int>()); // 내림차순
    }

    dfs(R, vec);

    for (int i = 1; i <= N; i++)
    {
        std::cout << visited[i] << "\n";
    }

    return 0;
}