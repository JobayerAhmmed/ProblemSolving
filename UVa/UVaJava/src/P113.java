import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Status: Incomplete
 */
public class P113 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, k;
        BigInteger p;
        BigDecimal decimalP;
        BigDecimal calculatedK;
        double exponent;
        while (scanner.hasNextInt()) {
            n = scanner.nextInt();
            p = scanner.nextBigInteger();
//            exponent = BigDecimal.ONE.divide(BigDecimal.valueOf(n), 100, BigDecimal.ROUND_HALF_UP);
            exponent = 1.0 / n;
            decimalP = new BigDecimal(p);
//            calculatedK = decimalP.pow(exponent);
//
//            k = 1;
//            q = BigInteger.valueOf(k).pow(n);
//            while (!p.equals(q)) {
//                k++;
//                q = BigInteger.valueOf(k).pow(n);
//            }
            System.out.println(exponent);
        }
        scanner.close();
    }
}
