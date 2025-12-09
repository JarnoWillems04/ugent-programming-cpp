#include <stdexcept>
using namespace std;

class file_error : public runtime_error {
public:
   file_error() : runtime_error("can't open file") {}
   file_error(const string &what) : runtime_error(what) {}
};
