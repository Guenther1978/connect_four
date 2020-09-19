#include "constants.hpp"
#include "playing_field.hpp"


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
