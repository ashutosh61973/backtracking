#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

void display(vector<int> &arr, vector<vector<int>> &part, int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << "[";
        int size = part[i].size();
        int j;
        for (j = 0; j <= size - 2; j++)
        {
            cout << part[i][j] << ',';
        }
        cout << part[i][j];
        cout << "]";
    }

    cout << endl;
}
int cnt = 0;
void k_partition(int i, vector<int> &arr, vector<vector<int>> &part, vector<int> sum_part, int non_empty_subset_so_far, int n, int k, int sum)
{
    if (i >= n)
    {

        if (non_empty_subset_so_far == k) //to element non empty subset
        {
            cnt++;
            display(arr, part, k);
        }
        return;
    }
    for (int j = 0; j < k; j++)
    {
        if (part[j].size() > 0)
        {

            sum_part[j] += arr[i];
            if (sum_part[j] > sum)
            {
                sum_part[j] -= arr[i];
                continue;
            }
            part[j].push_back(arr[i]);
            k_partition(i + 1, arr, part, sum_part, non_empty_subset_so_far, n, k, sum);
            part[j].pop_back();
            sum_part[j] -= arr[i];
        }
        else
        {
            part[j].push_back(arr[i]);
            sum_part[j] += arr[i];
            k_partition(i + 1, arr, part, sum_part, non_empty_subset_so_far + 1, n, k, sum);
            part[j].pop_back();
            sum_part[j] -= arr[i];
            break; //to stop permutation;
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<vector<int>> part(k);
    vector<int> sum_part(k, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % k == 0)
    {
        sum = sum / k;
        k_partition(0, arr, part, sum_part, 0, n, k, sum);
        if (cnt == 0)
        {
            cout << "not possible" << endl;
        }
    }
    else if (sum % k != 0)
    {
        cout << "not possible" << endl;
    }
}
