import java.util.*;
import java.io.*;

public class TaskA {
    public static InputReader in;
    public static PrintWriter out;
    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out);
        int n = in.nextInt();
        String s = in.next();
        int[] sumE = new int[n + 2];
        for (int i = 0; i < n; i++) {
            sumE[i] = (s.charAt(i) == 'E' ? 1 : 0);
            if (i > 0) sumE[i] += sumE[i - 1];
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            if (i - 1 >= 0) cur += i - sumE[i - 1];
            if (i + 1 < n) cur += sumE[n - 1] - sumE[i];
            ans = Math.min(ans, cur);
        }
        out.println(ans);
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

