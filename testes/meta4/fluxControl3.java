class fluxControl3 {
	//Insert '30' as a param
    public static int b(int input){
		int k; k = 0;
		int i,g; i = 0; g = 0;
		int is_pair; is_pair = 0;
        while( k < 5){
			if(k == 1) { 
				input = input - 2;
				i = 0;
				g = 0;
				while(i < 100){
					while(g < 50){
						input = input + 2;
						if((g % 2) == 0){
							is_pair = is_pair + 1;
						} 
						g = g + 1;							
					}
					g = 0;
					i = i + 1;
				}
			}
			else {
				if( k == 2) {input = input *3;}
			}
			k = k + 1;
		}
		System.out.print("Is pair: ");
		System.out.print(is_pair);
		System.out.print("|\n");
		return input;
    }
    public static void main(String[] args) {
		int aux1;
        aux1 = 40;
		aux1 = b(aux1);
		System.out.print(Integer.parseInt(args[0]));
		System.out.print("\n");
    }
}