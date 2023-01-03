// 누적합 : DP 문제

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long N, M;
    std::cin >> N >> M;
    long num;
    long long sum[N + 1] = {
        0,
    };
    for (int i = 1; i <= N; i++)
    {
        std::cin >> num;
        sum[i] = sum[i - 1] + num; // 첫번째가 sum[1]에 저장
    }

    long long s, e;
    for (int i = 0; i < M; i++)
    {
        std::cin >> s >> e;
        std::cout << sum[e] - sum[s - 1] << "\n"; // 2 4 이면 0~4 - 0~1
    }

    return 0;
}