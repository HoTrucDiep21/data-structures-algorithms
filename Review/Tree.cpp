#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *pL;
    struct node *pR;

};
typedef struct node NODE;
// Create Tree
void createTree(NODE* &t){
    t = NULL;
}
// add Node to Tree
void addNodeToTree(NODE* &t, int x){
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
        }else if (t->data < x)
        {
            addNodeToTree(t->pR, x);
        }
        
        
    }
    
    

}
//Traversing
void TraversingNLR(NODE* t){
    if (t != NULL)
    {
        cout << t->data << " ";
        TraversingNLR(t->pL);
        TraversingNLR(t->pR);
    }
    

}

int main(){
    

    return 0;
}