
/*******************************************************************************************************
* NAME: singlelinkedlist.h*                                                                             
*                                                                                                       
* PURPOSE: Defines a general template for single linked lists, including                                
* the different needed functions                                                                        
*                                                                                                       
* GLOBAL VARIABLES: None                                                                                
*                                                                                                       
*                                                                                                       
* DEVELOPMENT HISTORY:                                                                                  
*                                                                                                       
* Date          Author          Change Id       Release         Description Of Change                   
* ----------    --------------- ---------       -------         -----------------------------------     
* 27-10-2024    Tiago Rodrigues                       1         Prolog and definition of operations     
*                                                                                                       
*                                                                                                       
*******************************************************************************************************/
#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

/* 0 copyright/licensing */
/**********************************************************************
*
* 2024 Tiago Filipe Rodrigues tiagorodrigues1590@hotmail.com
*
***********************************************************************/

#ifdef __cplusplus
extern "C" {
#endif



/* 1 includes */
/*****************************************************/
#include <stdint.h>

/*****************************************************/

/* 2 defines */
/*****************************************************/

/*****************************************************/

/* 3 external declarations */
/*****************************************************/

/*****************************************************/

/* 4 typedefs */
/*****************************************************/

// typedef uint32_t max_dim_of_list;




typedef struct node node_s_t;
typedef struct node_value node_value_s_t;
/*****************************************************/

/* 5 global variable declarations */
/*****************************************************/


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/

/******************************************************************
*
* FUNCTION NAME:        create_list
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* head         node_s_t*         I       pointer to a node
*
*
* RETURNS: node_s_t (as a head to a new list)
*
*
*
*****************************************************************/
node_s_t *create_list(node_s_t *head);

/******************************************************************
*
* FUNCTION NAME:        create_value
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	--------------------------
* value1        void*           I       void pointer to data to 
*                                        put in data of a node
*
*
* RETURNS: node_value_s_t (as a new values structure)     
*
*
*
*****************************************************************/
node_value_s_t *create_value(void *value1);

/******************************************************************
*
* FUNCTION NAME:        get_value
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	--------------------------
* head          node_s_t*           I     pointer to head of list 
*
*
* RETURNS: void* (which is the data position of the value of head)     
*
*
*
*****************************************************************/
void *get_value(node_s_t * head);






node_s_t *create_node(node_value_s_t *value);




/******************************************************************
*
* FUNCTION NAME:        add_node_to_head
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	--------------------------
* head          node_s_t*         I       pointer to head of list 
* new_node      node_s_t*         I       pointer to new node
*
* RETURNS: node_s_t* (new head of list)     
*
*
*
*****************************************************************/
node_s_t *add_node_to_head(node_s_t *head,node_s_t *new_node);

node_s_t *add_node_to_tail(node_s_t *head, node_s_t *new_node);

node_s_t *add_node_in_index_n(node_s_t *head, node_s_t *new_node, uint64_t n);





node_s_t *remove_head_node(node_s_t *head);

node_s_t *remove_tail_node(node_s_t *head);

node_s_t *remove_node_in_index_n(node_s_t *head, uint64_t n);


void print_list(node_s_t *head);


void *get_value_in_index_n(node_s_t * head, uint64_t n);

/*****************************************************/



/* 7 function declarations */
/*****************************************************/

/*****************************************************/


#ifdef __cplusplus
}
#endif


#endif

























