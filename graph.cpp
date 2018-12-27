#include "graph.h"
#include <set>
#include <utility>
#include <iostream>

using namespace std;

void graph::addEdge(string src , string dst , int distance){
    neighbor tmp_node;
    //from src to dst
    tmp_node.destination=dst;
    tmp_node.weight=distance;
    map[src].push_back(tmp_node);
    //from dst to src
    tmp_node.destination=src;
    tmp_node.weight=distance;
    map[dst].push_back(tmp_node);
};

void graph::removeEdge(string src , string dst){
    //between src and dst
    for(int i = 0 ; i<map[src].size() ; i++){
        if(map[src][i].destination == dst){
            map[src].erase(map[src].begin() + i);
        }
    }
    //between dst and src
    for(int i = 0 ; i<map[dst].size() ; i++){
        if(map[dst][i].destination == src){
            map[dst].erase(map[dst].begin() + i);
        }
    }
};

void graph::removeNode(string twn){
    for (unordered_map< string , vector < neighbor > >::iterator map_it = map.begin() ; map_it != map.end() ; map_it++){
        for(int i=0 ; i<map_it->second.size() ; i++){
            if(map_it->second[i].destination == twn){
                map_it->second.erase(map_it->second.begin() + i);
                --i;
            }
        }
    }
    map.erase(twn);
};

void graph::viewMap(){
    for (unordered_map< string , vector < neighbor > >::iterator map_it = map.begin() ; map_it != map.end() ; map_it++){
        for(int i=0 ; i<map_it->second.size() ; i++){
            cout<<map_it->first<<" >>--- "<<map_it->second[i].weight<<" --> "<<map_it->second[i].destination<<endl;
        }
    }
};


void graph::dijkstra(string src , string dst){
    if(src == dst){
        cout<<"Congrats you are there."<<endl<<endl;
    }
    else if(map[dst].empty()){
        cout<<"You can't go there."<<endl<<endl;
    }
    else if(map[src].empty()){
        cout<<"You're on another planet."<<endl<<endl;
    }
    else{
        unordered_map <string , pair<int, string> > distances;//carries all distances to all the nodes from src and the previous node from the path
        for(auto it = map.begin() ; it != map.end() ; it++){
            distances[it->first].first = 2143658710;//intialize all the distances with "infinity"
            distances[it->first].second = "None";//and still you didn't reach any of them
        }
        distances[src].first = 0;//distance between src and src equals 0
        set < pair < int , string > > neighbors;//carries all the neighbors of the current node
        neighbors.insert(make_pair(0,src));//first step passing throgh src
        while (!neighbors.empty()){//finish calculating the shortest path from the current node to all it's neighbors
            neighbor tmp;
            tmp.destination=neighbors.begin()->second;//store the top neighbor in the set as the current node
            tmp.weight=neighbors.begin()->first;//store the top neighbor in the set as the current node
            neighbors.erase(neighbors.begin());//remove the neighbor that was just stored to empty the set from calculated neighbor's path
            for(auto it=map[tmp.destination].begin() ; it != map[tmp.destination].end() ; it++){//loop over all the current node's neighbors
                if(tmp.weight + it->weight <= distances[it->destination].first){// if the total cost(sum of weights) for getting to the current node + the weight of the neighbor's edge less than the stored cost in the ( unordered_map <string , pair<int, string> > distances; ) that carries all distances to all the nodes from src and the previous node from the path
                    //if true replace the current stored path in the ( unordered_map <string , pair<int, string> > distances; ) that carries all distances to all the nodes from src and the previous node from the path
                    auto old_pair = make_pair(distances[it->destination].first , it->destination);
                    auto find_old_pair = neighbors.find(old_pair);
                    if(find_old_pair!=neighbors.end()){
                        neighbors.erase(find_old_pair);
                    }
                    auto new_pair = make_pair( (tmp.weight + it->weight) , it->destination );
                    neighbors.insert(new_pair);
                    distances[it->destination].first = tmp.weight + it->weight;
                    distances[it->destination].second = tmp.destination;
                }
            }
        }
        cout<<"The total distance: "<<distances[dst].first<<endl<<endl;
        cout<<"The shortest path is through locations: ";
        vector <string> locations;//stores the path
        string loc = dst;//starting from dst
        while(loc != "None"){//while src not found and None is the node that the src was reached from which is None because you're starting at src of course
            locations.push_back(loc);//store the node that you came from all the way to src
            loc = distances[loc].second;
        }
        for(int i=locations.size()-1 ; i>-1 ; i--){//because the path stored in reverse in the ( vector <string> locations; ) 
            cout<<locations[i]<<"  ";
        }
        cout<<endl<<endl;
    }
};
