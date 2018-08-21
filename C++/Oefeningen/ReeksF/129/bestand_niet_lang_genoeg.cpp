#include <stdexcept>
using namespace std;
class bestand_niet_lang_genoeg: public runtime_error{
    public:
    bestand_niet_lang_genoeg():runtime_error("That's what she said") { }
    bestand_niet_lang_genoeg(const string & what):runtime_error(what) { }
};