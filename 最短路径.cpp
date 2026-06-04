#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

class bfsShortestPath {
private:
	int n;
	vector<vector<int>> graph;
	vector<int> dist;
	vector<int> parent;
public:
	bfsShortestPath(int n) : n(n), graph(n) {}

	void addEdge(int u, int v) { graph[u].push_back(v); }

	void bfs(int start) {
		dist.assign(n, INF);
		parent.assign(n, -1);

		queue<int> q;
		dist[start] = 0;
		q.push(start);

		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto v : graph[u]) {
				if(dist[v]==INF) {
					dist[v] = dist[u] + 1;
					parent[v] = u;
					q.push(v);
				}
			}
		}
	}

	vector<int> getShortestPath(int end) {
		vector<int> path;
		if (dist[end] == INF) return path; // No path
		for (int v = end; v != -1; v = parent[v]) {
			path.push_back(v);
		}
		reverse(path.begin(), path.end());
		return path;
	}
};

class dijkstraShortestPath {
private:
	int n;
	vector<vector<pair<int, int>>> graph; // (neighbor, weight)
	vector<int> dist;
	vector<int> parent;
public:
	dijkstraShortestPath(int n) : n(n), graph(n) {}

	void addEdge(int u, int v, int w) { graph[u].emplace_back(v, w); }

	void dijkstraNaive(int start) {
		dist.assign(n, INF);
		parent.assign(n, -1);
		vector<bool> visited(n, false);

		dist[start] = 0;
		for (int i = 0; i < n; ++i) {
			int u = -1;
			for (int j = 0; j < n; ++j) {
				if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
					u = j;
				}
			}
			if (u == -1 || dist[u] == INF) break; // No more reachable vertices
			visited[u] = true;

			for (auto& edge : graph[u]) {
				int v = edge.first, w = edge.second;
				if (!visited[v] && dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					parent[v] = u;
				}
			}
		}
	}

	void dijkstraHeap(int start) {
		dist.assign(n, INF);
		parent.assign(n, -1);
		vector<bool> visited(n, false);

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		// (distance, vertex)

		dist[start] = 0;
		pq.push({ 0, start });

		while (!pq.empty()) {
			int u = pq.top().second;
			pq.pop();

			if (visited[u]) continue;
			visited[u] = true;

			for (auto& edge : graph[u]) {
				int v = edge.first, w = edge.second;
				if (!visited[v] && dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					parent[v] = u;
					pq.push({ dist[v], v });
				}
			}
		}
	}

	void run(int start, bool useNaive = false) {
		if (useNaive)
			dijkstraNaive(start);
		else
			dijkstraHeap(start);
	}

	int getDistance(int end) {
		if (end < 0 || end >= n) return -1;// Invalid vertex
		return dist[end] == INF ? -1 : dist[end];
	}

	void getAllDistances(int start) {
		run(start);
		for (int i = 0; i < n; ++i) {
			cout << "Distance from " << start << " to " << i << ": ";
			if (dist[i] == INF) {
				cout << "INF" << endl;
			}
			else {
				cout << dist[i] << endl;
			}
		}
	}

	void getShortestDistances(int start, const vector<int>& targets, bool useNaive = false) {
		run(start, useNaive);
		for (int target : targets) {
			cout << "Distance from " << start << " to " << target << ": ";
			if (dist[target] == INF) {
				cout << "INF" << endl;
			}
			else {
				cout << dist[target] << endl;
			}
		}
	}

	vector<int> getShortestPath(int end) {
		vector<int> path;
		if (dist[end] == INF) return path; // No path
		for (int v = end; v != -1; v = parent[v]) {
			path.push_back(v);
		}
		reverse(path.begin(), path.end());
		return path;
	}

};

class FloydShortestPath {
private:
	int n;
	vector<vector<int>> dist;
	vector<vector<int>> path;
public:
	FloydShortestPath(int n) : n(n), dist(n, vector<int>(n, INF)), path(n, vector<int>(n, -1)) {
		for (int i = 0; i < n; ++i) {
			dist[i][i] = 0;
			path[i][i] = i;
		}
	}

	void addEdge(int u, int v, int w) {
		dist[u][v] = w;
		path[u][v] = u;
	}

	void floydWarshall() {
		// Floyd-Warshall算法核心部分
		// 通过每个中间节点k，更新所有节点对(i, j)的最短路径
		// 如果通过k的路径更短，则更新dist[i][j]和path[i][j]
		// 时间复杂度O(n^3)，适用于小规模图
		// 注意：如果图中存在负权边且有负权环，Floyd-Warshall算法无法正确处理
		//通过每个中间节点k，更新所有节点对(i, j)的最短路径
		//如果通过k的路径更短，则更新dist[i][j]和path[i][j]
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				if (dist[i][k] == INF) continue; 
				for (int j = 0; j < n; ++j) {
					if (dist[k][j] == INF) continue;
					int newDist = dist[i][k] + dist[k][j];
					if (newDist < dist[i][j]) {
						dist[i][j] = newDist;
						path[i][j] = path[k][j];  
					}
				}
			}
		}
	}

	vector<int> getShortestPath(int start, int end) {
		vector<int> result;
		if (dist[start][end] == INF) return result; // No path
		for (int v = end; v != start; v = path[start][v]) {
			result.push_back(v);
		}
		result.push_back(start);
		reverse(result.begin(), result.end());
		return result;
	}
};

int main() {

	//bfs test
	/*
	int n, m, start, end;
	cin >> n >> m >> start >> end;
	bfsShortestPath solver(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		solver.addEdge(u, v, w);
	}
	solver.bfs(start);
	vector<int> path = solver.getShortestPath(end);
	if (path.empty()) {
		cout << "No path from " << start << " to " << end << endl;
	} else {
		cout << "Shortest path from " << start << " to " << end << ": ";
		for (int v : path) {
			cout << v << " ";
		}
		cout << endl;
	}
	*/

	vector<vector<int>> graph = {
		{1, 2},          // 0 连接 1,2
		{0, 3, 4},       // 1 连接 0,3,4
		{0, 4},          // 2 连接 0,4
		{1, 5},          // 3 连接 1,5
		{1, 2, 5, 6},    // 4 连接 1,2,5,6
		{3, 4},          // 5 连接 3,4
		{4}              // 6 连接 4
	};
	bfsShortestPath solver(graph.size());
	for (int u = 0; u < graph.size(); ++u) {
		for (int v : graph[u]) {
			solver.addEdge(u, v); // 无权图，权重为1
		}
	}
	solver.bfs(0);
	vector<int> path = solver.getShortestPath(6);
	if (path.empty()) {
		cout << "No path from 0 to 6" << endl;
	} else {
		cout << "Shortest path from 0 to 6: ";
		for (int v : path) {
			cout << v << " ";
		}
		cout << endl;
	}


	//dijkstra test
	auto dijkstraSolver = dijkstraShortestPath(7);
	dijkstraSolver.addEdge(0, 1, 2);
	dijkstraSolver.addEdge(0, 2, 4);
	dijkstraSolver.addEdge(1, 3, 7);
	dijkstraSolver.addEdge(1, 4, 3);
	dijkstraSolver.addEdge(2, 4, 1);
	dijkstraSolver.addEdge(3, 5, 1);
	dijkstraSolver.addEdge(4, 5, 2);
	dijkstraSolver.addEdge(4, 6, 5);

	int start = 0, end = 6;
	dijkstraSolver.run(start);
	int distance = dijkstraSolver.getDistance(end);
	if (distance == -1) {
		cout << "No path from " << start << " to " << end << endl;
	} else {
		cout << "Shortest distance from " << start << " to " << end << ": " << distance << endl;
		vector<int> path = dijkstraSolver.getShortestPath(end);
		cout << "Shortest path from " << start << " to " << end << ": ";
		for (int v : path) {
			cout << v << " ";
		}
		cout << endl;
	}

	auto dijkstraSolverNaive = dijkstraShortestPath(7);
	dijkstraSolverNaive.addEdge(0, 1, 2);
	dijkstraSolverNaive.addEdge(0, 2, 4);
	dijkstraSolverNaive.addEdge(1, 3, 7);
	dijkstraSolverNaive.addEdge(1, 4, 3);
	dijkstraSolverNaive.addEdge(2, 4, 1);
	dijkstraSolverNaive.addEdge(3, 5, 1);
	dijkstraSolverNaive.addEdge(4, 5, 2);
	dijkstraSolverNaive.addEdge(4, 6, 5);
	dijkstraSolverNaive.run(start, true);
	distance = dijkstraSolverNaive.getDistance(end);
	if (distance == -1) {
		cout << "No path from " << start << " to " << end << endl;
	} else {
		cout << "Shortest distance from " << start << " to " << end << ": " << distance << endl;
		vector<int> path = dijkstraSolverNaive.getShortestPath(end);
		cout << "Shortest path from " << start << " to " << end << ": ";
		for (int v : path) {
			cout << v << " ";
		}
		cout << endl;
	}

	auto dijkstraSolverHeap = dijkstraShortestPath(7);
	dijkstraSolverHeap.addEdge(0, 1, 2);
	dijkstraSolverHeap.addEdge(0, 2, 4);
	dijkstraSolverHeap.addEdge(1, 3, 7);
	dijkstraSolverHeap.addEdge(1, 4, 3);
	dijkstraSolverHeap.addEdge(2, 4, 1);
	dijkstraSolverHeap.addEdge(3, 5, 1);
	dijkstraSolverHeap.addEdge(4, 5, 2);
	dijkstraSolverHeap.addEdge(4, 6, 5);
	dijkstraSolverHeap.run(start, false);
	distance = dijkstraSolverHeap.getDistance(end);
	if (distance == -1) {
		cout << "No path from " << start << " to " << end << endl;
	} else {
		cout << "Shortest distance from " << start << " to " << end << ": " << distance << endl;
		vector<int> path = dijkstraSolverHeap.getShortestPath(end);
		cout << "Shortest path from " << start << " to " << end << ": ";
		for (int v : path) {
			cout << v << " ";
		}
		cout << endl;
	}

	//Floyd-Warshall test
	auto floydSolver = FloydShortestPath(4);
	floydSolver.addEdge(0, 1, 5);
	floydSolver.addEdge(0, 2, 10);
	floydSolver.addEdge(1, 2, 3);
	floydSolver.addEdge(1, 3, 1);
	floydSolver.addEdge(2, 3, 8);
	floydSolver.floydWarshall();
	int startFloyd = 0, endFloyd = 3;
	int distanceFloyd = floydSolver.getShortestPath(startFloyd, endFloyd).empty() ? -1 : floydSolver.getShortestPath(startFloyd, endFloyd).size() - 1;
	if (distanceFloyd == -1) {
		cout << "No path from " << startFloyd << " to " << endFloyd << endl;
	} else {
		cout << "Shortest distance from " << startFloyd << " to " << endFloyd << ": " << distanceFloyd << endl;
		vector<int> path = floydSolver.getShortestPath(startFloyd, endFloyd);
		cout << "Shortest path from " << startFloyd << " to " << endFloyd << ": ";
		for (int v : path) {
			cout << v << " ";
		}
		cout << endl;
	}


	return 0;
}