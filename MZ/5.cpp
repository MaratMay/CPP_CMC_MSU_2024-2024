class Vec{
    double *v;
    int len;
	public:
	    explicit Vec(int len_inp, double *arr=nullptr);
	    Vec(const Vec &a);
	    ~Vec();
	    void set(double arg, int coord);
	    double get(int coord) const
	    {
	        if ((coord>=len) || (coord<0)) return 0;
	        return v[coord];
	    }
	    double euc_norm() const;
	    double max_norm() const;
	    void print() const;
	    Vec operator+(const Vec & op) const;
        Vec operator-(const Vec & op) const;
        Vec operator*(double a) const;
        friend Vec operator*(double a, const Vec & op);
		const Vec& operator= (const Vec& op);
		friend bool operator== (const Vec& op1, const Vec& op2);
		double& operator[] (int index) {return v[index];}
		friend ostream& operator<<(ostream& os, const Vec& op);
};

const Vec& Vec::operator= (const Vec& op)
{
	if (*this == op) return *this;
	delete []v;
	v = new double[op.len];
	len = op.len;
	int i;
	for(i=0; i < len; i++) v[i] = op.v[i];
	return *this;
}

Vec Vec::operator+(const Vec & op) const
{
    Vec tmp(len);
    for (int i = 0; i < len; i++) tmp.v[i] = v[i] + op.v[i];
    return tmp;
}

Vec Vec::operator-(const Vec & op) const
{
    Vec tmp(len);
    for (int i = 0; i < len; i++) tmp.v[i] = v[i] - op.v[i];
    return tmp;
}

Vec Vec::operator*(double a) const
{
    Vec tmp(len);
    for (int i = 0; i < len; i++) tmp.v[i] = v[i] * a;
    return tmp;
}

Vec operator*(double a, const Vec& op){
    Vec tmp(op.len);
    for (int i = 0; i < op.len; i++) tmp.v[i] = op.v[i] * a;
    return tmp;
}

bool operator== (const Vec& op1, const Vec& op2)
{
	if (op1.len != op2.len) return false;
	int i;
	for (i=0; i < op1.len; i++) if (op1.v[i] != op2.v[i]) return false;
	return true;
}

ostream& operator<<(ostream& os, const Vec& op)
{
	int i=0;
	os << "(";
	for(i=0; i < op.len - 1; i++) os << op.v[i] << ",";
	os << op.v[op.len-1] << ")";
	return os;
}

Vec::Vec(int len_inp, double *arr){
    len = len_inp;
    v = new double[len];
    int i;
    if (arr == nullptr) 
    	for (i=0; i < len; i++) v[i] = 0; 
    else
        for (i=0; i < len; i++) v[i] = arr[i];
}

Vec::Vec(const Vec &a){
    len = a.len;
    v = new double[len];
    for (int i = 0; i < len; i++) v[i] = a.v[i];
}
Vec::~Vec(){
    delete []v;
}

void Vec::set(double arg, int coord){
    if ((coord >= len) || (coord < 0)) return;
    v[coord] = arg;
}

double Vec::euc_norm() const{
    double res = 0;
    for (int i = 0; i < len; i++) res += v[i] * v[i];
    return sqrt(res);
}

double Vec::max_norm() const{ 
    double max =- 1;
    for (int i = 0; i < len; i++) {if (abs(v[i]) > max) max = abs(v[i]);}
    return max;
}
void Vec::print() const{
    cout << "(";
    for (int i = 0; i < len - 1; i++) cout << v[i] << ",";
    cout << v[len-1] << ")" << endl;
}