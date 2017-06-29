#include  <iostream>
#include  <iomanip>

#include "memtrace.h"
#include "tervektor.h"


using std::ostream;

tervektor::tervektor(double x, double y, double z) { //ctor 3 param
        pData= new double[3];
        siz=3;
        pData[0]=x;
        pData[1]=y;
        pData[2]=z;
}


tervektor::tervektor(tervektor const& rvektor) { //copy
        this->pData= new double[rvektor.siz];
        this->siz=rvektor.siz;
        for(int i=0; i<this->siz; i++)
            pData[i]=rvektor.pData[i];
}

tervektor::~tervektor(){
        delete[] pData;
}

tervektor& tervektor::operator=(tervektor const& rvektor) {
        if(this!=&rvektor){
            delete[] pData;
            this->pData= new double[rvektor.siz];
            this->siz=rvektor.siz;
            for(int i=0; i<this->siz; i++)
                pData[i]=rvektor.pData[i];
        }
        return (*this);
}

tervektor tervektor::operator+(tervektor const& rvektor){
        tervektor uj;
        for(int i=0; i<siz; i++)
            uj.pData[i]=pData[i]+rvektor.pData[i];
        return uj;
}
tervektor tervektor::operator-(tervektor const& rvektor){
        tervektor uj;
        for(int i=0; i<siz; i++)
            uj.pData[i]=pData[i]-rvektor.pData[i];
        return uj;
}
tervektor tervektor::operator*(tervektor const& rvektor){   //vektoriális szorzat, csak hogy vektor maradjon
        double i=pData[1]*rvektor.pData[2]-pData[2]*rvektor.pData[1],
                j=pData[2]*rvektor.pData[0]-pData[0]*rvektor.pData[2],
                k=pData[0]*rvektor.pData[1]-pData[1]*rvektor.pData[0];
        return tervektor(i,j,k) ;
}
tervektor tervektor::operator*(double szorzo){  //jobbról
        tervektor uj;
        for(int i=0; i<siz; i++)
            uj.pData[i]=pData[i]*szorzo;
        return uj;
}

tervektor operator*(tervektor const& lvektor, double szorzo){   //balról
        return lvektor*szorzo;
}

ostream& operator<<(ostream& os, tervektor const& v){
        for(int i=0; i<v.siz;i++){
            os << std::setw(3);
            os << v.pData[i];
            if(i<(v.siz-1)) os << ",  ";
        }
        return os;
}

