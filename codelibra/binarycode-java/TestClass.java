import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TestClass {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N;
        int visited[] = new int[100000];
        N = in.nextInt();
        for (int i = 0; i < N; i++) {
            String string = in.next();
            String reserve = in.next();
            char[] chars = reserve.toCharArray();
            Arrays.sort(chars);
            reserve = new String(chars);
            char[] ansString = string.toCharArray();
            for (int j = 0; j < string.length(); ++j) {
                for (int j2 = 0; j2 < reserve.length(); j2++) {
                    if (reserve.charAt(j2) < string.charAt(j) && visited[j2] == 0) {
                        ansString[j] = reserve.charAt(j2);
                        visited[j2] = 1;
                    }
                }
            }
            out.println(ansString.toString());
        }
    }
}

class InputReader {
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

}