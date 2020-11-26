typedef int ElemType;
typedef struct
{
  ElemType *Elme; //动态数组
  int length;     //表的长度
} SSTable;

//顺序查找实现（哨兵）,哨兵的作用：可以减少是否越界的比较
int Search_Seq(SSTable ST, ElemType key)
{
  ST.Elme[0] = key;
  int i;
  for (i = ST.length; ST.Elme[i] != key; i)
    return i;
}