import collections
graph=collections.defaultdict(list)
def insert_vertex(g, v):
    g[v]

def search_vertex(g, v):
    if v in g:
        return 1
    else:
        return 0

def add_edge(g, v1, v2):
    g[v1[0]].append(v2)
    g[v2[0]].append(v1)

def print_graph(g):
    print("(",end="")
    for i in g.keys():
        if len(g[i])>0:
            print(i,end='(')
            print(g[i], end='')
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
            print(i[0],end=' ')
    else:
        print("No adjacent",end='')
    print()

def delete_vertex(g, v):
    for i in g.keys():
        for j in g[i]:
            if v == j[0]:
                g[i].remove(j)

    del g[v]

def path_exist(g, v1, v2):
    for i in g[v1]:
        if i[0] == v2: 
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
    for j in g[v1]:
        if v2== j[0]:
            return 1
    return 0

def delete_edge(g, v1, v2):
    for j in g[v1]:
        if v2 == j[0]:
             g[v1].remove(j)

    for j in g[v2]:
        if v1 == j[0]:
             g[v2].remove(j)

def rename_vertex(g,ov,nv):
    new_graph=collections.defaultdict(list)
    for i in g.keys():
        for j in g[i]:
          if j[0]==ov:
            j[0]=nv
        if i==ov:
          new_graph[nv] = g[i]
        else:
          new_graph[i] = g[i]
  
    return new_graph
    

def clear_graph(g):
    g.clear()

def change_weight(g,v1,v2,w):
    for j in g[v1]:
        if v2==j[0]:
            j[1]=w
    for j in g[v2]:
        if v1==j[0]:
            j[1]=w
  

def menu():
    print("+data: insert vertex")
    print("E(data,data,weighted value): insert edge **가중치**")
    print("L: print graph")
    print("V(data): degree of vertex")
    print("C: is connected?")
    print("N: is empty?")
    print("A(data): adjacent")
    print("-data: delete vertex")
    print("P(data,data): path exist?")
    print("X: number of vertex")
    print("H: number of edge")
    print("D(data,data): delete edge")
    print("R(data,new name,weighted value): rename_vertex")
    print("K: clear graph")
    print("Q: quit")
    print("M(data,data,new weiht): change weight ***가중치를 위한 기능 추가함***")

menu()
while True:
    m=input(">>")
    if m[0]=='+':
        insert_vertex(graph,m[1:])
        
    elif m[0]=='E':
        nums = m[2:-1].split(',')
        v1=search_vertex(graph, nums[0])
        v2=search_vertex(graph, nums[1])
        if v1==0 or v2==0:
            print("Not exist")
        else:
            add_edge(graph,[nums[0],nums[2]], [nums[1], nums[2]])

    elif m[0]=='L':
        if is_empty(graph)==1:
            print("Graph is empty")
        else:
            print_graph(graph)

    elif m[0]=='V':
        if search_vertex(graph,m[2:-1])==1:
            print(degree_of_vertex(graph,m[2:-1]))
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
        if search_vertex(graph, m[2:-1])==1:
            adjacent(graph,m[2:-1])
        else:
            print("Not exist")

    elif m[0]=='-':
        if search_vertex(graph, m[1:])==1:
            delete_vertex(graph,m[1:])
        else:
            print("Not exist")

    elif m[0]=='P':
        nums = m[2:-1].split(',')
        v1=search_vertex(graph, nums[0])
        v2=search_vertex(graph, nums[1])
        if v1==0 or v2==0:
            print("Not exist")
        else:
            if path_exist(graph,nums[0],nums[1])==1:
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
        nums = m[2:-1].split(',')
        v1=search_vertex(graph, nums[0])
        v2=search_vertex(graph, nums[1])
        if v1==0 or v2==0:
            print("Not exist")
        else:
            if search_edge(graph,nums[0],nums[1])==1:
                delete_edge(graph, nums[0], nums[1])
            else:
                print("No edge")

    elif m[0]=='R':
        nums = m[2:-1].split(',')
        if search_vertex(graph, nums[0])==0:
            print("Not exist")
        else:
            graph=rename_vertex(graph,nums[0],nums[1])

    elif m[0]=='K':
        clear_graph(graph)

    elif m[0]=='Q':
        break

    elif m[0]=='M':
        nums=m[2:-1].split(',')
        
        if search_edge(graph, nums[0],nums[1])==0:
            print("Not exist")
        else:
            change_weight(graph, nums[0], nums[1],nums[2])