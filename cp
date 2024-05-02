
# Define a large value to represent infinity
INF = 9999999

# Number of vertices in the graph
N = 5

# Creating the graph using the adjacency matrix method
G = [[0, 2, 7, 0, 0],
     [2, 0, 1, 5, 0],
     [7, 1, 0, 4, 3],
     [0, 5, 4, 0, 2],
     [0, 0, 3, 2, 0]]

# Initialize a list to keep track of selected nodes
selected_node = [0, 0, 0, 0, 0]

# Initialize variables for total weight and number of edges
total_weight = 0
no_edge = 0

# Select the first node to start
selected_node[0] = True

# Print the edge and weight
print("Edge : Weight\n")

# Continue until all edges are selected
while no_edge < N - 1:
    
    # Initialize the minimum weight to infinity
    minimum = INF
    a = 0
    b = 0
    
    # Find the minimum weight edge that connects a selected node to an unselected node
    for m in range(N):
        if selected_node[m]:
            for n in range(N):
                if (not selected_node[n]) and G[m][n]:  
                    # If the node is unselected and there is an edge
                    if minimum > G[m][n]:
                        minimum = G[m][n]
                        a = m
                        b = n
                        
    # Print the selected edge and its weight
    print(str(a) + "-" + str(b) + ":" + str(G[a][b]))
    
    # Update total weight
    total_weight += G[a][b]
    
    # Mark the selected node as True
    selected_node[b] = True
    
    # Increment the number of edges
    no_edge += 1

# Print the total weight of the minimum spanning tree
print("Total weight:", total_weight)














# Define a large value to represent infinity
INF = 9999999

# Number of vertices in the graph
N = 5

# Creating the graph using the adjacency matrix method
G = [[0, 2, 7, 0, 0],
     [2, 0, 1, 5, 0],
     [7, 1, 0, 4, 3],
     [0, 5, 4, 0, 2],
     [0, 0, 3, 2, 0]]

# Function to find the parent of a node using the union-find algorithm
def find(parent, i):
    while parent[i] != i:
        i = parent[i]
    return i

# Function to perform union of two sets
def union(parent, rank, x, y):
    xroot = find(parent, x)
    yroot = find(parent, y)

    if rank[xroot] < rank[yroot]:
        parent[xroot] = yroot
    elif rank[xroot] > rank[yroot]:
        parent[yroot] = xroot
    else:
        parent[yroot] = xroot
        rank[xroot] += 1

# Kruskal's algorithm to find the minimum spanning tree
def kruskal(graph):
    result = []  # Initialize an empty list to store the edges of the minimum spanning tree
    i = 0  # Initialize an index for sorted edges
    e = 0  # Initialize an index for result[]

    # Sort all the edges of the graph in non-decreasing order of their weight
    graph = sorted(graph, key=lambda item: item[2])

    # Create subsets for each node with rank and parent
    parent = []
    rank = []

    for node in range(N):
        parent.append(node)
        rank.append(0)

    # Loop until the number of edges equals N-1
    while e < N - 1:
        # Select the smallest edge and increment the index for sorted edges
        u, v, w = graph[i]
        i += 1
        x = find(parent, u)
        y = find(parent, v)

        # If including this edge does not form a cycle, include it in the result
        if x != y:
            e += 1
            result.append((u, v, w))
            union(parent, rank, x, y)

    return result

# Run Kruskal's algorithm
minimum_spanning_tree = kruskal([(i, j, G[i][j]) for i in range(N) for j in range(i+1, N) if G[i][j] != 0])

# Print the minimum spanning tree
print("Minimum Spanning Tree:")
for edge in minimum_spanning_tree:
    print(edge)
