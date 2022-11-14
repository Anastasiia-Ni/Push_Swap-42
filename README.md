# Push_Swap

## About project: 

The push_swap is a simple and effective algorithm project.

The main goal is to sort a random list of integers using the smallest number of moves, 2 stacks and a limited set of operations. 

It starts with two empty stacks: a and b. You are given a random list of integers via command line arguments. 


Only these moves are allowed:

| operation |                             action |
|:----:|-----------|
| sa | swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements|
| sb | swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements|
| ss | sa and sb at the same time |
| pa | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty|
| pb | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty|
| ra | rotate a - shift up all elements of stack a by 1. The first element becomes the last one|
| rb | rotate b - shift up all elements of stack b by 1. The first element becomes the last one|
| rr | ra and rb at the same time|
| rra| reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one|
|rrb | reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one|
|rrr | rra and rrb at the same time|

At the end, stack b must empty empty and all integers must be in stack a, sorted in ascending order. 

## Index: 

## Installation:
```
$ git clone git@github.com:Anastasiia-Ni/Push_Swap-42.git
$ cd Push_Swap-42
$ make
```

## Usage:

- `./push_swap arguments`  

arguments - a sequence of non-repeating integers in the range -2147483648 to 2147483647.

## Examples:
```
$>./push_swap 5 8 1
rra
$>./push_swap 2 1 3 6 5 8
rra
rra
pb
pb
pb
ra
pa
rra
pa
rra
pa
ra
ra
ra
$>./push_swap 0 one 2 3
Error
$>
```
