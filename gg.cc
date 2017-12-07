#include "gg.h"
#include <iostream>

using namespace std;
// implementatie van
// prototypes uit
// gg.h

int machtTien( int k ) {
   int getal = 1;
   for ( int i = 0; i < k; i++ ) {
      getal = getal * 10;
   }
   return getal;
}
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
  verschuiving = 0;
  toevElement = 0;
  delElement = 0;
  aantalBoten = 0;
} //gg::gg

//const int gg::aantalBoten = 0;

// druk lijst met ingang als ingang af
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
      aantalBoten++;
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
      aantalBoten++;
}//gg::bouwlijst

// door de gebruiker gegeven getal inlezen tot maximaal 1000
// enters en niet-getallen negeren
void gg::leesGetal( ) {
   bool nulOntwijker = false;
   char vorigeKeuze = '\n';
   char keuze = '\n';
 	int getal = 0;
 	int teller = 0;
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
         teller = 0;
         getal = 0;
      } // if
   } // while
   if ( teller > 0 ) {
   	verschuiving = k - teller;
      voegAchter( getal );
   } // if
   hevelen( );
} // gg::leesGetal

void gg::hevelen( ) {
   int d;
   int r = 0;
   int bootje;
   int bootVerschuiving;
   int bootDeler;
   if ( verschuiving > 0 ) {
      bootVerschuiving = machtTien( verschuiving );
   	bootDeler = machtTien( k - verschuiving );

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

void gg::telop( gg A, gg B ) {
	int C;
	int hulpC = 0;
	element* hulpA = A.uitgang;
	element* hulpB = B.uitgang;
	element* overig;
   verwijderen( );
	while ( hulpA != NULL && hulpB != NULL ) {

		C = hulpA->info + hulpB->info + hulpC;

		hulpC = C / machtTien( k );
      C = C % machtTien( k );


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

		hulpC = machtTien( k );
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
      aantalBoten = 0;
   } // if
} // gg::verwijderen

void gg::fibonacci( int n ) {
   gg eerste;
   gg tweede;
   gg hulp;
   eerste.maakeen( );
   tweede.maakeen( );
   for ( int teller = 3; teller <= n; teller++ ) {
      hulp.kopieer( tweede );
      tweede.telop( eerste, hulp );
      eerste.kopieer( hulp );
   }
   kopieer ( tweede );
   eerste.verwijderen( );
   tweede.verwijderen( );
   hulp.verwijderen( );
}

// doorgegeven grote getal (gg A) kopiëren naar aangeroepen grote getal
void gg::kopieer( gg A ) {
   verwijderen( );               // grote getal gereed voor kopieren maken (leeg)
   element* hulp = A.ingang;     // vanaf ingang van gg A
   while ( hulp != NULL ) {      // loopen tot einde
      voegAchter( hulp->info );  // elk bootje van A achter grote getal voegen
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

//int gg::getAantalBoten( ) {
   //return aantalBoten;
//}

void gg::vermenigvuldig( gg A, gg B ) {
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
         cout << hulpA->info << endl;
         cout << hulpB->info << endl;
			cout << rekenC << endl;
         rest = rekenC / machtTien( k );
         rekenC = rekenC % machtTien( k );

         cout << rest << endl << rekenC << endl << endl;
         hulpC.voegVoor( rekenC );
         hulpA = hulpA->vorige;

      }
      if ( rest > 0 ) {
         hulpC.voegVoor( rest );
      }
      rest = 0;
      temp.kopieer( C );
      C.telop( temp, hulpC );
      maakNullenTeller++;
      hulpB = hulpB->vorige;
   }
   kopieer ( C );
}
