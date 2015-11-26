/* implementation of graph using adjacency matrix */
#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;                         // subfix to represent vertex
typedef int Weight;                         // use int to represent weight
typedef char DataType;                      // data type of vertex data

/* definition of edge */
typedef struct Enode *Edge;
struct Enode {
    Vertex vr;                              // row subfix
    Vertex vc;                              // col subfix
    Weight w;                               // weight of the edge
};
/* definition of graph */
typedef struct Gnode *MGraph;
struct Gnode {
    int vertex_num;
    int edge_num;
    Weight G[MaxVertexNum][MaxVertexNum];   // the adjacency matix
    DataType Data[MaxVertexNum];            // data saved on vertexes
};

MGragh CreateGraph(int vn)                  // vn for vertex number
{
    /* initialize a graph with vn vertexes but no edges */
    Vertex i, j;
    MGraph Graph = (MGraph)malloc(sizeof(struct Gnode));
    Graph->vertex_num = vn;
    Graph->edge_num = 0;
    /* initialize the adjacency matrix */
    for (i = 0; i < vn; i++)
        for (j = 0; j < vn; j++)
            Graph->G[i][j] = INFINITY;
    return Graph;
}

void InsertEdge(MGraph g, Edge e)
{
    g->G[e->vr][e->vc] = e->w;
    g->G[e->vc][e->vr] = e->w; // if graph is undirected add this line
}