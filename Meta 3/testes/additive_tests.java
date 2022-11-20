class sub_2_pewdiepie {
    public static void main(String[] args){
        int i;
        double d;
        boolean b;

        i = 1;
        d = 1.1;
        b = true;

        i = i + i;
        i = i - i;

        i = i + d; // error 
        i = i - d; // error

        i = i + b; // error
        i = i - b; // error

        i = i + args; //error
        i = i - args; //error

        d = i + i;
        d = i - i;

        d = i + d;
        d = i - d;

        d = i + b; //error
        d = i - b; //error

        d = i + args; //error
        d = i - args; //error

    }
}