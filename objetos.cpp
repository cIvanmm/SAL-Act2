#include "mainwindow.h"
#include <QApplication>
#include<iostream>
#include<vector>

using namespace std;

class Neurona{
private:
    int id;
    float voltaje;
    int posicion_x;
    int posicion_y;
    int red;
    int green;
    int blue;
public:
    Neurona(int id, float voltaje, int posicion_x, int posicion_y, int red, int green, int blue)
    : id(id), voltaje(voltaje), posicion_x(posicion_x), posicion_y(posicion_y), red(red), green(green), blue(blue){}
    void print()const{
        cout <<"\nNeurona: " <<id <<"\nVoltaje: " <<voltaje << "\nPosicion (x, y): (" <<posicion_x
             <<", " <<posicion_y <<")\nColor (R, G, B): (" <<red <<", " <<green <<", " <<blue << ")\n";
    }
};

class ListaNeuronas{
private:
    vector<Neurona> neuronas;
public:
    void primero();
    void agregar_inicio(Neurona);
    void ultimo();
    void agregar_final(Neurona);
    void mostrar();
};

void ListaNeuronas::primero(){
    int id, posicion_x, posicion_y, red, green, blue;
    float voltaje;
    cout <<"\nId:\t";
    cin >>id;
    cout <<"\nVoltaje:\t";
    cin >>voltaje;
    cout <<"\nPosicion x:\t";
    cin >>posicion_x;
    cout <<"\nPosicion y:\t";
    cin >>posicion_y;
    cout <<"\nR:\t";
    cin >>red;
    cout <<"\nG:\t";
    cin >>green;
    cout <<"\nB:\t";
    cin >>blue;
    Neurona neurona(id, voltaje, posicion_x, posicion_y, red, green, blue);
    agregar_inicio(neurona);
}

void ListaNeuronas::agregar_inicio(Neurona neurona){
    neuronas.insert(neuronas.begin(), neurona);
}

void ListaNeuronas::ultimo(){
    int id, posicion_x, posicion_y, red, green, blue;
    float voltaje;
    cout <<"\nId:\t";
    cin >>id;
    cout <<"\nVoltaje:\t";
    cin >>voltaje;
    cout <<"\nPosicion x:\t";
    cin >>posicion_x;
    cout <<"\nPosicion y:\t";
    cin >>posicion_y;
    cout <<"\nR:\t";
    cin >>red;
    cout <<"\nG:\t";
    cin >>green;
    cout <<"\nB:\t";
    cin >>blue;
    Neurona neurona(id, voltaje, posicion_x, posicion_y, red, green, blue);
    agregar_final(neurona);
}

void ListaNeuronas::agregar_final(Neurona neurona){
    neuronas.push_back(neurona);
}

void ListaNeuronas::mostrar(){
    if(neuronas.size() ==0)
        cout <<"\nNo hay ninguna neurona registrada...\n\n";
    else
        for(size_t i=0; i<neuronas.size(); i++){
            neuronas[i].print();
            cout <<endl;
        }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    int op =0;
    ListaNeuronas lista;
    do{
        cout <<"\n1. Agregar inicio.\t2. Agregar final."
        <<"\n3. Mostrar.\t\t4. Salir.\n";
        cin >>op;
        cin.clear();
        cin.ignore();
        switch(op){
        case 1:
            lista.primero();
            break;
        case 2:
            lista.ultimo();
            break;
        case 3:
            lista.mostrar();
            break;
        case 4:
            cout <<"\nSaliendo...\n\n";
            break;
        default:
            cout <<"\nOpcion no valida...\n\n";
        }
    }while(op !=4);
}
