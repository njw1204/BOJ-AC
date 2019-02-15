import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String x = sc.nextLine();
        long ans = 0;
        
        for (int i = 0; i < x.length(); i++) {
            ans *= 26;
            ans += x.charAt(i) - 'A' + 1;
        }
        
        System.out.println(ans);
    }
}