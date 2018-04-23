#ifndef tensor_h
#define tensor_h

using namespace std;

const unsigned int Big=3; /* stala odpowiadajaca za domyslny rozmiar tensora */

template <class Typ> class Tensor;
template <class Typ> std::istream& operator>>( std::istream &is, Tensor<Typ> &t);

template <class Typ> class Tensor;
template <class Typ> std::ostream& operator<<( std::ostream &os, const Tensor<Typ> &t);

/* SZABLON KLASY REPREZENTUJACY TENSOR */

template <class Typ>
class Tensor
{
    Typ ***tab_tens; /* deklaracja trojwymiarowej tblicy przechowywujacej wartosci tensora */
    int x_size; /* x wymiar tensora */
    int y_size; /* y wymiar tensora */
    int z_size; /* z wymiar tensora */

public:

    Tensor( int=Big, int=Big, int=Big); /* konstruktor */
    Tensor( Tensor const &t); /* konstruktor kopiujacy */
   ~Tensor(); /* destruktor */
    /* metody */
    Typ show (int x, int y, int z) const; /* odczytanie elementu o danych wspolrzednych */
    void change(Typ nowy, int x, int y, int z); /* zmienianie elementu o danych wspolrzednych */
    /*przeciazenia operatorow */
    Tensor<Typ>& operator=(const Tensor &t);

    Tensor<Typ> operator+(const Tensor<Typ> &t) const;
    Tensor<Typ> operator+=(const Tensor<Typ> &t);

    Tensor<Typ> operator-(const Tensor<Typ> &t) const;
    Tensor<Typ> operator-=(const Tensor<Typ> &t);

    Tensor<Typ> operator*(const Tensor<Typ> &t) const;
    Tensor<Typ> operator*=(const Tensor<Typ> &t);

    bool operator==(const Tensor &t) const;
    bool operator!=(const Tensor &t) const;

    friend
    std::istream& operator>> <> (std::istream &is, Tensor<Typ> &t);

    friend
    std::ostream& operator<< <> (std::ostream &os, const Tensor<Typ> &t);

};

#endif
