#include <iostream>
#include <typeinfo>
#include <complex>
#include "tensor.h"

using namespace std;

template <class Typ> /* konstruktor, alokuje pamiec na trojwymiarowa tablice */
Tensor<Typ>::Tensor(int x_max, int y_max, int z_max)
{
    tab_tens = new Typ **[x_max];
    for(int i=0; i<x_max; i++)
    {
        tab_tens[i] = new Typ *[y_max];
        for(int j=0; j<y_max; j++)
        {
            tab_tens[i][j] = new Typ [z_max]();
        }
    }
    x_size=x_max;
    y_size=y_max;
    z_size=z_max;
}

template <class Typ> /* konstruktor kopiujacy, alokuje miejsce dla trojwymiarowej tablicy */
Tensor<Typ>::Tensor(Tensor const &t)
{
	tab_tens = new Typ **[t.x_size];
	for(int i = 0; i<t.x_size; i++)
    {
        tab_tens[i] = new Typ *[t.y_size];
        for(int j=0; j< t.y_size; j++)
        {
            tab_tens[i][j] = new Typ [t.z_size];
            for(int k=0; k<t.z_size; k++)
            {
                tab_tens[i][j][k]=t.tab_tens[i][j][k];
            }
        }

    }
    x_size=t.x_size;
    y_size=t.y_size;
    z_size=t.z_size;
}

template <class Typ> /* destruktor */
Tensor<Typ>::~Tensor()
{
    for(int i=0; i<y_size; i++)
    {
        for(int j=0; j<z_size; j++)
        { delete[] tab_tens[i][j]; }

        delete[] tab_tens[i];
    }
    delete[] tab_tens;
}

template <class Typ> /* odczytanie elementu o danych wspolrzednych */
Typ Tensor<Typ>::show(int x, int y, int z) const
{ return tab_tens[x-1][y-1][z-1]; }

template <class Typ>
void Tensor<Typ>::change(Typ nowy, int x, int y, int z)  /* zmienianie elementu o danych wspolrzednych */
{ tab_tens[x-1][y-1][z-1]=nowy; }

template <class Typ>
std::istream& operator>>(std::istream &is, Tensor<Typ>& t) /* wczytywnie tensora */
{
    Typ pom; /* zmienna pomocnicza odpowiedzialna za chwilowe przechowywanie wczytanego elementu */
    for(int i=0; i<t.x_size; i++)
    {
        for(int j=0; j<t.y_size; j++)
        {
            for(int k=0; k<t.z_size; k++)
            {
                is>>pom;
                t.tab_tens[i][j][k]=pom;
            }

        }
    }

    return is;
}

template <class Typ>
std::ostream& operator<<(std::ostream &os, const Tensor<Typ> &t) /* wypisywanie tensora */
{
    for(int i=0; i<t.x_size; i++)
    {
        os<<endl<<"elementy o wspolrzednych x="<<i+1<<" y, z"<<endl<<endl;
        for(int j=0; j<t.y_size; j++)
        {
            for(int k=0; k<t.z_size; k++)
            { os<<t.tab_tens[i][j][k]<<" "; }

            os<<endl;
        }
    }
   return os;
}

template <class Typ>
Tensor<Typ>& Tensor<Typ>::operator=(const Tensor &t) /* przypisanie tensora */
{
    x_size=t.x_size;
    y_size=t.y_size;
    z_size=t.z_size;
    tab_tens = new Typ** [x_size];

    for(int i=0; i<x_size; i++)
    {
        tab_tens[i] = new Typ* [y_size];
        for(int j=0; j<y_size; j++)
        { tab_tens[i][j] = new Typ [z_size]; }
    }

    for(int i=0; i<x_size; i++)
    {
        for(int j=0; j<y_size; j++)
        {
            for(int k=0; k<z_size; k++)
            { tab_tens[i][j][k]=t.tab_tens[i][j][k]; }
        }
    }

   return *this;
}

template <class Typ>
Tensor<Typ> Tensor<Typ>::operator+(const Tensor &t) const /* dodawanie tensorow element po elemencie */
{
    if( this->x_size!=t.x_size || this->y_size!=t.y_size || this->z_size!=t.z_size )
    { cout<<"Tensory maja rozne rozmiary"<<endl; }
    else
    {
        int x,y,z; /* pomocnicze zmienne przechowujace rozmiary tensora */
        x=t.x_size; /* przypisanie rozmiarow x,y,z tensora */
        y=t.y_size;
        z=t.z_size;

        Tensor<Typ> POM(x,y,z); /* pomocniczy obiekt w ktorym zapisywane sa poszczegolne sumy */

        for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {
                for(int k=0; k<z; k++)
                { POM.tab_tens[i][j][k]=this->tab_tens[i][j][k]+t.tab_tens[i][j][k]; }
            }
        }

        return POM;
    }
}

template <class Typ>
Tensor<Typ> Tensor<Typ>::operator+=(const Tensor<Typ> &t) /* dodawanie tensorow element po elemencie */
{
    if( this->x_size!=t.x_size || this->y_size!=t.y_size || this->z_size!=t.z_size )
    { cout<<"Tensory maja rozne rozmiary"<<endl; }
    else
    {
        for(int i=0; i<t.x_size; i++)
        {
            for(int j=0; j<t.y_size; j++)
            {
                for(int k=0; k<t.z_size; k++)
                { this->tab_tens[i][j][k]+=t.tab_tens[i][j][k]; }
            }
        }

        return * this;
    }
}

template <class Typ>
Tensor<Typ> Tensor<Typ>::operator-(const Tensor &t) const /* odejmowanie tensorow element po elemencie */
{
    if( this->x_size!=t.x_size || this->y_size!=t.y_size || this->z_size!=t.z_size )
    { cout<<"Tensory maja rozne rozmiary"<<endl; }
    else
    {
        int x,y,z; /* pomocnicze zmienne przechowujace rozmiary tensora */
        x=t.x_size; /* przypisanie rozmiarow x,y,z tensora */
        y=t.y_size;
        z=t.z_size;

        Tensor<Typ> POM(x,y,z); /* pomocniczy obiekt w ktorym zapisywane sa poszczegolne roznice */

        for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {
                for(int k=0; k<z; k++)
                { POM.tab_tens[i][j][k]=this->tab_tens[i][j][k]-t.tab_tens[i][j][k]; }
            }
        }

        return POM;
    }
}

template <class Typ>
Tensor<Typ> Tensor<Typ>::operator-=(const Tensor<Typ> &t) /* odejmowanie tensorow element po elemencie */
{
    if( this->x_size!=t.x_size || this->y_size!=t.y_size || this->z_size!=t.z_size )
    { cout<<"Tensory maja rozne rozmiary"<<endl; }
    else
    {
        for(int i=0; i<t.x_size; i++)
        {
            for(int j=0; j<t.y_size; j++)
            {
                for(int k=0; k<t.z_size; k++)
                { this->tab_tens[i][j][k]-=t.tab_tens[i][j][k]; }
            }
        }

        return * this;
    }
}

template <class Typ>
Tensor<Typ> Tensor<Typ>::operator*(const Tensor &t) const /* mnozenie tensorow element po elemencie */
{
    if( this->x_size!=t.x_size || this->y_size!=t.y_size || this->z_size!=t.z_size )
    { cout<<"Tensory maja rozne rozmiary"<<endl; }
    else
    {
        int x,y,z; /* pomocnicze zmienne przechowujace rozmiary tensora */
        x=t.x_size; /* przypisanie rozmiarow x,y,z tensora */
        y=t.y_size;
        z=t.z_size;

        Tensor<Typ> POM(x,y,z); /* pomocniczy obiekt w ktorym zapisywane sa poszczegolne ilorazy */

        for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {
                for(int k=0; k<z; k++)
                { POM.tab_tens[i][j][k]=this->tab_tens[i][j][k]*t.tab_tens[i][j][k]; }
            }
        }

        return POM;
    }
}

template <class Typ>
Tensor<Typ> Tensor<Typ>::operator*=(const Tensor<Typ> &t) /* mnozenie tensorow element po elemencie */
{
    if( this->x_size!=t.x_size || this->y_size!=t.y_size || this->z_size!=t.z_size )
    { cout<<"Tensory maja rozne rozmiary"<<endl; }
    else
    {
        for(int i=0; i<t.x_size; i++)
        {
            for(int j=0; j<t.y_size; j++)
            {
                for(int k=0; k<t.z_size; k++)
                { this->tab_tens[i][j][k]*=t.tab_tens[i][j][k]; }
            }
        }

        return * this;
    }
}

template <class Typ>
bool Tensor<Typ>::operator==(const Tensor &t) const /* porownanie tensorow */
{
    if( this->x_size!=t.x_size || this->y_size!=t.y_size || this->z_size!=t.z_size )
    { return false; }
    else
    {
        int licznik=0; /* zmienna zapisujaca wykryta roznice */
        for(int i=0; i<t.x_size && licznik==0; i++)
        {
            for(int j=0; j<t.y_size && licznik==0; j++)
            {
                for(int k=0; k<t.z_size && licznik==0; k++)
                {
                    if( this->tab_tens[i][j][k]!=t.tab_tens[i][j][k] )
                    { licznik++; } /* jesli jakies elementy sa rozne zwieksz licznik */
                }
            }
        }

        if( licznik==0 )
        { return true; }
        else
        { return false; }
    }
}

template <class Typ>
bool Tensor<Typ>::operator!=(const Tensor &t) const /* porownanie tensorow */
{
    if( this->x_size!=t.x_size || this->y_size!=t.y_size || this->z_size!=t.z_size )
    { return true; }
    else
    {
        int licznik=0; /* zmienna zapisujaca wykryta roznice */
        for(int i=0; i<t.x_size && licznik==0; i++)
        {
            for(int j=0; j<t.y_size && licznik==0; j++)
            {
                for(int k=0; k<t.z_size && licznik==0; k++)
                {
                    if( this->tab_tens[i][j][k]!=t.tab_tens[i][j][k] )
                    { licznik++; } /* jesli jakies elementy sa rozne zwieksz licznik */
                }
            }
        }

        if( licznik==0 )
        { return false; }
        else
        { return true; }
    }
}

