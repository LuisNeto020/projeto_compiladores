class Main {
	public static int overload;
    public static void overload(int n){
        System.out.print("I have a parameter");
    }

    public static void overload(){
         System.out.print("I don't have a parameter");
    }

    public static void main(String[] args){ //Antes estava: public static int main (int n)
    	if(args.length > 0)	overload(Integer.parseInt(args[0]));
		else overload();
		System.out.print("\n");
    }
}