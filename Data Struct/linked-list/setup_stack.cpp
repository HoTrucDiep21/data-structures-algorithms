// Set up Stack using LINked lis
#include<iostream>
using namespace std;

struct Node
{
    int data;
    int *next;

};
typedef struct Node *node;

node makeNode(int x){
    node tmp = new Node;
    tmp->data = x;
    tmp->next = NULL;

    return tmp;
}


int main(){

}