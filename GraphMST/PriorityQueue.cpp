//
//  PriorityQueue.cpp
//  GraphMST
//
//  Created by Vansh Mago on 2021-04-04.
//

#include <stdio.h>
using namespace std;

#include <iostream>
#include "mstprimtest.hpp"


PriorityQueue::~PriorityQueue(){
    delete [] heap;
    heap=nullptr;
}

PriorityQueue::PriorityQueue()
{
    size=0;
    capacity=0;
}

void PriorityQueue::init(const int n)
{
    size=n-1;
    capacity=n;
    heap= new Vertex [capacity];
    for(int i=0;i<capacity;i++)
    {
        Vertex a(i,INT8_MAX);
        heap[i]=a;
    }
}

Vertex PriorityQueue::extractMin()
{
  
      Vertex min = heap[0];
      heap[0] = heap[size];
      size--;
      this->buildHeap();
      return min;

}

void PriorityQueue::ModifyKey(const int u)
{
      int smallest = u;

      if ((leftChild(u) <= size) && (leftChild(u)>0)) {
        if (heap[leftChild(u)].key < heap[smallest].key) {
          smallest = leftChild(u);
        }
      }

      if ((rightChild(u) <= size && (rightChild(u)>0))) {
        if (heap[rightChild(u)].key < heap[smallest].key) {
          smallest = rightChild(u);
        }
      }

      if (smallest != u) {
          Vertex temp= heap[u];
          heap[u]=heap[smallest];
          heap[smallest]=temp;
          ModifyKey(smallest);
      }
}

const int PriorityQueue::leftChild(const int u)
{
    return ((2 * u) + 1);
}

const int PriorityQueue::rightChild(const int u)
{
    return ((2 * u) + 2);
}
 const bool PriorityQueue::isempty()
{
    return size==0;
}

const bool PriorityQueue::hasVertex(const int u)
{
    for(int i=0;i<=size;i++)
    {
        if(heap[i].Node==u)
            return true;
    }
    return false;
}

Vertex PriorityQueue::nodeVertex(const int node)
{
    for(int i=0;i<=size;i++)
    {
        if(heap[i].Node==node)
            return heap[i];
    }
    return heap[0];
}

double PriorityQueue::getKey(const int node)
{
    for(int i=0;i<=size;i++)
    {
        if(heap[i].Node==node)
            return heap[i].key;
    }
    return heap[0].key;
}

void PriorityQueue::setKey(const int node,const double key){
    for(int i=0;i<=size;i++)
    {
        if(heap[i].Node==node)
          heap[i].key=key;
    }
}

void PriorityQueue::buildHeap()
{
    for (int i = capacity-1; i >= 0; i--) {
        ModifyKey(i);
    }
}
