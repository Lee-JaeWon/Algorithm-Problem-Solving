#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define fastio std ::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int N, M;
std::vector<std::pair<int, int>> home;
std::vector<std::pair<int, int>> chicken, V;
int Ans;
bool Select[13];

int Min(int A, int B)
{
    if (A < B)
        return A;
    return B;
}

int Calculate_Distance()
{
    int Sum = 0;
    for (int i = 0; i < home.size(); i++)
    {
        int x = home[i].first;
        int y = home[i].second;
        int d = 99999999;

        for (int j = 0; j < V.size(); j++)
        {
            int xx = V[j].first;
            int yy = V[j].second;
            int Dist = abs(xx - x) + abs(yy - y);

            d = Min(d, Dist);
        }
        Sum = Sum + d;
    }
    return Sum;
}

void run(int index, int count)
{
    if (count == M)
    {
        Ans = Min(Ans, Calculate_Distance());
        return;
    }

    for (int i = index; i < chicken.size(); i++)
    {
        if (Select[i] == true)
            continue;
        Select[i] = true;
        V.push_back(chicken[i]);
        run(i, count + 1);
        Select[i] = false;
        V.pop_back();
    }
}

int main(void)
{
    fastio;

    std::cin >> N >> M;

    int tmp;
    Ans = 99999999;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> tmp;
            if (tmp == 1)
            {
                home.push_back({i, j});
            }
            if (tmp == 2)
            {
                chicken.push_back({i, j});
            }
        }
    }
    run(0, 0);

    std::cout << Ans;

    return 0;
}