#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data_id;
    char name[100];
    struct node* next;
};

struct node* booking_front = NULL;
struct node* booking_rear = NULL;

struct node* event_front=NULL;
struct node* event_rear=NULL;


int size;
int count=0;

struct node* create_node(int x, char name[]) 
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data_id = x;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    return new_node;
}

void enqueue_booking() {
    int x;
    printf("Enter your ID number: ");
    scanf("%d", &x);
    
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);
    
    struct node* new_node = create_node(x, name);
    
    if (booking_rear == NULL) {
        booking_front = booking_rear = new_node;
    } else {
        booking_rear->next = new_node;
        booking_rear = new_node;
    }
    
    printf("Booking added for ID: %d and Name: %s\n", x, name);
}

void peek_booking() {
    if (booking_front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("The person at the beginning of the booking queue is: \n");
        printf("ID: %d \nName: %s\n", booking_front->data_id, booking_front->name);
    }
}

void search_booking(int x) {
    struct node* temp = booking_front;
    while (temp != NULL) {
        if (temp->data_id == x) {
            printf("Person with ID %d found in booking queue: Name: %s\n", x, temp->name);
            return;
        }
        temp = temp->next;
    }
    
    printf("Person with ID %d not found in booking queue\n", x);
}


void dequeue_booking(){
    if(booking_front==NULL){
        printf("\nBooking queue is empty.");
        return;
    }
    if(count>=size){
        printf("The event is full.");
        return;
    }
    struct node*temp=booking_front;
    booking_front=booking_front->next;
    
    if(event_rear==NULL){
        event_front=event_rear=temp;
    }
    else{
        event_rear->next=temp;
        event_rear=temp;
    }
    event_rear->next=NULL;
    count++;
    printf("Moved to event queue: ID: %d, Name: %s\n", temp->data_id, temp->name);
}



void display_event_queue(){
    if(event_front==NULL){
        printf("Event queue is empty.");
        return;
    }
    struct node*temp=event_front;
    
    while(temp!=NULL){
        printf("ID is :%d and name is: %s", temp->data_id, temp->name);
        temp=temp->next;
    }
}

int main() {
    int choice;
    printf("Enter maximum number of people in the event: ");
    scanf("%d",&size);
    while (1) {
        printf("\nDashboard:\n");
        printf("1. Enter new guest\n");
        printf("2. Display guest at the begenning of the queue\n");
        printf("3. Search for a guest by ID\n");
        printf("4. Enqueue guest in event queue\n");
        printf("5. Display event queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enqueue_booking();
                break;
            case 2:
                peek_booking();
                break;
            case 3: {
                int id;
                printf("Enter the ID to search: ");
                scanf("%d", &id);
                search_booking(id);
                break;
            }
            case 4:{
                dequeue_booking();
                break;
            }
            case 5:{
                display_event_queue();
                break;
            }
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
