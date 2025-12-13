#define _USE_MATH_DEFINES // for C++
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;


class figuur {
	public:
		virtual double omtrek() const = 0;
		virtual double oppervlakte() const = 0;
		virtual void schrijf_soort(ostream &out) const = 0;
		friend ostream& operator<<(ostream &out, const figuur &f) {
			f.schrijf_soort(out);
			out<<" met omtrek "<<f.omtrek()<<" en oppervlakte "<<f.oppervlakte();		
			return out;	
		}		
};

class cirkel : public figuur {
	private:
		double straal;
		virtual void schrijf_soort(ostream &out) const { // virtual mag, maar moet niet
		                                                 // als je zeker bent dat er geen
		                                                 // verdere klassen afgeleid zullen
		                                                 // worden van cirkel
			out<<"cirkel";
		}
	public:
		cirkel(double s) : straal(s) {}
		double omtrek() const {
			return 2*M_PI*straal;
		}
		double oppervlakte() const {
			return M_PI*straal*straal;	
		}
};

class rechthoek : public figuur {
	private:
		double lengte, breedte;	
		virtual void schrijf_soort(ostream & out) const {
			out<<"rechthoek";
		}
	public:
		rechthoek(double l, double b) : lengte(l),breedte(b) {}
		double omtrek() const {
			return 2*(lengte+breedte);
		}
		double oppervlakte() const {
			return lengte*breedte;	
		}		
};

class vierkant : public rechthoek {
	private:		
		virtual void schrijf_soort(ostream & out) const {
			out<<"vierkant";
		}
	public:
		vierkant(double z) : rechthoek(z,z) {}
};
