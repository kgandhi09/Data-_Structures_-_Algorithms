//============================================================================
// Name        : Dijkstra.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Dijakstra in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

bool contains(vector<int> adjNodes, int node);

int main() {


	int fieldArr[36][36]={
			{0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //0
			{1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //1
			{0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //2
			{0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //3
			{0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //4
			{0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //5
			{0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //6
			{0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //7
			{0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //8
			{0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //9
			{0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //10
			{1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //11
			{0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},  //12
			{0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},  //13
			{0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //14
			{0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //15
			{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //16
			{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //17
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},  //18
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},  //19
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},  //20
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0},  //21
			{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0},  //22
			{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},  //23
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1},  //24
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0},  //25
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0},  //26
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0},  //27
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0},  //28
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0},  //29
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},  //30
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0},  //31
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0},  //32
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0},  //33
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1},  //34
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0}   //35
	};
	int endNode;
	cout << "Enter the destination - " << endl;
	cin >> endNode;

	int startNode = 0;

	int Q[36][3];

	for(int i = 0; i < 36; i++){   // setting up queue
		Q[i][0] = -1;              // setting penultimate vertex = null / -1 for int
		if(i == startNode){
			Q[i][1] = 0;           //setting distance for source
		}
		else{
			Q[i][1] = INT_MAX;     // setting rest nodes to infinty
		}
		Q[i][2] = 0;               //setting everything not visited
	}

	for(int i = 0; i< 36; i++){


		int min = INT_MAX;    //min distance not visited in queue
		int minIndex;         // index of minimum distance
		for(int j =0; j < 36; j++){        // go through all the nodes which have Q[j][2] = 0
			if(Q[j][2] == 0){			   // checks if the node is visited or not
				if(Q[j][1] < min){
					min = Q[j][1];        //resets a new min (lesser than prev min)
					minIndex = j;		  // resets the index of min
				}
			}
		}
		Q[minIndex][2] = 1;               //sets the min node to visited


		//get adjacent nodes from matrix

		vector<int> adjacent;      // array of adjacent nodes

		for(int j = 0; j<36; j++){
			if(fieldArr[minIndex][j] > 0){
				adjacent.push_back(j);
			}
		}

		for(int j = 0; j<36; j++){
			if(Q[j][2] == 0 && contains(adjacent, j)){       //check if node is not visited and adjacent
				if(Q[minIndex][1] + fieldArr[minIndex][j] <= Q[j][1]){
					Q[j][1] = Q[minIndex][1] + fieldArr[minIndex][j];
					Q[j][0] = minIndex;
				}
			}
		}

		//int j = 0;


	}
//printing the Q
//	for(int i = 0; i < 36; i++){
//		for(int j = 0; j < 3; j++){
//			cout << Q[i][j] << " ";
//		}
//		cout << endl;
//	}

	vector<int> path;
	path.push_back(endNode);

	while(endNode != startNode){ // endNode will be mutated to penUltimate
		path.push_back(Q[endNode][0]);
		endNode = Q[endNode][0];
	}

	int size=path.size();
	for(int i=size-1;i>=0;i--){
		if(i==0){
			cout<< path[i];
		}
		else{
			cout<< path[i] << "->";
		}
	}

	return 0;
}

//contains - check if the vector contains the given node

bool contains(vector<int> adjNodes, int node){
	bool found = false;
	int size = adjNodes.size();
	for(int i = 0; i< size; i++){
		if(node == adjNodes[i]){
			found = true;
		}

	}
	return found;
}




