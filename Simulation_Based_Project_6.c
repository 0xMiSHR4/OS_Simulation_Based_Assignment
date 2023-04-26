#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct customer {
    int id;
    int arrival_time;
    int remaining_time;
};

struct queue {
    struct customer c[MAX];
    int front;
    int rear;
};

void init_queue(struct queue *q) {
    q->front = q->rear = -1;
}

void enqueue(struct queue *q, struct customer x) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->c[q->rear] = x;
}

struct customer dequeue(struct queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        exit(0);
    }
    q->front++;
    struct customer x = q->c[q->front];
    return x;
}

int size(struct queue *q) {
    return q->rear - q->front;
}
    
int main() {
    int cust_id=0;
    struct queue regular_customers, new_customers;
   init_queue(&regular_customers);
    init_queue(&new_customers);

   // add customers to the queues
    struct customer c1 = {1, 0, 100};
    enqueue(&regular_customers, c1);
    struct customer c2 = {2, 1, 15};
    enqueue(&new_customers, c2);
    
    // add more customersa
    struct customer c3 = {3, 2, 20};
    enqueue(&regular_customers, c3);
    struct customer c4 = {4, 3, 25};
    enqueue(&new_customers, c4);

    
    
    // calculate total number of requests
    int total_requests = size(&regular_customers) + size(&new_customers);
    
    // process requests
    int time_spent = 0;
    
    while (size(&regular_customers) > 0 || size(&new_customers) > 0) {
        if (time_spent >= 240) {
        printf("Total time spent has exceeded 240\n");
        break;
    }
        if (size(&regular_customers) > 0) {
            struct customer c = dequeue(&regular_customers);
            printf("Processing request from regular customer %d\n", c.id);
            
            if (c.remaining_time > 10) {
                time_spent += 10; // fixed time slice for each request
                printf("The time spent in handling query form customer %d is %d out of 240 minutes from the beginning \n", c.id,time_spent);
                c.remaining_time -= 10;
                enqueue(&regular_customers, c); // add the customer back to the end of the queue
            } else {
                time_spent += c.remaining_time;
                printf("The time spent in handling query form customer %d is %d out of 240 minutes from the beginning \n", c.id,time_spent);
                c.remaining_time = 0;
               printf("The time spent in handling query form customer %d is %d out of 240 minutes from the beginning \n", c.id,time_spent);
            }
        }
        
        if (size(&new_customers) > 0) {
            struct customer c = dequeue(&new_customers);
            printf("Processing request from new customer %d\n", c.id);
            
            if (c.remaining_time > 10) {
                time_spent += 10; // fixed time slice for each request
                printf("The time spent in handling query form customer %d is %d out of 240 minutes from the beginning \n", c.id,time_spent);
                c.remaining_time -= 10;
                enqueue(&new_customers, c); // add the customer back to the end of the queue
            } else {
                time_spent += c.remaining_time;
                printf("The time spent in handling query form customer %d is %d out of 240 minutes from the beginning \n", c.id,time_spent);
                c.remaining_time = 0;
                printf("Finished processing request from new customer %d\n", c.id);
            }
        }
    }
    
    printf("Total time spent: %d minutes\n", time_spent);
    
    float mdf = (float) time_spent / total_requests;
    
    printf("Average query time: %.2f minutes\n", mdf );
    
    return 0;
}
