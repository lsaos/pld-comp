int main(){
	int a, b[8];
	a=3;
	for(int i=0; i<8; i=i+1){
		b[i]=i;
	}
	return b[3*2]+a;
}
