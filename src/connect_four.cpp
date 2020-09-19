/**
 * @file
 * @brief The connect 4 game
 *
 * This is the connect 4 game, programmed for a Linux terminal.
 */

#include <curses.h>

#include "graphics.hpp"
#include "player.hpp"
#include "playing_field.hpp"

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

  endwin();                         // Back to normal mode

  
  return 0;
}
