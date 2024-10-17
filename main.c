#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct TItem
{
	struct TItem * m_Next;
	char * m_Name;
	char m_Secret[24];
} TITEM;

#endif /* __PROGTEST__ */

TITEM * newItem ( const char * name, TITEM * next )
{
	TITEM * tmp = (TITEM*) malloc (sizeof(TITEM));
	tmp -> m_Next = next;
	tmp -> m_Name = strdup(name);
	for (int i = 0; i < 24; i++)
		tmp -> m_Secret[i] = '\0';
	return tmp;
}

void printList ( TITEM * l) {

	//printf("List: ");
	while (l != NULL) {
		printf("%s, ", l -> m_Name);
		l = l -> m_Next;
	}
	//printf("NULL");
}

int countList(TITEM * l)
{
	int count = 0;
	while (l != NULL) {
		count++;
		l = l -> m_Next;
	}
	return count;
}


TITEM * swapNodes2( TITEM * prev, TITEM * l)
{
	TITEM * tmp;

	tmp = l->m_Next;
	//printf("\n\nl -> name: %s\n\n", l->m_Name);
	l->m_Next = tmp->m_Next;
	tmp->m_Next = l;
	return tmp;

}
//function to swap prev -> m_Next and prev -> m_Next -> m_Next
void swapNodes1( TITEM * prev)
{
	TITEM * tmp;

	if (prev -> m_Next -> m_Next == NULL) {
		tmp = prev -> m_Next;			// tmp -> C
		prev -> m_Next = NULL;			// A -> NULL
		tmp -> m_Next = prev -> m_Next;			//
		prev -> m_Next = tmp;
		return;
	}


	tmp = prev -> m_Next -> m_Next;
	prev -> m_Next -> m_Next = tmp -> m_Next;
	tmp -> m_Next = prev -> m_Next;
	prev -> m_Next = tmp;
}

int compare( char * a, char * b, int ascending)				//ascending 1 = ABCabc, 0 = cbaCBA
{
	if (ascending == 1) {
		if (strcmp(a, b) > 0)
			return 1;

		else
			return 0;
	}

	if (strcmp(a, b) < 0)
		return 1;


	return 0;
}

TITEM * sortList ( TITEM * l, int ascending )
{
	int count = countList( l );
	if (count == 1)
		return l;
	TITEM * head = l;
	TITEM * prev = l;

	for (int i = 0; i < count; i++) {

		l = head;
		prev = l;
		//printf("\nCMP mimo: %s %s \n\n", l -> m_Name, l -> m_Next -> m_Name);
		if (compare(l -> m_Name, l -> m_Next -> m_Name, ascending)) {
			//printList(head);


			head = swapNodes2(prev, l);					// in case of swap, update head
			prev = head;

		}
		else
			l = l -> m_Next;


		for (int j = 1; j < count - i - 1; j++) {
			/*printf("\n list:");

			printf("\n%s %s \n", l -> m_Name, l -> m_Next -> m_Name);*/
			if (compare(l -> m_Name, l -> m_Next -> m_Name, ascending)) {
				swapNodes1(prev);
			}
			prev = prev -> m_Next;
			l = prev -> m_Next;
		}
	}

	return head;
}

void freeList ( TITEM * src )
{
	while (src) {
		TITEM * next = src -> m_Next;
		free(src -> m_Name);
		free(src);
		src = next;
	}
}


#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
	TITEM * l;
	char tmp[50];

	assert ( sizeof ( TITEM ) == sizeof ( TITEM * ) + sizeof ( char * ) + 24 * sizeof ( char ) );
	l = NULL;
	l = newItem ( "PA1", l );
	l = newItem ( "PA2", l );
	l = newItem ( "UOS", l );
	l = newItem ( "LIN", l );
	l = newItem ( "AG1", l );



	return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */