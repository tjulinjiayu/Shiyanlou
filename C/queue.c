#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

static struct node *phead = NULL;

static struct node *create_node(int val) {
    struct node *pnode = NULL;
    pnode = (struct node*)malloc(sizeof(struct node));
    if (!pnode) {
        return NULL;
    }
    pnode -> val = val;
    pnode -> next = NULL;
    return pnode;
}

static void destory_single_link() {
    struct node *pnode = NULL;
    while (phead != NULL) {
        pnode = phead;
        phead = phead -> next;
        free(pnode);
    }
}

static void add(int val) {
    if (!phead) {
        phead = create_node(val);
        return ;
    }
    struct node *pnode = create_node(val);
    struct node *pend = phead;
    while (pend -> next) {
        pend = pend -> next;
    }
    pend -> next = pnode;
}

static int front() {
    // TODO:
    if (!phead)
        exit(-1);
    return phead -> val;
}

static int pop() {
    // TODO:
    if (!phead)
        exit(-1);
    int res = phead -> val;
    struct node *pnode = phead;
    phead = phead -> next;
    free(pnode);
    return res;
}

static int count() {
    // TODO:
    if(!phead)
        return 0;
    struct node *pend = phead;
    int cnt = 1;
    while(pend -> next){
        cnt++;
        pend = pend ->next;
    }
    return cnt;
}

static int is_empty() {
    // TODO:
    if (!phead)
        return 1;
    return 0;
}

int main() {
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    add(6);
    printf("%d", front());
    printf("%d", pop());
    printf("%d", front());
    printf("%d", count());
    printf("%d", is_empty());
    return 0;
}
