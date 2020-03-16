#include <iostream>
#include <vector>
using namespace std;

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

int Short(const vector<vector<int>> &heightMap, vector<vector<int>> &short_slab, int i, int j, int n, int m)
{
    if(0<i&&i<n-1&&0<j&&j<m-1)
    {
        if(i==1&&short_slab[0][j]<=)
    }
}

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int rain = 0, n = heightMap.size(), m = heightMap[0].size(), t;
        vector<vector<int>> short_slab(n);
        for (int i = 0; i < n;i++)
        {
            short_slab[i] = heightMap[i];
        }
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                t = min(heightMap[i - 1][j], heightMap[i + 1][j], heightMap[i][j - 1], heightMap[i][j + 1]) - heightMap[i][j];
                if (t > 0)
                    rain += t;
            }
        }
        return rain;
    }
};
int main()
{
    return 0;
}