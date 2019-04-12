int main(){
	int a=0;
	int i=0,j=0,k=0,l=0;//counters
	while(i<2){
		while(j<2){
			while(k<2){
				while(l<2){
					a=a+1;
					l=l+1;
				}
				l=0;
				k=k+1;
			}
			k=0;
			j=j+1;
		}
		j=0;
		i=i+1;
	}
	return a;
	
}
