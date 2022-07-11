# [Gold IV] 녹색 옷 입은 애가 젤다지? - 4485 

[문제 링크](https://www.acmicpc.net/problem/4485) 

### 성능 요약

메모리: 3532 KB, 시간: 12 ms

### 분류

다익스트라(dijkstra), 그래프 이론(graphs)

### 문제 설명

<p>You are working on the team assisting with programming for the Mars rover. To conserve energy, the rover needs to find optimal paths across the rugged terrain to get from its starting location to its final location. The following is the first approximation for the problem.</p>

<p>N x N square matrices contain the expenses for traversing each individual cell. For each of them, your task is to find the minimum-cost traversal from the top left cell [0][0] to the bottom right cell [N-1][N-1]. Legal moves are up, down, left, and right; that is, either the row index changes by one or the column index changes by one, but not both.</p>

### 입력 

 <p>Each problem is specified by a single integer between 2 and 125 giving the number of rows and columns in the N x N square matrix. The file is terminated by the case N = 0.</p>

<p>Following the specification of N you will find N lines, each containing N numbers. These numbers will be given as single digits, zero through nine, separated by single blanks.</p>

### 출력 

 <p>Each problem set will be numbered (beginning at one) and will generate a single line giving the problem set and the expense of the minimum-cost path from the top left to the bottom right corner, exactly as shown in the sample output (with only a single space after “Problem” and after the colon).</p>

