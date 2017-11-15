//
//  Graph.cpp
//  Graph
//
//  Created by Mads Tilgaard Jensen on 05/12/2016.
//  Copyright © 2016 Mads Tilgaard Jensen. All rights reserved.
//

#include "Graph.hpp"

//Graph
Graph::Graph()
{
}

bool Graph::adjacent(Vertex *x,Vertex *y)
{
	for (int i = 0; i < x->getEdges().size(); i++)
	{
		if (x->getEdges()[i]->getEnd() == y)
			return 1;
	}
	return 0;
}

std::vector<Vertex*> Graph::neighbors(Vertex *x)
{
	std::vector<Vertex*> tmp;
	for ( int i = 0; i < x->getEdges().size(); i++)
	{
		tmp.push_back(x->getEdges()[i]->getEnd());
	}
	return tmp;
}

std::vector<Vertex*> Graph::incoming(Vertex *x)
{
    std::vector<Vertex*> tmp;
    for (int i = 0; i < vertices.size(); i++)
    {
        if (adjacent(vertices[i], x))
            tmp.push_back(vertices[i]);
    }
    return tmp;
}

void Graph::addVertex(Vertex *x)
{
    vertices.push_back(x);
}

void Graph::removeVertex(Vertex *x)
{
    for (int i = 0; i < vertices.size(); i++)
        if (vertices[i] == x)
            vertices.erase(vertices.begin()+i);
}

void Graph::addEdge(Vertex *x, Vertex *y)
{
	addEdge(x,y, 1);
}

void Graph::addEdge(Vertex *x, Vertex *y, int Value)
{
    Edge* tmp = new Edge(Value, y);
    x->addEdge(tmp);
}

void Graph::removeEdge(Vertex *x, Vertex *y)
{
    x->removeEdge(getEdge(x, y));
}

int Graph::getVertexValue(Vertex *x)
{
	return x->getVertexValue();
}

void Graph::setVertexValue(Vertex *x, int v)
{
	x->setVertexValue(v);
}

int Graph::getEdgeValue(Vertex *x, Vertex *y)
{
	return getEdge(x, y)->getEdgeValue();
}

void Graph::setEdgeValue(Vertex *x, Vertex *y, int v)
{
	if (adjacent(x, y))
		for (int i = 0; i < x->getEdges().size(); i++)
		{
			if (x->getEdges()[i]->getEnd() == y)
				x->getEdges()[i]->setEdgeValue(v);
		}
	else
		addEdge(x, y, v);
}

Edge* Graph::getEdge(Vertex *x, Vertex *y)
{
    
    for (int i = 0; i < x->getEdges().size(); i++)
    {
        if (x->getEdges()[i]->getEnd() == y)
            return x->getEdges()[i];
    }
    return nullptr;
}

void Graph::topologicalSorting()
{
    std::vector<Vertex*> list;
    std::vector<Vertex*> noEdges;
    for (int i = 0; i < vertices.size(); i++)
    {
        if (incoming(vertices[i]).size() == 0)
            noEdges.push_back(vertices[i]);
    }
    
    while (noEdges.size() != 0)
    {
        list.push_back(noEdges[0]);
        noEdges.erase(noEdges.begin());
        
        Vertex* current = list.back();
        unsigned long length = neighbors(current).size();
        for (int i = 0; i < length; i++)
        {
            Vertex* tmp = neighbors(current)[0];
            removeEdge(current, tmp);
            if (incoming(tmp).size() == 0)
                noEdges.push_back(tmp);
        }
    }
    vertices = list;
}

void Graph::clearDistances()
{
    for (int i = 0; i < vertices.size(); i++)
        vertices[i]->clearDistance();
}

void Graph::printGraph()
{
	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i]->getVertexValue() << " ";
	std::cout << std::endl;
}

void Graph::printGraphDistances()
{
	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i]->getVertexValue() << " " << vertices[i]->getDistance() << std::endl;
}

std::vector<Vertex*> Graph::getVertices()
{
    return vertices;
}

Graph::~Graph()
{
}


// Edge
Edge::Edge(void)
{
}

Edge::Edge(int length, Vertex *e)
{
    end = e;
    value = length;
}

void Edge::setEdgeValue(int v)
{
    value = v;
}

int Edge::getEdgeValue()
{
    return value;
}

Vertex* Edge::getEnd()
{
	return end;
}

Edge::~Edge()
{
}
    

// Vertex
Vertex::Vertex(void)
{
}

Vertex::Vertex(int v)
{
    value = v;
}

void Vertex::setVertexValue(int v)
{
    value = v;
}

void Vertex::addEdge(Edge *e)
{
    Edges.push_back(e);
}

std::vector<Edge*> Vertex::getEdges()
{
    return Edges;
}

int Vertex::getVertexValue()
{
    return value;
}

int Vertex::getDistance()
{
	return distance;
}

void Vertex::setDistance(int d)
{
	distance = d;
}

void Vertex::clearDistance()
{
    setDistance(255);
}

void Vertex::removeEdge(Edge *e)
{
	for (int i = 0; i < Edges.size(); i++)
        if (Edges[i] == e)
            Edges.erase(Edges.begin()+i);
}

Vertex::~Vertex()
{
}

// Dijkstra
Dijkstra::Dijkstra()
{
}

Dijkstra::Dijkstra(Graph *g, Vertex *x)
{
    g->clearDistances();
    
    vertices = g->getVertices();
    distances.assign(vertices.size(), 255);
    visited.assign(vertices.size(), 0);
    
    for (int i = 0; i < vertices.size(); i++)
    {
        if (x == vertices[i])
        {
            distances[i] = 0;
        }
    }

    calculateDistances(x);
    
    while (moreToCalculate())
        calculateDistances(nextVertex());
    
    for (int i = 0; i < vertices.size(); i++)
    {
        vertices[i]->setDistance(distances[i]);
    }
}

void Dijkstra::calculateDistances(Vertex *x)
{
    int initDist = 0;
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i] == x)
            initDist = distances[i];
    }
    
    for (int i = 0; i < x->getEdges().size(); i++)
    {
        int dist = x->getEdges()[i]->getEdgeValue() + initDist;
        Vertex* end = x->getEdges()[i]->getEnd();
        for (int a = 0; a < vertices.size(); a++)
        {
            if (vertices[a] == end)
            {
                if (distances[a] > dist)
                    distances[a] = dist;

            }
        }
    }
    
    for (int i = 0; i < vertices.size(); i++)
    {
        if (x == vertices[i])
        {
            visited[i] = 1;
        }
    }
}

bool Dijkstra::isVisited(Vertex *x)
{
    for (int i = 0; i < visited.size(); i++)
    {
        if (x == vertices[i])
        {
            return visited[i];
        }
    }
    return 1; // Burde aldrig komme herned.
}

int Dijkstra::getMinDistI()
{
    int index = 0;
    int distance = 255;
    for (int i = 0; i < distances.size(); i++)
    {
        if (distances[i] <= distance)
        {
            distance = distances[i];
            index = i;
        }
    }
    return index;
}

Dijkstra::~Dijkstra()
{
}

bool Dijkstra::moreToCalculate()
{
    for (int a = 0; a < distances.size(); a++)
    {
        if (distances[a] != 255 && visited[a] == 0)
        {
            return 1;
        }
    }
    return 0;
}

Vertex* Dijkstra::nextVertex()
{
    Vertex* next = nullptr;
    int dist = 255;
    for (int i = 0; i < vertices.size(); i++)
    {
        if (distances[i] < dist && visited[i] == 0)
        {
            next = vertices[i];
            dist = distances[i];
        }
    }
    return next;
}
