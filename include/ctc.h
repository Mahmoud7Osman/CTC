#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define CTC_HEAD 0x01
#define CTC_ERROR 0
#define CTC_OK    1



struct origin{
	int 		    task_count;
	struct node*	current_task;
	char** 			result;
	struct node*    last_node;
	struct node*    first_node;
};

typedef struct origin ctc_origin_t;
typedef void(*CTC_CODE)(int, char**, struct origin*, char**);

struct node{
	struct node*    next;
	struct origin*  origin;
	int 		    argc;
	char** 		    argv;
	CTC_CODE        code;
	char*           data;
};

typedef struct node ctc_node_t, ctc_task_t;
