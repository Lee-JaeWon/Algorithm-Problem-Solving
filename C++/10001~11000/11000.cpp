#include <iostream>
#include <queue>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int main(int argc, char **argv)
{
    fastio;

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> vec;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        vec.push_back(std::make_pair(a, b));
    }

    // 오름차순 정렬
    std::sort(vec.begin(), vec.end());

    // 작은값이 top으로
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    pq.push(vec[0].second);

    for(int i = 1; i < N; i++)
    {
        if(pq.top() <= vec[i].first) // 1,3(pq)  3,5 일때 
        {
            pq.pop();
            pq.push(vec[i].second);
        }
        else
        {
            pq.push(vec[i].second);
        }
    }

    std::cout << pq.size();

    return 0;
}