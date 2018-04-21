#include <iostream>
#include <typeinfo>
#include <complex>
#include "test.h"
#include "tensor.h"
#include "tens.h"

using namespace std;

void test()
{
    if(test_1())
       { cout<<"test_1: PASS"<<endl; }
    else
       { cout<<"test_1: FAIL"<<endl; }

    if(test_2())
       { cout<<"test_2: PASS"<<endl; }
    else
       { cout<<"test_2: FAIL"<<endl; }

    if(test_3())
       { cout<<"test_3: PASS"<<endl; }
    else
       { cout<<"test_3: FAIL"<<endl; }

    if(test_4())
       { cout<<"test_4: PASS"<<endl; }
    else
       { cout<<"test_4: FAIL"<<endl; }

    if(test_5())
       { cout<<"test_5: PASS"<<endl; }
    else
       { cout<<"test_5: FAIL"<<endl; }

    if(test_6())
       { cout<<"test_6: PASS"<<endl; }
    else
       { cout<<"test_6: FAIL"<<endl; }

    cout<<endl<<"PRZYKLAD:"<<endl;
    example();
}

bool test_1()
{
    Tensor<int> A(2,2,2);  /* tensor testowy */
    Tensor<int> B(2,2,2);  /* tensor testowy */
    Tensor<int> C(2,2,2);  /* pomocniczy tensor testowy */

    Tensor<int> Wynik_dod(2,2,2); /* tensor zawierajacy poprawny wynik dodawania */
    Tensor<int> Wynik_mn(2,2,2); /* tensor zawierajacy poprawny wynik mnozenia */
    Tensor<int> Wynik_ode(2,2,2); /* tensor zawierajacy poprawny wynik odejmowania */

    /* elementy pierwszego tensora */
    int element_1_1=3, element_2_1=4, element_3_1=3, element_4_1=0;
    int element_5_1=-1, element_6_1=4, element_7_1=2, element_8_1=3;
    /* elementy drugiego tensora */
    int element_1_2=1, element_2_2=4, element_3_2=3, element_4_2=6;
    int element_5_2=2, element_6_2=10, element_7_2=1, element_8_2=9;

    A.change(element_1_1 ,1,1,1);
    A.change(element_2_1 ,1,1,2);
    A.change(element_3_1 ,1,2,1);
    A.change(element_4_1 ,1,2,2);
    A.change(element_5_1 ,2,1,1);
    A.change(element_6_1 ,2,1,2);
    A.change(element_7_1 ,2,2,1);
    A.change(element_8_1 ,2,2,2);

    B.change(element_1_2 ,1,1,1);
    B.change(element_2_2 ,1,1,2);
    B.change(element_3_2 ,1,2,1);
    B.change(element_4_2 ,1,2,2);
    B.change(element_5_2 ,2,1,1);
    B.change(element_6_2 ,2,1,2);
    B.change(element_7_2 ,2,2,1);
    B.change(element_8_2 ,2,2,2);

    Wynik_dod.change(element_1_1+element_1_2 ,1,1,1);
    Wynik_dod.change(element_2_1+element_2_2 ,1,1,2);
    Wynik_dod.change(element_3_1+element_3_2 ,1,2,1);
    Wynik_dod.change(element_4_1+element_4_2 ,1,2,2);
    Wynik_dod.change(element_5_1+element_5_2 ,2,1,1);
    Wynik_dod.change(element_6_1+element_6_2 ,2,1,2);
    Wynik_dod.change(element_7_1+element_7_2 ,2,2,1);
    Wynik_dod.change(element_8_1+element_8_2 ,2,2,2);

    Wynik_ode.change(element_1_1-element_1_2 ,1,1,1);
    Wynik_ode.change(element_2_1-element_2_2 ,1,1,2);
    Wynik_ode.change(element_3_1-element_3_2 ,1,2,1);
    Wynik_ode.change(element_4_1-element_4_2 ,1,2,2);
    Wynik_ode.change(element_5_1-element_5_2 ,2,1,1);
    Wynik_ode.change(element_6_1-element_6_2 ,2,1,2);
    Wynik_ode.change(element_7_1-element_7_2 ,2,2,1);
    Wynik_ode.change(element_8_1-element_8_2 ,2,2,2);

    Wynik_mn.change(element_1_1*element_1_2 ,1,1,1);
    Wynik_mn.change(element_2_1*element_2_2 ,1,1,2);
    Wynik_mn.change(element_3_1*element_3_2 ,1,2,1);
    Wynik_mn.change(element_4_1*element_4_2 ,1,2,2);
    Wynik_mn.change(element_5_1*element_5_2 ,2,1,1);
    Wynik_mn.change(element_6_1*element_6_2 ,2,1,2);
    Wynik_mn.change(element_7_1*element_7_2 ,2,2,1);
    Wynik_mn.change(element_8_1*element_8_2 ,2,2,2);

    if(A.show(1,2,2)!=element_4_1)
       { return false; }
    if(B.show(2,1,1)!=element_5_2)
       { return false; }

    C=A+B;
    if(C!=Wynik_dod)
       { return false; }

    C=A-B;
    if(C!=Wynik_ode)
       { return false; }

    C=A*B;
    if(C!=Wynik_mn)
       { return false; }

    A+=B;
    if(A!=Wynik_dod)
       { return false; }

    if(A==B)
       { return false; }
    else
       { return true; }
}

bool test_2()
{
    Tensor<double> A(2,2,2);  /* tensor testowy */
    Tensor<double> B(2,2,2);  /* tensor testowy */
    Tensor<double> C(2,2,2);  /* pomocniczy tensor testowy */

    Tensor<double> Wynik_dod(2,2,2); /* tensor zawierajacy poprawny wynik dodawania */
    Tensor<double> Wynik_mn(2,2,2); /* tensor zawierajacy poprawny wynik mnozenia */
    Tensor<double> Wynik_ode(2,2,2); /* tensor zawierajacy poprawny wynik odejmowania */

    /* elementy pierwszego tensora */
    double element_1_1=3.2, element_2_1=4.1, element_3_1=3.01, element_4_1=0.1;
    double element_5_1=-1, element_6_1=4.51, element_7_1=2.55, element_8_1=3.63;
    /* elementy drugiego tensora */
    double element_1_2=1.5, element_2_2=4.6, element_3_2=3, element_4_2=6;
    double element_5_2=2.12, element_6_2=10, element_7_2=1.001, element_8_2=9.9;

    A.change(element_1_1 ,1,1,1);
    A.change(element_2_1 ,1,1,2);
    A.change(element_3_1 ,1,2,1);
    A.change(element_4_1 ,1,2,2);
    A.change(element_5_1 ,2,1,1);
    A.change(element_6_1 ,2,1,2);
    A.change(element_7_1 ,2,2,1);
    A.change(element_8_1 ,2,2,2);

    B.change(element_1_2 ,1,1,1);
    B.change(element_2_2 ,1,1,2);
    B.change(element_3_2 ,1,2,1);
    B.change(element_4_2 ,1,2,2);
    B.change(element_5_2 ,2,1,1);
    B.change(element_6_2 ,2,1,2);
    B.change(element_7_2 ,2,2,1);
    B.change(element_8_2 ,2,2,2);

    Wynik_dod.change(element_1_1+element_1_2 ,1,1,1);
    Wynik_dod.change(element_2_1+element_2_2 ,1,1,2);
    Wynik_dod.change(element_3_1+element_3_2 ,1,2,1);
    Wynik_dod.change(element_4_1+element_4_2 ,1,2,2);
    Wynik_dod.change(element_5_1+element_5_2 ,2,1,1);
    Wynik_dod.change(element_6_1+element_6_2 ,2,1,2);
    Wynik_dod.change(element_7_1+element_7_2 ,2,2,1);
    Wynik_dod.change(element_8_1+element_8_2 ,2,2,2);

    Wynik_ode.change(element_1_1-element_1_2 ,1,1,1);
    Wynik_ode.change(element_2_1-element_2_2 ,1,1,2);
    Wynik_ode.change(element_3_1-element_3_2 ,1,2,1);
    Wynik_ode.change(element_4_1-element_4_2 ,1,2,2);
    Wynik_ode.change(element_5_1-element_5_2 ,2,1,1);
    Wynik_ode.change(element_6_1-element_6_2 ,2,1,2);
    Wynik_ode.change(element_7_1-element_7_2 ,2,2,1);
    Wynik_ode.change(element_8_1-element_8_2 ,2,2,2);

    Wynik_mn.change(element_1_1*element_1_2 ,1,1,1);
    Wynik_mn.change(element_2_1*element_2_2 ,1,1,2);
    Wynik_mn.change(element_3_1*element_3_2 ,1,2,1);
    Wynik_mn.change(element_4_1*element_4_2 ,1,2,2);
    Wynik_mn.change(element_5_1*element_5_2 ,2,1,1);
    Wynik_mn.change(element_6_1*element_6_2 ,2,1,2);
    Wynik_mn.change(element_7_1*element_7_2 ,2,2,1);
    Wynik_mn.change(element_8_1*element_8_2 ,2,2,2);

    if(A.show(1,2,2)!=element_4_1)
       { return false; }
    if(B.show(2,1,1)!=element_5_2)
       { return false; }

    C=A+B;
    if(C!=Wynik_dod)
       { return false; }

    C=A-B;
    if(C!=Wynik_ode)
       { return false; }

    C=A*B;
    if(C!=Wynik_mn)
       { return false; }

    A+=B;
    if(A!=Wynik_dod)
       { return false; }

    if(A==B)
       { return false; }
    else
       { return true; }
}

bool test_3()
{

    Tensor< complex<int> > A(2,2,2);  /* tensor testowy */
    Tensor< complex<int> > B(2,2,2);  /* tensor testowy */
    Tensor< complex<int> > C(2,2,2);  /* pomocniczy tensor testowy */

    Tensor< complex<int> > Wynik_dod(2,2,2); /* tensor zawierajacy poprawny wynik dodawania */
    Tensor< complex<int> > Wynik_mn(2,2,2); /* tensor zawierajacy poprawny wynik mnozenia */
    Tensor< complex<int> > Wynik_ode(2,2,2); /* tensor zawierajacy poprawny wynik odejmowania */

    /* elementy pierwszego tensora */
    complex<int> element_1_1=(3,1), element_2_1=(4,2), element_3_1=(0,1), element_4_1=(5,0);
    complex<int> element_5_1=(-3,8), element_6_1=(5,2), element_7_1=(3,9), element_8_1=(0,0);
    /* elementy drugiego tensora */
    complex<int> element_1_2=(7,4), element_2_2=(-2,-1), element_3_2=(5,1), element_4_2=(1,2);
    complex<int> element_5_2=(0,0), element_6_2=(1,0), element_7_2=(0,1), element_8_2=(0,0);

    A.change(element_1_1 ,1,1,1);
    A.change(element_2_1 ,1,1,2);
    A.change(element_3_1 ,1,2,1);
    A.change(element_4_1 ,1,2,2);
    A.change(element_5_1 ,2,1,1);
    A.change(element_6_1 ,2,1,2);
    A.change(element_7_1 ,2,2,1);
    A.change(element_8_1 ,2,2,2);

    B.change(element_1_2 ,1,1,1);
    B.change(element_2_2 ,1,1,2);
    B.change(element_3_2 ,1,2,1);
    B.change(element_4_2 ,1,2,2);
    B.change(element_5_2 ,2,1,1);
    B.change(element_6_2 ,2,1,2);
    B.change(element_7_2 ,2,2,1);
    B.change(element_8_2 ,2,2,2);

    Wynik_dod.change(element_1_1+element_1_2 ,1,1,1);
    Wynik_dod.change(element_2_1+element_2_2 ,1,1,2);
    Wynik_dod.change(element_3_1+element_3_2 ,1,2,1);
    Wynik_dod.change(element_4_1+element_4_2 ,1,2,2);
    Wynik_dod.change(element_5_1+element_5_2 ,2,1,1);
    Wynik_dod.change(element_6_1+element_6_2 ,2,1,2);
    Wynik_dod.change(element_7_1+element_7_2 ,2,2,1);
    Wynik_dod.change(element_8_1+element_8_2 ,2,2,2);

    Wynik_ode.change(element_1_1-element_1_2 ,1,1,1);
    Wynik_ode.change(element_2_1-element_2_2 ,1,1,2);
    Wynik_ode.change(element_3_1-element_3_2 ,1,2,1);
    Wynik_ode.change(element_4_1-element_4_2 ,1,2,2);
    Wynik_ode.change(element_5_1-element_5_2 ,2,1,1);
    Wynik_ode.change(element_6_1-element_6_2 ,2,1,2);
    Wynik_ode.change(element_7_1-element_7_2 ,2,2,1);
    Wynik_ode.change(element_8_1-element_8_2 ,2,2,2);

    Wynik_mn.change(element_1_1*element_1_2 ,1,1,1);
    Wynik_mn.change(element_2_1*element_2_2 ,1,1,2);
    Wynik_mn.change(element_3_1*element_3_2 ,1,2,1);
    Wynik_mn.change(element_4_1*element_4_2 ,1,2,2);
    Wynik_mn.change(element_5_1*element_5_2 ,2,1,1);
    Wynik_mn.change(element_6_1*element_6_2 ,2,1,2);
    Wynik_mn.change(element_7_1*element_7_2 ,2,2,1);
    Wynik_mn.change(element_8_1*element_8_2 ,2,2,2);

    if(A.show(1,2,2)!=element_4_1)
       { return false; }
    if(B.show(2,1,1)!=element_5_2)
       { return false; }

    C=A+B;
    if(C!=Wynik_dod)
       { return false; }

    C=A-B;
    if(C!=Wynik_ode)
       { return false; }

    C=A*B;
    if(C!=Wynik_mn)
       { return false; }

    A+=B;
    if(A!=Wynik_dod)
       { return false; }

    if(A==B)
       { return false; }
    else
       { return true; }
}

bool test_4()
{
    Tensor<unsigned int> A(2,2,2);  /* tensor testowy */
    Tensor<unsigned int> B(2,2,2);  /* tensor testowy */
    Tensor<unsigned int> C(2,2,2);  /* pomocniczy tensor testowy */

    Tensor<unsigned int> Wynik_dod(2,2,2); /* tensor zawierajacy poprawny wynik dodawania */
    Tensor<unsigned int> Wynik_mn(2,2,2); /* tensor zawierajacy poprawny wynik mnozenia */
    Tensor<unsigned int> Wynik_ode(2,2,2); /* tensor zawierajacy poprawny wynik odejmowania */

    /* elementy pierwszego tensora */
    unsigned int element_1_1=4, element_2_1=5, element_3_1=3, element_4_1=9;
    unsigned int element_5_1=9, element_6_1=11, element_7_1=2, element_8_1=2;
    /* elementy drugiego tensora */
    unsigned int element_1_2=1, element_2_2=3, element_3_2=1, element_4_2=6;
    unsigned int element_5_2=8, element_6_2=11, element_7_2=1, element_8_2=2;

    A.change(element_1_1 ,1,1,1);
    A.change(element_2_1 ,1,1,2);
    A.change(element_3_1 ,1,2,1);
    A.change(element_4_1 ,1,2,2);
    A.change(element_5_1 ,2,1,1);
    A.change(element_6_1 ,2,1,2);
    A.change(element_7_1 ,2,2,1);
    A.change(element_8_1 ,2,2,2);

    B.change(element_1_2 ,1,1,1);
    B.change(element_2_2 ,1,1,2);
    B.change(element_3_2 ,1,2,1);
    B.change(element_4_2 ,1,2,2);
    B.change(element_5_2 ,2,1,1);
    B.change(element_6_2 ,2,1,2);
    B.change(element_7_2 ,2,2,1);
    B.change(element_8_2 ,2,2,2);

    Wynik_dod.change(element_1_1+element_1_2 ,1,1,1);
    Wynik_dod.change(element_2_1+element_2_2 ,1,1,2);
    Wynik_dod.change(element_3_1+element_3_2 ,1,2,1);
    Wynik_dod.change(element_4_1+element_4_2 ,1,2,2);
    Wynik_dod.change(element_5_1+element_5_2 ,2,1,1);
    Wynik_dod.change(element_6_1+element_6_2 ,2,1,2);
    Wynik_dod.change(element_7_1+element_7_2 ,2,2,1);
    Wynik_dod.change(element_8_1+element_8_2 ,2,2,2);

    Wynik_ode.change(element_1_1-element_1_2 ,1,1,1);
    Wynik_ode.change(element_2_1-element_2_2 ,1,1,2);
    Wynik_ode.change(element_3_1-element_3_2 ,1,2,1);
    Wynik_ode.change(element_4_1-element_4_2 ,1,2,2);
    Wynik_ode.change(element_5_1-element_5_2 ,2,1,1);
    Wynik_ode.change(element_6_1-element_6_2 ,2,1,2);
    Wynik_ode.change(element_7_1-element_7_2 ,2,2,1);
    Wynik_ode.change(element_8_1-element_8_2 ,2,2,2);

    Wynik_mn.change(element_1_1*element_1_2 ,1,1,1);
    Wynik_mn.change(element_2_1*element_2_2 ,1,1,2);
    Wynik_mn.change(element_3_1*element_3_2 ,1,2,1);
    Wynik_mn.change(element_4_1*element_4_2 ,1,2,2);
    Wynik_mn.change(element_5_1*element_5_2 ,2,1,1);
    Wynik_mn.change(element_6_1*element_6_2 ,2,1,2);
    Wynik_mn.change(element_7_1*element_7_2 ,2,2,1);
    Wynik_mn.change(element_8_1*element_8_2 ,2,2,2);

    if(A.show(1,2,2)!=element_4_1)
       { return false; }
    if(B.show(2,1,1)!=element_5_2)
       { return false; }

    C=A+B;
    if(C!=Wynik_dod)
       { return false; }

    C=A-B;
    if(C!=Wynik_ode)
       { return false; }

    C=A*B;
    if(C!=Wynik_mn)
       { return false; }

    A+=B;
    if(A!=Wynik_dod)
       { return false; }

    if(A==B)
       { return false; }
    else
       { return true; }
}


bool test_5()
{
    Tensor<int> A(3,1,1);  /* tensor testowy */
    Tensor<int> B(3,1,1);  /* tensor testowy */
    Tensor<int> C(3,1,1);  /* pomocniczy tensor testowy */

    Tensor<int> Wynik_dod(3,1,1); /* tensor zawierajacy poprawny wynik dodawania */
    Tensor<int> Wynik_mn(3,1,1); /* tensor zawierajacy poprawny wynik mnozenia */
    Tensor<int> Wynik_ode(3,1,1); /* tensor zawierajacy poprawny wynik odejmowania */

    /* elementy pierwszego tensora */
    int element_1_1=3, element_2_1=4, element_3_1=3;
    /* elementy drugiego tensora */
    int element_1_2=1, element_2_2=8, element_3_2=0;

    A.change(element_1_1 ,1,1,1);
    A.change(element_2_1 ,2,1,1);
    A.change(element_3_1 ,3,1,1);

    B.change(element_1_2 ,1,1,1);
    B.change(element_2_2 ,2,1,1);
    B.change(element_3_2 ,3,1,1);

    Wynik_dod.change(element_1_1+element_1_2 ,1,1,1);
    Wynik_dod.change(element_2_1+element_2_2 ,2,1,1);
    Wynik_dod.change(element_3_1+element_3_2 ,3,1,1);

    Wynik_ode.change(element_1_1-element_1_2 ,1,1,1);
    Wynik_ode.change(element_2_1-element_2_2 ,2,1,1);
    Wynik_ode.change(element_3_1-element_3_2 ,3,1,1);

    Wynik_mn.change(element_1_1*element_1_2 ,1,1,1);
    Wynik_mn.change(element_2_1*element_2_2 ,2,1,1);
    Wynik_mn.change(element_3_1*element_3_2 ,3,1,1);

    if(A.show(1,1,1)!=element_1_1)
       { return false; }
    if(B.show(2,1,1)!=element_2_2)
       { return false; }

    C=A+B;
    if(C!=Wynik_dod)
       { return false; }

    C=A-B;
    if(C!=Wynik_ode)
       { return false; }

    C=A*B;
    if(C!=Wynik_mn)
       { return false; }

    A*=B;
    if(A!=Wynik_mn)
       { return false; }

    if(A==B)
       { return false; }
    else
       { return true; }
}

bool test_6()
{
    Tensor<int> A(3,1,1);  /* tensor testowy */
    Tensor<int> B(3,1,1);  /* tensor testowy */
    Tensor<int> C(3,1,1);  /* pomocniczy tensor testowy */

    Tensor<int> Wynik_dod(3,1,1); /* tensor zawierajacy poprawny wynik dodawania */
    Tensor<int> Wynik_mn(3,1,1); /* tensor zawierajacy poprawny wynik mnozenia */
    Tensor<int> Wynik_ode(3,1,1); /* tensor zawierajacy poprawny wynik odejmowania */

    /* elementy pierwszego tensora */
    int element_1_1=2, element_2_1=0, element_3_1=3;
    /* elementy drugiego tensora */
    int element_1_2=2, element_2_2=5, element_3_2=0;

    A.change(element_1_1 ,1,1,1);
    A.change(element_2_1 ,2,1,1);
    A.change(element_3_1 ,3,1,1);

    B.change(element_1_2 ,1,1,1);
    B.change(element_2_2 ,2,1,1);
    B.change(element_3_2 ,3,1,1);

    Wynik_dod.change(element_1_1+element_1_2 ,1,1,1);
    Wynik_dod.change(element_2_1+element_2_2 ,2,1,1);
    Wynik_dod.change(element_3_1+element_3_2 ,3,1,1);

    Wynik_ode.change(element_1_1-element_1_2 ,1,1,1);
    Wynik_ode.change(element_2_1-element_2_2 ,2,1,1);
    Wynik_ode.change(element_3_1-element_3_2 ,3,1,1);

    Wynik_mn.change(element_1_1*element_1_2 ,1,1,1);
    Wynik_mn.change(element_2_1*element_2_2 ,2,1,1);
    Wynik_mn.change(element_3_1*element_3_2 ,3,1,1);

    if(A.show(1,1,1)!=element_1_1)
       { return false; }
    if(B.show(2,1,1)!=element_2_2)
       { return false; }

    C=A+B;
    if(C!=Wynik_dod)
       { return false; }

    C=A-B;
    if(C!=Wynik_ode)
       { return false; }

    C=A*B;
    if(C!=Wynik_mn)
       { return false; }

    A-=B;
    if(A!=Wynik_ode)
       { return false; }

    if(A==B)
       { return false; }
    else
       { return true; }
}

void example()
{
    cout<<"Podaj x y z"<<endl;
    int x,y,z;
    cin>>x>>y>>z;

    cout<<"Podaj elementy tensora intow:"<<endl;
    Tensor<int> A(x,y,z);
    cin>>A;
    cout<<A;

}