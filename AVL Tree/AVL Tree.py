#import collections
#min_value = -1
#max_value = -1

class Node(object):
    
    path = []
    min_value = -1
    max_value = -1

    leftAns=0
    midAns=0
    rightAns=0

    def __init__(self, data, parent=None):
        self.childs = {}
        self.data = [data]
        self.parent = parent

    def insert(self, value):
        Node.path = []
        insert_node = self.search(value)
        insert_node.add(value)

    def split(self):
        if self.parent is None and self.childs:
            branch = Node.path.pop()
            newNodeLeft = Node(self.data.pop(0), self)
            newNodeRight = Node(self.data.pop(1), self)                      
            if branch == "left":
               newNodeLeft.childs["left"] = self.childs["left"]
               newNodeLeft.childs["right"] = self.childs["overflow"]
               newNodeRight.childs["left"] = self.childs["mid"]
               newNodeRight.childs["right"] = self.childs["right"]
            elif branch == "mid":
               newNodeLeft.childs["left"] = self.childs["left"]
               newNodeLeft.childs["right"] = self.childs["mid"]
               newNodeRight.childs["left"] = self.childs["overflow"]
               newNodeRight.childs["right"] = self.childs["right"]
            elif branch == "right":
               newNodeLeft.childs["left"] = self.childs["left"]
               newNodeLeft.childs["right"] = self.childs["mid"]
               newNodeRight.childs["left"] = self.childs["right"]
               newNodeRight.childs["right"] = self.childs["overflow"]
            newNodeLeft.childs["left"].parent = newNodeLeft
            newNodeLeft.childs["right"].parent = newNodeLeft
            newNodeRight.childs["left"].parent = newNodeRight
            newNodeRight.childs["right"].parent = newNodeRight
            self.childs["left"] = newNodeLeft
            self.childs["right"] = newNodeRight
            #print('del mid childs ------')
            del self.childs["mid"]
            del self.childs["overflow"]
            #self.print_23()
            #print('dddd', self.data)
            #for i in self.childs.keys():
            #    print(i)
            #input()

        elif self.parent is not None and self.childs:
            branch = Node.path.pop()
            newNode = Node(self.data.pop(), self.parent)
            self.parent.childs["overflow"] = newNode
            if branch == "left":  
                newNode.childs["left"] = self.childs["mid"]
                newNode.childs["right"] = self.childs["right"]
                self.childs["right"] = self.childs["overflow"]
            elif branch == "mid":
                newNode.childs["left"] = self.childs["overflow"]
                newNode.childs["right"] = self.childs["right"]
                self.childs["right"] = self.childs["mid"]
            elif branch == "right":
                newNode.childs["left"] = self.childs["right"]
                newNode.childs["right"] = self.childs["overflow"]
                self.childs["right"] = self.childs["mid"]
            newNode.childs["left"].parent = newNode
            newNode.childs["right"].parent = newNode
            del self.childs["mid"]
            del self.childs["overflow"]

        elif self.parent is None and not self.childs:
            self.childs["left"] = Node(self.data.pop(0), self)
            self.childs["right"] = Node(self.data.pop(1), self)   

        elif self.parent is not None and not self.childs:
            self.parent.childs["overflow"] = Node(self.data.pop(), self.parent) 
            
                
    def add(self, value):
        if value not in self.data:
            self.data.append(value)
            self.data.sort()
            if len(self.data) == 3:
                self.split()
                if self.parent is not None:
                    self.parent.add(self.data.pop())
            else:
                if "overflow" in self.childs:
                    branch = Node.path.pop()
                    if branch == "left":
                        self.childs["mid"] = self.childs["overflow"]
                    elif branch == "right":
                        self.childs["mid"] = self.childs["right"]
                        self.childs["right"] = self.childs["overflow"]
                    del self.childs["overflow"]

    def search(self, value):   
        if self.childs:
            boundLeft = min(self.data)
            boundRight = max(self.data)
            if value < boundLeft:
                Node.path.append("left")
                return self.childs["left"].search(value)
            elif value > boundRight:
                Node.path.append("right")
                return self.childs["right"].search(value)
            else:
                Node.path.append("mid")
                return self.childs["mid"].search(value)
        else:
             return self 

    def search_value(self, value):
        if self.childs:
            boundLeft = min(self.data)
            boundRight = max(self.data)
            if value < boundLeft:
                #Node.path.append("left")
                return self.childs["left"].search_value(value)
            elif value > boundRight:
                #Node.path.append("right")
                return self.childs["right"].search_value(value)
            elif value in self.data:
                return self
            else:
                #Node.path.append("mid")
                return self.childs["mid"].search_value(value)
        else:
             return self

    def find_node(self, value):
        if self.childs:
            boundLeft = min(self.data)
            boundRight = max(self.data)
            if value < boundLeft:
                Node.path.append("LEFT")
                return self.childs["left"].find_node(value)
            elif value > boundRight:
                Node.path.append("RIGHT")
                return self.childs["right"].find_node(value)
            elif value< boundRight and value>boundLeft:
                Node.path.append("MID")
                return self.childs["MID"].find_node(value)
            elif value in self.data:
                return self
        elif value in self.data:
            return self

    def element(self, value):
        if value in self.data:
            return True
        elif self.childs:
            boundLeft = min(self.data)
            boundRight = max(self.data)
            if value < boundLeft:
                return self.childs["left"].element(value)
            elif value > boundRight:
                return self.childs["right"].element(value)
            else:
                return self.childs["mid"].element(value)
        else:
            return False

    def print_23(self):
        print(self.data, end='')
        #if self.parent != None:
         #   print('parent', self.parent.data)
        if self.childs:
            self.childs = dict(sorted(self.childs.items()))
            for i in self.childs.keys():
                #print(i, self.childs[i].data)
                if i == "left":
                    print('[', end='')
                elif i == "mid" or i== "right":
                    print("[", end='')
                self.childs[i].print_23()
        #print(self.data)
        print(']', end='')

    def get_min(self):
        if "left" in self.childs:
            self.childs["left"].get_min()
        else:
            print("mim value is: ", self.data[0])
            Node.min_value = self.data[0]

    def get_max(self):
        if "right" in self.childs:
            self.childs["right"].get_max()
        else:
            print("max value is: ", self.data[-1])
            Node.max_value = self.data[-1]

    def inorder_traversal(self):
        self.get_min()
        self.get_max()

        all_list=[]
        print(Node.min_value, Node.max_value)
        for i in range(Node.min_value, Node.max_value+1):

            if self.element(i):
                all_list.append(i)

        return all_list

    def rightorder_traversal(self):
        temp_list = self.inorder_traversal()
        temp_list.sort(reverse=True)
        return temp_list

    def get_right_child(self, value):
        if self.element(value):
            node = self.search_value(value)
            if "right" in node.childs:
                return node.childs["right"].data

        return [-1]

    def count_node(self):
        temp_list = self.inorder_traversal()
        return len(temp_list)

    def get_left_child(self, value):
        if self.element(value):
            node = self.search_value(value)
            if "left" in node.childs:
                return node.childs["left"].data

        return [-1]

    def get_mid_child(self, value1, value2):
        if self.element(value1) and self.element(value2):
            node = self.search_value(value1)
            if value2 in node.data and "mid" in node.childs:
                return node.childs["mid"].data

        return [-1]

    def init_h(self):
        Node.leftAns =0
        Node.rightAns =0
        Node.midAns =0

    def init_path(self):
        Node.path=[]

    def height(self):
        print('ans', Node.leftAns, Node.rightAns)
        if self.childs is None:
            return 0

        if "left" in self.childs:
            Node.leftAns = self.childs["left"].height()
        if "mid" in self.childs:
            Node.midAns = self.childs["mid"].height()
        if "right" in self.childs:
            Node.rightAns = self.childs["right"].height()

        return max(Node.leftAns, Node.midAns, Node.rightAns)+1

    def delete_node(self, value):
        node = self.find_node(value)
        #print(node.data, len(node.data), node.parent.data, node.childs)
        if node.childs == {} and len(node.data) == 2:
            node.data.remove(value)
        elif node.childs == {} and len(node.data) == 1:
            for i in node.parent.childs.keys():
                if value in node.parent.childs[i].data:
                    del(node.parent.childs[i])
                    break
        elif node.childs != {} and len(node.data) == 2:
            node.data.remove(value)
        elif node.childs != {} and len(node.data) == 1:
            if "right" in node.childs:
                node.data = node.childs["right"].data
                del(node.childs["right"])
                node.childs["left"].data.append(node.data)
                node.data =-1

    def height2(self):
        if self.childs != {}:
            return 1+self.childs["left"].height2()

        return 1


my23 = Node(9)
#my23.print_23()
#input()

my23.insert(5)
#my23.print_23()
#input()

my23.insert(8)
#my23.print_23()
#input()

my23.insert(3)
#my23.print_23()
#input()

my23.insert(2)
#my23.print_23()
#input()

my23.insert(4)

my23.insert(7)

my23.insert(30)
my23.insert(29)
my23.insert(14)
my23.insert(17)
my23.insert(19)
my23.insert(24)
my23.insert(22)
my23.insert(20)
my23.insert(18)
my23.init_h()
h = my23.height2()
print(h)

print()
#my23.delete_node(8)
my23.print_23()
print()