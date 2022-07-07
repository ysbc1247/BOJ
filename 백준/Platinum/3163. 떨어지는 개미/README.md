# [Platinum V] 떨어지는 개미 - 3163 

[문제 링크](https://www.acmicpc.net/problem/3163) 

### 성능 요약

메모리: 4508 KB, 시간: 380 ms

### 분류

애드 혹(ad_hoc), 정렬(sorting)

### 문제 설명

<p>N ants are on a stick where some facing right and some facing left. You can assume all ants are so tiny compared to the distance between them, that they can be considered moving points without volume. From a start signal, all ants begin to march in whichever direction they are currently facing. All ants march in a constant speed such as 1mm per second. If two different ants collide on a point, then they bounce and reverse their previous direction. Bouncing and reversing movement does not take any time. When an ant is reaching the end of stick, that ant falls off from the stick and down to the ground. We assume the stick is floating over a floor. </p>

<p>Initially all ants are placed in distinct positions, that means no two ants are placed at a same point of the stick. We represent each ant using a signed integer, called an ant ID. The sign of the ant ID denotes the facing direction in the intial state, where '-'('+') means facing the left (right). The absolute value of the ant ID is one of N integers 1, 2, ⋯ , N. So the absolute values of the ant ID are all distinct. In Figure 1, you can see that there are 6 ants with the signed ID {+4, +5, -1, -3, -2, +6} whose corresponding positions are  {5,8,19,22,24,25} on a long stick with length L = 30. The arrow assigned for each ant shows the facing direction in the initial state. The position of the left end is 0, and the position of the right end is 30. It is easy to see that the ant of ID +6 will arrive at the right end of the stick at time t = 5, and then it falls off the stick at t =6. </p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/ant1.png" style="height:184px; opacity:0.9; width:646px"></p>

<p>You are given information of ants before marching; ant ID and the corresponding position on a stick. If two ants are falling simultaneously from both sides (left and right), then we will break the tie of falling order such that the ant with smaller ID number falls off slightly earlier than the other. Let us give one example for this case. In Figure 2, if two ants with ID = {-1, +2} will reach each end simultaneously, the ant of ID = -1 will fall off earlier than the ant of ID = +2 since -1 < +2. So the falling sequence of four ants in Figure 2 is 〈-1, 2, 4, 3〉, i.e., the ant of ID = -1 falls off the first and the ant of ID = 3 falls off the last. </p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/ant2.png" style="height:156px; opacity:0.9; width:539px"></p>

<p>Given a positive integer 1 ≤ k ≤ n, you should find the k-th ant in the falling sequence, i.e., the k-th falling ant. </p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with three integer numbers N, L and k, where N is the total number of the ants, L is the length of the stick, and k is the falling order we are concerned with k ≤ N. Each line in the following has two integer numbers, p<sub>i</sub> and a<sub>i</sub>, where p<sub>i</sub> is the initial position of the ant a<sub>i</sub>. Note that p<sub>i</sub> is increasing such as p<sub>i</sub> < p<sub>i+1</sub> . Note that 1 ≤ p<sub>i</sub> ≤ L - 1, 3 ≤ N ≤ 100,000, 10 ≤ L ≤ 5,000,000 and 1 ≤ k ≤ N. </p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain the ID number of the k-th falling ant from the stick among all N ants. You should not write ‘+’ symbol if the ant ID is positive. </p>

