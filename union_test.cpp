//objects of type TokenVlue have a single member,which could be of any of the listed types
union TokenValue{
    char cval;
    int ival;
    double dval;
};//union can't use fot base class
TokenValue first_token={'a'};//initialization
TokenValue last_token;
TokenValue *pt=new TokenValue;
class Token{
public:
    enum TokenKind{INT,CHAR,DBL};
    TokenKind tok;
    union{
        char cval;
        int ival;
        double dval;
    }val;//member val is a union fo the 3 listed types
};
int main(){
    last_token.cval='z';
    pt->ival=42;
    Token token;
    switch (token.tok)
    {
    case Token::INT:/* constant-expression */
        token.val.ival=42;/* code */
        break;
    case Token::CHAR:
        token.val.cval='a';break;
    case Token::DBL:
        token.val.dval=3.14;break;
    }
}
