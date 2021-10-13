//
//  GraphMST.cpp
//  GraphMST
//
//  Created by Vansh Mago on 2021-04-02.
//

#include <stdio.h>
#include <iomanip>
#include "mstprimtest.hpp"

GraphMST::~GraphMST()
{
    
        for(int i=0;i<NumVertices;i++){
//            Vertex** temp=adjacency_matrix;
//            if(temp!=nullptr){
            delete [] adjacency_matrix[i];
            adjacency_matrix[i]=nullptr;
//            }
        }

        delete []adjacency_matrix;
        adjacency_matrix=nullptr;
 
        delete [] arr;
        arr=nullptr;

        delete [] degreeArray;
        degreeArray=nullptr;

}

GraphMST::GraphMST(const int n){
    NumVertices=n;
    NumEdges=0;
    adjacency_matrix= new Vertex *[NumVertices];
    arr= new Vertex [NumVertices];
    degreeArray= new int[NumVertices];
    for(int i=0;i<n;i++)
    {
        adjacency_matrix[i]=new Vertex [NumVertices];
        for(int j=0;j<n;j++)
        {
            adjacency_matrix[i][j].key=INT8_MIN;
        }
    }
    for(int i=0;i<n;i++)
    {
        arr[i].key=INT8_MIN;
    }
    for(int i=0;i<n;i++)
    {
        degreeArray[i]=0;;
    }
}

string GraphMST::insert(const int u, const int v, const double w)
{
    if(u<0 || v>NumVertices-1 || u==v || w<0.0)
        throw illegal_exception();
    
    if(adjacency_matrix[u][v].key==INT8_MIN){
       NumEdges+=2;
        degreeArray[u]+=1;
        degreeArray[v]+=1;
    }
    adjacency_matrix[u][v].key=w;
    adjacency_matrix[v][u].key=w;
    
   
    return "success";
}

string GraphMST::erase (const int u, const int v)
{
    if(u<0 || v>NumVertices-1 || u==v)
        throw illegal_exception();
    
    if(adjacency_matrix[u][v].key==INT8_MIN)
        return "failure";
    
    adjacency_matrix[u][v].key=0;
    adjacency_matrix[v][u].key=0;
    NumEdges-=2;
    degreeArray[u]-=1;
    degreeArray[v]-=1;
    return "success";
}

void GraphMST::adjacent(const int u, const int v, const double w)
{
    if(u<0 || v>NumVertices-1 || u==v || w<0.0)
        throw illegal_exception();
    
    if(adjacency_matrix[u][v].key==w){
        cout<<"adjacent "<<u<<" "<<v<<" ";
        cout<<fixed<<setprecision(2)<<w<<endl;
        
    }
    
    else cout<<"not adjacent "<<u<<" "<<v<<" "<<fixed<<setprecision(2)<<w<<endl;
    
}
string GraphMST::degree(const int u)
{
    if(u<0 || u>NumVertices-1 ){
     throw illegal_exception();
    }  
    
    return "degree of "+to_string(u)+" is "+to_string(degreeArray[u]);
}

const string GraphMST::edge_count()
{
    return "edge count is "+to_string(NumEdges);
}

void GraphMST::clear()
{
    for(int i=0;i<NumVertices;i++)
    {
        for(int j=0;j<NumVertices;j++)
        {
            adjacency_matrix[i][j].key=INT8_MIN;
        }
    }
    NumEdges=0;
}

void GraphMST::mst(const int u)
{
    double weight{0.0};
    if(u<0 || u>NumVertices-1 ){
     throw illegal_exception();
    }

    if(this->degree(u).compare("degree of "+to_string(u)+" is 0")==0)
    {
        cout<<"not connected"<<endl;
        return;
    }
    
    PriorityQueue pq;
    pq.init(NumVertices);
    pq.heap[0].key=0;
    pq.buildHeap();

    while(!pq.isempty())
    {
        Vertex a = pq.extractMin();

        for(int i=0;i<NumVertices;i++)
        {
            
            if(adjacency_matrix[a.Node][i].key!=INT8_MIN)
            {

                if(pq.hasVertex(i) && adjacency_matrix[a.Node][i].key<pq.getKey(i) )
                {
                    pq.setKey(i,adjacency_matrix[a.Node][i].key);
                    pq.buildHeap();
                    arr[i].key=adjacency_matrix[a.Node][i].key;
                }
            }
        }
    }
    for(int i=0;i<NumVertices;i++)
    {
        if(arr[i].key>0)
        weight+=arr[i].key;
    }
    
    cout<<"mst "<<fixed<<setprecision(2)<<weight<<endl;
    
}
