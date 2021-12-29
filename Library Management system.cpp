#include <iostream>
#include <string>
using namespace std;
static int size1 = 0;

class Arthur
{
	string name;
	int age2;
	string gender;
public:
	Arthur()
	{
		name = "";
		age2 = 0;
		gender = "";
	}

	Arthur(string name1, int age1, string gender1)
	{
		name = name1;
		age2 = age1;
		gender = gender1;
	}
	Arthur operator=(Arthur &obj)
	{
		name = obj.name;
		age2 = obj.age2;
		gender = obj.gender;
		return *this;
	}
	string getgender()
	{
		return gender;
	}

	int getage()
	{
		return age2;
	}
	string getarthur()
	{
		return name;
	}

	void printdata()
	{
		cout << "Author Detail...\n" << "Name: " << name << "\nAge:" << age2 << "\nGender:" << gender << endl;
		cout << endl;
	}
	~Arthur()
	{

	}
};


class books
{
	string title;
	int price;
	int numofarth;
	string genre;
	Arthur **arthur;
public:
	books()
	{
		title = " ";
		price = 0;
		genre = " ";
		numofarth = 0;
		arthur = nullptr;
	}

	Arthur **getarth()
	{
		return arthur;
	}
	books(string title1, int price1, string genre1, Arthur **arth, int num)
	{
		title = title1;
		price = price1;
		genre = genre1;
		numofarth = num;
		//arthur = new Arthur();
		//*arthur = *arth;
		arthur = new Arthur*[num];
		for (int i = 0; i < num; i++)
		{

			arthur[i] = arth[i];
		}
	}
	int getnum()
	{
		return numofarth;
	}

	string getbookn()
	{
		return title;
	}
	int getprice()
	{
		return price;
	}
	string getgenre()
	{
		return genre;
	}
	void printdata()
	{
		cout << "Book Detail...\n" << "Title: " << title << "\nPrice: Rs." << price << "\nGener: " << genre << endl;
		cout << endl;
	}
	books &operator=(books &obj)
	{
		title = obj.title;
		price = obj.price;
		genre = obj.genre;
		numofarth = obj.numofarth;
		//arthur = new Arthur();
		//*arthur = *arth;
		arthur = new Arthur*[numofarth];
		for (int i = 0; i < numofarth; i++)
		{
			arthur[i] = new Arthur();
			*arthur[i] = *obj.arthur[i];
		}

		return *this;
	}
	~books()
	{
		for (int i = 0; i < numofarth; i++)
		{
			delete arthur[i];
		}
		delete[]arthur;
	}
};

class book_store
{
private:

	int totalsales;
public:
	books **listofbooks;
	book_store()
	{
		totalsales = 0;
	}
	void addbook()
	{
		books **temp;
		string bookname;
		string genre1;
		string arthurname;
		int age1;
		string gender1;
		int number = 0;
		int price1 = 0;
		cout << " ENTER THE NAME OF BOOK.... " << endl;
		cin.ignore();
		getline(cin,bookname);
		int check1 = 0;
		for (int i = 0; i < size1; i++)
		{
			if (bookname == listofbooks[i]->getbookn())
			{
				check1 = 1;
			}
			else
			{
				check1 = 0;
			}
		}
		if (check1 == 0)
		{
			cout << "enter price of book " << endl;
			cin >> price1;
			cout << "enter the genre of book " << endl;
			cin.ignore();
			getline(cin,genre1);
			cout << "enter number of arthus whoo wrote this book " << endl;
			cin >> number;

			Arthur** check = new Arthur*[number];
			int c = 0;
			while (c != number)
			{
				cout << "enter the name of arthur " << endl;
				cin.ignore();
				getline(cin,arthurname);
				cout << "enter the age of arthur " << endl;
				cin >> age1;
				cout << "enter the gender of arthur " << endl;
				cin.ignore();
				getline(cin,gender1);
				Arthur *obj = new Arthur(arthurname, age1, gender1);
				check[c] = obj;
				c++;
			}
			c = 0;
			books *obj1 = new books(bookname, price1, genre1, check, number);
			if (size1 != 0)
			{
				temp = new books*[size1];

				for (int i = 0; i < size1; i++)
				{
					temp[i] = new books();
					*temp[i] = *listofbooks[i];
				}
				for (int i = 0; i < size1; i++)
				{
					delete listofbooks[i];  ////how i can delete the list
				}
				size1++;
				listofbooks = new books*[size1];
				for (int i = 0; i < size1 - 1; i++)
				{
					listofbooks[i] = new books;
					*listofbooks[i] = *temp[i];
				}
				for (int i = 0; i < size1 - 1; i++)
				{
					delete  temp[i];
				}
				delete[] temp;
				temp = nullptr;
			}
			else
			{
				size1++;
				listofbooks = new books*[size1];
			}
			//cout << size1 << endl;
			listofbooks[size1 - 1] = obj1;
			//listofbooks[0]->getbookn();
		}
		else
		{
			cout << endl;
			cout << "THIS BOOK IS ALREADY PRESENT IN BOOK STORE...... " << endl;
			cout << endl;
		}
	}
	void printallbooks()
	{
		if (size1 != 0)
		{
			for (int i = 0; i < size1; i++)
			{
				listofbooks[i]->printdata();
				for (int j = 0; j < listofbooks[i]->getnum(); j++)
				{
					listofbooks[i]->getarth()[j]->printdata();
				}

			}
		}
		else
		{
			system("cls");
			cout << endl;
			cout << " THERE ARE NO BOOKS TO PRINT.......PLEASE FIRST ENTER SOME BOOKS... " << endl;
			cout << endl;
		}
	}
	void sellbook()
	{
		if (size1 != 0)
		{
			int check = 0;
			string bookn;
			cout << "enter the book you want to sell " << endl;
			cin.ignore();

			getline(cin,bookn);
			for (int i = 0; i < size1; i++)
			{
				if (listofbooks[i]->getbookn() == bookn)
				{
					books **temp2;
					size1--;
					check = 1;
					totalsales = totalsales + listofbooks[i]->getprice();
					if (size1 != 0)
					{
						temp2 = new books*[size1];
						int counter = 0;
						for (int j = 0; j < size1 + 1; j++)
						{
							if (j != i)
							{
								temp2[counter] = new books;
								*temp2[counter] = *listofbooks[j];
								counter++;
							}
						}
						for (int j = 0; j < size1 + 1; j++)
						{
							delete listofbooks[j];
						}
						listofbooks = new books*[size1];
						for (int i = 0; i < size1; i++)
						{
							listofbooks[i] = new books;
							*listofbooks[i] = *temp2[i];
						}
						for (int i = 0; i < size1; i++)
						{
							delete temp2[i];
						}
						delete[] temp2;
						temp2 = nullptr;
					}
					else
					{
						cout << endl;
						system("cls");
						cout << "THERE ARE NO BOOK LEFT BEHIND AFTER REMOVING THIS BOOK " << endl << endl;;
						listofbooks = nullptr;
					}
				}
				if (check == 0)
				{
					cout << endl;
					cout << "  THERE IS NO BOOK WITH THIS NAME IN STORE.... " << endl;
					cout << endl;
				}

			}

		}
		else
		{
			system("cls");
			cout << endl;
			cout << " YOUR STORE IS EMPTY.....PLEASE FIRST ENTER SOME BOOKS  " << endl;
			cout << endl;
		}

	}
	void printbookbyarthur()
	{
		if (size1 != 0)
		{
			int check = 0;
			string arthn;
			cout << "  ENTER THE NAME OF ARTHUR OF WHOM YOU WANT TO PRINT BOOK...... " << endl;
			cout << endl;
			cin.ignore();
			getline(cin,arthn);
			for (int i = 0; i < size1; i++)
			{
				for (int j = 0; j < listofbooks[i]->getnum(); j++)
				{
					if (listofbooks[i]->getarth()[j]->getarthur() == arthn)
					{
						listofbooks[i]->printdata();
						check = 1;
					}

				}
			}
			if (check = 0)
			{
				cout << endl;
				cout << "  THERE IS NO BOOK WITH THIS ARTHUR NAME IN STORE..... " << endl;
				cout << endl;
			}
		}
		else
		{
			system("cls");
			cout << endl;
			cout << " THERE IS NO ARTHUR TO PRINT YET....... " << endl;
			cout << endl;
		}

	}
	void printallbooksofgenre()
	{
		if (size1 != 0)
		{
			int check = 0;
			string bgen;
			cout << endl;
			cout << "....BOOK OF WHICH GENRE YOU WANT TO PRINT...... " << endl;
			cout << endl;
			cin.ignore();
			getline(cin,bgen);
			for (int i = 0; i < size1; i++)
			{
				if (listofbooks[i]->getgenre() == bgen)
				{
					listofbooks[i]->printdata();
					check = 1;
				}
			}
			if (check == 0)
			{
				cout << endl;
				cout << " BOOK OF THIS GENRE IS NOT AVAILABLE IN STORE........ " << endl;
			}
		}
		else
		{
			system("cls");
			cout << endl;
			cout << " BOOK STORE IS EMPTY......FIRST ENTER SOME BOOKS..." << endl;
			cout << endl;
		}

	}
	void  totol_sales()
	{
		cout << totalsales << endl;
	}
	~book_store()
	{
		for (int i = 0; i < size1; i++)
		{
			delete listofbooks[i];
		}
		delete[]listofbooks;
	}
};

int main()
{
	book_store store;
loop:

	cout << " 1. Add New Book\n 2. Sale a Book\n 3. Print All Books\n 4. Print Books of an Author\n 5. Print Books of Specific Genre\n 6. Total Sales\n 7. PRINT DATA OF ALL ARTHURS\n 8. PRINT DATA OF ALL BOOKS\n 9. Exit" << endl;
label:
	int choice;
	cout << "Choose an Option" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		store.addbook();
		system("cls");
		cout << endl;
		cout << " YOUR BOOK HAS BEEN ADDED...... " << endl;
		cout << endl;
		store.printallbooks();
		break;
	case 2:
		store.sellbook();
		if (size1 != 0)
		{
			system("pause");
			cout << " YOUR BOOK HAS BEEN SOLD.......THE REMAINING BOOKS ARE...... " << endl << endl;
			store.printallbooks();
		}
		break;
	case 3:
		cout << "\t\tAll Books in Book Store.... " << endl;
		store.printallbooks();
		break;
	case 4:
		store.printbookbyarthur();
		break;
	case 5:
		store.printallbooksofgenre();
		break;
	case 6:
			cout << endl;
			cout << "\nTotal Sales of BookStore: Rs.";
			store.totol_sales();
			cout << endl;
            break;
	case 7:
		if (size1 != 0)
		{
			for (int i = 0; i < size1; i++)
			{
				for (int j = 0; j < store.listofbooks[i]->getnum(); j++)
				{
					store.listofbooks[i]->getarth()[j]->printdata();
				}
			}
		}
		else
		{
			system("cls");
			cout << endl;
			cout << " THERE IS NO DATA OF ANY ARTHUR YET......  " << endl;
			cout << endl;
		}
		break;
	case 8:
		if (size1 != 0)
		{
			for (int i = 0; i < size1; i++)
			{
				store.listofbooks[i]->printdata();
			}
		}
		else
		{
			system("cls");
			cout << endl;
			cout << " THRE IS NO DATA OF ANY BOOK TO PRINT..... " << endl;
			cout << endl;
		}
		break;
	case 9:
		return 0;
	default:
		cout << "Invalid Choice!!!.. Choose the Valid One... " << endl;
		goto label;
	}
	goto loop;
}



