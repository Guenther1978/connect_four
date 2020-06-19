/***********************************************************************/
/* Zerti06.hpp: Headerdatei mit Konstanten und Klassendeklarationen    */
/***********************************************************************/

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

/***********************************************************************/
/* Klassen zum Zeichnen                                                */
/***********************************************************************/

/*---------------------------- Basisklasse ----------------------------*/
class Punkt                                             // Klasse 'Punkt'
{
private:
  int x;
  int y;
public:
  Punkt();
  Punkt(int x, int y);
  int GetX(void){return x; };                                  // Inline
  int GetY(void){return y; };
  virtual void zeichne(void);
  void zeichne(char);
};
/*---------  von Punkt abgeleitete Klasse - Vererbung -----------------*/

class Linie : public Punkt               // Klasse 'Linie', abgeleitet '
{                                        // von Klasse 'Punkt
private:
  int x2;
  int y2;
public:
  Linie();
  Linie(int x1, int y1, int x2, int y2);
  int GetX2(void){return x2; };              // Inline
  int GetY2(void){return y2; };
  void zeichne(void);
};
/*---------  von Linie abgeleitete Klasse - Vererbung -----------------*/

class Rechteck : public Linie           // Klasse 'Rechteck', abgeleitet 
{                                       // von Klasse  'Linie'
private:
public:
  Rechteck();
  Rechteck(int x1, int y1, int x4, int y4);
  void zeichne(void);
};

/***********************************************************************/
/* Klassen zur Realisierung des Spieles                                */
/***********************************************************************/
class Spielfeld;    // Vorwaertsdeklaration

/***********************************************************************/
class Spieler
{
private:
  int nummer;
  char spielstein;
  char spielstein_gegner;
  bool ist_mensch;
  bool darf_anfangen;
  int siege;
public:
  Spieler(int, char, char, bool, bool);
  int gebe_nummer(void)            {return nummer;};
  char gebe_stein(void)            {return spielstein;};
  char gebe_stein_gegener(void)    {return spielstein_gegner;};
  int gebe_siege(void)             {return siege;};
  bool gebe_darf_anfangen(void)    {return darf_anfangen;};
  bool gebe_ist_mensch(void)       {return ist_mensch;};
  void inkrementiere_siege(void)   {siege ++;};
  void setze_darf_anfangen(bool a) {darf_anfangen = a;};
  int waehle_spalte(Spielfeld&);
  int suche_spalte(Spielfeld&, char);
  void delay();
};  

/***********************************************************************/
class Spielfeld
{
private:
  char feld[ZEILEN][SPALTEN];
  int anzahl_steine;
public:
  Spielfeld(void);
  friend class Spieler;
  bool vierer_reihe_voll(char);
  void loesche(void);
  bool spalte_nicht_voll(int s)    {return (feld[0][s] == ' ');};
  int gebe_zeile(int);
  void setze_stein(int z, int s, char c)    {feld[z][s] = c;};
};
