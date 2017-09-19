import java.util.Scanner;

/**
 * Status: Incomplete
 */
public class P466 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        String[] original;
        String[] transformed;
        int count = 0;
        while (true) {
            n = scanner.nextInt();
            original = new String[n];
            transformed = new String[n];
            count++;
//            System.out.println(n);
            scanner.nextLine();
            for (int i = 0; i < n; i++) {
                original[i] = scanner.next();
                transformed[i] = scanner.next();
//                System.out.println(original + " " + transformed);
            }

            System.out.println("Pattern " + count + " was ");
        }
//        scanner.close();
    }
}
