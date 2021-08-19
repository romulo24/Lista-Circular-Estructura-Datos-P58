
#include <iostream>
using namespace std;

struct nodo{
    int dato;
    struct nodo *enlace;
};

nodo *ultimo;
nodo *cabeza;

void menu();
void insertar();
void mostrar(int);

int main(void)
{
    cabeza = NULL;
    int op;

    do
    {
        menu();
        cin>>op;

        switch(op)
        {
        case 1:
            insertar();
            break;
        case 2:
            {
            int veces = 0;
            cout << "\n\nLista Circular \n\n";
            cout << "Ingrese las veces que desea imprimir: ";
            cin >> veces;
            mostrar(veces);
            }
            break;
        case 3:
            cout << "Gracias por usar nuestro programa" << endl;
            break;
        default: cout << "Ingrese una opcion valida...";
            break;
        }

        cout<<endl<<endl;

    }while(op!=3);

    return 0;
}

void menu()
{
    cout << "\n\t\tLISTA ENLAZADA CIRCULAR\n\n";
    cout << "1.INSERTAR NODO" << endl;
    cout << "2.IMPRIMIR LISTA CIRCULAR" << endl;
    cout << "3.SALIR" << endl;
    cout << "INGRESE OPCION: ";
}

void insertar()
{
    nodo *nuevo;
    nuevo = new struct nodo;

    cout << "\nIngrese el dato: ";
    cin >> nuevo->dato;
    cout << "El " << nuevo->dato << " ha sido insertado correctamente";
    nuevo->enlace = NULL;

    if(cabeza==NULL)
    {
        cabeza = nuevo;
        cabeza->enlace = cabeza;
        ultimo = nuevo;
    }
    else
    {
        nuevo->enlace = cabeza;
        cabeza = nuevo;
        ultimo->enlace = cabeza;
    }

}

void mostrar(int veces)
{   nodo *aux;
    aux = cabeza;
    int i=0;

    if(cabeza!=NULL)
    {
        do
        {
            cout << "  " << aux->dato;
            aux = aux->enlace;
            i++;
        }while(i<veces);
    }
    else
        cout<<"\n\n\tLista vacia...!"<<endl;
}
