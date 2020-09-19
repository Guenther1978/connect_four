#include <curses.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

#include "constants.hpp"
#include "player.hpp"
#include "playing_field.hpp"

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
