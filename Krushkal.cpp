#include <bits/stdc++.h>
using namespace std;
typedef struct N
{
    struct N *next;
    struct ver *orig;
    int weight;
    int vertexno;
} node;

typedef struct ver
{

    int Data;
    node *pt;

} vertex;

typedef struct gra
{

    int v;
    vertex *arr;

} graph;

typedef struct LIST
{
    int sr, des, weight;
    struct LIST *next;
} list1;

graph *create(int a)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->v = a;
    g->arr = (vertex *)malloc(sizeof(vertex) * a);
    for (int i = 0; i < a; i++)
    {
        cout<<"Enter data of"<<i + 1<<" node :" ;
        cin>>g->arr[i].Data;
        g->arr[i].pt = NULL;
    }
    return g;
}

void addconnection(graph *g, int sr, int des, int w)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->orig = &(g->arr[des - 1]);
    newnode->weight = w;
    newnode->vertexno = des;
    node *temp = g->arr[sr - 1].pt;
    newnode->next = temp;
    g->arr[sr - 1].pt = newnode;
}

void print(graph *g)
{
    cout<<"\n\nGraph is :\n";
    for (int i = 0; i < g->v; i++)
    {
        cout<<i + 1<<"node data is"<<  g->arr[i].Data <<" and is connected to : \n";
        node *temp = g->arr[i].pt;
        if (temp == NULL)
            printf("No other vertex\n");
        else
            while (temp)
            {
                cout<<temp->vertexno<<"node (Data is "<<temp->orig->Data <<") and weight of edge between them is"<<temp->weight<<endl;
                temp = temp->next;
            }
        cout<<endl;
    }
    cout<<"\n\n Graph is printed\n\n\n\n\n";
}
int find(int parent[], int i)
{
    if (parent[i] == -1)
    {
        return i;
    }
    return find(parent, parent[i]);
}

void select(graph *g, list1 *head, int n)
{
    list1 *ptr = head, *ptr1 = NULL;
    int *parent = (int *)malloc(g->v * sizeof(int));
    int i;
    memset(parent, -1, sizeof(int) * g->v);
    for (i = 0; ptr != NULL && i < n;)
    {
        int check1 = find(parent, ptr->sr - 1);
        int check2 = find(parent, ptr->des - 1);
        if (check1 != check2)
        {
            parent[ptr->des - 1] = ptr->sr - 1;
            i++;
        }
        else
        {
            ptr1->next = ptr->next;
            free(ptr);
            ptr = ptr1;
        }
        ptr1 = ptr;
        ptr = ptr->next;
        if (i == n - 1)
            ptr->next = NULL;
    }
}

list1 *sortl(list1 *head, int sr, int des, int w)
{
    if (head == NULL)
    {
        head = (list1 *)malloc(sizeof(list1));
        head->sr = sr;
        head->des = des;
        head->next = NULL;
        head->weight = w;
        return head;
    }
    if (head->weight > w)
    {
        list1 *temp = (list1 *)malloc(sizeof(list1));
        temp->sr = sr;
        temp->des = des;
        temp->next = head;
        temp->weight = w;
        return temp;
    }
    head->next = sortl(head->next, sr, des, w);
    return head;
}

list1 *make_list(graph *g)
{
    list1 *head = NULL;
    for (int i = 0; i < g->v; i++)
    {
        node *temp = g->arr[i].pt;
        if (temp != NULL)
            while (temp)
            {
                head = sortl(head, i + 1, temp->vertexno, temp->weight);
                temp = temp->next;
            }
    }
    return head;
}
void printlist(list1 *head)
{
    if (head == NULL)
        return;
    cout<<"edge: "<<head->sr<< "--"<<head->des<<"  weight : "<<head->weight<<endl;
    printlist(head->next);
}
int main()
{
    int v;
   cout<<"Enter No. of Nodes/vertex of graph \n";
    cin>>v;
    graph *Graph = create(v);
    while (1)
    {
        int ch, sr, des, weight;
        cout<<"Enter 1 to add connection and 0 to exit:\n";
        cin>>ch;
        if (ch == 0)
            break;
        cout<<"Enter Node No.s to be connected and edge weight:\n";
        cin >> sr>> des >> weight;
        addconnection(Graph, sr, des, weight);
    }
    print(Graph);
    list1 *head = make_list(Graph);
    select(Graph, head, v - 1);
    printlist(head);
    return 0;
}