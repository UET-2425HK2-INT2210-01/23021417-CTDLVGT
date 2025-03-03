Define MAX_SIZE <- 100
Define queue[MAX_SIZE]
Define front <- -1
Define rear <- -1

Function IsEmpty():
    Return (front = -1 OR front > rear)

Function IsFull():
    Return (rear = MAX_SIZE - 1)

Function Enqueue(value):
    If IsFull() then:
        Print "Queue is full"
        Return
    If front = -1 then:
        front <- 0
    rear <- rear + 1
    queue[rear] <- value

Function Dequeue():
    If IsEmpty() then:
        Print "Queue is empty"
        Return
    front <- front + 1
    If front > rear then:
        front <- -1
        rear <- -1

Function Front():
    If IsEmpty() then:
        Print "Queue is empty"
        Return NULL
    Return queue[front]

