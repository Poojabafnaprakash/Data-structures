#include <iostream>
#include <list>
#include <limits.h>
using namespace std;

// Graph class for a directed graph using adjacency list representation
class Graph
{
    int verticesGraph;    // No. of vertices
    list<int> *adjVertex;    // Pointer to an array containing adjacency lists
    void DepthFirstTraversalUtil(int v, bool visited[]);  // A function used by DepthFirstTraversal
public:
    Graph(int verticesGraph);   // Constructor
    void addEdge(int vertex, int vertexAdj);   // function to add an edge to graph
    void DepthFirstTraversal(int vertexDFT);    // DepthFirstTraversal of the vertices reachable from vertexDFT
    void BreadthFirstTraversal(int vertexBFT);
    void printGraph(int sz);
};

Graph::Graph(int verticesGraph)
{
    this->verticesGraph = verticesGraph;
    adjVertex = new list<int>[verticesGraph];
}

void Graph::addEdge(int vertex, int vertexAdj)
{
    adjVertex[vertex].push_back(vertexAdj); // Add vertexAdj to vertex’s list.
}

void Graph::DepthFirstTraversalUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adjVertex[v].begin(); i != adjVertex[v].end(); ++i)
        if(!visited[*i])
            DepthFirstTraversalUtil(*i, visited);
}

// DepthFirstTraversal of the vertices reachable from vertexDFT. It uses recursive DepthFirstTraversalUtil()
void Graph::DepthFirstTraversal(int vertexDFT)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[verticesGraph];
    for(int i = 0; i < verticesGraph; i++)
        visited[i] = false;

    // Call the recursive helper function to print DepthFirstTraversal traversal
    DepthFirstTraversalUtil(vertexDFT, visited);
}
 void Graph::BreadthFirstTraversal(int vertexBFT)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[verticesGraph];
    for(int i = 0; i < verticesGraph; i++)
        visited[i] = false;

    // Create a queue for BreadthFirstTraversal
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[vertexBFT] = true;
    queue.push_back(vertexBFT);

    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        vertexBFT = queue.front();
        cout << vertexBFT << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adjVertex[vertexBFT].begin(); i != adjVertex[vertexBFT].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::printGraph(int sz)
{
    list<int>::iterator j;
    for(int i = 0; i < sz; i++)
    {
        cout << i << "\t";
        for (j = adjVertex[i].begin(); j != adjVertex[i].end(); j++)
        {
            cout << *j << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int vertexTraversal;

    Graph gNew(5);
    gNew.addEdge(0, 1);
    gNew.addEdge(0, 2);
    gNew.addEdge(1, 2);
    gNew.addEdge(2, 0);
    gNew.addEdge(2, 3);
    gNew.addEdge(3, 3);
    gNew.addEdge(4, 1);
    gNew.addEdge(4, 0);
    gNew.addEdge(3, 2);
    gNew.addEdge(2, 4);
    gNew.addEdge(0, 4);

    gNew.printGraph(5);

    cout << "Enter the vertex from where the traversal should start" << endl;
    cin >> vertexTraversal;
    cout << "\nDepth First Traversal (starting from vertex "<< vertexTraversal << " )" << endl;
    gNew.DepthFirstTraversal(vertexTraversal);
    cout << "\nBreadth First Traversal (starting from vertex " << vertexTraversal << " )" << endl;
    gNew.BreadthFirstTraversal(vertexTraversal);

    return 0;
}
