#include <bits/stdc++.h>
using namespace std;

#define U 6

//  find minimum key.
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < U; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

//  print MST edges.
void printMST(int parent[], int graph[U][U], int start)
{
    cout << "Start Vertex : " << start << endl;
    cout << " Edge    Weight\n";
    for (int i = 1; i < U; i++)
        cout << parent[i] << " - " << i << "      " << graph[i][parent[i]] << " \n";
}

//  find MST.
void primMST(int graph[U][U], int start)
{
    int parent[U];
    int key[U];
    bool mstSet[U];

    //  initialize variables.
    for (int i = 0; i < U; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = start;
    parent[0] = -1;

    //  update MST.
    for (int count = 0; count < U - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < U; v++)
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, start);
}

int main()
{
    int graph[U][U] = { { 0, 3, 0, 0, 0, 1 },
                        { 3, 0, 2, 1, 10, 0 },
                        { 0, 2, 0, 3, 0, 5 },
                        { 0, 1, 3, 0, 5, 0 },
                        { 0, 10, 0, 5, 0, 4 },
                        { 1, 0, 5, 0, 4, 0 } };

    primMST(graph, 0);

    return 0;
}