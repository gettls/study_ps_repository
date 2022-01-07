import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static int[][] map;

    private static final int[] dx = {0, 0, -1, 1};
    private static final int[] dy = {-1, 1, 0, 0};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine().trim());

        final int n = Integer.parseInt(st.nextToken());
        final int m = Integer.parseInt(st.nextToken());
        final int t = Integer.parseInt(st.nextToken());

        map = new int[n][];

        for (int i = 0; i < n; i++) {
            map[i] = Arrays.stream(br.readLine().trim().split(" "))
                .mapToInt(Integer::parseInt)
                .toArray();
        }

        int result = bfs(t);
        if (result == -1) {
            System.out.println("Fail");
            return;
        }
        System.out.println(result);
    }

    private static int bfs(int limitTime) {
        Queue<Player> q = new ArrayDeque<>();
        boolean[][][] visited = new boolean[map.length][map[0].length][2];

        visited[0][0][0] = true;
        q.offer(new Player(0, 0, 0, false));
        while (!q.isEmpty()) {
            Player player = q.poll();

            if (player.getStep() > limitTime) {
                continue;
            }

            if (isGoal(player)) {
                return player.getStep();
            }

            for (int i = 0; i < 4; i++) {
                int nx = player.getX() + dx[i];
                int ny = player.getY() + dy[i];

                if (canMove(nx, ny)) {
                    if (player.isGram()) {
                        if (!visited[ny][nx][1]) {
                            visited[ny][nx][1] = true;
                            q.offer(new Player(nx, ny, player.getStep() + 1, true));
                        }
                    } else {
                        if (!visited[ny][nx][0]) {
                            if (map[ny][nx] == 2) {
                                visited[ny][nx][0] = true;
                                q.offer(new Player(nx, ny, player.getStep() + 1, true));
                            } else if (map[ny][nx] == 0) {
                                visited[ny][nx][0] = true;
                                q.offer(new Player(nx, ny, player.getStep() + 1, false));
                            }
                        }
                    }
                }
            }
        }

        return -1;
    }

    private static boolean canMove(int x, int y) {
        return 0 <= x && x < map[0].length && 0 <= y
            && y < map.length;
    }

    private static boolean isGoal(Player player) {
        return player.getX() == (map[0].length - 1) && player.getY() == (map.length - 1);
    }

    private static class Player {

        private final int x;
        private final int y;
        private final boolean gram;
        private final int step;

        public Player(int x, int y, int step, boolean gram) {
            this.x = x;
            this.y = y;
            this.gram = gram;
            this.step = step;
        }

        public int getStep() {
            return step;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        public boolean isGram() {
            return gram;
        }
    }
}