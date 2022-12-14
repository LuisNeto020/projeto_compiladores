class a{
	public static int global_var;
	public static void main(String[] args){
		int a;
		boolean b;
		double c;

		a = 1;
		System.out.print(a);
		System.out.print("\n");
		a = +1;
		System.out.print(a);
		System.out.print("\n");
		a = -1;
		System.out.print(a);
		System.out.print("\n");

		b = true;
		System.out.print(b);
		System.out.print("\n");
		b = false;
		System.out.print(b);
		System.out.print("\n");

		c = 2.0;
		System.out.print(c);
		System.out.print("\n");
		c = 2.2;
		System.out.print(c);
		System.out.print("\n");
		c = 2;
		System.out.print(c);
		System.out.print("\n");
		a = 1;
		c = a;
		System.out.print(c);
		System.out.print("\n");
		c = +2.2;
		System.out.print(c);
		System.out.print("\n");
		c = -2.2;
		System.out.print(c);
		System.out.print("\n");
		c = +a;
		System.out.print(c);
		System.out.print("\n");
		c = -a;
		System.out.print(c);
		System.out.print("\n");

		global_var = 10;
		System.out.print(global_var);
		System.out.print("\n");


		/*
		//Ao descomentar isto, note-se que e preciso colocar um argumento, por exemplo:
		//lli-3.9 A.ll 3

		//E acrescentar ao output:
		//3
		//1
		//3
		//1
		//-3
		//-1

		a = Integer.parseInt(args[0]);
		System.out.print(a);
		System.out.print("\n");
		a = args.length;
		System.out.print(a);
		System.out.print("\n");
		a = +Integer.parseInt(args[0]);
		System.out.print(a);
		System.out.print("\n");
		a = +args.length;
		System.out.print(a);
		System.out.print("\n");
		a = -Integer.parseInt(args[0]);
		System.out.print(a);
		System.out.print("\n");
		a = -args.length;
		System.out.print(a);
		System.out.print("\n");
		*/


	}
}