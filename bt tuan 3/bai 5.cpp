Define MAX_SIZE <- 100
Define stack[MAX_SIZE]
Define top <- -1

Function IsEmpty():
    Return (top = -1)

Function IsFull():
    Return (top = MAX_SIZE - 1)

Function Push(value):
    If IsFull() then:
        Print "Stack is full"
        Return
    top <- top + 1
    stack[top] <- value

Function Pop():
    If IsEmpty() then:
        Print "Stack is empty"
        Return
    top <- top - 1

Function Top():
    If IsEmpty() then:
        Print "Stack is empty"
        Return NULL
    Return stack[top]
do phuc tap O(1)
