/*
 * @Author: Peng Liu
 * @Date: 2024-06-02 16:39:37
 * @LastEditTime: 2024-06-02 20:57:11
 * @Description: 
 * 
 * Copyright (c) 2024 by Data Warehouse and Business Intelligence Laboratory(DW&BI) of Renmin University of China(RUC), All Rights Reserved. 
 */
#include <iostream>
#include "include/graph.hpp"
using namespace std;

void TestGraph(){

    int  a[] = {0,1,2,3,4};

    matrix::Graph<int, int, false> graph(a, 5);
    
    matrix::Graph<int, int, false> graph_init(6);

    cout<<"init have finished!"<<endl;
    //添加元素的时候发生错误
    graph.add_edge(0, 1, 1.0);  
    graph.add_edge(0, 2, 0.4);  
    graph.add_edge(0, 3, 1.0);  
    graph.add_edge(0, 4, 0.8);  
    graph.add_edge(1, 2, 0.4);  
    graph.add_edge(1, 4, 0.1);  
    graph.add_edge(2, 3, 0.7);  

    graph.printGraph();
		
}

int main(){
    TestGraph();
    return 0;
}