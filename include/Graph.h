#pragma once
#include "Object.h"
#include "Source.h"
#include<iostream>
#include <list>
#include <unordered_map>
using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{

public:
    Graph();
    ~Graph();
   
    void addEdge(Object* head, Object* w);
    void deleteEdge(Object* head, Object* w);
    void replaceEdge(Object* head, list<Object*> w);
    void WaterFlow();
  
private:
    void DFS(Object* vertex);
    unordered_map<Object*, list<Object*>> adj;
};