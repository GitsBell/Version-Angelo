/* 
   Fecha: 23/10/2017
   Enunciado
   Se necesita conocer el camino óptimo para retirar las urnas de los colegios y llevarlas hacia 
   el centro de cómputos. Para el camino óptimo se debe utilizar las distancias entre los distintos 
   colegios,sumadas a la demora, que se calcula con la siguiente ecuación:
   (Número Aleatorio entre 0 y 1) x (Velocidad Promedio del Móvil), que será ingresada al Sistema por
   el Usuario. El camino más óptimo será entregado al conductor de la camioneta en una estructura 
   dinámica que permita obtener cuál es el siguiente colegio por el que debe pasar.
*/

#include <iostream>
#include <random>
#include <conio.h>
#include <array>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

const size_t rutas = 9;
const size_t establecimientos = 9;
long double practicidad = 0;  
long double max = 0; 
double velocidad = 0;                                           // C0 C1 C2 C3 C4 C5 C6 C7 C8    
array< array< double, rutas >, establecimientos > mapaDeRutas = {  0, 1, 1, 0, 0, 0, 0, 0, 0 , 
                                                                   1, 0, 1, 1, 0, 0, 0, 0, 0 ,
                                                                   1, 1, 0, 1, 1, 0, 0, 0, 0 ,
                                                                   0, 1, 1, 0, 1, 1, 0, 0, 0 , 
                                                                   0, 0, 1, 1, 0, 1, 0, 0, 0 , 
                                                                   0, 0, 0, 1, 1, 0, 1, 1, 0 ,
                                                                   0, 0, 0, 0, 0, 1, 0, 1, 1 , 
                                                                   0, 0, 0, 0, 0, 1, 1, 0, 1 ,
                                                                   0, 0, 0, 0, 0, 0, 1, 1, 0  
                                                                };
                                                                

int main()
{
    void caminoOptimo(array< array< double, rutas >, establecimientos> & );
    caminoOptimo( mapaDeRutas );
    getch();
    return 0;
}

void caminoOptimo( array< array< double, rutas >, establecimientos> & m)
{
    void recolectarDatos( array< array< double, rutas >, establecimientos> & );
    recolectarDatos( m );
    void mostrarCaminos( const array< array< double, rutas >, establecimientos> & );
    mostrarCaminos( m );
    //void mejorCamino(); hay que hacer primero la funcion ahi abajo
    //mejorCamino();
    
}


void recolectarDatos( array< array< double, rutas >, establecimientos> & grafo )
{
    cout << "ingrese la velocidad del movil: ";
    cin >> velocidad;
    void almacenarDatos( array< array< double, rutas >, establecimientos> & );
    almacenarDatos( grafo );
}

void almacenarDatos( array< array< double, rutas >, establecimientos> & r)
{
    double distancia = 0;
    default_random_engine motor( static_cast<unsigned int>( time( 0 ) ) );
    uniform_int_distribution< unsigned int > intAleatorio( 0, 1 );
    for ( size_t establecimiento = 0; establecimiento < r.size(); establecimiento++ )
      for( size_t ruta = 0; ruta < r[ ruta ].size(); ruta++ )
      {
          if ( r.at( establecimiento ).at( ruta ) == 1 )
          {
              cout << "ingrese la distancia de C" << establecimiento << " a C" << ruta << ": " ;
              cin >> distancia; 
              r.at( establecimiento ).at( ruta ) = (intAleatorio( motor ) * velocidad) + distancia;
              r.at( ruta ).at( establecimiento ) = r.at( establecimiento ).at( ruta );
          } 
      }
}

void mostrarCaminos( const array< array< double, rutas >, establecimientos> & s)
{
    cout << "\nCaminos posibles con sus practicidad:" << endl;
    for ( size_t establecimiento = 0; establecimiento < s.size(); establecimiento++ )
    {  for( size_t ruta = 0; ruta < s[ ruta ].size(); ruta++ )
       {
           cout << setprecision( 2 ) << fixed << setw( 10 ) << s[establecimiento ][ ruta ] << " "; 
       } 
       cout << endl << endl; 
    }    
}

/* hay que trabajar en esta parte para encontar todavia
void mejorCamino()
{
    for (size_t establecimiento = 0; establecimiento < s.size(); establecimiento++)
    {
        min =  s[establecimiento][0];
        for (size_t ruta = 0; ruta < s[ruta].size(); ruta++)
        {
            if (s[establecimiento][ruta] < min)
            {
                min = s[establecimiento][ruta];
            }
        }
    }
}

*/
