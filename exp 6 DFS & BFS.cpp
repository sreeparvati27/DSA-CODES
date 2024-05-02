#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;
class Graph {
    int V; // Number of vertices
    list<int> *adjList; // Pointer for adjacency list
    bool **adjMatrix; // Pointer for adjacency matrix
public:
    Graph(int V) {
        this->V = V;
        adjList = new list<int>[V];
        // Initialize adjacency matrix
        adjMatrix = new bool*[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new bool[V];
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = false;
            }
        }
    }
	// Function to add an edge for both representations
	void addEdge(int v, int w) {
        adjList[v].push_back(w); // Add w to v's list.
        adjList[w].push_back(v); // Since the graph is undirected
		// For adjacency matrix
        adjMatrix[v][w] = true;
        adjMatrix[w][v] = true;
    }
	// DFS utility function using adjacency matrix
    void DFSUtilMatrix(int v, bool visited[]) {
        // Mark the current node as visited and print it
        visited[v] = true;
        cout << v << " ";
		// Recur for all vertices adjacent to this vertex
        for (int i = 0; i < V; i++) {
            if (adjMatrix[v][i] && !visited[i]) {
                DFSUtilMatrix(i, visited);
            }
        }
    }
	// DFS traversal of the vertices reachable from v using adjacency matrix
    void DFSMatrix(int v) {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        DFSUtilMatrix(v, visited);
        cout << endl;
    }
	// BFS traversal of the graph using adjacency list
    void BFSList(int s) {
        // Mark all the vertices as not visited
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
		// Create a queue for BFS
        queue<int> queue;
        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push(s);
        while (!queue.empty()) {
            // Dequeue a vertex from queue and print it
            s = queue.front();
            cout << s << " ";
            queue.pop(); // Get all adjacent vertices of the dequeued vertex s
            // If an adjacent has not been visited, then mark it visited and enqueue it
            for (auto i = adjList[s].begin(); i != adjList[s].end(); ++i) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    queue.push(*i);
                }
            }
        }
        cout << endl;
    }
};
int main() {
    // Create a graph given in the above diagram (6 vertices)
    Graph g(6);
    g.addEdge(0, 1); // College to Library
    g.addEdge(0, 2); // College to Sports Complex
    g.addEdge(0, 3); // College to Cafeteria
    g.addEdge(1, 4); // Library to Hostel
    g.addEdge(2, 5); // Sports Complex to Parking Lot
    g.addEdge(3, 5); // Cafeteria to Parking Lot
    cout << "DFS (starting from vertex 0, College, using adjacency matrix): \n";
    g.DFSMatrix(0);
    cout << "BFS (starting from vertex 0, College, using adjacency list): \n";
    g.BFSList(0);
    return 0;
}
OUTPUT:
DFS (starting from vertex 0, College, using adjacency matrix):
0 1 4 2 5 3

BFS (starting from vertex 0, College, using adjacency list):
0 1 2 3 4 5

