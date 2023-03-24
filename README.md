# push_swap

Exploring sorting algorithms and computational complexity.
> You have to write a program named push_swap that takes as an argument the stack formatted as a list of integers. The program must display the smallest list of instructions possible to sort the stack, separated by a `’\n’`. The goal is to sort the stack with the lowest possible number of operations

## **About:**

- You have 2 stacks named *a* and *b*.
- At the beginning:
	- The stack *a* contains a random amount of negative and/or positive numbers which cannot be duplicated.
	- The stack *b* is empty.
- The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:

### **Operations:**
| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

## **Bonus:**

- Write a program named checker that takes as an argument the stack a formatted as a list of integers.
- It will then wait and read instructions on the standard input. 
- Each instruction will be followed by `’\n’`. 
- Once all the instructions have been read, the program has to execute them on the stack received as an argument.
- If after executing the stack a is sorted and the stack b is empty, then the program must display `"OK"` followed by a `’\n’`.
- In every other case, it must display `"KO"` followed by a `’\n’` on the standard output.
- In case of error, you must display `"Error"` followed by a `’\n’` on the standard error. 
- Errors include for example: 
	- some arguments are not integers 
	- some arguments are bigger than an integer
	- there are duplicates
	- an instruction doesn’t exist and/or is incorrectly formatted.