import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        int[][] map = new int[n][];

        for (int i = 0; i < n; i++) {
            map[i] = Arrays.stream(br.readLine().trim().split("")).mapToInt(Main::parseInt)
                    .toArray();
        }

        int answerH = 0, answerW = 0;
        for (int i = 0; i < n; i++) {
            answerW += check(map[i]);
            answerH += check(wtoh(map, i));
        }
        System.out.print(answerW + " " + answerH);
    }

    private static int[] wtoh(int[][] map, int col) {
        int[] w = new int[map.length];
        for (int i = 0; i < map.length; i++) {
            w[i] = map[i][col];
        }
        return w;
    }

    private static int check(int[] row) {
        int count = 0;
        int answer = 0;
        for (int j : row) {
            if (j == 1) {
                count++;
            } else {
                if (2 <= count) {
                    answer++;
                }
                count = 0;
            }
        }
        if (2 <= count) {
            answer++;
        }
        return answer;
    }

    private static int parseInt(String s) {
        if (s.equals(".")) {
            return 1;
        }
        return -1;
    }
}
