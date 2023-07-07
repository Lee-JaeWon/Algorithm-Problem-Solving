#include <iostream>
#include <vector>
#include <queue>

#define MAX_CITY 1001
#define INF_NUM 99999999

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int main(int argc, char **argv)
{
    fastio;

    // 도시 개수
    int N;
    std::cin >> N;

    // 버스 개수
    int M;
    std::cin >> M;

    //
    std::vector<std::pair<int, int>> Bus[MAX_CITY];
    int a, b, c;
    for (int i = 0; i < M; i++)
    {
        std::cin >> a >> b >> c;
        Bus[a].push_back(std::make_pair(b, c));
    }

    int start, dest;
    std::cin >> start >> dest;

    int dist[MAX_CITY];
    for (int i = 1; i <= N; i++)
    {
        dist[i] = INF_NUM;
    }

    // 다익스트라
    std::priority_queue<std::pair<int, int>> pq;
    // 시작 정점 초기화
    pq.push(std::make_pair(0, start));
    dist[start] = 0;
    //
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int current = pq.top().second; // 현재 노드
        pq.pop();
        // 작으면 계속 진행
        if (dist[current] < cost)
            continue;
        for (int i = 0; i < Bus[current].size(); i++)
        {
            int next = Bus[current][i].first;
            int nCost = cost + Bus[current][i].second; // 다음으로 향하는 cost로의 합
            if(dist[next] > nCost) // 보다 dist 값이 크면
            {
                //초기화 해야지
                dist[next] = nCost;
                pq.push(std::make_pair(nCost, next));
            }
        }
    }
    std::cout << dist[dest];

    return 0;
}