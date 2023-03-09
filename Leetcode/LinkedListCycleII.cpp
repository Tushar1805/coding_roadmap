/********** Get Problem Here **********/
// https://leetcode.com/problems/linked-list-cycle-ii/description/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

// Solution to find any cycle in linked list using 'Hare and tortoise approach'
struct ListNode {
      int data;
      ListNode *next;
      ListNode(int x) : data(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool cycleFound = false;

        while(fast && fast -> next){
            slow = slow -> next; // Moves only one step
            fast = fast -> next -> next; // Moves two step
            if(slow == fast){
                cycleFound = true;
                break;
            }
        }
        if(!cycleFound) return NULL;

        // if cycle is found -> move both pointers by one step -> finally you will reach the 
        // start of the cycle (shift any one pointer to head)

        fast = head;
        while(slow != fast){
            fast = fast -> next;
            slow = slow -> next;
        }
        return slow;
    }
};

void display();

// Represent a node of singly linked list  
// struct node
// {
// 	int data;
// 	struct node *next;
// };



// Represent the head and tail of the singly linked list  
struct ListNode *head, *tail = NULL;

// insertCycle() function inserts the cycle in linked list
void insertCycle(int pos)
{
    struct ListNode* temp = head; // Creating a temporary
                              // variable pointing to head
    int i;
    if (pos == 0) {
        tail ->next = temp->next; // joining the tail to starting position
    }
    else {
        for (i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        // Now temp pointer points to the previous node on
        // which cycle is to be attached

        tail->next = temp->next; // joins the tail to pos
    }
    // printf("\nUpdated Linked List is : \n");
    // display();
}

// deleteNode() function deletes the node from the list
void deleteNode(int pos)
{
    struct ListNode* temp = head; // Creating a temporary
                              // variable pointing to head
    int i;
    if (pos == 0) {
        printf("\nElement deleted is : %d\n", temp->data);
        head = head->next; // Advancing the head pointer
        temp->next = NULL;
        free(temp); // Node is deleted
    }
    else {
        for (i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        // Now temp pointer points to the previous node of
        // the node to be deleted
        struct ListNode* del
            = temp->next; // del pointer points to the node
                          // to be deleted
        temp->next = temp->next->next;
        printf("\nElement deleted is : %d\n", del->data);
        del->next = NULL;
        free(del); // Node is deleted
    }
    printf("\nUpdated Linked List is : \n");
    display();
}

// addNode() will add a new node to the list  
void addNode(int data){

	// Create a new node  
	struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
	newNode -> data = data;
	newNode -> next = NULL;

	// Checks if the list is empty  
	if (head == NULL)
	{
		// If list is empty, both head and tail will point to new node
		head = newNode;
		tail = newNode;
	}else{
		// newNode will be added after tail such that tail's next will point to newNode 
		tail -> next = newNode;
		// newNode will become new tail of the list  
		tail = newNode;
	}
}

// display() will display all the nodes present in the list  
void display(){
	// Node current will point to head  
	struct ListNode* current = head;

	if (head == NULL)
	{
		printf("List is empty\n");
	}else{
		printf("Singly Linked list elements are: \n");
		while(current != NULL){
			// Prints each node by incrementing pointer  
			printf("%d -> ", current -> data);
			current = current -> next;
		}
		if (current == NULL)
		{
			printf ("null");
		}
		printf("\n\n");
	}
}

int main(){
	Solution s;
	struct ListNode *cycleAt;
	int data, ch, pos, cyclePos;
	do{
		printf("\n1 to enter the element in the list.\n2 to delete the element from the list.\n3 to display the list.\n4 to insert cycle.\n5 Find is there any cycle present in the linked list.\n");
		scanf("%d", &ch);
		switch(ch){
			case 1: 
				printf("\nEnter the data to enter in the list: ");
				scanf("%d", &data);
				addNode(data);
				break;
			case 2:
				printf("\nEnter the position to delete element at list: ");
				scanf("%d", &pos);
				deleteNode(pos);
				break;
			case 3:
				display();
				break;
			case 4: 
				printf("\nEnter the position to insert cycle at: ");
				scanf("%d", &cyclePos);
				insertCycle(cyclePos);
				break;
			case 5:
				cycleAt = s.detectCycle(head);
				printf("\nCycle present at %d", cycleAt -> data);
				break;
			default: 
				printf("Invalid Input, enter correct choice\n");
				break;
		}
		printf("Enter 1 to perform operations again. Else enter any other key to exit: ");
		scanf("%d", &ch);
	}while(ch == 1);
	getch();
	return 0;
}