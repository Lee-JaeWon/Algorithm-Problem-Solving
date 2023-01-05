#include <iostream>
#include <algorithm>

int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int H, W;
    std::cin >> H >> W;

    int arr[W] = {
        0,
    };

    for (int i = 0; i < W; i++)
    {
        std::cin >> arr[i];
    }

    int ans = 0;
    for (int i = 1; i < W - 1; i++)
    {
        int left = 0;
        int right = 0;

        for (int j = 0; j < i; j++) // 0부터 i전까지 최대 검사
        {
            left = std::max(left, arr[j]);
        }
        for (int k = W - 1; k > i; k--) // 끝부터 i+1까지 최대 검사
        {
            right = std::max(right, arr[k]);
        }
        ans += std::max(0, std::min(left, right) - arr[i]);
    }
    std::cout << ans;

    return 0;
}