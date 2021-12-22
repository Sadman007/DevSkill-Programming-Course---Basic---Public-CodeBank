#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    vector<node*>next;
    node()
    {
        value = 0;
        next.push_back(NULL);
    }
    node(int _value)
    {
        value = _value;
        next.push_back(NULL);
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
    while(copy_head -> next[0] != NULL)
    {
        copy_head = copy_head -> next[0];
    }
    copy_head -> next[0] = tmp;
}

// List has been populated with n values from 1 to n.
void populate_list(int n)
{
    for (int i = 0; i < n; i++)
    {
        insert_at_tail(i + 1);
    }
    printf("Populating is complete!\n");
}

void populate_next_pointer_list(int n)
{
    int k = log2(n);
    for (int j = 1; j <= k; j++)
    {
        node* copy_head = head;
        while(copy_head->next[j - 1] != NULL)
        {
            copy_head->next.push_back(copy_head->next[j - 1]->next[j - 1]);
            copy_head = copy_head->next[0];
        }
    }
}

void print_linked_list()
{
    node* copy_head = head;
    while(copy_head != NULL) /// [1, address(2)] -----> [2, address(3)] ----> [3, NULL]
    {
        printf("%d ", copy_head->value);
        copy_head = copy_head -> next[0];
    }
}

// 0-based indexing
int get_element_at(int index)
{
    node* curr = NULL;
    node* copy_head = head;
    for (int i = 30; i >= 0; i--)
    {
        int state = index & (1 << i);
        if (state > 0)
        {
            curr = copy_head->next[i];
            copy_head = curr;
        }
    }
    if (curr) return curr->value;
    return -1; // Let's assume we won't have -1 as our value.
}

int main()
{
    int n = 1000;
    populate_list(n);
    populate_next_pointer_list(n);
    cout << get_element_at(654);
    return 0;
}
