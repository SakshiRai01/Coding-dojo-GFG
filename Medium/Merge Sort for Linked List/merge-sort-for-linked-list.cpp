//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
  
  Node* findMid(Node* l)
  {
      Node* slow = l;
      Node* fast = l->next;
      
      while(fast!= NULL && fast->next != NULL)
      {
          slow = slow->next;
          fast = fast->next->next;
      }
      return slow;
  }
  
  Node* merge(Node* a , Node* b)
  {
      
      if(a==NULL)
      return b;
      
      if(b==NULL)
      return a;
      
      
      Node* ans = new Node(NULL);
      Node* temp = ans;
      while(a!= NULL && b!= NULL)
      {
          if(a->data < b->data)
          {
              temp->next = a;
             temp = a;
             a = a->next;
          }
          
          else
          {
              temp->next = b;
             temp = b;
             b = b->next;
          }
      }
      
      while(a!=NULL)
      {
          temp->next = a;
             temp = a;
             a = a->next;
      }
      
      while(b!=NULL)
      {
          temp->next = b;
             temp = b;
             b = b->next;
      }
      ans = ans->next;
      return ans;
  }
  
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head->next == NULL)
        return head;
        
        
        Node* mid = findMid(head);
        Node* left = head;
        Node* right = mid->next;
        mid -> next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        Node* result = merge(left, right);
        return result;
        
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends