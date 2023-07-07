#include <iostream>
#include <vector>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

#define MAX_SIZE 1001

int parent[MAX_SIZE];
int result = 0;

int getParent(int num)
{
    // 부모가 자기 자신인 경우
    if (num == parent[num])
    {
        return num;
    }
    // 아니라면 num의 최상위 부모 찾으러 감.
    return parent[num] = getParent(parent[num]);
}

bool findParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if (a == b)
        return true;
    else
        return false;
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a != b) {
		parent[a]= b;
	}
}

int main(int argc, char **argv)
{
    fastio;

    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, std::pair<int, int>>> edge(M);

    for (int i = 0; i < M; i++)
    {
        int a, b, cost;
        std::cin >> a >> b >> cost;
        edge[i] = {cost, {a, b}};
    }
    std::sort(edge.begin(), edge.end());

    // 초기에는 각 정점의 부모가 자기 자신.
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int cost = edge[i].first;
        int a = edge[i].second.first;
        int b = edge[i].second.second;

        // a와 b의 부모가 같지 않으면 -> 사이클을 형성하지 않으면
        // MST에 추가
        if (!findParent(a, b))
        {
            result += cost;
            // a와 b를 연결
            unionParent(a, b);
        }
    }

    std::cout << result;

    return 0;
}