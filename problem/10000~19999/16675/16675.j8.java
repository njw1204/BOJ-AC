import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        char a, b, c, d;
        a = sc.next().charAt(0);
        b = sc.next().charAt(0);
        c = sc.next().charAt(0);
        d = sc.next().charAt(0);
        
        if (a == b) {
            if (a == 'R' && (c == 'P' || d == 'P')) {
                System.out.println("TK");
                return;
            }
            else if (a == 'S' && (c == 'R' || d == 'R')) {
                System.out.println("TK");
                return;
            }
            else if (a == 'P' && (c == 'S' || d == 'S')) {
                System.out.println("TK");
                return;
            }
        }
        
        if (c == d) {
            if (c == 'R' && (a == 'P' || b == 'P')) {
                System.out.println("MS");
                return;
            }
            else if (c == 'S' && (a == 'R' || b == 'R')) {
                System.out.println("MS");
                return;
            }
            else if (c == 'P' && (a == 'S' || b == 'S')) {
                System.out.println("MS");
                return;
            }
        }
        
        System.out.println("?");
    }
}