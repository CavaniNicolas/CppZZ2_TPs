#include "catch.hpp"
#include <cstring>
#include <sstream> 
#include "../Vecteur.hpp"

TEST_CASE ("Vecteur1") {
  const Vecteur v;
 
  REQUIRE ( v.getCapacity() >= 10 );
  REQUIRE ( v.getSize()     == 0  );
}


TEST_CASE ("Vecteur2" ) {
  Vecteur v(20);
 
  REQUIRE ( v.getCapacity() == 20 );
  REQUIRE ( v.getSize()     == 0  );
}

TEST_CASE ("Vecteur3" ) {
  Vecteur v(5);
 
  SECTION("ajout de quelques elements") {
    REQUIRE ( v.getCapacity() == 5 );

    for (int i=0; i<4; ++i)
      v.push_back(i * 1.0);

    REQUIRE ( v.getSize()     == 4  );
  }

  SECTION("tableau un peu agrandi") {
    // on peut verifier que vecteur est bien un nouveau :-) 
  REQUIRE ( v.getCapacity() == 5 );
    for (int i=0; i<6; ++i)
      v.push_back(i * 1.0);

    REQUIRE ( v.getCapacity()  == 10 );
    REQUIRE ( v.getSize()      == 6  );
  }

//   SECTION("on verifie les valeurs dans le vecteur") {
//     for (int i=0; i<25; ++i)
//       v.push_back(i * 1.0);

//     REQUIRE( v.getCapacity() ==  40 );
//     REQUIRE( v.getSize()     ==  25 );

//     for (int i=0; i<25; ++i)
//       CHECK(v[i] == Approx(i * 1.0 + 0.1));  // :-)
//   }

//   SECTION("on verifie les exceptions") {
//     REQUIRE_THROWS_AS( v[-1] == 0, Vecteur::OutOfRangeException); 
//     REQUIRE_THROWS_AS( v [6] == 0, std::bad_alloc);  // :-)
//    }
}