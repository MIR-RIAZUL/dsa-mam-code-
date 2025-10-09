#include<iostream>
#include<stack>
#include<queue>
#define V 7
using namespace std;

void initialize(int arr[][V])
{
    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            arr[i][j]=0;
}

// Creates an edge src->des
void addEdge(int arr[][V], int src, int des)
{
    arr[src][des]=1;
    arr[des][src]=1; //Undirected
}

void display(int arr[][V])
{
    for(int i=0; i<V; i++)
    {
        cout<<i<<": ";
        for(int j=0; j<V; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

//visited[0] = true

void DFS(int arr[][V])
{
    bool visited[V] = {false};
    stack<int> st;

    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            st.push(i);
            while(!st.empty())
            {
                int vertex = st.top();
                st.pop();
                if(!visited[vertex])
                {
                    visited[vertex]=true;
                    cout<<vertex<<" ";
                    for(int j=V-1; j>=0; j--)
                    {
                        if(arr[vertex][j]==1 && !visited[j])
                        {
                            st.push(j);
                        }
                    }
                }
            }
        }
    }
    cout<<endl;
}

void BFS(int arr[][V])
{
    bool visited[V] = {false};
    queue<int> q;
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            q.push(i);
            visited[i] = true;
            while(!q.empty())
            {
                int vertex = q.front();
                q.pop();
                cout<<vertex<<" ";
                for(int j=0; j<V; j++)
                {
                    if(arr[vertex][j]==1 && !visited[j])
                    {
                        q.push(j);
                        visited[j]=true;
                    }
                }
            }
        }
    }
    cout<<endl;
}

int main()
{
    int adjMatrix[V][V];
    initialize(adjMatrix);

    addEdge(adjMatrix,0,1);
    addEdge(adjMatrix,0,3);
    addEdge(adjMatrix,1,2);
    addEdge(adjMatrix,1,3);
    addEdge(adjMatrix,2,4);
    addEdge(adjMatrix,2,6);
    addEdge(adjMatrix,4,5);
    addEdge(adjMatrix,4,6);

    display(adjMatrix);

    cout<<"DFS"<<endl;
    DFS(adjMatrix);

    cout<<"BFS"<<endl;
    BFS(adjMatrix);
}
