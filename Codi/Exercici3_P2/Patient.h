/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Patient.h
 * Author: oscar
 *
 * Created on 29 / de març / 2021, 17:00
 */

#ifndef PATIENT_H
#define PATIENT_H
#include <string>

using namespace std;

class Patient {
private:
    string iden;
    string nom;
    string cognom;
    string estat;
public:
    Patient();
    Patient(string nom, string cognom, string iden, string estat);
    const string getEstat();
    const string getNom();
    const string getCognom();
    const string getIdentificador();
    void setEstat(string estat);
    void setNom(string nom);
    void setCognom(string cognom);
    void setIdentificador(string iden);
    void print() const;
    virtual ~Patient();

    

};

#endif /* PATIENT_H */

