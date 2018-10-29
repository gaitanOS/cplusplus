//FILE: sequence.cpp
//CLASS IMPLEMENTED: sequence (see sequence.h for documentation)
//
//
//  COEN 79
//  --- Behnam Dezfouli, COEN, SCU ---
//
//
//INVARIANT for the sequence class
//  1. The number of items in the sequence is stored in the member variable "many_nodes"
//
//  2. For an empty sequence, we do not care what is stored in any of data and head_ptr
//      and tail_ptr point to NULL; for a non-empty sequence, the items stored in the
//      sequence can be accessed using head_ptr and tail_ptr and we don't care what is
//      stored in the rest of the data.
//
//  3. If there is a current item, then it lies in *cursor; if there is no
//     current item, then cursor* equals NULL.
//
//  4. If there is a previous item, then it lies in precursor*.  If there is no previous
//       item, then precursor equals NULL.


#include <iostream>
#include <algorithm> //provides copy function
#include <cassert> //for assert function
#include "sequence.h" //header file for class
#include "node.h" // provides node class

using namespace std; //For copy function

namespace coen79_lab6
{
    // Default private member variable initialization function.
    void sequence::init()
    {
        //Initializing pointers to NULL
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        //Initializiing many_nodes (or our counter) to 0
        many_nodes = 0;
    }

    //CONSTRUCTOR IMPLEMENTATION for default constructor
    sequence :: sequence ()
    {
        init();
    }

    //Copy Constructor
    sequence :: sequence(const sequence& source)
    {
        init();
        *this = source;
    }
    sequence:: ~sequence( )
    {
        start();    //we go back to the head of the sequence in order to remove every element of the sequence.
            while (head_ptr != NULL)
            {
                remove_current();
            }
        
        many_nodes = 0;
    }
    // CONSTANT MEMBER FUNCTIONS for the sequence class:
    sequence::size_type sequence::size( ) const
    {
        return many_nodes;
    }
    //     Postcondition: The return value is the number of items in the sequence.
    //
    bool sequence::is_item( ) const //review what are the conditions that make current item valid;
                                    //right now we are just taking into account whether the cursor is null or not
    {
        return (cursor != NULL);
    }
    //     Postcondition: A true return value indicates that there is a valid
    //     "current" item that may be retrieved by activating the current
    //     member function (listed below). A false return value indicates that
    //     there is no valid current item.
    //
       sequence::value_type sequence::current( ) const
    {
        assert(is_item());
        return cursor->data();
    }
    //     Precondition: is_item( ) returns true.
    //     Postcondition: The item returned is the current item in the sequence.
    //
    // MODIFICATION MEMBER FUNCTIONS for the sequence class:
       void sequence::start( )
    {
        this->cursor = this->head_ptr;
        this->precursor = this->head_ptr;
    }
    //     Postcondition: The precursor and cursor are adjusted such that the first
    //     item in the sequence becomes the current item (but if the sequence is
    //     empty, then there is no current item).
    //
    void sequence::end( )
    {
        precursor = tail_ptr;
        cursor = tail_ptr;
    }
    //     Postcondition: The precursor and cursor are adjusted such that the last
    //     item in the sequence becomes the current item (but if the sequence is
    //     empty, then there is no current item).
    //
       void sequence::advance( )
    {
        assert(is_item());
        if (cursor == tail_ptr)
        {
            this->cursor = NULL;
            this->precursor =tail_ptr;
        }
    }
    //     Precondition: is_item returns true.
    //     Postcondition: If the current item was already the last item in the
    //     sequence, then there is no longer any current item. Otherwise, the new
    //     current item is the item immediately after the original current item.
    //
    void sequence::insert(const value_type& entry)
    {
        node *inserted_ptr;
        inserted_ptr = new node;
        inserted_ptr->set_data(entry);
        if (cursor == NULL)
        {
        inserted_ptr->set_link(head_ptr);
            cursor = inserted_ptr; //the newly inserted item is now the current item of the sequence.
        this->precursor = cursor;
        }
        else
        {
        inserted_ptr->set_link(cursor);
        this->precursor->set_link(inserted_ptr);
        cursor = inserted_ptr; //the newly inserted item is now the current item of the sequence.
        }
    }
    //     Postcondition: A new copy of entry has been inserted in the sequence
    //     before the current item. If there was no current item, then the new entry
    //     has been inserted at the front of the sequence. In either case, the newly
    //     inserted item is now the current item of the sequence.
    //
    void sequence::attach(const value_type& entry)
    {
        node *inserted_ptr;
        inserted_ptr = new node;
        inserted_ptr->set_data(entry);
        if (cursor == NULL)
        {
            tail_ptr->set_link(inserted_ptr); //we insert the new node next to the end of the sequence
            this->precursor = tail_ptr;
            this->cursor = inserted_ptr;
        }
        else
        {
            cursor->set_link(inserted_ptr);
            inserted_ptr->set_link(cursor->link());
            this->precursor = cursor; //now the current item will be the inserted pointer, e.g. the new entry
            this->cursor = inserted_ptr;
        }
        
    }
    //     Postcondition: A new copy of entry has been inserted in the sequence after
    //     the current item. If there was no current item, then the new entry has
    //     been attached to the end of the sequence. In either case, the newly
    //     inserted item is now the current item of the sequence.
    //
    void sequence::remove_current( )
    {
        assert(is_item());
        node *remove_item;
        remove_item = cursor;                  //we keep this item in another variable, otherwise we will be deleting the "new cursor".
        precursor->set_link(cursor->link()); //we change the link of the precursor to the next link of the current item
        cursor = cursor->link();            // we advance the cursor one position
        delete remove_item;                 //finally we remove the item we wanted to.
        
    }
    //     Precondition: is_item returns true.
    //     Postcondition: The current item has been removed from the sequence, and
    //     the item after this (if there is one) is now the new current item.
    //
    
    void sequence::operator =(const sequence& source)
    {
        
    }
}
