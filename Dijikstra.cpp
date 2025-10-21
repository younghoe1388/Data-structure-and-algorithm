#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <functional>
using namespace std;

class SimpleGraph {
private:
    vector<vector<pair<int, int>>> adjList;  // 邻接表: [邻居顶点, 权重]

public:
    SimpleGraph(int n) : adjList(n) {}

    // 添加边
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({ v, weight });
        adjList[v].push_back({ u, weight });  // 无向图
    }

    // Dijikstra 算法
    vector<int> dijikstra(int start) {
        int n = adjList.size();
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start] = 0;
        pq.push({ 0, start });

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (dist[u] > d) continue;

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                int newDist = dist[u] + weight;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({ newDist, v });
                }
            }
        }
        return dist;
    }

    int size() const { return adjList.size(); }

    vector<vector<int>> connectComponent(const vector<vector<int>>& graph) {
        int n = adjList.size();
        vector<bool> visited(n, false);
        vector<vector<int>> components;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                // 新的连通分量
                vector<int> component;
                queue<int> q;
                visited[i] = true;
                q.push(i);

                // BFS遍历
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    component.push_back(u);

                    for (auto& neighbor : adjList[u]) {
                        int v = neighbor.first;  // 提取顶点编号
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
                components.push_back(component);
            }
        }
        return components;
    }
};



// 使用示例
int main() {
    system("chcp 65001");
    SimpleGraph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 1);

    vector<int> dist = g.dijikstra(0);
    for (int i = 0; i < g.size(); ++i) {
        cout << "Distance to " << i << ": " << dist[i] << endl;
    }
}