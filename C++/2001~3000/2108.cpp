#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> vec;

    int temp;
    int total = 0;
    int arr[8001] = {
        0,
    };
    int index = 0;
    int max_idx = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> temp;
        vec.push_back(temp);
        total += temp;

        if (temp <= 0)
        {
            index = -temp;
        } // like counting sort
        else
        {
            index = 4000 + temp;
        }

        arr[index]++;

        if (arr[index] > max_idx)
        {
            max_idx = arr[index];
        }
    }

    // 정렬
    std::sort(vec.begin(), vec.end());

    // 차이
    int diff = vec[vec.size() - 1] - vec[0];

    // 최빈값
    int result = 0;
    bool flag = false;
    for (int i = -4000; i < 4001; i++)
    {
        if (i <= 0)
        {
            index = -i;
        }
        else
        {
            index = i + 4000;
        }

        if (arr[index] == max_idx)
        {
            result = i;

            if (flag)
            {
                break;
            }
            flag = true;
        }
    }

    int avg = round(double(total) / N);
    if(avg == -0){
        avg =0;
    }

    std::cout << avg << "\n"
              << vec[vec.size() / 2] << "\n"
              << result << "\n"
              << diff;

    return 0;
}