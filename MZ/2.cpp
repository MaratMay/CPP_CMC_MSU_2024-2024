class Rect
{
	private:
		int x, y;
		unsigned int wd, hd;
	public:
		Rect(int x, int y, unsigned int wd, unsigned int hd)
		{
			this -> x = x;
			this -> y = y;
			this -> wd = wd;
			this -> hd = hd;
		}

		Rect(unsigned int num = 1)
		{
			wd = num;
			hd = num;
			x = 0;
			y = 0;
		}

		void print_corner()
		{
			cout << "(" << x << "," << y << ")" << endl;
		}

		void print_sz()
		{
			cout << "wd=" << wd << " hd=" << hd << endl;
		}

		int area()
		{
			return wd * hd;
		}

		int perimeter()
		{
			return (wd + hd) * 2;
		}

		bool intersect(Rect r)
		{
			int new_x = x + wd, new_y = y + hd, r_new_x = r.x + r.wd, r_new_y = r.y + r.hd;
			return (x <= r_new_x) && (new_x >= r.x) && (new_y >= r.y) && (y <= r_new_y);
		}
};