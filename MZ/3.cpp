class Vec{
    double *v;
    int len;
	public:
	    explicit Vec(int len_inp, double *arr);
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
};

Vec::Vec(int len_inp, double *arr=nullptr){
    len = len_inp;
    v = new double[len];
    int i;
    if (arr == nullptr) 
    	for (i=0; i < len; i++) v[i] = 0; 
    else
        for (i=0; i < len; i++) v[i] = arr[i];
}

Vec::Vec(const Vec &a)
{
    len = a.len;
    v = new double[len];
    for (int i = 0; i < len; i++) v[i] = a.v[i];
}
Vec::~Vec()
{
    delete []v;
}

void Vec::set(double arg, int coord)
{
    if ((coord >= len) || (coord < 0)) return;
    v[coord] = arg;
}

double Vec::euc_norm() const
{
    double res = 0;
    for (int i = 0; i < len; i++) res += v[i] * v[i];
    return sqrt(res);
}

double Vec::max_norm() const
{
    double max =- 1;
    for (int i = 0; i < len; i++) {if (abs(v[i]) > max) max = abs(v[i]);}
    return max;
}
void Vec::print() const
{
    cout << "(";
    for (int i = 0; i < len - 1; i++) cout << v[i] << ",";
    cout << v[len-1] << ")" << endl;
}