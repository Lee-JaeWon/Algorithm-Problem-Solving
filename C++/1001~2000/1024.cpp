#include <iostream>
#include <cctype>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int main(void)
{
    fastio;

    long double N;
    long double L;

    std::cin >> N >> L;

    bool flag = true;

    while (flag)
    {
        long double cons = 0;
        long double first_num = 0;
        for (int i = 1; i < L; i++)
        {
            cons += i;
        }
        first_num = (N - cons) / L;

        if (int(first_num) == first_num && first_num >= 0)
        {
            for (int i = 0; i < L; i++)
            {
                std::cout << int(first_num) + i << " ";
            }
            flag = false;
        }
        else
        {
            if (L == 100)
            {
                std::cout << "-1";
                flag = false;
            }
            else
            {
                L++;
            }
        }
    }

    return 0;
}