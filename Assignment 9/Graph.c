#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
int vert, edge;
int adjMatrix[10][10];


void addEdge(int x, int y)
    {
        // checks if the vertex exists in the graph
        if ((x >= vert) || (y > vert)) 
		{
            printf("Vertex does not exists");
        }
 
        // checks if the vertex is connecting to itself
        if (x == y) {
            printf("Same Vertex!");
        }
        else {
            // connecting the vertices
            adjMatrix[y][x] = 1;
            adjMatrix[x][y] = 1;
        }
    }

void createGraph(int vert)
{
	int i,j;
	for (i = 0; i < vert; ++i) 
	{
            for (j = 0; j < vert; ++j) 
			{
                adjMatrix[i][j] = 0;
            }
	}
	printf("Enter the number of edges:");
	scanf("%d",&edge);
	printf("Enter the edges:");
	for(i=0;i<edge;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		addEdge(a,b);
	}
}

void bfs(int source, int vert)
{
	int queue[MAX],i;
	int rear = -1;
	int front = 0;
	int queueItemCount = 0;
	int visited[vert];
	for(i=0;i<vert;i++)
		visited[i]=0;
	visited[source]=1;
	printf("%d",source);
	queue[++rear]=source;
	queueItemCount++;
	int unvisitedVertex;
	
	bool isQueueEmpty() 
	{
		return queueItemCount == 0;
	}
	
	int removeData() 
	{
		queueItemCount--;
		return queue[front++]; 
	}
   
   int getAdjUnvisitedVertex(int vertexIndex)
   {
   		int i;
   		for(i = 0; i<vert; i++) 
		{
      			if(adjMatrix[vertexIndex][i] == 1 && visited[i] == 0)
        			return i;
   		}
  		return -1;
}
	
	

	while(!isQueueEmpty())
	{
      //get the unvisited vertex of vertex which is at front of the queue
      int tempVertex = removeData();   

      //no adjacent vertex found
      while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1)
	  {    
    	visited[unvisitedVertex] = 1;
        printf("%d",unvisitedVertex);
        queue[++rear]=unvisitedVertex;
		queueItemCount++;              
      }
   }   

   //queue is empty, search is complete, reset the visited flag        
   for(i = 0;i<vert;i++) 
   {
      visited[i] = 0;
   }    	
}


void dfs(int source, int vert)
{
	int i;
	int visited[vert];
	for(i=0;i<vert;i++)
		visited[i]=0;
	visited[source]=1;
	int stack[MAX]; 
	int top = -1; 
	
	//stack push function
	void push(int item) 
	{ 
   		stack[++top] = item; 
	}
	
	//stack pop function
	int pop() 
	{ 
   		return stack[top--]; 
	} 
	
	//A boolean function that tells whether the stack is empty or not
	bool isStackEmpty() 
	{
   		return top == -1;
	}
	
	//custom function to get the nextunvisited vertex adjacent to 'vertexIndex'
	int getAdjUnvisitedVertex(int vertexIndex)
	{
		int i;
		for(i = 0; i<vert; i++) 
		{
			if(adjMatrix[vertexIndex][i] == 1 && visited[i] == 0)
				return i;
		}
   		return -1;
	}
	printf("%d", source);
	push(source);
	
	while(!isStackEmpty()) {
      //get the unvisited vertex of vertex which is at top of the stack
      int unvisitedVertex = getAdjUnvisitedVertex(stack[top]);

      //no adjacent vertex found
      	if(unvisitedVertex == -1) 
	  {
      		  pop();
     	 } 
	else 
	  {
      	  visited[unvisitedVertex] = 1;
      	  printf("%d",unvisitedVertex);
       	  push(unvisitedVertex);
     	 }
   }

   //stack is empty, search is complete, reset the visited flag        
   for(i = 0;i < vert;i++) 
   {
   		visited[i] = 0;
   }
}


//main driver function
void main()
{
	printf("Enter the number of vertices:");
	scanf("%d",&vert);
	createGraph(vert);
	printf("Performing BFS:");
	bfs(0, vert);
	printf("\nPerforming DFS:\n");
	dfs(0, vert);
}
