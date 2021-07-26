//
//  main.cpp
//  spojovy seznam
//
//  Created by Paul Ekishev on 02/11/2020.
//

#include <iostream>
#include "do.hpp"
using namespace std;


int main(){
    
    Seznam *s = new Seznam;
    praceSUzivately(s);
    if(s->hlava!=nullptr){
        zrus(*s);
    }
    delete s;
    
    return 0;
}
