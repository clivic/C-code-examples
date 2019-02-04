#include "PictureList.h"
#include "utility.h"

PictureList::PictureList()
{
	count = 0;
	head = NULL;
	//current_position = 0;
	current = NULL;
}

PictureRecord getOnePicRecorder(ifstream &myFile)
{
 	string picname;
	OthersType ot;
	char ch;

    //filename;
	picname = "";
	myFile.get(ch);
	while (ch != ',')
	{
		picname = picname + ch;
		myFile.get(ch);
	}

	myFile >> ot.height;
	myFile.get();
	
	myFile >> ot.width;
	myFile.get();

	myFile >> ot.size;
	myFile.get();

	myFile >> ot.time;
	myFile.get();

	//information;
	ot.information = "";
	myFile.get(ch);
	while (ch != ',')
	{
		ot.information=ot.information+ch;
		myFile.get(ch);
	}

	//title;
	ot.titleEn = "";
	myFile.get(ch);
	while (ch != ',')
	{
		ot.titleEn=ot.titleEn+ch;
		myFile.get(ch);
	}
    
	//map;
	ot.map = "";
	myFile.get(ch);
	while (ch != ',') 
	{
		ot.map=ot.map+ch;
		myFile.get(ch);
	}
	
	//location;
	ot.location = "";
	myFile.get(ch);
	while (ch != ',')
	{
		ot.location=ot.location+ch;
		myFile.get(ch);
	}
	//hmap;
	ot.hmap = "";
	myFile.get(ch);
	while (ch != ',') 
	{
		ot.hmap=ot.hmap+ch;
		myFile.get(ch);
	}
	//hlocation;
	ot.hlocation = "";
	myFile.get(ch);
	while (ch != ',')
	{
		ot.hlocation=ot.hlocation+ch;
		myFile.get(ch);
	}
	
	getline(myFile, ot.owner);
	PictureRecord item(picname, ot);
    return item;
}

Error_code PictureList::Initialization()
{
	ifstream myFile;
	int number;

	myFile.open("info.txt");
	
	if(!myFile)
	{
		cout << "open file failed!" << endl;	
		return not_present;
	}

	myFile>>number;

    int i=0;
	while(myFile) 
	{
		myFile.get();
		PictureRecord item = getOnePicRecorder(myFile);
		Insert(item);

		myFile >> number;
		cout << '.'; i++;
	}
	cout << i << endl;
	return success;
}

Error_code PictureList::Insert(const PictureRecord  &data) 
{
	int len = Size();
	int position; 
	PictureRecord  tmp;
    
	//judge if duplicate
	if(SearchByKey(data.GetKey(),tmp,position) == success)
	{
		cout<<data.GetKey()<<" has been inserted!"<<endl<<endl;
		return duplicate_error;
	}

	return List<PictureRecord>::Insert(position,data);
}

Error_code PictureList::Remove(PictureRecord &data)
{
	int position;
	PictureRecord  tmp;
    
	if(SearchByKey(data.GetKey(),tmp,position) == not_present) 
	{
		cout << "This picLibrary is not present!" << endl << endl;
		return not_present;
	}
	
	return List<PictureRecord>::Remove(position, data);
}

Error_code PictureList::Replace(const PictureRecord &data)  
{
    int position;
	PictureRecord  tmp;

	if (SearchByKey(data.GetKey(), tmp, position) == not_present)
	{
		cout<<"This picLibrary is not present!"<<endl<<endl;
		return not_present;
	}
	
	return List<PictureRecord>::Replace(position, data);
}

 
Error_code PictureList::SearchByTitle(string title, int&n , const Node<PictureRecord>* items[])
{
	if (head == NULL)
		return not_present;

	Node<PictureRecord > *ptr=head;
	n=0;
	
	while (ptr != NULL)
	{
		//judge whether titleEn(refered by ptr) statrs with title
		int cr = strncmp(ptr->entry.GetTitleEn().c_str(), title.c_str() ,title.length());
		if (cr == 0)
		{
			items[n] = ptr;
			n++;
		}
		ptr = ptr->next;
	}

	if (n > 0)	return success;
	else		return not_present;
}

Error_code PictureList::SearchByLocation(string location,  int &n, const Node<PictureRecord> *items[])
{
	if (head == NULL)
		return not_present;
	Node<PictureRecord> *ptr = head;

	//search by location
	n = 0;
	while (ptr != NULL)
	{
		if (ptr->entry.GetLocation() == location || ptr->entry.GetHLocation() == location)
		{
			items[n] = ptr;	n++;
		}
		ptr = ptr->next;
	}

	if (n > 0)	return success;
	else		return not_present;
}


Error_code PictureList::SearchByKey(string picname, PictureRecord &item, int &pos)  
{

	if (head == NULL)
	{
		pos = 0;	return not_present;
	}

	Node<PictureRecord> *ptr = head;
	pos = 0;
	
	//对有序链表的查找
	while (ptr != NULL &&ptr->entry.GetKey() < picname)
	{
		ptr=ptr->next;	pos++;
	}

	if (ptr != NULL &&ptr->entry.GetKey() == picname)
	{
		item = ptr->entry;
		return success;
	}
	else 
		return not_present;
}

//footprint
Error_code PictureList::SearchByFootmark(Map<200> &map)
{
	if (head == NULL)
		return not_present;

	Node<PictureRecord > *ptr = head;
    	
	//search
	int n = 0;
	while (ptr != NULL)
	{	
		if (ptr->entry.GetMap() == map.GetName()) 
		{
			if (map.InserPicPtr(ptr->entry.GetLocation(), ptr) == not_present)
				cout << ptr->entry.GetKey() << "foot mark fail!" << endl;
			else	n += 1;
		}
		else if (ptr->entry.GetHMap() == map.GetName())
		{
			if (map.InserPicPtr(ptr->entry.GetHLocation(), ptr) == not_present)
				cout << ptr->entry.GetKey() << "foot mark fail!" << endl;
			else	n += 1;
		}
		ptr=ptr->next;		
	}

	if(n>0 ) return success;
	else return not_present;
}

//Insertion Sort
void PictureList::Sort()
{
	Node<PictureRecord > *firstUnsorted,        
		 *lastSorted,
		 *cur,             //used to traverse the Sorted sublist
		 *trailing;        //one position behind current
	if (head != NULL)
	{
		lastSorted = head;
		while (lastSorted->next != NULL) 
		{
			firstUnsorted = lastSorted->next;
			if (firstUnsorted->entry < head->entry)
			{
				lastSorted->next = firstUnsorted->next;
				firstUnsorted->next = head;
				head = firstUnsorted;
			}
			else 
			{
				trailing = head;
				cur = trailing->next;
				while (firstUnsorted->entry > cur->entry)
				{
					trailing = cur;
					cur = trailing->next;
				}
				if (firstUnsorted == cur)
					lastSorted = firstUnsorted;
				else 
				{
					lastSorted->next = firstUnsorted->next;
					firstUnsorted->next = cur;
					trailing->next = firstUnsorted;
				}
			}
		}
	}
}

//print into file
void PictureList::Print()
{
	ofstream fout;	
	fout.open("MyInfo.txt");
	
	Node<PictureRecord > *ptr = head;
	int i = 1;
	while(ptr) 
	{
		cout << i << "," << ptr->entry;
		i += 1;
		ptr = ptr->next;
	}
}