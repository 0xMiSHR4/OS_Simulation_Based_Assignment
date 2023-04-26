# OS_Simulation_Based_Assignment
Simulation Based Assignment_Operating System - 6

Question/ Problem Statement:

Ajay Kalia is a Banking Expert who wants to have an online system where he can handle customer queries. Since there can be multiple requests at any time he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time. He will log into the system from 9am to 1pm only. He wants to have separate requests queues for regular customers and new customers. Implement a strategy for the same. The summary at the end of the session should include the total time he spent on handling queries and average query time.

Scenario:

1. Ajay Kalia is a Banking Expert who wants to have an online system where he can handle customer queries.
2. He will log into the system from 9am to 1pm only.
3. He wants to have separate requests queues for regular customers and new customers.

Problem:

1. Since there can be multiple requests at any time he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time.
2. The summary at the end of the session should include the total time he spent on handling queries and average query time.

Methodology Adopted to Solve the Problem:

This C code implements a simple simulation of a queueing system to process requests from two queues: regular_people and new_people. The code uses a queue data structure to store and manage the requests.

The code defines two structs: person and queue. The person struct represents a person with three attributes: id (an integer representing the person's ID), arrival_time (an integer representing the time the person arrived), and remaining_time (an integer representing the remaining time required to process the person's request). The queue struct represents a queue of persons, with an array of persons p, and two integer variables front and rear representing the front and rear indices of the queue, respectively.

The code provides several functions to operate on the queue:

init_queue(struct queue *q): Initializes an empty queue by setting both front and rear to -1.

enqueue(struct queue *q, struct person x): Adds a person x to the rear of the queue q, unless the queue is full (i.e., rear is equal to MAX - 1).

struct person dequeue(struct queue *q): Removes and returns the person from the front of the queue q, unless the queue is empty (i.e., front is equal to rear).

int size(struct queue *q): Returns the number of persons in the queue q, calculated as the difference between rear and front.

The main() function is the entry point of the program and implements the simulation of the queueing system. It creates two queues: regular_people and new_people, and initializes them using the init_queue() function. Then, it adds four persons to the queues with different arrival times and remaining times using the enqueue() function.

The simulation uses a time-based approach to process requests. It starts with an initial time spent of 0 and a quantum of 10 (representing the maximum time that can be spent processing a request at a time). It uses a while loop to simulate the passage of time and processes requests in the queues accordingly.

Inside the while loop, it first checks if the total time spent has exceeded 240 minutes (the condition time_spent >= 240). If so, it prints a message and breaks out of the loop.

Then, it checks if there are any persons in the new_people queue whose arrival time is less than or equal to the current time spent (time_spent). If so, it dequeues such persons from the new_people queue and enqueues them into the regular_people queue, assuming they have become regular customers.

Next, it processes requests from the regular_people queue. It dequeues persons from the regular_people queue one by one as long as their arrival time is less than or equal to the current time spent. For each person, it prints a message indicating the processing of their request, and updates the time spent and remaining time for the person accordingly. If the remaining time for the person is greater than the quantum, the person is enqueued back into the regular_people queue. Otherwise, the person's remaining time is set to 0, indicating that their request has been fully processed.

The simulation continues until both the regular_people and new_people queues are empty. After the while loop, it calculates the total time spent and the average query time per request (mdf) by dividing the total time spent by the total number of requests, and prints the results.

Finally, the program returns 0, indicating successful execution.
