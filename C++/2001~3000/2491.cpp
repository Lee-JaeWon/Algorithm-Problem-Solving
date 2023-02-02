// 초기 계획
// 구현 문제 -> 같거나 클때 추가해나갈 변수 하나와 작거나 같을때 추가해나갈 변수를 다루기
// 두 변수 중 가장 큰것

#include <iostream>
#include <vector>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int main(void)
{
    fastio;

    int N;
    std::cin >> N;

    int temp;
    std::cin >> temp; // 0번째 입력 먼저 받기

    int vec[N] = {0};
    vec[0] = temp;

    int upper = 1;
    int lower = 1;
    int result = 1;
    for (int i = 1; i < N; i++) // 1번째 입력부터
    {
        std::cin >> temp;
        vec[i] = temp;
        if (vec[i - 1] > temp)
        {
            lower++;
            upper = 1;
            if (lower > result)
            {
                result = lower;
            }
        }
        else if (vec[i - 1] < temp)
        {
            upper++;
            lower = 1;
            if (upper > result)
            {
                result = upper;
            }
        }
        else // 같은 경우?
        {
            lower++;
            upper++;
            int max = std::max(upper, lower);
            if (max > result)
            {
                result = max;
            }
        }
    }
    std::cout << result;

    return 0;
}