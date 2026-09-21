#include <iostream>                      // Include the iostream library for input/output (cin, cout)
#include <vector>                        // Include the vector library so we can use the dynamic array container
using namespace std;                     // Bring the std namespace into scope so we can write cout instead of std::cout
                                         // (blank line for readability)
#define MAX 5                            // Define a macro MAX with the value 5, the maximum capacity of our queue

int main(){                              // Program entry point; everything inside runs when the program starts
    vector<int> queue(MAX);              // Create an integer vector named 'queue' with MAX (5) default-initialized slots

    int first = -1,rear = -1;            // Declare two ints: 'first' (front index) and 'rear' (back index), both -1 meaning empty
                                         // (blank line for readability)
                                         // (blank line for readability)
    if(rear == MAX - 1){                 // Check if the queue is full: rear has reached the last valid index (MAX-1 = 4)
        cout << "The queue is overflow"; // If full, print an overflow message
    }                                    // End of the overflow check block
    else {                               // If the queue is NOT full, we can safely insert a new element
        if(first == -1){                 // Check if the queue was empty (first is still -1)
            first = 0;                   // Since we're adding the first element, move the front pointer to index 0
        }                                // End of the empty-queue check block
                                         // (blank line for readability)
        rear++;                          // Increment rear so it points to the next free slot (from -1 to 0)
        queue[rear] = 10;                // Insert the value 10 at the new rear position
    }                                    // End of the first enqueue block
                                         // (blank line for readability)
    if(rear == MAX - 1){                 // Again check if the queue is full before inserting the second element
        cout << "The queue is overflow"; // If full, print an overflow message
    }                                    // End of the overflow check block
    else {                               // If there is space, proceed to insert
                                         // (blank line for readability)
                                         // (blank line for readability)
        rear++;                          // Move rear forward to the next free slot
        queue[rear] = 20;                // Insert the value 20 at the new rear position
    }                                    // End of the second enqueue block
                                         // (blank line for readability)
     if(rear == MAX - 1){                // Check if the queue is full before inserting the third element
        cout << "The queue is overflow"; // If full, print an overflow message
    }                                    // End of the overflow check block
    else {                               // If there is space, proceed to insert
                                         // (blank line for readability)
                                         // (blank line for readability)
        rear++;                          // Move rear forward to the next free slot
        queue[rear] = 30;                // Insert the value 30 at the new rear position
    }                                    // End of the third enqueue block
                                         // (blank line for readability)
    if(first == -1 || first > rear){     // Check for underflow: queue is empty if front is -1 or front has passed rear
        cout << "The queue is underflow"; // If empty, print an underflow message
    }else{                               // Otherwise the queue has at least one element to remove
        cout << "Detected front: " << queue[first] << endl; // Print the element currently at the front
        first++;                         // Advance the front pointer, effectively removing (dequeuing) that element
    }                                    // End of the first dequeue block
  if(rear == MAX - 1){                   // Check if the queue is full before inserting the fourth element
        cout << "The queue is overflow"; // If full, print an overflow message
    }                                    // End of the overflow check block
    else {                               // If there is space, proceed to insert
                                         // (blank line for readability)
                                         // (blank line for readability)
        rear++;                          // Move rear forward to the next free slot
        queue[rear] = 40;                // Insert the value 40 at the new rear position
    }                                    // End of the fourth enqueue block
                                         // (blank line for readability)
    if(first == -1 || first > rear){     // Check for underflow again before the next dequeue
        cout << "The queue is underflow"; // If empty, print an underflow message
    }else{                               // Otherwise the queue has an element to remove
        cout << "Detected front: " << queue[first] << endl; // Print the element currently at the front
        first++;                         // Advance the front pointer, removing that element from the queue
    }                                    // End of the second dequeue block
                                         // (blank line for readability)
      if(rear == MAX - 1){               // Check if the queue is full before inserting the fifth element
        cout << "The queue is overflow"; // If full, print an overflow message
    }                                    // End of the overflow check block
    else {                               // If there is space, proceed to insert
                                         // (blank line for readability)
                                         // (blank line for readability)
        rear++;                          // Move rear forward to the next free slot
        queue[rear] = 50;                // Insert the value 50 at the new rear position
    }                                    // End of the fifth enqueue block
                                         // (blank line for readability)
    for(int i = first; i <= rear; i++){  // Loop from the front index to the rear index to display remaining elements
        cout << queue[i] << endl;        // Print each element of the queue on its own line
    }                                    // End of the display loop
                                         // (blank line for readability)
                                         // (blank line for readability)
    return 0;                            // Return 0 to indicate the program ended successfully
}                                        // End of the main function
