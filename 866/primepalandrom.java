
import java.util.ArrayList;
import java.util.Collections;

class primepalandrom {

      public int arraytonumber(ArrayList<Integer> ans) {
        int number = 0;
        for (int i = 0; i < ans.size(); i++) {
            number = number * 10 + ans.get(i);
        }
        return number;
    }
    //number to array
    public ArrayList<Integer> numbertoarray(int n) {
        ArrayList<Integer> ans = new ArrayList<>();
        while (n != 0) {
            int rem = n % 10;
            ans.add(rem);
            n = n / 10;
        }
        Collections.reverse(ans);
        int mid = (ans.size() - 1) / 2;
        int high = ans.size() - 1;
        for (int i = 0; i <= mid; i++) {
            ans.set(high, ans.get(i));
            high--;
        }

        return ans;

    }
    //left half plus one
    public int leftplus(int n) {
        ArrayList<Integer> ans = numbertoarray(n);
        int mid = (ans.size() - 1) / 2;
        int lefthalf = 0;
        for (int i = 0; i <= mid; i++) {
            lefthalf = lefthalf * 10 + ans.get(i);
        }
        lefthalf++;
        int i = mid;
        while (i>=0 && lefthalf != 0) {
            int rem = lefthalf % 10;
            ans.set(i, rem);
            lefthalf = lefthalf / 10;
            i--;
        }
        if(i!=0){
            ans.add(0);
            for(int j=ans.size()-1;j>=1;j--){
                ans.set(j,ans.get(j-1));
            }
            ans.set(0,lefthalf);
        }

        int number = arraytonumber(ans);
        return number;

    }
    //prime check
    public boolean isprime(int n){
        boolean found = false;
        for(int i= 2;i*i<=n;i++){
            if(n%i==0){
                found = true;
                break;
            }
        }
        return found;
    }
    //main fun
    public int primePalindrome(int n) {
        //special case
        if (n == 1) {
            return n + 1;
        }
        if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11) {
            return n;
        }

        //less then 11
        while (n <= 11) {
            boolean found = false;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    found = true;
                    break;
                }
            }
            if (found) {
                n++;
            } else {
                return n;
            }
        }

        //less then 101
        if (n <= 101) {
            return 101;
        }

        //greater then 
        ArrayList<Integer> ans = numbertoarray(n);
        int number = arraytonumber(ans);
        if (number < n) {
            number = leftplus(number);
            ans = numbertoarray(number);
            number = arraytonumber(ans);
        }
        //check prime
        boolean notprime = isprime(number);
        while (notprime != false) {
            number = leftplus(number);
            ans = numbertoarray(number);
            number = arraytonumber(ans);
            notprime = isprime(number);
        }
        return number;

    }
}
