#include <iostream>
#include <vector>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

#define N 3

int main(void)
{

    fastio;

    int T;
    std::cin >> T;

    int temp;
    std::vector<int> vec;
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cin >> temp;

            vec.push_back(temp);
        }
        std::sort(vec.begin(), vec.end(), std::greater<int>());

        std::cout << vec[N - 1] << "\n";
        vec.clear();
    }

    return 0;
}