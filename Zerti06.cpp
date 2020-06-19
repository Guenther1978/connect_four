/***********************************************************************/
/* Zerti06.cpp: Methoden der Klassen und die Funktion main zum Testen. */
/***********************************************************************/
//#include <iostream>
//using namespace std;

#include <curses.h>
#include <stdlib.h>
#include <time.h>

#include "Zerti06.hpp"


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

/***********************************************************************/
/*                                                                     */
/* Klassen zur Kontrolle                                               */
/*                                                                     */
/***********************************************************************/

Spieler::Spieler(int n, char s, char g, bool m, bool a)
{
  nummer = n;
  spielstein = s;
  spielstein_gegner = g;
  ist_mensch = m;
  darf_anfangen = a;
  siege = 0;
  if (!ist_mensch)
    {
      srand(time(NULL));
    }	    
}

/***********************************************************************/
int Spieler::waehle_spalte(Spielfeld & feld)
{
  int ziffer = -1;
  char taste = ' ';
  if (ist_mensch)
    {
      do
	{
	  taste = getch();
	} while ((taste < '1') || (taste > '7'));
      ziffer = taste - 0x30;
      ziffer --;    // Anpassung Ziffer - Index
    }
  else
    {
      ziffer = suche_spalte(feld, spielstein);
      if (ziffer < 0)
	{
	  ziffer = suche_spalte(feld, spielstein_gegner);
	}
      if (ziffer < 0)
	{
	  ziffer = (rand() % SPALTEN);
	}
      delay();
    } 
  return ziffer;
}

/***********************************************************************/

void Spieler::delay(void)
{
  int l = ((rand() & 7) + 1);
    for (int zufall = l; zufall > 0; zufall --)
    {
      for(unsigned long int k = 100000000; k > 0; k --);
    }
}
/***********************************************************************/

int Spieler::suche_spalte(Spielfeld& sf, char stein)
{
  // Durchsuche senkrecht
  for (int j = SPALTE_LINKS; j <= SPALTE_RECHTS; j ++)
    {
      for (int i = ZEILE_MAX; i >= ZEILE_MIN; i --)
	{
	  if ((sf.feld[i][j] == stein)
	      && (sf.feld[i-1][j] == stein)
	      && (sf.feld[i-2][j] == stein)
	      && (sf.feld[i-3][j] == ' '))
	      {
		return j;
	      }
	}
    }
  
  // Durchsuche waagerecht von links 
  for (int i = ZEILE_MAX; i >= 0; i --)
    {
      for (int j = SPALTE_LINKS; j <= MITTE; j ++)
	{
	  if ((sf.feld[i][j] == stein)
	      && (sf.feld[i][j+1] == stein)
	      && (sf.feld[i][j+2] == stein)
	      && (sf.feld[i][j+3] == ' ')
	      && ((i == (ZEILEN - 1)) || (sf.feld[i+1][j+3] != ' ')))
	      {
		return (j + 3);
	      }
	}
    }

  // Durchsuche waagerecht von rechts
  for (int i = ZEILE_MAX; i >= 0; i --)
    {
      for (int j = SPALTE_RECHTS; j >= MITTE; j --)
	{
	  if ((sf.feld[i][j] == stein)
	      && (sf.feld[i][j-1] == stein)
	      && (sf.feld[i][j-2] == stein)
	      && (sf.feld[i][j-3] == ' ')
	      && ((i = (ZEILEN - 1)) || (sf.feld[i+1][j-3] != ' ')))
	      {
		return (j - 3);
 	      }
	}
    }

  // Durchsuche schraeg von links
  for (int i = ZEILE_MAX; i >= ZEILE_MIN; i --)
    {
      for (int j = SPALTE_LINKS; j <= MITTE; j ++)
	{
	  if ((sf.feld[i][j] == stein)
	      && (sf.feld[i-1][j+1] == stein)
	      && (sf.feld[i-2][j+2] == stein)
	      && (sf.feld[i-3][j+3] == ' ')
	      && ((i = (ZEILEN - 1)) || (sf.feld[i-2][j+3] != ' ')))
	      {
		return  (j + 3);
	      }
	}
    }

  // Durchsuche schraeg von rechts
    for (int i = ZEILE_MAX; i >= ZEILE_MIN; i --)
    {
      for (int j = SPALTE_RECHTS; j >= MITTE; j --)
	{
	  if ((sf.feld[i][j] == stein)
	      && (sf.feld[i-1][j-1] == stein)
	      && (sf.feld[i-2][j-2] == stein)
	      && (sf.feld[i-3][j-3] == ' ')
	      && ((i == (ZEILEN - 1)) || (sf.feld[i-2][j-3] != ' ')))
	      {
		return (j - 3);
	      }
	}
    }

  return  -1;
}

/***********************************************************************/
Spielfeld::Spielfeld(void)
{
  loesche();
}

/***********************************************************************/
void Spielfeld::loesche(void)
{
   for (int i = 0; i < ZEILEN; i ++)
    {
      for (int j = 0; j < SPALTEN; j ++)
	{
	  feld[i][j] = ' ';
	}
    }
}

/***********************************************************************/
int Spielfeld::gebe_zeile(int spalte)
{
  int zeile = ZEILEN - 1;
  while (feld[zeile][spalte] != ' ')
    {
      zeile --;
    }
  return zeile;
}

/***********************************************************************/
bool Spielfeld::vierer_reihe_voll(char stein)
{
  /* Durchsuche senkrecht */
  for (int j = SPALTE_LINKS; j <= SPALTE_RECHTS; j ++)
    {
      for (int i = ZEILE_MAX; i >= ZEILE_MIN; i --)
	{
	  if ((feld[i][j] == stein)
	      && (feld[i-1][j] == stein)
	      && (feld[i-2][j] == stein)
	      && (feld[i-3][j] == stein))
	      {
		return true;
	      }
	}
    }

  /* Durchsuche waagerecht */
  for (int i = ZEILE_MAX; i >= 0; i --)
     {
      for (int j = SPALTE_LINKS; j <= MITTE; j ++)
	{
	  if ((feld[i][j] == stein)
	      && (feld[i][j+1] == stein)
	      && (feld[i][j+2] == stein)
	      && (feld[i][j+3] == stein))
	      {
		return true;
	      }
	}
    }

    /* Durchsuche schraeg von links */
    for (int i = ZEILE_MAX; i >= ZEILE_MIN; i --)
    {
      for (int j = SPALTE_LINKS; j <= MITTE; j ++)
	{
	  if ((feld[i][j] == stein)
	      && (feld[i-1][j+1] == stein)
	      && (feld[i-2][j+2] == stein)
	      && (feld[i-3][j+3] == stein))
	      {
		return true;
	      }
	}
    }

    /* Durchsuche senkrecht von rechts */
  for (int i = ZEILE_MAX; i >= ZEILE_MIN; i --)
    {
      for (int j = SPALTE_RECHTS; j >= MITTE; j --)
	{
	  if ((feld[i][j] == stein)
	      && (feld[i-1][j-1] == stein)
	      && (feld[i-2][j-2] == stein)
	      && (feld[i-3][j-3] == stein))
	      {
		return true;
	      }
	}
    }

      return false;
}
/***********************************************************************/

int main(void)
{
  char weiter = ' ';
  char stein = ' ';
  int nummer = 0;
  int spalte = 0;
  int zeile = 0;
  int spielzug = 0;
  int steine_gesetzt = 0;
  int anzahl_grafik_objekte  = 0;
  int i = 0;
  bool farbig = false;
  
  Spielfeld sf;

  Spieler *SpielerListe[SPIELER];       // Liste auf die Spieler
  Punkt *GrafikObjekte[ELEMENTE];        // Liste auf die Spielfeldelemente
  Punkt *SpielSteine[ZEILEN*SPALTEN];   // max. Anzahl an Spielsteinen
  
  initscr();                            // Initialisiert das Terminal
  cbreak();                             // Zeichen sofort weiterreichen
  noecho();                             // Kein Echo bei getch()
  //echo();                             // Echo bei getch()
  nonl();                               // Keine neue Zeile bei Return
  nodelay(stdscr, FALSE);
  intrflush(stdscr, FALSE);
  keypad(stdscr, TRUE);  // Ziffernblock aktivieren.
  start_color();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);

  SpielerListe[0] = new Spieler(1, 'O', 'X', true, true);
  addstr("Ist Spieler Nummer 2 ebenfalls ein Mensch (j/n)? ");
  if ((getch() | 0x20) == 'j')
    {
        SpielerListe[1] = new Spieler(2, 'X', 'O', true, false);
    }
  else
    {
        SpielerListe[1] = new Spieler(2, 'X', 'O', false, false);
    }
  clear();

  addstr("Moechten Sie farbige Spielsteine? (j/n)? ");
  if ((getch() | 0x20) == 'j')
    {
      farbig = TRUE;
    }
  else
    {
      farbig = FALSE;
    }
  clear();

  GrafikObjekte[0] = new Rechteck(ECKE_X,ECKE_Y,ECKE_X+BREITE,ECKE_Y+HOEHE);
  GrafikObjekte[0]->zeichne();
  for (i = 1; i <= SPALTEN; i ++)
    {
      GrafikObjekte[i] = new Punkt(ECKE_X + 2*i, ECKE_Y + HOEHE + 1);
      GrafikObjekte[i]->zeichne(i + 0x30);
    }

  mvaddstr(MELDUNGEN_Y, MELDUNGEN_X, "Ziffer = Spalte");
  mvaddstr(PUNKTE_1_Y, ECKE_X, "Spieler 1: 0");
  mvaddstr(PUNKTE_2_Y, ECKE_X, "Spieler 2: 0");

  do
    {
      spielzug = 0;
      steine_gesetzt = 0;
      bool vierer_voll = false;
      sf.loesche();
      mvaddstr(MELDUNGEN_Y, MELDUNGEN_X, "                                 ");
      if ((SpielerListe[0]->gebe_darf_anfangen()) == false)
	{
	  spielzug ++;
	}

      do
	{
	  do
	    {
	      if ((spielzug & 0x01) == 0)
		{
		  nummer = SpielerListe[0]->gebe_nummer();
		  stein = SpielerListe[0]->gebe_stein();
        	  mvaddstr(SPIELER_Y, SPIELER_X, "Spieler ");
	          addch(nummer + 0x30);
	          spalte = SpielerListe[0]->waehle_spalte(sf);
	        }
	      else
	        {
		  nummer = SpielerListe[1]->gebe_nummer();
	          stein = SpielerListe[1]->gebe_stein();
        	  mvaddstr(SPIELER_Y, SPIELER_X, "Spieler ");
	          addch(nummer + 0x30);
	          spalte = SpielerListe[1]->waehle_spalte(sf);
	        }
	      if (!sf.spalte_nicht_voll(spalte))
		{
		  mvaddstr(MELDUNGEN_Y, MELDUNGEN_X, "Diese Spalte ist voll.  ");
		}
	      else
		{
		  mvaddstr(MELDUNGEN_Y, MELDUNGEN_X, "                      ");
		}
	    } while (!sf.spalte_nicht_voll(spalte));
	  
          zeile = sf.gebe_zeile(spalte);
	  sf.setze_stein(zeile, spalte, stein);
	  SpielSteine[steine_gesetzt] = new Punkt(ECKE_X+2+spalte*2,ECKE_Y+HOEHE-ZEILEN+0+zeile);

	  if (farbig)
	    {
	      if (nummer == 1)
	      {
	        attron(COLOR_PAIR(1));
	        SpielSteine[steine_gesetzt]->zeichne(stein);
	        attroff(COLOR_PAIR(1));
	      }
	      else
	      {
	        attron(COLOR_PAIR(2));
	        SpielSteine[steine_gesetzt]->zeichne(stein);
	        attroff(COLOR_PAIR(2));
	      }
	    }
	  else
	    {
	      SpielSteine[steine_gesetzt]->zeichne(stein);
	    }
	  move(MELDUNGEN_Y, MELDUNGEN_X);
	  refresh();
	  steine_gesetzt ++;
	  vierer_voll = sf.vierer_reihe_voll(stein);
	  spielzug ++;
        } while((steine_gesetzt < ANZAHL_STEINE) && (vierer_voll == false));

      if (!vierer_voll)
	{
	  mvaddstr(MELDUNGEN_Y, MELDUNGEN_X, "unentschieden           ");
	}
      else
	{
	  mvaddstr(MELDUNGEN_Y, MELDUNGEN_X, "Spieler ");
	  addch(nummer + 0x30);
	  addstr(" hat gewonnen.");
	  if (nummer == 1)
	    {
	      SpielerListe[0]->inkrementiere_siege();
	      SpielerListe[0]->setze_darf_anfangen(false);
	      SpielerListe[1]->setze_darf_anfangen(true);
	      mvprintw(PUNKTE_1_Y, PUNKTE_1_X, "%u", SpielerListe[0]->gebe_siege());
	    }
	  else
	    {
	      SpielerListe[1]->inkrementiere_siege();
	      SpielerListe[0]->setze_darf_anfangen(true);
	      SpielerListe[1]->setze_darf_anfangen(false);
	      mvprintw(PUNKTE_2_Y, PUNKTE_1_X, "%u", SpielerListe[1]->gebe_siege());
	    }
	  }

      getch();
      
      sf.loesche();
      for (i = 0; i < steine_gesetzt; i++)
	{
	  SpielSteine[i]->zeichne(' ');
	}

      for (i = 0; i < steine_gesetzt; i++)
	{
	  delete SpielSteine[i];
	}

      mvaddstr(MELDUNGEN_Y, MELDUNGEN_X, "Beenden mit q, sonst neues Spiel. ");
      
    } while ((getch() | 0x20) != 'q');

  for(i=0; i < SPIELER; i++) 
  {                                         
    delete SpielerListe[i];
  }
  
  for(i=0; i < ELEMENTE; i++)  
  {                                    
    delete GrafikObjekte[i];
  }

  endwin();                         // Normalen Modus wieder herstellen  

  return 0;
}
/*****************************************************************************/
