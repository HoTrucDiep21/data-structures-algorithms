#include <iostream>

using namespace std;


struct node
{
    int data;
    struct node *pL;
    struct node *pR;
};
typedef struct node NODE;

void createTree(NODE *&t)
{
    t = NULL;
}

void addNodeToTree(NODE *&t, int x)
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
            addNodeToTree(t->pL, x);
        }
        else if (t->data < x)
        {
            addNodeToTree(t->pR, x);
        }
    }
}
void TraversingTree(NODE *t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        TraversingTree(t->pL);
        TraversingTree(t->pR);
    }
}

void Menu(NODE *t)
{
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t=========MENU=========";
        cout << "\n1. Add Node To Tree";
        cout << "\n2. Traversing Tree";
        cout << "\n0. Finished!!";
        cout << "=========END=========";

        int choose;
        cout << "\n\tInput choose: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            int x;
            cout << "\n\tInput data: ";
            cin >> x;
            addNodeToTree(t, x);
            break;
        case 2:
            TraversingTree(t);
            system("pause");

            break;

        default:
            break;
        }
    }
}

int main()
{
    NODE *t;

    createTree(t);
    Menu(t);
    
    system("pause");
    return 0;
}