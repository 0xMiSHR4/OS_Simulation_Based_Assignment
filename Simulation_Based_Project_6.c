#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct person {
    int id;
    int arrival_time;
    int remaining_time;
};

struct queue {
    struct person p[MAX];
    int front;
    int rear;
};

void init_queue(struct queue *q) {
    q->front = q->rear = -1;
}

void enqueue(struct queue *q, struct person x) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->p[q->rear] = x;
}

struct person dequeue(struct queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        exit(0);
    }
    q->front++;
    struct person x = q->p[q->front];
    return x;
}

int size(struct queue *q) {
    return q->rear - q->front;
}

int main() {
    int person_id = 0;
    struct queue regular_people, new_people;
    init_queue(&regular_people);
    init_queue(&new_people);

    // add people to the queues
    struct person p1 = {1, 0, 100};
    enqueue(&regular_people, p1);
    struct person p2 = {2, 1, 15};
    enqueue(&new_people, p2);

    // add more people
    struct person p3 = {3, 2, 20};
    enqueue(&regular_people, p3);
    struct person p4 = {4, 3, 25};
    enqueue(&new_people, p4);

    // calculate total number of requests
    int total_requests = size(&regular_people) + size(&new_people);

    // process requests
    int time_spent = 0;
    int quantum = 10;

    while (size(&regular_people) > 0 || size(&new_people) > 0) {
        if (time_spent >= 240) {
            printf("Total time spent has exceeded 240\n");
            break;
        }

        // check if there are any new people waiting
        if (size(&new_people) > 0 && time_spent >= new_people.front->arrival_time) {
            struct person p = dequeue(&new_people);
            enqueue(&regular_people, p);
        }

        // process regular people
        while (size(&regular_people) > 0 && time_spent >= regular_people.front->arrival_time) {
            struct person p = dequeue(&regular_people);
            printf("Processing request from regular person %d\n", p.id);

            if (p.remaining_time > quantum) {
                time_spent += quantum;
                p.remaining_time -= quantum;
                enqueue(&regular_people, p);
            } else {
                time_spent += p.remaining_time;
                p.remaining_time = 0;
                printf("Finished processing request from regular person %d\n", p.id);
            }
        }
    }

    printf("Total time spent: %d minutes\n", time_spent);

    float mdf = (float) time_spent / total_requests;

    printf("Average query time: %.2f minutes\n", mdf);

    return 0;
}