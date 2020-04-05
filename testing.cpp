#include <iostream>
using namespace std;
struct Element{
    int data;
    Element *next;
};
struct List{
    int n;
    Element *head;
    Element *tail;

};
//create list
List *createList(List *ls);
//create addTobegin
void createToBegin(List *ls,int dataNew);
//create display
void displayAllData(List *ls);
//create DeleteBegin
void DeleteBegin(List *ls);
//add the end
void endList(List *ls, int dataNew);
//delete end
void deleteEnd(List *ls);
int main(){
    
}
void deleteEnd(List *ls){
    Element *tmp,*c;
    if (ls->n==0)
    {
        ls->head=NULL;
        ls->tail=NULL;
    }
    tmp = ls->tail;
    c->next=NULL;
    ls->tail->next =c;
    ls->tail=c;
    delete tmp;
    ls->n--;

}
void endList(List *ls, int dataNew){
    Element *e;
    e= new Element;
    if (ls->n==0)
    {
        createToBegin(ls,dataNew);
    }
    //update tail
    else
    {
        e->data=dataNew;
        e->next =NULL;
        ls->tail->next=e;
        ls->tail=e;
        ls->n++;
    }
    
}
void DeleteBegin(List *ls){
    Element *tmp;
    //set next become head
    tmp=ls->head;
    ls->head = ls->head->next;
    //delete head
    delete tmp;
    //update tail
    if (ls->n==0)
    {
        ls->tail=NULL;
    }
    ls->n--;//element minus 1
}
void displayAllData(List *ls){
    Element *tmp;
    tmp=ls->head;
    while (tmp->next!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl<<endl;

}
void createToBegin(List *ls,int dataNew){
    Element *e;
    e=new Element;
    e->data=dataNew;
    e->next =ls->head;
    ls->head = e;
    if (ls->n==0)
    {
        ls->tail=e;//if null        
    }
    ls->n++; //next element
}


List *createList(List *ls){
    ls=new List;
    
    ls->n=0;
    ls->head=NULL;
    ls->tail=NULL;
    return ls;
}
