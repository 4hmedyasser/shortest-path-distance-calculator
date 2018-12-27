#include <unordered_map>
#include <vector>

using namespace std;

class neighbor{
public:
    string destination;
    int weight;
};

class graph{
public:
    unordered_map < string , vector < neighbor > > map;// using ( unordered_map < string , vector < pair < string , int > > > map; ) totally works by replacing ( .destination ) w/ ( .first ) & ( .weight ) w/ ( .second ).
    void addEdge(string src , string dst , int distance);
    void removeEdge(string src , string dst);
    void removeNode(string twn);
    void viewMap();
    void dijkstra(string src , string dst);
};