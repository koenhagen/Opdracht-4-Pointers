#include <iostream>
#include "gg.h"

using namespace std;

// overige karakters na keuze (buffer) verwijderen
void bufferSchoonmaken ( char buffer ) {
   if ( buffer != '\n' ) {          // testen of buffer niet leeg is, zo ja
      while ( buffer != '\n' ) {    // tot enter van gebruiker
         cin.get ( buffer );        // overige karakters blijven ophalen
      }
   }
}

// keuze van gebruiker inlezen
void leesOptie ( char& keuze, char& buffer ) {
   keuze = '\n';
   while ( keuze == '\n' ) {        // enters negeren
      cin.get ( keuze );
   }
   cin.get ( buffer );              // controleren op meerdere karakters na keuze
   if ( buffer != '\n' ) {          // als dit het geval is:
      keuze = '0';                  // keuze ongeldig maken
   }
}

int main ( ) {
   gg A;
   gg B;
   gg C;
   char invoer;
   char buffer;
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
            toevTotaal = A.toevElement + B.toevElement + C.toevElement;
            delTotaal = A.delElement + B.delElement + C.delElement;
            cout << "Aantal elementen toegevoegd: " << toevTotaal << endl;
            cout << "Aantal elementen verwijderd: " << delTotaal << endl;
		      cout << "Einde programma" << endl;
		      menuAan = false;
            break;
         case 'L': case 'l':
		      A.leesGetal ( );
		      B.leesGetal ( );
            break;
         case 'D': case 'd':
            A.verwijderen ( );
            B.verwijderen ( );
            C.verwijderen ( );
            break;
         case 'P': case 'p':
		      A.print ( );
		      B.print ( );
		      C.print ( );
            break;
         case 'F': case 'f':
		      C.fibonacci ( 1000, C );
		      C.print ( );
		      break;
         case 'V': case 'v':
		      C.vermenigvuldig ( A, B, C);
		      break;
         case 'T': case 't':
		      C.telop ( A, B );
            break;
	      default:
	         cout << "Geen geldige optie" << endl;
            break;
      } // switch
   } // while
   return 0;
}//main
