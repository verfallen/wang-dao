typedef int ElemType;
typedef struct
{
  ElemType *Elme;
  int length;
} SSTable;

//顺序查找
int Search_Seq(SSTable ST, ElemType key)
{
  int i;
  for (i = 0; i < ST.length && ST.Elme[i] != key; i++)
    return i == ST.length ? -1 : i;
}