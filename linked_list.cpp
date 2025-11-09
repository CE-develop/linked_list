#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

/*

Given the head of a linked list, remove the nth node from the end of the list and return its new head.
struct node {
  int val;
  node* next;
};

E.g.
3 -> 5 -> 7 -> 8 -> 9 -> 20 -> 12 

List after deleting 3rd node from back

3 -> 5 -> 7 -> 8 -> 20 -> 12

C:\msys64\ucrt64\bin\gcc.exe

gcc 


*/




// Define a Node class
class Node{
  public:
    int data; // Data part of the node
    Node* next; // Pointer to the next node

    // Constructor for convenience
    Node(int value) : data(value), next(nullptr) {}
};

// Class for singly linked list
class LinkedList{
private:
    Node* head; // Pointer to the head of the list

public:
    // Constructor to initialize an empty list
    LinkedList(){
      head = nullptr;
    }
    // Function to insert a node at the end
    void insertAtEnd(int value){
      Node* newNode = new Node(value);
      if(head == nullptr){
        head = newNode; // If list is empty, make newNode the head
      }
      else{
        Node* temp = head;
        while (temp->next != nullptr){
          temp = temp->next; // Traverse to the last node
        }
        temp->next = newNode; // Link the last node to newNode
      }
    }


    void insertAtFront(int new_data)
    {
        // Create a new node with the given data
        Node* new_node = new Node(new_data);
    
        // Make the next of the new node point to the current
        // head
        new_node->next = head;
        head = new_node;
    }


    // Function to delete a Node by Value
    void deleteByValue(int value){
      if(head == nullptr){
        return;
      }
      if(head->data == value){
        Node* temp = head;
        head = head->next; // Move head to the next node
        delete temp; // Free memory of the deleted node
        return;
      }
      Node* temp = head;
      while(temp->next && temp->next->data != value){
        temp = temp->next; // Traverse to find the node to delete 
      }
      if(temp->next){
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next; // Unlink the node
        delete nodeToDelete; //Free Memory
      }
    }

    // Function to display the list
    void display(void){
      Node* temp = head;
      while(temp != nullptr){
        cout << temp->data << "->";
        temp = temp->next;
      }
      cout << "NULL" <<endl;
    }
    
    
    // Counts number of nodes in linked list
    int countNodes(void) {
        // Initialize count with 0
        int count = 0;
        // Initialize curr with head of Linked List
        Node* curr = head;
    
        // Traverse till we reach nullptr
        while (curr != nullptr) {
            // Increment count by 1
            count++;
            // Move pointer to next node
            curr = curr->next;
        }
        // Return the count of nodes
        return count;
    }
    
    
    
    
    // Function to remove every kth node in the linked list
    void deleteEveryKNode(int k) {
    
      // If list is empty or k is 0, return the head
      if (head == nullptr || k <= 0) 
          return;
    
      Node* curr = head;
      Node* prev = nullptr;
      
      // Initialize counter to track node positions
      int count = 0;
    
      // Traverse the linked list
      while (curr != nullptr) {
          count++;
    
          // If count is a multiple of k, remove current node
          if (count % k == 0) {
            
              // skip the current node
              if (prev != nullptr) {
                  prev->next = curr->next;
              } 
              else {
                
                  head = curr->next;
              }
          } 
          else {
            
              // Update previous node pointer only if
              // we do not remove the node
              prev = curr;
          }
          curr = curr->next;
      }
    
    }



    // checks whether key is present in linked list
    bool searchKey(int key) {
        // initialize curr with the head of linked list
        Node* curr = head;
    
        // iterate over all the nodes
        while (curr != NULL) {
            // If the current node's value is equal to key,
            // return true
            if (curr->data == key)
                return true;
    
            // move to the next node
            curr = curr->next;
        }
    
        // if there is no node with value as key, return false
        return false;
    }





    // Function to find the nth node in the list
    int GetNth(int index) {
        Node *curr = head;
        int count = 1;
    
        while (curr != nullptr) {
            if (count == index)
                return curr->data;
            count++;
            curr = curr->next;
        }
    
        return -1;
    }


    // Function to insert a new node after a given node
    void insertAfter(int key, int newData)
    {
        // Initilize curr Pointer to head
        Node* curr = head;
    
        // Iterate over Linked List to find the key
        while (curr != nullptr) {
            if (curr->data == key)
            {
                break;
            }
            curr = curr->next;
        }
   
        // if curr becomes NULL means, given key is not
        // found in linked list
        //if (curr == nullptr)
        //   break;
    
        // Allocate new node by given data and point
        // the next of newNode to curr's next &
        // point current next to newNode
        Node* newNode = new Node(newData);
        newNode->next = curr->next;
        curr->next = newNode;
        //return ;
    }



    // Function to insert a node at a specific position in the
    // linked list.
    void insertAtPosition(int position, int data)
    {
        Node* newNode = new Node(data);
    
        // If inserting at the beginning
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
    
        Node* current = head;
        // Traverse the list to find the node before the
        // insertion point
        for (int i = 1; i < position - 1 && current != nullptr;
             ++i) {
            current = current->next;
        }
    
        // If the position is out of bounds
        if (current == nullptr) {
            cout << "Position is out of bounds." << endl;
            delete newNode; // Deallocate memory to prevent
                            // memory leak
            return;
        }
    
        // Insert the new node at the specified position
        newNode->next = current->next;
        current->next = newNode;
    }
    
    
    // Function to find the Nth node from the last of a linked list
    int findNthFromLast(int N) {
        int len = 0, i;
      
        // Pointer to store the copy of head
        Node* temp = head;
    
        // Count the number of nodes in Linked List
        while (temp != NULL) {
            temp = temp->next;
            len++;
        }
    
        // Check if value of N is not
        // more than length of the linked list
        if (len < N)
            return -1;
    
        temp = head;
    
        // Get the (len - N + 1)th node from the beginning
        for (i = 1; i < len - N + 1; i++)
            temp = temp->next;
    
        return temp->data;
    }

//TODO: Issue
//   void reverseList(void) {
//   
//       Node *curr = head, *prev = nullptr, *next;
//   
//       // Traverse all the nodes of Linked List
//       while (curr != nullptr) {
//   
//           // Store next
//           next = curr->next;
//   
//           // Reverse current node's next pointer
//           curr->next = prev;
//   
//           // Move pointers one position ahead
//           prev = curr;
//           curr = next;
//       }
//   
//       //return;
//   }
   
   
    // Delete the head node and return the new head
    void deleteHead(void) {
      
        // Check if the list is empty
        if (head == nullptr)
            return;
    
        // Store the current head in a
        // temporary variable
        Node* temp = head;
    
        // Move the head pointer to the next node
        head = head->next;
    
        // Free the memory of the old head node
        delete temp;
    
        //return;
    }

    void deleteNode(int position) {
        Node* temp = head;
    
        // Head is to be deleted
        if (position == 1) {
            head = temp->next;
            delete temp;
            return;
        }
    
        // Traverse to the node 
        // before the one to be deleted
        Node* prev = nullptr;
        for (int i = 1; i < position; i++) {
            prev = temp;
            temp = temp->next;
        }
    
        // Delete the node at the position
        prev->next = temp->next;
        delete temp;
    
    }
   
   
   
    // Function to remove the last node
    // of the linked list
    void removeLastNode(void) {
        // If the list is empty, return nullptr
        if (head == nullptr) {
            return;
        }
    
        // If the list has only one node, delete it and return nullptr
        if (head->next == nullptr) {
            delete head;
            return;
        }
    
        // Find the second last node
        Node* secondLast = head;
        while (secondLast->next->next != nullptr) {
            secondLast = secondLast->next;
        }
    
        // Delete the last node
        delete secondLast->next;
    
        // Change next of second last
        secondLast->next = nullptr;
    
    }
   


    // Function to remove duplicates using nested loops
    void removeDuplicates(void) {
        Node* curr1 = head; 
    
        // Traverse each node in the list
        while (curr1 != nullptr) {
            Node* curr2 = curr1; 
    
            // Traverse the remaining nodes to find and 
            // remove duplicates
            while (curr2->next != nullptr) {
                
                // Check if the next node has the same 
                // data as the current node
                if (curr2->next->data == curr1->data) {
                    
                    // Duplicate found, remove it
                    Node* duplicate = curr2->next;  
                    curr2->next = curr2->next->next;  
    
                    // Free the memory of the duplicate node
                    delete duplicate;
                } else {
                  
                    // If the next node has different data from 
                    // the current node, move to the next node
                    curr2 = curr2->next;
                }
            }
            
            // Move to the next node in the list
            curr1 = curr1->next;
        }
    }


    void removeDuplicates2(void) {
        unordered_set<int> hashSet;
        Node *curr = head;
        Node *prev = nullptr;
    
        while (curr != nullptr) {
    
            // Check if the element is already in the hash table
            if (hashSet.find(curr->data) != hashSet.end()) {
    
                // Element is present, remove it
                prev->next = curr->next;
    
                // Delete the curr node
                Node *temp = curr;
                curr = curr->next;
                delete temp;
            }
            else {
    
                // Element is not present, add it to hash table
                hashSet.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
    }
    



    //***************START Linked List Quicksort**************
    // Returns the last node of the list
    Node* getTail(Node* cur) {
        while (cur != nullptr && cur->next != nullptr)
            cur = cur->next;
        return cur;
    }

    // Partitions the list taking the first element as the pivot
    Node* partition(Node* head, Node* tail) {
      
      	// Select the first node as the pivot node
        Node* pivot = head;
      
        // 'pre' and 'curr' are used to shift all 
      	// smaller nodes' data to the left side of the pivot node
        Node* pre = head;
        Node* curr = head;
    
        // Traverse the list until you reach the node after the tail
        while (curr != tail->next) {
            
            if (curr->data < pivot->data) {
                swap(curr->data, pre->next->data);
              
                // Move 'pre' to the next node
                pre = pre->next;
            }
            
          	// Move 'curr' to the next node
            curr = curr->next;
        }
        
        swap(pivot->data, pre->data);
        
      	// Return 'pre' as the new pivot
        return pre;
    }
    
    // Helper function for quick sort
    void quickSortHelper(Node* head, Node* tail) {
      
        // Base case: if the list is empty or consists of a single node
        if (head == nullptr || head == tail) {
            return;
        }
        
      	// Call partition to find the pivot node
        Node* pivot = partition(head, tail);
        
      	// Recursive call for the left part of the list (before the pivot)
        quickSortHelper(head, pivot);
        
      	// Recursive call for the right part of the list (after the pivot)
        quickSortHelper(pivot->next, tail);
    }
    
    // The main function for quick sort. This is a wrapper over quickSortHelper
    void quicksort(void) {
        
        Node* tail = getTail(head);
        
      	// Call the helper function to sort the list
        quickSortHelper(head, tail);
        
    }
    //***************END Linked List Quicksort**************


   
//TODO: Issue
//void deleteList(void) {
//
//    // Base case: If the list is empty, return
//    if (head == nullptr) {
//        return;
//    }
//
//    // Recursively delete the next node
//    deleteList(head->next);
//
//    // Delete the current node
//    delete head;
//}

  
    // Destructor to free all allocated memory
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.insertAtEnd(60);
    list.insertAtEnd(70);
    list.insertAtEnd(80);

    cout << "Linked List: ";
    list.display();

    int val = 20;
    cout << "Delete value " << val << "    ";
    list.deleteByValue(val);
    list.display();

    cout << "After Deleting 20: ";
    list.display();

    cout << "Number of nodes: " << list.countNodes() << "\n";

    int k = 3;
    list.deleteEveryKNode(k);
    cout << "Delete every key " << k << " node: ";
    list.display();

    val = 30;
    string res;
    res = list.searchKey(val)?"True":"False";
    cout << "Is " << val << " in the list? " << res << "\n";
    
    val = 11;
    res = list.searchKey(val)?"True":"False";
    cout << "Is " << val << " in the list? " << res << "\n";

    int index = 3;
    cout << "The value at index " << index << " is " <<  list.GetNth(index) << "\n";
    index = 4;
    cout << "The value at index " << index << " is " <<  list.GetNth(index) << "\n";

    val = 25;
    cout << "Insert at the front: " << val << "    ";
    list.insertAtFront(val);
    list.display();

    val = 35;
    cout << "Insert at the front: " << val << "    ";
    list.insertAtFront(val);
    list.display();
    
    int data = 10;
    val = 15;
    cout << "Insert after data " << data << " value " << val << "    ";
    list.insertAfter(data, val);
    list.display();

    data = 50;
    val = 55;
    cout << "Insert after data " << data << " value " << val << "    ";
    list.insertAfter(data, val);
    list.display();

    int position = 4;
    data = 50;
    cout << "Insert value " << data << " at position " << position << "    ";
    list.insertAtPosition(position, data);
    list.display();

    position = 2;
    data = 100;
    cout << "Insert value " << data << " at position " << position << "    ";
    list.insertAtPosition(position, data);
    list.display();

    position = 3;
    cout << "The node with position " << position << " from the end contains " << list.findNthFromLast(position) << "\n";
    position = 5;
    cout << "The node with position " << position << " from the end contains " << list.findNthFromLast(position) << "\n";

    //cout << "The list is reversed:  ";
    //list.display();
    //list.reverseList();
    //list.display();

    cout << "Delete the head   ";
    list.deleteHead();
    list.display();
    
    cout << "Delete the head   ";
    list.deleteHead();
    list.display();

    position = 2;
    cout << "Delete node number: " << position << "   ";
    list.deleteNode(position);
    list.display();

    position = 4;
    cout << "Delete node number: " << position << "   ";
    list.deleteNode(position);
    list.display();

    cout << "Delete last node:   ";
    list.removeLastNode();
    list.display();

    cout << "Delete last node:   ";
    list.removeLastNode();
    list.display();


    cout << "Remove duplicates: \n";
    cout << "   Insert duplicate values 20 at the end" << "    ";
    list.insertAtEnd(20);
    list.insertAtEnd(20);
    list.insertAtEnd(20);
    list.insertAtEnd(20);
    list.display();
    list.removeDuplicates();
    cout << "   Duplicates are removed:   ";
    list.display();


    cout << "Remove duplicates(function 2): \n";
    cout << "   Insert duplicate values 23 at the end" << "    ";
    list.insertAtEnd(23);
    list.insertAtEnd(23);
    list.insertAtEnd(23);
    list.insertAtEnd(23);
    list.display();
    list.removeDuplicates2();
    cout << "   Duplicates are removed:   ";
    list.display();


    cout << "   Quick sort:   ";
    list.quicksort();
    list.display();








    return 0;
}