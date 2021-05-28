#include <iostream>
typedef unsigned int Bit;
class File{
public:
    Bit mode: 2;
    Bit modified: 1;
    Bit prot_owner: 3;
    Bit prot_group: 3;
    Bit prot_world: 3;
    void write();
    void close();
};
void File::write()
{
    modified=1;
}
void File::close()
{
    if(modified)
        mode=1;//...save contents
}
enum {READ=01,WRITE=02};
int main(){
    File myFile;
    myFile.mode |= READ;//set the READ bit
    if(myFile.mode& READ)//IF the READ bit is on
        std::cout << "myFILe.mode READ is set\n";
}
