import java.util.Arrays;

public class Solution {

    private int maxLength = 0;

    public int solution(int[] citations) {
        this.maxLength = citations.length;
        int[] sorted = Arrays.stream(citations).sorted().toArray();
        for (int i = 0; i < maxLength; i++) {
            if (sorted[i] >= getLength(i)) {
                return getLength(i);
            }
        }
        return 0;
    }

    private int getLength(int i) {
        return maxLength - i;
    }
}
