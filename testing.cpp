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
List *createList();
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
//delete end other method        
void otherDeleteEnd(List *ls); 
void deleteAll(List *ls);                          
int p=0; 
int f=1;  
int main(){
    int choice,number;
    List *ls;
    ls=createList();
    
    while (1)
    {
        cout<<"\t\t=========================\n";
        cout<<"\t\t+Welcome to link list-_-+\n";
        cout<<"\t\t=========================\n\n";
        cout<<"1.Input data begin of list.\n\n";
        cout<<"2.Display data in list.\n\n";
        cout<<"3.Delete data Begin of list.\n\n";
        cout<<"4.Input data end of list.\n\n";
        cout<<"5.Delete data end of list.\n\n";
        cout<<"6.Exit the program.\n\n";
        cout<<"7.Delete all data in list.\n";
        cout<<"Choice:";
        cin>>choice;
        if (choice==1)
        {
            system("clear||cls");
            cout<<"Input number:";
            cin>>number;
            createToBegin(ls,number);
        }else if (choice==2)
        {
            displayAllData(ls);            
        }else if (choice==3)
        {
            DeleteBegin(ls);
        }else if (choice==4)
        {
            system("clear||cls");

            cout<<"Input number:";
            cin>>number;
            endList(ls,number);
        }else if (choice==5)
        {
            // cout<<"1.method\n\n";
            otherDeleteEnd(ls);
            // cout<<"2.Other method\n\n";
            // deleteEnd(ls);
        }else if(choice==7){
          deleteAll(ls);
        }
        else if (choice==6)
        {
            cout<<"Bye Bye!\n\n";
            break;
        }
    }
}
void deleteEnd(List *ls){
   Element *tmp1,*tmp;
    if (ls->head ==NULL)
    {
        cout<<"You cant delete more.\n";
    }   
    else{
        if (ls->head->next==NULL)
        {
            cout<<"Successfull deleted.\n";

            delete ls->head;
            ls->head=NULL;
            p=1;
        }
    else
    {
        cout<<"Successfull deleted.\n";
        p=0;
        tmp=ls->head;
       while (tmp->next!=NULL)
       {
            tmp1=tmp;
            tmp=tmp->next;           
       }
        

       delete tmp1->next;
       tmp1->next=NULL; 
        

   }
    }
   
}
void endList(List *ls, int dataNew){
    Element *e;
    e= new Element();
    p=0;
    f=0;
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
        ls->tail=e;//ls->tail=ls->tail->next
        ls->n++;
    }
    
}

void DeleteBegin(List *ls){
    Element *tmp;
    //set next become head
    if (ls->head==NULL)
    {
        p=1;
        cout<<"You cant delete more.\n";
    }else
    {
        tmp=ls->head;
        ls->head = ls->head->next;
        //delete head
        delete tmp;
        f=1;

        //update tail
        if (ls->n==0)
        {
            ls->tail=NULL;
        }
        if (ls->head ==NULL)
        {
            p=1;
        }

        ls->n--;//element minus 1
    }
}
void displayAllData(List *ls){
    Element *tmp;
    tmp=ls->head;
    
    if (p==1)
    {
        cout<<"No result!\n";
    }
    else{
        while (tmp!=NULL)
        {
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        
        }
    }
    cout<<endl<<endl;

}
void createToBegin(List *ls,int dataNew){
    Element *e;
    e=new Element();
    p=0;
    f=0;
    e->data=dataNew;
    e->next =ls->head;
    ls->head = e;
    if (ls->n==0)
    {
        ls->tail=e;//if null        
    }
    ls->n=ls->n+1; //next element
}


List *createList(){
    List *ls;
    ls=new List();
    
    ls->n=0;
    ls->head=NULL;
    ls->tail=NULL;
    return ls;
}
void otherDeleteEnd(List *ls){
    Element *tmp;
    if (ls->tail==NULL||ls->head==NULL)
    {
        p=1;
        cout<<"Cant delete.\n";
    }else
    {
        if (ls->n==1)
        {
            DeleteBegin(ls);
        }else
        {
            tmp= ls->head;
            for (int i = 1; i <ls->n-1; i++)
            {
                tmp=tmp->next;          
            }
            ls->tail=tmp;
            tmp=tmp->next;
            ls->tail->next=NULL;
            cout<<"Successfull deleted.\n";
            if (ls->tail==NULL)
            {
                p=1;
            }
            ls->n--;
    }
    }
   
}                    
void deleteAll(List *ls){
  
  if(ls->n>0){
    
  while(ls->n>0){
    
    DeleteBegin(ls);
  }
  }else{
    cout<<"Cant delete";
  }
  if(f==1){
    cout<<"successful delete\n";
  }
}
