#include<iostream>
#include<queue>
using namespace std;

bool hasPath(int ** edges, int n, int sv, int ev,bool* visited){
    if(edges[sv][ev] == 1)
        return true;
    visited[sv] = true;
    for(int i = 0; i<n; i++){
        if(visited[i] == false){
            bool ans = hasPath(edges,n,i,ev,visited);
            if(ans){
                return true;
            }
        }
    }
    return false;
}
bool DFSHasPath(int** edges, int n, int sv, int ev){
    bool* visited = new bool[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }
    for(int i = 0; i<n; i++){
        if(!visited[i] && i == sv)
            return hasPath(edges, n, i,ev,visited);
    }
    return false;
}

void printDFS(int** edges, int n, int sv, bool* visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for(int i = 0; i<n; i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}
void printBFS(int** edges, int n, int sv, bool* visited){
    queue<int>q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        cout<<t<<" ";
        for(int i = 0; i<n; i++){
            if(i == t){
                continue;
            }
            if(edges[t][i] == 1){
                if(visited[i]){
                    continue;
                }
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int** edges, int n){
    bool* visited = new bool[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }
    for(int i = 0; i<n; i++){
        if(!visited[i])
            printDFS(edges, n, i,visited);
    }
}

void BFS(int** edges,int n){
    bool* visited = new bool[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }
    for(int i = 0; i<n; i++){
        if(!visited[i])
            printBFS(edges, n, i,visited);
    }
}


int main()
{
    int n,sv,ev;
    int e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i = 0; i<n; i++){
        edges[i] = new int[n];
        for(int j = 0; j<n; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i<e; i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    cin>>sv>>ev;
    bool *visited = new bool[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }

    /*
    BFS(edges, n);
    cout<<endl;
    DFS(edges, n);*/
    cout<<hasPath(edges,n,sv,ev,visited)<<endl;

    for(int i = 0; i<n; i++)
        delete[] edges[i];
    delete[] edges;
    return 0;
}
