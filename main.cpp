#include "graph.h"
#include <iostream>
using namespace std;

int main(){

    graph places;
    short choice;
infinite_loop:
    cout<<"Enter '1' to add a edge between two places.\n\n";
    cout<<"Enter '2' to remove an edge from your map.\n\n";
    cout<<"Enter '3' to remove a place from your map.\n\n";
    cout<<"Enter '4' to print out your map.\n\n";
    cout<<"Enter '5' to show you the shortest path between two places.\n\n";
    cout<<"Enter '0' to return 0 ;)\n------------------------------------------------------------------------------------------------------------------------\n> ";
    cin>>choice;
    if(choice == 1){
        cout<<"Enter source's name:\n>> ";
        string from;
        cin>>from;
        cout<<"Enter destination's name:\n>> ";
        string to;
        cin>>to;
        cout<<"Enter the distance between them:\n>> ";
        int cost;
        cin>>cost;
        places.addEdge(from , to , cost);
        goto infinite_loop;
    }
    else if(choice == 2){
        cout<<"Enter source's name:\n>> ";
        string from;
        cin>>from;
        cout<<"Enter destination's name:\n>> ";
        string to;
        cin>>to;
        places.removeEdge(from , to);
        goto infinite_loop;
    }
    else if(choice == 3){
        cout<<"Enter place's name:\n>> ";
        string place;
        cin>>place;
        places.removeNode(place);
        goto infinite_loop;
    }
    else if(choice == 4){
        places.viewMap();
        goto infinite_loop;
    }
    else if(choice == 5){
        cout<<"Enter source's name:\n>> ";
        string from;
        cin>>from;
        cout<<"Enter destination's name:\n>> ";
        string to;
        cin>>to;
        places.dijkstra(from , to);
        goto infinite_loop;
    }
    else if(choice == 0){
        return 0;
    }
    else{
        goto infinite_loop;
    }
}