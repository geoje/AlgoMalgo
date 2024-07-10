package BOJ.category.pq;

import java.util.*;

record Lecture(int start, int end) {}

public class P11000 {
    
    public static void main(String[] args) {
        // Init
        Scanner in = new Scanner(System.in);
        
        // Read
        int n = in.nextInt();
        int[] s = new int[n];
        int[] t = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = in.nextInt();
            t[i] = in.nextInt();
        }

        // Write
        int result = solution(n, s, t);
        System.out.printf("%d%n", result);
        in.close();
    }

    static int solution(int n, int[] s, int[] t) {
        int result = 0;
        List<Lecture> list = new ArrayList<>();
        PriorityQueue<Lecture> pq = new PriorityQueue<Lecture>((a, b) -> a.end() - b.end());

        for (int i = 0; i < n; i++) list.add(new Lecture(s[i], t[i]));
        list.sort((a, b) -> a.start() - b.start());
        
        for (var l : list) {
            pq.add(l);

        }

        

        return result;
    }
}