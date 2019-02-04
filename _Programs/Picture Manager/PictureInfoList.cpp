#include"PictureInfoList.h"
#include<cstring>
#include<fstream>
using namespace std;

PictureInfoList::PictureInfoList()
{
	count = 0;
	head = NULL;
	current_position = 0;
	current = NULL;
}

PictureRecord getOnePicRecorder(ifstream & myFile){

    
 	string picname;
	OthersType ot;
	char ch;
	
	
    //filename;
	picname="";
	myFile.get(ch);
	while(ch!=',') {
		picname=picname+ch;
		myFile.get(ch);
	}

	myFile>>ot.height;
	myFile.get();
	
	myFile>>ot.width;
	myFile.get();

	myFile>>ot.size;
	myFile.get();

	myFile>>ot.time;
	myFile.get();

	//detail;
	ot.detail = "";
	myFile.get(ch);
	while(ch!=',') {
		ot.detail=ot.detail+ch;
		myFile.get(ch);
	}

	//title;
	ot.titleEn = "";
	myFile.get(ch);
	while(ch!=',') {
		ot.titleEn=ot.titleEn+ch;
		myFile.get(ch);
	}
    
	//map;
	ot.map= "";
	myFile.get(ch);
	while(ch!=',') {
		ot.map=ot.map+ch;
		myFile.get(ch);
	}
	
	//location;
	ot.location= "";
	myFile.get(ch);
	while(ch!=',') {
		ot.location=ot.location+ch;
		myFile.get(ch);
	}
	//hmap;
	ot.hmap= "";
	myFile.get(ch);
	while(ch!=',') {
		ot.hmap=ot.hmap+ch;
		myFile.get(ch);
	}
	//hlocation;
	ot.hlocation= "";
	myFile.get(ch);
	while(ch!=',') {
		ot.hlocation=ot.hlocation+ch;
		myFile.get(ch);
	}
	
	getline(myFile,ot.owner);

	PictureRecord item(picname,ot);
    return item;
}

Error_code PictureInfoList::initialization()
{
	ifstream myFile;
	int number;

	myFile.open("D:\\picLibrary\\info.txt");
	
	if(!myFile){
		cout<<"open file failed!"<<endl;
		return notPresent;
	}

	myFile>>number;

    int i=0;
	while(myFile) {
		myFile.get();
        PictureRecord  item= getOnePicRecorder(myFile);
		insert(item);

        myFile>>number;	
		//在屏幕输出提示信息
		cout<<'.'; i++;
	}
    cout<<i<<endl;
	//cout<<endl;
	myFile.close();
	myFile.sync();
	return success;
}

Error_code PictureInfoList::insert(const PictureRecord  &data) 
{
	int len=size();
	int position; //存放位置data插入的位置
	PictureRecord  tmp;
    
	//判断是否有重复的关键码
	if(searchByKey(data.the_key(),tmp,position) == success) {
		cout<<data.the_key()<<" has been inserted!"<<endl<<endl;
		return duplicateKey;
	}

	return List<PictureRecord >::insert(position,data);
}

Error_code PictureInfoList::remove(PictureRecord & data)
{
	
	int position;
	PictureRecord  tmp;
    
	//判断关键码是否存在
	if(searchByKey(data.the_key(),tmp,position) == notPresent) {
		cout<<"This picLibrary is not present!"<<endl<<endl;
		return notPresent;
	}
	
	return List<PictureRecord >::remove(position,data);
}

Error_code PictureInfoList::replace(const PictureRecord  &data)  
{
    int position;
	PictureRecord  tmp;
    
	//判断关键码是否存在
	if(searchByKey(data.the_key(),tmp,position) == notPresent) {
		cout<<"This picLibrary is not present!"<<endl<<endl;
		return notPresent;
	}
    
	//考虑如果仅仅允许修改detail，title，地图，位置，属主等信息，该怎么做？
	

	return List<PictureRecord >::replace(position,data);
}

 
Error_code PictureInfoList::searchByTitle(string title, int& n /*查找到的数量*/, const Node<PictureRecord >*   items[]/*对应空间的指针地址*/)
{
	if(head==NULL) {
		//cout<<"Not present."<<endl;
		
		return notPresent;
	}

	Node<PictureRecord > * ptr=head;
	
	//对有序链表的查找
	n=0;
	
	while(ptr!=NULL ){
		//判断ptr指向记录的titleEn是否以title开始；
		int cr = strncmp(ptr->entry.the_titleEn().c_str(), title.c_str() ,title.length());
		if(cr == 0){
		     items[n] = ptr;
			 n++;
		}
		ptr=ptr->next;
	}

	if(n> 0){		
		return success;
	}
	else {
		//cout<<"Not present."<<endl;
		return notPresent;
	}
}

Error_code PictureInfoList::searchByLocation(string location,  int& n /*查找到的数量*/, const Node<PictureRecord >  *   items[]/*对应记录的指针地址*/)
{
	if(head==NULL) {
		//cout<<"Not present."<<endl;
		
		return notPresent;
	}

	Node<PictureRecord > * ptr=head;
	
	
	//查找 
	n=0;
	while(ptr!=NULL ){
		
		if (ptr->entry.the_location()==location || ptr->entry.the_hlocation()==location){
             items[n] = ptr;
			 n++;
		}
		
		ptr=ptr->next;
		
	}

	if(n> 0){
		return success;
	}
	else {
		//cout<<"Not present."<<endl;
		return notPresent;
	}
}


Error_code PictureInfoList::searchByKey(string  picname, PictureRecord  & item, int& pos)  
{

	if(head==NULL) {
		//cout<<"Not present."<<endl;
		pos=0;
		return notPresent;
	}

	Node<PictureRecord > * ptr=head;
	pos = 0;
	
	//对有序链表的查找
	while(ptr!=NULL && ptr->entry.the_key() <picname){
		ptr=ptr->next;
		pos++;
	}

	if(ptr!=NULL && ptr->entry.the_key()==picname){
		item=ptr->entry;
		return success;
	}
	else {
		//cout<<"Not present."<<endl;
		return notPresent;
	}
}

//足迹统计
Error_code PictureInfoList::searchByFootmark(LocationGraph<FOOTPRINT_SIZE> &map){
   if(head==NULL) {
		return notPresent;
	}

	Node<PictureRecord > * ptr=head;
    	
	//查找 
	int n=0;
	while(ptr!=NULL ){
		
		if (ptr->entry.the_map()==map.the_name()) {
             if(map.InserPicPtr(ptr->entry.the_location(),ptr) == notPresent)
				 cout<<ptr->entry.the_key()<<"foot mark fail!"<<endl; 
			 else
				 n++;
			       		
		}else if(ptr->entry.the_hmap()==map.the_name()){
			 if(map.InserPicPtr(ptr->entry.the_hlocation(),ptr)==notPresent)
				 cout<<ptr->entry.the_key()<<"foot mark fail!"<<endl; 
			 else
				 n++;
		}
		
		ptr=ptr->next;
		
	}

	if(n>0 ) return success;
	else return notPresent;
}

//插入排序
void PictureInfoList::sort()
{
	Node<PictureRecord > *first_unsorted,        
		 *last_sorted,
		 *cur,             //used to traverse the sorted sublist
		 *trailing;        //one position behind current
	if(head!=NULL) {
		last_sorted=head;
		while(last_sorted->next!=NULL) {
			first_unsorted=last_sorted->next;
			if(first_unsorted->entry < head->entry) {
				last_sorted->next = first_unsorted->next;
				first_unsorted->next=head;
				head=first_unsorted;
			}
			else {
				trailing=head;
				cur=trailing->next;
				while(first_unsorted->entry > cur->entry) {
					trailing=cur;
					cur=trailing->next;
				}
				if(first_unsorted==cur) 
					last_sorted=first_unsorted;
				else {
					last_sorted->next=first_unsorted->next;
					first_unsorted->next=cur;
					trailing->next=first_unsorted;
				}
			}
		}
	}
}

//输出到文件
void PictureInfoList::print()
{
	ofstream fout;	
	fout.open("D:\\picLibrary\\info.txt");
	
	Node<PictureRecord > *ptr=head;
	
	int i=1;
	while(ptr) {
		fout<<i<<'.'<<ptr->entry;
		//fout<<i<<','<<ptr->entry.the_key()<<','<<ptr->entry.the_frequency()<<','<<ptr->entry.the_meaning()<<endl;
		//cout<<i<<","<<ptr->entry;
		i++;
		ptr=ptr->next;
	}
	fout.close();
}
