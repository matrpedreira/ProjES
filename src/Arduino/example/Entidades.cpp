#include "Entidades.h"

StringList::StringList()
{
	list = NULL;
}


bool StringList::empty()
{
	if(list == NULL)
		return true;
	else
		return false;
}

void StringList::push(char * valor)
{
	LStrings *termo =(lStrings*)malloc(sizeof(lStrings));
	termo->Valor = valor;
	termo->next = list;
	list = termo;
}

void StringList::list_push_back(StringList *aList)
{
	if(list == NULL){
		list = aList->list;
	}else{
		LStrings *termo;
		for(termo = list; termo->next != NULL; termo = termo->next);
		termo->next =aList->list;
	}
	delete(aList);
}



char* StringList::pop()
{
	char *termo = NULL;
	if(list == NULL)
		return termo;

	termo = list->Valor;
	lStrings *inter = list;
	list= list->next;
	free(list);
	return termo;
}

char* StringList::getFirst()
{
	return getN(0);
}

char* StringList::getN(int ni)
{
	char *termo = NULL;
	int i = 0;
	for(lStrings *iList = list; iList != NULL; iList = iList->next, i++){
		if(i == ni)
		{
			termo = iList->Valor;
			return termo;
		}
	}
	return termo;
}

