import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.MethodOrderer;
import org.junit.jupiter.api.Order;
import org.junit.jupiter.api.Tag;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestMethodOrder;

@TestMethodOrder(MethodOrderer.OrderAnnotation.class)
public class TestDiv {
    private Div testeur;

    @BeforeAll
    public static void debut() {
        System.out.println("Et c'est parti !!!");
    }

    @AfterAll
    public static void fin() {
        System.out.println("C'EST FINI !!!");
    }

    @BeforeEach
    public void init() {
        System.out.println("init...");
        testeur = new Div();
    }

    @AfterEach
    public void del() {
        System.out.println("...del");
        testeur = null;
    }

    @Test
    @DisplayName("Mon cas de test identité 10/1=10")
    @Order(1)
    public void test1() {
        Assertions.assertEquals(10, testeur.divide(10, 1), "10/1=1 FAILED");
    }

    @Test
    @Tag("TestZero")
    @DisplayName("Mon cas de test 0/5=0")
    @Order(3)
    public void testZeroUn() {
        // System.out.println("0/5=0 ("+testeur.divide(0, 5)+")");
        Assertions.assertEquals(0, testeur.divide(0, 5), "0/5=0 FAILED");
    }

    @Test
    @Tag("TestZero")
    @DisplayName("Mon cas de test 2/5=0")
    @Order(4)
    public void testZeroDeux() {
        // System.out.println("0/5=0 ("+testeur.divide(0, 5)+")");
        Assertions.assertEquals(0, testeur.divide(2, 5), "2/5=0 FAILED");
    }

    // @Disabled
    @Test
    @Tag("TestZero")
    @Tag("TestPlante")
    @DisplayName("Mon cas plante")
    @Order(5)
    public void testBindon() {
        Assertions.assertEquals(2, testeur.divide(2, 5), "2/5=2 FAILED");
    }

    // @Disabled
    @Test
    @DisplayName("2 cas de test 10/5=2 et 10/3=3")
    @Order(2)
    public void testPlusieurs() {
        System.out.println("Plusieurs tests similaires");
        Assertions.assertAll("Divisions classiques",
                () -> Assertions.assertTrue(testeur.divide(10, 5) == 2, "10/5=2 FAILED"),
                () -> Assertions.assertEquals(testeur.divide(10, 3), 3, "10/3=3 FAILED"));
    }

    // @Disabled
    @Test
    @DisplayName("Mon cas de test Exception division / 0")
    @Tag("exception")
    @Order(10)
    public void testPlante() {
        System.out.println("ça va planter");
        Assertions.assertThrows(java.lang.ArithmeticException.class, () -> testeur.divide(5, 0));
    }
}
