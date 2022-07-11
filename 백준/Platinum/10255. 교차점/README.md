# [Platinum IV] 교차점 - 10255 

[문제 링크](https://www.acmicpc.net/problem/10255) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

많은 조건 분기(case_work), 기하학(geometry), 선분 교차 판정(line_intersection)

### 문제 설명

<p>Your job is to write a program of solving a simple geometry problem for finding the number of intersection points of the boundary of a rectangle and a line segment. Each edge of a given rectangle is parallel to x-axis or y-axis. (You are very lucky!) The number of intersections between them is zero, one, two, or infinity. A case of ‘infinity’ occurs in a situation in which an edge of the rectangle and the segment are overlapped partially or wholly. See the figure below which shows examples of several situations between a rectangle and a segment.</p>

<p style="text-align:center"><img alt="" src="" style="height:127px; width:632px"></p>

<p style="text-align:center">(a) Some examples of zero intersection between R and l. </p>

<p style="text-align:center"><img alt="" src="https://www.acmicpc.net/upload/images2/inter2.png" style="height:109px; width:638px"></p>

<p style="text-align:center">(b) Some examples of one intersection between R and l. </p>

<p style="text-align:center"><img alt="" src="" style="height:111px; width:640px"></p>

<p style="text-align:center">(c) Some examples of two intersections between R and l. </p>

<p style="text-align:center"><img alt="" src="" style="height:124px; width:635px"></p>

<p style="text-align:center">(d) Some examples of infinite intersections between R and l. </p>

<p style="text-align:center">Figure 1. Examples of several situations between a rectangle R(blue) and a line segment l(red).</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with four integers xmin, ymin, xmax, and ymax representing a recrangle R, where (xmin, ymin) and (xmax, ymax) represent the coordinates of the lower left corner and upper right corner of R, respectively, -10,000 ≤ xmin < xmax ≤ 10,000 and -10,000 ≤ ymin < ymax ≤ 10,000. The next line contains four integers x1, y1, x2, and y2 representing a line segment l, where (x1, y1) and (x2, y2) represent the coordinates of two end poiunts of l, respectinely, -10,000 ≤ x1, y1, x2, y2 ≤ 10,000, and the length of l is greater than zero.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain an integer representing the number of the intersections of the boundary of a rectangle and a line segment given by input. If the number of the intersections is infinity, then your program should output "4" instead. </p>

