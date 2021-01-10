#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long

int cnt = 0;
int isitsafe(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited, int n)
{
    for (int i = row; i >= 0; i--)
    {
        if (grid[i][col] == 1)
        {
            return 0;
            break;
        }
    }
    //left diagonal
    for (int i = row, j = col; (i >= 0) && (j >= 0); i--, j--)
    {
        if (grid[i][j] == 1)
        {
            return 0;
            break;
        }
    }
    //right diagonal;
    for (int i = row, j = col; (i >= 0) && (j < n); i--, j++)
    {
        if (grid[i][j] == 1)
        {
            return 0;
            break;
        }
    }
    return 1;
}
void display(vector<vector<int>> &grid, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                cout << 'Q' << " ";
            }
            else
            {
                cout << '.' << " ";
            }
        }
        cout << endl;
    }
}
void Nqueens_placement(int row, int queens, vector<vector<int>> &grid, vector<vector<int>> &visited, int n)
{
    if (queens == n)
    {
        display(grid, n);
        cout << endl;
        cnt++;
        return;
    }
    if (row >= n)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if ((isitsafe(row, i, grid, visited, n)))
        {
            //visited[row][i] = 1;
            grid[row][i] = 1;
            Nqueens_placement(row + 1, queens + 1, grid, visited, n);
            // visited[row][i] = 0;
            grid[row][i] = 0;
        }
    }
    return;
}
//2->ans 0 ways
//4->ans 2 ways
//5->ans 10 ways
//6->ans 4 ways
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
        Nqueens_placement(0, 0, grid, visited, n);
        cout << "total number of ways"
             << "->";
        cout << cnt << endl;
        cnt = 0;
    }
}
