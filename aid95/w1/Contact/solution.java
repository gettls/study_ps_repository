import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    private static final String FIND_REG = "(100+1+|01)+";

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine().trim());

        for (int i = 0; i < t; i++) {
            if (br.readLine().trim().matches(FIND_REG)) {
                System.out.println("YES");
                continue;
            }
            System.out.println("NO");
        }
    }
}
