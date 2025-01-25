

#include "singlelinkedlist.h"

#include <stdint.h>
#include <stdio.h>


void simple_single_linked_list_test()
{

        void *head1 = NULL;
        void *node1 = NULL;
        uint32_t data1 = 2;

        create_node(&head1);


        give_node_value(head1,(void*) &data1,sizeof(uint32_t));
        printf("%u\n", *((uint32_t*)get_value(head1)));

   

        create_node(&node1);
        data1 = 3;
        give_node_value(node1,(void*) &data1,sizeof(uint32_t));

        add_node_to_head(&head1,node1);


        printf("%u\n", *((uint32_t*)get_value(head1)));
     
        remove_head_node(&head1);

        printf("%u\n", *((uint32_t*)get_value(head1)));

        remove_head_node(&head1);
        remove_head_node(&head1);
        remove_head_node(&head1);

        return ;
}


void simple_single_linked_list_test2()
{

        void *head1 = NULL;
        void *node1 = NULL;
        uint32_t data1 = 22;

        create_node(&head1);

        give_node_value(head1,(void*) &data1,sizeof(uint32_t));
        // printf("%u\n", *((uint32_t*)get_value(head1)));

   
        for(int i=0;i<10;i++)
        {
                create_node(&node1);
                data1 = i;
                give_node_value(node1,(void*) &data1,sizeof(uint32_t));

                add_node_to_tail(&head1,node1);
        }

        create_node(&node1);
        data1 = 730;
        give_node_value(node1,(void*) &data1,sizeof(uint32_t));
        add_node_in_index_n(&head1,node1,122);

        for(int i=0;i<10;i++)
        {
                printf("%u\n", *((uint32_t*)get_value(head1)));
                // remove_head_node(&head1);
                //remove_tail_node(&head1);
                remove_node_in_index_n(&head1,5);
        }       

        for(int i=0;i<10;i++)
        {
                printf("%u\n", *((uint32_t*)get_value(head1)));
                // remove_head_node(&head1);
        }       

        printf("%u\n", *((uint32_t*)get_value(head1)));

        remove_head_node(&head1);
        remove_head_node(&head1);
        remove_head_node(&head1);

        return ;
}



int main()
{
        // simple_single_linked_list_test();

        
        simple_single_linked_list_test2();
        
        return 0;  
}