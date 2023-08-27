#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct monty_s - monty structure
 * @line: the line
 * @words: array of words
 * @line_number: line number
 * @my_stack: the stack
 * Description: monty structure
*/

typedef struct monty_s
{
	char *line;
	char **words;
	int line_number;
	stack_t *my_stack;
} monty_t;

/**general utils**/
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int is_valid_op(char *opcode);
int	ft_strcmp(const char *s1, const char *s2);
int isstrnumber(char *str);
void remove_new_line(char **s);
int is_line_empty(char *line);
void free_stack(stack_t *stack);
void free_array(char **words);
void do_op(monty_t *monty);
/**stack utils**/
void malloc_error(void);
void push(stack_t **stack, int n);
void print_stack(stack_t *stack);
void pop(stack_t **stack);
void swap(stack_t **stack);
void add(stack_t **stack_t);
char	**split(const char *s, char c);


#endif
