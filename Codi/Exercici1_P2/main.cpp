/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: oscar
 *
 * Created on 24 / de març / 2021, 12:18
 */

#include <cstdlib>
#include "ArrayDeque.h"
#include <iostream>
#include <stdexcept>

#include "ArrayDeque.h"

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

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int mida, element, opcio;
    
    
    cout << "Quina mida del vector vols?\n";
    cin >> mida;
    ArrayDeque deque = ArrayDeque(mida);
    cout << "Estructura creada\n";
    
    do{
        mostrarMenu();
        opcio = seleccionarOpcio();
    
        switch(opcio){
            case 1:
                cout << "Quin element vols inserir?\n";
                cin >> element;
                try{
                    deque.enqueueFront(element);
                    cout << "Element " << element << " agregat\n";
                }
                catch( const invalid_argument& ex ){
                    cout << ex.what() << endl;
                }
                break;
           case 2:
                cout << "Quin element vols inserir?\n";
                cin >> element;
                try{
                    deque.enqueueBack(element);
                    cout << "Element " << element << " agregat\n";
                }
                catch( const invalid_argument& ex ){
                    cout << ex.what() << endl;
                }
                break;
           case 3:
                try{
                    deque.dequeueFront();
                    cout << "Element del davant eliminat\n";
                }
                catch( const invalid_argument& ex ){
                    cout << ex.what() << endl;
                }
                break;
            case 4:
                try{
                    deque.dequeueBack();
                    cout << "Element del darrere eliminat\n";
                }
                catch( const invalid_argument& ex ){
                    cout << ex.what() << endl;
                }
                break;
            case 5: 
                try{
                    element = deque.getFront();
                    cout << element << "\n";
                }
                catch( const invalid_argument& ex ){
                    cout << ex.what() << endl;
                }
                break;
            case 6:
                try{
                    element = deque.getBack();
                    cout << element << "\n";
                }
                catch( const invalid_argument& ex ){
                    cout << ex.what() << endl;
                }
                break;
            case 7:
                deque.print();
                break;
        }
    } while (opcio != 8);
    
    return 0;
    
}

