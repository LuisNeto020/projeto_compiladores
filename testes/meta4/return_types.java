class return_types {
    public static void main(String[] uncommon_name){
        double d;
        d = fun_double();
        System.out.print(d);
        System.out.print("\n");
        d = fun_int();
        System.out.print(d);
        System.out.print("\n");
        d = fun_double_from_int();
        System.out.print(d);
        System.out.print("\n");
        d = fun_double_from_int_fun();
        System.out.print(d);
        System.out.print("\n");
        d = fun_double_from_int_var();
        System.out.print(d);
        System.out.print("\n");
        d = fun_double_from_args(uncommon_name);
        System.out.print(d);
        System.out.print("\n");
        d = fun_double_from_unary_plus(uncommon_name);
        System.out.print(d);
        System.out.print("\n");

        System.out.print(1.3);
        System.out.print("\n");
    }

    public static double fun_double(){return 1.1;}
    public static int fun_int(){return 1;}

    public static double fun_double_from_int(){return 2;}

    public static double fun_double_from_int_fun(){return fun_int();}

    public static double fun_double_from_int_var(){
        double d;
        d = 0;
        return d + fun_int() + fun_double();
    }

    public static double fun_double_from_args(String[] str_arr){
        // return str_arr.length;
        return str_arr.length;
    }

    public static double fun_double_from_unary_plus(String[] str_arr){
        // return str_arr.length;
        return +1;
    }
}
