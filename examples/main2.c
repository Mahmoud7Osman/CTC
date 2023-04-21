#include "../include/ctc.c"
#include "./tasks.c"
#include <stdio.h>

int main(void){
	char* result;
	ctc_origin_t* origin = ctc_create_origin();
	ctc_add_task(0, NULL, say_hello, origin);
	ctc_add_task(0, NULL, say_bye, origin);
	printf("Created Origin At %p With 2 Tasks From tasks.c\n", origin);

	while (1){
		if (!ctc_run_current_task(origin, &result))
			printf("Error");
		printf("%s\n" ,result);
		free(result);
		ctc_next_task(origin, ontaskswitch);
	}
	ctc_clean(origin);
}
