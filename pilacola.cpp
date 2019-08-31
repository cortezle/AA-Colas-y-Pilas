// Example program
// Example program
#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *sig;
    Nodo *prev;
}*inicio,*fin;

class Cola
{
    public:
        Nodo* crearNodo(int dato)
        {
            Nodo *n= new Nodo;
            n->dato= dato;
            n->sig = nullptr;
            return n;
        }
        
        void push(int dato)
        {
            Nodo *n=crearNodo(dato);
            if(!inicio)
            {
                inicio=n;
                fin=n;
            }
            else
            {
                fin->sig=n;
                fin=n;
            }
        }
        
        void pop()
        {
            Nodo *temp=inicio;
            inicio=inicio->sig;
            free(temp);
        }
        
        void mostrarCola()
        {
            Nodo *temp = inicio;
            if(!inicio)
            {
                cout<<"Pila vacia"<<endl;
            }
            else
            {
                while(temp)
                {
                cout<<temp->dato<<" ";
                temp = temp->sig;
                }
            }
        }

	int devolverDato(Nodo *temp)
	{
	    return temp->dato;
	}

	

        
        Cola()
        {
            inicio=nullptr;
        }
};

class Pila: Cola
{
    public:
        Nodo* crearNodo(int dato)
        {
            Nodo *m= new Nodo;
            m->dato= dato;
            m->sig = nullptr;
            return m;
        }
        
        void push(int dato)
        {
            Nodo *m=crearNodo(dato);
            m->sig=inicio;
            inicio=m;
        }
    

    
	void push2(Nodo *tempo)
	{
	    Cola c;
		while(tempo)
		{
			push(c.devolverDato(tempo));
			tempo=tempo->sig;
			
		}
	}
        
        void pop()
        {
            Nodo *tempo=inicio;
            inicio=inicio->sig;
            free(tempo);
        }
        
        void mostrarPila()
        {
            Nodo *tempo = inicio;
            if(!inicio)
            {
                cout<<"Pila vacia"<<endl;
            }
            else
            {
                while(tempo)
                {
                cout<<tempo->dato<<" ";
                tempo = tempo->sig;
                }
            }
        }
        
        Pila()
        {
            inicio=nullptr;
        }

	
};

int main()
{
    Cola c;
    Pila p;
    c.push(1);
    c.push(2);
    c.push(3);
    c.mostrarCola();
    Nodo *temps=fin;
    p.push2(temps);
    
   /* p.push(1);
    p.push(2);
    p.push(3);*/
    cout<<endl;
    p.mostrarPila();
    
}
