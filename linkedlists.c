#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int val;
    struct node * next;
}node_t;

void print_list(node_t * head)
{
    node_t * current = head;
    
    while (current != NULL)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void node_append(node_t * head, int val)
{
    node_t * current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void node_prepend(node_t ** head, int val)
{
    node_t * new_node;
    new_node = malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int pop(node_t ** head)
{
    int val = -1;
    node_t * new_head = NULL;

    if(*head == NULL)
    {
        return -1;
    }

    new_head = (*head)->next;
    val = (*head)->val;
    free(*head);
    *head = new_head;

    return val;
}

int remove_last(node_t * head)
{
    int val = 0;
    if (head->next == NULL)
    {
        val = head->val;
        free(head);
        return val;
    }

    node_t * current =  head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    val = current->next->val;
    free(current->next);
    current->next = NULL;

    return val;
}

int remove_by_index(node_t ** head, int n)
{
    int val = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;

    if (n == 0)
    {
        return pop(head);
    }

    for (int i = n; i > 0; i--)
    {
        if (current->next == NULL)
        {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    val = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return val;
}

int remove_by_value(node_t ** head, int n)
{
    node_t * current = *head;
    node_t * temp_node = NULL;
    int val;

    if (current->val == n)
    {
        return pop(head);
    }

    while (current->next->val != n)
    {
        if (current->next == NULL)
        {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    val = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return val;
}

int main()
{
    return 0;
}
