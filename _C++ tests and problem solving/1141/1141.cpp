#include <iostream>
#include <string>

using namespace std;

int main()
{
/*	int q,qq,w,ww,e,ee,r,rr,t,tt,y,yy,u,uu,i,ii,o,oo,
		p,pp,a,aa,s,ss,d,dd,f,ff,g,gg,h,hh,j,jj,k,kk,
		l,ll,z,zz,x,xx,c,cc,v,vv,b,bb,n,nn,m,mm,A,AA,
		B,BB,C,CC,D,DD,E,EE,F,FF,G,GG,H,HH,I,II,J,JJ,
		K,KK,L,LL,M,MM,N,NN,O,OO,P,PP,Q,QQ,R,RR,S,SS,
		T,TT,U,UU,V,VV,W,WW,X,XX;
	cin >>q>>qq>>w>>ww>>e>>ee>>r>>rr>>t>>tt>>y>>yy>>u
		>>uu>>i>>ii>>o>>oo>>p>>pp>>a>>aa>>s>>ss>>d>>dd
		>>f>>ff>>g>>gg>>h>>hh>>j>>jj>>k>>kk>>l>>ll>>z
		>>zz>>x>>xx>>c>>cc>>v>>vv>>b>>bb>>n>>nn>>m>>mm
		>>A>>AA>>B>>BB>>C>>CC>>D>>DD>>E>>EE>>F>>FF>>G
		>>GG>>H>>HH>>I>>II>>J>>JJ>>K>>KK>>L>>LL>>M>>MM
		>>N>>NN>>O>>OO>>P>>PP>>Q>>QQ>>R>>endl; */
	int i(0);
	string a, b, str;
	str = "";
	while (i < 50)
	{
		cin >> a >> b;
		if (b >= "80")
			str = str + a + ' ' + b + '\n';
		i++;
	}
	cout << str;
	return 0;
}