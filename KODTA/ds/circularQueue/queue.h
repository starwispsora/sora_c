#ifndef QUEUE_H
#define QUEUE_H
//#define QUEUESIZE 100

typedef struct {
	//int array[QUEUESIZE];
	int *pArr;
	int size;
	int front;
	int rear;
} Queue;

void initQueue(Queue *pq, int size);
void cleanupQueue(Queue *pq);

void push(Queue *pq, int data);
int pop(Queue *pq);

#endif