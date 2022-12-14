class Main {
	public static int overload;
    public static boolean overload(boolean n){
        System.out.print("I have two doubles\n");
		return false;
    }
    public static double overload(double n){
         System.out.print("I have one double\n");
		 return 2.2*2 + main(2) / 5 * 6 + 2*3 + 3*4 + 2 *8 + 5*9 + overload(2,2);
    }	
	public static int overload(double b, double b1){
		overload = 2 + overload;
		double overload;
        System.out.print("I have one int\n");
		return 5;
    }
	public static int overload(int b, int b1){
		return 5;
    }	
	public static int main(int n){
         System.out.print("I'm the fake main\n");
		 return 5;
    }
    public static void main(String[] args){
    	if(args.length > 0)	overload(Integer.parseInt(args[0]));
		else overload(5);
		System.out.print(!false);
		System.out.print("\n");
		int a; a = 222_22_22;
		double d; d = 2323_2332e1;
		int b; b = 3;
		
		System.out.print(a);
		//System.out.print(d%2);
		//System.out.print(2.2%2);
		boolean b1; b1 = true;
		System.out.print(a + a +a + 8%2 + d/3 + a*d + d - a + (a*b/+d)*(a*b/+d) + overload(2.2) + (d = overload(1,1)) + main(5) + Integer.parseInt(args[args.length-1]));
		System.out.print("\na:\n");
		System.out.print(a);
		System.out.print("Before if\n");
		if(a >= 2*2+3/5 + main(5) ) if( a <= 2) if(2 >= a) if(2 <= a) if(a==2) if(2==a) if(a>2) if(a<2) if(2>a) if (2<a) if(a!=2) if(2!=a) {}
		System.out.print("After ifs\n");
		if(d >= 2) if( d <= 2) if(2 >= d) if(2 <= d) if(d==2) if(2==d) if(d>2) if(d<2) if(2>d) if (2<d) if(d!=2) if(2!=d) {}
		if(d >= 2.2) if( d <= 2.2) if(2.2 >= d) if(2.2 <= d) if(d==2.2) if(2.2==d) if(d>2.2) if(d<2.2) if(2.2>d) if (2.2<d) if(d!=2.2) if(2.2!=d) {}
		if(b1==true && d >= 2.2 && 2 >= d && 2.2 <= d || 2.2== d + (d=2.3 + (a = 2) + (d = 2))) if(true==b1) if(b1!=true) if(true!=b1) {}
		if(b1&&true || b1||true && !b1^false) 
		if(true&&b1 || true||b1 && false^!b1) {}
		System.out.print("After ifs\n");
		System.out.print(a * -d);
		System.out.print("\n");
		System.out.print(false^!b1);
		System.out.print("\n");
		double d1;
		d1 = args.length + 1.1 + overload(3) + 3*3 + 2+2 + -2 + 3/3;
		int i; i = 0; int j; j = 0;
		System.out.print("Before while\n");
		while(i<10) while(10>i) while(20>j && i<10){ i=i+1;j=j+1;if(i==10) if(j==9) {}}
    }
}