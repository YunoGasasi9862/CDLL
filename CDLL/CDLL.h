#pragma once
typedef int LType;
typedef struct node_s
{
	LType data;
	node_s* next;
	node_s* prev;

}node_t;


node_t* getNode(void)
{

	node_t* tp;
	tp = (node_t*)malloc(sizeof(node_t));
	tp->next = NULL;
	tp->prev = NULL;
	return tp;
}

node_t* AddBeginning(node_t* hp, LType data)
{

	node_t* tp;
	tp = getNode();
	tp->data;
	tp->next = hp;
	if (hp != NULL)
		hp->prev = tp;
	tp->data = data;
	return tp;

}

void addAfter(node_t* hp, LType data)
{
	node_t* tp;
	tp = getNode();
	tp->data = data;
	tp->next = hp->next;
	hp->next = tp;
	tp->prev = hp;
}