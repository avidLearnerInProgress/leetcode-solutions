class Solution {
public:
    void reorderList(ListNode *head) {
  // use fast/slow points to find the second half of the list       
            ListNode *head1, *head2;
            ListNode *preNode, *curNode;
            
            if(!head || !(head->next) )
            {// if the list is empty or only has one element
                return;
            }
            else
            {
                head1 = head;
                head2 = head->next;
                
                // find the starting point of the second half
                while(head2 && head2->next)
                {
                    head1 = head1->next;
                    head2 = (head2->next)->next;
                }
                
                //reverse the second half
                head2 =head1->next; // the head of the second half
                head1->next =NULL;
                preNode = NULL;
                
                while(head2)
                {
                    curNode = head2->next;
                    head2->next = preNode;
                    preNode= head2;
                    head2 = curNode;
                }
                
                // merge the first half and the reversed second half
                head2 = preNode;
                head1 = head;
                
                while(head2)
                {
                    curNode = head1->next;
                    head1 = head1->next = head2;
                    head2 = curNode;
                }
                
                return;
            }
        }