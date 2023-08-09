class Node(object):
    def __init__(self, data, prev=None, next=None):
        self.data = data
        self.prev = prev
        self.next = next


class DoubleLinkedList(object):
    def __init__(self):
        self.head = None
        self.cur=None
        self.tail = self.head

    def addTail(self, data):
        if self.head is None:
            self.head = Node(data)
            self.tail = self.head
            self.cur = self.head
        else:
            node=self.tail
            new_node = Node(data,prev=node)
            node.next = new_node
            self.tail = new_node
            self.cur = new_node

    def pt(self):
        if self.head==None:
            print('LinkedList is empty')
        else:
            n=self.head
            while n!=None:
                if n==self.cur:
                    print("(%s) "%n.data,end='')
                else:
                    print("%s "%n.data,end='')
                n=n.next
            print()

    def getdata(self):
        if self.head==None:
            print('LinkedList is empty')
        else:
            print("(%s) "%self.cur.data)
        
    def delete(self):
        if self.head==None:
            print('LinkedList is empty')
            
        else:
            if self.cur.next==None and self.cur.prev!=None:
                self.cur.prev.next=None
                self.tail=self.cur.prev
                self.cur=self.head
                self.head=self.cur
            elif self.cur.prev==None and self.cur.next!=None:
                self.cur.next.prev=None
                self.cur=self.cur.next
                self.head=self.cur
                self.cur=self.head
            elif self.cur.next==None and self.cur.prev==None:
                self.cur=None
                self.head=None
            else:
                self.cur.prev.next=self.cur.next
                self.cur.next.prev=self.cur.prev
                self.cur=self.cur.next
                if self.cur.next==None:
                    self.tail=self.cur
        
    
    def add(self, data):
        if self.head is None:
            self.head = Node(data)
            self.tail = self.head
            self.cur=self.head
        elif self.cur.prev is None:
            new_node=Node(data)
            self.cur.prev=new_node
            new_node.next=self.cur
            new_node.prev=None
            self.cur=new_node
            self.head=new_node
        else:
            new_node=Node(data)
            self.cur.prev.next=new_node
            new_node.next=self.cur
            new_node.prev=self.cur.prev
            self.cur.prev=new_node
            self.cur=new_node
            

    def addd(self, data):
        if self.cur.next is None:
            new_node=Node(data)
            self.cur.next=new_node
            new_node.prev=self.cur
            new_node.next=None
            self.cur=new_node
        else:
            new_node=Node(data)
            self.cur.next.prev=new_node
            new_node.prev=self.cur
            new_node.next=self.cur.next
            self.cur.next=new_node
            self.cur=new_node
            
    def traversefront(self):
        if self.head is None:
            print('LinkedList is empty')
        else:
            self.cur=self.head

    def traversefrontmove(self,n):
        DL.traversefront()
        for i in range(n):
            self.cur=self.cur.next
            if self.cur.next==None:
                self.tail=self.cur
    
    def addfirst(self, data):
        if self.is_empty():
            self.head = Node(data)
            self.tail = Node(None, self.head)
            self.head.next = self.tail
            self.cur=self.head
        else:
            tmp = self.head
            self.head = Node(data, None, self.head)
            tmp.prev = self.head
            self.cur=self.head

    def traverserear(self):
        if DL.is_empty()==1:
            print("LinkedList is empty")
        else:
            self.cur=self.tail

    def replace(self,data):
        if DL.is_empty()==1:
            print("LinkedList is empty")
        else:
            if self.cur.prev==None:
                new_node=Node(data)
                self.cur.next.prev=new_node
                new_node.next=self.cur.next
                new_node.prev=None
                self.cur=new_node
                self.head=new_node
            elif self.cur.next==None:
                new_node=Node(data)
                self.cur.prev.next=new_node
                self.cur.prev=new_node.prev
                new_node.next=None
                self.cur=new_node
                self.tail=new_node
            else:
                new_node=Node(data)
                self.cur.prev.next=new_node
                new_node.prev=self.cur.prev
                new_node.next=self.cur.next
                self.cur.next.prev=new_node
                self.cur=new_node
            DL.pt()
            
    def index(self,data):
        if DL.is_empty()==1:
            print("LinkedList is empty")
        else:
            x=int(data)-1
            y=1;
            self.cur=self.head
            while self.cur.next!=None:
                y+=1
                self.cur=self.cur.next
        
        
            if x+1>y:
                raise IndexError('index exceed')

            if x<0:
                raise IndexError('index is less than range')
            
            if x+1<=y and x>=0:
                self.cur=self.head
                for i in range(x):
                    self.cur=self.cur.next
                    if self.cur.next==None:
                        self.tail=self.cur

    def find(self,data):
        if DL.is_empty()==1:
            print("LinkedList is empty")
        else:
            c=1
            self.cur=self.head
            while True:
                if self.head.data==data:
                    print("%d번째에 %s가 있습니다"%(c,data))
                    c=0
                    break
                elif self.cur.data==data:
                    print("%d번째에 %s가 있습니다"%(c,data))
                    break
                if self.cur.next==None:
                    if self.cur.data==data:
                        print("%d번째에 %s가 있습니다"%(c,data))
                        break
                    else:
                        print("리스트에 %s가 없습니다"%data)
                        break
                self.cur=self.cur.next
                c+=1
        

    def datacount(self):
        if DL.is_empty()==1:
            print("LinkedList is empty")
        else:
            node = self.head
            cnt = 0
            while node is not None:
                cnt += 1
                node = node.next
            print(cnt)

    def clear(self):
        if DL.is_empty()==1:
            print("LinkedList is already empty")
        
        else:
            self.cur=self.head
            if self.cur.next==None and self.cur.prev!=None:
                self.cur.prev.next=None
                self.tail=self.cur.prev
                self.cur=self.head
                self.head=self.cur
            elif self.cur.prev==None and self.cur.next!=None:
                self.cur.next.prev=None
                self.cur=self.cur.next
                self.head=self.cur
                self.cur=self.head
            elif self.cur.next==None and self.cur.prev==None:
                self.cur=None
                self.head=None
            else:
                self.cur.prev.next=self.cur.next
                self.cur.next.prev=self.cur.prev
                self.cur=self.cur.next
                if slef.cur.next.next==None:
                    self.tail=self.cur.next
            self.head=None
            print("list is clear")
            
    def is_empty(self):
        if self.head==None:
            return 1
        else:
            return 0

    def upper(self):
        self.cur.data=self.cur.data.upper()

    def lower(self):
        self.cur.data=self.cur.data.lower()

def menu():
    print("========================menu========================")
    print("addTail                          : t +(data)")
    print("print                            : L\n")
    print("get data                         : G\n")
    print("traverse front                   : <(N)\n")
    print("(N은 다음 인덱스로 한 칸 이동을 뜻)\n")
    print("delete                           : -\n")
    print("add current position             : +(data)\n")
    print("add next position                : N +(data)\n")
    print("delete last                      : > -\n")
    print("add first position               : < +(data)\n")
    print("replace current position         : =(data)\n")
    print("get designated position data     : (index)G\n")
    print("data count                       : #\n")
    print("is member                        : ?(data)\n")
    print("replace designated position data : (index)=(data)\n")
    print("clear the list                   : C\n")
    print("is empty                         : E\n")
    print("upper case                       : U\n")
    print("lower case                       : l\n")
    print("view menu                        : M\n")
    print("Quit                             : Q\n")
        
DL=DoubleLinkedList()
menu()
while True:
    m=input()
    if m[0]=='t':
        for i in range(len(m)):
            if(m[i]=='+'):
                DL.addTail(m[i+1])
        DL.pt()

    elif m[0]=='L':
        DL.pt()
        
    elif m[0]=='G':
        DL.getdata()
        
    elif m[0]=='<':
        n=0
        if len(m)==1:
            DL.traversefront()
        else:
            for i in range(len(m)):
                if i==2:
                    if m[i]=='+':
                        DL.addfirst(m[i+1])
                if i>2:
                    if m[i]=='+':
                        DL.addd(m[i+1])
                if m[i]=='N':
                    n+=1
        if n>0:
            DL.traversefrontmove(n)
        DL.pt()
        
    elif m[0]=='-':
        DL.delete()
        DL.pt()
        
    elif m[0]=='+':
        for i in range(len(m)):
            if i==0:
                if m[i]=='+':
                    DL.add(m[i+1])
            else:
                if m[i]=='+':
                    DL.addd(m[i+1])
        DL.pt()

    elif m[0]=='N':
        for i in range(len(m)):
            if m[i]=='+':
                DL.addd(m[i+1])
        DL.pt()

    elif m[0]=='>':
        if m[2]=='-':
            DL.traverserear()
            DL.delete()
        else:
            DL.traverserear()
        DL.pt()

    elif m[0]=='=':
        DL.replace(m[1])

    elif m[0]=='?':
        DL.find(m[1])

    elif m[0]=='#':
        DL.datacount()

    elif m[0]=='C':
        DL.clear()

    elif m[0]=='E':
        if DL.is_empty()==1:
            print("TRUE")
        else:
            print("FALSE")

    elif m[0]=='U':
        DL.upper()
        DL.pt()
        
    elif m[0]=='l':
        DL.lower()
        DL.pt()

    elif m[0]=='M':
        DL.menu()

    elif m[0]=='Q':
        break
        
    else:
        DL.index(m[0])
        if m[1]=='G':   
            DL.getdata()
        if m[1]=='=':
            DL.replace(m[2])
            
