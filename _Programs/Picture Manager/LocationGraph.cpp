#include "LocationGraph.h"
#include <fstream>
using namespace std;
#pragma once

template <int graph_size>
LocationGraph<graph_size>::LocationGraph( ){
   count =0;
   name="none";
}

template <int graph_size>
void LocationGraph<graph_size>::get_trackByIndex(int index, VertexRecord& vr, const List <const Node<PictureRecord >  *>*& trackListPtr)
{
	vertexList.retrieve(index, vr);
	trackListPtr = &picInfoPtrs[index];

}

template <int graph_size>
void LocationGraph<graph_size>::positionToNum(int x, int y, int& index, int& no) const{
	double mindis = 100;
	no = -1;
	index = -1;

	for (int i = 0; i<count; i++){
		//ȡ����i����
		VertexRecord tmp;
		vertexList.retrieve(i, tmp);
		//�����i���㵽���ľ���
		double value = (tmp.the_x() - x)*(tmp.the_x() - x) + (tmp.the_y() - y)*(tmp.the_y() - y);
		double d = sqrt(value);

		if (d<mindis){
			no = tmp.the_no();
			index = i;
			mindis = d;
		}

	}

	return;
}

template <int graph_size>
int LocationGraph<graph_size>::get_verterxCount() const{//��count

	return count;
}


template <int graph_size>
string LocationGraph<graph_size>::the_name() const{
	return name;

}

template <int graph_size>
void LocationGraph<graph_size>::set_name(string name1){
    name = name1;
}

template <int graph_size>
Error_code LocationGraph<graph_size>::Initialize(string mapname,string mappath){//��ȡgraphVertex.txt����ȡintrouction.txt
    name = mapname;

	if(readVertexXY(mappath) == success)
	   return readVertexInfo(mappath);
   else
	   return notPresent;

}	

template <int graph_size>
Error_code LocationGraph<graph_size>::InserPicPtr(string location, const Node<PictureRecord >  * cptr){//���ӵص���pic�Ķ�Ӧ��ϵ
    int pos;
	VertexRecord vr;

	SearchByLocation(location, pos, vr);//��ѯ�Ƿ���ڣ�

	if(pos>=0){
	     return picInfoPtrs[pos].insert(picInfoPtrs[pos].size(),cptr);
		 	
	}else{
	     return notPresent;
	}

}


template <int graph_size>
void LocationGraph<graph_size>::Print(){//����ڵ���Ϣ������ڵ���ص�Ķ�Ӧ��ϵ��Ϣ��
	VertexRecord tmpVR;
	const Node<PictureRecord >* cptr;
	PictureRecord precord;
	for(int i=0; i<count; i++ ){
	if(picInfoPtrs[i].size()>0){
	   vertexList.retrieve(i,tmpVR);
	   cout<<tmpVR.the_no()<<" "<<tmpVR.the_x()<<"  "<<tmpVR.the_y()<<" "
		   <<tmpVR.the_location()<<"  "<<picInfoPtrs[i].size()<<" ";
	   for(int j=0; j<picInfoPtrs[i].size();j++){
	      picInfoPtrs[i].retrieve(j,cptr);
	      precord = cptr->entry;
		  cout<<precord.the_key()<<"  ";
	   }

	   cout<<endl;
	}
	   
  }   		
}

template <int graph_size>
Error_code  LocationGraph<graph_size>::readVertexXY(string mappath){ //��ȡ�ڵ��x��y����Ϣ��called by Initialize
  ifstream infile;
  string filename = ".\\"+mappath+"\\"+"graphVertex.txt"; 
  infile.open(filename.c_str());
  
  if(!infile){
	  cout<<"Open graphVertex.txt file error!!"<<endl;
	  return notPresent;
  }

  int no,x,y;

  infile>>no>>x>>y;
  while(infile){
     VertexRecord vt(no,x,y,"",""); //Ĭ������£��ص����ƺ͵ص�����Ϊ��
	 vertexList.insert(vertexList.size(),vt);
	 count++;
	 infile>>no>>x>>y;
  }
  infile.close();
  infile.sync();
  return success;
}

template <int graph_size>
Error_code LocationGraph<graph_size>::readVertexInfo(string mappath){//��ȡ�ڵ����ϸ��Ϣ��called by Initialize
  ifstream infile;
  string filename = ".\\"+mappath+"\\"+"introduction.txt";
  infile.open(filename.c_str());
   
  if(!infile){
	  cout<<"Open introduction.txt file error!!"<<endl;
	  return notPresent;
  }
  
  int no,pos;
  string location,detail;
  VertexRecord vr;

  infile>>no>>location>>detail;
  while(infile){
     SearchByNo(no, pos, vr);//��ѯ�Ƿ���ڣ�

	 if (pos >= 0 ){//������
	   vr.set_location(location);
	   vr.set_detail(detail);
       vertexList.replace (pos,vr);//����name��detail	    
	 }
	 else{
	    cout<<"Becareful: veretex"<<no<<" doesn't exist."<<endl;
		return notPresent;
	 }
     	 
	  infile>>no>>location>>detail;
  }  
  infile.close();
  infile.sync();
  return success;
}

template <int graph_size>
Error_code LocationGraph<graph_size>::SearchByNo(int no, int&pos, VertexRecord& vr){
    
	VertexRecord tmpVR;
	pos = -1;

	if(vertexList.size() == 0) {
		return notPresent;
	}
	
	for (int i=0; i<vertexList.size();i++){
	    vertexList.retrieve(i,tmpVR);

		if(tmpVR.the_no() == no){
			vr = tmpVR;
			pos = i;
		    return success;
		}
	}
	
	//���ˣ���ʾno�ı�Ų�����
	return notPresent;
}

template <int graph_size>
Error_code LocationGraph<graph_size>::SearchByLocation(string location, int&pos, VertexRecord& vr){
    
	VertexRecord tmpVR;
	pos = -1;

	if(vertexList.size() == 0) {
		return notPresent;
	}
	
	for (int i=0; i<vertexList.size();i++){
	    vertexList.retrieve(i,tmpVR);

		if(tmpVR.the_location() == location){
			vr = tmpVR;
			pos = i;
		    return success;
		}
	}
	
	//���ˣ���ʾno�ı�Ų�����
	return notPresent;
}