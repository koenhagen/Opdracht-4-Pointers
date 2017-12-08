#include <iostream>
#include "gg.h"

using namespace std;

// aan de hand van keuze gebruiker het juiste grote getal doorgeven voor array
int grootGetalKeuze( char keuze ) {
   int grootGetal;
   if ( keuze == 'a' || keuze == 'A') {
      grootGetal = 0;
   } else if ( keuze == 'b' || keuze == 'B') {
      grootGetal = 1;
   } else if ( keuze == 'c' || keuze == 'C') {
      grootGetal = 2;
   } else {
      cout << "geen geldige optie: functie wordt niet uitgevoerd." << endl;
      grootGetal = 3; // ongeldige optie
   }
   return grootGetal;
}

// overige karakters na keuze (buffer) verwijderen
void bufferSchoonmaken( char buffer ) {
   if ( buffer != '\n' ) {          // testen of buffer niet leeg is, zo ja
      while ( buffer != '\n' ) {    // tot enter van gebruiker
         cin.get( buffer );         // overige karakters blijven ophalen
      } // while
   } // if
} // bufferSchoonmaken

// keuze van gebruiker inlezen
void leesOptie( char& keuze, char& buffer ) {
   keuze = '\n';
   while ( keuze == '\n' ) {        // enters negeren
      cin.get( keuze );
   } // while
   cin.get( buffer );               // controleren op meerdere karakters na keuze
   if ( buffer != '\n' ) {          // als dit het geval is:
      keuze = '0';                  // keuze ongeldig maken
   } // if
   bufferSchoonmaken( buffer );
} // leesOptie

// meerdere grote getallen inlezen en koppelen aan juist getal voor array (a, b, c)
void grootGetalKeuzes( int& a, int& b, int& c ) {
	char keuze;
	char buffer;
	cout << "Geef linkerlid: (A, B, of C) ";
   leesOptie( keuze, buffer );
   a = grootGetalKeuze( keuze );
   cout << "Geef rechterlid: (A, B, of C) ";
   leesOptie( keuze, buffer );
   b = grootGetalKeuze( keuze );
   cout << "Waarheen? (A, B of C) ";
   leesOptie( keuze, buffer );
   c = grootGetalKeuze( keuze );
}

// door de gebruiker gegeven getal inlezen
// enters en niet-getallen negeren
int leesGetal( ) {
 	char vorigeKeuze = '\n';
 	char keuze = '\n';
 	int getal = 0;
   while ( vorigeKeuze == '\n' || keuze != '\n' ) {
      vorigeKeuze = keuze;
      cin.get( keuze );
      if ( keuze >= '0' && keuze <= '9' ) {
         getal = ( getal * 10 ) + ( keuze - '0' );
      } // if
   } // while
   return getal;
} // leesGetal

// menuopties naar scherm schrijven
void menuOpties( ) {
   cout << "Opties: "
        << "(P)rint - "
	     << "(L)ees in - "
	     << "(T)el op - "
	     << "(F)ibonacci - "
	     << "(V)ermenigvuldig - "
	     << "(D)eleten - "
	     << "(S)top en verwijder" << endl
	     << "Wat wilt u doen: ";
}

int main( ) {
   gg X[3];
   int a, b, c;
   char keuze;
   char buffer;
   int grootGetal;
   int toevTotaal;
   int delTotaal;
   bool menuAan = true;
   while ( menuAan ) {
      menuOpties( );
	   leesOptie( keuze, buffer );
      switch ( keuze ) {
         case 'S': case 's':
            for ( int i = 0; i < 3; i++ ) {
               X[i].verwijderen( );
               toevTotaal = X[i].toevElement;
               delTotaal = X[i].delElement;
            }
            cout << "Aantal elementen toegevoegd: " << toevTotaal << endl;
            cout << "Aantal elementen verwijderd: " << delTotaal << endl;
		      cout << "Einde programma" << endl;
		      menuAan = false;
            break;
         case 'L': case 'l':
            cout << "waarin? (A, B of C): ";
            leesOptie( keuze, buffer );
            grootGetal = grootGetalKeuze( keuze );
            if ( grootGetal < 3 ) {       // een ongeldige optie vermijden
               cout << "Geef getal: ";
               X[grootGetal].leesGetal( );
            }
            break;
         case 'D': case 'd':
            X[0].verwijderen( );
            X[1].verwijderen( );
            X[2].verwijderen( );
            cout << "Getallen verwijderd.." << endl;
            break;
         case 'P': case 'p':
            cout << "Getal A: ";
		      X[0].print( );
            cout << "Getal B: ";
		      X[1].print( );
            cout << "Getal C: ";
		      X[2].print( );
            break;
         case 'F': case 'f':
            cout << "waarin? (A, B of C): ";
            leesOptie( keuze, buffer );
            grootGetal = grootGetalKeuze( keuze );
            if ( grootGetal < 3 ) {       // een ongeldige optie vermijden
               cout << "Geef getal: ";
               X[grootGetal].fibonacci( leesGetal( ) );
            }
		      break;
         case 'V': case 'v':
            grootGetalKeuzes( a, b, c );
            if ( a < 3 && b < 3 && c < 3 ) {
		         X[c].vermenigvuldig( X[a], X[b] );
		      }
		      break;
         case 'T': case 't':
            grootGetalKeuzes( a, b, c );
            if ( a < 3 && b < 3 && c < 3 ) {
		         X[c].telop( X[a], X[b] );
		      }
            break;
	      default:
	         cout << "Geen geldige optie" << endl;
            break;
      } // switch
   } // while
   return 0;
}//main
//test
