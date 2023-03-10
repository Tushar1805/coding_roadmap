/********** Get Problem Here **********/
 // https://leetcode.com/problems/linked-list-random-node/description/

// Here used the reservior sampling algorithm to get the random value from linked list

#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  struct ListNode *start , *endPtr = nullptr;

  class Solution{
  	private: ListNode *head;
    public: 
    	Solution(ListNode *head){
    		this -> head = head;
    	}


    	int getRandom(){
    		ListNode* curr = this -> head;
	        int scope = 1;
	        int chosenValue = curr -> val;
	        curr =  curr -> next;
	        while(curr != nullptr){
	            scope++;
	            // get the random value in the range [0, scope -1]
	            int index = rand()%scope;
	            if(!index)
	                chosenValue = curr -> val;
	            curr = curr -> next;
	        }
	        return chosenValue;
    	}
  };

  void display(){
  	if (start == nullptr)
  	{
  		printf("List is empty");
  	}else{
  		while(start != nullptr){
  			printf("%d -> ", start -> val);
  			start = start -> next;
  		}
  		if (start == NULL)
		{
			printf ("null");
		}
		printf("\n");
  	}
  }

  void addNode(int data){
  	// Create a new node  
	struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
	newNode -> val = data;
	newNode -> next = NULL;

	// Checks if the list is empty  
	if (start == NULL)
	{
		// If list is empty, both head and tail will point to new node
		start = newNode;
		endPtr = newNode;
	}else{
		// newNode will be added after tail such that tail's next will point to newNode 
		endPtr -> next = newNode;
		// newNode will become new tail of the list  
		endPtr = newNode;
	}
  }

  int getRandom(ListNode *head){
    		ListNode* curr =  head;
	        int scope = 1;
	        int chosenValue = curr -> val;
	        curr =  curr -> next;
	        while(curr != nullptr){
	            scope++;
	            // get the random value in the range [0, scope -1]
	            int index = rand()%scope;
	            if(!index)
	                chosenValue = curr -> val;
	            curr = curr -> next;
	        }
	        return chosenValue;
    	}

  int main(int argc, char const *argv[])
  {
  	Solution* obj = new Solution(start);;
	int data, ch, rnd;
	do{
		printf("\n1 to enter the element in the list.\n2 to display the list.\n3 to generate random number from list.\n");
		scanf("%d", &ch);
		switch(ch){
			case 1: 
				printf("\nEnter the data to enter in the list: ");
				scanf("%d", &data);
				addNode(data);
				break;
			case 2:
				display();
				break;
			case 3: 
				rnd = getRandom(start);
				cout<<"\nRandom number generated from the list: "<<rnd;
				
				break;
			default: 
				printf("Invalid Input, enter correct choice\n");
				break;
		}
		printf("Enter 1 to perform operations again. Else enter any other key to exit: ");
		scanf("%d", &ch);
	}while(ch == 1);
	return 0;
  }