
#include <Vecteur/VecteurTest.h>
#include <Vecteur/Vecteur.h>

using namespace cassebrique;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( VecteurTest );


void VecteurTest::setUp() { }
void VecteurTest::tearDown() { }

void VecteurTest::testConstructor()
{
	int x = 0;
	int y = 0;

	Vecteur<int> v0(x, y); /* le constructeur est appelé. Il est nécéssaire de
			    définir l'objet avec 2 attributs car nous n'avons
			    pas défini d'autres constructeurs */
	v0.nouvellesCoordonnees(1, 2); /* on assigne des coordonnées ensuite */

	Vecteur<int> v(1, 2);

	v.recupererCoordonnees(x, y);
	CPPUNIT_ASSERT(x == 1 && y == 2);

	CPPUNIT_ASSERT(v0 == v);

	v += v;
	/* le constructeur de copie implicite est appelé, ce qui est possible
         * car toutes les données membre de la classe sont copiables */
	Vecteur<int> vv(v);
	v.recupererCoordonnees(x, y);
	CPPUNIT_ASSERT(x == 2 && y == 4);
}

void VecteurTest::testEgalite()
{
	/* test de l'opérateur == */
	Vecteur<int> v(1, 2);

	CPPUNIT_ASSERT(   v == Vecteur<int>( 1,  2)  );
	CPPUNIT_ASSERT( !(v == Vecteur<int>( 2,  2)) );
	CPPUNIT_ASSERT( !(v == Vecteur<int>( 1,  1)) );
	CPPUNIT_ASSERT( !(v == Vecteur<int>( 2,  1)) );
	CPPUNIT_ASSERT( !(v == Vecteur<int>(-1, -2)) );
	CPPUNIT_ASSERT( !(v == Vecteur<int>(-2, -1)) );
}

void VecteurTest::testDifferent()
{
	/* test de l'opérateur != */
	Vecteur<int> v(1, 2);

	CPPUNIT_ASSERT( !(v != Vecteur<int>( 1,  2)) );
	CPPUNIT_ASSERT(   v != Vecteur<int>( 2,  2)  );
	CPPUNIT_ASSERT(   v != Vecteur<int>( 1,  1)  );
	CPPUNIT_ASSERT(   v != Vecteur<int>( 2,  1)  );
	CPPUNIT_ASSERT(   v != Vecteur<int>(-1, -2)  );
	CPPUNIT_ASSERT(   v != Vecteur<int>(-1, -2)  );
}

void VecteurTest::testSomme()
{
	/* test de l'opérateur + */
	Vecteur<int> v1(1, 2);
	Vecteur<int> v2(2, 3);
	Vecteur<int> v3(0, 0);

	v3 = v1 + v2;

	CPPUNIT_ASSERT(v1 == Vecteur<int>(1, 2));
	CPPUNIT_ASSERT(v2 == Vecteur<int>(2, 3));
	CPPUNIT_ASSERT(v3 == Vecteur<int>(3, 5));

	/* test de l'opérateur += */
	v3 = Vecteur<int>(0, 0);

	v3 += v1;
	v3 += v2;

	CPPUNIT_ASSERT(v1 == Vecteur<int>(1, 2));
	CPPUNIT_ASSERT(v2 == Vecteur<int>(2, 3));
	CPPUNIT_ASSERT(v3 == Vecteur<int>(3, 5));
}

void VecteurTest::testSoustraction()
{
	/* test de l'opérateur - */
	Vecteur<int> v1(1, 2);
	Vecteur<int> v2(2, 3);
	Vecteur<int> v3(0, 0);

	v3 = v2 - v1;

	CPPUNIT_ASSERT(v1 == Vecteur<int>(1, 2));
	CPPUNIT_ASSERT(v2 == Vecteur<int>(2, 3));
	CPPUNIT_ASSERT(v3 == Vecteur<int>(1, 1));

	/* test de l'opérateur -= */
	v3 = Vecteur<int>(0, 0);

	v3 -= v1;
	v3 -= v2;

	CPPUNIT_ASSERT(v1 == Vecteur<int>(1, 2));
	CPPUNIT_ASSERT(v2 == Vecteur<int>(2, 3));
	CPPUNIT_ASSERT(v3 == Vecteur<int>(-3, -5));
}

