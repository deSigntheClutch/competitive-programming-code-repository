import java.util.*;
import java.io.*;

public class TaskA {
    public static InputReader in;
    public static PrintWriter out;
    static int n;
    static int m;
    static char[][] a;
    static int[][] dp;

    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out);
        n = in.nextInt();
        m = in.nextInt();
        a = new char[n + 5][m + 5];
        dp = new int[n + 5][m + 5];
        for (int i = 0; i < n; i++) {
            a[i] = in.next().toCharArray();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = 100000000;
            }
        }
        dp[0][0] = (a[0][0] == '#') ? 1 : 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] != 100000000) continue;
                if (a[i][j] == '#') {
                    if (i - 1 >= 0 && a[i - 1][j] == '#') dp[i][j] = Math.min(dp[i][j], dp[i - 1][j]);
                    if (i - 1 >= 0 && a[i - 1][j] == '.') dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + 1);
                    if (j - 1 >= 0 && a[i][j - 1] == '#') dp[i][j] = Math.min(dp[i][j], dp[i][j - 1]);
                    if (j - 1 >= 0 && a[i][j - 1] == '.') dp[i][j] = Math.min(dp[i][j], dp[i][j - 1] + 1);
                } else {
                    if (i - 1 >= 0 && a[i - 1][j] == '#') dp[i][j] = Math.min(dp[i][j], dp[i - 1][j]);
                    if (i - 1 >= 0 && a[i - 1][j] == '.') dp[i][j] = Math.min(dp[i][j], dp[i - 1][j]);
                    if (j - 1 >= 0 && a[i][j - 1] == '#') dp[i][j] = Math.min(dp[i][j], dp[i][j - 1]);
                    if (j - 1 >= 0 && a[i][j - 1] == '.') dp[i][j] = Math.min(dp[i][j], dp[i][j - 1]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                out.print(dp[i][j] + " ");
            }
            out.println();
        }
        out.println(dp[n - 1][m - 1]);
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

