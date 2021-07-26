//
//  nactiDatu.cpp
//  spojovy seznam
//
//  Created by Paul Ekishev on 14/11/2020.
//

#include "do.hpp"

void nactiDataZeSouboru(string &souborDat,Seznam *&s, int &vyber){
    ifstream soubor;
    while(!soubor.is_open()){
        cout << "Zadej nazev souboru, v kterem mate datu: ";
        cin >> souborDat;
        cout << endl;
        soubor.open("/Users/Imcheldon/Documents/spojovy seznam c++/trida/LinkedList/LinkedList/LinkedList/ zadani.txt");
        if(soubor.is_open()){
            soubor.close();
            break;
        }
        else{
            cout << "Chyba nesmohl otevrit,zadej znovu\n";
            soubor.clear();
            soubor.ignore(433443, '\n');
        }
    }
    soubor.open(souborDat);
    Clovek *person = new Clovek;
    if(soubor.is_open()){
        while(!soubor.eof()){
            string radek;
            getline(soubor,radek);
            if(radek[0] == '#'){
                continue;
            }
            int id;
            string givenName;
            string givenPrijmen;
            string birthday;
            int vyska;
            double vaha;
            int id_mother;
            int id_father;
            
            int pos = 0;
            char delimetr = ';';
            int previos = 0;
            
            for(int i = 0; i<8; i++){
                
                pos = radek.find(delimetr,pos+1);
                switch(i){
                    case 0 : {
                        birthday = radek.substr(previos,pos);
                        person->birthday = birthday;
                        previos = pos;
                        break;
                    }
                    case 1 : {
                        string id_mom = radek.substr(previos+1,pos-previos-1);
                        if(id_mom == "-1" || id_mom == ""){
                            id_mother = -1;
                        }
                        else{
                            if(id_mom != ""){
                            id_mother = stoi(id_mom);
                            }
                        }
                        person->id_mother = id_mother;
                        previos = pos;
                        break;
                    }
                    case 2 : {
                        givenName = radek.substr(previos+1,pos-previos-1);
                        person->givenName = givenName;
                        previos = pos;
                        break;
                    }
                    case 3 : {
                        string height = radek.substr(previos+1,pos-previos-1);
                        vyska = stoi(height);
                        person->vyska = vyska;
                        previos = pos;
                        break;
                    }
                    case 4 : {
                        string moje_id = radek.substr(previos+1,pos-previos-1);
                        id = stoi(moje_id);
                        person->id = id;
                        previos = pos;
                        
                        break;
                    }
                    case 5 : {
                        string id_pop = radek.substr(previos+1,pos-previos-1);
                        if(id_pop == "-1" || id_pop == ""){
                            id_father = -1;
                        }
                        else{
                            if(id_pop != ""){
                            id_father = stoi(id_pop);
                            }
                        }
                        person->id_father = id_father;
                        previos = pos;
                        
                        break;
                    }
                    case 6 : {
                        string moje_vaha = radek.substr(previos+1,pos-previos-1);
                        vaha = stod(moje_vaha);
                        person->vaha = vaha;
                        previos = pos;
                        break;
                    }
                    case 7 : {
                        givenPrijmen = radek.substr(previos+1,radek.length() - pos - 2);
                        person->givenPrijmen = givenPrijmen;
                        break;
                    }
                }
            }
            
            if(vyber == 1){
                vytvorAVloz(*s, *person);
            }
            else if(vyber == 2){
                vytvorAVlozNaZacatek(*s, *person);
            }
            else if(vyber == 3){
                int pozice;
                while(true){
                    cout << "Zadej cislo pizice v seznamu odkud chces vlozit prvek: ";
                    cin >> pozice;
                    if(!cin){
                        cinIgnore();
                    }
                    else{
                        break;
                    }
                }
                vytvorAVlozSPozice(pozice, *s, *person);
            }
    }
    delete person;
    soubor.close();
}
}
void addDat(Prvek &newPrvek, std::ofstream &soubor) {
    soubor << "Name: " << newPrvek.data.givenName << endl;
    soubor << "Surname: " << newPrvek.data.givenPrijmen << endl;
    soubor << "Birthday: " << newPrvek.data.birthday << endl;
    soubor << "ID: " << newPrvek.data.id << endl;
    soubor << "Weight: " << newPrvek.data.vaha << endl;
    soubor << "Height: " << newPrvek.data.vyska << endl;
    soubor << "Mother_id: ";
    if(newPrvek.data.id_mother == -1){
        soubor << "Nedefinovane" << endl;
    }
    else{
        soubor << newPrvek.data.id_mother << endl;
    }
    soubor << "Father_id: ";
    if(newPrvek.data.id_father == -1){
        soubor << "Nedefinovane" << endl;
    }
    else{
        soubor << newPrvek.data.id_father << endl;
    }
    soubor << endl;
}

void vypisDoSouboru(string &nazev, Seznam &s){
    ofstream soubor;
    while(!soubor.is_open()){
        cout << "Zadej nazev souboru: ";
        cin >> nazev;
        cout << endl;
        soubor.open(nazev);
        if(soubor.is_open()){
            soubor.close();
            break;
        }
        else{
            cout << "Chyba nesmohl otevrit,zadej jiny znovu\n";
            soubor.clear();
        }
    }
    soubor.open(nazev);
    if(soubor.is_open()){
        soubor << "Seznam: " << endl;
        soubor << '\n';
        Prvek *newPrvek = s.ocas;
        do{
            addDat(*newPrvek,soubor);
            newPrvek = newPrvek->predchozi;
            
        } while (newPrvek != s.hlava);
        addDat(*newPrvek, soubor);
        
    }
    soubor.close();
    
}



int stringNeboNe(string &s){
    bool pravda = true;
    for(int i =0; i< s.length(); i++){
        if(s[i] >= 65 && s[i] <= 122){
            pravda = true;
        }
        else{
            pravda = false;
            break;
        }
    }
    return pravda;
}

int cisloNeboNe(string &s){
    bool pravda = true;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 45 && s[i] <= 57){
            pravda = true;
        }
        else{
            pravda = false;
            break;
        }
    }
    return pravda;
}

