#ifndef TERVEKTOR_H_INCLUDED
#define TERVEKTOR_H_INCLUDED

#include  <iostream>

using std::ostream;

class tervektor{
    private:
        double *pData;
        int siz;
    public:
        tervektor(double x=0, double y=0, double z=0);
        tervektor(tervektor const& rvektor);
        ~tervektor();
        tervektor &operator=(tervektor const& rvektor);
        tervektor operator+(tervektor const& rvektor);
        tervektor operator-(tervektor const& rvektor);
        tervektor operator*(tervektor const& rvektor);
        tervektor operator*(double szorzo);
        int getsiz(){ return siz;}
        friend ostream& operator<<(ostream& os, tervektor const& v);
};

#endif // TERVEKTOR_H_INCLUDED
