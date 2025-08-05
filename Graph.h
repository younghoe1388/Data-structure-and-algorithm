#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


// 邻接矩阵实现的无向图
class GraphAdjMatrix {
private:
	vector<int> vertices; // 顶点列表，元素代表“顶点值”，索引代表“顶点索引”
	vector<vector<int>> adjMatrix; // 邻接矩阵，行列索引对应“顶点索引”

public:
	GraphAdjMatrix(const vector<int>& vertices, const vector<vector<int>>& edges);
	~GraphAdjMatrix();

	int getSize() const ;
	void addVertex(int vertex);
	void removeVertex(int index);
	void addEdge(int i, int j);
    void removeEdge(int i, int j);

	// 图的遍历
	// 广度优先搜索BFS（结果并不唯一）
	void graphBFS(int startVertex); // startVertex是顶点索引
	// 深度优先搜索DFS（结果不唯一）
	void graphDFS(int startVertex);

	void print();
};
