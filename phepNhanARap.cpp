#include <iostream>
#include <string>
using namespace std;
struct Cell
{
    int donvi,chuc;
};
Cell a[20] [20];
string x="1234", y="567";
int m = x.size(), n = y.size();
void Fill()
{
   int u, v;
   for (int i=1;i<=m; i++)
  {
    u = x[i-1] - 48;
    for (int j=1;j<=n;j++)
    {
      v = y[j-1] - 48;
      a[i][j].chuc = u*v/10;
      a[i][j].donvi= u*v%10;
    }
  }
}
void View()
{
    for (int i=1;i<=m;i++)
   {
     for (int j=1;j<=n;j++)
      cout<<a[i][j].chuc<<"/"<<a[i][j].donvi<<" ";
      cout<<endl<<endl;
   }
}
string NhanArap (string x, string y)
{
   string z="";
   char c;
   int s,schuc, sdonvi, nho=0;
   c = a[m][n].donvi + 48;
   z = c + z;
   schuc = a[m][n].chuc;
   	// duyet nua bang duoi
  	for (int i=m-1;i>0; i--)
	{
		s = schuc + nho;
		sdonvi = 0;
		schuc = 0;
		int u = i, v = n;
		while (u<=m) //chua vuot qua so
			{
				sdonvi += a[u][v].donvi;
				schuc += a[u][v].chuc;
				u++; v--;
		    }  
			s+= sdonvi;
			nho = s/10;
			c = s%10+ 48;
		    z = c + z;
    	}
		   for (int j=n-1;j>0;j--)
			{
			 	s = schuc + nho;
				sdonvi = 0;
				schuc = 0;
				int u = 1, v = j;
				while(v>0) //chua vuot ra ngoai k
				{
					sdonvi += a[u][v].donvi;
					schuc += a[u][v].chuc;
					u++; v--;
			    }
					s += sdonvi;
					nho=s/10;
					c = s%10 + 48;
					z = c + z;
		   }
      //Xu ly so cuoi cung
       s = schuc + nho;
       if (s>0)
      {
      	c = s + 48;
      	z = c + z;
      }
      return z;
   
}
main()
{ 
  Fill();
  View();
  cout<<NhanArap(x,y);
}