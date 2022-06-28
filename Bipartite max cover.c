#include <iostream>
#define MAX 10
using namespace std;

int graph[MAX][MAX],setB[MAX];
char setA[MAX];
int A,B;

bool bipartiteMatch(int u, bool *visited, int *matchR) {
   for (int v = 0; v < B; v++) {
      if (graph[u][v] && !visited[v]) {
         visited[v] = true;
         if (matchR[v] < 0 || bipartiteMatch(matchR[v], visited, matchR)) {
            matchR[v] = u;
            return true;
         }
      }
   }
   return false;
}

int maxMatch() {
    int matchR[A];
    bool visited[A];

    for(int i = 0; i<A; i++){
        matchR[i] = -1;
    }

    int result = 0;

     for (int u=0; u<A; u++) {
        for(int i=0; i<A; i++) visited[i] = false;
        if(bipartiteMatch(u, visited, matchR)) result++;
     }

     cout<<"Matched vertices set = {";
     for(int i=0; i<A; i++){
        cout<<"("<<setA[i]<<", "<<setB[matchR[i]]<<")";
        if(i != A-1) cout<<", ";
     }
     cout<<"}";

     return result;
}

int main() {
    int x;
    cout<<"Enter number of vertices in setA and setB of bipartite graph\n";
    cin>>A>>B;

    cout<<"Enter vertices of setA:(ENTER ALPHABETS FOR VERTICES OF SET A)\n ";
    for(int i=0; i<A; i++) cin>>setA[i];

    cout<<"Enter vertices of setB:(ENTER NUMBERS FOR VERTICES OF SET B)\n";
    for(int i=0; i<B; i++) cin>>setB[i];

    cout<<"Enter adjacency matrix \n";
    for(int i=0; i<A; i++){
        for(int j=0; j<B; j++){
            cin>>graph[i][j];
        }
    }

    x=maxMatch();
    cout<<"\nMaximum number of matching is " <<x;

    return 0;
}

