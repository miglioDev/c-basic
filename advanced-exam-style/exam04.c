/*
 * Exam 04 — Linked Lists: File Processing and Recursive Filtering
 *
 * Manage a linked list of integers using text files.
 *
 * a) Write an iterative function:
 *    LINK read_list_from_file(char *filename);
 *    that reads a sequence of integers from a text file, 
 *    (terminated by the end of the file), builds the corresponding
 *    linked list while preserving the input order (by inserting nodes at
 *    the tail), and returns the head of the list.
 *
 * b) Write an iterative function that finds the smallest value stored
 *    in the linked list, computes its Fibonacci number, and returns it.
 *    The main function must print the Fibonacci number.
 *
 * c) Write a recursive function:
 *    LINK filter_even_rec(LINK head);
 *    that returns a new linked list containing only the even values from
 *    the original list. The new list must be built using newly allocated
 *    nodes, while the original list must remain unchanged.
 *
 * d) Write a function that properly deallocates the memory used by both
 *    linked lists.
 *
 * e) Write a main function that:
 *    - reads the linked list from a file named "input.txt";
 *    - prints the original list;
 *    - builds the filtered list by calling filter_even_rec();
 *    - writes the filtered list to a file named "output.txt";
 *    - deallocates both linked lists before terminating.
 */

