#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
typedef struct Node *node;

node makeNode(int x)
{
    node temp = new Node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}

int Size(node head)
{
    int count = 0;
    while (head->next != NULL)
    {
        ++count;
        head = head->next;
    }
    return count;
}

void addFirst(node &head, int x)
{
    node temp = makeNode(x);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void addLast(node &head, int x)
{
    node temp = makeNode(x);
    if (head == NULL)
    {
        head = temp;
    }
    node p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
}

void addBetween(node &head, int x, int pos)
{
    int n = Size(head);
    if (pos <= 0 && pos > n + 1)
    {
        cout << "\nVi tri chen khong hop le!!!";
        return;
    }
    if (pos == 1)
    {
        addFirst(head, x);
    }
    else if (pos == n + 1)
    {
        addLast(head, x);
    }
    node p = head;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    node temp = makeNode(x);
    temp->next = p->next;
    p->next = temp;
}

void exportLinkedList(node head)
{
    cout << "\n--------------------------------\n";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << "\n--------------------------------\n";
}

// ================================
void deleteFirst(node &head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        head = head->next;
    }
}

void deleteLast(node &head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        node before = NULL, after = head;
        while (after->next != NULL)
        {
            before = after;
            after = after->next;
        }
        before->next = NULL;
    }
}

void deleteBetween(node &head, int pos)
{
    int n = Size(head);
    if (pos <= 0 && pos > n)
    {
        cout << "\nVi tri xoa khong hop le!!!";
        return;
    }

    node before = NULL, after = head;
    for (int i = 1; i < pos; i++)
    {
        before = after;
        after = after->next;
    }
    if (before == NULL)
    {
        head = head->next;
    }
    else
    {
        before->next = after->next;
    }
}

int main()
{
    node head = NULL;
    while (1)
    {
        system("cls");
        cout << "\n--------------------------------\n";
        cout << "\n1. Add First";
        cout << "\n2. Add Last";
        cout << "\n3. Add Between";
        cout << "\n4. Export LinkedList";
        cout << "\n5. Delete First";
        cout << "\n6. Delete Last";
        cout << "\n7. Delete Between";
        cout << "\n0. Thoat";
        cout << "\n--------------------------------\n";
        int choose;
        cout << "\nEnter option: ";
        cin >> choose;

        if (choose == 1)
        {
            int x;
            cout << "\nEnter the value to add at the first: ";
            cin >> x;
            addFirst(head, x);
        }
        else if (choose == 2)
        {
            int x;
            cout << "\nEnter the value to add at the last: ";
            cin >> x;
            addLast(head, x);
        }
        else if (choose == 3)
        {
            int x;
            cout << "Enter the value to add at the between: ";
            cin >> x;
            int pos;
            cout << "\nEnter position to add: ";
            cin >> pos;
            addBetween(head, x, pos);
        }
        else if (choose == 4)
        {
            exportLinkedList(head);
            system("pause");
        }
        else if (choose == 5)
        {
            deleteFirst(head);
        }
        else if (choose == 6)
        {
            deleteLast(head);
        }
        else if (choose == 7)
        {
            int pos;
            cout << "\nEnter index to delete: ";
            cin >> pos;
            deleteBetween(head, pos);
        }

        else if (choose == 0)
        {
            break;
        }
    }
    return 0;
}