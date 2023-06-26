// https://leetcode.com/problems/find-if-path-exists-in-graph/description/
// BFS

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int n, int source, int destination, vector<vector<int> >& nodes) {
        vector<int>dist(n,-1);
        queue<int>que;
        que.push(source);
        dist.at(source) = 0;

        while (!que.empty()) {
            int v = que.front();
            que.pop();


            for (auto next_v : nodes.at(v)) {
                if (dist.at(next_v) != -1) continue;

                que.push(next_v);
                dist.at(next_v) = dist.at(v) + 1;
            }
        }

        // return で条件式を返す。
        // bool can;はcanはfalseで初期化されない。単体の宣言はデフォルトの初期化はない！
        // やるなら bool can = false;
        return bfs(n, source, destination, nodes);
    }
public:
    bool validPath(int n, vector<vector<int> >& edges, int source, int destination) {
        vector<vector<int> >nodes(n);
        for (auto v : edges) {
            int a = v.at(0);
            int b = v.at(1);
            nodes.at(a).push_back(b);
            nodes.at(b).push_back(a);
        }

        return bfs (n, source, destination, nodes);
    }
};