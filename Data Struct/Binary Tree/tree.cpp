#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *pLeft;
    struct node *pRight;
};
typedef struct node NODE;
typedef NODE *TREE;

// KHởi tạo cây
void createTree(TREE &t)
{
    t = NULL;
}

// Thêm phần tử vào cây nhị Phân
void addNodeToTree(TREE &t, int x)
{
    if (t == NULL)
    {
        NODE *p = new NODE; // create a Node to add to TREE
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p; // Node p chính là NOde gốc <=> x chính là NODE gốc.
    }
    else // If tree has ellement.
    {
        if (t->data > x)
        {
            addNodeToTree(t->pLeft, x); // Duyệt qua trái để Thêm phần Tử x
        }
        else if (t->data < x)
        {
            addNodeToTree(t->pRight, x);
        }
    }
}

void Duyet_NLR(TREE t)
{
    // If the tree has element , then countinue traversing
    if (t != NULL)
    {
        cout << t->data << " ";
        Duyet_NLR(t->pLeft);
        Duyet_NLR(t->pRight);
    }
}

void Menu(TREE &t)
{
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t===========MENU===========";
        cout << "\n1. Input data";
        cout << "\n2. Export data of TREE (NLR)";
        cout << "\n0. End";
        cout << "\n\n\t\t===========END===========";

        int choose;
        cout << "\nInput choose: ";
        cin >> choose;

        if (choose < 0 || choose > 2)
        {
            cout << "Invalid selection!!";
            system("pause");
        }
        else if (choose == 1)
        {
            int x;
            cout << "\nInput data for X : ";
            cin >> x;
            addNodeToTree(t, x);
        }
        else if (choose == 2)
        {
            cout << "\n\n\tTraversing TREE by NLR\n";
            Duyet_NLR(t);
            system("pause");
        }
        else
        {
            break;
        }
    }
}
int main()
{
    TREE t;
    createTree(t);
    Menu(t);

    system("pause");
    return 0;
}