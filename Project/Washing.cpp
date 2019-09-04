#include <iostream>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <string>
#include <cmath>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

class program
{
	public:
	string name;
	int time;
	int temp;
	int energy;
}rect;
void be()
{
	SetConsoleTextAttribute(hConsole, 7);
}

void dot(int i,int limdown,int limup)
{
	if(i<=limup && i>limdown){SetConsoleTextAttribute(hConsole, 103);}
	
}
int console(int c,int point)
{
		SetConsoleTextAttribute(hConsole, 4);
		cout<<"press:\nArrow up for up,\nArrow down for down,\nS for start/stop,\nE for exit"<<endl<<endl;
		SetConsoleTextAttribute(hConsole, 8);
		cout<<"Choose program: "<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		int i=0;
		dot(point,0,c);
		cout<<"1. one"<<endl;be();
		if(point>0&&point<=c){i=0;}
		dot(point,c,2*c);
		cout<<"2. two"<<endl;be();
		if(point>c&&point<=2*c){i=1;}
		dot(point,2*c,3*c);
		cout<<"3. three"<<endl;be();
		if(point>2*c&&point<=3*c){i=2;}
		dot(point,3*c,4*c);
		cout<<"4. four"<<endl;be();
		if(point>3*c&&point<=4*c){i=3;}
		dot(point,4*c,5*c);
		cout<<"5. five"<<endl;be();
		if(point>4*c&&point<=5*c){i=4;}
		Sleep(100);
		return i;
				
}
int erabe(int c,int point,program chosen[])
{		
		int i=0;
		bool state=0;
		int up=GetKeyState(VK_UP);
		int down=GetKeyState(VK_DOWN);
		
		
		if(up==-128 || up==-127)
		{
			point=point-1;
		//	up=0;
			state=1;
		
		}
		if(down==-128 ||down==-127)
		{
			point=point+1;
			//down=0;
			state=1;
		}
		if(point<0){point=5*c;}
		if(point>5*c){point=0;}
		if(state)
		{			
			system("cls");
			i=console(c,point);
			if(point!=0)
			{
				
				cout<<"\n\t\t\tprogram: "<<chosen[i].name<<"\n\t\t\ttime: "<<chosen[i].time<<"\n\t\t\ttemp: "<<chosen[i].temp<<"\n\t\t\tenergy: "<<chosen[i].energy<<endl;
			}
			else{cout<<"\n\n\t\t\tNo Program CHOSEN\n";}
		}
		
		return point;
}
void install(string name,double time,int temp,int energy)
{
	
		
		string txt=".txt",h=name+txt;
		fstream filel;
		filel.open(h.c_str());
		if(filel){cout<<"all in place"<<endl;}
		else
		{
			ofstream file(h.c_str());
			file<<name<<endl<<time<<endl<<temp<<endl<<energy;
			file.close();
			cout<<h<<" has been created"<<endl;
		}
	
	
}
int standard(int point,int c,program chosen)
{
	system("cls");

	console(c,point);
	if(point!=0)
			{
				
				cout<<"\n\t\t\tprogram: "<<chosen.name<<"\n\t\t\ttime: "<<chosen.time<<"\n\t\t\ttemp: "<<chosen.temp<<"\n\t\t\tenergy: "<<chosen.energy<<endl;
			}
			else{cout<<"\n\n\t\t\tNO PROGRAM CHOSEN\n";}

}
program data(string name)
{
	
	
		program chosen;
		string txt=".txt",h=name+txt;
		fstream file;
		file.open(h.c_str(),ios::in|ios::out);
		file >>chosen.name>>chosen.time>>chosen.temp>>chosen.energy;
		file.close();
	
	return chosen;
}

int clk(clock_t ck)
{
	ck=clock()/1000;
	return ck;
}
int v(int ck0,int ck1)
{	
	if(ck0<ck1){return 1;}
	else{return 0;}
}

int main()
{
	///////////////////////////////// file creation and data reading /////////////////////////////
	SetConsoleTextAttribute(hConsole, 7);
	program chosen[5];
	string names[5]={"one","two","three","four","five"};
	int times[5]={10,20,15,25,30}, temps[5]={30,40,50,60,70},energys[5]={100,110,120,130,140};	
	string name="hello";
	int tens=0;
	int norm=0;
		
	/////////////////////////////// console responsivity and choise //////////////////////////////
	int point=0,o=0,g=0,pointO=0;
	int c=1;
	int know=1,accept=0,exit=0;
	int t_elapsed=0;

	////////////////////////////// showing console ///////////////////////////////////////////////
	for(int i=0;i<5;i++)
	{
		install(names[i],times[i],temps[i],energys[i]);
		chosen[i]=data(names[i]);
		cout<<chosen[i].name<<"\t\n";
	}

	standard(point,c,chosen[0]);

	for(;;)
	{
		pointO=point;
		point=erabe(c,point,chosen);
	
		exit=GetKeyState(0x45);
		if(exit==-128 || exit==-127){return 0;}
		

	
	
		accept=GetKeyState(0x53);
		if(point!=pointO){g=1;}
		int ac;
		if(accept<0){ac=0;}else{ac=1;}
		if(point!=0)
		{
			if(!ac)
			{
				if(g)
				{ 
					clock_t ck=0;int ck0=0,ck1=0;
					int accept1=0,accept0=0,abort=0;
					int z=0,g2=0/*,g3=0*/;
					int g3=0.0,
					g=0;
					
				
					int end =1,ss=0;
					time_t t;
					do
					{
						
						abort=GetKeyState(0x45);
						if(abort==-128||abort==-127){end=0;}
						accept1=GetKeyState(0x53);
						if(accept0>accept1){ss=ss+1;}
						ck0=clk(ck);
						if(ck0>ck1){z=z+1;}
						if(ss%2==1)						
						{
							if(ck0>ck1)
							{
								standard(point,c,chosen[point-1]);
								g3=50*z/chosen[point-1].time;
								
								char line[50];
								for(int ii=0;ii<50;ii++)
								{
									line[ii]=' ';
								}
								tens=g3/5;
								
								if(tens==0){tens=8-0x30;}
								if(tens>=10){tens=0;line[23]=1+0x30;}
								
								norm=(g3%5)*2;
								line[24]=tens+0x30;
								line[25]=norm+0x30;
								line[26]='%';
								
								cout<<endl<<"\t\t";
							
								
								for(int i=0;i<50;i++)
								{
									
									if(i<=g3){SetConsoleTextAttribute(hConsole, 63);}
									if(i>g3){SetConsoleTextAttribute(hConsole, 7);}
									cout<<line[i];
								}
								SetConsoleTextAttribute(hConsole, 7);
							
								
								
								cout<<endl;
												
								if(z==chosen[point-1].time){Sleep(500);end=0;}
							}
						
						}
						if(ss%2==0)
						{
							if(ck0>ck1)
							{
								z=z-1;
								system("cls");
								SetConsoleTextAttribute(hConsole, 7);								
								cout<<endl<<"\n\n\t\t\t\t\tPAUSED"<<endl;
								g3=50*z/chosen[point-1].time;
								char line[50],space=' ';
								for(int ii=0;ii<50;ii++)
								{
									line[ii]=' ';
								}
								tens=g3/5;
								if(tens==10){tens=0;line[23]=1+0x30;}
								if(tens==0){tens=8-0x30;}
								norm=(g3%5)*2;
								line[24]=tens+0x30;
								line[25]=norm+0x30;
								line[26]='%';
								cout<<endl<<"\t\t";
								
								for(int i=0;i<50;i++)
								{
										if(i<=g3){SetConsoleTextAttribute(hConsole, 63);}
										if(i>g3){SetConsoleTextAttribute(hConsole, 7);}
										cout<<line[i];
										
										
									
									//if(i<(g3/2)-2)
								}
								SetConsoleTextAttribute(hConsole, 7);
							}
							
						}						
						accept0=accept1;
						ck1=ck0;						
						
					}while(end);
					system("cls");
					cout<<"\n\n\n\n\n\t\tPROGRAM HAS FINISHED5!!"<<endl;
					Sleep(1000);
					point=0;
					standard(point,c,chosen[point]);
					
				}				
			}
		}

		
	
	}
	return 0;
}
