/***********************************************************************/
/* Zerti06.cpp: Methoden der Klassen und die Funktion main zum Testen. */
/***********************************************************************/
//#include <iostream>
//using namespace std;

#include <curses.h>
//#include <stdlib.h>
//#include <time.h>

#include "graphics.hpp"
#include "constants.hpp"


/***********************************************************************/
/* Methoden der Basisklasse                               Punkt        */
/***********************************************************************/
Punkt::Punkt()                                // Konstruktor fuer Objekte 
{                                             // der Klasse 'Punkt'
  x = 19;
  y = 9;
}

Punkt::Punkt(int x1, int y1)                  // Konstruktor fuer Objekte 
{                                             // der Klasse 'Punkt'
  x = x1;
  y = y1;
}

void Punkt::zeichne(void)                     // Methode zur
{                                             // Ausgabe eines Punktes
  mvaddch(y,x,'*');
}

void Punkt::zeichne(char z)                   // Methode zur
{                                             // Ausgabe eines Punktes
  mvaddch(y,x,z);
}
/***********************************************************************/


/***********************************************************************/
/* Methoden der Klasse                                   Linie         */
/***********************************************************************/
Linie::Linie():Punkt(14,10)
{
  x2 = 14;
  y2 = 13;

}
Linie::Linie(int x1, int y1, int xx2, int yy2):Punkt(x1,y1)
{
  x2 = xx2;                                  // Konstruktor fuer Objekte 
  y2 = yy2;                                  // der Klasse 'Linie'
}

void Linie::zeichne(void)                    // Methode zur 
{                                            // Ausgabe einer Linie
  int x  = GetX(),
      y  = GetY();
  int i;
  char zeichen;

  if(x != x2 && y != y2 )
  {
    move(1,1);
    printw("Ausgeben der Linie nicht moeglich!");
  }
  else
  {
  if( x == x2 )
    for (i=y+1; i<=y2; i++)                   // eine senkrechte Linie
    {
      mvaddch(i,x,VERT);
    }
  else
    for (i=x; i<=x2; i++)                     // eine waagerechte Linie
    {
      mvaddch(y,i,HORIZ);
    }
  }
}
/***********************************************************************/
/* Methoden der Klasse                                   Rechteck      */
/***********************************************************************/
Rechteck::Rechteck():Linie(3,4,5,6)
{
}

Rechteck::Rechteck(int x1, int y1, int x4, int y4):Linie(x1,y1,x4,y4)
{
}

void Rechteck::zeichne(void)             // Methode zur
{                                        // Ausgabe eines Rechtecks
  int x  = GetX(),
      y  = GetY(),
      x2 = GetX2(),
      y2 = GetY2();
  int i;
  mvaddch(y,x,LINKS_OBEN);
  
  for (i=x+1; i<x2; i++)                 // die obere Linie des Rechtecks
  {
    mvaddch(y,i,HORIZ);
  } 
  mvaddch(y,x2,RECHTS_OBEN);
                   
  for (i=y+1; i<y2; i++)                 // Die senkrechten Linien
  {
    mvaddch(i,x,VERT);
    mvaddch(i,x2,VERT);
  }
  mvaddch(y2,x,LINKS_UNT);
  
  for (i=x+1; i<x2; i++)                 // Die untere Linie
  {
    mvaddch(y2,i,HORIZ);
  }
  mvaddch(y2,x2,RECHTS_UNT);
}
/***********************************************************************/
