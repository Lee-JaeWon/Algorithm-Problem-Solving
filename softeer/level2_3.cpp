// DFS 문제
// 백준 유기농 배추 문제와 흡사

#include <iostream>
#include <string>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int main(int argc, char **argv)
{
    fastio;

    // road size input
    int N;
    std::cin >> N;

    // road data
    int road[N][N];

    // road input
    std::string str;
    for (int i = 0; i < N; i++)
    {
        std::cin >> str;
        for (int j = 0; j < N; j++)
        {
            road[i][j] = str[j] - '0';
        }
    }

    // DFS
    int x_dir[4] = {-1, 1, 0, 0}; // 상화 좌우 x축 방향
    int y_dir[4] = {0, 0, -1, 1}; // 상화 좌우 y축 방향

    int visited[N][N];
    memset(visited, 0, sizeof(visited));

    std::vector<int> vec;
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] != 1 && road[i][j] == 1) // 방문하지 않았고, 도로이면,
            {
                std::queue<std::pair<int, int>> dfs_queue;
                visited[i][j] = 1; // 방문체크
                dfs_queue.push(std::make_pair(i, j));
                vec.push_back(0);
                while (!dfs_queue.empty())
                {
                    int nx = dfs_queue.front().first;
                    int ny = dfs_queue.front().second;

                    dfs_queue.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int nx_new = nx + x_dir[k];
                        int ny_new = ny + y_dir[k];
                        if ((0 <= nx_new && nx_new < N) && (0 <= ny_new && ny_new < N) && visited[nx_new][ny_new] == 0 && road[nx_new][ny_new] == 1)
                        {
                            visited[nx_new][ny_new] = 1;
                            dfs_queue.push(std::make_pair(nx_new, ny_new));
                            vec[cnt]++;
                        }
                    }
                }
                cnt++;
            }
        }
    }

    std::sort(vec.begin(), vec.end());

    // for check
    std::cout << cnt << "\n";
    for (int i = 0; i < cnt; i++)
    {
        std::cout << vec[i] + 1 << "\n";
    }

    return 0;
}