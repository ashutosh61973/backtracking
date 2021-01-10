#include "bits/stdc++.h"

using namespace std;

int isitsafe(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited, int n)
{
    int x = ((i >= 0) && (j >= 0) && (i < n) && (j < n)) && (grid[i][j] != 0) && (visited[i][j] == 0);
    return x;
}
vector<char> path;
void display()
{
    for (auto x : path)
    {
        cout << x;
    }
    cout << " ";
}
int cnt = 0;
void ratpaths(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited, int n)
{
    if ((i == (n - 1)) && (j == (n - 1)))
    {
        display();
        cnt++;
        return;
    }
    visited[i][j] = 1;
    if (isitsafe(i, j + 1, grid, visited, n))
    {
        path.push_back('R');
        ratpaths(i, j + 1, grid, visited, n);
        path.pop_back();
    }
    if (isitsafe(i, j - 1, grid, visited, n))
    {
        path.push_back('L');
        ratpaths(i, j - 1, grid, visited, n);
        path.pop_back();
    }
    if (isitsafe(i + 1, j, grid, visited, n))
    {
        path.push_back('D');
        ratpaths(i + 1, j, grid, visited, n);
        path.pop_back();
    }
    if (isitsafe(i - 1, j, grid, visited, n))
    {
        path.push_back('U');
        ratpaths(i - 1, j, grid, visited, n);
        path.pop_back();
    }
    visited[i][j] = 0;

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, 0));
        vector<vector<int>> visited(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
                if (x == 1)
                    grid[i][j] = 1;
            }
        }
        if (grid[n - 1][n - 1] == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            ratpaths(0, 0, grid, visited, n);
            if (cnt == 0)
            {
                cout << -1;
            }
            cout << endl;
        }
        cnt = 0;
    }
}
