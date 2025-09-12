#include "Graph.h"
#include <iostream>
#include <vector>
using namespace std;

GraphAdjMatrix::GraphAdjMatrix(const vector<int>& vertices, const vector<vector<int>>& edges) {
    for (int val : vertices) {
        addVertex(val);
    }

    for (const vector<int>& edge : edges) {
        addEdge(edge[0], edge[1]);
    }
}

GraphAdjMatrix::~GraphAdjMatrix() {

}

int GraphAdjMatrix::getSize() const{
	return vertices.size();
}

// 添加顶点
void GraphAdjMatrix::addVertex(int vertex) {
    vertices.push_back(vertex); // 顶点数 +1
    size_t newSize = vertices.size(); // 新的顶点数

    // 1. 先调整所有现有行的列数（从 n 增加到 n+1）
    for (auto& row : adjMatrix) {
        row.resize(newSize, 0); // 填充 0
    }

    // 2. 添加新行（n+1 个 0）
    adjMatrix.emplace_back(newSize, 0);
}

// 删除顶点
void GraphAdjMatrix::removeVertex(int index) {
    if (index >= getSize()) {
        throw out_of_range("Invalid vertex index");
    }

    // 在顶点列表中移除索引 index 的顶点
    vertices.erase(vertices.begin() + index);
    // 删除索引 index 的行
    adjMatrix.erase(adjMatrix.begin() + index);
    // 删除索引 index 的列
    for (vector<int>& row : adjMatrix) {
        row.erase(row.begin() + index);
    }
}

// 添加边
void GraphAdjMatrix::addEdge(int i, int j) {
    if (i < 0 || j < 0 || i >= getSize() || j >= getSize() || i == j) {
        throw out_of_range("Invalid edge");
    }

    // 在无向图中，邻接矩阵关于主对角线对称，即满足 (i, j) == (j, i)
    adjMatrix[i][j] = 1;
    adjMatrix[j][i] = 1;
}

void GraphAdjMatrix::removeEdge(int i, int j) {
    if (i < 0 || j < 0 || i >= getSize() || j >= getSize() || i == j) {
        throw out_of_range("Invalid edge");
    }

    // 断开连接
    adjMatrix[i][j] = 0;
    adjMatrix[j][i] = 0;
}

void GraphAdjMatrix::print() {
    cout << "Vertices list: " << endl;
    for (size_t i = 0; i < vertices.size(); i++) {
        cout << vertices[i] << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Adjacency matrix: " << endl;
    for (size_t i = 0; i < adjMatrix.size(); i++) {
        for (size_t j = 0; j < adjMatrix[i].size(); j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void GraphAdjMatrix::graphBFS(int startVertex) {
    if (startVertex < 0 || startVertex >= getSize()) {
        throw out_of_range("Invalid vertex index");
    }

    vector<bool> visited(getSize(), false); // 标记顶点是否被访问
    queue<int> q;                           // BFS 队列

    q.push(startVertex); // 将起始顶点加入队列
    visited[startVertex] = true;

    cout << "BFS traversal start at " << vertices[startVertex] << ": ";
    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        cout << vertices[currentVertex] << " ";

        for (int vertex = 0; vertex < getSize(); ++vertex) {
            if (adjMatrix[currentVertex][vertex] == 1 && !visited[vertex]) {
                q.push(vertex);
                visited[vertex] = true;
            }
        }
    }
    cout << endl;
}

void GraphAdjMatrix::graphDFS(int startVertex) { 
    if (startVertex < 0 || startVertex >= getSize()) {
        throw out_of_range("Invalid vertex index");
    }

    vector<bool> visited(getSize(), false);
    stack<int> s;

    s.push(startVertex);
    visited[startVertex] = true;
    cout << "DFS traversal starting from vertex " << vertices[startVertex] << ": ";

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        cout << vertices[u] << " ";

        // 反向遍历邻接顶点（保证顺序一致）
        for (int v = getSize() - 1; v >= 0; --v) {
            if (adjMatrix[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }
    cout << endl;
}

vector<int> GraphAdjMatrix::randomWalk(int startNode, int steps, std::mt19937& rng) {
    vector<int> walk;
    int current = startNode;
    int nodesNum = this->getSize();

    walk.reserve(nodesNum + 1); //预留位置
    walk.push_back(vertices[current]);

    for (int step = 0; step < steps; ++step) {
        // 获取当前节点的邻居信息
        const vector<int>& neighboursInfo = adjMatrix[current];

        // 收集当前节点的所有邻居节点索引
        vector<int> neighbours;
        for (int i = 0; i < nodesNum; ++i) {
            if (neighboursInfo[i] > 0) {
                neighbours.push_back(i);
            }
        }

        // 若无邻居，停止游走
        if (neighbours.empty()) {
            std::cerr << "Warning, current node " << current << " has no neighbour, walking end" << endl;
            break;
        }

        std::uniform_int_distribution<int> dist(0, neighbours.size() - 1);
        int next_node = neighbours[dist(rng)];
        current = next_node;
        walk.push_back(current);
    }
    return walk;
}

int main() {
    system("chcp 65001");
    std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

    GraphAdjMatrix graph(
        { 1, 2, 3 },
        { {0, 1}, {1, 2}, {2, 0} }  // 去掉 {2, 3} 和 {3, 0}
    );
    graph.addVertex(4);
    graph.addVertex(5);
    graph.addEdge(3, 2);
    graph.print();

    graph.graphDFS(0);
    graph.graphBFS(0);
    cout << endl;
    
    std::vector<int> path = graph.randomWalk(1, 3, rng);

    // 输出结果
    cout << "Random walk path: " << endl;
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i < path.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}