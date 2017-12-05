class element {
  public:
    element* vorige;
    element* volgende;
    int info;
};//element

class gg {
   public:
        gg ( );
      void print ( );
      void leesGetal ( );
      void telop ( gg A, gg B );
 	   void verwijderen ( );
 	   void fibonacci ( int n, gg& A );
 	   void vermenigvuldig ( gg A, gg B, gg& C );
 	   //static const int k;
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
 	   void kopieer ( gg& A, gg B );
       int verschuiving;
 	    int k;
 	    int aantalBoten;
};//gg


