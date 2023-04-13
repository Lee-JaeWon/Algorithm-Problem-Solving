#include <iostream>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int main(int argc, char **argv)
{
    fastio;

    int K, N;
    std::cin >> K >> N;

    unsigned int maximum = 0;

    unsigned int arr[K];

    for (int i = 0; i < K; i++)
    {
        std::cin >> arr[i];
        maximum = std::max(maximum, arr[i]);
    }

    unsigned int left = 1, right = maximum, mid;
    unsigned int result = 0;

    while (left <= right)
    {
        mid = (left + right) / 2;

        unsigned int now = 0;

        for (int i = 0; i < K; i++)
        {
            now += arr[i] / mid;
            // std::cout << now << "\n";
        }

        if (now >= N) // 더 크게 자를 수 있는지
        {
            left = mid + 1;
            result = std::max(result, mid);
        }
        else // 더 잘게 잘라야함
        {
            right = mid - 1; // right 길이 씩 자르기
        }
    }

    std::cout << result;

    return 0;
}