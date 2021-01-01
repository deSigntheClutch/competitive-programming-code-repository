import java.util.*;
import java.io.*;

public class CountTheBlock {
    public static InputReader in;
    public static PrintWriter out;
    static final int MOD = 998244353;

    public static void main(String[] args) {
        Integer a = 100;
        Integer b = 100;
        Integer c = 200;
        Integer d = 200;
        System.out.println(a==b);
        System.out.println(c==d);

//        in = new InputReader(System.in);
//        out = new PrintWriter(System.out);
//        int n = in.nextInt();
//        int[] ans = new int[n + 5];
//        int[] pow10 = new int[n + 5];
//        pow10[0] = 1;
//        for (int i = 1; i <= n; i++) {
//            pow10[i] = (int)((long)pow10[i - 1] * 10 % MOD);
//        }
//        ans[n] = 10;
//        for (int i = 1; i < n; i++) {
//            ans[i] = (int)((long)10 * 9 * 2 * pow10[n - 1 - i] % MOD);
//        }
//        for (int i = 1; i < n - 1; i++) {
//            ans[i] = (int)(((long)ans[i] + (long)(n - i - 1) * 10 * 9 * 9 * pow10[n - 2 - i]) % MOD);
//        }
//        for (int i = 1; i <= n; i++) {
//            out.print(ans[i] + " ");
//        }
//        out.println();
//        out.close();
    }
//    static class InputReader {
//        public BufferedReader reader;
//        public StringTokenizer tokenizer;
//        public InputReader(InputStream stream) {
//            reader = new BufferedReader(new InputStreamReader(stream), 32768);
//            tokenizer = null;
//        }
//        public String next() {
//            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
//                try {
//                    tokenizer = new StringTokenizer(reader.readLine());
//                } catch (IOException e) {
//                    throw new RuntimeException(e);
//                }
//            }
//            return tokenizer.nextToken();
//        }
//        public int nextInt() {
//            return Integer.parseInt(next());
//        }
//        public Long nextLong() {
//            return Long.parseLong(next());
//        }
//        public Double nextDouble() {
//            return Double.parseDouble(next());
//        }
//    }
}
