# [Platinum V] 홍준이의 친위대 - 3948 

[문제 링크](https://www.acmicpc.net/problem/3948) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

조합론(combinatorics), 다이나믹 프로그래밍(dp), 수학(math)

### 문제 설명

<p>The king has guards of all different heights. Rather than line them up in increasing or decreasing height order, he wants to line them up so each guard is either shorter than the guards next to him or taller than the guards next to him (so the heights go up and down along the line). For example, seven guards of heights 160, 162, 164, 166, 168, 170 and 172 cm. could be arranged as:</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/kud1.png" style="height:123px; width:358px"></p>

<p>or perhaps:</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/kud2.png" style="height:139px; width:366px"></p>

<p>The king wants to know how many guards he needs so he can have a different up and down order at each changing of the guard for rest of his reign. To be able to do this, he needs to know for a given number of guards, n, how many different up and down orders there are:</p>

<p>For example, if there are four guards: 1, 2, 3, 4 can be arranged as:</p>

<p>1324, 2143, 3142, 2314, 3412, 4231, 4132, 2413, 3241, 1423</p>

<p>For this problem, you will write a program that takes as input a positive integer n, the number of guards and returns the number of up and down orders for n guards of differing heights.</p>

### 입력 

 <p>The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. Each data set consists of single line of input containing one integer, n (1 <= n <= 20), is the number of guards of differing heights.</p>

### 출력 

 <p>For each data set there is one line of output. It contains the number of up and down orders for the n guards.</p>

