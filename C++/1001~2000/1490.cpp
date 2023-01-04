#include <iostream>
#include <string>
#include <cmath>
#include <vector>

size_t countDigits(long long N)
{
    std::string tmp;

    tmp = std::to_string(N);
    return tmp.size();
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    // 입력
    long long N;
    std::cin >> N;

    // 각 자리수 저장
    long long num = N;
    std::vector<int> vec;
    int len = countDigits(N);
    for (int i = 0; i < len; i++)
    {
        vec.push_back((int(num % 10)));
        num /= 10;
    }

    long long tmp = 0;
    bool flag = true;
    int up_n = 0;
    int plus = 0;
    int nPow;

    while (flag)
    {
        flag = false;
        nPow = (int)(pow(10, up_n));

        // 10의 n제곱 배
        tmp = N * (long long)nPow + (long long)plus;
        // std::cout << tmp << std::endl;
        for (int i = 0; i < len; i++)
        {
            if (vec[i] != 0)
            {
                if (tmp % (long long)(vec[i]) != 0)
                {
                    flag = true;
                }
            }
        }

        // 1씩 더하기
        plus++;
        if (plus == nPow)
        {
            plus = 0;
            up_n++;
        }
    }

    std::cout << tmp;
    return 0;
}
