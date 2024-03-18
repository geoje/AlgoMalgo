package BOJ.category.pq;

import java.io.*;
import java.util.StringTokenizer;

public class P11000 {
    public static void main(String[] args) throws IOException {
        // Init
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // Read
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());

        // Write
        bw.write(String.format("%s", solution(n)));
        bw.flush();
    }

    static int solution(int arg) {
        return arg;
    }
}