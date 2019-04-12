int modulo(int a, int b){
	int divisionResult=divide(a,b);
	int moduloResult=a-divisionResult*b;
	return moduloResult;
}

int divide(int a, int b){
	int result=0;
	for(int i=0; i<a; i=i+b){
		result=result+1;
	}
	return result;
}

int main(){
	int div = divide(43,3);
	int mod = modulo(43,3);
	return div*3+mod;
}