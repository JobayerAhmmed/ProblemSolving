import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/*
* Status: AC
*/
class P394 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberOfArray = scanner.nextInt();
        int numberOfReference = scanner.nextInt();
        String[] nameOfArrays = new String[numberOfArray];
        int[] baseAddresses = new int[numberOfArray];
        int[] sizesInByte = new int[numberOfArray];
        int[] numberOfDimensions = new int[numberOfArray];
        int[][] pairOfBounds = new int[numberOfArray][];

//        System.out.println(numberOfArray + " " + numberOfReference);
        for (int i = 0; i < numberOfArray; i++) {
            nameOfArrays[i] = scanner.next();
            baseAddresses[i] = scanner.nextInt();
            sizesInByte[i] = scanner.nextInt();
            numberOfDimensions[i] = scanner.nextInt();
            int totalBounds = numberOfDimensions[i]*2;
            pairOfBounds[i] = new int[totalBounds];

//            System.out.print(nameOfArray[i] + "\t" + baseAddress[i] + " " + sizeInByte[i] + " " + numberOfDimension[i] + " ");

            for (int j = 0; j < totalBounds; j++) {
                pairOfBounds[i][j] = scanner.nextInt();
//                System.out.print(pairOfBounds[i][j] + " ");
            }
//            System.out.println();
        }

        List<String> nameList = Arrays.asList(nameOfArrays);
        for (int i = 0; i < numberOfReference; i++) {
            String name = scanner.next();
            int indexOfName = nameList.indexOf(name);
            int D = numberOfDimensions[indexOfName];
            int[] indexes = new int[D];

//            System.out.print(name + "\t");
            for (int j = 0; j < D; j++) {
                indexes[j] = scanner.nextInt();
//                System.out.print(indexes[j] + " ");
            }
            System.out.print(name + "[" + indexes[0]);
            for (int j = 1; j < D; j++)
                System.out.print(", " + indexes[j]);
            System.out.print("] = ");

            int[] Ld = new int[D];
            int[] Ud = new int[D];
            int pairIndex = 0;
            for (int x = 0; x < D; x++) {
                Ld[x] = pairOfBounds[indexOfName][pairIndex];
                pairIndex++;
                Ud[x] = pairOfBounds[indexOfName][pairIndex];
                pairIndex++;
            }

            int[] Cd = new int[D];
            Cd[D-1] = sizesInByte[indexOfName];
            for (int x = D-2; x >= 0; x--) {
                Cd[x] = Cd[x+1] * (Ud[x+1] - Ld[x+1] + 1);
            }
            int CL = 0;
            int Ci = 0;
            for (int x = 0; x < D; x++) {
                CL = CL + Cd[x] * Ld[x];
                Ci = Ci + Cd[x] * indexes[x];
            }
            int C0 = baseAddresses[indexOfName] - CL;
            int physicalAddress = C0 + Ci;
            System.out.println(physicalAddress);
        }
    }
}
