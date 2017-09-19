import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/**
 * Status: WA
 */
public class P482 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberOfCases = scanner.nextInt();

        scanner.nextLine();
        for (int i = 0; i < numberOfCases; i++) {
            scanner.nextLine();
            String xLine = scanner.nextLine();
            String xPermutedLine = scanner.nextLine();

            String[] xStrings = xLine.split(" ");
            String[] xPermutedStrings = xPermutedLine.split(" ");

            String[] xSorted = xStrings.clone();

            Arrays.sort(xSorted, new Comparator<String>() {
                @Override
                public int compare(String o1, String o2) {
                    return Integer.valueOf(o1).compareTo(Integer.valueOf(o2));
                }
            });
            Arrays.sort(xPermutedStrings, new Comparator<String>() {
                @Override
                public int compare(String o1, String o2) {
                    return new BigDecimal(o1).compareTo(new BigDecimal(o2));
                }
            });

            int n = xStrings.length;
//            for (int p = 0; p < n; p++) {
//                System.out.print(xSorted[p] + " ");
//            }
//            System.out.println();
//            for (int p = 0; p < n; p++) {
//                System.out.print(xPermutedStrings[p] + " ");
//            }

            for (int p = 0; p < n; p++) {
                String  current = xStrings[p];
                int index = Integer.parseInt(current) - 1;
                System.out.println(xPermutedStrings[index]);
            }
            System.out.println();
        }
        scanner.close();
    }
}
