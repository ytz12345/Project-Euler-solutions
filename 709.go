package main

import (
	"fmt"
	"os"
	"sync"
	"time"
)

const (
	N   = 30000
	Mod = 1020202009
)

var (
	inv [N]int64
	fac [N]int64
	dp  [2][N]int

	n  int
	wg sync.WaitGroup
)

func init() {
	fac[0] = 1
	inv[0] = 1
	inv[1] = 1

	for i := 1; i < N; i += 1 {
		fac[i] = fac[i-1] * int64(i) % Mod
		if i != 1 {
			inv[i] = inv[Mod%i] * int64(Mod-Mod/i) % Mod
		}
	}
	for i := 2; i < N; i += 1 {
		inv[i] = inv[i] * inv[i-1] % Mod
	}
}

func C(n, m int) int64 {
	return fac[n] * inv[m] % Mod * inv[n-m] % Mod
}

func MOD(x *int) {
	for *x >= Mod {
		*x -= Mod
	}
}

func main() {
	fmt.Fscanln(os.Stdin, &n)

	dp[1][1] = 1
	var now int

	start := time.Now().UnixNano()
	for i := 2; i <= n; i += 1 {
		now = i & 1
		for j := 1; j <= i; j += 1 {
			wg.Add(1)
			//fmt.Println(i, j)
			go func(j int) {
				dp[now][j] = dp[now^1][j-1]
				for k, d := j+1, 2; k < i; k += 2 {
					dp[now][j] += int(int64(dp[now^1][k]) * C(k, d) % Mod)
					//fmt.Println(i, j, k, d, C(k, d))
					MOD(&dp[now][j])
					d += 2
				}
				//fmt.Println(i, j, dp[now][j])
				wg.Done()
			}(j)
		}
		wg.Wait()
	}

	ans := 0
	for i := 1; i <= n; i += 1 {
		ans += dp[n&1][i]
		MOD(&ans)
	}
	fmt.Println(ans)
	fmt.Println("time cost", (time.Now().UnixNano()-start)/1000000, "ms")
}

/*
773479144
time cost 2132002 ms
*/
