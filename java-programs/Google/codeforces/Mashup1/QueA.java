package Mashup1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class QueA {
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
        int N = in.nextInt();
        int visited[] = new int[1000005];

        int current = 0, total = 0;
        for (int i = 0; i < N; i++) {
            String symbol = in.next();
            String person = in.next();

            int index = Integer.parseInt(person);

            if (symbol.charAt(0) == '+') {
                current = current + 1;
                if (current > total)
                    total = current;
                visited[index] = 1;
            } else {
                if (visited[index] == 1) {
                    current = current - 1;
                } else {
                    total = total + 1;
                }
            }
        }
        out.print(total);
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