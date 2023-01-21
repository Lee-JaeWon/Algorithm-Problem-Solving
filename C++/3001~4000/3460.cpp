#include <iostream>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

void binary(long long n)
{
    int temp = n;
    int cnt = 0;
    while (temp != 0)
    {
        if (temp % 2 == 1)
        {
            std::cout << cnt << " ";
        }
        cnt++;
        temp /= 2;
    }
    std::cout << "\n";
}

int main(void)
{
    fastio;

    int T;
    long long n;
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        std::cin >> n;
        binary(n);
    }

    return 0;
}