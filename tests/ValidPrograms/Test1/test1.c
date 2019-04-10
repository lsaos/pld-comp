int main(){
	int a, b[8];
    int i;
	a=3;
	for(i=0; i<8; i=i+1){
		b[i]=i;
	}
	return b[3*2]+a;
}
