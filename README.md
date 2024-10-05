# Eventify


Eventify is a basic event managemnt system

There are 2 main queues, the booking queue which is dynamically sized, which allows guests to enter.
The admin can allow guests from the booking queue to the event queue, the event queue is a limited size which is predefined by the admin (ie the number of seats/slots in the event)

To manage both queues, I have take 4 pointers in total
The first 2 are for the booking queue (booking_front,booking_rear)
The last 2 are for the event queue (event_front, event_rear)


This progrma allows the user to:
1. Enter guests in booking queue.
2. Display the guest at the beginning of the booking queue.
3. Search for a guest by ID in the booking queue.
4. Enqueue guest in event queue from the booking queue.
5. Display event queue.
