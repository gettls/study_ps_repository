import java.util.Stack;

public class Solution {

  public int solution(String s) {
    int length = s.length();
    Stack<Character> stack = new Stack<>();
    stack.push(s.charAt(0));
    for (int i = 1; i < length; i++) {
      Character ch = s.charAt(i);
      if (!stack.isEmpty() && stack.peek() == ch) {
        stack.pop();
      } else {
        stack.push(ch);
      }
    }
    return stack.isEmpty() ? 1 : 0;
  }
}
