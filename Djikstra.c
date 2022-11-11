#include<stdlib.h>
#include<stdio.h>
#include<limits.h>  // INT_MAX

struct Node
{
    int vertex;
    struct Node *next;
    int weight;
};
typedef struct Node node;

struct Graph
{
    int NumOfVertices;
    node **adjList;
    int *distance;
};
typedef struct Graph graph;

// Your Add Edge method:

struct Set
{
   int *array;  // The set
   int front;   // Remembers the last found element
   int capacity; // Maximum number of elements
   int size;    // Current number of elements in the set / array
};
typedef struct Set set; 

int isEmpty(set *s){
    if(s->size == 0){
        return 1;
    }
    return 0;
}

void set_insert(set *s, int vertex){
    s->array[s->front] = vertex;
    s->front = s->front + 1;
}

void set_delete(set *s, int vertex){
    for( int i = 0; i < s->capacity; i++){
        if(s->array[i] == vertex){
            s->array[i] = -1;         // Set the element to 0
        }                             // If you'd like to have a resizing array, go ahead  
    }
    s->size = s->size - 1;
}

int is_inSet(set *s, int vertex){
    for( int i = 0; i < s->capacity; i++){
        if(s->array[i] == vertex){
            return 1;
        }
    }
    return 0;
}

int find_min_distance_vert(set *s, graph *g){
    int min = INT_MAX;
    for( int i = 0; i < s->capacity; i++){
        if(s->array[i] != -1){
            if(g->distance[s->array[i]] < min){
                min = i;
            }
        }
    }
    return min;
}

int findDistance(graph *g, int u, int vertex){
    node *head = g->adjList[u];

    while(head){
        if(head->vertex == vertex) return head->weight;
        head = head->next;
    }
    return -1;  // this exist condition will never be triggered
}

void clean_set(set *s){
    for( int i = 0; i < s->capacity; i++){
        s->array[i] = 0;
    }
}

void Djikstra(graph *g, set *s, int source){
    for(int i = 0; i < g->NumOfVertices; i++){
        g->distance[i] = INT_MAX;   // Inserting every vertex into the set
        set_insert(s, i);           // Assuming that vertexes are sequentially numbered
    }

    g->distance[source] = 0;

    while(isEmpty(s) != 1){
        int u = find_min_distance_vert(s, g);
        set_delete(s, u);

        if(u != INT_MAX){
            node *head = g->adjList[u];
            while(head){
                if(is_inSet(s, head->vertex) == 1){
                    int alt = g->distance[u] + findDistance(g, u, head->vertex);    // Relaxation
                    if(alt < g->distance[head->vertex]){
                        g->distance[head->vertex] = alt;
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[argc + 1]){
    // Construct your graph
    // Make sure that if your vertices are not in sequential order they are all inserted in the set
    // Here, insertion is done inside the Djikstra function 

    Djikstra(g, s, source);
}


