import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class GaloisFieldTests {

    @Test
    void constructors_test() {
        GaloisField a = new GaloisField();
        Assertions.assertEquals(0, a.toInt() );
        a = new GaloisField(1234577);
        Assertions.assertEquals(0, a.toInt() );
        a = new GaloisField(10000000);
        Assertions.assertEquals(123384, a.toInt() );
        a = new GaloisField(-10);
        Assertions.assertEquals(1234567, a.toInt() );
        a = new GaloisField(-1234577);
        Assertions.assertEquals(0, a.toInt() );
        a = new GaloisField(-10000000); Assertions.assertEquals( 1111193, a.toInt() );
    }

    @Test
    void addition_test_1() {
        Assertions.assertEquals( 20, GaloisField.add(new GaloisField(10), new GaloisField(10)).toInt() );
        Assertions.assertEquals( 0, GaloisField.add(new GaloisField(1234567), new GaloisField(10)).toInt() );
        Assertions.assertEquals( 1234575, GaloisField.add(new GaloisField(1234576), new GaloisField(1234576)).toInt() );
    }

    @Test
    void addition_test_2() {
        GaloisField a = new GaloisField(10);
        a.add(new GaloisField(10));
        Assertions.assertEquals( 20, a.toInt() );
        a = new GaloisField(1234567);
        a.add(new GaloisField(10));
        Assertions.assertEquals( 0, a.toInt() );
        a = new GaloisField(1234576);
        a.add(new GaloisField(1234576));
        Assertions.assertEquals( 1234575, a.toInt() );
    }

    @Test
    void subtraction_test_1() {
        Assertions.assertEquals( 10, GaloisField.subtract(new GaloisField(20), new GaloisField(10)).toInt() );
        Assertions.assertEquals( 1234567, GaloisField.subtract(new GaloisField(10), new GaloisField(20)).toInt() );
        Assertions.assertEquals( 1, GaloisField.subtract(new GaloisField(), new GaloisField(1234576)).toInt() );
    }

    @Test
    void subtraction_test_2() {
        GaloisField a = new GaloisField(20);
        a.subtract(new GaloisField(10));
        Assertions.assertEquals( 10, a.toInt() );
        a = new GaloisField(10);
        a.subtract(new GaloisField(20));
        Assertions.assertEquals( 1234567, a.toInt() );
        a = new GaloisField();
        a.subtract(new GaloisField(1234576));
        Assertions.assertEquals( 1, a.toInt() );
    }

    @Test
    void multiplication_test_1() {
        Assertions.assertEquals( 100, GaloisField.mutiply(new GaloisField(10), new GaloisField(10)).toInt() );
        Assertions.assertEquals( 1233840, GaloisField.mutiply(new GaloisField(10000), new GaloisField(10000)).toInt() );
        Assertions.assertEquals( 1, GaloisField.mutiply(new GaloisField(1234576), new GaloisField(1234576)).toInt() );
    }

    @Test
    void multiplication_test_2() {
        GaloisField a = new GaloisField(10);
        a.multiply(new GaloisField(10));
        Assertions.assertEquals( 100, a.toInt() );
        a = new GaloisField(10000);
        a.multiply(new GaloisField(10000));
        Assertions.assertEquals( 1233840, a.toInt() );
        a = new GaloisField(1234576);
        a.multiply(new GaloisField(1234576));
        Assertions.assertEquals( 1, a.toInt() );
    }

    @Test
    void division_test_1() {
        Assertions.assertThrows( ArithmeticException.class, () -> GaloisField.divide(new GaloisField(1), new GaloisField()) );
        Assertions.assertEquals( 123, GaloisField.mutiply(GaloisField.divide( new GaloisField(123), new GaloisField(456)), new GaloisField(456)).toInt() );
        Assertions.assertEquals( 1, GaloisField.divide(new GaloisField(7754321), new GaloisField(7754321)).toInt() );
        Assertions.assertEquals( 214711, GaloisField.divide(new GaloisField(45), new GaloisField(23)).toInt() );
    }

    @Test
    void division_test_2() {
        GaloisField b = new GaloisField(10);
        Assertions.assertThrows( ArithmeticException.class, () -> b.divide(new GaloisField()) );
        GaloisField a = new GaloisField(123);
        a.divide(new GaloisField(456));
        a.multiply(new GaloisField(456));
        Assertions.assertEquals( 123, a.toInt() );
        a = new GaloisField(7754321);
        a.divide(new GaloisField(7754321));
        Assertions.assertEquals( 1, a.toInt() );
        a = new GaloisField(45);
        a.divide(new GaloisField(23));
        Assertions.assertEquals( 214711, a.toInt() );
    }

    @Test
    void comparison_test() {
        GaloisField a = new GaloisField();
        Assertions.assertTrue( a.equals(new GaloisField()) );
        Assertions.assertTrue( a.equals(new GaloisField(1234577)) );
        Assertions.assertFalse( a.equals(null) );
        Assertions.assertFalse( a.equals( new Object() ) );
        Assertions.assertFalse( a.equals(1) );

        a = new GaloisField(10);
        Assertions.assertEquals( 0, a.compareTo(new GaloisField(10)) );
        Assertions.assertTrue( a.compareTo(new GaloisField(5)) > 0 );
        Assertions.assertTrue( a.compareTo(new GaloisField(20)) < 0 );
    }
}
