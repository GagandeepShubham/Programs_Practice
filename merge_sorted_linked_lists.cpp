/**
 * A program to merge two sorted linked lists.
**/

#include<iostream>
using namespace std;

struct node
{
  int val;
  node *next;
};

node * insert(int data, node *root) //function to insert a node in the ll whose root is root.
{
    node *temp = new node();
    temp -> val = data;
    temp -> next = NULL;
    if(root == NULL)root = temp;
    else
    {
       node *temp1 = root;
       while(temp1 -> next != NULL)temp1 = temp1 -> next;
       temp1 -> next = temp;
    }
    return root;
}

void print_list(node *temp) //function to print a linked list.
{
  while(temp != NULL)
  {
    cout << temp -> val << " ";
    temp = temp -> next;
  }
  cout << "\n";
}

node * merge_two_list(node *l1, node *l2)
{
    node *root = NULL;

    //check if either of the linked list is empty.
    if(l1 == NULL)  //if list1 is empty then make the root list2 as root and return
    {
      root = l2;
      return root;
    }
    else if(l2 == NULL)//else if list2 is empty then make the root list1 as root and return
    {
      root = l1;
      return root;
    }

    node *temp1 = l1;
    node *temp2 = l2;
    while(temp1 != NULL && temp2 != NULL) //traverse both the list.
    {
      if(temp1 -> val == temp2 -> val) //if both the current node has same value then insert both node in new ll
      {
        root = insert(temp1 -> val, root);
        root = insert(temp2 -> val, root);
        temp1 = temp1 -> next;        //move on to the next node.
        temp2 = temp2 -> next;        //move on to the next node.
      }
      else if(temp1 -> val < temp2 -> val) //if ll1 has smaller node than in ll2 then insert that node.
      {
        root = insert(temp1 -> val, root);
        temp1 = temp1 -> next;          //move on to the next node.
      }
      else if(temp1 -> val > temp2 -> val) //else ll2 has smaller node than in ll1 then insert that node.
      {
        root = insert(temp2 -> val, root);
        temp2 = temp2 -> next;         //move on to the next node.
      }
    }

    //this is the case when ll's are like as follows:
    //ll1: 1, 2, 3
    //ll2: 4, 5, 6
    //then you can see that ll1 would be over first and then we have to put
    //the ll2 list as it is in the end of our resultant ll.
    if(temp1 == NULL && temp2 != NULL) 
    {
      node *temp3 = root;
      while(temp3 -> next != NULL)temp3 = temp3 -> next;
      temp3 -> next = temp2;
    }
    else if(temp2 == NULL && temp1 != NULL)
    {
      node *temp3 = root;
      while(temp3 -> next != NULL)temp3 = temp3 -> next;
      temp3 -> next = temp1;
    }
    return root;
}

int main()
{
  int i, n, data;
  node *l1 = NULL;
  cout << "Enter total nodes of ll1: ";
  cin >> n;
  for(i = 0; i < n; i++)
  {
     cout << "Enter data: ";
     cin >> data;
     l1 = insert(data, l1);
  }

  cout << "\nLinked list1: ";
  print_list(l1); //prints the linked list.

  node *l2 = NULL;
  cout << "\nEnter total nodes of ll2: ";
  cin >> n;
  for(i = 0; i < n; i++)
  {
    cout << "Enter data: ";
    cin >> data;
    l2 = insert(data, l2);
  }

  cout << "\nLinked list2: ";
  print_list(l2); //print the ll2

  node *root = merge_two_list(l1, l2);

  cout << "\nMerged linked list: ";
  print_list(root); //print the merged list.
}
