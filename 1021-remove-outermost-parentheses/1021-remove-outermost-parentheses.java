class Solution {
    public String removeOuterParentheses(String s) {
        int n = s.length();
        Stack<Character> st = new Stack<>();
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                if (!st.isEmpty()) {
                  ans.append('(');
                }
                st.push(s.charAt(i));
            } else if (s.charAt(i) == ')') {
                st.pop();
                if (!st.isEmpty()) {
                   ans.append(')');
                }
            }
        }
        return ans.toString();
    }
}