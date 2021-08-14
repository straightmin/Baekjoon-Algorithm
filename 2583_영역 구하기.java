import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Collections;

public class Main{
	static int n, m;
	static boolean[][] map;
	static int[] dx = {0,0,-1,1};
	static int[] dy = {-1,1,0,0};
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		map = new boolean[n][m];
		
		while(k-- != 0) {
			int x1, y1, x2, y2;
			st = new StringTokenizer(br.readLine());
			x1 = Integer.parseInt(st.nextToken());
			y1 = Integer.parseInt(st.nextToken());
			x2 = Integer.parseInt(st.nextToken());
			y2 = Integer.parseInt(st.nextToken());
			for(int i = y1; i < y2; i++) {
				for(int j = x1; j < x2; j++) {
					map[i][j] = true;
				}
			}
		}
		
		int count = 0;
		LinkedList<Integer> arr = new LinkedList<>();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(map[i][j]) continue;
				arr.add(bfs(i, j)); count++;
			}
		}
		
		System.out.println(count);
		
		Collections.sort(arr);
		StringBuilder sb = new StringBuilder();
		for(int num:arr) {
			sb.append(num+" ");
		}
		System.out.println(sb);
		
	}
	
	static boolean in(int y, int x) {
		return (y >= 0 && y < n && x >= 0 && x < m);
	}
	
	static int bfs(int y, int x) {
		class Pair{
			int y, x;
			Pair(int y, int x){
				this.y = y;
				this.x = x;
			}
		}
		
		Queue<Pair> q = new LinkedList<>();
		q.offer(new Pair(y, x));
		map[y][x] = true;
		int area = 1;
		
		while(!q.isEmpty()) {
			Pair p = q.poll();
			for(int i = 0; i < 4; i++) {
				y = dy[i] + p.y;
				x = dx[i] + p.x;
				
				if(!in(y, x)) continue;
				if(map[y][x]) continue;
				
				map[y][x] = true;
				q.offer(new Pair(y, x));
				area++;
			}
		}
		
		return area;
	}
}
