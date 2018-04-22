#include <stdio.h>
#include"seqstack.h"
void seqstack_init(seqstack *seq)
{
    if(seq == NULL)
    {
        return;//非法输入
    }
    else{
        seq->size = 0;
        seq->capacity = 1000;
        seq->data = (seqstacktype*)
            malloc(seq->capacity*sizeof(seqstacktype));
        return;

    }
}
void seqstack_print(seqstack *seq)
{
    if(seq == NULL)
    {
        return;//非法输入
    }
    if(seq->size == 0)
    {
        return;//空顺序表
    }
    else
    {
        size_t i = 0;
        for(;i<seq->size;i++)
        {
            printf("[%c]",seq->data[i]);
        }
        printf("\n");
    }
}

void seqstack_resize(seqstack *seq)
{
    if(seq == NULL)
    {
        return;
    }
    if(seq->size < seq->capacity)
    {
        return;
    }
    seqstacktype *newdata = (seqstacktype *)malloc(seq->capacity*sizeof(seqstack)*2+1);
    int i = 0;
    for(;i<seq->size;i++)
    {
        newdata[i] =seq->data[i];
    }
    free(seq->data);
    seq->data = newdata;
    return;
}
void seqstack_pushback(seqstack *seq,seqstacktype value)
{
    if(seq == NULL)
    {
        return;//非法输入
    }
    if(seq->size >= seq->capacity)
    {
        seqstack_resize(seq);
    }

    seq->data[seq->size++] = value;
    return;
}

void seqstack_popback(seqstack *seq)
{
    if(seq == NULL)
    {
        return;
    }
    if(seq->size == 0)
    {
        return;
    }
    seq->size--;
}

int seqstack_gettop(seqstack *seq,seqstacktype *value)
{
    if(seq == NULL)
    {
        return -1;
    }
    if(value == NULL)
    {
        return -1;
    }
    *value = seq->data[seq->size-1];
    return 1;


}

void seqstack_destroy(seqstack *seq)
{
    if(seq == NULL)
    {
        return;
    }
    seq->size = 0;
    free(seq->data);
    return;
}
/////////////////////
//测试函数
/////////////////////

test_seqstack_pushback()
{
    HEADER;
    seqstack seq;
    seqstack_init(&seq);
    printf("入栈四个元素\n");
    seqstack_pushback(&seq,'a');
    seqstack_pushback(&seq,'b');
    seqstack_pushback(&seq,'c');
    seqstack_pushback(&seq,'d');
    seqstack_print(&seq);
}

test_seqstack_popback()
{
    HEADER;
    seqstack seq;
    seqstack_init(&seq);
    printf("入栈四个元素\n");
    seqstack_pushback(&seq,'a');
    seqstack_pushback(&seq,'b');
    seqstack_pushback(&seq,'c');
    seqstack_pushback(&seq,'d');
    seqstack_print(&seq);
    printf("出栈一个元素\n");
    seqstack_popback(&seq);
    seqstack_print(&seq);

}
test_seqstack_gettop()
{
    HEADER;
    seqstack seq;
    seqstack_init(&seq);
    printf("入栈四个元素\n");
    seqstack_pushback(&seq,'a');
    seqstack_pushback(&seq,'b');
    seqstack_pushback(&seq,'c');
    seqstack_pushback(&seq,'d');
    seqstack_print(&seq);
    seqstacktype value;
    int i = seqstack_gettop(&seq,&value);
    printf("expected ret is 1,actul ret is %d\n",i);
    printf("expected value is d,actul value is %c\n",value);
}


int main()
{
    test_seqstack_pushback();
    test_seqstack_popback();
    test_seqstack_gettop();
}


