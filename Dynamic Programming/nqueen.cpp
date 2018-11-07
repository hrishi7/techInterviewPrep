#include<iostream>
#define INF 1000000
#define n 4
using namespace std;

//time complexity v^3 and space complexity v^2
int** getShortestDistanceMat(int distanceMatrix[][n]){

    int **distance = new int*[n];
    for(int i = 0; i<n; i++)
        distance[i] = new int[n];

    int **path = new int*[n];
    for(int i = 0; i<n; i++)
        path[i] = new int[n];

        for (int i=0; i < n; i++) {
            for (int j=0; j< n; j++){
                distance[i][j] = distanceMatrix[i][j];
                if (distanceMatrix[i][j] != INF && i != j) {//if there is an path
                    path[i][j] = i;
                } else {
                    path[i][j] = -1;//if there is no path
                }
            }
        }
//k is intermediate node and we check if there is an path via k in full graph matrix
//if there is an path then check if via k path is taking less cost so we update path materix..
//and return graph with minimum cost
        for(int k=0; k < n; k++){
            for(int i=0; i < n; i++){
                for(int j=0; j < n; j++){
                    if(distance[i][k] == INF || distance[k][j] == INF) {
                        continue;
                    }
                    if(distance[i][j] > distance[i][k] + distance[k][j]){
                        distance[i][j] = distance[i][k] + distance[k][j];
                        path[i][j] = path[k][j];
                    }
                }
            }
        }
     return distance;
}


int main(){
    int graph[n][n] = {
                {0,   3,   6,   15},
                {INF, 0,  -2,   INF},
                {INF, INF, 0,   2},
                {1,   INF, INF, 0}
        };
    int **distance = new int*[n];
    for(int i = 0; i<n; i++)
        distance[i] = new int[n];

        cout<<"Previously it is :"<<endl;
        for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cout<<graph[i][j]<<"\t\t";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Minimum Distance matrix"<<endl;
    distance = getShortestDistanceMat(graph);
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cout<<distance[i][j]<<"  ";
        }
        cout<<endl;
    }



}
