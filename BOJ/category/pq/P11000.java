package BOJ.category.pq;

import java.util.Scanner;

public class p11000 {
    public static void main(String[] args) {
        // Init
        Scanner in = new Scanner(System.in);
        
        // Read
        int n = in.nextInt();

        // Write
        int result = solution(n);
        System.out.printf("%d%n", result);
        in.close();
    }

    static int solution(int n) {
        return n;
    }
}
