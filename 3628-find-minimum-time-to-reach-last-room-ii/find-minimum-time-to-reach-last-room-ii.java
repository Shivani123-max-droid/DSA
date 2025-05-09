import java.util.*;

class Solution {
    public int minTimeToReach(int[][] moveTime) {
        int n = moveTime.length;
        int m = moveTime[0].length;
        int[][] dist = new int[n][m];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        dist[0][0] = 0;

        // Directions: right, down, left, up
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[]{0, 0, 0, 1}); // {time, x, y, moveDuration}

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int time = current[0], x = current[1], y = current[2], moveDuration = current[3];

            // If we've reached the destination
            if (x == n - 1 && y == m - 1) {
                return time;
            }

            // Explore adjacent rooms
            for (int[] dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newMoveDuration = (moveDuration == 1) ? 2 : 1;
                    int newTime = Math.max(time, moveTime[nx][ny]) + moveDuration;
                    if (newTime < dist[nx][ny]) {
                        dist[nx][ny] = newTime;
                        pq.offer(new int[]{newTime, nx, ny, newMoveDuration});
                    }
                }
            }
        }

        return -1; // In case there's no path
    }
}
