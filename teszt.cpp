#include <iostream>
#include <ctime>


#include "memtrace.h"
#include "teszt.h"
#include "matrix.hpp"
#include "tervektor.h"

void beolvas_teszt(){
        cout << "Int matrix beolvasasa, eloszor meret(NxM) megadasa, majd ertekek" << endl;
        matrix<int> *input;
        cin >> input;
        cout << (*input) << endl;
        delete input;
        cout << "**************************************************************************************" << endl;
        cout << "**************************************************************************************" << endl;
        cout << "**************************************************************************************" << endl;
}

void teszt_1(){
        cout << "***********************----------------------------------------***********************" << endl;
        cout << "***********************teszt1 (ctor,cpy,operatorok, int matrix)***********************" << endl;
        cout << "***********************----------------------------------------***********************" << endl;
        matrix<int> m1(5,3);        //ctor
        feltolt(m1);
        cout << "m1" << m1 << endl;


        matrix<int> m2=m1;          //copy
        cout << "m2" << m2 << endl;


        matrix<int> m3=m1+m2;       //op+
        cout << "m3=m1+m2" << m3 << endl;


        matrix<int> m4(5,3);
        m4=m3;                      //op=
        cout << "m4=m3"    << m4 << endl;


        m4+=m3;                     //op+=
        cout << "m4+=m3"   << m4 << endl;


        m4-=m3;                     //op-=  op-
        cout << "m4-=m3"   << m4 << endl;
                                    //mátrixszorzás op*= és op*
        matrix<int> m5(3,5);
        feltolt(m5);
        cout << "m5" << m5 << endl;
        m4*=m5;
        cout << "m4*=m5"   << m4 << endl;

                                    //op* globális, de op* is meghívódik
        cout << "7*m1"     << 7*m1 << endl;

                                    //op*=
        m1*=7;
        cout << "m1*=7"    << m1 << endl;

}// dtor

void teszt_2(){
        cout << "*****************----------------------------------------------------*****************" << endl;
        cout << "*****************teszt2 (adattag lekerese, modositasa, double matrix)*****************" << endl;
        cout << "*****************----------------------------------------------------*****************" << endl;
        srand(time(NULL));
        matrix<double> dmatrix(5,5);    //double
        feltolt(dmatrix);
        cout << dmatrix << endl;
        cout << "dmatrix(3,3)" << " "<< dmatrix(3,3) << endl;
        cout << "dmatrix(3,3)=0" << endl;
        dmatrix(3,3)=0;
        cout << dmatrix << endl;
}

void teszt_3(){ //térvektoros
        cout << "**********************************------------------**********************************" << endl;
        cout << "**********************************teszt3 (tervektor)**********************************" << endl;
        cout << "**********************************------------------**********************************" << endl;
        matrix<tervektor> termatrix1(3,3);
        matrix<tervektor> termatrix2(3,3);
        feltolt(termatrix1);
        feltolt(termatrix2);
        cout << "termatrix1" << termatrix1 << endl; //specializált
        cout << "termatrix2" << termatrix2 << endl; //specializált
        cout << "termatrix1*termatrix2" << termatrix1*termatrix2 << endl;
        cout << "termatrix1+termatrix2" << termatrix1+termatrix2 << endl;
        termatrix1-=termatrix1;
        cout << "termatrix1-=termatrix1" << termatrix1 << endl;
        cout << "termatrix1(1,1)" << termatrix1(1,1) << endl;
        cout << "termatrix1(1,1)=termatrix2(1,1)" << endl;
        termatrix1(1,1)=termatrix2(1,1);
        cout << termatrix1 << endl;
}

void index_hiba1(){ //lekero
        cout << "*************************************-------------************************************" << endl;
        cout << "*************************************lekero() hiba************************************" << endl;
        cout << "*************************************-------------************************************" << endl;
        matrix<int> tesztmatrix(5,5);
        feltolt(tesztmatrix);
        cout << "tesztmatrix" << tesztmatrix << endl;
        cout << "tesztmatrix(3,3)" << " = " << tesztmatrix(3,3) << endl;
        cout << "tesztmatrix(10,10)" << endl;
        cout << tesztmatrix(10,10) << endl;
}
void index_hiba2(){ //modosito
        cout << "************************************---------------***********************************" << endl;
        cout << "************************************modosito() hiba***********************************" << endl;
        cout << "************************************---------------***********************************" << endl;
        matrix<int> tesztmatrix(5,5);
        feltolt(tesztmatrix);
        cout << "tesztmatrix" << tesztmatrix << endl;
        cout << "tesztmatrix(3,3)" << " = " << tesztmatrix(3,3) << endl;
        cout << "tesztmatrix(3,3)=5 utan a matrix" << " ";
        tesztmatrix(3,3)=5;
        cout << tesztmatrix << endl;
        cout << "tesztmatrix(10,10)=5 utan a matrix" << endl;
        tesztmatrix(10,10)=5;
        cout << tesztmatrix << endl;
}
void osszeadas_kivonas_hiba(){
        cout << "*******************************-----------------------********************************" << endl;
        cout << "*******************************osszeadas, kivonas hiba********************************" << endl;
        cout << "*******************************-----------------------********************************" << endl;
        matrix<int> bal(5,5);
        matrix<int> jobb(2,2);
        feltolt(bal);
        feltolt(jobb);
        cout << "bal" << " " << bal << endl;
        cout << "jobb" << " " << jobb << endl;
        int akarat;
        cout << "Osszeadas(1) vagy kivonas(2)?";
        cin >> akarat;
        if (akarat==1) bal+jobb; else
        if (akarat==2) bal-jobb; else
        throw("Rossz menupont (osszeadas_kivonas_hiba)");

}
void szorzas_hiba(){
        cout << "*************************************------------*************************************" << endl;
        cout << "*************************************szorzas hiba*************************************" << endl;
        cout << "*************************************------------*************************************" << endl;
        matrix<int> bal(5,5);
        matrix<int> jobb(5,2);
        feltolt(bal);
        feltolt(jobb);
        cout << "bal" << " " << bal << endl;
        cout << "jobb" << " " << jobb << endl;
        int akarat;
        cout << "bal*jobb(1) vagy jobb*bal(2)?";
        cin >> akarat;
        if (akarat==1){cout << "bal*jobb" << " " << bal*jobb << endl;}else
        if (akarat==2){cout << "jobb*bal" << " " << jobb*bal << endl;}else
        throw("Rossz menupont (szorzas_hiba)");
}
