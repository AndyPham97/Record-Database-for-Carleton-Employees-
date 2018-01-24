
/* 
File name is linked_list.c
 Purpose: file contains functions for manipulating singly linked list
 
 Created By
 Doron Nussbaum 2016
 
 Modifications:
 November 2017 - minor modifications
 
 
 Copyright 2017
 
 */

/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"


/************************************************************************/
// Define 



/************************************************************************/

/*
Purpose: insert a new node into the list as the first element
input
id - id of person
firstName - first name of person
familyName - family name of person

input/output
head - head of linked list

return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/

PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, 
        char *firstName, char *familyName)
{
	// add code
 	PersonalInfo *p = NULL; //Insertion pointer
	
	p = (PersonalInfo *)malloc(sizeof(PersonalInfo));
	if (p == NULL) return NULL;

	p->id = id;
	strncpy(p->firstName,firstName,sizeof(p->firstName)); 
	strncpy(p->familyName,familyName,sizeof(p->familyName)); 

	p->next = *head; //Point to the current head node

	*head = p; //Assign the newly allocated node as the new head node
	return p;   

}


/************************************************************************/
/*
Purpose: insert a new node into the list after the given node  

Input
node - the node after which the new node must be added to the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertAfter(PersonalInfo *node, unsigned int id, char *firstName, char *familyName)
{
	// add code 
	PersonalInfo *p = NULL; //Insertion pointer
	
	p = (PersonalInfo *)malloc(sizeof(PersonalInfo)); 
	if (p == NULL) return NULL;

	p->id = id;
	strncpy(p->firstName,firstName,sizeof(p->firstName)); 
	strncpy(p->familyName,familyName,sizeof(p->familyName));  

	p->next = node->next; //Insert new node after where the given node is placed along the list
	node->next = p; //Make the given node connect to the newly allocated node
	
	return p;


}

/************************************************************************/
/*
Purpose: create a new node and insert it into the end of the list
Input
head - the head of the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertLast(PersonalInfo **head, unsigned int id, char *firstName, char *familyName)
{
	// add code
	PersonalInfo *p = NULL; //Insertion pointer
	PersonalInfo *i = *head; //Pointer to the head node
	
	p = (PersonalInfo *)malloc(sizeof(PersonalInfo));
	if (p == NULL) return NULL;

	p->id = id;
	strncpy(p->firstName,firstName,sizeof(p->firstName)); 
	strncpy(p->familyName,familyName,sizeof(p->familyName)); 

	if (listSize(*head) == 0) {
		p->next = *head; //Point to the current head node
		*head = p; //Assign the newly allocated node to be the new head node 
		return p;
	}
	else {
		while (i->next != '\0') { //i->next ensures that it doesn't stop on a node that points to nothing
			i=i->next;
		}

		i->next = p; //Make the current last node in the list connect to the new node
	
		return p;
	}

}


/************************************************************************/
/*
Purpose: search for the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

return
a pointer to the node that was found.
NULL - if no node was found or list empty

*/


PersonalInfo *searchByName(PersonalInfo *head, char *firstName)
{
	// add code 
	if (listSize(head) == 0)
		return NULL;
	else {
		while (head != '\0') {
			if (strcmp(head->firstName,firstName) == 0) 
				return head;
			head=head->next;
		}
		return NULL;	
	}

}

/************************************************************************/
/*
Purpose: search for the first node with the matching id
Input
head - the head of the list
id - id of person person

return
a pointer to the node that was allocated.  

NULL - if no node was found or list empty 

*/


PersonalInfo *searchById(PersonalInfo *head, unsigned int id)
{
	// add code 
	if (listSize(head) == 0)
		return NULL;
	else {
		while (head != '\0') {
			if (head->id == id)
				return head;
			head=head->next;
		} 
		return NULL;
	}	
    
}

/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted
1 if node was not deleted or list is empty

*/


int deleteFromList(PersonalInfo **head, unsigned int *id,
	char *firstName, char *familyName)

{

    // add code
	if (listSize(*head) == 0)
		return 1;
	else if (listSize(*head) == 1) {
		PersonalInfo *p = NULL; //Deletion node
	
		p = (PersonalInfo *)malloc(sizeof(*head));
		if (p == NULL) return(1);	

		p = *head; // Head node to be deleted
		*head = NULL; //Since there is only a single node in the list, you terminate the head pointer entirely

		//Copy the data to the output
		*id = p->id;
		strncpy(firstName, p->firstName, sizeof(p->firstName));
		strncpy(familyName, p->familyName, sizeof(p->familyName));

		free(p);

		return(0);
	}
	else {
		PersonalInfo *p = NULL; //Deletion node
	
		p = (PersonalInfo *)malloc(sizeof(*head));
		if (p == NULL) return(1);	

		p = *head; //Head node to be deleted
		*head = p->next; //Assign the next node in the updated list the new head node

		//Copy the data to the output
		*id = p->id;
		strncpy(firstName, p->firstName, sizeof(p->firstName));
		strncpy(familyName, p->familyName, sizeof(p->familyName));

		free(p);
		
		return(0);
	}

}


/***************************************************************/

/*
Purpose: delete the last node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted  
1 if node was not deleted or list is empty 

*/


int deleteLast(PersonalInfo **head, unsigned int *id,
                char *firstName, char *familyName)

{
    // add code 
	PersonalInfo *p = NULL; //Deletion node
	PersonalInfo *prev = NULL; //Previous pointer on the node before the current node
	PersonalInfo *i = *head; //Traversing node pointer

	if (listSize(*head) == 0)
		return 1;
	else if (listSize(*head) == 1) {
		p = (PersonalInfo *)malloc(sizeof(*head));
		if (p == NULL) return(1);

		p = *head; //Head node to be deleted
		*head = NULL; //Since there is only one node in the list, you terminate the head pointer entirely
	
		//Copy the data to the output
		*id = p->id;
		strncpy(firstName, p->firstName, sizeof(p->firstName));
		strncpy(familyName, p->familyName, sizeof(p->familyName));

		free(p);

		return(0);
	}
	else {
		while (i->next != '\0') {
			prev = i; //Previous pointer to current node before traversing to the next one
			i=i->next; 
		}

		p = (PersonalInfo *)malloc(sizeof(i));
		if (p == NULL) return(1);

		p = i; //Current node to be deleted which is also the last node in the list
		prev->next = NULL; //Since there is no node after the last node, you make the last node point to nothing 

		//Copy the data to the output
		*id = p->id;
		strncpy(firstName, p->firstName, sizeof(firstName));
		strncpy(familyName, p->familyName, sizeof(familyName));
	
		free(p);

		return(0);
	}

}



/************************************************************************/

/*
Purpose: delete the record after the given node 
Input
node - a node in the list

output
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0 if node was deleted 
1 if node was not deleted (either input node is NULL or input node was the lastnode in the list)

*/



int deleteAfter(PersonalInfo *node, unsigned int *id,
                char *firstName, char *familyName)

{
    // add code 
	if (node == NULL || node->next == NULL)
		return 1;
	else {
		PersonalInfo *p = NULL; //Deletion node
	
		p = (PersonalInfo *)malloc(sizeof(node->next));
		if (p == NULL) return(1);	
		
		p = node->next; //Node to be deleted and that is the node after the given node
		if (p->next == NULL) 
			node->next = NULL; //If it's the last node in the list then make it point to nothing
		else
			node->next = p->next;//Else connect the given node to the next node in the list after deletion

		//Copy the data to the output
		*id = p->id;
		strncpy(firstName, p->firstName, sizeof(p->firstName));
		strncpy(familyName, p->familyName, sizeof(p->familyName));


		free(p);

		return(0);
	}
	
	

}

/************************************************************************/

/*
Purpose: delete the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

*/


int deleteNodeByName(PersonalInfo **head, char *firstName,
	char *familyName, unsigned int *id)
{
	// add code 
	PersonalInfo *p = NULL; //Deleting pointer
	PersonalInfo *i = *head; //Traversing pointer
	PersonalInfo *prev = NULL; //Previous pointer behind the current node the traversing pointer is currently pointing to
	int found = 0; //This dictates that it needs to check the last node 
	
	if(listSize(*head) == 0)
		return 1;

	else if (listSize(*head) == 1) {
		if (strcmp((*head)->firstName,firstName) == 0) {
			p = (PersonalInfo *)malloc(sizeof(*head)); 
			if (p == NULL) return(1);
	
			p =  *head; //Head node to be deleted
			*head = NULL; //No nodes in the list anymore, so there is no head node basically

			//Copy the data to the output
			*id = p->id;
			strncpy(firstName, p->firstName, sizeof(p->firstName));
			strncpy(familyName, p->familyName, sizeof(p->familyName));

			free(p);
			return(0);
		}
		else
			return(1);
	}
	else { 
		while (i->next != '\0') {
			if (strcmp(i->firstName,firstName) == 0) {
				found = 1;
				break; //Once we find the first occurence of a matching record with the desired first name
			}
			
			prev = i; //Make previous node point to the current node before traversing
			i=i->next; 
		}

		//Ensures that it reaches the final node if no matching record was given
		if (found == 0) {
			if (strcmp(i->firstName,firstName) == 0) {
				p = (PersonalInfo *)malloc(sizeof(i)); 
				if (p == NULL) return(1);

				p = i; //Current node to be deleted
				prev->next = NULL; //Make previous node to that deleted node point to nothing

				//Copy the data to the output
				*id = p->id;
				strncpy(firstName, p->firstName, sizeof(p->firstName));
				strncpy(familyName, p->familyName, sizeof(p->familyName));

				free(p);
				return(0);
			}
			else
				return(1);
		}

		else {
			p = (PersonalInfo *)malloc(sizeof(i)); 
			if (p == NULL) return(1);

			//If first node from the list had the matching name
			if (i == *head) {
				*head = p->next; //Make the next node in the updated list be the new head node

				//Copy the data to the output
				*id = p->id;
				strncpy(firstName, p->firstName, sizeof(p->firstName));
				strncpy(familyName, p->familyName, sizeof(p->familyName));

				free(p);
			}
			else { //Other nodes in the list
				p = i; // Current node to be deleted
				prev->next = p->next; //Make previous node to that deleted node point to the next node in the list after deletion

				//Copy the data to the output
				*id = p->id;
				strncpy(firstName, p->firstName, sizeof(p->firstName));
				strncpy(familyName, p->familyName, sizeof(p->familyName));

				free(p);
			}
		  }
			return(0);	
		}


}
/************************************************************************/
/*
Purpose: deletes all nodes from the list
input/output
head - the head of the list


*/


void deleteList(PersonalInfo **head)
{
	// add code 
	PersonalInfo *p = NULL; //Deletion node
	PersonalInfo *i = *head; //Traversal node pointer
	while (i != '\0') {
		p = (PersonalInfo *)malloc(sizeof(i)); 
		p = *head; //Deleting the current head node
		*head = p->next; //Make the next node in the updated list be the new head node
		i=i->next; //Next node to be deleted in the list
		free(p);			
	}


}



/************************************************************************/
/*
Purpose: prints the fields of a node
input:
node - a pointer to a given node

*/


void printNode(PersonalInfo *node)
{
	printf("%-20s %-20s %7d \n",node->firstName, node->familyName, node->id);

}


/************************************************************************/
/*
Purpose: prints all the records in the list

input
head - the head of the list
*/


void printList(PersonalInfo *head)
{
	// add code 
	if (listSize(head) == 0) 
		printf("List is empty.\n");
	else {
		while(head != '\0') {
			printNode(head); //Uses printNode function to print out node's data
			head=head->next; 
		}
	}
}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list
input
head - the head of the list

return 
the number of nodes in the list

*/


int listSize(PersonalInfo *head)
{
	// add code 
	int size = 0; //Counter for # of nodes in the list
	while (head != '\0') {
		size++;
		head = head->next;
	}

	return size;
}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list with a matching firstName
input
head - the head of the list

return 
the number of nodes in the list that match the firstName


*/


int countRecords(PersonalInfo *head, char *firstName)
{
	// add code 
	int count = 0; //Counter for # of records with given first name

	while (head != '\0') {
		if (strcmp(head->firstName, firstName) == 0)
			count++;
	head = head->next;
	}
	return count;
}




/************************************************************************/
/*

Purpose: removes all duplicates records from the list.  Duplicate records are determined by their first name. 
You can assume that the listed is sorted by first name.

input
head - the head of the  list



*/




void removeDuplicates(PersonalInfo *head)
{
	// add code 
	PersonalInfo *i = head; //Current node for traversal
	PersonalInfo *p = NULL; //Pointer handle to node that is going to be deleted

	if (listSize(head) == 0 || listSize(head) == 1)
		printf("List is empty or too small\n");	

	else {
		while (i->next != '\0') {			
			if (strcmp(i->firstName, i->next->firstName) == 0) {
				p = (PersonalInfo *)malloc(sizeof(i->next));
				if (p == NULL) return;

				p = i->next; //Node to be deleted and that is the next node after the current node
				i->next = p->next; //Make previous node to the deleted node connect to the next node in the updated list
				free(p);
			}
			else 
				i = i->next; //Move to the next node
		}
	}
}

