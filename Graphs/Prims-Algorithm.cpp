#include <iostream>
using namespace std;

int V = 0;

// Function to find the vertex with minimum key value
int min_Key(int key[], bool visited[])
{
    int min = 999, min_index; // 999 represents an Max Cost value

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false && key[v] < min)
        {
            // vertex should not be visited
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the final MST stored in parent[]
void print_MST(int parent[], int **cost)
{
    int minCost = 0;
    cout << "Edges \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] + 1 << " - " << i + 1 << " \t" << cost[i][parent[i]] << " \n";
        minCost += cost[i][parent[i]];
    }
    cout << "\nTotal cost is: " << minCost;
}

void printGraph(int **cost)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}

void find_MST(int **cost)
{
    int parent[V], key[V];
    bool visited[V];

    // Initialize all the arrays
    for (int i = 0; i < V; i++)
    {
        key[i] = 999; // 999 represents an Max Cost value
        visited[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int x = 0; x < V - 1; x++)
    {
        int u = min_Key(key, visited);

        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (cost[u][v] != 0 && visited[v] == false && cost[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }

    print_MST(parent, cost);
}

int main()
{
    system("cls");
    cout << "Enter number of vertices : ";
    cin >> V;

    cout << "\nEnter Graph in form of Adjacency Cost Matrix !\nEnter Weights directly !";

    int **cost = new int *[V];
    cout << "\n\nEnter the vertices for a graph with " << V << " vetices " << endl;
    for (int i = 0; i < V; i++)
    {
        cost[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            cin >> cost[i][j];
        }
    }
    cout << "\nYour Graph is\n";
    printGraph(cost);
    cout << endl;
    find_MST(cost);

    return 0;
}