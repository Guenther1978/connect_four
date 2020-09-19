#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

/*----- Konstanten zum Zeichnen von Rechtecken und Linien -------------*/
#define LINKS_OBEN  ACS_ULCORNER     // Zeichen zum Malen der Linien und
#define RECHTS_OBEN ACS_URCORNER     // Rechtecke. Die Zeichen sind in 
#define HORIZ       ACS_HLINE        // der Headerdatei 'ncurses.h'
#define VERT        ACS_VLINE        // vordefiniert. Es handelt sich um
#define LINKS_UNT   ACS_LLCORNER     // senkrechte und waagerechte Linie
#define RECHTS_UNT  ACS_LRCORNER     // sowie um die vier Ecken eines
                                     // Rechtecks
/*----- Konstanten des Spieles ----------------------------------------*/
#define ZEILEN        6
#define SPALTEN       7
#define SPIELER       2
#define ELEMENTE      8
#define ANZAHL_STEINE ZEILEN*SPALTEN

/*----- Konstanten zur Textausgabe ------------------------------------*/
#define ECKE_X        30
#define ECKE_Y        10
#define BREITE        2*SPALTEN+2
#define HOEHE         ZEILEN+1
#define SPIELER_Y     ECKE_Y+HOEHE+3
#define SPIELER_X     ECKE_X
#define MELDUNGEN_Y   ECKE_Y+HOEHE+4
#define MELDUNGEN_X   ECKE_X
#define PUNKTE_1_Y    ECKE_Y+HOEHE+6
#define PUNKTE_1_X    ECKE_X+11
#define PUNKTE_2_Y    ECKE_Y+HOEHE+7
#define PUNKTE_2_X    ECKE_X+11

/*----- Aufbau des Spielfeldes ----------------------------------------*/
/*   _______________
    0|_|_|_|_|_|_|_|
    1|_|_|_|_|_|_|_|
    2|_|_|_|_|_|_|_|
    3|_|_|_|_|_|_|_|
    4|_|_|_|_|_|_|_|
    5|_|_|_|_|_|_|_|
      0 1 2 3 4 5 6
/*---------------------------------------------------------------------*/

/*----- Konstanten zur Ueberprufung des Spielfeldinhaltes -------------*/
#define ZEILE_MAX     5
#define ZEILE_MIN     3
#define MITTE         3
#define SPALTE_LINKS  0
#define SPALTE_RECHTS 6

#endif
