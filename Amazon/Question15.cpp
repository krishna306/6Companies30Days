void linkdelete(struct Node  *head, int M, int N){
    if(head == NULL){
        return;
    }
    int m=0;
    while(head != NULL && head -> next  ){
        m++;
        if(m==M){
            Node *temp = head;
            int l = N;
            while(l--){
                if(temp-> next){
                    temp = temp ->next;
                }
            }
            head->next  = temp->next;
            m=0;
        }
        head = head-> next;
    }
}