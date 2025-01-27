
/*******************************************************************************************************
* NAME: singlelinkedlist.h                                                                        
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
* 24-01-2025    Tiago Rodrigues                         0       Changed all operations to use void *                                                                                                       
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




// typedef struct node node_s_t;
// typedef struct node_value node_value_s_t;
/*****************************************************/

/* 5 global variable declarations */
/*****************************************************/


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/

/******************************************************************
*
* FUNCTION NAME:        
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* 
*
*
* RETURNS:
*
*
*****************************************************************/
void create_node(void** node);


/******************************************************************
*
* FUNCTION NAME:        
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* 
*
*
* RETURNS:
*
*
*****************************************************************/
void give_node_value(void* node, void *value1, uint64_t size_of_datatype);



void add_node_to_head(void** head, void* node);

void add_node_to_tail(void** head, void* node);                  // ** needed in case head in null

void add_node_in_index_n(void** head, void* node,uint64_t position);

void remove_head_node(void** head);

void remove_tail_node(void** head);

void remove_node_in_index_n(void** head, uint64_t position);


void next_node(void** node);

void* get_next_node(void* node);

void* get_value(void* node);

void* get_value_in_index_n(void* head, uint64_t n);

// void print_list(void* head);

void free_linked_list(void** head);


/*****************************************************/



/* 7 function declarations */
/*****************************************************/

/*****************************************************/


#ifdef __cplusplus
}
#endif


#endif

























