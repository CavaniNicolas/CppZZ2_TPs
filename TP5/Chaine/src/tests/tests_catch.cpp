#include "catch.hpp"
#include <cstring>
#include <sstream> 
#include "../Chaine.hpp"

TEST_CASE("Constructeur par defaut") {
   Chaine c;
   CHECK( -1 == c.getCapacite());
   CHECK(  0 == c.c_str()); // 0, NULL, ou nullptr
}


TEST_CASE("Verification des const sur les accesseurs") {
   const Chaine c;
   CHECK( -1 == c.getCapacite());
   CHECK(  0 == c.c_str()); // 0, NULL, ou nullptr
}


TEST_CASE("Constructeur par chaine C") {
	char source [] = "rien";
    Chaine c1(source);
    CHECK( (signed)strlen(source) == c1.getCapacite() );
    CHECK( 0 == strcmp(source, c1.c_str()) ); 

    Chaine c2 = "";
    CHECK( 0 == c2.getCapacite() );
    CHECK( 0 == strcmp("", c2.c_str()));

    // Verifier que la liberation memoire est bien faite
}


TEST_CASE("Constructeur avec capacite") {
    Chaine c1(6);
    CHECK( 6 == c1.getCapacite());
    CHECK( 0 == strlen(c1.c_str())); 

    // Verifier que la liberation memoire est bien faite
}


TEST_CASE("Constructeur de copie") {
    Chaine s1(10);   // une chaine vide
    Chaine s2 = s1;  // une autre chaine vide
    
    CHECK( s1.getCapacite() == s2.getCapacite());
    // tous les problemes vont venir de la
    // j'ai converti en void * uniquement pour l'affichage de catch
    CHECK( (void *)s1.c_str() != (void *)s2.c_str() );
    CHECK( 0 == strcmp(s1.c_str(), s2.c_str() ));
}


TEST_CASE("methode afficher") {
	const char * original = "une chaine a tester";
    const Chaine c1(original);
    std::stringstream ss;
    
    c1.afficher(); // on verifie juste que ca compile
    c1.afficher(ss);

    CHECK( ss.str() == original); // test de std::string :-)
}


TEST_CASE("operateur d'affectation") {
	Chaine s1("une premiere chaine");
    Chaine s2("une deuxieme chaine plus longue que la premiere");
    
    s1 = s2;

    CHECK( s1.getCapacite() == s2.getCapacite()); 
    CHECK( (void *)s1.c_str() != (void *)s2.c_str() );
    CHECK( 0 == strcmp(s1.c_str(), s2.c_str() ));

    s1 = s1; // est ce que cela va survivre a l execution ?
}


TEST_CASE("Surcharge <<") {
	char const * chaine = "une nouvelle surcharge";
	Chaine s(chaine);
    std::stringstream ss;
    ss << s;

    CHECK( ss.str() == chaine );

	char const * chaine2 = "une nouvelle surcharge hello";
    ss << " hello";
    CHECK( ss.str() == chaine2 );
}

TEST_CASE("Surcharge []") {
    Chaine s("Bisous");

    // s[-1] = 'Z';
    // CHECK( !strcmp(s.c_str(), "BiZous") );
    // SIGABRT - Abort (abnormal termination) signal :)

    s[2] = 'Z';
    CHECK( !strcmp(s.c_str(), "BiZous") );

    Chaine const s2("Bisous");
    char c = s2[1]; // Verifie si operator[] const est bien appele


    Chaine s3("une grande licorne rouge");
    const Chaine s4("le petit panda vert");

    char c1 = s3[4];
    char c2 = s3.operator[](2);
    CHECK( c1=='g');
    CHECK( c2=='e');
    s3[0]='U';
    CHECK(0 == strcmp(s3.c_str(), "Une grande licorne rouge"));

    char c3 = s4[3];
    CHECK( c3=='p');
}

TEST_CASE("Operator ==") {
    Chaine c1("bonjour");
    Chaine c2("bisous");
    Chaine c3("bisous");

    CHECK( !(c1 == c2) );
    CHECK( c2 == c3 );
    CHECK( Chaine("bonjour") == c1 );
    // CHECK( c2 == "bisous" );
}

TEST_CASE("Operator +") {
    Chaine c1("bonjour");
    Chaine c2("bisous");

    CHECK( !strcmp((c1 + c2).c_str(), "bonjourbisous") );
}


// TP6 Exceptions

TEST_CASE("exceptions aux bornes") {
    Chaine s(10);

    REQUIRE_THROWS_AS( s[-1] == 0, Chaine::OutOfRangeException);
    // OU
    // REQUIRE_THROWS_AS( s[-1] == 0, std::out_of_range);
    // REQUIRE_THROWS_AS( s[12] == 0, std::bad_alloc);  // :-)
}

// TEST_CASE("exception sur pointeur null") {
//   Chaine s(0);
    
//   // verification que l'heritage est bien fait  
//   std::logic_error * pe = new null_pointer;
//   delete pe;

//   REQUIRE_THROWS_AS( s[1] == 0, null_pointer);
// }