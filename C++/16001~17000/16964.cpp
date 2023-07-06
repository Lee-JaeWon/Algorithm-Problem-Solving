#include <iostream>
#include <vector>
#include <algorithm>

#define fastio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)

#define ARR_SIZE 100001

int visited[ARR_SIZE] = {
    0,
};
int order[ARR_SIZE];
std::vector<int> dfs_order;

bool comp(int &a, int &b)
{
    return order[a] < order[b];
}

void dfs(const std::vector<std::vector<int>> &vec, int R)
{
    if (visited[R] == 1)
        return;

    visited[R] = 1;

    // std::cout << R << " ";
    dfs_order.push_back(R);

    int vec_size = vec[R].size();
    for (int i = 0; i < vec_size; i++)
    {
        if (visited[vec[R][i]] == 0)
        {
            dfs(vec, vec[R][i]);
        }
    }
}

int main(int argc, char **argv)
{
    fastio;

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> vec;
    vec.resize(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;

        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    std::vector<int> res_vec;
    for (int i = 1; i <= N; i++)
    {
        int temp;
        std::cin >> temp;

        res_vec.push_back(temp);
        order[temp] = i;
    }

    int R = 1;

    for (int i = 1; i <= N; i++)
        std::sort(vec[i].begin(), vec[i].end(), comp);
    dfs(vec, R);

    if (res_vec == dfs_order)
    {
        std::cout << "1";
        return 0;
    }
    else
    {
        std::cout << "0";
    }

    return 0;
}