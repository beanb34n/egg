#include <iostream>

using namespace std;

int fm(int e,int s);

int d(int e,int s)
{
    if(s<=1) return s;
    if(e==1) return s;
    int f=fm(e,s);
    int db,dnb;
    db=d(e-1,f-1);
    dnb=d(e,s-f);
    if(db>dnb) return 1+db;
    return 1+dnb;

}

int fm(int e,int s)
{
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
        if(dnow>dprev) return i-1;

    }
    if(i>s) return s;
    return i-1;


}


int main()
{
    cout << d(2,40) << endl;
    return 0;
}
