#include <iostream>
using namespace std;

struct Item
{
    int data;
    Item *next;
};

void walk(Item *list)
{
    while (list != NULL)
    {
        cout << list->data << (list->next != NULL ? ", " : "");
        list = list->next;
    }
    cout << endl;
}

Item *sort(Item *head)
{
    bool changed = true;
    while (changed)
    {
        Item *current = head;
        Item *pre = head;
        changed = false;
        while (current->next != NULL)
        {
            if (current->data > current->next->data)
            {
                if (current == head)
                {
                    head = current->next;
                }
                Item *temp = current->next;
                pre->next = temp;
                temp->next = current;
                current->next = temp->next;
                pre = temp;
                changed = true;
            }
            else
            {
                pre = current;
                current = current->next;
            }
        }
    }
    return head;
}
/*
* Add an item to the beginning of the dynamic list having it's head the **head**
* Returns the new head!
*/
Item *unshift(Item *head, Item *item)
{
    if (head != NULL)
    {
        item->next = head;
        head = item;
    }
    return head;
}

int count(Item *list)
{
    int size = 0;
    while (list != NULL)
    {
        size++;
        list = list->next;
    }
    return size;
}

void add(Item *head, int index, Item *item)
{
    if (head != NULL && index > 1 && index < count(head))
    {
        while (index - 1 > 1)
        {
            head = head->next;
            index--;
        }
        item->next = head->next;
        head->next = item;
    }
}

/*
* Add an item to the end of the dynamic list*
* list - head of the list
* item - item to be added
*/
void push(Item *list, Item *item)
{
    if (list != NULL)
    {
        while (list->next != NULL)
        {
            list = list->next;
        }
        list->next = item;
    }
}

/*
*Remove an item from the beginning of an Array
*/
Item *shift(Item *head)
{
    if (head != NULL)
    {
        Item *remove = head;
        head = head->next;
        delete remove;
    }
    return head;
}

/*
 * Remove an item from the end of an Array
 */

Item *pop(Item *head)
{
    if (head != NULL)
    {
        if (head->next == NULL)
        {
            delete head;
            return NULL;
        }

        Item *list = head;
        while (list->next->next != NULL)
        {
            list = list->next;
        }
        delete list->next;
        list->next = NULL;
    }

    return head;
}

Item *makeItem(int data)
{
    Item *item = new Item();
    item->next = NULL;
    item->data = data;
    return item;
}

int main()
{

    Item *head = makeItem(1);

    push(head, makeItem(2));
    push(head, makeItem(3));
    push(head, makeItem(4));
    // 1,2,3,4
    walk(head);

    head = unshift(head, makeItem(5));
    head = unshift(head, makeItem(6));
    // 6,5,1,2,3,4
    walk(head);
    //6
    cout << count(head) << endl;

    pop(head);
    pop(head);

    // 6,5,1,2
    walk(head);

    head = shift(head);
    head = shift(head);
    // 1,2
    walk(head);
    //2
    cout << count(head) << endl;

    push(head, makeItem(7));
    push(head, makeItem(8));
    // 1,2,7,8
    walk(head);
    add(head, 2, makeItem(9));
    add(head, 2, makeItem(10));

    // 1,10,9,2,7,8
    walk(head);

    add(head, 5, makeItem(11));
    // 1,10,9,2,11,7,8
    walk(head);

    pop(head);
    pop(head);
    pop(head);
    pop(head);
    pop(head);
    pop(head);
    //1, 10, 9, 2
    walk(head);

    push(head, makeItem(0));
    // 1, 2
    walk(head);

    head = sort(head);
    //1, 2, 9, 10
    walk(head);
    return 0;
}