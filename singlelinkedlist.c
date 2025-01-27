/*******************************************************************************************************************
* FILE NAME: singlelinkedlist.c
*                                                                                                               
* PURPOSE: This file implements all the functions needed for the creation and modification of a single linked list
*                                                                                                               
* FILE REFERENCES:                                                                                              
*                                                                                                               
* Name                          I/O                     Description                                             
* ----                          ---                     -----------                                             
* none     
                                                                                                          
* EXTERNAL VARIABLES:                                                                                           
*                                                                                        
*                                                                                                               
* Name          Type            I/O                     Description                                             
* ----          ----            ---                     -----------                                             
* none
*
*                                                                                                             
* EXTERNAL REFERENCES:                                                                                          
* Name                          Description                                                                     
* ----                          -----------                                                                     
* calloc                        allocates memory, and initiates with zeros     
* printf                        function to print formatted output     
*    
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:                                                  
*             
*                                                                                                  
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:                                                                       
* It is assumed that the list is less than 2^64 elements, for input at                                          
*  a especific position operations          
* It is assumed for list insertion that it starts at index 0,and if n is larger than the list,
*  it is added to the end  
                                                                                                                
* NOTES:                                                                                                        
* If more that 2^64 is needed, use arbitrary-precision arithmetic libs                                  
*                                       
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:                                                            
*
*                                                                                                               
* DEVELOPMENT HISTORY:                                                                                          
*                                                                                                               
* Date          Author                  Change Id       Release         Description Of Change                   
* ----------    ---------------         ---------       -------         ---------------------   
* 27-10-2024    Tiago Rodrigues                         0               Prolog start and coding of a function
* 28-10-2024    Tiago Rodrigues                         0               Added prolog to functions 
* 24-01-2025    Tiago Rodrigues                         0               Changed all operations to use void *
* 25-01-2025    Tiago Rodrigues                         0               New operations implemented
*                                                                                                              
* ALGORITHM (PDL)
*    
*
*                                                                                                           
****************************************************************************************************************/


/* 0 copyright/licensing */
/***************************************************************************************************************/
/*
*       2024 Tiago Filipe Rodrigues tiagorodrigues1590@hotmail.com
*/
/***************************************************************************************************************/


/* 1 includes */
/*****************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "singlelinkedlist.h"
/*****************************************************/


/* 2 defines */
/*****************************************************/

/*****************************************************/


/* 3 external declarations */
/*****************************************************/

/*****************************************************/


/* 4 typedefs */
/*****************************************************/

/*****************************************************/


/* 5 global variable declarations */
/*****************************************************/
struct node
{
        // uint64_t size_of_datatype;                   not needed, unless trying to make a multi value linked list
        void* data;
        struct node* next;
};



/*****************************************************/


/* 6 function prototypes */
/*****************************************************/

/*****************************************************/



/* 7 function declarations */
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
void create_node(void** node)
{
        (*node) = malloc(1*sizeof(struct node));
        if(NULL == (*node))
        {
                fprintf(stderr, "Memory allocation failed\n");
                return ;
        }
        (*(struct node **)(node))->next = NULL;
        return ;
}


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
void give_node_value(void* node, void *value1, uint64_t size_of_datatype)
{
        if(NULL == node)
        {
                fprintf(stderr, "Node mem location is null\n");
                return ;
        }

        ((struct node*)node)->data =(void*) malloc(1*size_of_datatype);

        if(NULL == ((struct node*)node)->data)
        {
                fprintf(stderr, "Memory allocation failed\n");
        }

        memcpy(((struct node*)node)->data, value1, size_of_datatype);

        return ;
}



void add_node_to_head(void** head, void* node)
{
        if(NULL == (*head))
        {
                head = node;
                return;
        }
        if(NULL == node)
        {
                return;
        }

        ((struct node*)node)->next= ((struct node*)(*head));

        (*head) = node;

}


void add_node_to_tail(void** head, void* node)
{
        if(NULL == (*head))
        {
                head = node;
                return;
        }
        if(NULL == node)
        {
                return;
        }

        struct node* aux_ptr = (*(struct node**)(head));
        while(NULL != get_next_node((void *)aux_ptr))
        {
                
                next_node((void**) &aux_ptr);


        }

        aux_ptr->next = node;

        return;

}


void add_node_in_index_n(void** head, void* node, uint64_t position)
{
        if(NULL == (*head))
        {
                head = node;
                return;
        }
        if(NULL == node)
        {
                return;
        }
        if(0 == position)
        {
                add_node_to_head(head, node);
                return ;
        }

        struct node* aux_ptr = (*(struct node**)(head));
        while(NULL != get_next_node((void *)aux_ptr) && position>1)                     //has to be 1
        {
                next_node((void**) &aux_ptr);
                position--;
        }

        ((struct node*)node)->next= aux_ptr->next;
        aux_ptr->next =((struct node*)node);
        

        return;
}

void remove_head_node(void** head)
{
        if(NULL == (*head))
        {
                return;
        }

        struct node* aux_ptr = (*(struct node**)(head));

        next_node(head);

        free(aux_ptr->data);
        free(aux_ptr);

        return;

}

void remove_tail_node(void** head)
{
        if(NULL == (*head))
        {
                return;
        }
        if(NULL == (*(struct node**)(head))->next)
        {
                free((*(struct node**)(head))->data);
                free((*head));
                return;
        }

        struct node* aux_ptr = (*(struct node**)(head));
        while(NULL != get_next_node(get_next_node((void *)aux_ptr)))
        {
                
                next_node((void**) &aux_ptr);


        }

        //free(get_value(get_next_node((void *)aux_ptr)));
        free(aux_ptr->next->data);
        //free(get_next_node((void *)aux_ptr));
        free(aux_ptr->next);
        aux_ptr->next = NULL;

        return;


}

void remove_node_in_index_n(void** head, uint64_t position)
{

        if(NULL == (*head))
        {
                return;
        }
        if(0 == position)
        {
                remove_head_node(head);
                return ;
        }

        struct node* aux_ptr = (*(struct node**)(head));
        while(NULL != get_next_node((void *)aux_ptr) && position>1)                     //has to be 1
        {
                next_node((void**) &aux_ptr);
                position--;
        }

        if(NULL == get_next_node((void *)aux_ptr))
                return ;

        if(1 == position)
        {
                struct node* node_to_free = NULL;
                node_to_free = get_next_node((void *)aux_ptr);
                aux_ptr->next = node_to_free->next;
        
                free(node_to_free->data);
                free(node_to_free);
        }

        return ;
}



void next_node(void** node)
{
        (*(struct node**)(node)) = get_next_node((*(struct node**)(node)));
        return;
}



void* get_value(void* node)
{
        if(NULL == node)
                return NULL;
        return ((struct node*)node)->data;
}

void* get_next_node(void* node)
{
        if(NULL == node)
                return NULL;

        return ((void *)((struct node*)node)->next);              
}


void* get_value_in_index_n(void* head, uint64_t n)
{
        if(NULL == (head))
        {
                return NULL;
        }

        struct node* aux_ptr = ((struct node*)(head));
        

        while(NULL != get_next_node((void *)aux_ptr) && n>0)                  
        {
                next_node((void**) &aux_ptr);
                n--;
        }

        if(0 != n)
                return NULL;
        
        return aux_ptr->data;
}

// void print_list(void* head);



void  free_linked_list(void** head)
{
        while(NULL != (*head))
        {
                struct node* aux_ptr = (*head);
                (*head) = get_next_node((*head));
                free(aux_ptr->data);
                free(aux_ptr);
        }
        head = NULL;

        return ;
}



/*****************************************************/





