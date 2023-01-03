// 2805 BOJ, 최적화 문제?
// 절단기로 설정할 수 있는 높이의 "최댓값"
// 임의의 값에 접근할 때는 이분 탐색으로 접근하는 것이 "효율적"

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // default
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    long long M;
    cin >> N >> M;

    vector<int> vec;
    long long a;
    long long maxi = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        vec.push_back(a);
        if (a >= maxi)
        {
            maxi = a;
        }
    }

    long long left = 0;
    long long right = maxi;
    long long mid;
    long long sum = 0;
    long long result = 0;
    while (left <= right)
    {
        mid = (left + right) / 2; // 몫만
        sum = 0;

        // 나무의 높이의 합은 항상 M보다 크거나 같기 때문에(출처 BOJ)
        for (int i = 0; i < N; i++)
        {
            if (mid < vec[i]) // 중간 값보다 클 때
            {
                sum = sum + vec[i] - mid; // 남는 길이의 합
            }
        }
        // 나무의 높이의 합이 M보다 크거나 같을 때
        if (sum >= M)
        {
            result = mid; // 결과 후보
            left = mid + 1; // 왼쪽을 줄여서 이진 탐색
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << result;

    return 0;
}