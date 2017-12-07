#include <iostream>
#include "gg.h"

using namespace std;

// overige karakters na keuze (buffer) verwijderen
void bufferSchoonmaken ( char buffer ) {
   if ( buffer != '\n' ) {          // testen of buffer niet leeg is, zo ja
      while ( buffer != '\n' ) {    // tot enter van gebruiker
         cin.get ( buffer );        // overige karakters blijven ophalen
      } // while
   } // if
} // bufferSchoonmaken

// keuze van gebruiker inlezen
void leesOptie ( char& keuze, char& buffer ) {
   keuze = '\n';
   while ( keuze == '\n' ) {        // enters negeren
      cin.get ( keuze );
   } // while
   cin.get ( buffer );              // controleren op meerdere karakters na keuze
   if ( buffer != '\n' ) {          // als dit het geval is:
      keuze = '0';                  // keuze ongeldig maken
   } // if
} // leesOptie

// door de gebruiker gegeven getal inlezen tot maximaal 1000
// enters en niet-getallen negeren
int leesGetal ( ) {
 	char vorigeKeuze = '\n';
 	char keuze = '\n';
 	int getal = 0;
   while ( vorigeKeuze == '\n' || keuze != '\n' ) {
      vorigeKeuze = keuze;
      cin.get ( keuze );
      if ( keuze >= '0' && keuze <= '9' ) {
         getal = ( getal * 10 ) + ( keuze - '0' );
      } // if
   } // while
   
   cout << getal << endl;
   return getal;
} // leesGetal

int main ( ) {
   gg X[3];
   char invoer;
   char buffer;
   char antwoord;
   int a = 0, b = 1, c = 2;
   int toevTotaal;
   int delTotaal;
   bool menuAan = true;
   while ( menuAan ) {
      cout << "Opties: ";
	   cout << "(P)rint - ";
	   cout << "(L)ees in - ";
	   cout << "(T)el op - ";
	   cout << "(F)ibonacci - ";
	   cout << "(V)ermenigvuldig - ";
	   cout << "(D)eleten - ";
	   cout << "(S)top en verwijder" << endl;
	   cout << "Wat wilt u doen: ";
	   leesOptie( invoer, buffer );
      bufferSchoonmaken( buffer );
      switch ( invoer ) {
         case 'S': case 's':
            toevTotaal = X[0].toevElement + X[1].toevElement + X[2].toevElement;
            delTotaal = X[0].delElement + X[1].delElement + X[2].delElement;
            cout << "Aantal elementen toegevoegd: " << toevTotaal << endl;
            cout << "Aantal elementen verwijderd: " << delTotaal << endl;
		      cout << "Einde programma" << endl;
		      menuAan = false;
            break;
         case 'L': case 'l':
            cout << "waarin? (A, B of C) ";
            leesOptie( antwoord, buffer );
            bufferSchoonmaken( buffer );
            if ( antwoord == 'a' || antwoord == 'A') {
            cout << "Geef getal: ";
		      X[0].leesGetal( );
		      }
		      else if ( antwoord == 'b' || antwoord == 'B') {
            cout << "Geef getal: ";
		      X[1].leesGetal( );
		      }
		      else if ( antwoord == 'c' || antwoord == 'C') {
            cout << "Geef getal: ";
		      X[2].leesGetal( );
		      }
		      else {
		      cout << "Geen geldige optie." << endl;
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
            cout << "waarin? (A, B of C) ";
            leesOptie( antwoord, buffer );
            bufferSchoonmaken( buffer );
            if ( antwoord == 'a' || antwoord == 'A') {
            cout << "Geef getal: ";
		      X[0].fibonacci( leesGetal( ), X[0] );
		      }
		      else if ( antwoord == 'b' || antwoord == 'B') {
            cout << "Geef getal: ";
		      X[1].fibonacci( leesGetal( ), X[1] );
		      }
		      else if ( antwoord == 'c' || antwoord == 'C') {
            cout << "Geef getal: ";
		      X[2].fibonacci( leesGetal( ), X[2] );
		      }
		      else {
		      cout << "Geen geldige optie." << endl;
		      }
		      break;
         case 'V': case 'v': 
            cout << "Geef linkerlid: (A, B, of C) ";
            leesOptie( antwoord, buffer );
            if ( antwoord == 'a' || antwoord == 'A') {
            a = 0;
            }
            else if ( antwoord == 'b' || antwoord == 'B') {
		      a = 1;
		      }
		      else if ( antwoord == 'c' || antwoord == 'C') {
		      a = 2;
		      }
            cout << "Geef rechterlid: (A, B, of C) ";
            leesOptie( antwoord, buffer );
            if ( antwoord == 'a' || antwoord == 'A') {
            b = 0;
            }
            else if ( antwoord == 'b' || antwoord == 'B') {
		      b = 1;
		      }
		      else if ( antwoord == 'c' || antwoord == 'C') {
		      b = 2;
		      }
		      cout << "Waarheen? (A, B of C) ";
            leesOptie( antwoord, buffer );
            if ( antwoord == 'a' || antwoord == 'A') {
            c = 0;
            }
            else if ( antwoord == 'b' || antwoord == 'B') {
		      c = 1;
		      }
		      else if ( antwoord == 'c' || antwoord == 'C') {
		      c = 2;
		      }
		      X[c].vermenigvuldig( X[a], X[b], X[c] );
		      break;
         case 'T': case 't': 
            cout << "Geef linkerlid: (A, B, of C) ";
            leesOptie( antwoord, buffer );
            if ( antwoord == 'a' || antwoord == 'A') {
            a = 0;
            }
            else if ( antwoord == 'b' || antwoord == 'B') {
		      a = 1;
		      }
		      else if ( antwoord == 'c' || antwoord == 'C') {
		      a = 2;
		      }
            cout << "Geef rechterlid: (A, B, of C) ";
            leesOptie( antwoord, buffer );
            if ( antwoord == 'a' || antwoord == 'A') {
            b = 0;
            }
            else if ( antwoord == 'b' || antwoord == 'B') {
		      b = 1;
		      }
		      else if ( antwoord == 'c' || antwoord == 'C') {
		      b = 2;
		      }
		      cout << "Waarheen? (A, B of C) ";
            leesOptie( antwoord, buffer );
            if ( antwoord == 'a' || antwoord == 'A') {
            c = 0;
            }
            else if ( antwoord == 'b' || antwoord == 'B') {
		      c = 1;
		      }
		      else if ( antwoord == 'c' || antwoord == 'C') {
		      c = 2;
		      }
		      X[c].telop( X[a], X[b] );
            break;
	      default:
	         cout << "Geen geldige optie" << endl;
            break;
      } // switch
   } // while
   return 0;
}//main
