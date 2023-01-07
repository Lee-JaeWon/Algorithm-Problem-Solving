#include <iostream>
#include <vector>

int main(void)
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    long long K;

    std::cin >> N >> K;

    std::vector<long long> vec;
    long long temp;
    for (int i = 0; i < N; i++)
    {
        std::cin >> temp;
        vec.push_back(temp);
    }

    int result = 0;
    int num, candi;
    int answer = 0;
    while (K != 0)
    {
        for (int i = 0; i < N; i++)
        {
            num = K / int(vec[i]);
            if (num != 0)
            {
                candi = num;
                result = candi*int(vec[i]); // result = 4 * 1000
            }
        }
        answer += candi;
        K -= result;
    }
    std::cout << answer;

    return 0;
}