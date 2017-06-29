#include <iostream>
#include <iomanip>

#include "memtrace.h"
#include "tervektor.h"
#include "teszt.h"


using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::cerr;



int main(int argc, char *argv[]){
    if (!(argc>1)){
        try{
            cout << "Valaszd ki mit szeretnel" << endl;
            cout << "\t 0. manualis matrix beolvasasa" << endl;
            cout << "\t 1. teszt1 (ctor,cpy,operatorok, int matrix)" << endl;
            cout << "\t 2. teszt2 (adattag lekerese, modositasa, double matrix)" << endl;
            cout << "\t 3. teszt3 (tervektor)" << endl;
            cout << "\t 4. lekero() hiba" << endl;
            cout << "\t 5. modosito() hiba" << endl;
            cout << "\t 6. osszeadas, kivonas hiba" << endl;
            cout << "\t 7. szorzas hiba" << endl;
            cout << endl;
            int menu;
            cin >> menu;
            switch(menu){
                case 0: beolvas_teszt(); break;
                case 1: teszt_1(); break;
                case 2: teszt_2(); break;
                case 3: teszt_3(); break;
                case 4: index_hiba1(); break;
                case 5: index_hiba2(); break;
                case 6: osszeadas_kivonas_hiba(); break;
                case 7: szorzas_hiba(); break;
                default: throw("Helytelen menuhasznalat"); break;
            }
        }catch(const char *hiba){
            cerr << hiba << endl;    //ha valami kivételt dob
        }
     }
    else{
        try{
            beolvas_teszt();
        }catch(const char* hiba){
            cerr << hiba << endl;
        }
        teszt_1();  //ezekben nincs hiba
        teszt_2();
        teszt_3();
    }
    return 0;
}
