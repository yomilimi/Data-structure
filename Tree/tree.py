def menu():
    print("+data: make root node")
    print("+data(data): insert child node")
    print("-data: delete node")
    print("=data(datadata): insert sibling")
    print("P(data): get parent")
    print("C(data): get child")
    print("S(data): get sibling")
    print("A(data): get ancestors")
    print("D: get descendants")
    print("L: level of tree / L(data): level of data")
    print("G: degree of tree / G(data): degree of data")
    print("#: count node")
    print("K: clear tree")
    print("T: print tree")
    print("Q: QUIT")
    print("J(newrootrootroot): join tree")
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None  # child
        self.right = None  # sibling


class Tree:
    def __init__(self):
        self.root = None
        self.count = 0
        self.level = 0
        self.degree = 0

    def insert_child(self, parent, item):
        node = Node(item)

        if parent.left is None:
            parent.left = node

        else:
            cur = parent.left
            while cur.right is not None:
                cur = cur.right
            cur.right = node

        self.count += 1

    def insert_sibling(self, sib, item):
        node = Node(item)
        cur = sib
        while cur.right is not None:
            cur = cur.right
        cur.right = node

        self.count += 1

    def print_tree(self, node1, node2):
        cur = node2.left
        if node1 is node2:
            print(node1.data, end='')

        if node1.left is None:
            print()
            return
        print("(", end='')

        while cur is not None:
            print(cur.data, end='')
            if cur.left is not None:
                self.print_tree(node1, cur)
            if cur.right is not None:
                print(",", end='')
            cur = cur.right

        print(")", end='')
        if node1 is node2:
            print()

    def search_node(self, node, item):
        if node is None:
            return
        if node.data == item:
            return node

        cur = self.search_node(node.left, item)
        if cur is not None:
            return cur
        cur = self.search_node(node.right, item)
        if cur is not None:
            return cur

        return None

    def get_parent_bt(self, root, node):
        if root is None:
            return None
        if root.left is node or root.right is node:
            return root
        cur = self.get_parent_bt(root.left, node)
        if cur is not None:
            return cur
        cur = self.get_parent_bt(root.right, node)
        if cur is not None:
            return cur
        return None

    def is_leftchild(self, parent, node):
        if parent.left is node:
            return True
        else:
            return False

    def is_rightchild(self, parent, node):
        if parent.right is node:
            return True
        else:
            return False

    def get_parent(self, root, node):
        if self.get_parent_bt(root, node) is None:
            return None

        cur = node
        while not self.is_leftchild(self.get_parent_bt(root, cur), cur):
            cur = self.get_parent_bt(root, cur)
        return self.get_parent_bt(root, cur)

    def get_child(self, parent):
        if parent.left is None:
            print("NO CHILD")
            return

        cur = parent.left
        while cur is not None:
            print(cur.data, end='')
            cur = cur.right
        print()

    def get_sibling(self, root, node):
        cur = self.get_parent(root, node)
        if cur is None:
            print("{} IS ROOT NODE".format(node.data))
            return
        cur = cur.left
        while cur is not None:
            if cur.data != node.data:
                print(cur.data, end='')
            cur = cur.right
        print()

    def level_of_node(self, root, node):
        level = 0
        cur = node
        while cur is not root:
            cur = self.get_parent(root, cur)
            level += 1
        return level

    def level_of_tree(self, root, node):
        if node is not None:
            self.level_of_tree(root, node.left)
            self.level_of_tree(root, node.right)
            if self.level_of_node(root, node) > self.level:
                self.level = self.level_of_node(root, node)
        return

    def delete_node(self, root, node):
        if node.left is not None:
            print("ERROR")
            return

        parent = self.get_parent_bt(root, node)

        if node.right is None:
            if self.is_leftchild(parent, node):
                parent.left = None
            else:
                parent.right = None

        else:
            child = node.right
            if self.is_leftchild(parent, node):
                parent.left = child
            else:
                parent.right = child

    def get_ancestors(self, node):
        if self.root is node:
            print("NO ANCESTORS")
            return
        cur = node
        while cur is not self.root:
            cur = self.get_parent(self.root, cur)
            print(cur.data, end='')
        print()

    def get_descendants(self, node):
        temp = node.data
        node.data = ''
        self.print_tree(node, node)
        node.data = temp

    def degree_of_node(self, node):
        degree = 0
        cur = node.left
        while cur is not None:
            degree += 1
            cur = cur.right
        return degree

    def degree_of_tree(self, root):
        if root is not None:
            self.degree_of_tree(root.left)
            self.degree_of_tree(root.right)
            if self.degree_of_node(root) > self.degree:
                self.degree = self.degree_of_node(root)
        return

    def count_child(self, node):
        if node is None:
            return -1
        elif node.left == 0:
            return 0
        else:
            num = 0
            cur = node.left
            while cur is not None:
                cur = cur.right
                num += 1
            return num



def copy_tree(root):
    if root is not None:
        newnode = Node(root.data)
        newnode.left = copy_tree(root.left)
        newnode.right = copy_tree(root.right)
        return newnode
    return None


def join_trees(newroot, root1, root2):
    node1 = copy_tree(root1)
    node2 = copy_tree(root2)
    newroot.left = node1
    node1.right = node2
    return newroot


trees = []
idx = -1
menu()
is_binary = int(input("choose binary tree 1/ genaral tree 0: "))
while True:
    enter = input(">> ")
    enter += ' '
    if enter[0] == 'Q':
        break
    i = 0
    while i < len(enter):
        if enter[i] == '+':
            if enter[i + 2] == '(':
                node = trees[idx].search_node(trees[idx].root, enter[i + 1])
                if node is None:
                    print("Not exist")
                else:
                    i += 3
                    while enter[i] != ')':
                        if is_binary == 1 and trees[idx].count_child(node) == 2:
                            print("ERROR")
                            break
                        trees[idx].insert_child(node, enter[i])
                        i += 1
                while enter[i] != ')':
                    i += 1
            else:
                root = Node(enter[i + 1])
                tree = Tree()
                tree.root = root
                trees.append(tree)
                idx = len(trees) - 1
                i += 1
              
        elif enter[i] == '-':
            node = trees[idx].search_node(trees[idx].root, enter[i + 1])
            if node is None:
                print("Not exist")
            else:
                trees[idx].delete_node(trees[idx].root, node)
            i += 1
          
        elif enter[i] == '=':
            node = trees[idx].search_node(trees[idx].root, enter[i + 1])
            if node is None:
                print("Not exist")
            else:
                i += 3
                while enter[i] != ')':
                    if is_binary == 1 and trees[idx].count_child(trees[idx].get_parent(node)) == 2:
                        print("ERROR")
                        break
                    trees[idx].insert_sibling(node, enter[i])
                    i += 1
            while enter[i] != ')':
                i += 1

        elif enter[i] == 'P':
            parent = trees[idx].get_parent(trees[idx].root, trees[idx].search_node(trees[idx].root, enter[i + 2]))
            if parent is None:
                print("ERROR")
            else:
                print(parent.data)
            i += 3
          
        elif enter[i] == 'C':
            if trees[idx].search_node(trees[idx].root, enter[i + 2]) is None:
                print("Not exist")
            else:
                trees[idx].get_child(trees[idx].search_node(trees[idx].root, enter[i + 2]))
            i += 3

        elif enter[i] == 'S':
            node = trees[idx].search_node(trees[idx].root, enter[i+2])
            if node is None:
                print("Not exist")
            else:
                trees[idx].get_sibling(trees[idx].root, node)
            i += 3
          
        elif enter[i] == 'A':
            node = trees[idx].search_node(trees[idx].root, enter[i+2])
            if node is None:
                print("Not exist")
            else:
                trees[idx].get_ancestors(node)
            i += 3
          
        elif enter[i] == 'D':
            node = trees[idx].search_node(trees[idx].root, enter[i+2])
            if node is None:
                print("Not exist")
            else:
                trees[idx].get_descendants(node)
            i += 3
          
        elif enter[i] == 'L':
            if enter[i+1] == '(':
                node = trees[idx].search_node(trees[idx].root, enter[i+2])
                if node is None:
                    print("Not exist")
                else:
                    print("LEVEL: %d" %trees[idx].level_of_node(trees[idx].root, node))
                i += 3
            else:
                trees[idx].level_of_tree(trees[idx].root, trees[idx].root)
                print("LEVEL: %d"%trees[idx].level)
              
        elif enter[i] == 'G':
            if enter[i+1] == '(':
                node = trees[idx].search_node(trees[idx].root, enter[i+2])
                if node is None:
                    print("Not exist")
                else:
                    print("DEGREE: %d"%trees[idx].degree_of_node(node))
                i += 3
            else:
                trees[idx].degree_of_tree(trees[idx].root)
                print("DEGREE: %d"%trees[idx].degree)
              
        elif enter[i] == '#':
            if enter[i+1] == '(':
                node = trees[idx].search_node(trees[idx].root, enter[i+2])
                if node is None:
                    print("Not exist")
                else:
                    print("CHILD NODE: %d"%trees[idx].count_child(node))
                i += 3
            else:
                print("NODE COUNT: %d"%trees[idx].count)
              
        elif enter[i] == 'K':
            if idx == -1:
                print("NO TREE")
            else:
                trees.pop(idx)
                idx -= 1

        elif enter[i] == 'T':
            if idx == -1:
                print("Not exist")
            else:
                trees[idx].print_tree(trees[idx].root, trees[idx].root)

        elif enter[i] == 'J':
            idx1 = -1
            idx2 = -1
            cnt1 = 0
            cnt2 = 0
            for j in range(len(trees)):
                if trees[j].root.data == enter[i+3]:
                    idx1 = j
                    cnt1 = trees[j].count
                elif trees[j].root.data == enter[i+4]:
                    idx2 = j
                    cnt2 = trees[j].count
            if idx1 == -1 or idx2 == -1:
                print("ERROR")
            else:
                newtree = Tree()
                newroot = Node(enter[i+2])
                newtree.root = newroot
                join_trees(newroot, trees[idx1].root, trees[idx2].root)
                newtree.count = cnt1 + cnt2 + 1
                trees.append(newtree)
                idx = len(trees) - 1
            i += 5
        i += 1