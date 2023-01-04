#include <iostream>

bool prime_num(long long num);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long N, M;
    std::cin >> N >> M;

    for (int i = N; i <= M; i++)
    {
        if (prime_num(i))
        {
            std::cout << i << "\n";
        }
    }

    return 0;
}

bool prime_num(long long num)
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}