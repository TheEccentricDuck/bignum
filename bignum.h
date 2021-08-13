#ifndef _BIGNUM_H_
#define _BIGNUM_H_

#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

class bignum
{
	private:

		vector<int> a;
		int sign;

		bignum make_bignum(vector<int> b,int s) const
		{
			bignum t;
			t.sign=s;
			t.a.clear();
			for (vector<int>::iterator it=b.begin();it!=b.end();it++) t.a.push_back(*it);
			return t;
		}

	public:

		bignum()
		{
			sign=0;
			a.resize(1);
			a[0]=0;
		}

		bignum(const char *s)
		{
			int n=strlen(s);
			if (s[0]=='-')
			{
				sign=1;
				for (int i=0;i<n-1;i++) a.push_back(s[n-i]-48);
			}
			else for (int i=0;i<n;i++) a.push_back(s[n-i-1]-48);
		}

		bignum(int x)
		{
			sign=x<0?1:0;
			int t=x<0?-x:x;
			if (!t) a.push_back(t);
			else
			{
				while (t)
				{
					a.push_back(t%10);
					t/=10;
				}
			}
		}

		bignum(short x)
		{
			sign=x<0?1:0;
			int t=x<0?-x:x;
			if (!t) a.push_back(t);
			else
			{
				while (t)
				{
					a.push_back(t%10);
					t/=10;
				}
			}
		}

		bignum(long x)
		{
			sign=x<0?1:0;
			long t=x<0?-x:x;
			if (!t) a.push_back(t);
			else
			{
				while (t)
				{
					a.push_back(t%10);
					t/=10;
				}
			}
		}

		bignum(long long x)
		{
			sign=x<0?1:0;
			long long t=x<0?-x:x;
			if (!t) a.push_back(t);
			else
			{
				while (t)
				{
					a.push_back(t%10);
					t/=10;
				}
			}
		}

		bignum(unsigned x)
		{
			sign=0;
			unsigned t=x;
			if (!t) a.push_back(t);
			else
			{
				while (t)
				{
					a.push_back(t%10);
					t/=10;
				}
			}
		}

		bignum(unsigned short x)
		{
			sign=0;
			unsigned short t=x;
			if (!t) a.push_back(t);
			else
			{
				while (t)
				{
					a.push_back(t%10);
					t/=10;
				}
			}
		}

		bignum(unsigned long x)
		{
			sign=0;
			unsigned long t=x;
			if (!t) a.push_back(t);
			else
			{
				while (t)
				{
					a.push_back(t%10);
					t/=10;
				}
			}
		}

		bignum(unsigned long long x)
		{
			sign=0;
			unsigned long long t=x;
			if (!t) a.push_back(t);
			else
			{
				while (t)
				{
					a.push_back(t%10);
					t/=10;
				}
			}
		}

		void in()
		{
			a.clear();
			vector<int> t;
			char c;
			c=getchar();
			while (!(c>='0'&&c<='9'))
			{
				if (c=='-') sign=1;
				c=getchar();
			}
			while (c>='0'&&c<='9')
			{
				t.push_back(c-48);
				c=getchar();
			}
			for (int i=t.size()-1;i>=0;i--) a.push_back(t[i]);
			return;
		}

		void out() const
		{
			if (sign) putchar('-');
			for (int i=a.size()-1;i>=0;i--) putchar(a[i]+48);
			return;
		}

		inline bignum operator = (const bignum x)
		{
			sign=x.sign;
			a.clear();
			for (int i=0;i<x.a.size();i++) a.push_back(x.a[i]);
			return x;
		}

		inline bignum operator = (const char *s)
		{
			int n=strlen(s);
			bignum t;
			a.clear();
			if (s[0]=='-')
			{
				sign=1;
				t.sign=1;
				for (int i=0;i<n-1;i++)
				{
					a.push_back(s[n-i]-48);
					t.a.push_back(s[n-i]-48);
				}
			}
			else
			{
				for (int i=0;i<n;i++)
				{
					a.push_back(s[n-i-1]-48);
					t.a.push_back(s[n-i-1]-48);
				}
			}
			return t;
		}

		inline bignum operator = (string s)
		{
			bignum t;
			a.clear();
			if (s[0]=='-')
			{
				sign=1;
				t.sign=1;
				for (int i=0;i<s.size()-1;i++)
				{
					a.push_back(s[s.size()-i]-48);
					t.a.push_back(s[s.size()-i]-48);
				}
			}
			else
			{
				for (int i=0;i<s.size();i++)
				{
					a.push_back(s[s.size()-i-1]-48);
					t.a.push_back(s[s.size()-i-1]-48);
				}
			}
			return t;
		}

		inline int operator = (const int x)
		{
			a.clear();
			if (!x)
			{
				a.push_back(x);
				return x;
			}
			int k=x;
			if (x<0)
			{
				sign=1;
				k=-k;
			}
			while (k)
			{
				a.push_back(k%10);
				k/=10;
			}
			return x;
		}

		inline short operator = (const short x)
		{
			a.clear();
			if (!x)
			{
				a.push_back(x);
				return x;
			}
			short k=x;
			if (x<0)
			{
				sign=1;
				k=-k;
			}
			while (k)
			{
				a.push_back(k%10);
				k/=10;
			}
			return x;
		}

		inline long operator = (const long x)
		{
			a.clear();
			if (!x)
			{
				a.push_back(x);
				return x;
			}
			long k=x;
			if (x<0)
			{
				sign=1;
				k=-k;
			}
			while (k)
			{
				a.push_back(k%10);
				k/=10;
			}
			return x;
		}

		inline long long operator = (const long long x)
		{
			a.clear();
			if (!x)
			{
				a.push_back(x);
				return x;
			}
			long long k=x;
			if (x<0)
			{
				sign=1;
				k=-k;
			}
			while (k)
			{
				a.push_back(k%10);
				k/=10;
			}
			return x;
		}

		inline unsigned operator = (const unsigned x)
		{
			a.clear();
			if (!x)
			{
				a.push_back(x);
				return x;
			}
			unsigned k=x;
			while (k)
			{
				a.push_back(k%10);
				k/=10;
			}
			return x;
		}

		inline unsigned short operator = (const unsigned short x)
		{
			a.clear();
			if (!x)
			{
				a.push_back(x);
				return x;
			}
			unsigned short k=x;
			while (k)
			{
				a.push_back(k%10);
				k/=10;
			}
			return x;
		}

		inline unsigned long operator = (const unsigned long x)
		{
			a.clear();
			if (!x)
			{
				a.push_back(x);
				return x;
			}
			unsigned long k=x;
			while (k)
			{
				a.push_back(k%10);
				k/=10;
			}
			return x;
		}

		inline unsigned long long operator = (const unsigned long long x)
		{
			a.clear();
			if (!x)
			{
				a.push_back(x);
				return x;
			}
			unsigned long long k=x;
			while (k)
			{
				a.push_back(k%10);
				k/=10;
			}
			return x;
		}

		inline bool operator < (const bignum x) const
		{
			if (!sign&&x.sign) return false;
			if (sign&&!x.sign) return true;

			if (!sign&&!x.sign)
			{
				if (a.size()!=x.a.size()) return a.size()<x.a.size();
				int k=a.size()-1;
				while (k>=0&&a[k]==x.a[k]) k--;
				if (k==-1) return false;
				return a[k]<x.a[k];
			}

			if (a.size()!=x.a.size()) return a.size()>x.a.size();
			int k=a.size()-1;
			while (k>=0&&a[k]==x.a[k]) k--;
			if (k==-1) return false;
			return a[k]>x.a[k];
		}

		inline bool operator < (const int x) const
		{
			if (!sign&&x<0) return false;
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<t;
		}

		inline bool operator < (const short x) const
		{
			if (!sign&&x<0) return false;
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<t;
		}

		inline bool operator < (const long x) const
		{
			if (!sign&&x<0) return false;
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<t;
		}

		inline bool operator < (const long long x) const
		{
			if (!sign&&x<0) return false;
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<t;
		}

		inline bool operator < (const unsigned x) const
		{
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<t;
		}

		inline bool operator < (const unsigned short x) const
		{
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<t;
		}

		inline bool operator < (const unsigned long x) const
		{
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<t;
		}

		inline bool operator < (const unsigned long long x) const
		{
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<t;
		}

		inline bool operator > (const bignum x) const
		{
			if (!sign&&x.sign) return true;
			if (sign&&!x.sign) return false;

			if (!sign&&!x.sign)
			{
				if (a.size()!=x.a.size()) return a.size()>x.a.size();
				int k=a.size()-1;
				while (k>=0&&a[k]==x.a[k]) k--;
				if (k==-1) return false;
				return a[k]>x.a[k];
			}

			if (a.size()!=x.a.size()) return a.size()<x.a.size();
			int k=a.size()-1;
			while (k>=0&&a[k]==x.a[k]) k--;
			if (k==-1) return false;
			return a[k]<x.a[k];
		}

		inline bool operator > (const int x) const
		{
			if (!sign&&x<0) return true;
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>t;
		}

		inline bool operator > (const short x) const
		{
			if (!sign&&x<0) return true;
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>t;
		}

		inline bool operator > (const long x) const
		{
			if (!sign&&x<0) return true;
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>t;
		}

		inline bool operator > (const long long x) const
		{
			if (!sign&&x<0) return true;
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>t;
		}

		inline bool operator > (const unsigned x) const
		{
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>t;
		}

		inline bool operator > (const unsigned short x) const
		{
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>t;
		}

		inline bool operator > (const unsigned long x) const
		{
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>t;
		}

		inline bool operator > (const unsigned long long x) const
		{
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>t;
		}

		inline bool operator <= (const bignum x) const
		{
			if (!sign&&x.sign) return false;
			if (sign&&!x.sign) return true;

			if (!sign&&!x.sign)
			{
				if (a.size()!=x.a.size()) return a.size()<x.a.size();
				int k=a.size()-1;
				while (k>=0&&a[k]==x.a[k]) k--;
				if (k==-1) return true;
				return a[k]<x.a[k];
			}

			if (a.size()!=x.a.size()) return a.size()>x.a.size();
			int k=a.size()-1;
			while (k>=0&&a[k]==x.a[k]) k--;
			if (k==-1) return true;
			return a[k]>x.a[k];
		}

		inline bool operator <= (const int x) const
		{
			if (!sign&&x<0) return false;
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<=t;
		}

		inline bool operator <= (const short x) const
		{
			if (!sign&&x<0) return false;
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<=t;
		}

		inline bool operator <= (const long x) const
		{
			if (!sign&&x<0) return false;
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<=t;
		}

		inline bool operator <= (const long long x) const
		{
			if (!sign&&x<0) return false;
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<=t;
		}

		inline bool operator <= (const unsigned x) const
		{
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<=t;
		}

		inline bool operator <= (const unsigned short x) const
		{
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<=t;
		}

		inline bool operator <= (const unsigned long x) const
		{
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<=t;
		}

		inline bool operator <= (const unsigned long long x) const
		{
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)<=t;
		}

		inline bool operator >= (const bignum x) const
		{
			if (!sign&&x.sign) return true;
			if (sign&&!x.sign) return false;

			if (!sign&&!x.sign)
			{
				if (a.size()!=x.a.size()) return a.size()>x.a.size();
				int k=a.size()-1;
				while (k>=0&&a[k]==x.a[k]) k--;
				if (k==-1) return true;
				return a[k]>x.a[k];
			}

			if (a.size()!=x.a.size()) return a.size()<x.a.size();
			int k=a.size()-1;
			while (k>=0&&a[k]==x.a[k]) k--;
			if (k==-1) return true;
			return a[k]<x.a[k];
		}

		inline bool operator >= (const int x) const
		{
			if (!sign&&x<0) return true;
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>=t;
		}

		inline bool operator >= (const short x) const
		{
			if (!sign&&x<0) return true;
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>=t;
		}

		inline bool operator >= (const long x) const
		{
			if (!sign&&x<0) return true;
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>=t;
		}

		inline bool operator >= (const long long x) const
		{
			if (!sign&&x<0) return true;
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>=t;
		}

		inline bool operator >= (const unsigned x) const
		{
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>=t;
		}

		inline bool operator >= (const unsigned short x) const
		{
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>=t;
		}

		inline bool operator >= (const unsigned long x) const
		{
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>=t;
		}

		inline bool operator >= (const unsigned long long x) const
		{
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)>=t;
		}

		inline bool operator == (const bignum x) const
		{
			if (sign!=x.sign) return false;

			if (a.size()!=x.a.size()) return false;
			int k=a.size()-1;
			while (k>=0&&a[k]==x.a[k]) k--;
			if (k==-1) return true;
			return false;
		}

		inline bool operator == (const int x) const
		{
			if (!sign&&x<0) return false;
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)==t;
		}

		inline bool operator == (const short x) const
		{
			if (!sign&&x<0) return false;
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)==t;
		}

		inline bool operator == (const long x) const
		{
			if (!sign&&x<0) return false;
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)==t;
		}

		inline bool operator == (const long long x) const
		{
			if (!sign&&x<0) return false;
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)==t;
		}

		inline bool operator == (const unsigned x) const
		{
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)==t;
		}

		inline bool operator == (const unsigned short x) const
		{
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)==t;
		}

		inline bool operator == (const unsigned long x) const
		{
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)==t;
		}

		inline bool operator == (const unsigned long long x) const
		{
			if (sign&&x>=0) return false;

			bignum t=x;
			return (*this)==t;
		}

		inline bool operator != (const bignum x) const
		{
			if (!sign&&x.sign) return true;
			if (sign&&!x.sign) return true;

			if (a.size()!=x.a.size()) return true;
			int k=a.size()-1;
			while (k>=0&&a[k]==x.a[k]) k--;
			if (k==-1) return false;
			return true;
		}

		inline bool operator != (const int x) const
		{
			if (!sign&&x<0) return true;
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)!=t;
		}

		inline bool operator != (const short x) const
		{
			if (!sign&&x<0) return true;
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)!=t;
		}

		inline bool operator != (const long x) const
		{
			if (!sign&&x<0) return true;
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)!=t;
		}

		inline bool operator != (const long long x) const
		{
			if (!sign&&x<0) return true;
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)!=t;
		}

		inline bool operator != (const unsigned x) const
		{
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)!=t;
		}

		inline bool operator != (const unsigned short x) const
		{
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)!=t;
		}

		inline bool operator != (const unsigned long x) const
		{
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)!=t;
		}

		inline bool operator != (const unsigned long long x) const
		{
			if (sign&&x>=0) return true;

			bignum t=x;
			return (*this)!=t;
		}

		inline bignum operator + () const
		{
			return make_bignum(a,sign);
		}

		inline bignum operator - () const
		{
			return make_bignum(a,!sign);
		}

		inline bignum operator ++ ()
		{
			bignum t=make_bignum(a,sign);
			t=t+1;
			(*this)=t;
			return t;
		}

		inline bignum operator -- ()
		{
			bignum t=make_bignum(a,sign);
			t=t-1;
			(*this)=t;
			return t;
		}

		template<typename T> inline bool operator && (const T x) const
		{
			if ((*this)!=0&&x) return true;
			return false;
		}

		template<typename T> inline bool operator || (const T x) const
		{
			if (!(*this)&&!x) return false;
			return true;
		}

		inline bool operator ! () const
		{
			if ((*this)==0) return true;
			return false;
		}

		inline bignum operator + (const bignum x) const
		{
			bignum t;
			t.a.clear();

			if (!sign&&!x.sign)
			{
				if (a.size()<x.a.size())
				{
					for (int i=0;i<a.size();i++) t.a.push_back(a[i]+x.a[i]);
					for (int i=a.size();i<x.a.size();i++) t.a.push_back(x.a[i]);
					for (int i=0;i<x.a.size()-1;i++)
					{
						if (t.a[i]>=10)
						{
							t.a[i+1]+=t.a[i]/10;
							t.a[i]%=10;
						}
					}
					if (t.a[t.a.size()-1]>=10)
					{
						t.a.resize(x.a.size()+1);
						t.a[t.a.size()-1]+=t.a[t.a.size()-2]/10;
						t.a[t.a.size()-2]%=10;
					}
					return t;
				}

				for (int i=0;i<x.a.size();i++) t.a.push_back(a[i]+x.a[i]);
				for (int i=x.a.size();i<a.size();i++) t.a.push_back(a[i]);
				for (int i=0;i<a.size()-1;i++)
				{
					if (t.a[i]>=10)
					{
						t.a[i+1]+=t.a[i]/10;
						t.a[i]%=10;
					}
				}
				if (t.a[t.a.size()-1]>=10)
				{
					t.a.resize(t.a.size()+1);
					t.a[t.a.size()-1]+=t.a[t.a.size()-2]/10;
					t.a[t.a.size()-2]%=10;
				}
				return t;
			}

			if (sign&&x.sign)
			{
				t.sign=1;
				if (a.size()<x.a.size())
				{
					for (int i=0;i<a.size();i++) t.a.push_back(a[i]+x.a[i]);
					for (int i=a.size();i<x.a.size();i++) t.a.push_back(x.a[i]);
					for (int i=0;i<x.a.size()-1;i++)
					{
						if (t.a[i]>=10)
						{
							t.a[i+1]+=t.a[i]/10;
							t.a[i]%=10;
						}
					}
					if (t.a[t.a.size()-1]>=10)
					{
						t.a.resize(t.a.size()+1);
						t.a[t.a.size()-1]+=t.a[t.a.size()-2]/10;
						t.a[t.a.size()-2]%=10;
					}
					return t;
				}

				for (int i=0;i<x.a.size();i++) t.a.push_back(a[i]+x.a[i]);
				for (int i=x.a.size();i<a.size();i++) t.a.push_back(a[i]);
				for (int i=0;i<a.size()-1;i++)
				{
					if (t.a[i]>=10)
					{
						t.a[i+1]+=t.a[i]/10;
						t.a[i]%=10;
					}
				}
				if (t.a[t.a.size()-1]>=10)
				{
					t.a.resize(t.a.size()+1);
					t.a[t.a.size()-1]+=t.a[t.a.size()-2]/10;
					t.a[t.a.size()-2]%=10;
				}
				return t;
			}

			if (!sign&&x.sign)
			{
				bignum b=make_bignum(a,sign),p=make_bignum(x.a,0);
				if (b>=p)
				{
					for (int i=0;i<p.a.size();i++)
					{
						if (b.a[i]<p.a[i])
						{
							b.a[i+1]--;
							b.a[i]+=10;
						}
						t.a.push_back(b.a[i]-p.a[i]);
					}
					for (int i=p.a.size();i<b.a.size();i++)
					{
						if (b.a[i]<0)
						{
							b.a[i+1]--;
							b.a[i]+=10;
						}
						t.a.push_back(b.a[i]);
					}
					int k=t.a.size()-1;
					while (k>=1&&!t.a[k]) k--;
					t.a.resize(k+1);
					return t;
				}
				else
				{
					t.sign=1;
					for (int i=0;i<b.a.size();i++)
					{
						if (p.a[i]<b.a[i])
						{
							p.a[i+1]--;
							p.a[i]+=10;
						}
						t.a.push_back(p.a[i]-b.a[i]);
					}
					for (int i=b.a.size();i<p.a.size();i++)
					{
						if (p.a[i]<0)
						{
							p.a[i+1]--;
							p.a[i]+=10;
						}
						t.a.push_back(p.a[i]);
					}
					int k=t.a.size()-1;
					while (k>=1&&!t.a[k]) k--;
					t.a.resize(k+1);
					return t;
				}
			}

			bignum b=make_bignum(a,0),p=make_bignum(x.a,0);

			if (p>=b)
			{
				for (int i=0;i<b.a.size();i++)
				{
					if (p.a[i]<b.a[i])
					{
						p.a[i+1]--;
						p.a[i]+=10;
					}
					t.a.push_back(p.a[i]-b.a[i]);
				}
				for (int i=b.a.size();i<p.a.size();i++)
				{
					if (p.a[i]<0)
					{
						p.a[i+1]--;
						p.a[i]+=10;
					}
					t.a.push_back(p.a[i]);
				}
				int k=t.a.size()-1;
				while (k>=1&&!t.a[k]) k--;
				t.a.resize(k+1);
				return t;
			}

			t.sign=1;
			for (int i=0;i<p.a.size();i++)
			{
				if (b.a[i]<p.a[i])
				{
					b.a[i+1]--;
					b.a[i]+=10;
				}
				t.a.push_back(b.a[i]-p.a[i]);
			}
			for (int i=p.a.size();i<b.a.size();i++)
			{
				if (b.a[i]<0)
				{
					b.a[i+1]--;
					b.a[i]+=10;
				}
				t.a.push_back(b.a[i]);
			}
			int k=t.a.size()-1;
			while (k>=1&&!t.a[k]) k--;
			t.a.resize(k+1);
			return t;
		}

		inline bignum operator + (const int x) const
		{
			bignum t=x;
			return (*this)+t;
		}

		inline bignum operator + (const short x) const
		{
			bignum t=x;
			return (*this)+t;
		}

		inline bignum operator + (const long x) const
		{
			bignum t=x;
			return (*this)+t;
		}

		inline bignum operator + (const long long x) const
		{
			bignum t=x;
			return (*this)+t;
		}

		inline bignum operator + (const unsigned x) const
		{
			bignum t=x;
			return (*this)+t;
		}

		inline bignum operator + (const unsigned short x) const
		{
			bignum t=x;
			return (*this)+t;
		}

		inline bignum operator + (const unsigned long x) const
		{
			bignum t=x;
			return (*this)+t;
		}

		inline bignum operator + (const unsigned long long x) const
		{
			bignum t=x;
			return (*this)+t;
		}

		template<typename T> inline bignum operator += (const T x)
		{
			bignum t=(*this);
			t=t+x;
			(*this)=t;
			return t;
		}

		inline bignum operator - (const bignum x) const
		{
			bignum t;
			t.a.clear();

			if (!sign&&!x.sign)
			{
				bignum b=x,p=make_bignum(a,sign);
				if (p>=b)
				{
					for (int i=0;i<b.a.size();i++)
					{
						if (p.a[i]<b.a[i])
						{
							p.a[i+1]--;
							p.a[i]+=10;
						}
						t.a.push_back(p.a[i]-b.a[i]);
					}
					for (int i=b.a.size();i<p.a.size();i++)
					{
						if (p.a[i]<0)
						{
							p.a[i+1]--;
							p.a[i]+=10;
						}
						t.a.push_back(p.a[i]);
					}
					int k=t.a.size()-1;
					while (k>=1&&!t.a[k]) k--;
					t.a.resize(k+1);
					return t;
				}

				t.sign=1;
				for (int i=0;i<p.a.size();i++)
				{
					if (b.a[i]<p.a[i])
					{
						b.a[i+1]--;
						b.a[i]+=10;
					}
					t.a.push_back(b.a[i]-p.a[i]);
				}
				for (int i=p.a.size();i<b.a.size();i++)
				{
					if (b.a[i]<0)
					{
						b.a[i+1]--;
						b.a[i]+=10;
					}
					t.a.push_back(b.a[i]);
				}
				int k=t.a.size()-1;
				while (k>=1&&!t.a[k]) k--;
				t.a.resize(k+1);
				return t;
			}

			if (sign&&x.sign)
			{
				bignum b=x,p=make_bignum(a,sign);
				if (p>=b) //|x|-p
				{
					for (int i=0;i<p.a.size();i++)
					{
						if (b.a[i]<p.a[i])
						{
							b.a[i+1]--;
							b.a[i]+=10;
						}
						t.a.push_back(b.a[i]-p.a[i]);
					}
					for (int i=p.a.size();i<b.a.size();i++)
					{
						if (b.a[i]<0)
						{
							b.a[i+1]--;
							b.a[i]+=10;
						}
						t.a.push_back(b.a[i]);
					}
					int k=t.a.size()-1;
					while (k>=1&&!t.a[k]) k--;
					t.a.resize(k+1);
					return t;
				}

				t.sign=1;
				for (int i=0;i<b.a.size();i++)
				{
					if (p.a[i]<b.a[i])
					{
						p.a[i+1]--;
						p.a[i]+=10;
					}
					t.a.push_back(p.a[i]-b.a[i]);
				}
				for (int i=b.a.size();i<p.a.size();i++)
				{
					if (p.a[i]<0)
					{
						p.a[i+1]--;
						p.a[i]+=10;
					}
					t.a.push_back(p.a[i]);
				}
				int k=t.a.size()-1;
				while (k>=1&&!t.a[k]) k--;
				t.a.resize(k+1);
				return t;
			}

			if (!sign&&x.sign)
			{
				if (a.size()<x.a.size())
				{
					for (int i=0;i<a.size();i++) t.a.push_back(a[i]+x.a[i]);
					for (int i=a.size();i<x.a.size();i++) t.a.push_back(x.a[i]);
					for (int i=0;i<x.a.size()-1;i++)
					{
						if (t.a[i]>=10)
						{
							t.a[i+1]+=t.a[i]/10;
							t.a[i]%=10;
						}
					}
					if (t.a[t.a.size()-1]>=10)
					{
						t.a.resize(t.a.size()+1);
						t.a[t.a.size()-1]+=t.a[t.a.size()-2]/10;
						t.a[t.a.size()-2]%=10;
					}
					return t;
				}

				for (int i=0;i<x.a.size();i++) t.a.push_back(a[i]+x.a[i]);
				for (int i=x.a.size();i<a.size();i++) t.a.push_back(a[i]);
				for (int i=0;i<a.size()-1;i++)
				{
					if (t.a[i]>=10)
					{
						t.a[i+1]+=t.a[i]/10;
						t.a[i]%=10;
					}
				}
				if (t.a[t.a.size()-1]>=10)
				{
					t.a.resize(t.a.size()+1);
					t.a[t.a.size()-1]+=t.a[t.a.size()-2]/10;
					t.a[t.a.size()-2]%=10;
				}
				return t;
			}

			t.sign=1;
			if (a.size()<x.a.size())
			{
				for (int i=0;i<a.size();i++) t.a.push_back(a[i]+x.a[i]);
				for (int i=a.size();i<x.a.size();i++) t.a.push_back(x.a[i]);
				for (int i=0;i<x.a.size()-1;i++)
				{
					if (t.a[i]>=10)
					{
						t.a[i+1]+=t.a[i]/10;
						t.a[i]%=10;
					}
				}
				if (t.a[t.a.size()-1]>=10)
				{
					t.a.resize(t.a.size()+1);
					t.a[t.a.size()-1]+=t.a[t.a.size()-2]/10;
					t.a[t.a.size()-1]%=10;
				}
				return t;
			}

			for (int i=0;i<x.a.size();i++) t.a.push_back(a[i]+x.a[i]);
			for (int i=x.a.size();i<a.size();i++) t.a.push_back(a[i]);
			for (int i=0;i<a.size()-1;i++)
			{
				if (t.a[i]>=10)
				{
					t.a[i+1]+=t.a[i]/10;
					t.a[i]%=10;
				}
			}
			if (t.a[t.a.size()-1]>=10)
			{
				t.a.resize(t.a.size()+1);
				t.a[t.a.size()-1]+=t.a[t.a.size()-2]/10;
				t.a[t.a.size()-2]%=10;
			}
			return t;
		}

		inline bignum operator - (const int x) const
		{
			bignum t=x;
			return (*this)-t;
		}

		inline bignum operator - (const short x) const
		{
			bignum t=x;
			return (*this)-t;
		}

		inline bignum operator - (const long x) const
		{
			bignum t=x;
			return (*this)-t;
		}

		inline bignum operator - (const long long x) const
		{
			bignum t=x;
			return (*this)-t;
		}

		inline bignum operator - (const unsigned x) const
		{
			bignum t=x;
			return (*this)-t;
		}

		inline bignum operator - (const unsigned short x) const
		{
			bignum t=x;
			return (*this)-t;
		}

		inline bignum operator - (const unsigned long x) const
		{
			bignum t=x;
			return (*this)-t;
		}

		inline bignum operator - (const unsigned long long x) const
		{
			bignum t=x;
			return (*this)-t;
		}

		template<typename T> inline bignum operator -= (const T x)
		{
			bignum t=(*this);
			t=t-x;
			(*this)=t;
			return t;
		}

		inline bignum operator * (const bignum x) const
		{
			bignum t;
			t.a.clear();
			if (!(!sign&&!x.sign||sign&&x.sign)) t.sign=1;
			t.a.resize(a.size()+x.a.size());

			for (int i=0;i<a.size();i++)
				for (int j=0;j<x.a.size();j++) t.a[i+j]+=a[i]*x.a[j];
			for (int i=0;i<t.a.size()-1;i++)
			{
				if (t.a[i]>=10)
				{
					t.a[i+1]+=t.a[i]/10;
					t.a[i]%=10;
				}
			}
			int k=t.a.size()-1;
			while (k>=1&&!t.a[k]) k--;
			t.a.resize(k+1);
			return t;
		}

		inline bignum operator * (const int x) const
		{
			bignum t=x;
			return (*this)*t;
		}

		inline bignum operator * (const short x) const
		{
			bignum t=x;
			return (*this)*t;
		}

		inline bignum operator * (const long x) const
		{
			bignum t=x;
			return (*this)*t;
		}

		inline bignum operator * (const long long x) const
		{
			bignum t=x;
			return (*this)*t;
		}

		inline bignum operator * (const unsigned x) const
		{
			bignum t=x;
			return (*this)*t;
		}

		inline bignum operator * (const unsigned short x) const
		{
			bignum t=x;
			return (*this)*t;
		}

		inline bignum operator * (const unsigned long x) const
		{
			bignum t=x;
			return (*this)*t;
		}

		inline bignum operator * (const unsigned long long x) const
		{
			bignum t=x;
			return (*this)*t;
		}

		template<typename T> inline bignum operator *= (const T x)
		{
			bignum t=(*this);
			t=t*x;
			(*this)=t;
			return t;
		}

		inline bignum operator / (const bignum x) const
		{
			if (x==0) throw;

			bignum t,p=make_bignum(x.a,0),s=0;
			if (sign!=x.sign) t.sign=1;
			t.a.resize(a.size());
			int k=t.a.size()-1;

			for (int i=t.a.size()-1;i>=0;i--)
			{
				s=s*10+a[i];
				while (s>=p)
				{
					s-=p;
					t.a[k]++;
				}
				k--;
			}
			k=t.a.size()-1;
			while (!t.a[k]&&k>=1) k--;
			t.a.resize(k+1);
			if (t.sign&&t.a.size()==1&&!t.a[0]) t.sign=0;
			return t;
		}

		inline bignum operator / (const int x) const
		{
			bignum t=x;
			return (*this)/t;
		}

		inline bignum operator / (const short x) const
		{
			bignum t=x;
			return (*this)/t;
		}

		inline bignum operator / (const long x) const
		{
			bignum t=x;
			return (*this)/t;
		}

		inline bignum operator / (const long long x) const
		{
			bignum t=x;
			return (*this)/t;
		}

		inline bignum operator / (const unsigned x) const
		{
			bignum t=x;
			return (*this)/t;
		}

		inline bignum operator / (const unsigned short x) const
		{
			bignum t=x;
			return (*this)/t;
		}

		inline bignum operator / (const unsigned long x) const
		{
			bignum t=x;
			return (*this)/t;
		}

		inline bignum operator / (const unsigned long long x) const
		{
			bignum t=x;
			return (*this)/t;
		}

		template<typename T> inline bignum operator /= (const T x)
		{
			bignum t=(*this);
			t=t*x;
			(*this)=t;
			return t;
		}

		inline bignum operator % (const bignum x) const
		{
			if (x==0) throw;
			bignum p=make_bignum(x.a,0),s;

			for (int i=a.size()-1;i>=0;i--)
			{
				s=s*10+a[i];
				while (s>=p) s-=p;
			}
			return s;
		}

		inline bignum operator % (const int x) const
		{
			bignum t=x;
			return (*this)%t;
		}

		inline bignum operator % (const short x) const
		{
			bignum t=x;
			return (*this)%t;
		}

		inline bignum operator % (const long x) const
		{
			bignum t=x;
			return (*this)%t;
		}

		inline bignum operator % (const long long x) const
		{
			bignum t=x;
			return (*this)%t;
		}

		inline bignum operator % (const unsigned x) const
		{
			bignum t=x;
			return (*this)%t;
		}

		inline bignum operator % (const unsigned short x) const
		{
			bignum t=x;
			return (*this)%t;
		}

		inline bignum operator % (const unsigned long x) const
		{
			bignum t=x;
			return (*this)%t;
		}

		inline bignum operator % (const unsigned long long x) const
		{
			bignum t=x;
			return (*this)%t;
		}

		template<typename T> inline bignum operator %= (const T x)
		{
			bignum t=(*this);
			t=t%x;
			(*this)=t;
			return t;
		}
};

inline istream& operator >> (istream& is,bignum &x)
{
	x.in();
	return is;
}

inline ostream& operator << (ostream& os,bignum x)
{
	x.out();
	return os;
}

#endif
