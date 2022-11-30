// prob H
class shift_errors{

    public static void valid(String[] args) {
        int x;
        int b;
        x = 1<<(x*1);
    }

    public static void main(String[] args){
        int i;
        double d;
        boolean b;

        i = i << 1;
        d = i << 1;
        i = i << 1.1; // error
        i = i << true;  // error

        d = d << 1; // error
        i = d << 1; // error
        d = d << 1.1; // error
        i = d << 1.1; // error
        d = d << true; // error
        i = d << true; // error

        b = b << 1;     // error    
        i = b << 1;     // error
        b = b << 1.1;   // error
        i = b << 1.1;   // error
        b = b << true;  // error
        i = b << true;  // error
    }


}