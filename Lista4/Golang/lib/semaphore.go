package lib

import "context"

type ChannelSemaphore struct {
	capacity int
	queue    chan chan bool
	wait     chan chan bool
	signal   chan bool
}

func NewChannelSemaphore(ctx context.Context, capacity, queueSize int) ChannelSemaphore {
	s := ChannelSemaphore{}
	s.capacity = capacity
	s.queue = make(chan chan bool, queueSize)
	s.wait = make(chan chan bool)
	s.signal = make(chan bool)
	go s.ChannelSemaphoreLogic(ctx)
	return s
}

func (s *ChannelSemaphore) ChannelSemaphoreLogic(ctx context.Context) {
	for {
		select {
		case <-ctx.Done():
			return
		case waiting := <-s.wait:
			if s.capacity > 0 {
				waiting <- true
				s.capacity -= 1
			} else {
				s.queue <- waiting
			}
		case <-s.signal:
			if len(s.queue) > 0 {
				waiting := <-s.queue
				waiting <- true
			} else {
				s.capacity += 1
			}
		}
	}
}

func (s *ChannelSemaphore) Wait() {
	waiting := make(chan bool)
	s.wait <- waiting
	<-waiting
}

func (s *ChannelSemaphore) Signal() {
	s.signal <- true
}
