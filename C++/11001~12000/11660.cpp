#include <iostream>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int main(void)
{
    fastio;

    int N, M;
    std::cin >> N >> M;

    int array[N + 1][N + 1];
    int sum[N + 1][N + 1] = {

    };
    int Nsum = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            std::cin >> array[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + array[i][j];
        }
    }

    int x1, x2, y1, y2;
    for (int i = 0; i < M; i++)
    {
        std::cin >> x1 >> y1 >> x2 >> y2;

        std::cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << "\n";
    }

    return 0;
}