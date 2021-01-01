import java.util.*;
import java.io.*;

public class TaskB {
    public static InputReader in;
    public static PrintWriter out;
    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out);
        int n = in.nextInt();
        String s = in.next();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = (s.charAt(i) - '0');
        }
        for (int i = 0; i < n - 1; i++) {
            a[i] = Math.abs(a[i] - a[i + 1]);
        }
        n -= 2;
        boolean hasOne = false;
        for (int i = 0; i <= n; i++) {
            if (a[i] == 1) hasOne = true;
        }
        int[] prime2 = new int[n + 1];
        for (int i = 2; i <= n; i *= 2) {
            for (int j = i; j <= n; j += i) {
                prime2[j] += 1;
            }
        }
        int[] coefParity = new int[n + 1];
        coefParity[0] = 1;
        coefParity[n] = 1;
        int cur = 0;
        for (int i = 1; i <= n / 2; i++) {
            cur += prime2[(n + 1 - i)] - prime2[i];
            if (cur > 0) {
                coefParity[i] = 0;
                coefParity[n - i] = 0;
            } else {
                coefParity[i] = 1;
                coefParity[n - i] = 1;
            }
        }
        if (hasOne) {
            int ans = 0;
            for (int i = 0; i <= n; i++) {
                if ((a[i] & 1) == 0) continue;
                ans ^= coefParity[i];
            }
            out.println(ans);
        } else {
            int ans = 0;
            for (int i = 0; i <= n; i++) {
                if (a[i] == 0) continue;
                ans ^= coefParity[i];
            }
            out.println(ans * 2);
        }
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