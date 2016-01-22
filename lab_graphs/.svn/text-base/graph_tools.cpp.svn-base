/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */

#include "graph_tools.h"

/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph & graph, Vertex start, Vertex end)
{
    // Get all vertives
    vector<Vertex> all = graph.getVertices();
   int alnn = all.size(); 
   for(int i =0; i < alnn;i++){
        graph.setVertexLabel(all[i],"UNEXPLORED");
    }
    
	queue<Vertex> q;
	q.push(start);
    
    // unordered map : parent
	unordered_map<Vertex,Vertex> parent;
	parent.emplace(start,start);
	int count = 1;

	while(!q.empty())
	{
		Vertex tem = q.front();
		q.pop();
        graph.setVertexLabel(tem,"VISITED");
        
		vector<Vertex> near = graph.getAdjacent(tem);
		int nn = near.size();
		for(int i =0; i < nn;i++)
		{
			if(graph.getVertexLabel(near[i]) == "UNEXPLORED")
            {
                graph.setVertexLabel(near[i],"VISITED");
                q.push(near[i]);
                parent.emplace(near[i],tem);
            }
		}
	}
    
   Vertex e = end;
    if(parent[e] == start){
        graph.setEdgeLabel(e,parent[e],"MINPATH");
        return 1;
    }
    
    while(parent[e]!=start){
        graph.setEdgeLabel(e,parent[e],"MINPATH");
        e = parent[e];
        count++;
        
    }
    
    if(parent[e] == start){
        graph.setEdgeLabel(e,parent[e],"MINPATH");
    }
    
    return count;
}

/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph & graph)
{
    queue<Vertex> q;
    // All edges
    vector<Edge> all = graph.getEdges();
    
    // Starting point
   // Vertex start = graph.getStartingVertex();
    
    Edge min = all[0];
    int nn = all.size();	   
    for(int i =0; i < nn; i++){
        if(min.weight <= all[i].weight)
            min = min;
        else
            min = all[i];
        
        
    }
    
    // Set label
    graph.setEdgeLabel(min.source,min.dest,"MIN");
    
    return min.weight;
}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the libdsets folder.
 * @note You may call std::sort (http://www.cplusplus.com/reference/algorithm/sort/)
 *  instead of creating a priority queue.
 */
void GraphTools::findMST(Graph & graph)
{
    // All edges
    vector<Edge> alledge = graph.getEdges();
    vector<Vertex> allvertex = graph.getVertices();
    int nedge = alledge.size();
    int nvertex = allvertex.size();
    int count = 0;
    
    sort(alledge.begin(),alledge.end());
    
    DisjointSets ds;
    ds.addelements(nvertex);
    
    while(count < nvertex -1){
    for(int i = 0; i < nedge; i++){
        Edge current = alledge[i];
       // source = current.source;
       // dest = current.dest;
        
        // Location of source and deft
        int possource = find(allvertex.begin(),allvertex.end(),current.source) - allvertex.begin();
        int posdest =find(allvertex.begin(),allvertex.end(),current.dest) - allvertex.begin();
        
        if(ds.find(possource) != ds.find(posdest))
        {
            ds.setunion(possource,posdest);
            graph.setEdgeLabel(current.source,current.dest,"MST");
            count++;
        }
    }
    }
}
