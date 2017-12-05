#include "gg.h"
#include <iostream>
#include <math.h>

using namespace std;
// implementatie van
// prototypes uit
// gg.h

int cijferTeller( int getal ) {
   int cijferTeller = 0;
   while ( getal != 0 ) {
      getal /= 10;
      cijferTeller++;
	}
   return cijferTeller;
} //gg::cijferTeller

//constructor
gg::gg( ) {
  ingang = NULL;
  uitgang = NULL;
  k = 4;
  verschuiving = 0;
  toevElement = 0;
  delElement = 0;
  aantalBoten = 0;
} //gg::gg

//const int gg::aantalBoten = 0;

// druk lijst met ingang als ingang af
void gg::print( ) {
   cout << "Lijst afdrukken van voor naar achter..." << endl;
   int bootTeller = 0;
   element* hulp = ingang;
   if ( hulp == NULL ) {
      cout << "NULL";
      aantalBoten = 0;
   }
   while ( hulp != NULL ) {
      bootTeller = cijferTeller( hulp->info );
      if ( bootTeller < k && hulp->vorige != NULL ) {
         for ( int i = 4; i > bootTeller; i-- ) {
            cout << "0";
         } // for
      } // if
      if ( hulp->info > 0 ) {
      	cout << hulp->info << " ";
      } else {
         cout << " ";
      } // if/else
      hulp = hulp->volgende;
   } //while
   cout << " (" << aantalBoten << ")" << endl;
} //gg::print

// voeg een bootje voor aan de lijsto.
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
      //bufferSchoonmaken( buffer );
} //gg::voegVoor

// voeg een bootje achter aan de lijsto.
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
}//gg::bouwlijst

// door de gebruiker gegeven getal inlezen tot maximaal 1000
// enters en niet-getallen negeren
void gg::leesGetal( ) {
   bool nulOntwijker = false;
   char vorigeKeuze = '\n';
   char keuze = '\n';
 	int getal = 0;
 	int teller = 0;
 	aantalBoten = 0;
 	verwijderen( );
 	cout << "welke info erin? ";
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
         aantalBoten++;
         teller = 0;
         getal = 0;
      } // if
   } // while
   if ( teller > 0 ) {
   	verschuiving = k - teller;
      voegAchter( getal );
      aantalBoten++;
   } // if
   hevelen( );
} // gg::leesGetal

void gg::hevelen( ) {
   int d;
   int r = 0;
   int bootje;
   double bootVerschuiving;
   double bootDeler;
   if ( verschuiving > 0 ) {
   	bootVerschuiving = pow( 10, verschuiving );
   	bootDeler = pow( 10, k - verschuiving );
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
         r = fmod( bootje, bootVerschuiving );
         hulp = hulp->volgende;
      } // while
   } // if
} // gg::hevelen

void gg::telop( gg A, gg B ) {
	int C;
	int hulpC = 0;
	double kMacht;
	element* hulpA = A.uitgang;
	element* hulpB = B.uitgang;
	element* overig;
   verwijderen( );
	while ( hulpA != NULL && hulpB != NULL ) {

		C = hulpA->info + hulpB->info + hulpC;

		kMacht = pow( 10, k );
		hulpC = C / kMacht;
		C = fmod( C, kMacht );


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

		hulpC = pow( 10, k );
		C = C % hulpC;
		hulpC = C / hulpC;

		//cout << hulpC << endl << C << endl;
		voegVoor( C );

		overig = overig->vorige;
	} // while
	if ( hulpC > 0 ) {
      voegVoor( hulpC );
	} // if
} // gg::telop

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
   } // if
} // gg::verwijderen

void gg::fibonacci( int n, gg& A ) {
   gg eerste;
   gg hulp;
   eerste.maakeen( );
   maakeen( );
   for ( int teller = 3; teller <= n; teller++ ) {
      kopieer( hulp, A );
      telop( eerste, hulp );
      kopieer( eerste, hulp );
   }
   eerste.verwijderen( );
   hulp.verwijderen( );
}

void gg::kopieer( gg& A, gg B ) {
   A.verwijderen( );
   element* hulp = B.ingang;
   while ( hulp != NULL ) {
      A.voegAchter( hulp->info );
      hulp = hulp->volgende;
   }
}

void gg::maakeen( ) {
   verwijderen( );
   voegAchter( 1 );
}

void gg::maakNullen( int m ) {
   verwijderen( );
      for ( int teller = 0; teller < m; teller++ ) {
         voegAchter( 0 );
      }
}

int gg::getAantalBoten( ) {
   return aantalBoten;
}

void gg::vermenigvuldig( gg A, gg B, gg& C ) {
   gg hulpC;
   gg temp;
   int rekenC;
	int rest = 0;
	double kMacht;
	int maakNullenTeller = 0;
   int limiet = B.getAantalBoten( );
   element* hulpB = B.uitgang;
   for ( int i = 1; i <= limiet; i++ ) {
      element* hulpA = A.uitgang;
      hulpC.maakNullen( maakNullenTeller );
      while ( hulpA != NULL ) {
         rekenC = hulpA->info * hulpB->info + rest;

         kMacht = pow( 10, k );
         rest = rekenC / kMacht;
         rekenC = fmod( rekenC, kMacht );

         //cout << rest << endl << rekenC << endl << endl;
         hulpC.voegVoor( rekenC );
         hulpA = hulpA->vorige;

      }
      hulpC.voegVoor ( rest );
      rest = 0;
      kopieer( temp, C );
      telop( temp, hulpC );
      maakNullenTeller++;
      hulpB = hulpB->vorige;
   }

   //verwijderen ( );
}
