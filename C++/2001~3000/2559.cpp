// 누적합 -> DP?

#include <iostream>

int main()
{
    long long N;
    long long K;
    std::cin >> N;
    std::cin >> K;

    long long num;
    long long sum[N + 1] = {
        0,
    };
    for (int i = 1; i <= N; i++)
    {
        std::cin >> num;
        sum[i] = sum[i - 1] + num; // sum[1] 부터 데이터 존재
    }

    long long temp = 0;
    long long result = -1000000;
    for (int i = K; i <= N; i++)
    {
        temp = sum[i] - sum[i - K];
        if (temp > result)
        {
            result = temp;
        }
    }
    std::cout << result;

    return 0;
}