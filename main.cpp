#include <iostream>
#include <string>
#include <sstream>
//Hello,iam omer;
//
//My homework : 
//Create list: 
//***Student datas :  name, surname, age // 
//**List sorting for student list : age // selection sort i used selection sort// 
//**List add student.
//***
//

using namespace std;

struct Student
{
//** Student Struct **//
	string name;
	string surname;
	int age;	
};

class Error
{
	//Alert messages for user control.
	//
	private :
		string message;
	public :
		Error (string msg):message(msg)
		{}
		void printMessage()
		{
			cout<<message;	
		}			
};


#define size 100
template <typename T>
class StudentList
{
//** Student List max size 100;
	private :
		T *list;//dynamic
		int ne;//number of element
	
	public :
		StudentList ()
		{
			//** Founder method
			list = new T[size];
			// size cant 101 because sizeController()
			ne   = 0; 
		}
		int getNumberOfElement ()
		{
			// return number of element //
			return ne;
		}	
		void addElement(int row, T element)
		{
			// row cant negative number
			errorControl(row);
			int j = ne;
			for (j;j>=row;j--)
			{
				//Elements adding a step//Only j until row//  
				list[j+1] = list[j];
			}
			list[row] = element;
			ne++;
		}
		void deleteThisElementIndis (int elementIndis)
		{
			errorControl(elementIndis);
			int i = elementIndis;
			for(i;i<ne-1;i++)
			{
				list[i] = list[i+1]; 
			}
			ne--;
		}
		T indexOf (int elementIndis)
		{			
			return list[elementIndis];
		}
	
		
		void selectionSortForAge()
		{
			T selector;
			// using list[].age because list is Student struct.[name,surname,age];
			for (int i=0;i<ne-1;i++)
			{
				for(int j=i+1;j<ne;j++)
				{
					if(list[i].age > list[j].age)
					{
						selector =list[i];
						list[i] = list[j];
						list[j] = selector;
					}
				}	
			}
		}
			
	private:void errorControl (int indis)
		{
			//My methods name long but clear, descriptive //
			//
			//element Indis cant negative numbers
			if (indis < 0)
			{
				// Alert Message;
				// Indis cant negative number
				throw Error("Indis deger negatif sayi olamaz.");
			}else if (indis > ne)
			{
				// element indis cant hight from ne (number of element)
				// Alert Message
				throw Error("Indis deger eleman sayisindan fazla olamaz.");
			}
		}
		
};

void sizeController(int lenght)
{
	//Students size controller
	if (lenght > 100)
	{
		throw Error("Ogrenci sayisi 100den fazla olamaz.");	
	}
}




int main(int argc, char** argv) {
	
	try
	{
		Student student[100];
		int n;
		cout<<"Ogrenci sayisini girniz :";
		cin>>n;
		sizeController(n);
		system("CLS");

		for (int i=0;i<n;i++)
		{
			cout<<"Ogrencinin ;"<<endl<<"Adini ve Soyadini :";
			cin>>student[i].name>>student[i].surname;
			cout<<"Yasini giriniz :";
			cin>>student[i].age;
			cout<<endl;
		}
		
		StudentList<Student>  *sList = new StudentList<Student>;
		
		for (int i=0; i<n;i++)
		{
			sList -> addElement(i,student[i]);	
			cout<< sList -> indexOf(i).age<<endl ;
		}	
		
		sList ->selectionSortForAge();
		
		cout<<sList ->getNumberOfElement()<<endl;
		
		for (int i=0;i<n;i++)
		{
			cout <<i+1<<" . ogrencinin;"<<endl<<"Adi ve soyadi :"<< sList -> indexOf(i).name<< sList -> indexOf(i).surname<<endl<<" yasi :"<< sList -> indexOf(i).age;
			cout<<endl;					
		}
		
	}catch (Error err)
	{
		err.printMessage();
		cout<<endl;
	}
	
	system("PAUSE");
	return 0;
}
