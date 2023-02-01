#include <iostream>
#include <vector>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int main(void)
{
    fastio;

    int A, B;
    std::cin >> A >> B;

    std::vector<int> vec;
    for (int i = 1; i <= B; i++)
    {
        for (int j = 0; j < i; j++)
        {
            vec.push_back(i);
        }
    }

    int sum = 0;
    for (int i = A - 1; i < B; i++)
    {
        sum += vec[i];
    }
    std::cout << sum;

    return 0;
}