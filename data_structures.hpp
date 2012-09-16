//
//  data_structures.hpp
//  fundamentals
//
//  Created by Andreas Fragner on 5/26/12.
//

#ifndef preparaton_data_structures_hpp
#define preparaton_data_structures_hpp

#include "initialize.hpp"

//PROTOTYPES

template <typename T> class SL_Node;
template <typename T> class Node;
template <typename T> class Stack;
template <typename T> class Queue;

//--------------------------------------------------------------------
// 
// SINGLY LINKED LIST IMPLEMENTATION
//
//--------------------------------------------------------------------


template <typename T> class SL_Node{
  
public:
    
    SL_Node( const T& k):key(k), next(NULL){};
    SL_Node( const T& k, SL_Node* link):key(k), next(link){};    
    
    //friend functions
    template <typename Ty> friend SL_Node<T>* reverse( SL_Node<T>* );
    template <typename Ty> friend SL_Node<T>* find_node( SL_Node<T>*, const T&);
    template <typename Ty> friend SL_Node<T>* delete_node( SL_Node<T>*, const T&);
    template <typename Ty> friend SL_Node<T>* append_node( SL_Node<T>*, const T&);
    template <typename Ty> friend SL_Node<T>* has_loop( SL_Node<T>*);
    template <typename Ty> friend void print_SL( SL_Node<T>* );

    T key;
    SL_Node* next;       
    
    
};

// find Node with key in list with head, return pointer to that node
template <typename T> SL_Node<T>* find_node( SL_Node<T>* head, const T& k){
    
    while( head->key != k && head->next != NULL )
    { head = head->next; }
    
    return head;
}

// reverse list, returns pointer to new head
template <typename T> SL_Node<T>* reverse(SL_Node<T>* head){
    
    SL_Node<T>* new_head = NULL;

    // reverse the links, one node at a time
    while( head != NULL ){
        SL_Node<T>* next_node = head->next; //1. temp store next node of head
        head->next = new_head;   //2. link the current head to the new one
        new_head = head;    //3. set the new head to be the current one
        head = next_node; //4. move current head up the list, now linked to new head
    }
    return new_head;
}

// append a node to tail
template <typename T> SL_Node<T>* append_node( SL_Node<T>* head, const T& k){
    
    try{
        SL_Node<T>* to_append = new SL_Node<T>( k );
        
        while( head->next != NULL)
        {   head = head->next; }
        head->next = to_append;
        return to_append;
    }
    catch( bad_alloc& ba ){ 
        cout << "\n" << ba.what() << endl;
        return NULL; 
    }
    
}

// delete a node from linked list, return pointer to new head
template <typename T> SL_Node<T>* delete_node( SL_Node<T>* head, const T& key){
    
    SL_Node<T>* current_head = head;
    
    if( head->key == key )
    {    
        return head->next;
    }
    
    while( head->next )
    {    
        if( head->next->key == key )
        {    
           // delete head->next;
            head->next = head->next->next;
            return current_head;
        }
        head = head->next;
    }
    
    return current_head;
}

// check if the list has a loop and return pointer to node of loop start
// if there's no loop return NULL pointer
// this is O(n) complexity and uses the runner technique
template<typename T> SL_Node<T>* has_loop(SL_Node<T>* head)
{
    SL_Node<T>* slow, fast;
    slow = fast = head;
    
    while( slow != NULL && fast !=NULL && fast->next != NULL)
    {
        if( slow == fast->next || slow == fast->next->next)
            return slow;
        
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return NULL;
}


// Node printer helper
template <typename T> void print_SL(SL_Node<T>* head){
    
    cout << "\n";
    while( head != NULL )
    {
        cout << head->key << "," << &(head->next) << endl;
        head = head->next;
    }
    
}


// Test singly linked list implementation
bool test_SL(){
    
    cout << "\n----TESTING SINGLY-LINKED LIST----\n" << endl;

    SL_Node<char> d('d');
    SL_Node<char> c( 'c', &d );
    SL_Node<char> b( 'b', &c );
    SL_Node<char> a( 'a', &b );
    
    SL_Node<char>* head = &a;
    print_SL(head);
    
    head = reverse(head);
    print_SL(head);
    
    head = reverse(head);
    append_node(head, 'e');
    print_SL(head);
    
    head = delete_node(head, 'e');
    print_SL(head);
    
    return true;
}


//--------------------------------------------------------------------
//
// NODE IMPLEMENTATION - FOR STACK AND QUEUE
//
//--------------------------------------------------------------------


template <typename T> class Node{
    
public:
    Node(const T& k): key(k) {};
    Node(const T& k, Node* link): key(k), next(link) {};
    Node(): next(NULL), key(NULL){};
    ~Node(){};
    /*Node<T>& operator=(const Node<T>& rhs){
        *this->next = (*rhs)->next;
        this->key = rhs->key;
        return this;
    }*/
    
    T key;
    Node<T>* next;
};


//--------------------------------------------------------------------
//
// STACK IMPLEMENTATION - POINTERS
//
//--------------------------------------------------------------------


template <typename T> class Stack {

    public:
    Node<T>* top;
    
    Stack(const T& k, Node<T>* link) { top = new Node<T>(k,link); }; //not exception safe yet
    
    T pop(){
        if( &top !=NULL && top->next !=NULL )
        {
            T item = top->key;
            top = top->next;
            return item;
        }
        else return NULL;
    }
    
    
    void push(const T &key){

        Node<T>* newnode = new Node<T>(key);
        newnode->next = top;
        top = newnode;
    }
 
    
    T peek(){
        return top->key;
    }
    

    bool is_empty(){
        if( top == NULL ) return true;
        else return false;
    }
    
};


bool test_Stack(){
    
    cout << "\n\n----TESTING STACK IMPLEMENTATION----\n" << endl;
    
    Stack<char> d('d', NULL);
    d.push('c');
    d.push('b');
    d.push('a');
    
    //unwinding the stack
    cout << "\n" << d.peek();
    d.pop();
    cout << "\n" << d.peek();
    d.pop();
    cout << "\n" << d.peek();
    d.pop();
    cout << "\n" << d.peek();
        
    
    return true;
}


//--------------------------------------------------------------------
//
// QUEUE IMPLEMENTATION - POINTERS
//
//--------------------------------------------------------------------


template <typename T> class Queue{

public:
    Node<T> head, tail;
    
    Queue(const T& k, Node<T>* link):head(k,link) { tail = head; };
    
    void enqueue(const T &key){
        Node<T>* new_tail = new Node<T>(key,NULL);
        if( head.next == NULL )
        {
            tail = *new_tail;
            head.next = new_tail;
        }
        else {
            tail.next = new_tail;
            tail = *new_tail;
        }
    }
    
    T dequeue(){
        if( head != NULL )
        {
            T item = head->key;
            head = head->next;
            return item;
        }
        else{
            return (T) 0;
        }
    }
    
};


template <typename T> void print_Queue( Node<T> head )
{
    cout << "\n";

    while( head.next != NULL )
    {
        cout << head.key << endl;
        head = *(head.next);
   }
}


bool test_Queue(){
    
    cout << "\n\n----TESTING QUEUE POINTER IMPLEMENTATION----\n" << endl;
    
    Queue<char> d('a', NULL);
    d.enqueue('b');
    d.enqueue('c');
    d.enqueue('d');
    d.enqueue('e');
    
    print_Queue( d.head );
 
    return true;

}



//--------------------------------------------------------------------
//
// TOWERS OF HANOI SOLVER
//
//--------------------------------------------------------------------


              
//--------------------------------------------------------------------
//
// DOUBLY LINKED LIST IMPLEMENTATION
//
//--------------------------------------------------------------------
              
    /*
     template <typename T> class DL_Node{
     
     public:
     
     DL_Node(const T&n):key(n),next(NULL),prev(NULL){};
     
     void append(const T& n){
     DL_Node to_append = new DL_node(n);
     DL_Node
     }
     
     void prepend(const T& n);
     
     private:
     T key;
     Node prev, next;
     
     
     };
     */




#endif
