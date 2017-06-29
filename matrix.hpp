#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "memtrace.h"
#include "tervektor.h"

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;


template<typename TYPE>
class matrix {
    private:
        TYPE *pData;
        unsigned int sor;
        unsigned int oszlop;
    public:

       /* csak ez létezik, a többi kétertemű lenne
        * 2 paraméteres konstruktor
        */
        matrix(unsigned int sor=1, unsigned int oszlop=1);

       /* másoló konstruktor
        */
        matrix(matrix const& mat);

       /* destruktor, rövid, azért van itt
        */
        ~matrix() {cout << "Dtor" << endl; delete[] pData;}

       /* tag lekérdezéséhez
        */
        TYPE operator()(unsigned int sor, unsigned int oszlop) const;

       /* tag módosításához
        */
        TYPE& operator()(unsigned int sor, unsigned int oszlop);

       /* operator=
        */
        matrix<TYPE>& operator=(matrix<TYPE> const& rmat);

       /* két mátrix összeadása
        */
        matrix<TYPE> operator+(matrix<TYPE> const& rmat);

       /* két mátrix összeadása
        * visszavezetve op+ ra
        */
        matrix<TYPE>& operator+=(matrix<TYPE> const& rmat){ (*this)=(*this) + rmat; return *this;}

       /* két mátrix kivonása
        */
        matrix<TYPE> operator-(matrix<TYPE> const& rmat);

       /* két mátrix kivonása
        * visszavezetve op- ra
        */
        matrix<TYPE>& operator-=(matrix<TYPE> const& rmat){ (*this)=(*this) - rmat; return *this;}

       /* mátrix megszorzása konstanssal jobbról
        */
        matrix<TYPE> operator*(TYPE const x);

       /* mátrix megszorzása konstanssal
        * visszavezetve op* ra
        */
        matrix<TYPE>& operator*=(TYPE szorzo){ (*this)=(*this) * szorzo; return *this;}

       /* matrixszorzás
        */
        matrix<TYPE> operator*(matrix<TYPE> const& rmat);

       /* mátrixszorzás
        * visszavezetve op* ra
        */
        matrix<TYPE>& operator*=(matrix<TYPE> const& rmat){ (*this)=(*this) * rmat; return *this;}

       /*sor lekérdezése
        */
        unsigned int get_sor() const {return sor;}

       /*oszlop lekérdezése
        */
        unsigned int get_oszlop() const {return oszlop;}

};

template<typename TYPE>     //ctor
matrix<TYPE>::matrix(unsigned int sor, unsigned int oszlop): sor(sor), oszlop(oszlop) {
    cout << "Ket param ctor" << endl;
    pData=new TYPE[sor*oszlop];
    for(unsigned int i= 1; i<=sor; i++){
        for(unsigned int j=1; j<=oszlop; j++){
            (*this)(i,j)=0;
        }
    }
}

template<typename TYPE>     //másolo
matrix<TYPE>::matrix(matrix<TYPE> const& mat){
    cout << "Copy ctor" << endl;
    sor=mat.sor;
    oszlop=mat.oszlop;
    pData=new TYPE[sor*oszlop];
    for(unsigned int i= 1; i<=sor; i++){
        for(unsigned int j=1; j<=oszlop; j++){
            (*this)(i,j)=mat(i,j);
        }
    }
}

template<typename TYPE>     //lekérõ
TYPE matrix<TYPE>::operator()(unsigned int sor, unsigned int oszlop) const {
    sor--;
    oszlop--;
    if(sor<this->sor && oszlop<this->oszlop)
        return pData[sor*this->oszlop+oszlop];
    const char* hiba = "Nem letezo index";
    throw(hiba);
}

template<typename TYPE>     //módositó
TYPE& matrix<TYPE>::operator()(unsigned int sor, unsigned int oszlop){
    sor--;
    oszlop--;
    if(sor<this->sor && oszlop<this->oszlop)
        return pData[sor*this->oszlop+oszlop];
    const char* hiba = "Nem letezo index";
    throw(hiba);
}

template<typename TYPE>     //op=
matrix<TYPE> &matrix<TYPE>::operator=(matrix<TYPE> const& rmat){
    if(this!=&rmat){
        cout << "op=" << endl;
        if(pData!=NULL)
            delete[] pData;
        oszlop=rmat.oszlop;
        sor=rmat.sor;
        pData=new TYPE[sor*oszlop];
        for(unsigned int i= 1; i<=sor; i++){
            for(unsigned int j=1; j<=oszlop; j++){
                (*this)(i,j)=rmat(i,j);
            }
        }
    }
    return *this;
}

template<typename TYPE>     //op+
matrix<TYPE> matrix<TYPE>::operator+(matrix<TYPE> const& rmat){
    if( sor!=rmat.sor || oszlop!=rmat.oszlop ){
        const char* hiba = "A ket matrix merete nem egyezik meg.\nA ket matrix nem osszeadhato.";
        throw(hiba);
    }
    matrix<TYPE> uj(sor, oszlop);
    for(unsigned int i= 1; i<=sor; i++){
        for(unsigned int j=1; j<=oszlop; j++){
            uj(i,j)= (*this)(i,j)+rmat(i,j);
        }
    }
    return uj;
}

template<typename TYPE>     //op-
matrix<TYPE> matrix<TYPE>::operator-(matrix<TYPE> const& rmat){
    if( sor!=rmat.sor || oszlop!=rmat.oszlop ){
        const char* hiba = "A ket matrix merete nem egyezik meg.\nA ket matrix nem kivonhato.";
        throw(hiba);
    }
    matrix<TYPE> uj(sor, oszlop);
    for(unsigned int i= 1; i<=sor; i++){
        for(unsigned int j=1; j<=oszlop; j++){
            uj(i,j)= (*this)(i,j)-rmat(i,j);
        }
    }
    return uj;
}


template<typename TYPE>     //mátrix szorzása konstanssal jobbról
matrix<TYPE> matrix<TYPE>::operator*(TYPE const x){
    matrix<TYPE> uj(sor, oszlop);
    for(unsigned int i= 1; i<=sor; i++){
        for(unsigned int j=1; j<=oszlop; j++){
            uj(i,j)= x*(*this)(i,j);
        }
    }
    return uj;
}

template<typename TYPE>     //balról szorzás konstanssal, visszavezettem a belsõ op*-ra
matrix<TYPE> operator*(TYPE left, matrix<TYPE> rmat){
    return rmat*left;
}

template<typename TYPE>     //mátrixszorszás
matrix<TYPE> matrix<TYPE>::operator*(matrix<TYPE> const& rmat){
    if( oszlop!=rmat.sor ){
        const char* hiba = "A szorzas errol az oldalrol nem elvegezheto.";
        throw(hiba);
    }
    matrix<TYPE> uj(sor, rmat.oszlop); //ikj sorrend szgarch
    for(unsigned int i = 1; i<=this->sor; i++){
        for(unsigned int k = 1; k<=this->oszlop; k++){
            for(unsigned int j = 1; j<=rmat.oszlop; j++){
                uj(i,j) = uj(i,j) + (*this)(i,k) * rmat(k,j);
            }
        }
    }

    return uj;
}


template<typename TYPE>     //mátrix kiiratás
ostream& operator<<(ostream& os, matrix<TYPE> const& mat){
    os << endl;
    const unsigned int sor=mat.get_sor();
    const unsigned int oszlop=mat.get_oszlop();
    os << sor << 'x' << oszlop  << endl;
    for(unsigned int i=1; i<=sor; i++){
        for(unsigned int j=1; j<=oszlop; j++){
            os << std::setw(4);
            os << mat(i,j) << ' ';
        }
    os << endl;
    }
    os << endl;
    return os;
}



template<>     //mátrix kiiratás
ostream& operator<<(ostream& os, matrix<tervektor> const& mat){
    os << endl;
    unsigned int sor=mat.get_sor();
    unsigned int oszlop=mat.get_oszlop();
    os << sor << 'x' << oszlop  << endl;
    for(unsigned int i=1; i<=sor; i++){
        for(unsigned int j=1; j<=oszlop; j++){
            os << "("<< mat(i,j) << ")" << '\t' ;
        }
    os << endl;
    }
    os << endl;
    return os;
}


template<typename TYPE>     //mátrix beolvasás
istream& operator>>(istream& is, matrix<TYPE>* &mat){
    is >> std::skipws;
    unsigned int sor;
    unsigned int oszlop;
    char x;
    is >> sor >> x >> oszlop;
    if(x!='x') throw("Helytelen meret beolvasasa.");
    matrix<TYPE> *uj=new matrix<int>(sor,oszlop);
    for(unsigned int i=1; i<=sor; i++){
        for(unsigned int j=1; j<=oszlop; j++){
            is >> (*uj)(i,j);
        }
    }
    mat=uj;
    is >> std::noskipws;
    return is;
}

///*********************************   feltöltők
///*********************************

template<typename TYPE> //igazából intre használom csak
void feltolt(matrix<TYPE> &m){
    int sor=m.get_sor();
    int oszlop=m.get_oszlop();
    for(int i=1; i<=sor; i++)
        for(int j=1; j<=oszlop; j++)
            m(i,j)=j*i;
}

template<>     //azért specifikáltam a feltöltést, hogy jobban eltérjen az int mátrixoktól
void feltolt(matrix<double> &m){
    int sor=m.get_sor();
    int oszlop=m.get_oszlop();
    for(int i=1; i<=sor; i++)
        for(int j=1; j<=oszlop; j++)
            m(i,j)= (rand() % 33)/5.0;
}

template<>     // tervektor matrix feltöltése
void feltolt(matrix<tervektor> &m){
    int sor=m.get_sor();
    int oszlop=m.get_oszlop();
    for(int i=1; i<=sor; i++)
        for(int j=1; j<=oszlop; j++){
            double rng=(rand() % 33)/5.0;
            m(i,j)= tervektor(i,j,rng);
        }
}


#endif // MATRIX_HPP_INCLUDED
