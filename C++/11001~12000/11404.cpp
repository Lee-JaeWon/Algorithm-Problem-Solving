#include <iostream>
#include <vector>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

#define MAX_CITY 101

#define INF 99999999

int main(int argc, char **argv)
{
    fastio;

    int n, m;
    std::cin >> n >> m;

    int arr[MAX_CITY][MAX_CITY];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = INF;
        }
    }

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b >> c;
        if (arr[a][b] > c)
            arr[a][b] = c;
    }

    for (int k = 1; k <= n; k++) // 거쳐가는 vertex
    {
        for (int a = 1; a <= n; a++) // Dab
        {
            for (int b = 1; b <= n; b++) // Dab
            {
                arr[a][b] = std::min(arr[a][b], arr[a][k] + arr[k][b]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || arr[i][j] == INF)
            {
                std::cout << 0 << " ";
            }
            else
            {
                std::cout << arr[i][j] << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}