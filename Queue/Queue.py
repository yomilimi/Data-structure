#shift를 구현할 때 파이썬은 리스트 안의 요소 이동이 불가능하기 때문에
#연결리스트를 사용하여 채워지지 않은 리스트를 사라지게 했습니다.
maxsize=7 #연결리스트이기 때문에 무한하다는 점을 보완하기 위해 최대 크기를 정의하여 유한하게 했습니다,
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.head = None
        self.tail = None
        self.count = 0

    def is_empty(self):
        if self.count == 0:
            return True
        else:
            return False
    
    def is_full(self):
      global maxsize
      if maxsize==self.count:
        return True
      else:
        return False

    def enqueue(self, item):
        newnode = Node(item)
        if self.is_empty():
            self.head = self.tail = newnode
        else:
            self.tail.next = newnode
            self.tail = newnode
        self.count += 1

    def dequeue(self):
        if self.is_empty():
            print("Queue is EMPTY")
            return
        item = self.head.data
        self.head = self.head.next
        self.count -= 1
        return item

    def peek(self):
        if self.is_empty():
            print("Queue is EMPTY")
            return
        return self.head.data

    def print_queue(self):
        if self.is_empty():
            print("Queue is EMPTY")
            return
        temp = Queue()
        while not self.is_empty():
            print(self.peek(), end = ' ')
            temp.enqueue(self.dequeue())
        while not temp.is_empty():
            self.enqueue(temp.dequeue())
        print()

    def replace(self, item):
        if self.is_empty():
            print("Queue is EMPTY")
            return
        self.tail.data = item

    def is_member(self, item):
        tf = False
        temp = Queue()
        while not self.is_empty():
            if self.peek() == item:
                tf = True
            temp.enqueue(self.dequeue())
        while not temp.is_empty():
            self.enqueue(temp.dequeue())
        return tf

    def clear_queue(self):
        self.head = None
        self.tail = None
        self.count = 0

    def Head(self):
      return self.head.data #연결리스트를 사용했기 때문에 head는 무조건 맨앞이라 인덱스값 대신 요소를 반환했습니다.

    def Tail(self):
      return self.tail.data #head와 동일한 이유

    def upper(self):
        self.tail.data=self.tail.data.upper()

    def lower(self):
        self.tail.data=self.tail.data.lower()
q = Queue()
def menu():
    print("----------------Queue Menu----------------\n");
    print("+(data): enqueue\n");
    print("L: print queue\n");
    print("P: peek data\n");
    print("-: dequeue one data\n");
    print("#: data count\n");
    print("T: tail\n");
    print("H: head\n");
    print("(number)-: dequeue number of data\n");
    print("?(data): is member?\n");
    print("=(data): replace data\n");
    print("C: clear queue\n");
    print("M: veiw menu\n");
    print("U: upper case\n");
    print("l: lower case\n");
    print("Q: Quit\n");
    print("E: is empty?\n");

menu()
while True:
    m = input("")
    i = 0
    while i < len(m):
        if m[i] == '+':
          if q.is_full():
            print("Queue is full")
          else:
            q.enqueue(m[i+1])
            i += 1
        elif m[i] == '-':
            q.dequeue()
        elif m[i] == 'P':
            print("Return %c" %q.peek())
        elif m[i] == '#':
            print("%d" %q.count)
        elif m[i] == 'E':
            if q.is_empty():
                print("TRUE")
            else:
                print("FALSE")
        elif m[i] == '=':
            q.replace(m[i+1])
            i += 1
        elif m[i] == '?':
            if q.is_empty():
                print("Queue is EMPTY")
            elif q.is_member(m[i+1]):
                print("TRUE")
            else:
                print("FALSE")
            i += 1
        elif m[i] == 'C':
            q.clear_queue()
        elif m[i] == 'L':
            q.print_queue()
        elif m[i]=='F':
          if q.is_full():
              print("True")
          else:
            print("False")
        elif m[i]=='H':
          if q.is_empty():
            print("Queue is empty")
          else:
            print("%d"%q.Head())
        elif m[i]=='T':
          if q.is_empty():
            print("Queue is empty")
          else:
            print("%d" %q.Tail())
        elif m[i]=='U':
            if q.is_empty():
                print("Queue is empty")
            else:
                q.upper()
        elif m[i]=='l':
            if q.is_empty():
                print("Queue is empty")
            else:
                q.lower()
        if m[0] == 'Q':
          break
        elif m[0].isdigit():
          n=int(m[0])
          if m[1] == '-':
            for i in range(n):
              q.dequeue()
        i += 1