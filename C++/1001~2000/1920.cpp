#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // default
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int x;
    vector<int> v1;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        v1.push_back(x);
    }
    sort(v1.begin(), v1.end());

    int M;
    cin >> M;

    bool isResult;
    for (int i = 0; i < M; i++)
    {
        cin >> x;
        isResult = binary_search(v1.begin(), v1.end(), x);
        cout << isResult << "\n";
    }

    return 0;
}