class Solution {
    List<String> ans = new ArrayList<>();

    boolean isvalid(String curr) {
        int count = 0;
        for (char ch : curr.toCharArray()) {
            if (ch == '(') {
                count++;
            } else {
                count--;
                if (count < 0) {
                    return false;
                }
            }
        }
        return count == 0;
    }

    void solve(String curr, int n) {
        if (curr.length() == 2 * n) {
            if (isvalid(curr)) {
                ans.add(curr);
            }
            return;
        }

        if(curr.length()==1){
           if(curr.charAt(0)==')'){
            return ;
           }
        }

        solve(curr + "(", n);
        solve(curr + ")", n);
    }

    public List<String> generateParenthesis(int n) {
        String curr = "";
        solve(curr, n);
        return ans;

    }
}