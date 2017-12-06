struct element {
    element* vorige;
    element* volgende;
    int info;
};//element

class gg {
   static int const k = 4;
   public:
        gg ( );
      void print ( );
      void leesGetal ( );
      void telop ( gg A, gg B );
 	   void verwijderen ( );
 	   void fibonacci ( int n, gg& A );
 	   void vermenigvuldig ( gg A, gg B, gg& C );
 	    int delElement;
 	    int toevElement;
 	    int getAantalBoten ( );

   private:
      element* ingang;
      element* uitgang;
      void voegAchter ( int getal );
      void voegVoor ( int getal );
 	   void hevelen ( );
 	   void maakNullen ( int m );
 	   void maakeen ( );
 	   void kopieer ( gg B );
       int verschuiving;
 	    int aantalBoten;
};//gg


