#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#define HEADER printf("\n===============%s==============\n",__FUNCTION__);
typedef char seqstacktype;
typedef struct seqstack{
    seqstacktype *data;
    size_t capacity;//存储的容量,可自行设置
    size_t size;
}seqstack;
seqstack seq;
void seqstack_init(seqstack *seq);
void seqstack_destroy(seqstack *seq);
void seqstack_print(seqstack *seq);
void seqstack_pushback(seqstack *seq,seqstacktype value);
void seqstack_popback(seqstack *seq);
int seqstack_gettop(seqstack *seq,seqstacktype *value);

