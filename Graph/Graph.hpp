//
//  Graph.hpp
//  Graph
//
//  Created by Mads Tilgaard Jensen on 05/12/2016.
//  Copyright © 2016 Mads Tilgaard Jensen. All rights reserved.
//

//#ifndef Graph_hpp
//#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

class Graph;
class Edge;
class Vertex;
class Dijkstra;

class Graph
{
public:
    Graph();
    bool adjacent(Vertex *x,Vertex *y);  			//tests whether there is an edge from the vertices x to y;
    std::vector<Vertex*> neighbors(Vertex *x); 		//lists all vertices y such that there is an edge from the vertex x to the vertices y;
    std::vector<Vertex*> incoming(Vertex *x);       //lists all vertices y such that there is an edge from the vertices y to x
    void addVertex(Vertex *x); 						//adds the vertex x, if it is not there;
    void removeVertex(Vertex *x); 					//removes the vertex x, if it is there;
    void addEdge(Vertex *x, Vertex *y); 			//adds the edge from the vertices x to y, if it is not there;
	void addEdge(Vertex *x, Vertex *y, int Value); 	//adds the edge from the vertices x to y , with the value, if it is not there;
    void removeEdge(Vertex *x, Vertex *y); 			//removes the edge from the vertices x to y, if it is there;
    int getVertexValue(Vertex *x); 					//returns the value associated with the vertex x;
    void setVertexValue(Vertex *x, int v); 			//sets the value associated with the vertex x to v.
    int getEdgeValue(Vertex *x, Vertex *y); 		//returns the value associated with the edge (x, y);
    void setEdgeValue(Vertex *x, Vertex *y, int v); //sets the value associated with the edge (x, y) to v.
	Edge* getEdge(Vertex *x, Vertex *y);			//returns the edge from vertex x to vertex y.
	void topologicalSorting();						//sorts the vertices of the grahp using Kahn's algorithm.
    void clearDistances();							//clears the distances calculated(setting them to
    void printGraph();								//prints the vertices of the grahp.
	void printGraphDistances();						//prints the vertices of the grahp with the distances from the main vertex.
    std::vector<Vertex*> getVertices();             //returns all the vertices of the graph.
    ~Graph();
	
private:
    std::vector<Vertex*> vertices;

};

class Edge
{
public:
    Edge(void);
    Edge(int length, Vertex *x);
    void setEdgeValue(int v);
    int getEdgeValue();
	Vertex* getEnd();
    ~Edge();

private:
    int value;
    Vertex* end;
};

class Vertex
{
public:
    Vertex(void);
    Vertex(int v);                                  //initializes a vertex with the value v.
    void setVertexValue(int v);                     //sets the vertex value to v.
    void addEdge(Edge *e);                          //adds an edge to the vertex.
    std::vector<Edge*> getEdges();                  //returns a vector containing all the edges assign to the vertex.
    int getVertexValue();                           //returns the vertex value.
	int getDistance();                              //returns the distances assigned to the vertex.
	void setDistance(int d);                        //sets the distance to the vertex.
	void clearDistance();                           //clears distance by setting it to 255.
	void removeEdge(Edge *e);                       //removes an edge from the vertex.
    ~Vertex();
    
private:
    int value;
	int distance = 255;
    std::vector<Edge*> Edges;
};

class Dijkstra
{
public:
    Dijkstra();
    Dijkstra(Graph *g, Vertex *x);                  //calculates the minimum distance from vertex x to all other vertices.
    void calculateDistances(Vertex *x);             //calculates the distance from vertex x to the adjecent vertices.
    bool isVisited(Vertex *x);                      //true if vertex has been visited by dijkstra.
    int getMinDistI();                              //returns the index for the closest vertex.
    ~Dijkstra();
    
private:
    bool moreToCalculate();                         //returns true if more distances can be calculated.
    Vertex* nextVertex();                           //returns the next vertex to be used for distance calculations.
    std::vector<Vertex*> vertices;
    std::vector<int> distances;
    std::vector<bool> visited;

};

//#endif /* Graph_hpp */
