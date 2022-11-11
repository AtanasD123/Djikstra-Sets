# Djikstra-Sets

## Implemnting Djikstra's Algorithm With Sets in C

Well, kinda. There is indeed a struct that holds a "set". Unfortunately, none of the important set operations are defined, so if you want to do operations with sets (complement, intersection, subtraction etc.), you will have to implement them on your own.

## Why use a set instead of a priority queue?
Mainly ease of implementation and comprehension. C does not have an integrated data strucuture that can hold a (value, vertex) pair. If you really want to go down the prio q path, I'd suggest creating a second node struct that holds a value vertex pair. Then you can start tweaking your favorite prio q implentation (heapify, swim, sink, swap).

## Why use a priority queue instead of a set?
Obviously, the main drawback of using a set is that you are sacrificing performance. Where Djikstra would usually run in O(VlogV) / maybe O(EVlogv). This implementation is more like (V^2).

CY@
