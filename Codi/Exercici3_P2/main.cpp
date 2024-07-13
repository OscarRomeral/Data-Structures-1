/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: oscar
 *
 * Created on 29 / de març / 2021, 16:43
 */

#include <cstdlib>
#include "LinquedDeque.h"
#include "Patient.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>


using namespace std;

void mostrarMenu(){
    cout << "1. Llegir un fitxer amb les entrades de pacients\n2. Imprimir la cua de pacients\n" <<
            "3. Eliminar el primer pacient de la cua\n4. Eliminar el darrer pacient de la cua\n" <<
            "5. Inserir n entrades de pacients des del teclat (0 per finalitzar)\n6. Consultar el primer pacient de la cua\n" << 
            "7. Consultar el darrer pacient de la cua\n8. Sortir\n";
    return;
}

int seleccionarOpcio(){
    int opcio;
    
    do{ 
        cout << "Seleccioni una de les opcions del menú:\n";
        cin >> opcio;
    } while( opcio > 8 || opcio <1);
    
    return opcio;
}



void afegirPacient(LinquedDeque *lindeque, string linia){
    string info[4], a;
    int comp = 0;
    
    for(int i=0; linia[i]!='\0'; i++){
        if(linia[i] == ','){
            info[comp] = a;
            comp++;
            a = "";
        }
        else {
            a += linia[i];
        }
    }
    info[comp] = a;
    if(info[3] != "OK" && info[3] != "NOT_OK"){
        throw invalid_argument("Entrada incorrecta");
    }
    Patient p (info[1], info[2], info[0], info[3]);
    if(info[3]=="OK"){
        lindeque->enqueueBack(p);
        cout << "Pacient afegit\n";
    }
    else{
        lindeque->enqueueFront(p);
        cout << "Pacient afegit\n";
    }
    return;
    
}


/*
 * 
 */
int main(int argc, char** argv) {
    int mida, opcio, n;
    string linia, fitxer = "Pacients.txt";
    Patient pacient;
    fstream fin;
    
    
    LinquedDeque lindeque;
    
    do{
        mostrarMenu();
        opcio = seleccionarOpcio();
        
    
        switch(opcio){
            case 1:
                fin.open(fitxer, ios::in);
                if (!fin) {
                    cout << "Fitxer innexistent" << endl;
                }
                else {
                    while (!fin.eof()) {
			getline(fin, linia); 
                        try{
                            afegirPacient(&lindeque, linia);
                        }catch (const invalid_argument& ia){
                            cout << ia.what() << endl;
                        }
                    }
                }
                fin.close();
                break;
           case 2:
                lindeque.print();
                break;
           case 3:
                try{
                    lindeque.dequeueFront();
                    cout << "Primer pacient de la cua eliminat\n";
                }
                catch( const out_of_range& oor ){
                    cout << oor.what() << endl;
                }
                break;
            case 4:
                try{
                    lindeque.dequeueBack();
                    cout << "Darrer pacient de la cua eliminat\n";
                }
                catch( const out_of_range& oor ){
                    cout << oor.what() << endl;
                }
                break;
            case 5:
                cout << "Introdueix nombre de pacients a afegir:\n";
                cin >> n;
                cout << "Escriu les dades dels pacients:\n";
                for(int i = 0; i < n; i++){
                    cin >> linia;
                    try{
                        afegirPacient(&lindeque, linia);
                    }catch (const invalid_argument& inv){
                        cout << inv.what() << endl;
                    }
                }
                break;
            case 6: 
                try{
                    pacient = lindeque.getFront();
                    pacient.print();
                }
                catch( const out_of_range& oor ){
                    cout << oor.what() << endl;
                }
                break;
            case 7:
                try{
                    pacient = lindeque.getBack();
                    pacient.print();
                }
                catch( const out_of_range& oor ){
                    cout << oor.what() << endl;
                }
                break;
            
        }
    } while (opcio != 8);
    
    return 0;
}



