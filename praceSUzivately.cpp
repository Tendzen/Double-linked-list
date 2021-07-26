//
//  praceSUzivately.cpp
//  spojovy seznam
//
//  Created by Paul Ekishev on 14/11/2020.
//

#include "do.hpp"

void cinIgnore() {
    cin.clear();
    cin.ignore(433443, '\n');
    cout << "Spatne! Zadej znovu" << endl;
}

void praceSUzivately(Seznam *&s){
    string souborDat;
    int vyber = 1;
    nactiDataZeSouboru(souborDat,s,vyber);
    char ano;
    char chceteProdolzit = 'a';
    while(chceteProdolzit == 'a' || chceteProdolzit == 'A'){
        while(true)
        {
            cout << "Chcete pridat prvek v konec seznamu? (a/n): ";
            cin >> ano;
            
            if(ano == 'a' || ano == 'A' || ano == 'n' || ano == 'N' ){
                break;
            }
            else
            {
                cinIgnore();
                
            }
        }
        if(ano == 'a' || ano == 'A'){
            int odkudZadat; // 1 - kosnol 2 - soubor
            while(true){
                cout << "Chcete zadat prvek pres konsol? (a/n): ";
                cin >> ano;
                if(ano == 'a' || ano == 'A'){
                    odkudZadat = 1;
                    pridejPrvekNaKonecSeznamu(s,odkudZadat);
                    break;
                }
                else if(ano == 'n' || ano == 'N'){
                    break;
                }
                else{
                    cinIgnore();
                }
            }
            while(true){
                cout << "Chcete zadat prvek pres soubor? (a/n): ";
                cin >> ano;
                if(ano == 'a' || ano == 'A'){
                    odkudZadat = 2;
                    pridejPrvekNaKonecSeznamu(s,odkudZadat);
                    break;
                }
                else if(ano == 'n' || ano == 'N'){
                    break;
                }
                else{
                    cinIgnore();
                    
                }
            }
            
        }
        while(true)
        {
            cout << "Chcete pridat prvek na zacatek seznamu? (a/n): ";
            cin >> ano;
            
            if(ano == 'a' || ano == 'A' || ano == 'n' || ano == 'N' ){
                break;
            }
            else
            {
                cinIgnore();
                
            }
        }
        if(ano == 'a' || ano == 'A'){
            int odkudZadat; // 1 - kosnol 2 - soubor
            while(true){
                cout << "Chcete zadat prvek pres konsol? (a/n): ";
                cin >> ano;
                if(ano == 'a' || ano == 'A'){
                    odkudZadat = 1;
                    pridejPrvekNaZacatekSeznamu(s,odkudZadat);
                    break;
                }
                else if(ano == 'n' || ano == 'N'){
                    break;
                }
                else{
                    cinIgnore();
                }
            }
            while(true){
                cout << "Chcete zadat prvek pres soubor? (a/n): ";
                cin >> ano;
                if(ano == 'a' || ano == 'A'){
                    odkudZadat = 2;
                    pridejPrvekNaZacatekSeznamu(s,odkudZadat);
                    break;
                }
                else if(ano == 'n' || ano == 'N'){
                    break;
                }
                else{
                    cinIgnore();
                }
            }
        }
    
        while(true)
        {
            cout << "Chcete pridat prvek s pozice v seznamu? (a/n): ";
            cin >> ano;
            
            if(ano == 'a' || ano == 'A' || ano == 'n' || ano == 'N' ){
                break;
            }
            else
            {
                cinIgnore();
                
            }
        }
        if(ano == 'a' || ano == 'A'){
            int odkudZadat; // 1 - kosnol 2 - soubor
            while(true){
                cout << "Chcete zadat prvek pres konsol? (a/n): ";
                cin >> ano;
                if(ano == 'a' || ano == 'A'){
                    odkudZadat = 1;
                    pridejPrvekSPoziceVSeznamu(s, odkudZadat);
                    break;
                }
                else if(ano == 'n' || ano == 'N'){
                    break;
                }
                else{
                    cinIgnore();
                }
            }
            while(true){
                cout << "Chcete zadat prvek pres soubor? (a/n): ";
                cin >> ano;
                if(ano == 'a' || ano == 'A'){
                    odkudZadat = 2;
                    pridejPrvekSPoziceVSeznamu(s, odkudZadat);
                    break;
                }
                else if(ano == 'n' || ano == 'N'){
                    break;
                }
                else{
                    cinIgnore();
                    
                }
            }
            
        }
        while(true)
        {
            cout << "Chcete vypsat delku seznama? (a/n): ";
            cin >> ano;
            
            if(ano == 'a' || ano == 'A' || ano == 'n' || ano == 'N' ){
                break;
            }
            else
            {
                cinIgnore();
                
            }
        }
        if(ano == 'a' || ano == 'A'){
            cout << delkaSeznamu(*s) << endl;
        }
        while(true){
            cout << "Chcete vypsat obsah seznamu? (a/n): ";
            cin >> ano;
            
            if(ano == 'a' || ano == 'A' || ano == 'n' || ano == 'N' ){
                break;
            }
            else
            {
                cinIgnore();
                
            }
        }
        if(ano == 'a' || ano == 'A'){
            
            while(true){
                cout << "Chece vypsat obsah seznamu do konzoli? (a/n): ";
                cin >> ano;
        
                if(ano == 'a' || ano == 'A'){
                    vypisObsahSeznamuDoKonzoli(*s);
                    break;
                    
                }
                else if(ano == 'n' || ano == 'N'){
                    break;
                }
                else{
                    cinIgnore();
                }
            }
            while(true){
                cout << "Chece vypsat obsah seznamu do souboru? (a/n): ";
                cin >> ano;
        
                if(ano == 'a' || ano == 'A'){
                    string newSoubor;
                    vypisDoSouboru(newSoubor,*s);
                    break;
                    
                }
                else if(ano == 'n' || ano == 'N'){
                    break;
                }
                else{
                    cinIgnore();
                }
            }
        }
        while(true){
            cout << "Chcete vypsat nejstarsi osobu? (a/n): ";
            cin >> ano;
            if(ano == 'a' || ano == 'A' || ano == 'n' || ano == 'N' ){
                break;
            }
            else
            {
                cinIgnore();
                
            }
        }
        
        if(ano == 'a' || ano == 'A'){
            while(true){
                cout << "Chcete vypsat nejstarsi obosu do konzoli? (a/n): ";
                cin >> ano;
                int odkud = 1;
                if(ano == 'a' || ano == 'A'){
                    najdiAvypisiNejstarsiObobu(*s, odkud);
                    break;
                    
                }
                else if(ano == 'n' || ano == 'N'){
                    break;
                }
                else{
                    cinIgnore();
                }
            }
            
            while(true){
                cout << "Chcete vypsat nejstarsi obosu do souboru? (a/n): ";
                cin >> ano;
                int vyber = 2;
                if(ano == 'a' || ano == 'A'){
                    najdiAvypisiNejstarsiObobu(*s, vyber);
                    break;
                    
                }
                else if(ano == 'n' || ano == 'N'){
                    break;
                }
                else{
                    cinIgnore();
                }
            }
        }
        int kolikOsob;
        while(true){
            cout << "Chcete vypsat nejvyssi osobu? (a/n): ";
            cin >> ano;
            if(ano == 'a' || ano == 'A' || ano == 'n' || ano == 'N' ){
                break;
            }
            else
            {
                cinIgnore();
                
            }
        }
        if(ano == 'a' || ano == 'A'){
            while(true){
                while(true){
                    cout << "Kolik nejvyssi osob chece vypsat?: ";
                    cin >> kolikOsob;
                    if(!cin){
                        cinIgnore();
                    }
                    break;
                }
                cout << "Chcete vypsat nejvyssi obosu do konzoli? (a/n): ";
                cin >> ano;
                int odkud = 1;
                if(ano == 'a' || ano == 'A'){
                    najdiZadanyPocetNejvyssiOsob(*s,odkud,kolikOsob);
                    break;
                    
                }
                else if(ano == 'n' || ano == 'N'){
                    break;
                }
                else{
                    cinIgnore();
                }
            }
            
            while(true){
                cout << "Chcete vypsat nejvyssi obosu do souboru? (a/n): ";
                cin >> ano;
                int vyber = 2;
                if(ano == 'a' || ano == 'A'){
                    najdiZadanyPocetNejvyssiOsob(*s,vyber,kolikOsob);
                    break;
                    
                }
                else if(ano == 'n' || ano == 'N'){
                    break;
                }
                else{
                    cinIgnore();
                }
            }
        }
        while(true){
            cout << "Chcete odstranit vsechny prvky s seznamu? (a/n): ";
            cin >> ano;
            
            if(ano == 'a' || ano == 'A' || ano == 'n' || ano == 'N' ){
                break;
            }
            else
            {
                cinIgnore();
                
            }
        }
        if(ano == 'a' || ano == 'A'){
            zrus(*s);
        }
        
        while(true){
            cout << "Chcete prodolzit? (a/n): ";
            cin >> ano;
            
            if(ano == 'a' || ano == 'A' || ano == 'n' || ano == 'N' ){
                break;
            }
            else
            {
                cinIgnore();
                
            }
        }
        if(ano == 'n' || ano == 'N'){
            break;
        }
}
}
