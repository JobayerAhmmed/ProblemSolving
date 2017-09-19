import java.math.BigInteger;
import java.util.Scanner;

/*
* Status: AC
*/

class P623 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            BigInteger factorial = findFactorialOf(n);
            System.out.println(n + "!");
            System.out.println(factorial);
        }

        scanner.close();
    }

    static BigInteger findFactorialOf(int n) {
        BigInteger factorial = BigInteger.valueOf(1);
        for (int i = 2; i <= n; i++)
            factorial = factorial.multiply(BigInteger.valueOf(i));
        return factorial;
    }
}
