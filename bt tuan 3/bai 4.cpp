Class Node:
    data
    next

Class Queue:
    front <- NULL
    rear <- NULL

Function IsEmpty():
    Return (front = NULL)

Function Enqueue(value):
    node <- new Node(value)
    If IsEmpty() then:
        front <- node
        rear <- node
    Else:
        rear.next <- node
        rear <- node

Function Dequeue():
    If IsEmpty() then:
        Print "Queue is empty"
        Return
    front <- front.next
    If front = NULL then:
        rear <- NULL

Function Front():
    If IsEmpty() then:
        Print "Queue is empty"
        Return NULL
    Return front.data
do phuc tap O(1)
