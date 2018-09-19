#pragma once
#include <vector>
#define ll long long

class BasicRand 
{
private:
	BasicRand(const BasicRand&);
	//BasicRand operator= (const BasicRand&);
public:
	BasicRand();
	virtual ll getModule() = 0;
	virtual ll getRandValue();
protected:
	ll prevValue;
	ll value;
private:
	virtual bool randomization() = 0;

//Алгоритми(для перевірки умов)
protected:
	ll gcd(ll, ll);
	ll gcdEx(ll, ll, ll&, ll&);
	std::vector <ll>& allFactors(ll, std::vector <ll>&);
	bool isArrayFactors(ll, std::vector<ll>);
	bool isSimple(ll);
	bool isBelong_0_1(double);
};


class LinearCong_1 : public BasicRand
{
private:
	LinearCong_1(const LinearCong_1&);
	LinearCong_1 operator= (const LinearCong_1&);
public:
	LinearCong_1();
	ll getModule();
private:
	bool randomization();
	bool check();                                                          

	// X(n+1) = (a * X(n) + c)mod m
	static const ll firstValue = 0;
	static const ll a = 10005;
	static const ll c = 47;
	static const ll m = 20008; 
};

class SquareLinear_2 : public BasicRand
{
private:
	SquareLinear_2(const SquareLinear_2&);
	SquareLinear_2 operator= (const SquareLinear_2&);
public:
	SquareLinear_2();
	ll getModule();
private:
	bool randomization();
	bool check();                                                              

	// X(n+1) = (d * X(n)^2 + a * X(n) + c)mod m
	static const ll firstValue = 0;
	static const ll d = 10004;
	static const ll a = 10005;
	static const ll c = 47;
	static const ll m = 20008;
};

class FibRand_3 : public BasicRand 
{
private:
	FibRand_3(const FibRand_3&);
	FibRand_3 operator= (const FibRand_3&);
public:
	FibRand_3();
	ll getModule();
	ll getRandValue();
private:
	bool randomization();
	bool check();                                                       

	// X(n+1) = (X(n) + X(n-1))mod m
	static const ll m = 10007;
	static const ll firstValue = 1;
	static const ll secondValue = 1;
	ll prevValueTwo;
};

class InverseCongSequence_4 : public BasicRand
{
private:
	InverseCongSequence_4(const InverseCongSequence_4&);
	InverseCongSequence_4 operator= (const InverseCongSequence_4&);
public:
	InverseCongSequence_4();
	ll getModule();
private:
	bool randomization();
	bool check();

	// X(n+1) = (a * X(n)^(-1) + c)mod p
	static const ll firstValue = 12345678;
	static const ll a = 98765;
	static const ll c = 43210;
	static const ll m = 1073676287;
};

class AssociationSets_5 : public BasicRand
{
private:
	AssociationSets_5(const AssociationSets_5&);
	AssociationSets_5 operator= (const AssociationSets_5&);
public:
	AssociationSets_5();
	~AssociationSets_5();
	ll getModule();
private:
	BasicRand* randValue;
private:
	bool randomization();
	bool check();                                                    

	// Z(n) = (X(n) - Y(n))mod m
	static const ll m = 10007;
};

class ThreeSigma_6 : public BasicRand 
{
private:
	ThreeSigma_6(const ThreeSigma_6&);
	ThreeSigma_6 operator= (const ThreeSigma_6&);
public:
	ThreeSigma_6();
	~ThreeSigma_6();
	ll getModule();
private:
	BasicRand* oneRand;
	std::vector <double> _12Values;
	bool generate_12_values(std::vector <double>&, BasicRand*);
private:
	bool randomization();
	bool check();

	// X(n) = m + (sum - 6) * sigma
	static const ll m = 0;
	static const ll sigma = 1;
};

class Polar_7 : public BasicRand
{
private:
	Polar_7(const Polar_7&);
	Polar_7 operator= (const Polar_7&);
public:
	Polar_7();
	~Polar_7();
	ll getModule();
private:
	BasicRand* randValue;
private:
	bool randomization();
	//bool check();                                                       
	static const ll m = 10000;
};

class Relations_8 : public BasicRand
{
private:
	Relations_8(const Relations_8&);
	Relations_8 operator= (const Relations_8&);
public:
	Relations_8();
	~Relations_8();
	ll getModule();
private:
	BasicRand* randValue;
private:
	bool randomization();
	//bool check();                                                              
	static const ll m = 10000;
};

class MethodLog_9 : public BasicRand
{
private:
	MethodLog_9(const MethodLog_9&);
	MethodLog_9 operator= (const MethodLog_9&);
public:
	MethodLog_9();
	~MethodLog_9();
	ll getModule();
private:
	BasicRand* oneRand;
private:
	bool randomization();
	//bool check();

	// x = -m*ln(U)
	static const ll m = 30;
};

class Arens_10 : public BasicRand
{
private:
	Arens_10(const Arens_10&);
	Arens_10 operator= (const Arens_10&);
public:
	Arens_10();
	~Arens_10();
	ll getModule();
	double U;
	BasicRand* oneRand;
private:
	bool randomization();
	bool genAndCheck();

	static const ll a = 50;
	static const ll m = 10000;
};