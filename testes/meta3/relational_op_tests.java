class time_is_relative {
    public static void main(String[] args){
        int i;
        double d;
        boolean b;
        i = 0;
        d = 1.1;
        b = true;

        if (i < i){}   
        if (i <= i){}   
        if (i > i){}   
        if (i >= i){}   
        if (i < d){}   
        if (i <= d){}   
        if (i > d){}   
        if (i >= d){}   
        if (i < b){}    // error
        if (i <= b){}    // error
        if (i > b){}     // error
        if (i >= b){}    // error
        if (i < 0){}   
        if (i <= 0){}   
        if (i > 0){}   
        if (i >= 0){}   
        if (i < 1.1){}   
        if (i <= 1.1){}   
        if (i > 1.1){}   
        if (i >= 1.1){}   
        if (i < true){}  //error 
        if (i <= true){} //error  
        if (i > true){}  //error 
        if (i >= true){} //error  
        if (d < i){}   
        if (d <= i){}   
        if (d > i){}   
        if (d >= i){}   
        if (d < d){}   
        if (d <= d){}   
        if (d > d){}   
        if (d >= d){}   
        if (d < b){}   //error
        if (d <= b){}   //error
        if (d > b){}   //error
        if (d >= b){}   //error
        if (d < 0){}   
        if (d <= 0){}   
        if (d > 0){}   
        if (d >= 0){}   
        if (d < 1.1){}   
        if (d <= 1.1){}   
        if (d > 1.1){}   
        if (d >= 1.1){}   
        if (b < i){}   //error
        if (b <= i){}   //error
        if (b > i){}   //error
        if (b >= i){}   //error
        if (b < d){}   //error
        if (b <= d){}   //error
        if (b > d){}   //error
        if (b >= d){}   //error
        if (b < true){}   //error
        if (b <= true){}   //error
        if (b > true){}   //error
        if (b >= true){}   //error
        if (0 < i){}   
        if (0 <= i){}   
        if (0 > i){}   
        if (0 >= i){}   
        if (0 < d){}   
        if (0 <= d){}   
        if (0 > d){}   
        if (0 >= d){}   
        if (0 < b){}   //error
        if (0 <= b){}   //error
        if (0 > b){}   //error
        if (0 >= b){}   //error
    }
}