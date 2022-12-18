#include <iostream>

using namespace std;

int fm(int e,int s);
int fma[100][100];
int da[100][100];
int d(int e,int s)
{
    if(da[e][s]!=-1) return da[e][s];
    if(s<=1) return s;
    if(e==1) return s;
    int f=fm(e,s);
    int db,dnb;
    db=d(e-1,f-1);
    dnb=d(e,s-f);
    if(db>dnb) dnb=db;
    da[e][s]=1+dnb;
    return 1+dnb;

}

int fm(int e,int s)
{
    if(fma[e][s]!=-1) return fma[e][s];
    if(e==1) return 1;
    if(s<=1) return s;
    int fm=1;
    int db,dnb,dprev,dnow,i;
    dprev=s;
    dnow=s;
    for(i=1;i<=s;i++)
    {
        dprev=dnow;
        db=d(e-1,i-1);
        dnb=d(e,s-i);
        if(db>dnb)
        {
            dnow=1+db;
        }
        else
        {
            dnow=1+dnb;
        }
        //cout<<e<<s<<i<<dnow<<dprev<<endl;
        if(dnow>dprev){
                fma[e][s]=i-1;
                return i-1;
        }

    }
    if(i>s){
            fma[e][s]=s;
            return s;
    }
    fma[e][s]=i-1;
    return i-1;


}


int main()
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            da[i][j]=-1;
            fma[i][j]=-1;
        }
    }
    cout << d(3,100) << endl;
    return 0;
}
