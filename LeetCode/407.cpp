#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> height, shortSlab;
int n, m, t;

int min(int a, int b, int c, int d)
{
    int num[4] = {a, b, c, d}, t = a;
    for (int i = 0; i < 4; i++)
    {
        if (t > num[i])
        {
            t = num[i];
        }
    }
    return t;
}

int Short(int i, int j)
{
    if(0<i&&i<n-1&&0<j&&j<m-1)
    {
        
    }
    else
    {
        if(shortSlab[i][j]<t)
    }
}

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int rain = 0;
        n = heightMap.size(), m = heightMap[0].size();
        height = heightMap;
        shortSlab = heightMap;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                t=
                // t = min(heightMap[i - 1][j], heightMap[i + 1][j], heightMap[i][j - 1], heightMap[i][j + 1]) - heightMap[i][j];
            }
        }
        return rain;
    }
};
int main()
{
    return 0;
}