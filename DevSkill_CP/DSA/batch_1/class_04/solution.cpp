#include <bits/stdc++.h>
using namespace std;
#define DUMMY 0

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

node* head = new node(DUMMY);

void insert_at_tail(int value)
{
    node* copy_head = head; /// [dummyValue, address(1)] ---> [1, address(2)] ---> [2, address(3)] ---> [3, address(4)] ---> [4, address(5)] ---> [5, NULL]
    while(copy_head -> next != NULL)
    {
        copy_head = copy_head -> next;
    }
    copy_head -> next = new node(value);
}

void insert_at_head(int value)
{
    node* nextNode = head->next;
    head->next = new node(value);
    head->next->next = nextNode;
}

int get_element_at(int position) /// [1, 2, 3] -> get_element_at(2) = 3
{
    node* curr = head->next;
    while(position--)
    {
        curr = curr->next;
    }
    return curr->value;
}

void delete_at(int position)
{
    node* curr = head; /// [D, (3), 2, (1)]
    while(position--)
    {
        curr = curr -> next;
    }
    node* nextNode = curr->next->next;
    curr->next = nextNode;
}

/// TO-DO
void add_at(int position) /// [D, 1, 2, 3] --> [D, 1, v, 2, 3]
{

}

void print_linked_list()
{
    node* copy_head = head -> next;
    while(copy_head != NULL) /// [1, address(2)] -----> [2, address(3)] ----> [3, NULL]
    {
        printf("%d ", copy_head -> value);
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
    insert_at_head(1); /// [1]
    insert_at_head(2); /// [2, 1]
    insert_at_head(3); /// [3, 2, 1]
    delete_at(2);
    print_linked_list();
    //print_linked_list();
    return 0;
}
