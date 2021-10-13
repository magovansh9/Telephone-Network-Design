//
//  mstprimtest.cpp
//  GraphMST
//
//  Created by Vansh Mago on 2021-04-02.
//
#include <iostream>
#include "mstprimtest.hpp"
#include <string>
#include <iomanip>
using namespace std;

int main()

{
    string input{""};
    int nodeNum{0};
    cin>>input>>nodeNum;
    cout<<"success"<<endl;
    GraphMST graph(nodeNum);

    while(input.compare("exit")!=0)
    {
        cin>>input;

         if (input=="i")
        {
            string input_string;
            cin.ignore();
            getline(cin,input_string);
            int a,b;
            double c;
            int x= input_string.find(";",1);
            int y= input_string.find(";",x+1);
            a=stoi(input_string.substr(0,x));
            b=stoi(input_string.substr(x+1,y));
            c=stod(input_string.substr(y+1,input_string.length()-1));

            try {
                cout<<graph.insert(a,b,c)<<endl;
            }
            catch(illegal_exception)
            {
                cout<<"illegal argument"<<endl;
            }


        }
        else if (input=="e")
        {
            string input_string;
            cin.ignore();
            getline(cin,input_string);
            int a,b;
            int x= input_string.find(";",1);
            a=stoi(input_string.substr(0,x));
            b=stoi(input_string.substr(x+1,input_string.length()-1));
            try {
                cout<<graph.erase(a,b)<<endl;
            }
            catch(illegal_exception)
            {
                cout<<"illegal argument"<<endl;
            }
        }
        else if (input=="adjacent")
        {

            string input_string;
            cin.ignore();
            getline(cin,input_string);
            int a,b;
            double c;
            int x= input_string.find(";",1);
            int y= input_string.find(";",x+1);
            a=stoi(input_string.substr(0,x));
            b=stoi(input_string.substr(x+1,y));
            c=stod(input_string.substr(y+1,input_string.length()-1));
            try {
                graph.adjacent(a,b,c);
            }
            catch(illegal_exception)
            {
                cout<<"illegal argument"<<endl;
            }

        }
        else if (input=="degree")
        {
            int node{0};
            cin>>node;
            try {
                cout<<graph.degree(node)<<endl;
            }
            catch(illegal_exception)
            {
                cout<<"illegal argument"<<endl;
            }

        }

        else if (input=="edge_count")
        {
            cout<<graph.edge_count()<<endl;
        }

        else if (input=="clear")
        {
            graph.clear();
            cout<<"success"<<endl;
        }
        else if (input=="mst")
        {
            int u{0};
            cin>>u;

            try {
                 graph.mst(u);
            }
            catch(illegal_exception)
            {
                cout<<"illegal argument"<<endl;
            }

        }

    }
}

