#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Wall
{
public:
    int i, j, height;
    bool operator>
};

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

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        priority_queue<int> walls;
        int i, j, rain = 0, n = heightMap.size(), m = heightMap[0].size();
        for (i = 0;; i = n - 1)
        {
            for (j = 0;; j = m - 1)
            {
            }
        }
    }
};

int main()
{
    return 0;
}