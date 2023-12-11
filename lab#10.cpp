#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int V; // No. of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists
    bool *visited; // visited array
    public:
        Graph(int V); // Constructor
        void addEdge(int v, int w); // function to add an edge to graph
        void removeEdge(int v, int w); // function to remove an edge from graph
        void addNode(int v); // function to add a node to graph
        void removeNode(int v); // function to remove a node from graph
        void traverse(int v); // function to traverse the graph
        void printGraph(); // function to print the graph
};

Graph::Graph(int vertices)
{
    V = vertices;
    adj = new list<int>[V];
    visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::removeEdge(int v, int w)
{
    adj[v].remove(w);
}

void Graph::addNode(int v){
    V++; // Increase the number of vertices
    list<int> *temp = new list<int>[V]; // Allocate new memory for the increased number of vertices
    for(int i = 0; i < V-1; i++)
        temp[i] = adj[i]; // Copy the old adjacency list to the new memory
    temp[V-1] = list<int>(); // Initialize the adjacency list of the new vertex
    adj = temp; // Point the adjacency list to the new memory
}

void Graph::removeNode(int v)
{
    V--; // Decrease the number of vertices
    list<int> *temp = new list<int>[V]; // Allocate new memory for the decreased number of vertices
    for(int i = 0; i < V; i++)
        temp[i] = adj[i]; // Copy the old adjacency list to the new memory, this might cause a segmentation error if v < V
    adj = temp; // Point the adjacency list to the new memory
}

void Graph::traverse(int v)
{
    visited[v] = true; // Mark the vertex as visited
    cout << v << " "; // Print the vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++) // Iterate over the adjacency list of the vertex
        if(!visited[*i]) // If the adjacent vertex is not visited
            traverse(*i); // Recursively traverse the adjacent vertex
}

void Graph::printGraph()
{
    for(int i = 0; i < V; i++)
    {
        cout << i << " ";
        list<int>::iterator j;
        for(j = adj[i].begin(); j != adj[i].end(); j++)
            cout << *j << " ";
        cout << endl;
    }
}

int main(){
    // Create a graph with 4 nodes
    Graph g(7);

    // Add edges
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(3, 6);
    g.addEdge(6, 3);

    // Print the graph
    cout<<"The graph is: \n";
    g.printGraph();

    // Add a node
    cout<<"Adding a node\n";
    g.addNode(7);

    // Print the graph after adding a node
    cout<<"The graph after adding a node is: \n";
    g.printGraph();

    // Remove a node
    cout<<"Removing a node\n";
    g.removeNode(3);

    // Print the graph after removing a node
    cout<<"The graph after removing a node is: \n";
    g.printGraph();

    return 0;
}
