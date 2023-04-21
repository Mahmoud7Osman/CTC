#include "ctc.h"

bool ctc_node_ok(ctc_node_t* n){
	if (n == NULL)       		  		  return CTC_ERROR;
	if (n->code == NULL) 				  return CTC_ERROR;
	if (n->argc != 0 && *n->argv == NULL) return CTC_ERROR;

	return CTC_OK;
}

ctc_origin_t* ctc_create_origin(){
	ctc_origin_t *origin = (ctc_origin_t*) malloc(sizeof(ctc_origin_t));
	origin->task_count   =    0;
	origin->result       = NULL;
	origin->current_task = NULL;
	origin->first_node   = NULL;
	origin->last_node    = NULL;
	
	return origin;
}

bool ctc_add_task(int argc, char** argv, CTC_CODE code, ctc_origin_t* origin){
	if (!origin) return CTC_ERROR;
	ctc_task_t* task = (ctc_task_t*)malloc(sizeof(ctc_task_t));
	task->next   =   origin->first_node;
	task->argc   =   argc;
	task->argv   =   argv;
	task->code   =   code;
	task->origin = origin;

	if (origin->last_node)
		origin->last_node->next = task;
		
	if (!origin->first_node)
		origin->first_node   = task;
		
	if (!origin->current_task)
		origin->current_task = task;
		
	origin->last_node 		= task;
	return CTC_OK;
}

bool ctc_next_task(ctc_origin_t *o, void(*code)()){
	if (!o) return CTC_ERROR;
	if (!ctc_node_ok(o->current_task->next)) return CTC_ERROR;	

	o->current_task = o->current_task->next;
	code();
	return CTC_OK;
}
bool ctc_run_current_task(ctc_origin_t* o, char** ptr){
	if (!o) return CTC_ERROR;
	if (!ctc_node_ok(o->current_task)) return CTC_ERROR;
	
	o->current_task->code(o->current_task->argc, o->current_task->argv, o,&(o->current_task->data));
	*ptr=o->current_task->data;
	return CTC_OK;
}

bool ctc_clean(ctc_origin_t* n){
	if (!n) return CTC_ERROR;
	for (ctc_node_t* i=n->first_node; i!=NULL; i = i->next){
		if (i->data) free (i->data);
		free(i);
	}
	if (n) free(n);
	return CTC_OK;
}
