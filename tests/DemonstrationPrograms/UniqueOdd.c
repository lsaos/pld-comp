int main(){
	int array[19];
	int size=10;
	int unique=0;
	int counter=0;
	for(int i=0; i<2*size-1; i=i+1){
		if (i<size){
			array[i]=i+1;
		} else {
			array[i]=i+1-size;
		}
	}
	//{0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8}
	//e.g. 9 is unique.
	while(counter<2*size-1){
		unique=unique^array[counter];
		counter=counter+1;
	}
	return unique;
}
