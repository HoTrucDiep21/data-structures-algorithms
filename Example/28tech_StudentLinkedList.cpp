#include <iostream>
#include <string>
using namespace std;
struct dataStudent
{
    string id, name;
    int age;
    float gpa;
};
struct nodeStudent
{
    dataStudent s;
    nodeStudent *next;
};
typedef struct nodeStudent *node;

node makeNode()
{
    dataStudent s;
    fflush(stdin);
    cout << "\nEnter id: ";
    getline(cin, s.id);
    cout << "\nEnter name: ";
    getline(cin, s.name);
    cout << "\nEnter age: ";
    cin >> s.age;
    cout << "\nEnter gpa: ";
    cin >> s.gpa;

    node tmp = new nodeStudent();
    tmp->s = s;
    tmp->next = NULL;
    return tmp;
}
bool checkEmpty(node head)
{
    return head == NULL;
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
// Add node
void addNodeFirst(node &head)
{
    node tmp = makeNode();
    if (head == NULL)
    {
        head = tmp;
    }
    else
    {
        tmp->next = head;
        head = tmp;
    }
}
// Add last
void addNodeLast(node &head)
{
    node tmp = makeNode();
    if (head == NULL)
    {
        head = tmp;
    }
    else
    {
        node p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
}
// Shows information Student
void exportStudent(dataStudent s)
{
    cout << "\n--------------------\n";
    cout << "\nId: " << s.id;
    cout << "\nName: " << s.name;
    cout << "\nAge: " << s.age;
    cout << "\nGPA: " << s.gpa;
    cout << "\n--------------------\n";
}
// Show list
void exportLinkedList(node head)
{
    cout << "\nInformation of LinkedList";
    while (head != NULL)
    {
        exportStudent(head->s);
        head = head->next;
    }
    cout << endl;
}
int main()
{
    node head = NULL;
    while (1)
    {
        system("cls");
        cout << "\n=========Menu=========";
        cout << "\n1. Add First";
        cout << "\n2. Add Last";
        cout << "\n9. Export";
        cout << "\n0. Exit";
        cout << "\n=========End=============";
        int choose;
        cout << "\nEnter choose: ";
        cin >> choose;
        if (choose == 1)
        {
            addNodeFirst(head);
        }
        else if (choose == 2)
        {
            addNodeLast(head);
        }

        else if (choose == 9)
        {
            exportLinkedList(head);
            system("pause");
        }
        else if (choose == 0)
        {
            break;
        }
    }

    system("pause");
    return 0;
}