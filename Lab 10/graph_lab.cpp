#include <iostream>
#include<list>
using namespace std;

struct Node{
    // A node will 2 entities
    //1. data type int called label
    int label;
    list<int> neighbours;
    //2. a int type list called neighbours

};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=8;
    Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=0;i<n;i++){
            nodes[i].label=i+1;
        }
    }

    void addedge(int u, int v){
        //select node u and push v into u's neighbour
        //int i=0; // this i for search i node.
        //while(i<n && nodes[i].label!=u){
           // i++;
        //}
        //nodes[i].neighbours.push_back(v); // successfully insert v for node u
        for(int i=0; i<n;i++){ 
            if(nodes[i].label==u){ //find U node
                nodes[i].neighbours.push_back(v); // push value V in node u
                break;
            }
        }

        //select node v and push u into v's neighbour
        //int j=0; // this j for search j node in graph array.
        //while(j<n && nodes[j].label!=v){ // when exit this while loop get serch node
          //  j++;
        //}
        //nodes[j].neighbours.push_back(u); // successfully insert u for node v
        for(int j=0;j<n;j++){
            if(nodes[j].label==v){
                 nodes[j].neighbours.push_back(u); // push value u in node V
                break;
            }
        }
    }

    void print(){
        //lets iterate through each node and print its neighbours
        int k=0;
        while(k<n){
            cout<<"Node value "<<nodes[k].label<<endl; // select Node 
            cout<<"Neighbours"<<endl; 
            for(int value:nodes[k].neighbours){ 
                cout<<value<<" "; // print neighbour value
            }
            cout<<endl;
            k++;
        }
    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.
    g->addedge(1,2);
    g->addedge(3,1);
    g->addedge(1,4);
    g->addedge(1,5);
    g->addedge(6,2);
    g->addedge(2,3);
    g->addedge(4,6);
    g->addedge(7,4);
    g->addedge(4,8);
    g->addedge(5,6);
    g->addedge(5,7);
    g->addedge(8,5);
    //print the graph adjaceny list
    g->print();
}