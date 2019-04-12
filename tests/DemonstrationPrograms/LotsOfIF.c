int main(){
	int a=6,resultat=-1;
	putchar('\n');
	putchar('\t');
	if (a==0){
		putchar('A');
	} else{
		if(a==1){
			putchar('B');
		} else {
			if(a==2){
				putchar('C');
			} else {
				if(a==3){
					putchar('D');
				} else {
					if(a==4){
						putchar('E');
					} else {
						if(a==5){
							putchar('F');
						} else {
							putchar('G');
						}
					}
				}
			}
		}
		
	}
	return a*a;
}
