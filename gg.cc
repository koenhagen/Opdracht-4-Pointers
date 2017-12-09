#include "gg.h"
#include <iostream>

using namespace std;

// tien tot de macht k (grootte van bootjes) berekenen
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
  ingang = NULL;		// begin van pointer lijst
  uitgang = NULL;		// eind van pointer lijst
  verschuiving = 0;	// aantal cijfers buiten een volledig bootje
  delElement = 0;		// aantal keer dat er een element is verwijderd
  aantalBoten = 0;
} // gg::gg

// destructor
gg::~gg( ) {
	verwijderen( );
} // gg::~gg

// print groot getal met juiste aantal nullen en aantal bootjes
void gg::print( ) {
   int bootTeller = 0;				// aantal cijfers in bootje
   element* hulp = ingang;
   if ( hulp == NULL ) {			// als leeg groot getal
      cout << "NULL";
   } // if
   
   // loopen door groot getal tot laatste bootje
   while ( hulp != NULL ) {		
      bootTeller = cijferTeller( hulp->info ); // aantal cijfers boot tellen
      // als er nullen nodig zijn benodigde nullen naar scherm schrijven
      // niet bij eerste boot in groot getal
      if ( bootTeller < k && hulp->vorige != NULL ) {
         for ( int i = k; i > bootTeller; i-- ) {
            cout << "0";
         } // for
      } // if
      
      // zorgen dat er niet extra nul naar scherm wordt geschreven
      if ( hulp->info > 0 ) {
      	cout << hulp->info << " ";
      } else {
         cout << " ";
      } // if/else
      // naar volgende boot
      hulp = hulp->volgende;
   } // while
   cout << " (" << aantalBoten << ")" << endl; 
} // gg::print

// voeg een bootje voor aan het grote getal
void gg::voegVoor(int getal) {
   element* bootje;
   bootje = new element;
   toevElement++;
	// als eerste bootje, ingang en uitgang aan bootje koppelen
   if ( ingang == NULL ) {
      uitgang = bootje;
   // anders vooraan toevoegen
   } else {
      ingang->vorige = bootje;
   } // if/else
   // bootje aan lijst koppelen
   bootje->vorige = NULL;
   bootje->volgende = ingang;
   bootje->info = getal;
   ingang = bootje;
   aantalBoten++;
} // gg::voegVoor

// voeg een bootje achter aan het grote getal
void gg::voegAchter( int getal ) {
   element* bootje;
   bootje = new element;
   toevElement++;
   // als eerste bootje, ingang en uitgang aan bootje koppelen
   if ( uitgang == NULL ) {
      ingang = bootje;
      // anders achteraan toevoegen
   } else {
      uitgang->volgende = bootje;
   } // if/else
   // bootje aan lijst koppelen
   bootje->vorige = uitgang;
   bootje->volgende = NULL;
   bootje->info = getal;
   uitgang = bootje;
   aantalBoten++;
}// gg::voegAchter

// door de gebruiker gegeven getal inlezen en per k bootje achteraan voegen
// enters en niet-getallen negeren
void gg::leesGetal( ) {
   bool nulOntwijker = false;		// voor nullen  aan begin van inlezen negeren
   char vorigeKeuze = '\n';		// voor enters negeren en alle getallen inlezen
   char keuze = '\n';				// zie vorigeKeuze
 	int getal = 0;						// van ingevoerde karakters getal maken
 	int teller = 0;					// houdt bij uit hoeveel cijfers getal bestaat
 	verwijderen( );					// groot getal leegmaken
 	// door alle ingevoerde getallen loopen en toevoegen aan groot getal
   while ( vorigeKeuze == '\n' || keuze != '\n' ) {
      vorigeKeuze = keuze;
      cin.get( keuze );
      if ( keuze >= '0' && keuze <= '9' ) {
         getal = ( getal * 10 ) + ( keuze - '0' );
         teller++;
         // nullen aan begin negeren, daarna niet meer
         if ( getal > 0 && !nulOntwijker ) {
      		teller = 0;		
            nulOntwijker = true;
         } // if
      } // if
      // getal per k (bootje) toevoegen aan groot getal 
      if ( teller == k && nulOntwijker ) {
         voegAchter( getal );
         // resetten voor volgend bootje
         teller = 0;
         getal = 0;
      } // if
   } // while
   // aan het einde, bootje kleiner dan k toevoegen
   if ( teller > 0 && nulOntwijker ) {
   	verschuiving = k - teller; // verschuiving onthouden voor hevelen
      voegAchter( getal );
   } // if
   hevelen( );
} // gg::leesGetal

// grote getal hevelen zodat eerste bootje het aantal cijfers laatste bootje wordt
void gg::hevelen( ) {
   int bootje;				// houdt de info van het element (getal van grootte k)
   int bootVerschuiving;// hoeveel cijers van bootje afgehakt moet worden (voor d)
   int bootDeler;			// hoeveel cijfers er verschoven moet worden (voor r)
   int d;					// getal dat blijft staan in bootje
   int r = 0;				// getal dat naar het volgende bootje moet 
   // alleen doen als er verschoven moet worden
   if ( verschuiving > 0 ) { 
      bootVerschuiving = tienMacht( verschuiving );
   	bootDeler = tienMacht( k - verschuiving );
   	element* hulp = ingang;
   	// loopen door te hevelen grote getal
   	while ( hulp != NULL ) {
         bootje = hulp->info;
         d = bootje / bootVerschuiving;
         // bij laatste bootje overige cijfers 
         if ( hulp->volgende == NULL ) {
         	hulp->info = ( r * bootDeler ) + bootje;
         // te verschuiven cijfers vooraan de blijvende cijfers voegen
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
	element* hulpA = A.uitgang;
	element* hulpB = B.uitgang;
	element* overig;
	int C;			// getal voor bootje na optellen
	int hulpC = 0;	// getal dat wordt doorgegeven aan volgende bootje
   verwijderen( );
   // loopen tot einde van een groot getal. 
   // bootjes gg A en gg B en rest (hulpC) optellen
	while ( hulpA != NULL && hulpB != NULL ) {
		C = hulpA->info + hulpB->info + hulpC;
		hulpC = C / tienMacht( k );
      C = C % tienMacht( k );
		hulpA = hulpA->vorige;
		hulpB = hulpB->vorige;
		voegVoor( C );
	} // while
	// als een groot getal groter is dan de andere, 
	// aanwijzen voor volgende loop (overig)
	if ( hulpA == NULL ) {
		overig = hulpB;
	} else {
		overig = hulpA;
	} // if/else
	// door blijven tellen met overig
	while ( overig != NULL ) {
		C = overig->info + hulpC;
      hulpC = C / tienMacht( k );
      C = C % tienMacht( k );
		voegVoor( C );
		overig = overig->vorige;
	} // while
	// rest afhandelen
	if ( hulpC > 0 ) {
      voegVoor( hulpC );
	} // if
} // gg::telop

// groot getal leegmaken door alle bootjes te deleten
void gg::verwijderen( ) {
	// niet nodig voor leeg getal
   if ( ingang != NULL ) {
      ingang = ingang->volgende;
      // vorige element verwijderen en ingang opschuiven
      while ( ingang != NULL ) {
         delete ingang->vorige;
         delElement++;
         ingang = ingang->volgende;
      } // while
 		// uitgang verwijderen en op NULL zetten, variabelen resetten
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
   // eerste twee fibonacci getallen klaarzetten
   eerste.maakEen( );
   maakEen( );
   // fibonacci getal van 0 op NULL zetten
   if ( n ==  0 ) {
   	verwijderen( );
   } else {
   	// loopen tot ingevoerde getal. Fibonacci getal berekenen
		for ( int teller = 3; teller <= n; teller++ ) {
		   hulp.kopieer( *this );
		   telop( eerste, hulp );
		   eerste.kopieer( hulp );
		} // for
	} // if/else
} // gg:fibonacci

// doorgegeven grote getal (gg A) kopiëren naar aangeroepen grote getal
void gg::kopieer( gg& A ) {
   verwijderen( );               // grote getal gereed voor kopieren maken (leeg)
   element* hulp = A.ingang;     // vanaf ingang van gg A
   while ( hulp != NULL ) {      // loopen tot einde
      voegAchter( hulp->info );  // elk bootje van A achter grote getal voegen
      hulp = hulp->volgende;
   } // while
} // gg::kopieer

// groot getal leegmaken en bootje van een toevoegen
void gg::maakEen( ) {
   verwijderen( );
   voegAchter( 1 );
} // gg::maakEen

// groot getal leegmaken, m aantal boten met nul toevoegen
void gg::maakNullen( int m ) {
   verwijderen( );
   for ( int teller = 0; teller < m; teller++ ) {
      voegAchter( 0 );
   } // for
} // gg::maakNullen

// twee grote getallen met elkaar vermenigvuldigen
void gg::vermenigvuldig( gg& A, gg& B ) {
   gg hulpC;
   gg temp;
   long long rekenC;	// getal voor bootje na vermenigvuldiging
	int rest = 0;		// getal dat wordt doorgegeven aan volgende bootje
	int maakNullenTeller = 0;	// bijhouden hoeveel nullen nodig
   element* hulpB = B.uitgang;
   verwijderen( );
   // loopen over alle bootjes van tweede grote getal
   // achter positie van bootje hulpB nullen maken
   while ( hulpB != NULL ) {
      element* hulpA = A.uitgang;
      hulpC.maakNullen( maakNullenTeller );
      // loopen over alle bootjes van eerste grote getal en toevoegen aan hulpC
      // bootje van gg B wordt vermenigvuldigd met alle bootjes van gg A
      while ( hulpA != NULL ) {
         rekenC = (long long) hulpA->info * hulpB->info + rest;
         rest = rekenC / tienMacht( k );
         rekenC = rekenC % tienMacht( k );
         hulpC.voegVoor( rekenC );
         hulpA = hulpA->vorige;
      } // while
      // rest afhandelen
      if ( rest > 0 ) {
         hulpC.voegVoor( rest );
      } // if
      rest = 0;
    	// nieuwe reeks (hulpC) optellen bij uitkomst (*this)
      temp.kopieer( *this );
      telop( temp, hulpC );
      maakNullenTeller++;
      hulpB = hulpB->vorige;
   } // while
} // gg::vermenigvulig
