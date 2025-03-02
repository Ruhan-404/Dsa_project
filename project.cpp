#include<bits/stdc++.h>
using namespace std;

struct Edge{int src,dest,weight;};

class Graph{
    int V;
   
    vector<vector<pair<int,int>>>adj;
    
    
    vector<Edge>edges;

public:
    Graph(int V){this->V=V;adj.resize(V);}

    void addEdge(int u,int v,int w){
        h
        adj[u].push_back({v,w});
        
           edges.push_back({u,v,w});
    }

    void dijkstra(int src){
        vector<int>dist(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[src]=0;pq.push({0,src});

        while(!pq.empty()){
                
                
            int u=pq.top().second;
               pq.pop();
            for(auto it=adj[u].begin();it!=adj[u].end();++it){
                   int v=it->first,weight=it->second;
        
                if(dist[u]+weight<dist[v]){
                      dist[v]=dist[u]+weight;
                    pq.push({dist[v],v});
                }
            }
        }
        cout<<"Dijkstra's Shortest Paths from Source "<<src<<":"<<endl;
        
        
        
        for(int i=0;i<V;i++)
            
            
            cout<<"To "<<i<<" -> "<<(dist[i]==INT_MAX?"Unreachable":to_string(dist[i]))<<endl;
    }

    void bellmanFord(int src){
      
      
        vector<int>dist(V,INT_MAX);
                    dist[src]=0;
                    
        for(int i=0;i<V-1;i++)
            
            for(size_t j=0;j<edges.size();j++){
                
                
                        int u=edges[j].src,v=edges[j].dest,weight=edges[j].weight;
                if(dist[u]!=INT_MAX&&dist[u]+weight<dist[v])dist[v]=dist[u]+weight;
            }

        for(size_t j=0;j<edges.size();j++){
            
            
                    int u=edges[j].src,v=edges[j].dest,weight=edges[j].weight;
            if(dist[u]!=INT_MAX&&dist[u]+weight<dist[v]){
                    
                    
                cout<<"Graph contains a negative weight cycle!"<<endl;
            
                return;
            }
        }

        cout<<"Bellman-Ford Shortest Paths from Source "<<src<<":"<<endl;
        
        for(int i=0;i<V;i++)
           
            cout<<"To "<<i<<" -> "<<(dist[i]==INT_MAX?"Unreachable":to_string(dist[i]))<<endl;
    }
};

int main(){
    int V,E;
    cout<<"Enter number of cities(vertices) and routes(edges): ";
    cin>>V>>E;
     
     Graph g(V);

    cout<<"Enter routes(source destination cost):"<<endl;
    for(int i=0;i<E;i++){
     
        int u,v,w;
        cin>>u>>v>>w;
        
        g.addEdge(u,v,w);
    }

    int src;
    cout<<"Enter starting city: ";
   
    cin>>src;

    cout<<"Choose Algorithm: 1)Dijkstra 2)Bellman-Ford: ";
    
    int choice;
    cin>>choice;

    if(choice==1)g.dijkstra(src);
    
    else if(choice==2)g.bellmanFord(src);
    else cout<<"Invalid choice!"<<endl;

    return 0;
}
