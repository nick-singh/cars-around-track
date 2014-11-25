#include <stdio.h>
#include <stdlib.h>

#define MaxCars 50


FILE* in, out;
int n;

typedef struct node
{
	int fuel, distance, num;
	struct node *next;	
}Node, *NodePtr;

NodePtr makeNode(int, int, int);
void getCar(NodePtr);

int main()
{
	int f, d, i;
	NodePtr top, np , last;
	in = fopen("input.txt", "r");
	top = NULL;
	fscanf(in,"%d", &n);
	for(i = 0; i < n; i++){
		fscanf(in, "%d %d", &f, &d);
		np = makeNode(f,d, i);
		if(top == NULL)top = np;
		else last->next = np;
		last = np;
	}
	last->next = top;

	getCar(top);
	return 0;
}


NodePtr makeNode(int f, int d, int i)
{
	NodePtr np = (NodePtr)malloc(sizeof (Node));
	np->fuel = f;
	np->distance = d;
	np->num = i;
	np->next = NULL;
	return np;
}


void getCar(NodePtr top)
{
	NodePtr curr, old;
	curr = top;
	// while we still have cars and top does not point to itself
	while(n > 0  && curr->next != curr){
		// if there is more fuel than distance
		if(curr->fuel >= curr->distance){	
			// add current fuel and fuel to reach next car		
			curr->fuel += curr->next->fuel;	
			curr->distance += curr->next->distance;	
			// remove car
			old = curr->next;
			// point to following car		
			curr->next = curr->next->next;
			n--;
			free(old);
		}
		// move to the next car...
		else curr = curr->next;
		
	}	
	printf("%d %d %d\n", curr->num, curr->fuel, curr->distance);
}