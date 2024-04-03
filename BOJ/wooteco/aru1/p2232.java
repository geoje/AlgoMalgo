package BOJ.wooteco.aru1;

import java.util.*;

public class p2232 {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Integer> mines = new ArrayList<>();

        for (int i = scanner.nextInt(); i > 0; i--) {
            mines.add(scanner.nextInt());
        }

        List<Integer> result = solution(mines);
        for (int v : result) {
            System.out.println(v);
        }
        scanner.close();
    }

    public static List<Integer> solution(List<Integer> mines) {
        List<Integer> answer = new ArrayList<>();
        mines.add(0, 0);
        mines.add(0);

        
        for (int i = 1; i < mines.size() - 1; i++) {
            int prev = mines.get(i - 1);
            int cur = mines.get(i);
            int next = mines.get(i + 1);

            if (prev <= cur && cur >= next) {
                answer.add(i);
            }
        }

        return answer;
    }
}
