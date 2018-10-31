// FILE: node.cpp
//
//
//  COEN 79
//  --- Behnam Dezfouli, COEN, SCU ---
//
//
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
//
// INVARIANT for the node class:
//   The data of a node is stored in data_field
//   and the link to the next node is stored in link_field.

#include "node.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include <iostream>

using namespace std;

namespace coen79_lab6
{
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
	const node *cursor;
	size_t answer;

	answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    ++answer;

	return answer;
    }

    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
    	head_ptr = new node(entry, head_ptr);
    }

    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
    	node *insert_ptr;

    	insert_ptr = new node(entry, previous_ptr->link( ));
    	previous_ptr->set_link(insert_ptr);
    }

    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	const node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	const node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    void list_head_remove(node*& head_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = head_ptr;
    	head_ptr = head_ptr->link( );
    	delete remove_ptr;
    }

    void list_remove(node* previous_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = previous_ptr->link( );
    	previous_ptr->set_link( remove_ptr->link( ) );
    	delete remove_ptr;
    }

    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
    	while (head_ptr != NULL)
    	    list_head_remove(head_ptr);
    }

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
    	head_ptr = NULL;
    	tail_ptr = NULL;

    	// Handle the case of the empty list.
    	if (source_ptr == NULL)
    	    return;

    	// Make the head node for the newly created list, and put data in it.
    	list_head_insert(head_ptr, source_ptr->data( ));
    	tail_ptr = head_ptr;

    	// Copy the rest of the nodes one at a time, adding at the tail of new list.
    	source_ptr = source_ptr->link( );
    	while (source_ptr != NULL)
    	{
    	    list_insert(tail_ptr, source_ptr->data( ));
    	    tail_ptr = tail_ptr->link( );
    	    source_ptr = source_ptr->link( );
    	}
    }
    
    
    /* Code implemented into node.cpp by team*/
    
    
    
    //   void list_piece(
    //     const node* start_ptr, const node* end_ptr,
    //     node*& head_ptr, node*& tail_ptr
    //   )
    //    Precondition: start_ptr and end_ptr are pointers to nodes on the same
    //    linked list, with the start_ptr node at or before the end_ptr node
    //    Postcondition: head_ptr and tail_ptr are the head and tail pointers for a
    //    new list that contains the items from start_ptr up to but not including
    //    end_ptr.  The end_ptr may also be NULL, in which case the new list
    //    contains elements from start_ptr to the end of the list.
    
    void list_piece(node* start_ptr, node* end_ptr, node*& head_ptr, node*& tail_ptr){
        
        if(start_ptr == end_ptr || end_ptr->link() != start_ptr){
            //before function can execute, the precondition must be met, where start_ptr can be at or before the end_ptr node.
            
            node *new_list = NULL; //create a new list
            head_ptr = new_list; //make the head pointer point to the newly created list
            head_ptr->set_link(start_ptr);//link the head_ptr to the start_ptr
            node *temp = head_ptr->link(); //initialize a temp variable to traverse in place of head ptr
            while(temp->link() != end_ptr){//make sure next node is not end ptr
                
                node *new_node = temp->link(); //create a new node equivalent to next node of temp.
                temp->set_link(new_node); //set temp link to new node
                temp = temp->link(); //move temp pointer to new node
                
                
            }
            
            tail_ptr = temp; //temp should be last node before end_ptr since it will exit loop if temp->link() is end_ptr. thus, we should make tail_ptr = temp.
            
            
            /*Postcondition should be met at this point*/
            
            
            
        }
        
    }
    
    
    //   size_t list_occurrences(node* head_ptr, const node::value_type& target)
    //     Precondition: head_ptr is the head pointer of a linked list.
    //     Postcondition: The return value is the count of the number of times
    //     target appears as the data portion of a node on the linked list.
    //     The linked list itself is unchanged.
    
    
    
    size_t list_occurrences(node* head_ptr, const node::value_type& target){
        size_t counter = 0; //initialize a variable of type size_t to increment if a value is found in the linked list
        if(head_ptr != NULL){
            //precondition must be met: head_ptr must not be null. Otherwise, it means that the head_ptr is not the head_ptr of a linked list
            
            node *temp = head_ptr; //intitalize a temporary pointer of type to point to the head of the linked list to prevent moving the head pointer.
            
            while (temp->link() != NULL){
                
                if(temp->data() == target){
                    counter++;
                }
                temp = temp->link();
                
                
            }
            
        }
        
        return counter;
        
        
        
    }
    //   void list_insert_at(Node*& head_ptr, const node::value_type& entry, size_t position)
    //     Precondition: head_ptr is the head pointer of a linked list, and
    //     position > 0 and position <= list_length(head_ptr)+1.
    //     Postcondition: A new node has been added to the linked list with entry
    //     as the data. The new node occurs at the specified position in the list.
    //     (The head node is position 1, the next node is position 2, and so on.)
    //     Any nodes that used to be after this specified position have been
    //     shifted to make room for the one new node.
    
    
    
    
    void list_insert_at(node*& head_ptr, const node::value_type& entry, size_t position){
        
        if(head_ptr != NULL && position > 0 && position <= list_length(head_ptr) + 1){
            //precondition must be met: head_ptr must not be null. Otherwise, it means that the head_ptr is not the head_ptr of a linked list. position must be greater than 0 and must less than or equal to the list_length + 1. All 3 of these conditions must be met.
            
            int i; //initialize variable for for loop.
            node *new_node = NULL; //create the new node that will be inserted into the list
            new_node->set_data(entry); //assign the data value of node to entry
            node *temp = head_ptr; //initialize a temporary node pointer to traverse the list
            for(i = 1; i < position - 1; i++){
                temp = temp->link();
                i++;
            }
            new_node->set_link(temp->link());//assign the link of the new node to be temp->link(), which will be shifted over since it is in currently in new node's position
            temp->set_link(new_node); //temp was pointing one before the node at position. thus, it should point to the new node. new node will now be at position
        }
        
    }
    
    //   node::value_type list_remove_at(node*& head_ptr, size_t position)
    //     Precondition: head_ptr is the head pointer of a linked list, and
    //     position > 0 and position <= list_length(head_ptr).
    //     Postcondition: The node at the specified position has been removed from
    //     the linked list and the function has returned a copy of the data from
    //     the removed node.
    //     (The head node is position 1, the next node is position 2, and so on.)
    
    
    
    node::value_type list_remove_at(node*& head_ptr, size_t position){
        node::value_type returndata = 0; //initialize a variable to store the data in the deleted node.
        if(head_ptr != NULL && position > 0 && position <= list_length(head_ptr)){
            //precondition must be met: head_ptr must not be null. Otherwise, it means that the head_ptr is not the head_ptr of a linked list. position must be greater than 0 and must less than or equal to the list length. All 3 of these conditions must be met.
            
            int i; //initialize variable for for loop.
            
            node *temp = head_ptr; //initialize a temporary node pointer to traverse the list
            node *deletion;
            for(i = 1; i < position-1; i++){
                temp = temp->link(); //traverse until temp points to node before node at position
                i++;
            }
            returndata = temp->link()->data(); //store data in node to be deleted in returndata
            deletion = temp->link(); //node pointer to keep track of node to be deleted
            temp->set_link(temp->link()->link());//set link of temp to be the link of the node to be deleted
            free(deletion); //free the node that needs to be removed
            
            
            
            
        }
        
        return returndata; //return the data
        
    }
    
    //   node* list_copy_segment(node* head_ptr, size_t start, size_t finish)
    //     Precondition: head_ptr is the head pointer of a linked list, and
    //     (1 <= start) and (start <= finish) and (finish <= list_length(head_ptr)).
    //     Postcondition: The value returned is the head pointer for
    //     a new list that contains copies of the items from the start position to
    //     the finish position in the list that head_ptr points to.
    //     (The head node is position 1, the next node is position 2, and so on.)
    //     The list pointed to by head_ptr is unchanged.
    
    node* list_copy_segment(node* head_ptr, size_t start, size_t finish){
        node *new_head_ptr = NULL;
        if(head_ptr != NULL && 1 <= start && start <= finish && finish <= list_length(head_ptr)){
            
            //precondition must be met: head_ptr must not be null. Otherwise, it means that the head_ptr is not the head_ptr of a linked list. start must be greater than or equal to 1. start must be less than or equal to finish. finish must be less than or equal to the length of the list.
            
            
            //node *new_list = NULL; //create a new list
            //node *new_head_ptr = new_list; //make the head pointer point to the newly created list
            node *temp = head_ptr;
            size_t i; //initialize variable used in for loop
            for(i = 1; i < start; i++){
                temp = temp->link(); //traverse until position start is reached
                i++;
                
            }
            node *new_node = temp;//create new node that will be start since that is where temp is
            new_head_ptr = new_node; //point the new head pointer to new_node
            
            for(i = start; i < finish; i++){
                //create the list to includes nodes from start to finish positions tio the new list
                
                //node *new_node = temp;
                new_node->set_link(temp->link());
                temp->set_link(new_node);
                temp = temp->link();
                i++;
                
                
                
            }
            
           
            
            /*Postcondition should be met at this point*/
            
            
        }
        
         return new_head_ptr;
        
        
        
        
    }
    
    
    
    //   void list_print (const node* head_ptr);
    //     Precondition: head_ptr is the head pointer of a linked list, and
    //     the operator << has been defined for the value_type
    //     Postcondition: The value_type of all the nodes in the linked list are printed
    
    void list_print (const node* head_ptr){
        
        if(head_ptr != NULL){
            //precondition needs to be met: the head pointer must not be null. Otherwise, it means it does not point to a linked list
            
            int i; //initialize variable used in for loop
            node const *temp = head_ptr;
            for(i = 0; i < list_length(head_ptr); i++){ //traverse the entire list of nodes and print out each value in data.
                
                cout << temp->data() << endl; //print out data value
                temp = temp->link(); //move temp over to next node
                i++; //increment position
                
            }
            
            
        }
        
        
    }
    
    
    //   void list_remove_dups(node* head_ptr)
    //     Precondition: head_ptr is the head pointer of a linked list
    //     Postcondition: All the duplicates are removed from the linked list
    //     Example: If the list contains 1,1,1,2, after running this function the list
    //     contains 1,2
    
    
    
    void list_remove_dups(node* head_ptr){
        
        if(head_ptr != NULL){
            //precondition needs to be met: the head pointer must not be null. Otherwise, it means it does not point to a linked list
            
            
            
            
            
            
        }
        
        
    }
    
    
    
    node* list_detect_loop (node* head_ptr)
    {
        node * fast_runner = head_ptr;
        node * slow_runner = head_ptr;
        while (fast_runner != NULL && fast_runner->link() != NULL && slow_runner == fast_runner)
            {
                slow_runner = slow_runner->link();
                fast_runner = fast_runner->link()->link();
            }
        if (fast_runner == NULL || fast_runner->link() == NULL)
            return NULL;
        
        while (slow_runner != fast_runner)
            {
                fast_runner = fast_runner->link();
                slow_runner = slow_runner->link();
            }
        return fast_runner;
    }
    /* Pseudo code for detecting loops.
    Floyd’s cycle-finding algorithm
     1. Declare two pointers slow_runner and fast_runner, where both
     point to the head of the linked list
     2. while (fast_runner != NULL && fast_runner -
     > link() != NULL)
     • slow_runner moves one step at a time, and fast_runner moves two steps at a time
     • Break the loop if slow_runner == fast_runner
     3. Return NULL if the two pointers did not meet (i.e.,
     fast_runner == NULL || fast_runner - > link() == NULL)
     4. while (slow_runner != fast_runner)
     • Both pointers move one step at a time.
     */

    
    
}
