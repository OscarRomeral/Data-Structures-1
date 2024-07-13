/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Patient.cpp
 * Author: oscar
 * 
 * Created on 29 / de març / 2021, 17:00
 */


#include "Patient.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
using namespace std;

Patient::Patient() {
    this->nom = "";
    this->cognom = "";
    this->iden = "";
    this->estat = "";
}

Patient::Patient(string nom, string cognom, string iden, string estat){
    this->nom = nom;
    this->cognom = cognom;
    this->iden = iden;
    if(estat == "NOT_OK" || estat == "OK"){
        this->estat = estat;
    }
    else throw invalid_argument("Estat no vàlid ");
}

const string Patient::getNom(){
    return this->nom;
}

const string Patient::getCognom(){
    return this->cognom;
}

const string Patient::getIdentificador(){
    return this->iden;
}

const string Patient::getEstat(){
    return this->estat;
}

void Patient::setNom(string nom){
    this->nom = nom;
}

void Patient::setCognom(string cognom){
    this->cognom = cognom;
}

void Patient::setEstat(string estat){
    if(estat=="NOT_OK" || estat=="OK"){
        this->estat = estat;
    }
    else{ throw invalid_argument(" Estat no vàlid");}
}


void Patient::setIdentificador(string iden){
    this->iden = iden;
}

void Patient::print() const{
    cout << this->iden << "," << this->nom << "," << this->cognom << "," << this->estat;
    return;
}


Patient::~Patient() {
}

