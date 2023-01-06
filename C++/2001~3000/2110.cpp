#include <iostream>
#include <vector>
#include <algorithm>

// 입력
// 첫째 줄에 집의 개수 N (2 ≤ N ≤ 200,000)과
// 공유기의 개수 C (2 ≤ C ≤ N)이 하나 이상의 빈 칸을 사이에 두고 주어진다.
// 둘째 줄부터 N개의 줄에는 집의 좌표를 나타내는 xi (0 ≤ xi ≤ 1,000,000,000)가 한 줄에 하나씩 주어진다.

// 핵심
// 가장 인접한 공유기의 거리가 가장 커야한다. -> 검사하다 작은게 있으면 끝

int main(void)
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long N = 2, C = 2;
    std::cin >> N >> C;

    std::vector<long long> vec;
    long long temp;
    for (int i = 0; i < N; i++)
    {
        std::cin >> temp;
        vec.push_back(temp);
    }

    std::sort(vec.begin(), vec.end());

    long long left = 0;
    long long right = vec[N - 1] - 1;

    long long mid = 0;
    long long start = 0;
    long long N_router = 0;
    long long result = 0;
    while (left <= right)
    {
        start = vec[0];
        N_router = 1;

        mid = (left + right) / 2;

        for (int idx = 1; idx < N; idx++)
        {
            if (vec[idx] - start >= mid)
            {
                start = vec[idx];
                N_router++;
            }
        }

        if (N_router >= C)
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    std::cout << result;

    return 0;
}