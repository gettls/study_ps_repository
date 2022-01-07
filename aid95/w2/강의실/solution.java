import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class Main {

    private static final ScheduleBoard scheduleBoard = new ScheduleBoard();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine().trim());
            scheduleBoard.addLecture(new Lecture(
                Integer.parseInt(st.nextToken()),
                Integer.parseInt(st.nextToken()),
                Integer.parseInt(st.nextToken())));
        }
        System.out.print(scheduleBoard.rooms());
    }

    public static class ScheduleBoard {

        private static final List<Lecture> lectures = new ArrayList<>();

        public void addLecture(Lecture lecture) {
            lectures.add(lecture);
        }

        public int rooms() {
            List<Lecture> sortedLectures = lectures.stream().sorted().collect(Collectors.toList());
            PriorityQueue<Lecture> pq = new PriorityQueue<>(endLectureComparator());

            int result = 0;
            for (Lecture lecture : sortedLectures) {
                if (pq.size() > 0) {
                    if (pq.peek().end > lecture.start) {
                        result++;
                    } else {
                        pq.poll();
                    }
                } else {
                    result++;
                }
                pq.offer(lecture);
            }
            return result;
        }

        private Comparator<Lecture> endLectureComparator() {
            return (o1, o2) -> {
                if (o1.end != o2.end) {
                    return o1.end - o2.end;
                }
                return o1.start - o2.start;
            };
        }
    }

    public static class Lecture implements Comparable<Lecture> {

        private final int no;
        private final int start;
        private final int end;

        public Lecture(int no, int start, int end) {
            this.no = no;
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Lecture o) {
            if (this.start != o.start) {
                return this.start - o.start;
            }
            return this.end - o.end;
        }
    }
}