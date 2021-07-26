//
//  do.cpp
//  spojovy seznam
//
//  Created by Paul Ekishev on 06/11/2020.
//

#include "do.hpp"




static Prvek *zadejPrvekPresKonsol() {
    Prvek *newPrvek = new Prvek;
    while(true){
        cout << "Zadej Jemeno: ";
        cin >> newPrvek->data.givenName;
        if(stringNeboNe(newPrvek->data.givenName) == false)
        {
            cin.clear();
            cin.ignore(433443, '\n');
            cout << "Spatne! Zadej znovu" << endl;
        }
        else{
            break;
        }
    }
    while(true){
        cout << "Zadej Prijemeni: ";
        cin >> newPrvek->data.givenPrijmen;
        if(stringNeboNe(newPrvek->data.givenPrijmen) == false)
        {
            cin.clear();
            cin.ignore(433443, '\n');
            cout << "Spatne! Zadej znovu" << endl;
        }
        else{
            break;
        }
    }
    while(true){
        cout << "Zadej datu narozeni ve tvaru: \n(rok-mesic-den, priklad: 2000-4-12): ";
        cin >> newPrvek->data.birthday;
        if(cisloNeboNe(newPrvek->data.birthday) == false)
        {
            cin.clear();
            cin.ignore(433443, '\n');
            cout << "Spatne! Zadej znovu" << endl;
        }
        else{
            break;
        }
    }
    
    while(true){
        cout << "Zadej svoje ID: ";
        string s;
        cin >> s;
        if(cisloNeboNe(s) == false)
        {
            cin.clear();
            cin.ignore(4334473, '\n');
            cout << "Spatne! Zadej znovu" << endl;
        }
        else{
            
            newPrvek->data.id = stoi(s);
            break;
        }
    }
    while(true){
        cout << "Zadej ID mamy, pokud nemate zadejte -1: ";
        string s;
        cin >> s;
        if(cisloNeboNe(s) == false)
        {
            cin.clear();
            cin.ignore(433443, '\n');
            cout << "Spatne! Zadej znovu" << endl;
        }
        else{
            newPrvek->data.id_mother = stoi(s);
            break;
        }
    }
    while(true){
        cout << "Zadej ID taty,pokud nemate zadejte -1: ";
        string s;
        cin >> s;
        if(cisloNeboNe(s) == false)
        {
            cin.clear();
            cin.ignore(433443, '\n');
            cout << "Spatne! Zadej znovu" << endl;
        }
        else{
            newPrvek->data.id_father = stoi(s);
            break;
        }
    }
    while(true){
        cout << "Zadej svoje vahu: ";
        string s;
        cin >> s;
        if(cisloNeboNe(s) == false)
        {
            cin.clear();
            cin.ignore(433443, '\n');
            cout << "Spatne! Zadej znovu" << endl;
        }
        else{
            newPrvek->data.vaha = stod(s);
            break;
        }
    }
    while(true){
        cout << "Zadej svoje vysku: ";
        string s;
        cin >> s;
        if(cisloNeboNe(s) == false)
        {
            cin.clear();
            cin.ignore(433443, '\n');
            cout << "Spatne! Zadej znovu" << endl;
        }
        else{
            newPrvek->data.vyska = stod(s);
            break;
        }
    }
    return newPrvek;
}


void vytvorAVloz(Seznam &s, Clovek &new_data){
    
    Prvek *newPrvek = new Prvek;
    newPrvek->data = new_data;
    
    if(s.hlava == nullptr){
        s.hlava = newPrvek;
        s.ocas = newPrvek;
    }
    else{
        newPrvek->dalsi = s.hlava;
        s.hlava = newPrvek;
        newPrvek->dalsi->predchozi = newPrvek;
        
    }
}

void vytvorAVlozSPozice(int &pozice, Seznam &s, Clovek &new_data){
    int lenght = 0;
    Prvek *prvekPos = s.ocas;
    Prvek *newPrvek = new Prvek;
    newPrvek->data = new_data;
    while(lenght != pozice){
        prvekPos = prvekPos->predchozi;
        lenght++;
    }
    newPrvek->dalsi = prvekPos->dalsi;
    prvekPos->dalsi = newPrvek;
    newPrvek->predchozi = prvekPos;
    if(newPrvek->dalsi != nullptr){
        newPrvek->dalsi->predchozi = newPrvek;
    }
}


void vytvorAVlozNaZacatek(Seznam &s, Clovek &new_data){
    Prvek *newPrvek = new Prvek;
    newPrvek->data = new_data;
    if(s.hlava == nullptr){
        s.hlava = newPrvek;
        s.ocas = newPrvek;
    }
    else{
        newPrvek->predchozi = s.ocas;
        s.ocas = newPrvek;
        newPrvek->dalsi = newPrvek->predchozi->dalsi;
        newPrvek->predchozi->dalsi = newPrvek;
        if(newPrvek->dalsi != nullptr ){
            newPrvek->dalsi->predchozi = newPrvek;
        }
    }
    
}

void vypis(Clovek &c){
    cout << "Name: " << c.givenName << endl;
    cout << "Surname: " << c.givenPrijmen << endl;
    cout << "Birthday: " << c.birthday << endl;
    cout << "ID: " << c.id << endl;
    cout << "Weight: " << c.vaha << endl;
    cout << "Height: " << c.vyska << endl;
    cout << "Mother_id: ";
    if(c.id_mother == -1){
        cout << "Nedefinovane" << endl;
    }
    else{
        cout << c.id_mother << endl;
    }
    cout << "Father_id: ";
    if(c.id_father == -1){
        cout << "Nedefinovane" << endl;
    }
    else{
        cout << c.id_father << endl;
    }
    
}

void vypisObsahSeznamuDoKonzoli(Seznam &s){
    cout << "Seznam: \n";
    Prvek *newPrvek = s.ocas;
    while (newPrvek != s.hlava) {
        vypis(newPrvek->data);
        cout << "\n" << endl;
        newPrvek = newPrvek->predchozi;
    }
    vypis(newPrvek->data);
    cout << '\n';
    
}

static void parseBirthday(char delimetr, int &den, int &denPredchozi, std::string &kolikLet, int &mesic, int &mesicPredchozi, Prvek *&nejstarsi, Prvek *&newPrvek, long &posDelimetru, int &rok, int &rokPredchozi) {
    kolikLet = newPrvek->data.birthday;
    rok = stoi(kolikLet.substr(0,4));
    switch(srovnatDvaCisla(rok, rokPredchozi)){
        case 0:{
            posDelimetru = kolikLet.find(5,delimetr);
            if(posDelimetru == 6 ){
                mesic = stoi(kolikLet.substr(5,1));
            }
            else{
                mesic = stoi(kolikLet.substr(5,2));
            }
            switch(srovnatDvaCisla(mesic, mesicPredchozi)){
                case 0: {
                    posDelimetru = kolikLet.find(6,delimetr);
                    if(posDelimetru == 7){
                        den = stoi(kolikLet.substr(posDelimetru,kolikLet.length() - posDelimetru));
                    }
                    else{
                        den = stoi(kolikLet.substr(posDelimetru,kolikLet.length() - posDelimetru));
                    }
                    switch(srovnatDvaCisla(den, denPredchozi)){
                        case 1:{
                            nejstarsi->data = newPrvek->data;
                            denPredchozi = den;
                            break;
                        }
                        case 2:{
                            break;
                        }
                    }
                    mesicPredchozi = mesic;
                    break;
                }
                case 1:{
                    nejstarsi->data = newPrvek->data;
                    break;
                }
                case 2:{
                    break;
                }
            }
            break;
        }
        case 1:{
            nejstarsi->data = newPrvek->data;
            rokPredchozi = rok;
            break;
        }
        case 2:{
            break;
        }
    }
    newPrvek = newPrvek->dalsi;
    kolikLet = "";
}

void najdiAvypisiNejstarsiObobu(Seznam &s,int &vyber){
    Prvek *newPrvek = s.hlava;
    string kolikLet;
    Prvek *nejstarsi = new Prvek;
    int rok; // a
    int mesic;
    int mesicPredchozi = 12;  // proste nejake hromadne cislo pro mesic aby bylo s cin srovnat ( jako proste prvni pointer)
    long posDelimetru;
    int den;
    int denPredchozi = 31;  // proste nejake hromadne cislo pro den
    char delimetr = '-';
    int rokPredchozi = 20500; // b  // proste nejake hromadne cislo pro rok
    
    while(newPrvek->dalsi != NULL){
        parseBirthday(delimetr, den, denPredchozi, kolikLet, mesic, mesicPredchozi, nejstarsi, newPrvek, posDelimetru, rok, rokPredchozi);
    }

    parseBirthday(delimetr, den, denPredchozi, kolikLet, mesic, mesicPredchozi, nejstarsi, newPrvek, posDelimetru, rok, rokPredchozi);
    
    if(vyber == 1){
        vypis(nejstarsi->data);
    }
    else if(vyber == 2){
        string nazev;
        cout << "Zadej nazev souboru: ";
        cin >> nazev;
        ofstream soubor;
        soubor.open(nazev);
        if(soubor.is_open()){
        addDat(*nejstarsi, soubor);
        }
        soubor.close();
    }

    delete nejstarsi;
}

void najdiZadanyPocetNejvyssiOsob(Seznam &s,int &vyber,int &kolikOsob){
    
    
    Prvek *nejvyssi = new Prvek;
    
    Seznam *seznamNejvyssiOsob = new Seznam;
    
    Prvek *newPrvek;
    
    double vyskaOsoby = 0;
    
    double nejvyssiOsoba = 500; // proste nejake hromadne cislo aby hlidali < cisla
    
    for(int i = kolikOsob; i > 0; i--){
        newPrvek = s.hlava;
        
        double predNejvyssiOsoba = 0;
        
        while(newPrvek->dalsi != NULL){
            
            vyskaOsoby = newPrvek->data.vyska;
            if(vyskaOsoby > predNejvyssiOsoba){
                if(vyskaOsoby < nejvyssiOsoba){
                nejvyssi->data = newPrvek->data;
                predNejvyssiOsoba = vyskaOsoby;
                }
            }
            newPrvek = newPrvek->dalsi;
        }
        vyskaOsoby = newPrvek->data.vyska;
        if(vyskaOsoby > predNejvyssiOsoba){
            if(vyskaOsoby < nejvyssiOsoba){
            nejvyssi->data = newPrvek->data;
            predNejvyssiOsoba = vyskaOsoby;
            }
        }
        
        vytvorAVloz(*seznamNejvyssiOsob, nejvyssi->data);
        nejvyssiOsoba = nejvyssi->data.vyska;
        
    }
    
    if(vyber == 1){
        vypisObsahSeznamuDoKonzoli(*seznamNejvyssiOsob);
    }
    else if(vyber == 2){
        string nazev;
        vypisDoSouboru(nazev, *seznamNejvyssiOsob);
}
    delete nejvyssi;
    zrus(*seznamNejvyssiOsob);
    delete seznamNejvyssiOsob;
}


int srovnatVysku(double a, double b){
    
    if(a == b){
        return 0;
    }
    
    return a > b ? 1 : 2; // 1 - vyssi je prvni osoba, 2 - vyssi je druha osoba
}




int srovnatDvaCisla(long a, long b){
    
    if(a == b){
        return 0;
    }
    
    return a < b ? 1 : 2; // 1 - starsi je prvni osoba, 2 - starsi je druha osoba
}


int delkaSeznamu(Seznam &s){
    int lenght = 1;
    Prvek *newPrvek = s.hlava;
    while(newPrvek->dalsi != NULL){
        newPrvek = newPrvek->dalsi;
        lenght++;
    }
    return lenght;
}

void smazVsechny(Seznam &s){
    Prvek *newPrvek = s.hlava;
    while (newPrvek->dalsi != nullptr ){
        s.hlava = s.hlava->dalsi;
        delete newPrvek;
        newPrvek = s.hlava;
    }
    delete newPrvek;
    s.hlava = nullptr;
    s.ocas = nullptr;
}

void zrus(Seznam &s){
    smazVsechny(s);
    delete s.hlava;
    s.hlava = nullptr;
    s.ocas = nullptr;
}

void pridejPrvekNaKonecSeznamu(Seznam *&s, int &odkudZadat){
    if (odkudZadat == 1){
        Prvek * newPrvek = zadejPrvekPresKonsol();
        vytvorAVloz(*s, newPrvek->data);
        delete newPrvek;
        
    }
    if(odkudZadat == 2){
        string nazev;
        cout << "Pozor!!! Personalni daty do souboru musi byt vlozeny v takovem poradi: " << endl;
        cout << "birthday;mother_id;givenName;height;id;father_id;weight;givenPrijmeni" << endl;
        int vyber = 1; // na konec vloz
        nactiDataZeSouboru(nazev, s,vyber);
    }
}



void pridejPrvekNaZacatekSeznamu(Seznam *&s, int &odkudZadat){
    if (odkudZadat == 1){
        Prvek * newPrvek = zadejPrvekPresKonsol();
        vytvorAVlozNaZacatek(*s, newPrvek->data);
        delete newPrvek;
        
    }
    if(odkudZadat == 2){
        string nazev;
        cout << "Pozor!!! Personalni daty do souboru musi byt vlozeny v takovem poradi: " << endl;
        cout << "birthday;mother_id;Name;height;id;father_id;weight;Prijmeni" << endl;
        int vyber = 2; // na zacatek
        nactiDataZeSouboru(nazev, s,vyber);
    }
}


void pridejPrvekSPoziceVSeznamu(Seznam *&s, int &odkudZadat){
    if (odkudZadat == 1){
        Prvek * newPrvek = zadejPrvekPresKonsol();
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
        vytvorAVlozSPozice(pozice, *s, newPrvek->data);
        delete newPrvek;
    }
    if(odkudZadat == 2){
        string nazev;
        cout << "Pozor!!! Personalni daty do souboru musi byt vlozeny v takovem poradi: " << endl;
        cout << "birthday;mother_id;Name;height;id;father_id;weight;Prijmeni" << endl;
        int vyber = 3; // s pozice
        nactiDataZeSouboru(nazev, s,vyber);
    }
    
}
