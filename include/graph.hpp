/*
 * @Author: Peng Liu
 * @Date: 2024-06-02 16:56:34
 * @LastEditTime: 2024-06-02 21:03:21
 * @Description: 
 * 
 * Copyright (c) 2024 by Data Warehouse and Business Intelligence Laboratory(DW&BI) of Renmin University of China(RUC), All Rights Reserved. 
 */
#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdio.h>
#include <limits.h>
using namespace std;

namespace matrix{

template<class V, class W,  bool Direction = false>
class Graph{
	private: 
		//vertex set
		vector<V> vertex;
		//edge set
		vector<vector<W>> edgeMatrix;
		//the index of vertex to position
		map<V, int> indexMap;

	public:
		//no params construct
		Graph(){}
		//construct
		Graph(const V * vertx, size_t n){
			vertex.reserve(n);

			for(int i = 0; i < n; ++i){
				vertex.push_back(vertx[i]);
				indexMap[vertx[i]] = i;
			}

			edgeMatrix.reserve(n);
			for(auto & it : edgeMatrix){
				it.resize(n, INT_MIN);
			}
		}

		Graph(size_t n){
			vertex.reserve(n);
			for(int i = 0; i < n; ++i){
				vertex.push_back(i);
			}

			edgeMatrix.reserve(n);
			for(auto & it : edgeMatrix){
				it.resize(n, INT_MAX);
			}
		}


		void add_edge(const V & src, const V & dest, const W & weight){
			size_t srcIndex = getVertexIndex(src);
			size_t destIndex = getVertexIndex(dest);
			cout<<"srcIndex:"<<srcIndex<<" "<<"destIndex:"<<destIndex<<endl;

			edgeMatrix[srcIndex][destIndex] = weight;

			cout<<"edge matrix is:"<<edgeMatrix[srcIndex][destIndex]<<endl;
			if(Direction == false){
				edgeMatrix[destIndex][srcIndex] = weight;
			}

		}

		size_t getVertexIndex(const V & v){
			auto it = indexMap.find(v);
			if(it != indexMap.end()){
				return it->second;
			}else{
				throw invalid_argument("vertex is not exist!");
				return -1;
			}
		}

		void printGraph(){
			cout<<" ";
			for(int i = 0; i < vertex.size(); ++i){
				cout<<i<<" ";
			}
			cout<<endl;

			for(int i = 0; i < edgeMatrix.size(); ++i){
				cout<<i<<" ";
				for(int j = 0; j < edgeMatrix[i].size(); ++j){
					if(edgeMatrix[i][j] != INT_MAX){
						cout<<edgeMatrix[i][j]<<" ";	
					}else{
						cout<<"~";
					}
				}
				cout<<endl;
			}
			cout<<endl;
		}
	
};

}