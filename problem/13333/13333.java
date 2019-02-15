
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	public static void main(String[] argv){
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int q = -1;
		ArrayList<Integer> arr = new ArrayList<Integer>();
		for(int i=1;i<n+1;i++){
			arr.add(s.nextInt());
		}
		
		arr.sort(new Comparator<Integer>(){
			@Override
			public int compare(Integer arg0, Integer arg1) {
				return arg1.compareTo(arg0);
			}
		});
		
		for(int i=0;i<n;i++){
			if(arr.get(i) == i+1){
				q = i+1;
				break;
			}
			if(arr.get(i) < i+1){
				q = i;
				break;
			}
			if(i==n-1) q = n;
		}
		
		System.out.println(q);
	}
}
