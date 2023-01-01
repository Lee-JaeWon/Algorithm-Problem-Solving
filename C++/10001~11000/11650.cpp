#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // default
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> v;

    int x, y;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    std::sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        cout << v[i].first << ' ' << v[i].second << "\n";
    }

    return 0;
}