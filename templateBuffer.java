import java.io.*;
import java.util.StringTokenizer;

public class templateBuffer {
    public static void main(String[] args) throws IOException {
        // Init
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // Read
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());

        // Write
        int result = solution(n);
        bw.write(String.format("%s", result));
        bw.flush();
    }

    static int solution(int n) {
        return n;
    }
}