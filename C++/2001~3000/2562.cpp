#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int N = 9;
    std::vector<int> vec;
    int temp;
    for (int i = 0; i < N; i++)
    {
        std::cin >> temp;
        vec.push_back(temp);
    }
    int max_index = std::max_element(vec.begin(), vec.end()) - vec.begin();
    int max = *std::max_element(vec.begin(), vec.end());

    std::cout << max << "\n"
              << max_index + 1;

    return 0;
}