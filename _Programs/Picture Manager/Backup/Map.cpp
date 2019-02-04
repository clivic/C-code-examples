#include  "Map.h"

template <int graphSize>
Map<graphSize>::Map( )
{
   count =0;
   name = "none";
   for (int i = 0; i < graphSize; i++)
   {
	   picInfoPtrs[i]();
   }
   vertexList();
}

template <int graphSize>
string Map<graphSize>::GetName() const
{
	return name;
}

template <int graphSize>
void Map<graphSize>::SetName(string name1)
{
    name = name1;
}

template <int graphSize>
Error_code Map<graphSize>::Initialize(string mapname,string mapPath)
{
    name = mapname;

	if(ReadVertexXY(mapPath) == success)
	   return readVertexInfo(mapPath);
	else
	   return not_present;

}	

template <int graphSize>
Error_code Map<graphSize>::InsertPicPtr(string location, const Node<PictureRecord> *cptr)
{
    int pos;
	VertexRecord vRec;

	SearchByLocation(location, pos, vRec);

	if (pos >= 0)
	     return picInfoPtrs[pos].Insert(picInfoPtrs[pos].Size(),cptr);
	else
	     return not_present;
}


template <int graphSize>
void Map<graphSize>::Print()
{
	VertexRecord tmpVR;
	const Node<PictureRecord >*cptr;
	PictureRecord precord;
	for (int i = 0; i<count; i++)
	{
		if (picInfoPtrs[i].Size()>0)
		{
			vertexList.Retrieve(i, tmpVR);
			cout << tmpVR.GetNo() << " " << tmpVR.GetX() << "  " << tmpVR.GetY() << " "
				<< tmpVR.GetLocation() << "  " << picInfoPtrs[i].Size() << " ";
			for (int j = 0; j < picInfoPtrs[i].Size(); j++)
			{
				picInfoPtrs[i].Retrieve(j, cptr);
				precord = cptr->entry;
				cout << precord.GetKey() << "  ";
			}

			cout << endl;
		}
	}
}

template <int graphSize>
Error_code  Map<graphSize>::ReadVertexXY(string mapPath)
{
  ifstream fin;
  string filename = ".\\" + mapPath + "\\" + "graphVertex.txt";
  fin.open(filename.c_str());
  
  if(!fin)
  {
	  cerr << "Warning: Can't open graphVertex.txt." << endl;
	  return not_present;
  }

  int no,x,y;

  fin >> no >> x >> y;
  while(fin)
  {
	  VertexRecord vt(no, x, y, "", "");//default
	  vertexList.Insert(vertexList.Size(), vt);
	  count++;
	  fin >> no >> x >> y;
  }
  return success;
}

template <int graphSize>
Error_code Map<graphSize>::readVertexInfo(string mapPath)
{
  ifstream fin;
  string filename = ".\\" + mapPath + "\\" + "introduction.txt";
  fin.open(filename.c_str());
   
  if(!fin)
  {
	  cerr << "Warning: Can't open introduction.txt." << endl;
	  return not_present;
  }
  
  int no,pos;
  string location,detail;
  VertexRecord vRec;

  fin >> no >> location >> detail;
  while(fin)
  {
     SearchByNo(no, pos, vRec);

	 if (pos >= 0 )
	 {
	   vRec.SetLocation(location);
	   vRec.SetInfo(detail);
       vertexList.Replace (pos,vRec);	//update name and info    
	 }
	 else
	 {
	    cout<<"Sorry, veretex"<<no<<" doesn't exist."<<endl;
		return not_present;
	 }
     	 
	 fin >> no >> location >> detail;
  }  

  return success;
}

template <int graphSize>
Error_code Map<graphSize>::SearchByNo(int no, int&pos, VertexRecord&vRec)
{
	VertexRecord tmpVR;
	pos = -1;

	if(vertexList.Size() == 0) 
	{
		return not_present;
	}
	
	for (int i = 0; i < vertexList.Size(); i++)
	{
	    vertexList.Retrieve(i,tmpVR);

		if(tmpVR.GetNo() == no)
		{
			vRec = tmpVR;
			pos = i;
		    return success;
		}
	}
	return not_present;
}

template <int graphSize>
Error_code Map<graphSize>::SearchByLocation(string location, int&pos, VertexRecord&vRec)
{
	VertexRecord tmpVR;
	pos = -1;

	if(vertexList.Size() == 0) 
	{
		return not_present;
	}
	
	for (int i = 0; i < vertexList.Size(); i++)
	{
		vertexList.Retrieve(i, tmpVR);

		if(tmpVR.GetLocation() == location)
		{
			vRec = tmpVR;
			pos = i;
		    return success;
		}
	}
	return not_present;
}