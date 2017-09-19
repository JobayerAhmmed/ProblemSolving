import java.util.Scanner;

/**
 * Status: AC
 */
public class P483 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String line;
        while (scanner.hasNextLine()) {
            line = scanner.nextLine();
            String [] words = line.split("\\s+");

            int n = words.length;
            System.out.print(new StringBuilder(words[0]).reverse().toString());

            for (int i = 1; i < n; i++) {
                System.out.print(" " + new StringBuilder(words[i]).reverse().toString());
            }
            System.out.println();
        }
        scanner.close();
    }
}
