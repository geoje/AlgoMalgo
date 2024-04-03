import java.util.*;

public class p5619 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Integer> list = new ArrayList<>();
        for (int i = scanner.nextInt(); i > 0; i--) {
            list.add(scanner.nextInt());
        }
        scanner.close();
        
        List<Integer> answer = new ArrayList<>();
        Collections.sort(list);
        int maxIndex = Math.min(4, list.size());
        for (int i = 0; i < maxIndex; i++) {
            for (int j = 0; j < maxIndex; j++) {
                if (i == j) continue;
                String result =
                    list.get(i).toString() +
                    list.get(j).toString();
                answer.add(Integer.parseInt(result));
            }
        }
        Collections.sort(answer);

        System.out.println(answer.get(2));
    }
}
