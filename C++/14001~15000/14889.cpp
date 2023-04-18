#include <iostream>
#include <vector>
#include <cmath>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

int N;
int minimum = 9999999;

bool team[20] = {};
int score[20][20] = {};

void dfs(int index, int cnt)
{
    std::vector<int> start;
    std::vector<int> link;

    int start_score = 0;
    int link_score = 0;

    if (cnt == (N / 2))
    {
        for (int i = 0; i < N; i++)
        {
            if (team[i] == true)
            {
                start.push_back(i);
            }
            else
            {
                link.push_back(i);
            }
        }
        for (int i = 0; i < (N / 2); i++)
        {
            for (int j = 0; j < (N / 2); j++)
            {
                start_score += score[start[i]][start[j]];
                link_score += score[link[i]][link[j]];
            }
        }
        if(std::abs(start_score - link_score) < minimum)
            minimum = std::abs(start_score - link_score);
        return;
    }
    for (int i = index; i < N; i++)
    {
        if (team[i] == true)
        {
            continue;
        }
        else
        {
            team[i] = true;
            dfs(i, cnt + 1);
            team[i] = false;
        }
    }
}

int main(int argc, char **argv)
{
    fastio;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> score[i][j];
        }
    }

    dfs(0, 0);

    std::cout << minimum;

    return 0;
}