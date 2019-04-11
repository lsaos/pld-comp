
int main(){
	int fac=5;
	int a =factorial(fac);
	return a;
}

int factorial(int fac){
	if (fac==1){
		return fac;
	} else {
		return fac*factorial(fac-1);
	}
}
