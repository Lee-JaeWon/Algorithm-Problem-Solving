// 접근 방법
// 모든 노드를 조사하며, 더 이상 조사되지 않을 때 지렁이 수++
// 모든 노드를 방문하는 것 -> DFS로 접근

// 해결해야할 문제
// 어떻게 주어진 입력이 인접한 노드인지 알 수 있는가

#include <iostream>
#include <string.h>
#include <queue>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int main(void)
{
    // fast i/o;
    fastio;

    // First Input
    int T;
    int M, N, K;
    std::cin >> T;

    // For Search
    int x_dir[4] = {-1, 1, 0, 0}; // 상화좌우 x축 방향
    int y_dir[4] = {0, 0, -1, 1}; // 상화좌우 y축 방향

    int result;
    for (int test_case = 0; test_case < T; test_case++)
    {
        // For result,
        int result = 0;

        // Input
        std::cin >> M >> N >> K;

        // coord Input
        int x, y;
        int ground[N][M]; // N 세로, M 가로
        int visited[N][M]; // 방문 기록

        // Init array
        memset(ground, 0, sizeof(ground));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < K; i++)
        {
            std::cin >> x >> y;
            ground[y][x] = 1;
        }

        // 전체 좌표에 대해 방문되지 않고 배추가 심어져있는 부분이 있다면 그 지점부터 DFS 시작.
        for (int P = 0; P < N; P++)
        {
            for (int L = 0; L < M; L++)
            {
                if (visited[P][L] != 1 && ground[P][L] != 0)
                {
                    std::queue<std::pair<int, int>> q;
                    visited[P][L] = 1;
                    q.push(std::make_pair(P, L));
                    while (!q.empty())
                    {
                        int nx = q.front().first;
                        int ny = q.front().second;

                        q.pop();

                        for (int j = 0; j < 4; j++)
                        {
                            int nx_new = nx + x_dir[j];
                            int ny_new = ny + y_dir[j];

                            if ((0 <= nx_new && nx_new < N) && (0 <= ny_new && ny_new < M) && !visited[nx_new][ny_new] && ground[nx_new][ny_new] == 1)
                            {
                                visited[nx_new][ny_new] = 1;
                                q.push(std::make_pair(nx_new, ny_new));
                            }
                        }
                    }
                    result++; // whlie 종료 시 모든 노드를 탐색한 것이기에, 지렁이++;
                }
            }
        }
        // Print
        std::cout << result << "\n";
    }

    // last
    return 0;
}