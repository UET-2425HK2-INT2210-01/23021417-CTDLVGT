Class Node:
    data
    next

Class Stack:
    top <- NULL

Function IsEmpty():
    Return (top = NULL)

Function Push(value):
    node <- new Node(value)
    node.next <- top
    top <- node

Function Pop():
    If IsEmpty() then:
        Print "Stack is empty"
        Return
    top <- top.next

Function Top():
    If IsEmpty() then:
        Print "Stack is empty"
        Return NULL
    Return top.data
do phuc tap O(1)
