#include <iostream>
using namespace std;
class node{
  node *next;
  node *anterior;
  int data;
  friend class lista;
};

class lista{
  node *head;
  public:
    lista()
    {
      head=NULL;
    }
    void insertar(int dato);
    void imprimir();
    void eliminarRepe();
    void ordenarAscendente();
};

void lista::insertar(int dato){
  node *nuevo=new node();
  nuevo->data=dato;

  node *aux1=head;
  node *aux2;
  while(aux1!=NULL)
  {
      aux2=aux1;
      aux1=aux1->next;
  }
  if(head==aux1)
  {
      head=nuevo;
      
  }
  else
  {
      aux2->next=nuevo;
  }
  nuevo->next=aux1;
}


void lista::imprimir()
{
    node *rec=head;
    while(rec!=NULL)
    {
        cout<<rec->data<<"->";
        rec=rec->next;
    }
    cout<<"NULL";
}


void lista::eliminarRepe()
{
  node *aux=head;
  while(aux!=NULL)
  {
    node *auxnext=aux->next;
    node *aux2=aux;
    while(auxnext!=NULL)
    {
      if(aux->data==auxnext->data){
        node *dele=auxnext;
        auxnext=aux2;
        aux2->next=dele->next;
        delete dele;
      }
      aux2=auxnext;
      auxnext=auxnext->next;
    }
    aux=aux->next;
  }
}
int main()
{
  lista l;
  l.insertar(9);
  l.insertar(8);
  l.insertar(7);
   l.insertar(1);
  l.insertar(2);
  l.insertar(3);
   l.insertar(15);
  l.insertar(20);


  
  cout<<" antes " << endl;
  l.imprimir();
  cout<<endl;
  cout<< " ahora " <<endl;
  l.eliminarRepe();
  l.imprimir();

}