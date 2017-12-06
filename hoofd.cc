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
   int a, b, c;
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
            cout << "Geef linkerlid: (A, B, of C)";
           // if ( leesOptie( antwoord, buffer ) == 'a') {
            //a = 0;
           // }

		      X[2].vermenigvuldig( X[a], X[1], X[2] );
            bufferSchoonmaken( buffer );
		      break;
         case 'T': case 't':
		      X[2].telop( X[0], X[1] );
            break;
	      default:
	         cout << "Geen geldige optie" << endl;
            break;
      } // switch
   } // while
   return 0;
}//main
