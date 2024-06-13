package lib

import "context"

type Monitor struct {
	S        ChannelSemaphore
	Fork     []int
	OKtoEatS []ChannelSemaphore
	OKtoEatC []int

	n int
}

func NewMonitor(ctx context.Context, n int) Monitor {
	m := Monitor{}
	m.S = NewChannelSemaphore(ctx, 1, n)
	m.Fork = make([]int, n)
	m.OKtoEatS = make([]ChannelSemaphore, n)
	m.OKtoEatC = make([]int, n)
	for i := 0; i < n; i++ {
		m.Fork[i] = 2
		m.OKtoEatS[i] = NewChannelSemaphore(ctx, 0, 1)
		m.OKtoEatC[i] = 0
	}
	m.n = n
	return m
}

func (m *Monitor) TakeFork(i int) {
	m.S.Wait()
	if m.Fork[i] != 2 {
		m.OKtoEatC[i] += 1
		m.S.Signal()
		m.OKtoEatS[i].Wait()
		m.S.Wait()
		m.OKtoEatC[i] -= 1
	}
	m.Fork[(i+1)%m.n] -= 1
	m.Fork[(m.n+i-1)%m.n] -= 1
	m.S.Signal()
}

func (m *Monitor) ReleaseFork(i int) {
	m.S.Wait()
	m.Fork[(i+1)%m.n] += 1
	m.Fork[(m.n+i-1)%m.n] += 1
	if m.Fork[(i+1)%m.n] == 2 {
		if m.OKtoEatC[(i+1)%m.n] != 0 {
			m.OKtoEatS[(i+1)%m.n].Signal()
		}
	}
	if m.Fork[(m.n+i-1)%m.n] == 2 {
		// ok to eat[(m.n + i-1) % m.n] signal
		if m.OKtoEatC[(m.n+i-1)%m.n] != 0 {
			m.OKtoEatS[(m.n+i-1)%m.n].Signal()
		}
	}
	m.S.Signal()
}
