

void swap( char *i, char *j, int recsize )
{
	char x;

	while( recsize-- > 0)
	{
		x = *i;
		*i++ = *j;
		*j++ = x;
	}
}

void sort( char *base, int nel, int recsize, int (*comp)(char*,char*) )
{
	char *i;
	char *j;
	char *last;

	last = base + ( nel - 1 ) * recsize;
	for( i = base ; i < last; i += recsize )
		for( j = i+recsize; j<=last;j += recsize)
			if( comp(i,j) > 0)
				swap(i,j,recsize);
}

int compare(int i , int j)
{
	if(i>j)
		return 1;
	else if(i==j)
		return 0;
	else 
		return -1;
}

int main()
{
	int i;
	int array[] = {2,3,5,1,6,2,5,2,8,4,3,7,4};
	for(i=0;i<13;i++)
		printf("%d", array[i]);
	sort(array,13,4,compare);

	printf("\n");
	for(i=0;i<13;i++)
		printf("%d", array[i]);
	return 0;
}