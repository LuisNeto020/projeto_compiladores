class Call_Me_Maybe {
    // Breaking Bad e bem melhor que Game of Thrones
    public static void main(String[] args) {

        int i;
        double d;
        boolean b;

        // Exact match
        f();
        f(true);
        f(0e0);
        f(123);
        f(args);
        f(i, d);
        f(i, d, b);
        f(i, d, b, i);
        f(0., 1, 2., 3);
        f(0, .1, 2, .3);

        // Inexact match
        f(i, i);
        f(i, i, b);
        f(i, i, b, i);
        f(0., 1, 2, 3);
        f(0, 1, 2., 3);
        f(0, .1, 2, 3);
        f(0, 1, 2, .3);

        // Nested calls
        f(f(f(f(f(f(0))))));
        f(f(true),f(0),f(0.0));
        f(f(true),f(false),f(0.0));

        // Print result
        System.out.print(f(f(f(f(f(f(0)))))));
        System.out.print(f(f(true),f(0),f(0.0)));
        System.out.print(f(0e0));
        System.out.print(f(123));

    }

    public static void f() {
    }

    public static int f(boolean a) {
    }

    public static boolean f(double a) {
    }

    public static double f(int a) {
    }

    public static void f(String[] a) {
    }

    public static boolean f(int a, double b) {
    }

    public static boolean f(int a, double b, boolean c) {
    }

    public static boolean f(int a, double b, boolean c, int d) {
    }

    public static int f(double a, int b, double c, int d) {
    }

    public static double f(int a, double b, int c, double d) {
    }

}
