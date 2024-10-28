

#include "singlelinkedlist.h"

#include <stdio.h>





int main()
{
        
        struct node *head,*new_node1,*new_node2,*new_node3 = NULL;
        struct node_value *value1,*value2,*value3, *value4 = NULL;
        
        int *pointertovalue = NULL;
        int valuetoaddint=3;
        int valuetoaddint2=2;
        int valuetoaddint3=4;
        int valuetoaddint4=1;
        value1 = create_value((void *) &valuetoaddint);
        value2 = create_value((void *) &valuetoaddint2);
        value3 = create_value((void *) &valuetoaddint3);
        value4 = create_value((void *) &valuetoaddint4);
        
        head = create_node(value1);
        head = create_list(head);
        new_node1 = create_node(value2);
        head = add_node_to_head(head,new_node1);

        new_node2 = create_node(value3);
        head = add_node_to_tail(head,new_node2);

        new_node3 = create_node(value4);
        head = add_node_in_index_n(head, new_node3, 0);
        
        // head = remove_node_in_index_n(head, 3);
        // head = remove_tail_node(head);
        // head = remove_head_node(head);
        
        print_list(head);
        
        //printf("%d", *(int*)get_value(head));
        
        pointertovalue = (int*) get_value_in_index_n(head,5);
        if(pointertovalue == NULL)
        {
                printf("NULL\n");
        }
        else if(pointertovalue != NULL)
        {
                printf("%d\n", *pointertovalue);        
        }
        
        
        return 0;  
}