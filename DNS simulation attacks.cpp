#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;
string * splits(string str)
{
	vector<string> v;
	stringstream ss(str);
 
    while (ss.good()) {
        string substr;
        getline(ss, substr, '.');
        v.push_back(substr);
    }
 
 	string *s= new string[v.size()];
    
    for (size_t i = 0; i < v.size(); i++)
    {
   		//cout << v[i] << endl;
   		s[i]=v[i];
   		//cout << s[i] << endl;
   		
    }
    return s;
    
}
class rootx{
	public:
	string IP;
	string tld;
	
	rootx()
	{
	}
	rootx(string tld_ip,string root_tld)
	{
		IP=tld_ip;
		tld=root_tld;
	}
	string getTLD(string query)
	{
		string *k=splits(query);
		
		if(k[2]==tld)
		{
			cout<<"found at TLD: "<<IP<<endl;
			return IP;
		}
		else
		{
			cout<<"Query Failed"<<endl;
			return "0.0.0.0";
		}
	}
};
class tld{
	public:	
	string IP;
	string list[10];
	string AUTH_IP;
	tld()
	{
		list[0]="example.pk";
		list[1]="nes.com";
		list[2]="anu.pk";
		list[3]="aes.com";
		list[4]="bu.pk";
		list[5]="example.com";
		list[6]="cu.pk";
		list[7]="ces.com";
		list[8]="du.pk";
		list[9]="des.com";
		AUTH_IP="192.168.0.2";
		
	
	}
	string getAUTH(string q)
	{
		//single auth server so one IP onli
		return AUTH_IP;
	}
	
};
class authoratative{
	public:
	string Domain[10];
	string IP[10];
	authoratative()
	{
		Domain[0]="domain.pk";
		Domain[1]="example.com";
		Domain[2]="domain.com";
		Domain[3]="example2.com";
		Domain[4]="example5.com";
		Domain[5]="example1.com";
		Domain[6]="dom.pk";
		Domain[7]="example4.com";
		Domain[8]="domain3.pk";
		Domain[9]="example3.com";
		
		IP[5]="192.168.0.1";
		IP[3]="192.168.0.2";
		IP[9]="192.168.0.3";
		IP[7]="192.168.0.4";
		IP[4]="192.168.0.5";
		IP[0]="192.168.0.6";
		IP[1]="192.168.0.7";
		IP[2]="192.168.0.8";
		IP[6]="192.168.0.9";
		IP[8]="192.168.0.10";
		
	}
	string getDestIP(string AUTH_IP,string query)
	{
		//find domain and finally get ur IP
		for(int i=0;i<10;i++)
		{
			string x="www."+Domain[i];
			//cout<<x<<endl;
			if(query==x)
			{
				return IP[i];
			}
			
		}
		return "0.0.0.0";
	}
};
class local{
	
	public:
	rootx root[5];
	tld com,pk;
	authoratative auth1;
	string cache[5];
	string dom_IP[5];
	local()
	{
		cache[0]="www.example1.com";
		cache[1]="www.example2.com";
		cache[2]="www.example3.com";
		cache[3]="www.example4.com";
		cache[4]="www.example5.com";
		dom_IP[0]="192.168.0.1";
		dom_IP[1]="192.168.0.2";
		dom_IP[2]="192.168.0.3";
		dom_IP[3]="192.168.0.4";
		dom_IP[4]="192.168.0.5";
		
		//assign IP of tld to root
		root[0].IP="10.0.0.2";
		root[0].tld="com";
		root[1].IP="10.0.0.1";
		root[1].tld="pk";
		root[2].IP="10.0.0.1";
		root[2].tld="pk";
		root[3].IP="10.0.0.2";
		root[3].tld="com";
		root[4].IP="10.0.0.1";
		root[4].tld="pk";
		
		com.IP="10.0.0.2";
		pk.IP="10.0.0.1";
		
		
		
		
	}
	string get_IP(string domain)
	{
		//cache check
		int size=sizeof(cache)/sizeof(cache[0]);
		for(int i=0;i<size;i++)
		{
			if(domain==cache[i])
			{
				cout<<"Cache hit"<<endl;
				return dom_IP[i];
				break;
				
			}
		}
		
		//if not in cache
		//go to root get TLDIP
		cout<<"\nCache Miss"<<endl;
		cout<<"Starting Recursive DNS Query"<<endl;
		//check all 5 roots until u find ur TLD
		for(int i=0;i<5;i++)
		{
			string TLD_IP = root[i].getTLD(domain);
			if(TLD_IP!="0.0.0.0")
			{
				cout<<"TLD IP: "<<TLD_IP<<endl;
				break;
			}
			else
			{
				cout<<"No TLD found"<<endl;
			}
		}
		//go to auth same for all
		string Auth = com.getAUTH(domain);
		cout<<"Authoratative server IP: "<<Auth<<endl;
		//finally the domain ip
		
		string dest = auth1.getDestIP(Auth,domain);
		if(dest!="0.0.0.0")
		{
			cout<<"Finally the IP of "<<domain<<" is "<<dest<<endl;
			return dest;
		}
		else
		{
			cout<<"Error! 404"<<endl;
			return "0.0.0.0";
		}
		
	}
};
int main()
{
	local l1;
	cout<<"IP: "<<l1.get_IP("www.exaple.com");
	return 0;
}
