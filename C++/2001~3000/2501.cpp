#include <iostream>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int solve(int N, int K)
{
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            K--;
            if (K == 0)
            {
                return i;
            }
        }
    }
    return 0;
}

int main(void)
{
    fastio;

    int N, K;
    std::cin >> N >> K;

    int ans;
    ans = solve(N, K);

    std::cout << ans;
    return 0;
}