class Quotient
{
	private:
		int chis;
		unsigned int znam;
	public:
		Quotient(int chis = 0, int znam = 1)
		{
			if (!znam) znam = 1;
			char flag = (abs(chis) > znam);
			int min = (flag) ? znam : chis;
			int i = 2;
			while (i <= abs(min))
			{
				if (chis % i == 0 && znam % i == 0) 
				{
					chis = chis / i;
					znam = znam / i;
					min = (flag) ? znam : chis;
				}
				else i++;
			}
			if (znam < 0) {znam *= -1; chis *= -1;}
			this -> chis = chis;
			this -> znam = znam;
		}

		void print()
		{
			if (znam - 1) cout << chis << "/" << znam << endl; else cout << chis << endl;
		}
};