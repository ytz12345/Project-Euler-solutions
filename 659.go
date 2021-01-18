package main

import (
	"fmt"
	"math/rand"
	"os"
	"sync"
	"time"
)

const (
	N = 10000000
	T = 20	
	G = 5000
	Mod = 1000000000000000000
)

var (
	start = time.Now().UnixNano()
	ans int64
	cnt int
	mutex sync.Mutex
	ch = make(chan int64, G)
	mp = make(map[int64]bool)
)

func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

func ran() int64 {
	return rand.Int63()
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func gcd(x, y int64) int64 {
	if y == 0 {
		return x
	}
	return gcd(y, x % y)
}

func qmul(a, b, p int64) int64 {
	var c int64 = 0
	a %= p
	for ; b > 0; {
		if b & 1 == 1 {
			c += a
		}
		if c >= p {
			c -= p
		}
		a <<= 1;
		if a >= p {
			a -= p
		}
		b >>= 1
	}
	
	return c
}

func qpow(x, k, p int64) int64 {
	var res int64 = 1
	x %= p
	for ; k > 0; {
		if k & 1 == 1 {
			res = qmul(res, x, p)
		}
		k >>= 1
		x = qmul(x, x, p)
	}

	return res
}

func check(a, n, x, t int64) bool {
	res := qpow(a, x, n)
	last := res
	for i := int64(1); i <= t; i += 1 {
		res = qmul(res, res, n)
		if res == 1 && last != 1 && last != n - 1 {
			return true
		}
		last = res
	}
	if res != 1 {
		return true
	}
	return false
}
 
func millerRabin(n int64) bool {
	if n < 2 {
		return true
	}
	x := n - 1
	t := int64(0)
	for ; x & 1 != 1; {
		x >>= 1
		t += 1
	}
	flag := true
	if t >= 1 && x & 1 == 1 {
		for k := 0; k < T; k += 1 {
			a := ran() % (n - 1) + 1
			if check(a, n, x, t) {
				flag = true
				break
			}
			flag = false
		}
	}
	if !flag || n == 2 {
		return false
	}
	return true
}

func pollardRho(x, c int64) int64{
	i := int64(1)
	x0 := ran() % x
	y := x0
	k := int64(2)
	for {
		i += 1;
		x0 = qmul(x0, x0, x) + c % x
		d := abs(gcd(y - x0, x))
		if d != 1 && d != x {
			return d
		}
		if y == x0 {
			return x
		}
		if i == k {
			y = x0 
			k <<= 1
		}
	}
}

func findFac(n int64, fac *int64) {
	if !millerRabin(n) {
		*fac = max(*fac, n)
		return
	}
	p := n
	for ; p >= n; {
		p = pollardRho(p, ran() % (n - 1) + 1)
	}
	findFac(p, fac)
	findFac(n / p, fac)
}

func worker() {
	for {
		x := <- ch
		var fac int64 = 0
		findFac(x, &fac)
		mutex.Lock()
		ans += fac
		for ; ans >= Mod; {
			ans -= Mod
		}
		cnt += 1
		if cnt == N {
			fmt.Println(ans)
			fmt.Println("time cost", (time.Now().UnixNano()-start)/1000000, "ms")
			os.Exit(0)
		}
		mutex.Unlock()
		
	}
}

func produce() {
	for i := int64(1); i <= N; i ++ {
		ch <- i * i * 4 + 1
	}
}

func main() {
	// 不用协程池会炸
	for i := 1; i <= G; i ++ {
		go worker()
	}
	go produce()
	select {}
}

/*
238518915714422000
time cost 384947 ms
*/