package main

import (
	"bufio"
	"fmt"
	"os"
)

var IN *bufio.Reader
var OUT *bufio.Writer

func cin(a ...any) {
	fmt.Fscan(IN, a...)
}

func cout(a ...any) {
	fmt.Fprint(OUT, a...)
}

func main() {
	IN = bufio.NewReader(os.Stdin)
	OUT = bufio.NewWriter(os.Stdout)
	defer OUT.Flush()
	var N int
	var mx int
	var mn int
	var arr [1000005]int
	mx = -1e9
	mn = 1e9
	cin(&N)
	for i := 0; i < N; i++ {
		cin(&arr[i])
		mx = max(mx, arr[i])
		mn = min(mn, arr[i])
	}
	cout(mn, mx)
}
