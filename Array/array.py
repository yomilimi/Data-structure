def INSERT(M,Arr,Ci):
  for i in range(len(M)):
    if M[i]=="+":
      if len(Arr)==0:
        Ci=0
      else :
        Ci+=1
      Arr.insert(Ci,M[i+1])
  return Ci
  
def TRAVERSE_FRONT(M,Arr,Ci):
  Ci=0
  Nip=0;
  for i in range(len(M)):
    if M[i]=="N":
      Ci+=1
    if M[i]=='M':
      if M[i+1]=='n':
        np=len(Arr)-1
      elif M[i+1]=='P':
        np=Ci-1
      elif M[i+1]=='N':
        np=Ci+1
      else:
        np=int(M[i+1])
      if np<Ci:
        Arr.insert(np,Arr[Ci])
        del Arr[Ci+1]
        Ci=int(np)
      else:
        np=np+1
        Arr.insert(np,Arr[Ci])
        del Arr[Ci]
        Ci=np-1
  return Ci
  
def TRAVERSE_REAR_DELETE(M,Arr,Ci):
  Ci=len(arr)-1
  for i in range(len(M)):
      if M[i]=="P":
        Ci-=1
      if M[i]=='-':
        del Arr[Ci]
        Ci=0 
  return Ci

def DELETE(Arr,Ci):
  if(Ci==(len(Arr)-1)):
    del Arr[Ci]
    Ci=0
  else:
    del Arr[Ci]
  return Ci

def GET_DATA(arr,ci):
  print('Return',arr[ci])

def REPLACE(M,Arr,Ci):
  Arr.insert(Ci,M[1])
  del Arr[Ci+1]
  return Ci
  
def EMPTY(arr):
  arr.clear()
  print("empty array")

def MOVE(Arr,Np,Ci):
  if Np<Ci:
    Arr.insert(Np,Arr[Ci])
    del Arr[Ci+1]
    Ci=int(Np)
  else:
    Np=Np+1
    Arr.insert(Np,Arr[Ci])
    del Arr[Ci]
    Ci=Np-1
  return Ci

def DATA_COUNT(Arr):
  return len(Arr)

def UPPER(Arr,Ci):
  return Arr[Ci].upper()

def LOWER(Arr,Ci):
  return Arr[Ci].lower()

def pt():
  for i in range(len(arr)):
      if i==ci:
        print("(%s) "%arr[i],end='')
      else:
        print("%s "%arr[i],end='')
  print()

def V():
    print("----------MENU----------\n")
    print("INSERT               : +(data)\n")
    print("TRAVERSE_FRONT       : <(N)\n")
    print("TRAVERSE_REAR        : >(P)\n")
    print("DELETE               : -\n")
    print("DELETE THE LAST      : > -(띄어쓰세요)\n")
    print("GET_DATA             : @\n")
    print("REPLACE              : =(data)(붙여쓰세요)\n")
    print("EMPTY                : E\n")
    print("TRAVERSE_FRONT&&MOVE : < M(POSITION)\n")
    print("<과 M은 띄어쓰고 M과 POSITION은 붙여쓰세요\n")
    print("MOVE                 : M(POSITION)(붙여쓰세요)\n")
    print("MOVE END             : Mn(붙여쓰세요)\n")
    print("MOVE PREV            : Mp(붙여쓰세요)\n")
    print("MOVE NEXT            : MN(붙여쓰세요)\n")
    print("PRINT                : L\n")
    print("VIEW                 : V\n")
    print("UPPER CASE           : U\n")
    print("LOWER CASE           : l\n")
    print("END                  : B\n")
arr=[]
ci=0;
V()
while True:
  m=input()
  if m[0]=="+":
    ci=INSERT(m,arr,ci)
    pt()
  elif m[0]=="<":
    ci=TRAVERSE_FRONT(m,arr,ci)
    pt()
  elif m[0]==">":
    ci=TRAVERSE_REAR_DELETE(m,arr,ci)
    pt()
  if m[0]=='-':
    ci=DELETE(arr,ci)
    pt()
  if m[0]=='@':
    GET_DATA(arr,ci)
  if m[0]=='=':
    ci=REPLACE(m,arr,ci)
    pt()
  if m[0]=='E':
    EMPTY(arr)
  if m[0]=='M':
    if m[1]=='n':
      np=DATA_COUNT(arr)-1
    elif m[1]=='P':
      np=ci-1
    elif m[1]=='N':
      np=ci+1
    else:
      np=int(m[1])
    ci=MOVE(arr,np,ci)
    pt()
  if m[0]=='L':
    pt()
  if m[0]=='V':
    V()
  if m[0]=='U':
    arr[ci]=UPPER(arr,ci)
    pt()
  if m[0]=='l':
    arr[ci]=LOWER(arr,ci)
    pt()
  if m[0]=='B':
    break;