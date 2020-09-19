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

