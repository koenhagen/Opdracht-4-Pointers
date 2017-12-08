#include "gg.h"
#include <iostream>

using namespace std;

// functie voor tien tot de macht k (grootte van bootjes)
int tienMacht( int k ) {
   int getal = 1;
   for ( int i = 0; i < k; i++ ) {
      getal = getal * 10;
   } // for
   return getal;
} // tienMacht

//tellen uit hoeveel cijfers het bootje bestaat
int cijferTeller( int getal ) {
   int cijferTeller = 0;
   while ( getal != 0 ) {
      getal /= 10;
      cijferTeller++;
	} // while
   return cijferTeller;
} // cijferTeller

//constructor
gg::gg( ) {
  ingang = NULL;
  uitgang = NULL;
  verschuiving = 0;
  toevElement = 0;
  delElement = 0;
  aantalBoten = 0;
} // gg::gg

//destructor
gg::~gg( ) {
	verwijderen( );
} // gg::~gg

// print groot getal met juiste aantal nullen en aantal boten
void gg::print( ) {
   int bootTeller = 0;
   element* hulp = ingang;
   if ( hulp == NULL ) {
      cout << "NULL";
   } // if
   while ( hulp != NULL ) {
      bootTeller = cijferTeller( hulp->info );
      if ( bootTeller < k && hulp->vorige != NULL ) {
         for ( int i = k; i > bootTeller; i-- ) {
            cout << "0";
         } // for
      } // if
      if ( hulp->info > 0 ) {
      	cout << hulp->info << " ";
      } else {
         cout << " ";
      } // if/else
      hulp = hulp->volgende;
   } // while
   cout << " (" << aantalBoten << ")" << endl;
} //gg::print

// voeg een bootje voor aan het grote getal.
void gg::voegVoor(int getal) {
      element* eenVakje;
      eenVakje = new element;
      toevElement++;

      if ( ingang == NULL ) {
         uitgang = eenVakje;
      } else {
         ingang->vorige = eenVakje;
      } // if/else

      eenVakje->vorige = NULL;
      eenVakje->volgende = ingang;
      eenVakje->info = getal;
      ingang = eenVakje;
      aantalBoten++;
} // gg::voegVoor

// voeg een bootje achter aan het grote getal
void gg::voegAchter( int getal ) {
      element* eenVakje;
      eenVakje = new element;
      toevElement++;

      if ( uitgang == NULL ) {
         ingang = eenVakje;
      } else {
         uitgang->volgende = eenVakje;
      } // if/else

      eenVakje->vorige = uitgang;
      eenVakje->volgende = NULL;
      eenVakje->info = getal;
      uitgang = eenVakje;
      aantalBoten++;
}// gg::voegAchter

// door de gebruiker gegeven getal inlezen en per k toevoegen aan grote getal
// enters en niet-getallen negeren
void gg::leesGetal( ) {
   bool nulOntwijker = false;
   char vorigeKeuze = '\n';
   char keuze = '\n';
 	int getal = 0;
 	int teller = 0;
 	verwijderen( );
   while ( vorigeKeuze == '\n' || keuze != '\n' ) {
      vorigeKeuze = keuze;
      cin.get( keuze );
      if ( keuze >= '0' && keuze <= '9' ) {
         getal = ( getal * 10 ) + ( keuze - '0' );
         teller++;
         if ( getal > 0 ) {
            nulOntwijker = true;
         } // if
      } // if
      if ( teller == k && nulOntwijker ) {
         voegAchter( getal );
         teller = 0;
         getal = 0;
      } // if
   } // while
   if ( teller > 0 && nulOntwijker ) {
   	verschuiving = k - teller;
      voegAchter( getal );
   } // if
   hevelen( );
} // gg::leesGetal

// grote getal hevelen zodat eerste bootje het aantal cijfers laatste bootje wordt
void gg::hevelen( ) {
   int d;
   int r = 0;
   int bootje;
   int bootVerschuiving;
   int bootDeler;
   if ( verschuiving > 0 ) {
      bootVerschuiving = tienMacht( verschuiving );
   	bootDeler = tienMacht( k - verschuiving );

   	element* hulp = ingang;
   	while ( hulp != NULL ) {
         bootje = hulp->info;
         d = bootje / bootVerschuiving;
         //cout << d << endl << bootje << endl << bootVerschuiving << endl << r << endl;
         if ( hulp->volgende == NULL ) {
         	hulp->info = ( r * bootDeler ) + bootje; //
         } else {
         	hulp->info = ( r * bootDeler ) + d;
         } // if/else
         r = bootje % bootVerschuiving;
         hulp = hulp->volgende;
      } // while
   } // if
} // gg::hevelen

// twee grote getallen optellen
void gg::telop( gg& A, gg& B ) {
	int C;
	int hulpC = 0;
	element* hulpA = A.uitgang;
	element* hulpB = B.uitgang;
	element* overig;
   verwijderen( );
	while ( hulpA != NULL && hulpB != NULL ) {

		C = hulpA->info + hulpB->info + hulpC;

		hulpC = C / tienMacht( k );
      C = C % tienMacht( k );


		hulpA = hulpA->vorige;
		hulpB = hulpB->vorige;

		//cout << hulpC << endl << C << endl;
		voegVoor( C );
	} // while
	if ( hulpA == NULL ) {
		overig = hulpB;
	} else {
		overig = hulpA;
	} // if/else
	while ( overig != NULL ) {
		C = overig->info + hulpC;

      hulpC = C / tienMacht( k );
      C = C % tienMacht( k );

		voegVoor( C );

		overig = overig->vorige;
	} // while
	if ( hulpC > 0 ) {
      voegVoor( hulpC );
	} // if
} // gg::telop

// groot getal leegmaken door alle bootjes te deleten
void gg::verwijderen( ) {
   if ( ingang != NULL ) {
      ingang = ingang->volgende;
      while ( ingang != NULL ) {
         delete ingang->vorige;
         delElement++;
         ingang = ingang->volgende;
      } // while
      delete uitgang;
      delElement++;
      uitgang = NULL;
      aantalBoten = 0;
   } // if
} // gg::verwijderen

// de n'ste fibonacci getal uitrekenen
void gg::fibonacci( int n ) {
   gg eerste;
   gg hulp;
   eerste.maakeen( );
   maakeen( );
   if ( n ==  0 ) {
   	verwijderen( );
   } else {
		for ( int teller = 3; teller <= n; teller++ ) {
		   hulp.kopieer( *this );
		   telop( eerste, hulp );
		   eerste.kopieer( hulp );
		} // for
	} // if/else
} // gg:fibonacci

// doorgegeven grote getal (gg A) kopi�ren naar aangeroepen grote getal
void gg::kopieer( gg& A ) {
   verwijderen( );               // grote getal gereed voor kopieren maken (leeg)
   element* hulp = A.ingang;     // vanaf ingang van gg A
   while ( hulp != NULL ) {      // loopen tot einde
      voegAchter( hulp->info );  // elk bootje van A achter grote getal voegen
      hulp = hulp->volgende;
   } // while
} // gg::kopieer

// groot getal leegmaken en bootje van een toevoegen
void gg::maakeen( ) {
   verwijderen( );
   voegAchter( 1 );
} // gg::maakeen

// groot getal leegmaken, m aantal boten met nul toevoegen
void gg::maakNullen( int m ) {
   verwijderen( );
   for ( int teller = 0; teller < m; teller++ ) {
      voegAchter( 0 );
   } // for
} // gg::maakNullen

// twee grote getallen met elkaar vermenigvuldigen
void gg::vermenigvuldig( gg& A, gg& B ) {
   gg C;
   gg hulpC;
   gg temp;
   long long rekenC;
	int rest = 0;
	int maakNullenTeller = 0;
   element* hulpB = B.uitgang;
   while ( hulpB != NULL ) {
      element* hulpA = A.uitgang;
      hulpC.maakNullen( maakNullenTeller );
      while ( hulpA != NULL ) {
         rekenC = (long long) hulpA->info * hulpB->info + rest;

         rest = rekenC / tienMacht( k );
         rekenC = rekenC % tienMacht( k );

         //cout << rest << endl << rekenC << endl << endl;
         hulpC.voegVoor( rekenC );
         hulpA = hulpA->vorige;

      } // while
      if ( rest > 0 ) {
         hulpC.voegVoor( rest );
      } // if
      rest = 0;
      temp.kopieer( C );
      C.telop( temp, hulpC );
      maakNullenTeller++;
      hulpB = hulpB->vorige;
   } // while
   kopieer( C );
} // gg::vermenigvulig
