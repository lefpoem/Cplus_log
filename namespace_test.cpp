#include <string>
//namespace define
namespace cplusplus_primer{
    class Sales_item{};
    Sales_item operator+(const Sales_item&,const Sales_item&);
    class Query{
    public:
        Query(const std::string&);
        std::ostream &dispaly(std::ostream& ) const;
    };
    class Query_base{};
}
namespace primer = cplusplus_primer;//primer is other name of cplusplus_primer
primer::Query tq;
namespace local{
    namespace {
        int i;//程序开始时创建直到程序结束,为命名空间局部于特定文件
    }
}
namespace blip{
    int bi=16,bj=12,bk=23;
    //other declaration
}
int bj=0;
void manip()
{
    //using directive-names in blip "added" to global scope
    using namespace blip;
    //clash between ::bj and blip::bj
    ++blip::bj;
    ++::bj;
}
namespace AW{
    int print(int);
}
namespace Primer{
    double print(double);
}
//using directive
//from an overloaded set of functions from different namespace
using namespace AW;
using namespace Primer;
long double print(long double);
int main()
{
    print(1);//calls ALL::print(int)
    print(3.1);//calls Primer::print(double)
    return 0;
}
