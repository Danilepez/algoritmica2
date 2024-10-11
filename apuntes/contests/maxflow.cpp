#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 
#define MAX_N 101       

int grafo[MAX_N][MAX_N];   
int path[MAX_N]; 
int maxFlow(int s,int t) { 
    int maxFlow = 0;
    while(true) { 
        memset(path, -1, sizeof(path)); 
        queue<int> Q;
        Q.push(s);
        path[s] = s;  
        while(!Q.empty() && path[t]==-1) {
            int currentNode = Q.front();
            Q.pop();
            for(int i = 0 ; i < MAX_N ; i++) {
                if(grafo[currentNode][i] > 0 && path[i]==-1)  {  
                    path[i] = currentNode;                      
                    Q.push(i);                                
                }   
            }
        }
       
        if(path[t]==-1) { 
            break; 
        }
        int minFlow = 1e9; 
        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {
            minFlow = min(minFlow,grafo[from][to]); 
        }                                          
        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {
            grafo[from][to] -= minFlow; 
            grafo[to][from] += minFlow; 
        }
        maxFlow += minFlow;
    }
    return maxFlow;
}



int main() {
int nodes, aristas, nroCases, speed; 
while(cin>>nodes && nodes) {
    int s = 1;
    int t = nodes;   
    cin>>aristas;
    memset(grafo,0,sizeof(grafo));
     for(int i=0;i<aristas;i++) {
        int from, to;
        long long capacity; 
        cin>>from>>to;
        cin>>capacity;
        grafo[from][to] = capacity;       
        grafo[to][from] = 0;              
    }
    cout<<maxFlow(s,t)<<endl;
    }    
}