class fluxControl2 {
    //Insert '30' as a param
    public static int a (int input){
		int i; i = 0;
		while( i < 10){
			input = input + 2;
			i = i+1;
		}
		return input;
    }
    
    public static int b(int input){
		int k; k = 0;
        while( k < 5){
			if(k == 1) { input = input - 2; }
			else {
				if( k == 2) {input = input *3;}
			}
			k = k + 1;
		}
		return input;
    }
    
	public static void main(String[] args) {
        
        int input;
		int aux, aux1;
		aux = 0; aux1 = 0;
		input = Integer.parseInt(args[0]);
		if(input < 10) {
			aux = a(input);
		} else {
			aux1 = b(input);
		}
		System.out.print(aux);
		System.out.print("\n");
		System.out.print(aux1);
		System.out.print("\n");
    }
	
}