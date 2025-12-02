// demoDestructor1.cpp
// "gewone" destructor

#include <iostream>
#include <memory>
using namespace std;

class basis {
 protected:
   int i;

 public:
    basis(int _i) : i(_i) {
        cout << "constructor van basis " << i << endl;
    }
    ~basis() {
        cout << "destructor van basis " << i << endl;
    }
};

class afgeleid : public basis {
 public:
    afgeleid(int i) : basis(i) {
        cout << "constructor van afgeleid " << i << endl;
    }
    ~afgeleid() {
        cout << "destructor van afgeleid " << i << endl;
    }
};

int main() {
   cout << "basis b1(1);" << endl;
   basis b1(1);

   cout << "\nafgeleid a(2);" << endl;
   afgeleid a(2);

   cout << "\nunique_ptr<basis> up1 = make_unique<basis>(\"3\");" << endl;
   unique_ptr<basis> up1 = make_unique<basis>(3);

   cout << "\nunique_ptr<basis> up2 = make_unique<afgeleid>(\"4\");" << endl;
   unique_ptr<basis> up2 = make_unique<afgeleid>(4);

   cout << endl;
   return 0;
}
