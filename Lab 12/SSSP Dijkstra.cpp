#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <limits>
#include <string>

typedef pair<int, int> recent;

vector<int> dijkstraAlgorithm(vector<vector<pii>>& graph, int begin) {
    vector<int> dist(graph.size(), numeric_limits<int>::max()); // intialize relaxtion
    dist[begin] = 0;
    
    priority_queue<recent, vector<recent>, greater<recent>> prq;
    prq.push(make_pair(0, begin));

    while (!prq.empty()) { // check prq empty or not.
        int i = prq.top().second; //take root node  
        int currtdist = prq.top().first; // take root node distance
        prq.pop();

      
        if (currtdist > dist[i]) {
          continue;
        }

        for (pii neighbor : graph[i]) { 
            int j = neighbor.first; 
            int weight = neighbor.second; 
            if (dist[j] > dist[i] + weight) {  
                dist[j] = dist[i] + weight;
                prq.push(make_pair(dist[j], j));
            }
        }
    }

    return dist;
}

void printShortPath(vector<int> dist,int begin) { // distance array, source node
    int sum = 0;
    for (int i = 0; i < dist.size(); i++) {
        if(begin!=i){
        cout<<"from city "<<to_string(begin)<<" to city "<<to_string(i)<<" = "<<to_string(dist[i])<<endl;
         sum+=dist[i];
        }
    }
    cout<<"\n";
    cout<<"Avarage time from the City "<<to_string(begin)<<" to other is: "<<to_string(sum/5)<<endl; // find average 

    cout<<endl;
}

//add values in adj matrix for graph
void adajanceMatr(vector<vector<pii>>& graph, int i,int j,int weight){ // graph,from,to, weight of path
     //un direct graph
    graph[i].push_back(make_pair(j, weight));
    graph[j].push_back(make_pair(i, weight));
}

int main(){
    vector<vector<recent>> graph(6); 
    // add values in graph represent as adj matrix
    adajanceMatr(graph, 0,1,10);
    adajanceMatr(graph, 0,4,15);
    adajanceMatr(graph, 0,5,5);
    adajanceMatr(graph, 1,2,10);
    adajanceMatr(graph, 1,3,30);
    adajanceMatr(graph, 2,3,12);
    adajanceMatr(graph, 2,4,5);
    adajanceMatr(graph, 3,5,20);
    
    printShortPath (dijkstraAlgorithm(graph, 0),0);     // source node is city 0
    printShortPath(dijkstraAlgorithm(graph, 1),1);    // source node is city 1
    printShortPath(dijkstraAlgorithm(graph, 2),2);    // source node is city 2
    printShortPath(dijkstraAlgorithm(graph, 3),3);    // source node is city 3
    printShortPath(dijkstraAlgorithm(graph, 4),4);    // source node is city 4
    printShortPath(dijkstraAlgorithm(graph, 5),5);    // source node is city 5
    return 0;
}
