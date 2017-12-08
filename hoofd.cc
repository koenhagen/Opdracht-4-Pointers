// Auteurs: Koen Hagen & Lucas de Bruin
// Studentnummers: s1998587 & s2040476
// Studierichting: Informatica en Economie
// Bestandsnamen: deBruinHagengg.cc & deBruinHagenhoofd.cc & deBruinHagengg.h
// Compiler: Code::Blocks' GNU GCC Compiler & Linux' G++ Compiler
// Laatst bijgewerkt: 08/12/2017

// Programma: In het menu kan de gebruiker een drietal grote getallen manipuleren.
// De grote getallen kunenn met elkaar opgeteld en vermenigvuldig worden.
// Ook kunnen 'fibonacci getallen' van een ingevoerd getal berekend worden.
#include <iostream>
#include "gg.h"

using namespace std;

// informatie over het programma voor de gebruiker
void infoBlokje ( ) {
   cout << "# Student1: Koen Hagen	  | Student2: Lucas de Bruin"    << endl
	     << "# aankomst: 2017 - 2018   | aankomst: 2017 - 2018"       << endl
	     << "# riching: I&E            | riching: I&E"                << endl
	     << "# Studentnummer: s1998587 | Studentnummer: s2040476"     << endl
        << "# Laatst bijgewerkt: 8 december 2017"                    << endl
	     << "# Opdracht 4: Grote getallen "                           << endl
	     << "# Met dit programma kunt u rekenen met grote getallen "
	     << "en fibonacci getallen berekenen, "
        << "aan de hand van de door u ingevoerde opties. "   << endl << endl;
} // infoBlokje

// aan de hand van keuze gebruiker het juiste grote getal doorgeven voor array
int grootGetalKeuze( char keuze ) {
   int grootGetal; // getal met keuze van gebruiker voor array
   if ( keuze == 'a' || keuze == 'A') {
      grootGetal = 0;
   } else if ( keuze == 'b' || keuze == 'B') {
      grootGetal = 1;
   } else if ( keuze == 'c' || keuze == 'C') {
      grootGetal = 2;
   } else {
      cout << "geen geldige optie: functie wordt niet uitgevoerd." << endl;
      grootGetal = 4; // ongeldige optie
   } // if/else
   return grootGetal;
} // grootGetalKeuze

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
   bufferSchoonmaken( buffer );		// zorgen dat menu eenmalig aangeroepen wordt
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
 	char vorigeKeuze = '\n';		// voor enters negeren en alle getallen inlezen
 	char keuze = '\n';				// zie vorigeKeuze
 	int getal = 0;						// van ingevoerde karakters getal maken
 	// door alle ingevoerde getallen loopen en toevoegen aan getal
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
} // menuopties

int main( ) {
   gg X[4];				// array van vier grote getallen (a, b, c en temp)
   int a, b, c;		// nodig voor keuze van grote getallen in array		
   int temp = 3;		// nodig voor optellen en vermenigvuldigen met zichzelf
   char keuze;			// optie van gebruiker
   char buffer;		// controle voor meer karakters na optie
   int grootGetal;	// getal met keuze van gebruiker voor array
   int toevTotaal;	// voor weergeven van aantal toegevoegde elementen
   int delTotaal;		// voor weergeven van aantal verwijderde elementen
   bool menuAan = true;
   infoBlokje( );
   while ( menuAan ) {
      menuOpties( );
	   leesOptie( keuze, buffer );
      switch ( keuze ) {
         case 'S': case 's':
         	// alle grote getallen verwijderen
         	// en aantal toegevoegde en verwijderde elementen optellen
            for ( int i = 0; i < 4; i++ ) {
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
            leesOptie( keuze, buffer );	 // keuze inlezen
            grootGetal = grootGetalKeuze( keuze );
            if ( grootGetal < 3 ) {      	 // een ongeldige optie vermijden
               cout << "Geef getal: ";
               X[grootGetal].leesGetal( ); // getal in keuze (groot getal) stoppen
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
            grootGetal = grootGetalKeuze( keuze );// keuze inlezen
            if ( grootGetal < 3 ) {      			  // een ongeldige optie vermijden
               cout << "Geef getal: ";
               // bepaalde fibonacci (getal) in keuze (groot getal) stoppen
               X[grootGetal].fibonacci( leesGetal( ) ); 
            }
		      break;
         case 'V': case 'v':
            grootGetalKeuzes( a, b, c );
            if ( a < 4 && b < 4 && c < 4 ) {
            	// vermenigvuldiging in temp stoppen
		         X[temp].vermenigvuldig( X[a], X[b] );
		         // temp in getal c stoppen	
		         X[c].kopieer( X[temp] );					
		      }
		      break;
         case 'T': case 't':
            grootGetalKeuzes( a, b, c );
            if ( a < 4 && b < 4 && c < 4 ) {	
		         X[temp].telop( X[a], X[b] );	// telop in temp groot getal stoppen
		         X[c].kopieer( X[temp] );		// temp groot getal in c stoppen
		      }
            break;
	      default:
	         cout << "Geen geldige optie" << endl;
            break;
      } // switch
   } // while
   return 0;
}// main
