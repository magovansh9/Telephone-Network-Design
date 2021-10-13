//
//  Vertex.cpp
//  GraphMST
//
//  Created by Vansh Mago on 2021-04-04.
//

#include <stdio.h>
using namespace std;

#include <iostream>
#include "mstprimtest.hpp"

Vertex::Vertex()
{
    Node=0;
    key=0;
}
Vertex::Vertex(const int Node,const double key)
{
    this->Node=Node;
    this->key=key;

}
void Vertex::setKey(const double w)
{
    this->key=w;
}

