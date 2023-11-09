import org.junit.Assert;
import org.junit.Test;

public class TestsTd1 {
    @Test
    public void oddOrPosTest1() {
        Assert.assertEquals(3, Td1.oddOrPos(new int[] { -3, -2, 0, 1, 4 }));
    }
}
