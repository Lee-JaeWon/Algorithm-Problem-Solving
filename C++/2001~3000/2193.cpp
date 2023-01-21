#include <iostream>

int main(void)
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    long long arr[N + 1] = {
        0,
    };
    arr[1] = 1;
    arr[2] = 1;

    for (int i = 3; i <= N; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    std::cout << arr[N];

    return 0;
}