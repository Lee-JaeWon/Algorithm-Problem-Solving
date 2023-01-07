#include <iostream>

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    int vec[10001] = {
        0,
    };

    int temp;
    for (int i = 0; i < N; i++)
    {
        std::cin >> temp;
        vec[temp]++;
    }

    for (int i = 0; i < 10001; i++)
    {
        for (int j = 0; j < vec[i]; j++)
        {
            std::cout << i << "\n";
        }
    }

    return 0;
}