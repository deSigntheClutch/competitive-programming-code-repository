import java.util.*;
import java.io.*;

public class TaskA {
    public static InputReader in;
    public static PrintWriter out;
    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out);
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int[] ans = new int[n];
        for (int i = 0; i < 31; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (((a[j] >> i) & 1) == 1) sum++;
            }
            for (int j = 0; j < n; j++) {
                if (0 == sum - ((a[j] >> i) & 1)) {
                    ans[j] |= (1 << i);
                }
            }
        }
        int idx = -1;
        int val = -1;
        for (int i = 0; i < n; i++) {
            if (val < ans[i]) {
                val = ans[i];
                idx = i;
            }
        }
        out.print(a[idx]);
        for (int i = 0; i < n; i++) {
            if (i == idx) continue;
            out.print(" " + a[i]);
        }
        out.println();
        out.close();
    }
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public Long nextLong() {
            return Long.parseLong(next());
        }
        public Double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}
