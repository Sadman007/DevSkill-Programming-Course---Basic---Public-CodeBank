#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    node* next;

    // constructor
    node()
    {
        value = 0;
        next = NULL;
    }

    node(int _value)
    {
        value = _value;
        next = NULL;
    }

    // helper functions
    void print_value()
    {
        cout << value;
    }
};

node* head = NULL;

void insert_at_tail(int value)
{
    // Create a node variable with value = 2 and next = NULL.
    node* tmp = new node(value);
    if (head == NULL)
    {
        head = tmp;
        return;
    }
    node* copy_head = head; /// [1, address(2)] ---> [2, address(3)] ---> [3, address(4)] ---> [4, address(5)] ---> [5, NULL]
    while(copy_head -> next != NULL)
    {
        copy_head = copy_head -> next;
    }
    copy_head -> next = tmp;
}

void print_linked_list()
{
    node* copy_head = head;
    while(copy_head != NULL) /// [1, address(2)] -----> [2, address(3)] ----> [3, NULL]
    {
        printf("%d ", copy_head->value);
        copy_head = copy_head -> next;
    }
}

/**
void bulk_insert_at_tail(vector<int> list_of_elements)
{
    for (int value : list_of_elements)
    {
        insert_at_tail(value);
    }
}
**/

int main()
{
    insert_at_tail(1);
    insert_at_tail(2);
    insert_at_tail(3);
    print_linked_list();
    return 0;
}
