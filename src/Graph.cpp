#include "Graph.h"

Graph::Graph() {}
//run the water from all pipes
void Graph::WaterFlow()
{
    unordered_map<Object*, list<Object*>>::iterator itr;
    for (itr = adj.begin(); itr != adj.end(); itr++)
    {
        if (dynamic_cast<Source*>(itr->second.front()))
        {
            DFS(itr->second.front());//run dfs on the sourse of water
        }
    }
}
//==================================================
Graph::~Graph()
{
    adj.clear();
}
//============================================
void Graph::addEdge(Object* head, Object* w)
{
    adj[head].push_back(w); // Add w to v’s list.
}
//=========================================================
//replace for a new list of neighbors for vetex
void Graph::replaceEdge(Object* head, list<Object*> w)
{
    for (auto x : adj[head])
    {
        x->disconnect();
    }
    adj[head].clear();
    adj[head] = w;
}
//=============================================================
//delete edge for the opposite dir 
void Graph::deleteEdge(Object* head, Object* w)
{
    adj[head].remove(w);
}
//===================================================
//smart algo dfs
void Graph::DFS(Object* vertex)
{
    // Mark the current node as visited and
    // print it
   
    (*adj[vertex].begin())->connect();
   
    // Recur for all the vertices adjacent
    // to this vertex
    list<Object*>::iterator i;
    for (i = adj[vertex].begin(); i != adj[vertex].end(); ++i)
    {
        if (!(*i)->is_connected())
            DFS(*i);
    }
}

