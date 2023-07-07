#include <iostream>
#include <vector>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int main(int argc, char **argv)
{
    fastio;

    // 상근이 숫자 카드 입력
    int N;
    std::cin >> N;
    std::vector<int> sang;
    int in;
    for (int i = 0; i < N; i++)
    {
        std::cin >> in;
        sang.push_back(in);
    }

    // 비교할 것 입력
    int M;
    std::cin >> M;
    std::vector<int> comp;
    for (int i = 0; i < M; i++)
    {
        std::cin >> in;
        comp.push_back(in);
    }

    // 정렬
    std::sort(sang.begin(), sang.end());

    // 이분 탐색
    for (int i = 0; i < comp.size(); i++)
    {
        int start = 0;   // index
        int end = N - 1; // index
        int mid = 0;
        int temp_res = 0;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            temp_res = sang[mid];
            if (sang[mid] == comp[i])
            {
                break;
            }
            if (sang[mid] < comp[i])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        if (temp_res == comp[i])
        {
            std::cout << "1 ";
        }
        else
        {
            std::cout << "0 ";
        }
    }

    return 0;
}