/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: oscar
 *
 * Created on 22 / de març / 2021, 19:27
 */

#include <cstdlib>
#include "LinquedDeque.h"
#include <iostream>
#include <stdexcept>


using namespace std;

void mostrarMenu(){
    cout << "1. Inserir al davant de la cua\n2. Inserir element al darrera de la cua\n" <<
            "3. Treure element pel davant de la cua\n4. Treure element pel darrera de la cua\n" <<
            "5. Consultar el primer element\n6. Consultar el darrer element\n" << 
            "7. Imprimir tot el contingut de l'ArrayDeque\n8. Sortir\n";
    return;
}

int seleccionarOpcio(){
    double opcio;
    
    do{ 
        cout << "Seleccioni una de les opcions del menú:\n";
        cin >> opcio;
    } while( opcio > 8 || opcio <1);
    
    return opcio;
}


/*
 * 
 */
int main(int argc, char** argv) {
    int mida, element, opcio;
    
    
    LinquedDeque lindeque;
    
    do{
        mostrarMenu();
        opcio = seleccionarOpcio();
        
    
        switch(opcio){
            case 1:
                cout << "Quin element vols inserir?\n";
                cin >> element;
                lindeque.enqueueFront(element);
                cout << "Element " << element << " agregat\n";
                break;
           case 2:
                cout << "Quin element vols inserir?\n";
                cin >> element;
                lindeque.enqueueBack(element);
                cout << "Element " << element << " agregat\n";
                break;
           case 3:
                try{
                    lindeque.dequeueFront();
                    cout << "Element del davant eliminat\n";
                }
                catch( const out_of_range& oor ){
                    cout << oor.what() << endl;
                }
                break;
            case 4:
                try{
                    lindeque.dequeueBack();
                    cout << "Element del darrere eliminat\n";
                }
                catch( const out_of_range& oor ){
                    cout << oor.what() << endl;
                }
                break;
            case 5: 
                try{
                    element = lindeque.getFront();
                    cout << element << "\n";
                }
                catch( const out_of_range& oor ){
                    cout << oor.what() << endl;
                }
                break;
            case 6:
                try{
                    element = lindeque.getBack();
                    cout << element << "\n";
                }
                catch( const out_of_range& oor ){
                    cout << oor.what() << endl;
                }
                break;
            case 7:
                lindeque.print();
                break;
        }
    } while (opcio != 8);
    
    return 0;
}

