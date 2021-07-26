//
//  do.hpp
//  spojovy seznam
//
//  Created by Paul Ekishev on 06/11/2020.
//

#ifndef do_hpp
#define do_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <istream>
#include <sstream>
#include <memory>


using namespace std;


struct Clovek {
    
    int id;
    string givenName;
    string givenPrijmen;
    string birthday;
    unsigned int vyska;
    double vaha;
    int id_mother;
    int id_father;
    
    Clovek& operator = (const Clovek& b){
        this->id = b.id;
        this->givenName = b.givenName;
        this->givenPrijmen = b.givenPrijmen;
        this->birthday = b.birthday;
        this->vyska = b.vyska;
        this->vaha = b.vaha;
        this->id_mother = b.id_mother;
        this->id_father = b.id_father;
        return *this;
    }
};

struct Prvek {
    
    Clovek data;
    Prvek *dalsi = nullptr;
    Prvek *predchozi  = nullptr;
};


struct Seznam{
    Prvek *hlava = nullptr;
    Prvek *ocas = nullptr;
};

void PrintMemoryUsage();
void vytvorAVloz(Seznam &s, Clovek &new_data);
void smazVsechny(Seznam &s);
void zrus(Seznam &s);
void vypis(Clovek &clovek);
void nactiDataZeSouboru(string &souborDat,Seznam *&s,int &vyber);
void vypisObsahSeznamuDoKonzoli(Seznam &s);

void praceSUzivately(Seznam *&s);

int delkaSeznamu(Seznam &s);

void vypisDoSouboru(string &nazev, Seznam &s);

void vypisDoSouboruDat(string &nazev, Seznam &s);
void smazVsechny(Seznam &s);

void najdiAvypisiNejstarsiObobu(Seznam &s,int &vyber);

void addDat(Prvek &newPrvek, std::ofstream &soubor);

void pridejPrvekNaKonecSeznamu(Seznam *&s, int &odkudZadat);

void pridejPrvekNaZacatekSeznamu(Seznam *&s, int &odkudZadat);

void pridejPrvekSPoziceVSeznamu(Seznam *&s, int &odkudZadat);

void vytvorAVlozNaZacatek(Seznam &s, Clovek &new_data);

void vytvorAVlozSPozice(int &pozice, Seznam &s, Clovek &new_data);

int srovnatDvaCisla(long a, long b);

void test();

int stringNeboNe(string &s);

void cinIgnore();

void najdiZadanyPocetNejvyssiOsob(Seznam &s,int &vyber,int &kolikOsob);


int srovnatVysku(double a, double b);



int cisloNeboNe(string &s);
#endif /* do_hpp */
