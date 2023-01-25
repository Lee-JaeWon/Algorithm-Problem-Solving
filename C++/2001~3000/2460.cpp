#include <iostream>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int main(void)
{
    fastio;

    int max = 0;
    int n, s, sum = 0;
    for (int i = 0; i < 10; i++)
    {
        std::cin >> n >> s;

        sum -= n;
        sum += s;
        if (sum > max)
        {
            max = sum;
        }
    }

    std::cout << max;

    return 0;
}