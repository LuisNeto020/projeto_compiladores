class strings {
    // por args com 1 2 3 4 5
    public static int i;
    public static void main(String[] args){
        System.out.print("\r\\\"\f\t\n");
        int a;
        a = args.length;
        System.out.print("Number of arguments:\t");
        System.out.print(a);
        System.out.print("\n");
        if (a > 0){
            while ((a+1) > ( i = i + 1)){
                System.out.print("Arg (");
                System.out.print(i);
                System.out.print("): ");
                System.out.print(Integer.parseInt(args[i-1]));
                System.out.print("\n");
                // i = i + 1;
            }
        } else {
            System.out.print("No arguments :(");
        }
        System.out.print("\n");
    }
}