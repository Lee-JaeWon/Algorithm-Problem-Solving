// 모든 테스트 케이스를 검사
// 이분 탐색?

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    int W, N;
    std::cin >> W >> N;

    int gold, price;
    std::pair<int, int> v[N];

    for (int i = 0; i < N; i++)
    {
        std::cin >> gold >> price;
        v[i] = {price, gold};
    }

    std::sort(v, v + N, greater<>());

    int result = 0;
    for (int i = 0; i<N, W> 0; i++)
    {
        int k = min(v[i].second, W);
        W -= k;
        result += k * v[i].first;
    }

    std::cout << result;

    return 0;
}