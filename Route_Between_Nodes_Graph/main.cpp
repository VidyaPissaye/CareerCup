/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 30, 2013, 1:19 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 *   Find out if there exists a route between two nodes.
 */

struct Graph {
    int vertex;
    vector<Graph*> edges;
    bool visited;
};

int BFS_route(Graph* startnode, Graph* endnode) {
    if((startnode == NULL) || (endnode == NULL)) {
        return 1;
    }
    
    startnode->visited = true;
    queue<Graph*> myqueue;
    myqueue.push(startnode);
    
    while(!myqueue.empty()){
        Graph* node = myqueue.front();
        cout << "Vertex visited: " << node->vertex << "->";
        
        for(int i=0; i<node->edges.size(); i++) {
            if(node->edges[i]->visited == false) {
                if(node->edges[i] != endnode) {
                    node->edges[i]->visited = true;
                    myqueue.push(node->edges[i]);
                }
                else {
                    return 1;
                }
            }
        }
    }
    return -1;
}

int main(int argc, char** argv) {

    return 0;
}

