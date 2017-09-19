import java.math.BigInteger;
import java.util.Scanner;

/*
* Status: TLE
*/

class P495 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        BigInteger fibonacciAtN;
        while (scanner.hasNextInt()) {
            n = scanner.nextInt();
            fibonacciAtN = findFibonacciAt(n);
            System.out.println("The Fibonacci number for " + n + " is " + fibonacciAtN);
        }
        scanner.close();
    }

    static BigInteger findFibonacciAt(int n) {
        BigInteger f0 = new BigInteger("0");
        BigInteger f1 = new BigInteger("1");
        BigInteger f2 = f1.add(f0);

        if (n == 0)
            return f0;
        else if (n == 1)
            return f1;
        else  {
            int count = 2;
            while (count < n) {
                f0 = new BigInteger(f1.toString());
                f1 = new BigInteger(f2.toString());
                f2 = f1.add(f0);
                count++;
            }
            return f2;
        }
    }
}
