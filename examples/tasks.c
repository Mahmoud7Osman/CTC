#include <unistd.h>

const char* task1="Circular Task Cycle Library Task Number 1 At Origin Zero";
const char* task2="Circular Task Cycle Library Task Number 2 At Origin Zero";

void say_hello(int argc, char** argv, ctc_origin_t* origin, char** data){
	*data = (char*) malloc(strlen(task1)+1);
	*(*data+strlen(task1)) = 0x00;
	memcpy(*data, task1, strlen(task1));
}

void say_bye(int argc, char** argv, ctc_origin_t* origin, char** data){
	*data = (char*) malloc(strlen(task2));
	*(*data+strlen(task2)) = 0x00;
	memcpy(*data, task2, strlen(task2));
}
void ontaskswitch(){
	usleep(500000);
}
