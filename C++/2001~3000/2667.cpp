// bFS문제, 유기농 배추, 미로 탐색과 같이 비슷한 문제, 이 문제는 특히 유기농 배추와 유사, DFS 종료시 단지 수++
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int x_dir[4] = {-1, 1, 0, 0}; // 상화좌우 x축 방향
int y_dir[4] = {0, 0, -1, 1}; // 상화좌우 y축 방향

int visited[25][25] = {
    0,
}; // 방문 기록

int main(int argc, char **argv)
{
    fastio;

    int N;
    std::cin >> N;

    int arr[N][N];

    std::string temp;

    // 입력 형태가 숫자가 모두 붙어있는 형태이기에 std::cin으로 불가
    // std::string 이용
    for (int i = 0; i < N; i++)
    {
        std::cin >> temp;
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = temp[j] - '0';
        }
    }

    int result = 0;
    int temp_n;
    std::vector<int> home_num;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // 방문하지 않았으며, 집 존재시
            if (visited[i][j] == 0 && arr[i][j] == 1)
            {
                std::queue<std::pair<int, int>> Q;
                visited[i][j] = 1;
                Q.push(std::make_pair(i, j));
                temp_n = 1;
                while (!Q.empty())
                {
                    int dx = Q.front().first;
                    int dy = Q.front().second;

                    Q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int new_dx = dx + x_dir[k];
                        int new_dy = dy + y_dir[k];

                        if ((0 <= new_dx && new_dx < N) && (0 <= new_dy && new_dy < N) && (visited[new_dx][new_dy] == 0) && (arr[new_dx][new_dy] == 1))
                        {
                            visited[new_dx][new_dy] = 1;
                            Q.push(std::make_pair(new_dx, new_dy));
                            temp_n++;
                        }
                    }
                }
                result++;
                home_num.push_back(temp_n);
            }
        }
    }
    std::cout << result << "\n";

    std::sort(home_num.begin(), home_num.end());

    for (int i = 0; i < home_num.size(); i++)
    {
        std::cout << home_num[i] << "\n";
    }

    return 0;
}