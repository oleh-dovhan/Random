#include"RandGenerator.h"
# define M_PI 3.14159265358979323846

//////////////////////////

BasicRand::BasicRand() : prevValue(NAN), value(NAN){}
ll BasicRand::getRandValue()
{
	if (!randomization()) return NAN;
	else
	{
		prevValue = value;
		return value;
	}
}


// Алгоритми (перевірка умов)

ll BasicRand::gcd(ll first0, ll second0)
{
	if (second0 == 0) return first0;
	else return gcd(second0, first0 % second0);
}

ll BasicRand::gcdEx(ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcdEx(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

bool BasicRand::isSimple(ll value0)
{
	if (value0 <= 1 || value0 % 2 == 0) return false;
	bool isSimple = true;
	for (ll i = 3; i <= sqrt(static_cast <double> (value0)) && isSimple == true; i += 2)
	{
		if (value0 % i == 0) isSimple = false;
	}
	return isSimple;
}

std::vector <ll>& BasicRand::allFactors(ll value0, std::vector <ll> &array0)
{
	if (value0 > 1)
	{
		for (ll i = 2, j = 0; value0 != 1 && i <= value0; i++)
		{
			if (value0 % i == 0)
			{
				array0.push_back(i); j++;
				while (value0 % i == 0) value0 /= i;
			}
		}
	}
	return array0;
}

bool BasicRand::isArrayFactors(ll value0, std::vector <ll> array0)
{
	if (array0.size() == 0 || value0 <= 1) return false;
	bool isFactor = true;
	for (ll i = 0; i <= array0.size() && isFactor == true && value0 >= array0[i] && array0[i] > 0 ; i++)
	{
		if (value0 % array0[i] == 0) isFactor = true;
		else isFactor = false;
	}
	return isFactor;
}

bool BasicRand::isBelong_0_1(double value0)
{
	if (value0 <= 0 || value0 >= 1) return false;
	else return true;
}


///////////////////////////////
// X(n+1) = (a * X(n) + c)mod m

LinearCong_1::LinearCong_1()
{
	prevValue = firstValue;
}

ll LinearCong_1::getModule() { return m; }

bool LinearCong_1::randomization()
{
	if (!check()) return false;
	else
	{
		value = (a*prevValue + c) % m;
		return true;
	}
}

bool LinearCong_1::check()
{
	if (m <= 0) return false;
	if (a >= m || a < 0) return false;
	if (c >= m || c < 0) return false;
	if (firstValue >= m || firstValue < 0) return false;
	if (gcd(m, c) != 1) return false;
	if (m % 4 == 0 && (a - 1) % 4 != 0) return false;    
	std::vector <ll> tmpArr(1);  
	if (!isArrayFactors(a - 1, allFactors(m, tmpArr))) return false;    
	return true;
}


////////////////////////////////////////////
// X(n+1) = (d * X(n)^2 + a * X(n) + c)mod m

SquareLinear_2::SquareLinear_2()
{
	prevValue = firstValue;
}

ll SquareLinear_2::getModule() { return m; }

bool SquareLinear_2::randomization()
{
	if (!check()) return false;
	else
	{
		value = (d*prevValue*prevValue + a*prevValue + c) % m;
		return true;
	}
}

bool SquareLinear_2::check()
{
	if (m <= 0) return false;
	if (a >= m || a < 0) return false;
	if (c >= m || c < 0) return false;
	if (d >= m || d < 0) return false;
	if (firstValue >= m || firstValue < 0) return false;
	if (gcd(c, m) != 1) return false;
	std::vector <ll> tmpArr(1000);
	if (!isArrayFactors(a - 1, allFactors(m, tmpArr))) return false;
	if (!isArrayFactors(d, allFactors(m, tmpArr))) return false;
	if (m % 4 == 0 && !((a - 1) % 4 == d % 4 && d % 2 == 0)) return false;   
	if (m % 2 == 0 && d % 2 != (a - 1) % 2) return false;
	if (m % 3 == 0 && (3 * c) % 9 == d % 9) return false;
	return true;
}


////////////////////////////////
// X(n+1) = (X(n) + X(n-1))mod m

FibRand_3::FibRand_3()
{
	prevValue = firstValue;
	prevValueTwo = secondValue;
}

ll FibRand_3::getModule() { return m; }

ll FibRand_3::getRandValue()
{
	if (!randomization()) return NAN;
	else
	{
		prevValueTwo = prevValue;
		prevValue = value;
		return value;
	}
}

bool FibRand_3::randomization()
{
	if (!check()) return false;
	else
	{
		value = (prevValue + prevValueTwo) % m;
		return true;
	}
}

bool FibRand_3::check()
{
	if (m <= 0) return false;
	else return true;
}


////////////////////////////////////
// X(n+1) = (a * X(n)^(-1) + c)mod m

InverseCongSequence_4::InverseCongSequence_4()
{
	prevValue = firstValue;
}

bool InverseCongSequence_4::randomization()
{
	if (!check()) return false;
	else
	{
		ll inverseValue, y;
		ll g = gcdEx(prevValue, m, inverseValue, y);
		if (g != 1) return false;
		else
		{
			inverseValue = (inverseValue % m + m) % m;
			value = (a*inverseValue + c) % m;
			return true;
		}
	}
}

bool InverseCongSequence_4::check()
{
	if (m <= 0) return false;
	if (a >= m || a < 0) return false;
	if (c >= m || c < 0) return false;
	if (firstValue >= m || firstValue < 0) return false;
	//if (!isSimple(m)) return false;
	if (prevValue < 0) return false;
	if (a % 4 != 1) return false;
	if (c % 4 != 2) return false;
	return true;
}

ll InverseCongSequence_4::getModule() { return m; }


////////////////////////////
// Z(n) = (X(n) - Y(n))mod m

AssociationSets_5::AssociationSets_5()
{
	randValue = new FibRand_3; 
}

AssociationSets_5::~AssociationSets_5()
{
	if (randValue != NULL) { delete randValue; randValue = NULL; }
}

ll AssociationSets_5::getModule() { return m; }

bool AssociationSets_5::randomization()
{
	if (!check()) return false;
	else
	{
		ll f = randValue->getRandValue();
		ll s = randValue->getRandValue();
		if (f >= m || f < 0 || s >= m || s < 0) return false;
		else
		{
			value = ((f + m) % m + s) % m;
			return true;
		}
	}
}

bool AssociationSets_5::check()
{
	if (m <= 0 || m != randValue->getModule()) return false;
	else return true;
}


///////////////////////////////
// X(n) = m + (sum - 6) * sigma

ThreeSigma_6::ThreeSigma_6()
{
	oneRand = new FibRand_3;
	_12Values.reserve(12);
}

ThreeSigma_6::~ThreeSigma_6()
{
	if (oneRand != NULL) { delete oneRand; oneRand = NULL; }
}

ll ThreeSigma_6::getModule(){ return oneRand->getModule(); }

bool ThreeSigma_6::randomization()
{
	if (!generate_12_values(_12Values, oneRand) || !check()) return false;
	else
	{
		double tmp, sum = 0;
		for (int i = 0; i < 12; i++)
		{
			sum += _12Values[i];
		}
		_12Values.clear();
		tmp = m + (sum - 6)*sigma;
		tmp *= oneRand->getModule();
		value = static_cast <ll> (tmp);
		return true;
	}
}

bool ThreeSigma_6::check()
{
	if (m >= sigma) return false;
	if (_12Values.size() != 12) return false;
	bool isOk = true;
	for (int i = 0; i < 12 && isOk == true; i++)
	{
		if (_12Values[i] > sigma || _12Values[i] < m) isOk = false;
	}
	return isOk;
}

bool ThreeSigma_6::generate_12_values(std::vector <double>& array0, BasicRand* oneRand0)
{
	if (!array0.empty()) return false;
	else
	{
		for (int i = 0; i < 12; i++)
			array0.push_back(static_cast <double> (oneRand0->getRandValue()) / oneRand0->getModule());
		return true;
	}
}


///////////////////////////////


Polar_7::Polar_7()
{
	randValue = new FibRand_3;
}

Polar_7::~Polar_7()
{
	if (randValue != NULL) { delete randValue; randValue = NULL; }
}

bool Polar_7::randomization()
{
	double U1 = randValue->getRandValue() / static_cast <double> (randValue->getModule());
	double U2 = randValue->getRandValue() / static_cast <double> (randValue->getModule());
	if (!isBelong_0_1(U1) || !isBelong_0_1(U2)) return false;
	else
	{
		U1 = 2 * U1 - 1;
		U2 = 2 * U2 - 1;
		double S = U1*U1 + U2*U2;
		if (S >= 1) randomization();
		else
		{
			double X1 = U1 * sqrt((-2 * log(S)) / S);
			double X2 = U2 * sqrt((-2 * log(S)) / S);
			value = static_cast <ll> ((X1 + X2) * m / 2);
		}
		return true;
	}

}

ll Polar_7::getModule(){ return m; }


///////////////////////////////

Relations_8::Relations_8()
{
	randValue = new AssociationSets_5;
}

Relations_8::~Relations_8()
{
	if (randValue != NULL) { delete randValue; randValue = NULL; }
}

ll Relations_8::getModule(){ return m; }

bool Relations_8::randomization()
{
	double U = randValue->getRandValue() / static_cast <double> (randValue->getModule());
	double V = randValue->getRandValue() / static_cast <double> (randValue->getModule());
	if (!isBelong_0_1(U) || !isBelong_0_1(V)) return false;
	else
	{
		double X = (sqrt(8 / exp(1))) * ((V - 0.5) / U);
		if (X*X <= 5 - 4 * exp(1 / 4) * U) { value = static_cast <ll> (m*X); return true; }
		if (X*X >= (4 * exp(-1.35)) / U + 1.4) randomization();
		if (X*X > -4 * log(U)) randomization();
		else
		{
			value = static_cast <ll> (m*X); 
			return true;
		}
	}
}


///////////////
// x = -m*ln(U)

MethodLog_9::MethodLog_9()
{
	oneRand = new AssociationSets_5;
}

MethodLog_9::~MethodLog_9()
{
	if (oneRand != NULL){ delete oneRand; oneRand = NULL; }
}

bool MethodLog_9::randomization()
{
	double U = static_cast <double> (oneRand->getRandValue()) / oneRand->getModule();
	if (!isBelong_0_1(U)) return false;
	else
	{
		value = -1 * m*log(1 - U);
		return true;
	}
}

ll MethodLog_9::getModule() { return 1; }


///////////////


Arens_10::Arens_10()
{
	oneRand = new AssociationSets_5;
}

Arens_10::~Arens_10()
{
	if (oneRand != NULL) { delete oneRand; oneRand = NULL; }
}

ll Arens_10::getModule(){ return m; }

bool Arens_10::genAndCheck()
{
	U = static_cast <double> (oneRand->getRandValue()) / oneRand->getModule();
	if (U < 0 || U > 1) return false;
	else return true;
}

bool Arens_10::randomization()
{
	double Y, X;
	bool isOk = true;
	do
	{
		if (!genAndCheck()) isOk = false;
		else
		{
			Y = tan(M_PI*U);
			X = Y*sqrt(2 * a - 1) + a - 1;
		}	
	} while (isOk == true && X <= 0);
	if (isOk == false) return false;
	else
	{
		if (!genAndCheck()) isOk = false;
		else
		{
			if (U > (1 + Y*Y)*exp((a - 1)*log(X / (a - 1)) - Y*sqrt(2 * a - 1))) randomization();
			else { value = X * 10000; }
		}
		return isOk;
	}
}


