import java.util.Scanner;

/**
 * Status: Incomplete
 * Towers of Hanoi
 */
class P254 {

    public static long moves = 0;

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int n, m=0;
        char source = 'A', dest = 'C', temp = 'B';

        do {
            n = scanner.nextInt();
//            m = scanner.nextInt();
//            System.out.println(n + " " + m);

            countHanoiMoves(n, source, dest, temp);
            System.out.println("Total moves: " + moves);
        } while (!(n==0 && m==0));

        scanner.close();
    }

    public static void countHanoiMoves(int n, char source, char dest, char temp) {
        if (n > 0) {
            countHanoiMoves(n-1, source, temp, dest);
            moves++;
//            System.out.println(n + " " + source + " -> " + dest);
            countHanoiMoves(n-1, temp, dest, source);
        }
    }
}
