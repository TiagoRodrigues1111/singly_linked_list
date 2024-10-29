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
typedef struct node 
{
        // static max_dim_of_list counter       
        struct node_value *value;
        struct node *next;
}node_s_t;


typedef struct node_value
{       
        int val;
}node_value_s_t;
/*****************************************************/


/* 5 global variable declarations */
/*****************************************************/

/*****************************************************/


/* 6 function prototypes */
/*****************************************************/

/*****************************************************/



/* 7 function declarations */
/*****************************************************/




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
node_value_s_t *create_value(void *value1)
{
        int node_value_s_to_put = *((int *) value1);
        node_value_s_t *value_node_s_to_add = NULL;
        value_node_s_to_add = (node_value_s_t *) calloc(1,sizeof(node_value_s_t));


        value_node_s_to_add->val = node_value_s_to_put;
                
        return value_node_s_to_add;
}

/******************************************************************
*
* FUNCTION NAME:        create_node
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	--------------------------
* value         node_value_s_t* I       pointer to data to put in data of a node
*
*
* RETURNS: node_s_t (as a new node structure)     
*
*
*
*****************************************************************/
node_s_t *create_node(node_value_s_t *value)
{
        node_s_t *new_node = NULL; 
        new_node = (node_s_t *) calloc(1,sizeof(node_s_t));
        if(new_node == NULL)
        {
                exit(EXIT_FAILURE);
        }
        new_node->value = value;     
        new_node->next = NULL;
        
        return new_node;            
}

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
* head          node_s_t*       I       pointer to a node
*
*
* RETURNS: node_s_t (as a head to a new list)
*
*
*
*****************************************************************/
node_s_t *create_list(node_s_t *head)
{        
        return add_node_s_to_head(NULL, head);
}


/******************************************************************
*
* FUNCTION NAME:        add_node_s_to_head
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	--------------------------
* head          node_s_t*       I       pointer to head of list 
* new_node      node_s_t*       I       pointer to new node
*
* RETURNS: node_s_t* (new head of list)     
*
*
*
*****************************************************************/
node_s_t *add_node_to_head(node_s_t *head, node_s_t *new_node)
{
        if(head == NULL)
        {
                head = new_node;
        }
        else
        {
                new_node->next = head;
                head = new_node;
        
        }
        return head;
        
}

/******************************************************************
*
* FUNCTION NAME:        add_node_to_tail
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	--------------------------
* head          node_s_t*       I       pointer to head of list 
* new_node      node_s_t*       I       pointer to new node
*
* RETURNS: node_s_t* (head of list)     
*
*
*
*****************************************************************/
node_s_t *add_node_to_tail(node_s_t *head, node_s_t *new_node)
{
        node_s_t *auxH;
        if(head == NULL)
        {
                head = new_node;
        }
        else
        {
                auxH = head;
                
                while(auxH->next != NULL)
                {
                        auxH = auxH->next;
                }
                auxH->next = new_node;
        }
        return head;
}

/******************************************************************
*
* FUNCTION NAME:        add_node_in_index_n
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	--------------------------
* head          node_s_t*       I       pointer to head of list 
* new_node      node_s_t*       I       pointer to new node
* n             uint64_t        I       position to add new node
*
* RETURNS: node_s_t* (head of list)     
*
*
*
*****************************************************************/
node_s_t *add_node_in_index_n(node_s_t *head, node_s_t *new_node, uint64_t n)
{
        node_s_t *auxp;
        uint64_t aux_inc = 0;
        
        if(head == NULL)
        {
                head = new_node;
        }
        else if(n == 0)
        {
              head = add_node_s_to_head(head,new_node);
        }
        else
        {
                auxp = head;
                
                while((auxp->next != NULL) && (aux_inc < (n-1) ))
                {
                        auxp = auxp->next;
                        aux_inc++;
                }
                if(aux_inc != (n-1))
                {
                        ; // it means that the node to be introduzed at n is outside of the list size (n> number of elements)
                }
                new_node->next = auxp->next;
                auxp->next = new_node;
                
        }
        return head;
             
}

/******************************************************************
*
* FUNCTION NAME:        remove_head_node
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	--------------------------
* head          node_s_t*       I       pointer to head of list 
*
* RETURNS: node_s_t* (new head of list)     
*
*
*
*****************************************************************/
node_s_t *remove_head_node(node_s_t *head)
{
        node_s_t *auxp = NULL;

        if (head == NULL) 
        {
                ;
        }
        else
        {
                auxp = head->next;
                free(head->value);
                free(head);
                head = auxp;
        }
        return head;    
}

/******************************************************************
*
* FUNCTION NAME:        remove_tail_node
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	--------------------------
* head          node_s_t*       I       pointer to head of list
*
* RETURNS: node_s_t* (head of list)     
*
*
*
*****************************************************************/
node_s_t *remove_tail_node(node_s_t *head)
{
        if(head == NULL)
        {
                ;
        }
        else if (head->next == NULL) 
        {
                free(head->value);
                free(head);
                head = NULL;
        }
        else
        {
                node_s_t * auxp = head;
                while (auxp->next->next != NULL)
                {
                        auxp = auxp->next;
                }
                /* now current points to the second to last item of the list, so let's remove current->next */
                free(auxp->next->value);
                free(auxp->next);
                auxp->next = NULL;          
        }
        return head;
}

/******************************************************************
*
* FUNCTION NAME:        remove_node_in_index_n
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	--------------------------
* head          node_s_t*       I       pointer to head of list 
* n             uint64_t        I       position of node to remove
*
* RETURNS: node_s_t* (head of list)     
*
*
*
*****************************************************************/
node_s_t *remove_node_in_index_n(node_s_t *head, uint64_t n)
{
        node_s_t * auxp = NULL, *auxp2 = NULL;
        uint64_t aux_inc = 0;
        
        if(head == NULL)
        {
                ;
        }
        else if (head->next == NULL) 
        {
                free(head->value);
                free(head);
                head = NULL;
        }
        else if(n == 0)
        {
                head = remove_head_node(head);
        }
        else
        {
                auxp = head;
                while ((auxp->next->next != NULL) && (aux_inc < (n-1) ))
                {
                        auxp = auxp->next;
                        aux_inc++;
                }
                auxp2 = auxp->next->next;
                free(auxp->next->value);
                free(auxp->next);
                auxp->next = auxp2;          
                                
        }
        return head; 
}

/******************************************************************
*
* FUNCTION NAME:        print_list
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	--------------------------
* head          node_s_t*       I       pointer to head of list 
*
* RETURNS: void     
*
*
*
*****************************************************************/
void print_list(node_s_t *head)
{
        node_s_t *current = head;
        while (current != NULL) 
        {
                printf("%d\n", current->value->val);
                current = current->next;
        }    
        
        
        
}

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
void *get_value(node_s_t * head)
{
        
        return (void *)&head->value->val;
}

/******************************************************************
*
* FUNCTION NAME:        get_value_in_index_n
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-----------	---	-----------------------------
* head          node_s_t*       I       pointer to head of list 
* n             uint64_t        I       position of node to get value
*
*
* RETURNS: void* (which is the data position of the value of head)     
*
*
*
*****************************************************************/
void *get_value_in_index_n(node_s_t * head, uint64_t n)
{

        if(head == NULL)
        {
                return NULL;
        }
        else if(n == 0)
        {
                return get_value(head);
        }
        else
        {
                // To remove the need for an auxiliary variable, check when n>0, and decrement
                while((head != NULL) && (n > 0))                                          
                {
                        head = head->next;
                        n--;                    
                }
                if(head == NULL)
                {
                        return NULL;
                }
                return  (void *) &head->value->val;               
        }
}




// list orderer
// index searcher(      only first ? = TRUE, FALSE);



/*****************************************************/





