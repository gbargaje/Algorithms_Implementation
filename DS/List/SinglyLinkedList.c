#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *next;
	int data;
}*Node;

Node createNode(int data){
	Node temp = (Node) malloc(sizeof(struct Node));
	if(!temp)
		return NULL;
	temp->data = data;
	temp->next = NULL;
	return temp;

}
void displayList(Node head){
	while(head){
		printf("%d  ", head->data);
		head = head->next;
	}
	printf("\n");
}

int addElementAtEnd(Node head, int data){
	Node temp = createNode(data);
	
	if(!temp)
		return 1;

	if(head){
		while(head->next)
			head = head->next;
		head->next = temp;
	}
	else {
		head = temp;
	}
	return 0;
}

int deleteFirstMatch(Node head, int data){
	if(head == NULL)
		return -1;

	Node temp;
	if(head->data == data){
		temp = head;
		head = head->next;
		free(temp);
		return 0;
	}
	else{
		while(head->next){
			if(head->next->data == data){
				temp = head->next;
				head = head->next->next;
				free(temp);
				return 0;
			}
			head = head->next;
		}
	}
	return 1;
}

int main(){
	Node head;
	int ele[] = {10, 20, 30, 40, 10};
	int len = sizeof(ele) / sizeof(int);
	for(int i = 0; i < len; i++)
		addElementAtEnd(head, ele[i]);
	

	int ch;
	do{
		printf("1. Add Element\n2. Delete Element\n3. display List\n 0. Exit\n");
		printf("Enter you choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 0:
				exit(0);
			break;
			case 1:
				printf("Enter Element : ");
				scanf("%d", &len);
				addElementAtEnd(head, len);
				displayList(head);
			break;
			case 2:
				printf("Enter Element : ");
				scanf("%d", &len);
				if(deleteFirstMatch(head, len) == 1){
					printf("Could not find the element ...\n");
				}
				displayList(head);
			break;
			case 3:
				displayList(head);
			break;
			default:
				printf("Invalied choice entered. Please choose correct option ...\n");
			break;
		}

	}while(ch);
}