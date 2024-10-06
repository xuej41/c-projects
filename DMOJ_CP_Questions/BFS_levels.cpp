// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
#include<iostream>
#include <list>

using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;
public:
    int *levels; // depths
    Graph(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s, to target t
    void BFS(int s, int t);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    levels = new int[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v�s list.
}

void Graph::BFS(int s, int t) // start, target
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
    levels[s] = 0;

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        int v  = queue.front();
        cout << v << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
                levels[*i] = levels[v] + 1;
                cout << endl << v << " " << *i << endl;
                if(*i == t)
                    return;
            }
        }
    }
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    int start = 2;
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex " << start << ") \n";
    //g.BFS(2, V+2);
    cout << endl;

    g.BFS(2, 1);
    cout << endl;

    cout << "Levels, or depths, or steps, or paths of "
         << "each vertex from vertex " << start << ") \n";

    cout << "vertex " <<  "level" <<endl;
    for(int i=0; i<V; i++) {
       cout << i << "    "  <<  g.levels[i] <<endl;
    }
    return 0;
}

/*
Output:

Following is Breadth First Traversal (starting from vertex 2)
2 0 3 1
*/
