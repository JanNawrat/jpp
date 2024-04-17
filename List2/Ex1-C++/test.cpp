#include "GaloisField.hpp"
#include "catch_amalgamated.hpp"

TEST_CASE("Galois field 1234577") {
    SECTION("Constructors") {
        REQUIRE( int(GaloisField()) == 0 );
        REQUIRE( int(GaloisField(1234577)) == 0 );
        REQUIRE( int(GaloisField(10000000)) == 123384 );
        REQUIRE( int(GaloisField(-10)) == 1234567);
        REQUIRE( int(GaloisField(-1234577)) == 0 );
        REQUIRE( int(GaloisField(-10000000)) == 1111193);
    }
    SECTION("Addition") {
        REQUIRE( int(GaloisField(10) + GaloisField(10)) == 20 );
        REQUIRE( int(GaloisField(1234567) + GaloisField(10)) == 0 );
        REQUIRE( int(GaloisField(1234576) + GaloisField(1234576)) == 1234575);
    }
    SECTION("Addition 2") {
        GaloisField a(10);
        a += GaloisField(10);
        GaloisField b(1234567);
        b += GaloisField(10);
        GaloisField c(1234576);
        c += GaloisField(1234576);
        REQUIRE( int(a) == 20 );
        REQUIRE( int(b) == 0 );
        REQUIRE( int(c) == 1234575);
    }
    SECTION("Substraction") {
        REQUIRE( int(GaloisField(20) - GaloisField(10)) == 10 );
        REQUIRE( int(GaloisField(10) - GaloisField(20)) == 1234567 );
        REQUIRE( int(GaloisField() - GaloisField(1234576)) == 1 );
    }
    SECTION("Substraction 2") {
        GaloisField a(20);
        a -= GaloisField(10);
        GaloisField b(10);
        b -= GaloisField(20);
        GaloisField c;
        c -= GaloisField(1234576);
        REQUIRE( int(a) == 10 );
        REQUIRE( int(b) == 1234567 );
        REQUIRE( int(c) == 1 );
    }
    SECTION("Multiplication") {
        REQUIRE( int(GaloisField(10) * GaloisField(10)) == 100 );
        REQUIRE( int(GaloisField(10000) * GaloisField(10000)) == 1233840 );
        REQUIRE( int(GaloisField(1234576) * GaloisField(1234576)) == 1 );
    }
    SECTION("Multiplication 2") {
        GaloisField a(10);
        a *= GaloisField(10);
        GaloisField b(10000);
        b *= GaloisField(10000);
        GaloisField c(1234576);
        c *= GaloisField(1234576);
        REQUIRE( int(a) == 100 );
        REQUIRE( int(b) == 1233840 );
        REQUIRE( int(c) == 1 );
    }
    SECTION("Division") {
        REQUIRE_THROWS( GaloisField(1) / GaloisField() );
        REQUIRE( int(GaloisField(123) / GaloisField(456) * GaloisField(456)) == 123 );
        REQUIRE( int(GaloisField(7754321) / GaloisField(7754321)) == 1 );
        REQUIRE( int(GaloisField(45) / GaloisField(23)) == 214711 );
    }
    SECTION("Division 2") {
        GaloisField a(1);
        REQUIRE_THROWS( a /= GaloisField() );
        GaloisField b(123);
        b /= GaloisField(456);
        b *= GaloisField(456);
        GaloisField c(7754321);
        c /= GaloisField(7754321);
        GaloisField d(45);
        d /= GaloisField(23);
        REQUIRE( int(b) == 123 );
        REQUIRE( int(c) == 1 );
        REQUIRE( int(d) == 214711 );
    }
    SECTION("Comparison operatiors") {
        REQUIRE( GaloisField() == GaloisField(1234577) );
        REQUIRE_FALSE( GaloisField() == GaloisField(1) );
        REQUIRE( GaloisField() != GaloisField(1) );
        REQUIRE_FALSE( GaloisField() != GaloisField(0) );
        REQUIRE( GaloisField(10) <= GaloisField(10) );
        REQUIRE_FALSE( GaloisField(20) <= GaloisField(10) );
        REQUIRE( GaloisField(10) <= GaloisField(20) );
        REQUIRE( GaloisField(10) >= GaloisField(10) );
        REQUIRE( GaloisField(20) >= GaloisField(10) );
        REQUIRE_FALSE( GaloisField(10) >= GaloisField(20) );
        REQUIRE( GaloisField(10) < GaloisField(20) );
        REQUIRE_FALSE( GaloisField(10) < GaloisField(10) );
        REQUIRE_FALSE( GaloisField(20) < GaloisField(10) );
        REQUIRE( GaloisField(20) > GaloisField(10) );
        REQUIRE_FALSE( GaloisField(10) > GaloisField(10) );
        REQUIRE_FALSE( GaloisField(10) > GaloisField(20) );
    }
}