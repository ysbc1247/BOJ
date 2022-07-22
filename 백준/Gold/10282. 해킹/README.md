# [Gold IV] 해킹 - 10282 

[문제 링크](https://www.acmicpc.net/problem/10282) 

### 성능 요약

메모리: 5136 KB, 시간: 132 ms

### 분류

다익스트라(dijkstra), 그래프 이론(graphs)

### 문제 설명

<p>As a jury member of the Best Architectural Planning Contest, you are tasked with scoring the reliability of a system. All systems entered in the contest consist of a number of components which depend on each other. The reliability of such a system depends on the damage done by a failing component. Ideally a failing component should have no consequences, but since most components depend on each other, some other components will usually fail as well.</p>

<p>Most components are somewhat resilient to short failures of the components they depend on. For example, a database could be unavailable for a minute before the caches expire and new data must be retrieved from the database. In this case, the caches can survive for a minute after a database failure, before failing themselves. If a component depends on multiple other components which fail, it will fail as soon as it can no longer survive the failure of at least one of the components it depends on. Furthermore no component depends on itself directly, however indirect self-dependency through other components is possible.</p>

<p>You want to know how many components will fail when a certain component fails, and how much time passes before all components that will eventually fail, actually fail. This is difficult to calculate by hand, so you decided to write a program to help you. Given the description of the system, and the initial component that fails, the program should report how many components will fail in total, and how much time passes before all those components have actually failed.</p>

### 입력 

 <p>On the first line one positive number: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line with three space-separated integers n, d and c (1 ≤ n ≤ 10 000 and 1 ≤ d ≤ 100 000 and 1 ≤ c ≤ n): the total number of components in the system, the number of dependencies between components, and the initial component that fails, respectively.</li>
	<li>d lines with three space-separated integers a, b and s (1 ≤ a, b ≤ n and a ≠ b and 0 ≤ s ≤ 1 000), indicating that component a depends on component b, and can survive for s seconds when component b fails.</li>
</ul>

<p>In each test case, all dependencies (a, b) are unique.</p>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>one line with two space-separated integers: the total number of components that will fail, and the number of seconds before all components that will fail, have actually failed.</li>
</ul>

