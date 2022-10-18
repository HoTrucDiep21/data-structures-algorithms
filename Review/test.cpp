#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *pL;
    struct node *pR;
};
typedef struct node NODE;
// Create Tree
void createTree(NODE *&t)
{
    t = NULL;
}
void addNode(NODE *&t, int x)
{
    if (t == NULL)
    {
        NODE *p = new NODE;
        p->data = x;
        p->pL = NULL;
        p->pR = NULL;
        t = p;
    }
    else
    {
        if (t->data > x)
        {
            addNode(t->pL, x);
        }
        else if (t->data < x)
        {
            addNode(t->pR, x);
        }
    }
}
// Traversing Tree
void traversingTree(NODE *t)
{
    if (t == NULL)
    {
        return;
    }

    traversingTree(t->pL);
    cout << t->data << " ";
    traversingTree(t->pR);
}
void menu(NODE *t)
{
    int chosen;
    while (true)
    {
        system("cls");
        cout << "\n-----------\n";
        cout << "\n1. Add Node";
        cout << "\n2. Traversing Tree\n";
        cout << "\n----------\n";

        cout << "\nInput chosen: ";
        cin >> chosen;

        if (chosen == 1)
        {
            int x;
            cout << "\nInput data for X = ";
            cin >> x;
            addNode(t, x);
        }
        else if (chosen == 2)
        {
            traversingTree(t);
            system("pause");
        }
    }
}
int main()
{
    NODE *t;
    createTree(t);

    menu(t);

    return 0;
}
