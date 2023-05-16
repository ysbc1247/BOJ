# [Gold II] Mural - 23987 

[문제 링크](https://www.acmicpc.net/problem/23987) 

### 성능 요약

메모리: 87844 KB, 시간: 240 ms

### 분류

애드 혹

### 문제 설명

<p>Thanh wants to paint a wonderful mural on a wall that is <b>N</b> sections long. Each section of the wall has a <i>beauty score</i>, which indicates how beautiful it will look if it is painted. Unfortunately, the wall is starting to crumble due to a recent flood, so he will need to work fast!</p>

<p>At the beginning of each day, Thanh will paint one of the sections of the wall. On the first day, he is free to paint any section he likes. On each subsequent day, he must paint a new section that is next to a section he has already painted, since he does not want to split up the mural.</p>

<p>At the end of each day, one section of the wall will be destroyed. It is always a section of wall that is adjacent to only one other section and is unpainted (Thanh is using a waterproof paint, so painted sections can't be destroyed).</p>

<p>The <i>total beauty</i> of Thanh's mural will be equal to the sum of the beauty scores of the sections he has painted. Thanh would like to guarantee that, no matter how the wall is destroyed, he can still achieve a total beauty of at least B. What's the maximum value of B for which he can make this guarantee?</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <b>T</b>. <b>T</b> test cases follow. Each test case starts with a line containing an integer <b>N</b>. Then, another line follows containing a string of <b>N</b> digits from 0 to 9. The i-th digit represents the beauty score of the i-th section of the wall.</p>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code>, where <code>x</code> is the test case number (starting from 1) and <code>y</code> is the maximum beauty score that Thanh can guarantee that he can achieve, as described above.</p>

