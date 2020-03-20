#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node
{
public:
    int x, y, height;
    Node() {}
    Node(int a, int b, int c = 0) : x(a), y(b), height(c) {}
    bool operator<(const Node &ano) const
    {
        return height > ano.height;
    }
};

int min(int a, int b, int c, int d = INT_MAX)
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

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() < 1 || heightMap[0].size() < 1) return 0;
        // 初始时将所有的边界加入到堆中，取出高度最小的，将此位置往内扩充，
        // 扩充过程中计算新扩充的位置处可以存储的雨水
        // 因为它由堆顶扩充而来，其他边界的高度均大于堆顶，因此将新扩充位置高度与堆顶高度比较
        // 可以得到该位置可以存储的雨水
        priority_queue<Node> pq;
        int n = heightMap.size(), m = heightMap[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            visited[i][0] = visited[i][m - 1] = true;
            pq.push(Node(i, 0, heightMap[i][0]));
            pq.push(Node(i, m - 1, heightMap[i][m - 1]));
        }
        for (int i = 1; i < m - 1; i++) {
            visited[0][i] = visited[n - 1][i] = true;
            pq.push(Node(0, i, heightMap[0][i]));
            pq.push(Node(n - 1, i, heightMap[n - 1][i]));
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        int res = 0;
        while (!pq.empty()) {
            Node node = pq.top(); pq.pop();
            for (int i = 0; i < 4; i++) {
                int x = node.x + dx[i], y = node.y + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                    visited[x][y] = true;
                    // 收缩边界的时候，当前的高度为新位置和旧位置中的最大值
                    pq.push(Node(x, y, max(node.height, heightMap[x][y])));
                    res += max(0, node.height - heightMap[x][y]);
                }
            }
        }

        return res;
    }
};

// class Solution
// {
// public:
//     int trapRainWater(vector<vector<int>> &heightMap)
//     {
//         priority_queue<Node> walls;
//         vector<Node> deserted;
//         int i, j, rain = 0, n = heightMap.size(), m = heightMap[0].size();
//         if (m || n)
//             return 0;
//         for (i = 0; i < n; i++)
//         {
//             Node t(i, 0, heightMap[i][0]);
//             walls.push(t);
//             t.y = m - 1;
//             t.height = heightMap[i][m - 1];
//             walls.push(t);
//             t.y = -1;
//             deserted.push_back(t);
//             t.y = m;
//             deserted.push_back(t);
//         }
//         for (j = 1; j < m - 1; j++)
//         {
//             Node t(0, j, heightMap[0][j]);
//             walls.push(t);
//             t.x = n - 1;
//             t.height = heightMap[n - 1][j];
//             walls.push(t);
//             t.x = -1;
//             deserted.push_back(t);
//             t.x = n;
//             deserted.push_back(t);
//         }
//         {
//             Node four;
//             four.x = -1;
//             four.y = 0;
//             deserted.push_back(four);
//             four.y = m - 1;
//             deserted.push_back(four);
//             four.x = n;
//             deserted.push_back(four);
//             four.y = 0;
//             deserted.push_back(four);
//         }
//         while (!walls.empty())
//         {
//             Node t = walls.top(), neiber;
//         }
//         return rain;
//     }
// };

int main()
{
    Solution t;
    vector<vector<int>> test;
    test = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}};
    t.trapRainWater(test);
    return 0;
}