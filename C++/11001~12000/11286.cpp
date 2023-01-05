#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

// Queue -> FIFO
// 11286 -> Priority Queue

struct compare
{
    bool operator()(int a, int b)
    {
        if (std::abs(a) == std::abs(b))
        {
            return a > b;
        }
        else
        {
            return std::abs(a) > std::abs(b);
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long N;
    std::cin >> N;

    std::priority_queue<int, std::vector<int>, compare> pq;

    long long temp;
    for (int i = 0; i < N; i++)
    {
        std::cin >> temp;
        if (temp != 0)
        {
            pq.push(temp);
        }
        else if (temp == 0)
        {
            if (pq.empty())
            {
                std::cout << "0"
                          << "\n";
            }
            else
            {
                std::cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}