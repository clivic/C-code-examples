#include"PhotoList.h"

ifstream fin("info.txt");

PhotoList::PhotoList()
{
	count = 0;
	head = NULL;
	currentPos = 0;
	current = NULL;
}

Error_code PhotoList::Initialization()
{
	ifstream fin;
	fin.open("info.txt");
	PhotoRecord temp;
	bool initialResponse = true;

	int num;
	string picname;			//identifier
	int len;
	int bth;
	int size;
	long ptime;
	string chn;				//chinese name
	string name;			//photoName
	string map;				//photo place's map	
	string pl;				//photo place
	string smap;			//superior map
	string spl;				//place in superior map
	string owner;

	char ch;				//dummy

	//initial reading
	//number
	fin >> num;		fin.get();

	//filename;
	picname = "";	fin.get(ch);
	while (ch != ',')
	{
		picname = picname + ch;	fin.get(ch);
	}

	fin >> len;	fin.get();

	fin >> bth;	fin.get();

	fin >> size; fin.get();

	fin >> ptime; fin.get();

	//chinese name
	chn = "";	fin.get(ch);
	while (ch != ',')
	{
		chn = chn + ch;	fin.get(ch);
	}

	//key
	name = ""; fin.get(ch);
	while (ch != ',')
	{
		name = name + ch;	fin.get(ch);
	}

	//map;
	map = "";	fin.get(ch);
	while (ch != ',')
	{
		map = map + ch;	fin.get(ch);
	}

	//location(place)
	pl = "";	fin.get(ch);
	while (ch != ',')
	{
		pl = pl + ch;		fin.get(ch);
	}

	//superior map
	smap = "";	fin.get(ch);
	while (ch != ',')
	{
		smap = smap + ch;	fin.get(ch);
	}

	//superior place
	spl = "";	fin.get(ch);
	while (ch != ',')
	{
		spl = spl + ch;	fin.get(ch);
	}

	getline(fin, owner);
	PhotoRecord item(num, picname, len, bth, size, ptime, chn, name, map, pl, smap, spl, owner, 0);
	temp = item;

	//loop reading (same)
	while (fin)	//prevent EOF
	{
		initialResponse = false;	Insert(temp);
		//number
		fin >> num;		fin.get();

		//filename;
		picname = "";	fin.get(ch);
		while (ch != ',')
		{
			picname = picname + ch;	fin.get(ch);
		}

		fin >> len;	fin.get();

		fin >> bth;	fin.get();

		fin >> size;fin.get();

		fin >> ptime;fin.get();

		//chinese name
		chn = "";	fin.get(ch);
		while (ch != ',')
		{
			chn = chn + ch;	fin.get(ch);
		}

		//key
		name = "";fin.get(ch);
		while (ch != ',')
		{
			name = name + ch;	fin.get(ch);
		}

		//map;
		map = "";	fin.get(ch);
		while (ch != ',')
		{
			map = map + ch;	fin.get(ch);
		}

		//location(place)
		pl = "";	fin.get(ch);
		while (ch != ',')
		{
			pl = pl + ch;		fin.get(ch);
		}

		//superior map
		smap = "";	fin.get(ch);
		while (ch != ',')
		{
			smap = smap + ch;	fin.get(ch);
		}

		//superior place
		spl = "";	fin.get(ch);
		while (ch != ',')
		{
			spl = spl + ch;	fin.get(ch);
		}

		getline(fin, owner);
		PhotoRecord item(num, picname, len, bth, size, ptime, chn, name, map, pl, smap, spl, owner, 0);
		temp = item;
	}  
	if (initialResponse)	return fail;
	return success;
}

Error_code PhotoList::Insert(const PhotoRecord &data) 
{
	//int len=Size();
	int position; //存放位置data插入的位置
	PhotoRecord tmp;
    
	//判断是否有重复的关键码
    if(SearchByKey(data,tmp,position) == success) 
	{
		cout << data.GetKey() << " has been Inserted!" << endl << endl;
		return duplicate_error;
	}

	return List<PhotoRecord>::Insert(position,data);
}

Error_code PhotoList::Remove(PhotoRecord& data)
{
	int position;
	PhotoRecord tmp;
    
	//判断关键码是否存在
    if(SearchByKey(data,tmp,position) == not_present) 
	{
		cout<<"This vocabulary is not present!"<<endl<<endl;
		return not_present;
	}
	
	return List<PhotoRecord>::Remove(position,data);
}

Error_code PhotoList::Replace(const PhotoRecord &data)  
{
    int position;
	PhotoRecord tmp;
    
	//判断关键码是否存在
    if(SearchByKey(data,tmp,position) == not_present) 
	{
		cout<<"This vocabulary is not present!"<<endl<<endl;
		return not_present;
	}
    

	return List<PhotoRecord>::Replace(position,data);
}

Error_code PhotoList::SearchByName(string name, int& n, List<Node<PhotoRecord> * > items)
{
	n = 0;	items.Clear(); bool initialResponse = true;
	if (head == NULL)
	{
		return not_present;
	}
	Node<PhotoRecord> *ptr = head;
	
	while (ptr != NULL)
	{
		if (ptr->entry.GetKey() == name)
		{
			initialResponse = false;
			ptr->entry.PlusFrequency();
			n += 1;
			items.Insert(items.Size(), ptr);
		}
		ptr = ptr->next;
	}

	if (initialResponse)
	{
		return not_present;
	}
	return success;
}

Error_code PhotoList::SearchByKey(PhotoKey key, PhotoRecord & item, int& pos)  
{
	if (head == NULL)
	{
		pos=0;
		return not_present;
	}

	Node<PhotoRecord> *ptr = head;
	pos = 0;
	
	//对链表的查找
	while (ptr != NULL)
	{
		if (ptr->entry.GetKey() == key)
		{
			ptr->entry.PlusFrequency();
			return success;
		}
		ptr = ptr->next;
		pos++;
	}
	return not_present;

}

Error_code PhotoList::SearchByPlace(string place, int& n, List<Node<PhotoRecord> * > items)
{
	n = 0;	items.Clear(); bool initialResponse = true;
	if (head == NULL)
	{
		return not_present;
	}
	Node<PhotoRecord> *ptr = head;

	while (ptr != NULL)
	{
		if (ptr->entry.GetPlace() == place)
		{
			initialResponse = false;
			ptr->entry.PlusFrequency();
			n += 1;
			items.Insert(items.Size(), ptr);
		}
		ptr = ptr->next;
	}

	if (initialResponse)
	{
		return not_present;
	}
	return success;
}

//插入排序
void PhotoList::Sort()
{
	Node<PhotoRecord> *firstUnSorted,        
		 *lastSorted,
		 *cur,             //used to traverse the Sorted sublist
		 *trailing;        //one position behind current
	if(head!=NULL) 
	{
		lastSorted=head;
		while(lastSorted->next!=NULL) 
		{
			firstUnSorted=lastSorted->next;
			if(firstUnSorted->entry < head->entry) 
			{
				lastSorted->next = firstUnSorted->next;
				firstUnSorted->next=head;
				head=firstUnSorted;
			}
			else 
			{
				trailing=head;
				cur=trailing->next;
				while(firstUnSorted->entry > cur->entry) 
				{
					trailing=cur;
					cur=trailing->next;
				}
				if(firstUnSorted==cur) 
					lastSorted=firstUnSorted;
				else 
				{
					lastSorted->next=firstUnSorted->next;
					firstUnSorted->next=cur;
					trailing->next=firstUnSorted;
				}
			}
		}
	}
}

//输出到文件
void PhotoList::Print()
{
	ofstream fout;	
	fout.open("Stored photoes info.txt");
	
	Node<PhotoRecord> *ptr=head;
	
	int i=1;
	while(ptr) 
	{
		fout << i << ',' << ptr->entry.GetIdentifier() << ',' 
			<< ptr->entry.GetLength() << ',' << ptr->entry.GetBreath() << ',' 
			<< ptr->entry.GetSize() << ',' << ptr->entry.GetTime() << ',' 
			<< ptr->entry.GetChName() << ',' << ptr->entry.GetKey() << ',' 
			<< ptr->entry.GetMap() << ',' << ptr->entry.GetPlace() << ',' 
			<< ptr->entry.GetSMap() << ',' << ptr->entry.GetSPlace() << ',' 
			<< ptr->entry.GetOwner() << ',' << ptr->entry.GetFrequency() << endl;	
		i++;
		ptr=ptr->next;
	}
}