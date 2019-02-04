//*******************************************************************
//	This headerfile is used to declare constants.
//	此標頭用來聲明各常量,類似控制臺作用。
//*******************************************************************
#ifndef CONSTANTS
#define CONSTANTS

//足跡部分
const int FOOTPRINT_SIZE = 300;		//Location Graph的list的大小
const int BRUSH_COLOR_X = 255;		//足跡中標點的圓圈的x,y,z顏色
const int BRUSH_COLOR_Y = 223;
const int BRUSH_COLOR_Z = 0;
const int CIRCLE_R_ECNU = 9;		//足跡中標點的圓圈的半徑(ECNU)
const int CIRCLE_R_CHINA = 5;		//足跡中標點的圓圈的半徑(CHINA)
const int TEXT_COLOR_X = 255;		//足跡中顯示照片數量的數字的x,y,z顏色
const int TEXT_COLOR_Y = 0;
const int TEXT_COLOR_Z = 0;

//背景圖部分
const int BACKGROUND_ST_X = 170;	//背景圖的左上角頂點x,y坐標
const int BACKGROUND_ST_Y = 30;	

//搜尋部分
const int MAX_NUM_SEARCHED = 300;	//最大搜尋到的圖片數,大於它數組會越界報問題也許
const int MAX_NUM_LOADED = 3000;	//最大能夠導入的作搜尋之圖片數,大於它也會報問題也許


#endif