#include<iostream>
#include<cmath>
using namespace std;

void print(int index[][3], int d, int column[])
{
    for(int i = 0; i < d; i++)
    {
        cout << index[i][column[i]];
    }
}

void for_loop(int index[][3], int d)
{
    int n = pow(3, d);
    int column[n][d];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < d; j++)
        {
            column[i][j] = index[j][j/pow(3, d-j)];
        }
    }

}

int main(void)
{
    int d, n;
    cout << "Enter d and n: ";
    cin >> d >> n;

    int grid[d];
    cout << "Input grid index: ";
    for(int i = 0; i < d; i++)
        cin >> grid[i];

    int index[d][3];
    for(int i = 0; i < d; i++)
    {
        if(grid[i] == 0)
        {
            index[i][0] = 0;
            index[i][1] = 1;
            index[i][2] = -1;
        }
        else if(grid[i] == n-1)
        {
            index[i][0] = n-2;
            index[i][1] = n-1;
            index[i][2] = -1;
        }
        else
        {
            index[i][0] = grid[i]-1;
            index[i][1] = grid[i];
            index[i][2] = grid[i]+1;
        }
    }

    /*for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(index[d-d][i] != -1 && index[d-d+1][j] != -1 && index[d-d+2][k] != -1)
                cout << "<" << index[d-d][i] << "," << index[d-d+1][j] << "," << index[d-d+2][k] << ">, ";
            }
        }

    }*/
    for_loop(index, d);

    return 0;
}
