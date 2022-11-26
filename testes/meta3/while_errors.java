// prob H
class while_errors {
    public static void main(String[] args){
        int i;
        boolean b;
        double d;
        while(b){}
        while(true){}
        while(i){}      //error
        while(1){}      //error
        while(d){}      //error
        while(1.1){}    //error
        while(1<<1){}   //error
        while(true<<true){};    //error
        while(b<<b){};  //error
        while(1^1){};   //error
        while(true^false){};
    }
}