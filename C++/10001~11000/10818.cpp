#include <iostream>
#include <vector>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cin.tie(NULL)

int main(void)
{
    fastio;

    int N;
    std::cin >> N;

    int num;
    std::vector<int> vec;
    for (int i = 0; i < N; i++)
    {
        std::cin >> num;
        vec.push_back(num);
    }

    std::cout << *std::min_element(vec.begin(), vec.end()) << " " << *std::max_element(vec.begin(), vec.end());

    return 0;
}