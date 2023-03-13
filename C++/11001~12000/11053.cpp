// LIS 문제
// O(n^2) 풀이로

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int main(int argc, char **argv)
{
    fastio;

    int N;
    std::cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }

    int length[N];
    length[0] = 1;
    for (int i = 1; i < N; i++)
    {
        length[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                length[i] = std::max(length[i], length[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (ans < length[i])
        {
            ans = length[i];
        }
    }
    std::cout << ans;

    return 0;
}