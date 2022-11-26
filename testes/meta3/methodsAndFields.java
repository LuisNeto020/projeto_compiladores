      
	     
class newClass{
	public static int i;
	public static boolean b;
	public static int main(int a, int c, double d) { 
		boolean b; //Local variable with the same name of a global variable, is that ok?
		int i1;
		
		return 0;
	}
	public static int pI;
	public static void a (int a, int b, boolean c) {
		int d;
		d = b;
		int i;
		boolean b;
		b= true;
		double f;
		f = 0.03;
		return d;
	
	}

	public static void a(){

	}
	public static double test(int a, int b, double s, boolean e, boolean e) { //Two variables with same name, what do you do?
		a(2,3, true);
		int a, b, c, d, e;
		int finalI;
		finalI = 2 + 3;
		return 0.02*0.03/5; //Does this matter to symbol table?
	}

	public static int sum(int k,int j) {
		test(2,2,2.0,true,false);
		return k + j;
	}
}
