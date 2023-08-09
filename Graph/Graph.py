import collections

def insert_vertex(g, v):
    g[v]

def search_vertex(g, v):
    if v in g:
        return 1
    else:
        return 0

def add_edge(g, v1, v2):
    g[v1].append(v2)
    g[v2].append(v1)

def print_graph(g):
    print("(",end="")
    for i in g.keys():
        if len(g[i])>0:
            print(i,end='(')
            for j in g[i]:
                print(j,end='')
            print(')', end=' ')
        else:
            print(i,end=' ')
    print(")")

def degree_of_vertex(g, v):
    return len(g[v])

def is_connected(g):
    eg=0
    for i in g.keys():
        if len(g[i])>0:
            eg+=1
    if eg>=len(g.keys()):
        return 1
    else:
        return 0

def is_empty(g):
    if len(g.keys())==0:
        return 1
    else:
        return 0

def adjacent(g, v):
    if len(g[v])>0:
        for i in g[v]:
            print(i,end=' ')
    else:
        print("No adjacent",end='')
    print()

def delete_vertex(g, v):
    for i in g.keys():
        if v in g[i]:
            idx=g[i].index(v)
            del g[i][idx]
                    
    del g[v]

def path_exist(g, v1, v2):
    if v2 in g[v1]:
        return 1
    else:
        for i in g:
            if v1 in g[i]:
                if v2 in g[i]:
                    return 1
    return 0

def num_of_vertex(g):
    return len(g.keys())

def num_of_edge(g):
    ne=0
    for i in g.keys():
            ne+=len(g[i])
    return int(ne/2)

def search_edge(g, v1, v2):
    if v2 in g[v1] and v1 in g[v2]:
        return 1
    else:
        return 0

def delete_edge(g, v1, v2):
    g[v1].remove(v2)
    g[v2].remove(v1)

def rename_vertex(g,ov,nv):
  new_graph=collections.defaultdict(list)
  for i in g.keys():
    for j in g[i]:
      if j==ov:
        idx=g[i].index(ov)
        g[i][idx]=nv
    if i==ov:
      new_graph[nv] = g[i]
    else:
      new_graph[i] = g[i]
  
  return new_graph

def clear_graph(g):
    g.clear()

def menu():
    print("+data: insert vertex")
    print("E(datadata): insert edge")
    print("L: print graph")
    print("V: degree of vertex")
    print("C: is connected?")
    print("N: is empty?")
    print("A: adjacent")
    print("-data: delete vertex")
    print("P(datadata): path exist?")
    print("X: number of vertex")
    print("H: number of edge")
    print("D: delete edge")
    print("R(datadata): rename_vertex")
    print("K: clear graph")
    print("Q: quit")

menu()
graph=collections.defaultdict(list)
while True:
    m=input(">>")
    if m[0]=='+':
        insert_vertex(graph,m[1])
        
    elif m[0]=='E':
        v1=search_vertex(graph, m[2])
        v2=search_vertex(graph, m[3])
        if v1==0 or v2==0:
            print("Not exist")
        else:
            add_edge(graph,m[2], m[3])

    elif m[0]=='L':
        if is_empty(graph)==1:
            print("Graph is empty")
        else:
            print_graph(graph)

    elif m[0]=='V':
        if search_vertex(graph,m[2])==1:
            print(degree_of_vertex(graph,m[2]))
        else:
            print("Not exist")

    elif m[0]=='C':
        if is_connected(graph)==1:
            print("True")
        else:
            print("False")

    elif m[0]=='N':
        if is_empty(graph)==1:
            print("True")
        else:
            print("False")

    elif m[0]=='A':
        if search_vertex(graph, m[2])==1:
            adjacent(graph,m[2])
        else:
            print("Not exist")

    elif m[0]=='-':
        if search_vertex(graph, m[1])==1:
            delete_vertex(graph,m[1])
        else:
            print("Not exist")

    elif m[0]=='P':
        v1=search_vertex(graph, m[2])
        v2=search_vertex(graph, m[3])
        if v1==0 or v2==0:
            print("Not exist")
        else:
            if path_exist(graph,m[2],m[3])==1:
                print("True")
            else:
                print("False")

    elif m[0]=='X':
        if is_empty(graph)==0:
            print(num_of_vertex(graph))
        else:
            print("No data")

    elif m[0]=='H':
        if is_empty(graph)==0:
            print(num_of_edge(graph))
        else:
            print("No data")

    elif m[0]=='D':
        v1=search_vertex(graph, m[2])
        v2=search_vertex(graph, m[3])
        if v1==0 or v2==0:
            print("Not exist")
        else:
            if search_edge(graph,m[2],m[3])==1:
                delete_edge(graph, m[2], m[3])
            else:
                print("No edge")

    elif m[0]=='R':
        if search_vertex(graph, m[2])==0:
            print("Not exist")
        else:
            graph=rename_vertex(graph,m[2],m[3])

    elif m[0]=='K':
        clear_graph(graph)

    elif m[0]=='Q':
        break