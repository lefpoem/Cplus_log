//局部类只能访问在外围作用域中定义的的类型名，static变量和枚举成员
int a,val;
void foo(int val){
    static int si;
    enum Loc{a=1024,b};
    //Bar is local to foo
    class Bar{
    public:
        Loc locval;
        int barVal;
        void fooBar(Loc l=a)
        {
            //barVal=val;error:val is local to foo
            barVal=::val;
            barVal=si;
            locval=b;
        }
        class nested;
    };
    class Bar::nested{
        //....
    };
}
