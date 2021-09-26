#include <bits/stdc++.h>
#include<fstream>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("input.txt");
	priority_queue<int,vector<int>,greater<int> > pq;
	map<int,list<int> >slot_age_no;
	map<string,int>reg_no_slot;
	map<string,int>reg_age;
	map<int,string>slot_reg_no;
	map<int,list<string> >reg_no_age;
	map<int,int>slt;
	while(fin)
	{
		string inp;
		getline(fin,inp);
		if(inp=="-1")
			break;
		if(inp[0]=='C')
		{
			int n=0;
			int i=inp.size()-1;
			int l=0;
			while(inp[i]!=' ')
			{
				i--;
			}
			for(int j=i+1;j<=inp.size()-1;j++){
				n=n*10 + (int)(inp[j]-'0');
			}
			cout<<"Created parking of "<<n<<" slots\n";
			int zz=1;
			while(zz<=n)
				pq.push(zz++);
		}
		else if(inp[0]=='P')
		{
			string reg_no;
			int st=5;
			while(inp[st]!=' ')
				reg_no+=inp[st++];
			int age=0;
			int i=inp.size()-1;
			while(inp[i]!=' ')
				i--;
			i++;
			while(i<=inp.size()-1)
				age=age*10+(int)(inp[i++]-'0');
				
			if(!pq.empty()){
			int slot=pq.top();
			slt[slot]=1;
			pq.pop();
			cout<<"Car with vehicle registration number ' "<<reg_no<<" ' has been parked at slot number "<<slot<<endl;
			reg_no_age[age].push_back(reg_no);
			slot_age_no[age].push_back(slot);
			slot_reg_no[slot]=reg_no;
			reg_no_slot[reg_no]=slot;
			reg_age[reg_no]=age;
			}
			else
				cout<<"Sorry All slots are full\n";
		}
		else if(inp[0]=='L')
		{
			int sl=0;
			int i=inp.size()-1;
			while(inp[i]!=' ')
				i--;
			i++;
			while(i<=inp.size()-1)
			sl=sl*10+(int)(inp[i++]-'0');
			if(slt[sl]==1){
			pq.push(sl);
			slt[sl]=0;

			}
			else{
				cout<<"Slot Already Vacant\n";
				continue;
			}
			string reg = slot_reg_no[sl];
			int ag=reg_age[reg];
			cout<<"Slot number "<<sl<<" vacated, the car with vehicle registration number '"<<reg<<" ' left the space , the driver of the car was of age "<<ag<<"\n";
			slot_age_no[ag].remove(sl);
			reg_no_age[ag].remove(reg);
		}
		
		else if(inp[0]=='V')
		{
			int age=0;
			int i=inp.size()-1;
			while(inp[i]!=' ')
				i--;
			i++;
			while(i<=inp.size()-1)
			age=age*10+(int)(inp[i++]-'0');
			cout<<"Vehicles with age of drive "<<age<<" are \n";
			for(auto i:reg_no_age[age])
				cout<<i<<endl;
		}
		else if(inp[0]=='S')
		{
			int i=inp.size()-1;
			int c=0;
			while(inp[i]!=' ')
			{
				i--;
				c++;
			}
			i++;
			int age=0;
			string reg_no;
			if(c>3)
			{
				while(i<=inp.size()-1)
					reg_no+=inp[i++];
				cout<<"Slot Number for car with Number "<<reg_no<<" is "<<reg_no_slot[reg_no]<<"\n";
			}
			else{
				while(i<=inp.size()-1)
					age=age*10+(int)(inp[i++]-'0');
				for(auto i:slot_age_no[age])
					cout<<i<<" ";
				cout<<endl;
			}
		}
	}
}