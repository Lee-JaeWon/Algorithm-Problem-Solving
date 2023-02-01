#include <iostream>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int main(void)
{
    fastio;

    int N;
    std::cin >> N;

    int seat[N] = {0};

    int input;
    for (int i = 0; i < N; i++)
    {
        std::cin >> input;
        for (int j = 0; j < N; j++)
        {
            if (input == 0 && seat[j] == 0)
            {
                seat[j] = i + 1;
                break;
            }
            else if (seat[j] == 0)
            {
                input--;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        std::cout << seat[i] << " ";
    }

    return 0;
}