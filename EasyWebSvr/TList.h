//***********************************************
// �ļ����ƣ�tlist.h
// �������ܣ�����ģ��
// �������ߣ�wbj
// �������ڣ�2002-12-10
// �������ڣ�2007-02-01
//***********************************************
/*
������ʷ:

2003.10.25 ���� RemoveValue ����
2004.12.2  �޸� SortQuick ������һ��Bug
2004.12.2  ���� CuteNode ����
2004.12.3  ���� RemoveSame ����
2004.12.7  ���� SortInsert ����
           ���� AddHead, InsertBefore, InsertAfter��protected���ͺ���
2006-05-29 ��������Vc2003�±��벻��ͨ����Bug
2006-12-12 ���ӻص���ʽ�������InsertSorted����
2007-02-01 ��pNext��pPrev��Ա��Ϊ˽�У��ṩGetNext()��GetPrev()���к���
*/
#ifndef __TLIST_H__
#define __TLIST_H__

namespace minilib
{

template <class ARG_TYPE>
class TLIST
{
public:
  class NODE
  {
  public:
    ARG_TYPE    Data;

  private:
    NODE       *pNext;
    NODE       *pPrev;
    friend class TLIST<ARG_TYPE>;
  
  public:
    NODE(const ARG_TYPE &NodeData) : Data(NodeData), pNext(NULL), pPrev(NULL) {};
    NODE       *GetNext() { return pNext; }
    NODE       *GetPrev() { return pPrev; }
  };
  typedef NODE * POSITION;

protected:
  NODE         *pHead;     // ����ͷ�ڵ�ָ��
  NODE         *pTail;     // ����β�ڵ�ָ��
  int           NodeCount; // �����нڵ�ĸ���

public:
  TLIST();
  TLIST(const TLIST<ARG_TYPE> &OtherList);
  virtual  ~TLIST();

  const TLIST<ARG_TYPE> &operator =(const TLIST<ARG_TYPE> &OtherList);
  bool                  operator ==(const TLIST<ARG_TYPE> &OtherList);
  
  POSITION              AddHead(const ARG_TYPE &NewElement);
  void                  AddHead(const TLIST &OtherList);
  POSITION              AddTail(const ARG_TYPE &NewElement);
  void                  AddTail(const TLIST &OtherList);
  int                   CopyList(const TLIST &OtherList, int BeginIndex, int Count);

  const ARG_TYPE       &GetNext(POSITION &Position) const;
  const ARG_TYPE       &GetPrev(POSITION &Position) const;

  const ARG_TYPE       &GetAt(POSITION Position) const;
  const ARG_TYPE       &GetAt(int Index) const;
  void                  SetAt(POSITION Position, const ARG_TYPE &NewElement);
  void                  SetAt(int Index, const ARG_TYPE &NewElement);

  POSITION              GetPosFromIndex(int Index) const;
  int                   GetIndexFromPos(POSITION Position) const;

  const ARG_TYPE       &GetHead() const;
  const ARG_TYPE       &GetTail() const;
  POSITION              GetHeadPosition() const;
  POSITION              GetTailPosition() const;

  POSITION              InsertAfter(POSITION Position, const ARG_TYPE &NewElement);
  void                  InsertAfter(POSITION Position, const TLIST &OtherList);
  POSITION              InsertBefore(POSITION Position, const ARG_TYPE &NewElement);
  void                  InsertBefore(POSITION Position, const TLIST &OtherList);
  POSITION              InsertSorted(const ARG_TYPE &NewElement, bool bAsc);
  POSITION              InsertSorted(const ARG_TYPE &NewElement, int (*CompareFunc)(const ARG_TYPE &Data1, const ARG_TYPE &Data2));

  int                   GetCount() const;
  bool                  IsEmpty() const;

  void                  RemoveAll();
  void                  RemoveAt(POSITION Position);
  void                  RemoveAt(POSITION &Position, int Count);
  int                   RemoveValue(const ARG_TYPE &Value);
  int                   RemoveSame();
  ARG_TYPE              RemoveHead();  
  ARG_TYPE              RemoveTail();

  void                  CutNode(TLIST<ARG_TYPE> &OtherList, POSITION &Position, int Count);

  POSITION              Find(const ARG_TYPE &SearchValue, POSITION StartAfter = NULL) const;
  POSITION              ReverseFind(const ARG_TYPE &SearchValue) const;

  int                   CutSameGroup(TLIST &GroupList, int (*CompareFunc)(const ARG_TYPE &Data1, const ARG_TYPE &Data2));
  void                  SortQuick(POSITION LowPos, POSITION HighPosint, int (*CompareFunc)(const ARG_TYPE &Data1, const ARG_TYPE &Data2));
  void                  SortQuick(int (*CompareFunc)(const ARG_TYPE &Data1, const ARG_TYPE &Data2));  // ��������
  void                  SortInsert(int (*CompareFunc)(const ARG_TYPE &Data1, const ARG_TYPE &Data2)); // ��������
  void                  Swap(POSITION Pos1, POSITION Pos2);

#ifdef __BASEIO_H__
  bool                  Save(BaseIO *pIoStream) const;
  bool                  Load(BaseIO *pIoStream);
#endif // __BASEIO_H__

#ifdef _DEBUG
  bool                  CheckList() const;
#endif // _DEBUG

protected:
  POSITION              CutAt(POSITION Position);
  POSITION              AddHead(NODE *pNewNode);
  POSITION              AddTail(NODE *pNewNode);
  POSITION              InsertBefore(POSITION Position, NODE *pNewNode);
  POSITION              InsertAfter(POSITION Position, NODE *pNewNode);
  POSITION              InsertSorted(NODE *pNewNode, int (*CompareFunc)(const ARG_TYPE &Data1, const ARG_TYPE &Data2));
};

template <class ARG_TYPE>
TLIST<ARG_TYPE>::TLIST()
{
  pHead = pTail = NULL;
  NodeCount = 0;
}

template <class ARG_TYPE>
TLIST<ARG_TYPE>::TLIST(const TLIST<ARG_TYPE> &OtherList)
{
  pHead = pTail = NULL;
  NodeCount = 0;
  *this = OtherList;
}

template <class ARG_TYPE>
TLIST<ARG_TYPE>::~TLIST()
{
  RemoveAll();
}

template <class ARG_TYPE>
const TLIST<ARG_TYPE> &TLIST<ARG_TYPE>::operator =(const TLIST<ARG_TYPE> &OtherList)
{
  if(&OtherList != this)
  {
    RemoveAll();
    AddTail(OtherList);
  }
  return *this;
}

template <class ARG_TYPE>
bool TLIST<ARG_TYPE>::operator ==(const TLIST<ARG_TYPE> &OtherList)
{
  if(GetCount() != OtherList.GetCount())
    return false;
  NODE *pNode1 = this->pHead;
  NODE *pNode2 = OtherList.pHead;
  for(; pNode1 != NULL; pNode1 = pNode1->pNext, pNode2 = pNode2->pNext)
  {
    assert(pNode2 != NULL);
    if(!(pNode1->Data == pNode2->Data))
      return false;
  }
  assert(pNode1 == NULL && pNode2 == NULL);
  return true;
}

template <class ARG_TYPE>
inline typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::AddHead(const ARG_TYPE &NewElement)
{
  return AddHead(new NODE(NewElement));
}

template <class ARG_TYPE>
typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::AddHead(NODE *pNewNode) // protected
{
  assert(pNewNode != NULL);
  pNewNode->pPrev = NULL;

  if(pHead == NULL)
  {
    pNewNode->pNext = NULL;
    pHead = pTail = pNewNode;
  }
  else
  {
    pNewNode->pNext = pHead;
    pHead->pPrev = pNewNode;
    pHead = pNewNode;
  }

  NodeCount++;
  return pNewNode;
}

template <class ARG_TYPE>
void TLIST<ARG_TYPE>::AddHead(const TLIST &OtherList)
{
  POSITION Pos = OtherList.GetTailPosition();
  while(Pos)
  {
    AddHead(Pos->Data);
    Pos = Pos->pPrev;
  }
}
  
template <class ARG_TYPE>
inline typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::AddTail(const ARG_TYPE &NewElement)
{
  return AddTail(new NODE(NewElement));
}

template <class ARG_TYPE>
typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::AddTail(NODE *pNewNode) // protected
{
  assert(pNewNode != NULL);
  pNewNode->pPrev = pNewNode->pNext = NULL;

  if(pTail == NULL)
    pHead = pTail = pNewNode;
  else
  {
    pNewNode->pPrev = pTail;
    pTail->pNext = pNewNode;
    pTail = pNewNode;
  }

  NodeCount++;
  return pNewNode;
}

template <class ARG_TYPE>
inline typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::InsertSorted(const ARG_TYPE &NewElement, int (*CompareFunc)(const ARG_TYPE &Data1, const ARG_TYPE &Data2))
{
  return InsertSorted(new NODE(NewElement), CompareFunc);
}

template <class ARG_TYPE>
typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::InsertSorted(NODE *pNewNode, int (*CompareFunc)(const ARG_TYPE &Data1, const ARG_TYPE &Data2)) // protected
{
  assert(pNewNode != NULL);

  POSITION Pos = pHead;
  for(; Pos != NULL; Pos = Pos->pNext)
  {
    if(CompareFunc(pNewNode->Data, Pos->Data) < 0)
      break;
  }
  if(Pos == NULL)
    return AddTail(pNewNode);
  return InsertBefore(Pos, pNewNode);
}

template <class ARG_TYPE>
void TLIST<ARG_TYPE>::AddTail(const TLIST &OtherList)
{
  POSITION Pos = OtherList.GetHeadPosition();
  while(Pos != NULL)
  {
    AddTail(Pos->Data);
    Pos = Pos->pNext;
  }
}

// ���� OtherList ���±� BeginIndex ��ʼ�� Count ���ڵ�
// ����ֵ: �ɹ������Ľڵ����
template <class ARG_TYPE>
int TLIST<ARG_TYPE>::CopyList(const TLIST &OtherList, int BeginIndex, int Count)
{
  assert(Count > 0);
  RemoveAll();

  POSITION Pos = OtherList.GetPosFromIndex(BeginIndex);
  assert(Pos != NULL);
  for(int i = 0; Pos != NULL && i < Count; i++, Pos = Pos->pNext)
    AddTail(Pos->Data);

  return GetCount();
}

template <class ARG_TYPE>
inline const ARG_TYPE &TLIST<ARG_TYPE>::GetNext(POSITION &Position) const
{
  assert(Position != NULL);

  POSITION Pos = Position;
  Position = Pos->pNext;
  return Pos->Data;
}

template <class ARG_TYPE>
inline const ARG_TYPE &TLIST<ARG_TYPE>::GetPrev(POSITION &Position) const
{
  assert(Position != NULL);

  POSITION Pos = Position;
  Position = Pos->pPrev;
  return Pos->Data;
}

template <class ARG_TYPE>
const ARG_TYPE &TLIST<ARG_TYPE>::GetAt(POSITION Position) const
{
  assert(Position != NULL);
  return Position->Data;
}

template <class ARG_TYPE>
inline const ARG_TYPE &TLIST<ARG_TYPE>::GetAt(int Index) const
{
  assert(Index >= 0 && Index < NodeCount);
  
  NODE *pNode = GetPosFromIndex(Index);
  assert(pNode);
 
  return pNode->Data;
}

template <class ARG_TYPE>
void TLIST<ARG_TYPE>::SetAt(int Index, const ARG_TYPE &NewElement)
{
  assert(Index >= 0 && Index < NodeCount);
  
  NODE *pNode = GetPosFromIndex(Index);

  if(pNode == NULL)
    return;
  
  pNode->Data = NewElement;
}

template <class ARG_TYPE>
inline void TLIST<ARG_TYPE>::SetAt(POSITION Position, const ARG_TYPE &NewElement)
{
  if(pNode == NULL)
    return;

  Position->Data = NewElement;
}

template <class ARG_TYPE>
inline const ARG_TYPE &TLIST<ARG_TYPE>::GetHead() const
{
  assert(pHead);

  return pHead->Data;
}

template <class ARG_TYPE>
inline const ARG_TYPE &TLIST<ARG_TYPE>::GetTail() const
{
  assert(pTail);

  return pTail->Data;
}

template <class ARG_TYPE>
inline typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::GetHeadPosition() const
{
  return pHead;
}

template <class ARG_TYPE>
inline typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::GetTailPosition() const
{
  return pTail;
}

template <class ARG_TYPE>
inline typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::InsertAfter(POSITION Position, const ARG_TYPE &NewElement)
{
  return InsertAfter(Position, new NODE(NewElement));
}

template <class ARG_TYPE>
typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::InsertAfter(POSITION Position, NODE *pNewNode) // protected
{
  assert(pNewNode != NULL);
  if(Position == NULL || Position == pTail || IsEmpty())
    return AddTail(pNewNode);

  pNewNode->pPrev = Position;
  pNewNode->pNext = Position->pNext;
  Position->pNext->pPrev = pNewNode;
  Position->pNext = pNewNode;

  NodeCount++;
  return pNewNode;
}

template <class ARG_TYPE>
void TLIST<ARG_TYPE>::InsertAfter(POSITION Position, const TLIST &OtherList)
{
  if(Position == NULL || Position == pTail || IsEmpty())
  {
    AddTail(OtherList);
    return;
  }

  POSITION OtherPos = OtherList.GetHeadPosition();
  while(OtherPos != NULL)
  {
    Position = InsertAfter(Position, OtherPos->Data);
    OtherPos = OtherPos->pNext;
  }
}

template <class ARG_TYPE>
inline typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::InsertBefore(POSITION Position, const ARG_TYPE &NewElement)
{
  return InsertBefore(Position, new NODE(NewElement));
}

template <class ARG_TYPE>
typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::InsertBefore(POSITION Position, NODE *pNewNode) // protected
{
  assert(pNewNode != NULL);
  if(Position == NULL || Position == pHead || IsEmpty())
    return AddHead(pNewNode);

  pNewNode->pNext = Position;
  pNewNode->pPrev = Position->pPrev;
  Position->pPrev->pNext = pNewNode;
  Position->pPrev = pNewNode;

  NodeCount++;
  return pNewNode;
}

template <class ARG_TYPE>
void TLIST<ARG_TYPE>::InsertBefore(POSITION Position, const TLIST &OtherList)
{
  if(Position == NULL || Position == pHead || IsEmpty())
  {
    AddHead(OtherList);
    return;
  }

  POSITION OtherPos = OtherList.GetTailPosition();
  while(OtherPos != NULL)
  {
    Position = InsertBefore(Position, OtherPos->Data);
    OtherPos = OtherPos->pPrev;
  }
}

template <class ARG_TYPE>
typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::InsertSorted(const ARG_TYPE &NewElement, bool bAsc)
{
  POSITION Pos = pHead;
  while(Pos)
  {
    if(bAsc == (NewElement < Pos->Data))
      break;
    Pos = Pos->pNext;
  }
  if(Pos == NULL)
    return AddTail(NewElement);
  return InsertBefore(Pos, NewElement);
}

template <class ARG_TYPE>
inline int TLIST<ARG_TYPE>::GetCount() const
{
  return NodeCount;
}

template <class ARG_TYPE>
inline bool TLIST<ARG_TYPE>::IsEmpty() const
{
  return NodeCount == 0 ? true : false;
}

template <class ARG_TYPE>
void TLIST<ARG_TYPE>::RemoveAll()
{
  while(pHead)
  {
    NODE *pNode = pHead->pNext;
    delete pHead;
    pHead = pNode;
  }

  pHead = pTail = NULL;
  NodeCount = 0;
}

template <class ARG_TYPE>
typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::CutAt(POSITION Position)
{
  if(IsEmpty())     // ����Ϊ��
    return NULL;

  if(Position == pHead || Position == pTail)
  {
    if(pHead == pTail)           //  ֻ��һ���ڵ�
      pHead = pTail = NULL;
    else if(Position == pHead)   //   ɾ������ͷ�ڵ�
    {
      pHead = pHead->pNext;
      pHead->pPrev = NULL;
    }
    else                         //   ɾ������β�ڵ�
    {
      pTail = pTail->pPrev;
      pTail->pNext = NULL;
    }
  }
  else   //   ɾ�������м�ڵ�
  {
    Position->pPrev->pNext = Position->pNext;
    Position->pNext->pPrev = Position->pPrev;
  }

  NodeCount--;
  assert(NodeCount >= 0);
  return Position;
}

template <class ARG_TYPE>
void TLIST<ARG_TYPE>::CutNode(TLIST<ARG_TYPE> &OtherList, POSITION &Position, int Count)
{
  OtherList.RemoveAll();
  assert(Position);

  for(int i = 0; i < Count && Position != NULL; i++)
  {
    POSITION CutPos = Position;
    Position = Position->pNext;
    OtherList.AddTail(CutAt(CutPos));
  }
}

template <class ARG_TYPE>
inline void TLIST<ARG_TYPE>::RemoveAt(POSITION Position)
{
  assert(Position);
  delete CutAt(Position);
}

template <class ARG_TYPE>
void TLIST<ARG_TYPE>::RemoveAt(POSITION &Position, int Count)
{
  assert(Position != NULL);

  for(int i = 0; i < Count && Position != NULL; i++)
  {
    POSITION DelPos = Position;
    Position = Position->pNext;
    RemoveAt(DelPos);
  }
}

template <class ARG_TYPE>
ARG_TYPE TLIST<ARG_TYPE>::RemoveHead()
{
  assert(pHead);

  ARG_TYPE HeadData = pHead->Data;
  RemoveAt(GetHeadPosition());
  return HeadData;
}

template <class ARG_TYPE>
ARG_TYPE TLIST<ARG_TYPE>::RemoveTail()
{
  assert(pTail);

  ARG_TYPE TailData = pTail->Data;
  RemoveAt(GetTailPosition());
  return TailData;
}

// ɾ������������ֵΪ Value �Ľڵ�
// ���سɹ�ɾ���Ľڵ����
template <class ARG_TYPE>
int TLIST<ARG_TYPE>::RemoveValue(const ARG_TYPE &Value)
{
  int RemoveCount = 0;
  POSITION ListPos = pHead;
  while(ListPos != NULL)
  {
    if(ListPos->Data == Value)
    {
      RemoveAt(ListPos, 1);
      RemoveCount++;
    }
    else
      ListPos = ListPos->pNext;
  }
  return RemoveCount;
}

template <class ARG_TYPE>
typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::GetPosFromIndex(int Index) const
{
  assert(Index >= 0 && Index < NodeCount);
  if(Index < 0 || Index >= NodeCount)
    return NULL;

  NODE *pNode = pHead;
  for(int i = 0; i < Index; i++)
    pNode = pNode->pNext;
  return pNode;
}

template <class ARG_TYPE>
int TLIST<ARG_TYPE>::GetIndexFromPos(POSITION Position) const
{
  int Index = 0;
  for(POSITION Pos = GetHeadPosition(); Pos != NULL; Pos = Pos->pNext, Index++)
    if(Position == Pos)
      return Index;
  return -1;
}

template <class ARG_TYPE>
typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::Find(const ARG_TYPE &SearchValue, POSITION StartAfter) const
{
  if(pHead == NULL)
    return NULL;

  POSITION Pos = (StartAfter == NULL ? pHead : StartAfter->pNext);
  for(; Pos != NULL; Pos = Pos->pNext)
    if(Pos->Data == SearchValue)
      break;

  return Pos;
}

template <class ARG_TYPE>
typename TLIST<ARG_TYPE>::POSITION TLIST<ARG_TYPE>::ReverseFind(const ARG_TYPE &SearchValue) const
{
  POSITION Pos = pTail;
  for(; Pos != NULL; Pos = Pos->pPrev)
    if(Pos->Data == SearchValue)
      break;

  return Pos;
}
/*
typedef TLIST<int> IntLIST;
typedef IntLIST::NODE * IntListPOS;
void PrintIntList(const IntLIST &IntList, TSTRING &ResultStr)
{
  char TempStr[50];

  IntListPOS ListPos = IntList.GetHeadPosition();
  for(; ListPos != NULL; ListPos = ListPos->pNext)
  //IntListPOS ListPos = IntList.GetTailPosition();
  //for(; ListPos != NULL; ListPos = ListPos->pPrev)
  {
    wsprintf(TempStr, "%d, ", ListPos->Data);
    ResultStr += TempStr;
  }
}
*/

// ɾ�������е��ظ��ڵ�
// ���سɹ�ɾ���Ľڵ����
template <class ARG_TYPE>
int TLIST<ARG_TYPE>::RemoveSame()
{
  int RemoveCount = 0;
  POSITION ListPos = pHead;
  while(ListPos != NULL)
  {
    POSITION FindPos = ListPos->pNext;
    while(FindPos != NULL)
    {
      if(FindPos->Data == ListPos->Data)
      {
        RemoveAt(FindPos, 1);
        RemoveCount++;
      }
      else
        FindPos = FindPos->pNext;
    }
    ListPos = ListPos->pNext;
  }
  return RemoveCount;
}

// ���е������еĵ�һ���ڵ㼰���һ���ڵ���ͬ�����нڵ㣬�Ѽ��е��Ľڵ����һ���µ����� GroupList
template <class ARG_TYPE>
int TLIST<ARG_TYPE>::CutSameGroup(TLIST &GroupList, int (*CompareFunc)(const ARG_TYPE &Data1, const ARG_TYPE &Data2))
{
  GroupList.RemoveAll();
  if(IsEmpty())
    return 0;

  NODE *pFirst = CutAt(GetHeadPosition());
  GroupList.AddTail(pFirst);

  for(NODE *pNode = GetHeadPosition(); pNode != NULL;)
  {
    if(CompareFunc(pFirst->Data, pNode->Data) == 0)
    {
      NODE *pCutNode = pNode;
      pNode = pNode->pNext;
      GroupList.AddTail(CutAt(pCutNode));
    }
    else
     pNode = pNode->pNext;
  }
  assert(CheckList());
  assert(GroupList.CheckList());
  return GroupList.GetCount();
}

// ��������
// �������������ȶ��ģ�
template <class ARG_TYPE>
inline void TLIST<ARG_TYPE>::SortInsert(int (*CompareFunc)(const ARG_TYPE &Data1, const ARG_TYPE &Data2))
{
  if(GetCount() <= 1)
    return;
  TLIST<ARG_TYPE> SortList;
  while(!IsEmpty())
  {
    NODE *pNode = CutAt(GetHeadPosition());
    SortList.InsertSorted(pNode, CompareFunc);
  }
  assert(pHead == NULL && pTail == NULL);
  pHead = SortList.pHead;
  pTail = SortList.pTail;
  NodeCount = SortList.NodeCount;
  SortList.pHead = SortList.pTail = NULL;
  SortList.NodeCount = 0;
}

// ��������
// �����������ǲ��ȶ��ģ�
template <class ARG_TYPE>
inline void TLIST<ARG_TYPE>::SortQuick(int (*CompareFunc)(const ARG_TYPE &Data1, const ARG_TYPE &Data2))
{
  SortQuick(GetHeadPosition(), GetTailPosition(), CompareFunc);
}

// ��������
template <class ARG_TYPE>
void TLIST<ARG_TYPE>::SortQuick(POSITION LowPos, POSITION HighPos, int (*CompareFunc)(const ARG_TYPE &Data1, const ARG_TYPE &Data2))
{
  if(LowPos == HighPos)
    return;

  assert(LowPos != NULL && HighPos != NULL);

  NODE *NewLowPos = LowPos;
  NODE *NewHighPos = LowPos;
  assert(GetIndexFromPos(LowPos) < GetIndexFromPos(HighPos));

  POSITION Pos = LowPos;
  do
  {
    Pos = NewHighPos->pNext;
    if(CompareFunc(Pos->Data, LowPos->Data) < 0)
    {
      NODE *pCutNode = CutAt(Pos);

      pCutNode->pNext = NewLowPos;
      pCutNode->pPrev = NewLowPos->pPrev;
      (NewLowPos->pPrev == NULL ? pHead : NewLowPos->pPrev->pNext) = pCutNode;
      NewLowPos->pPrev = pCutNode;

      NewLowPos = pCutNode;

      NodeCount++;
    }
    else
      NewHighPos = Pos;
  } while(Pos != HighPos);

  if(NewLowPos != LowPos && NewLowPos != LowPos->pPrev)
    SortQuick(NewLowPos, LowPos->pPrev, CompareFunc);
  if(NewHighPos != LowPos && NewHighPos != LowPos->pNext)
    SortQuick(LowPos->pNext, NewHighPos, CompareFunc);
}

template <class ARG_TYPE>
void TLIST<ARG_TYPE>::Swap(POSITION Pos1, POSITION Pos2)
{
  if(Pos1 == Pos2)
    return;

  assert(Pos1 != NULL && Pos2 != NULL);

  if(Pos1->pNext != Pos2)
  {
    // ���� Pos1 �ĺ�һ���ڵ�� pPrev ֵ
    (Pos1->pNext == NULL ? pTail : Pos1->pNext->pPrev) = Pos2;

    // ���� Pos2 ��ǰһ���ڵ�� pNext ֵ
    (Pos2->pPrev == NULL ? pHead : Pos2->pPrev->pNext) = Pos1;
  }

  if(Pos1->pPrev != Pos2)
  {
    // ���� Pos1 ��ǰһ���ڵ�� pNext ֵ
    (Pos1->pPrev == NULL ? pHead : Pos1->pPrev->pNext) = Pos2;

    // ���� Pos2 �ĺ�һ���ڵ�� pPrev ֵ
    (Pos2->pNext == NULL ? pTail : Pos2->pNext->pPrev) = Pos1;
  }

  if(Pos1->pNext == Pos2)
  {
    Pos1->pNext = Pos2->pNext;
    Pos2->pPrev = Pos1->pPrev;

    Pos1->pPrev = Pos2;
    Pos2->pNext = Pos1;
  }
  else if(Pos1->pPrev == Pos2)
  {
    Pos2->pNext = Pos1->pNext;
    Pos1->pPrev = Pos2->pPrev;

    Pos2->pPrev = Pos1;
    Pos1->pNext = Pos2;
  }
  else
  {
    // ���� Pos1, Pos2 �� pPrev ֵ
    POSITION TempPos = Pos1->pPrev;
    Pos1->pPrev = Pos2->pPrev;
    Pos2->pPrev = TempPos;

    // ���� Pos1, Pos2 �� pNext ֵ
    TempPos = Pos1->pNext;
    Pos1->pNext = Pos2->pNext;
    Pos2->pNext = TempPos;
  }
}

/*
template <class ARG_TYPE>
void TLIST<ARG_TYPE>::Swap(POSITION Pos1, POSITION Pos2)
{
  if(Pos1 == Pos2)
    return;

  assert(Pos1 != NULL && Pos2 != NULL);

  if(Pos1->pNext == Pos2)
  {
    // ���� Pos1 ��ǰһ���ڵ�� pNext ֵ
    if(Pos1->pPrev == NULL)
      pHead = Pos2;
    else
      Pos1->pPrev->pNext = Pos2;

    // ���� Pos2 �ĺ�һ���ڵ�� pPrev ֵ
    if(Pos2->pNext == NULL)
      pTail = Pos1;
    else
      Pos2->pNext->pPrev = Pos1;

    Pos1->pNext = Pos2->pNext;
    Pos2->pPrev = Pos1->pPrev;

    Pos1->pPrev = Pos2;
    Pos2->pNext = Pos1;
  }
  else if(Pos1->pPrev == Pos2)
  {
    // ���� Pos1 �ĺ�һ���ڵ�� pPrev ֵ
    if(Pos1->pNext == NULL)
      pTail = Pos2;
    else
      Pos1->pNext->pPrev = Pos2;

    // ���� Pos2 ��ǰһ���ڵ�� pNext ֵ
    if(Pos2->pPrev == NULL)
      pHead = Pos1;
    else
      Pos2->pPrev->pNext = Pos1;

    Pos2->pNext = Pos1->pNext;
    Pos1->pPrev = Pos2->pPrev;

    Pos2->pPrev = Pos1;
    Pos1->pNext = Pos2;
  }
  else
  {
    // ���� Pos1 ��ǰһ���ڵ�� pNext ֵ
    if(Pos1->pPrev == NULL)
      pHead = Pos2;
    else
      Pos1->pPrev->pNext = Pos2;

    // ���� Pos2 �ĺ�һ���ڵ�� pPrev ֵ
    if(Pos2->pNext == NULL)
      pTail = Pos1;
    else
      Pos2->pNext->pPrev = Pos1;

    // ���� Pos1 �ĺ�һ���ڵ�� pPrev ֵ
    if(Pos1->pNext == NULL)
      pTail = Pos2;
    else
      Pos1->pNext->pPrev = Pos2;

    // ���� Pos2 ��ǰһ���ڵ�� pNext ֵ
    if(Pos2->pPrev == NULL)
      pHead = Pos1;
    else
      Pos2->pPrev->pNext = Pos1;

    // ���� Pos1, Pos2 �� pPrev ֵ
    POSITION TempPos = Pos1->pPrev;
    Pos1->pPrev = Pos2->pPrev;
    Pos2->pPrev = TempPos;

    // ���� Pos1, Pos2 �� pNext ֵ
    TempPos = Pos1->pNext;
    Pos1->pNext = Pos2->pNext;
    Pos2->pNext = TempPos;
  }
}
*/

#ifdef __BASEIO_H__

// �����������浽 pIoStream ��������
template <class ARG_TYPE>
bool TLIST<ARG_TYPE>::Save(BaseIO *pIoStream) const
{
  assert(pIoStream != NULL);
  if(pIoStream == NULL)
    return false;

  if(!pIoStream->WriteValue(NodeCount))
    return false;

  for(POSITION Pos = pHead; Pos != NULL; Pos = Pos->pNext)
    if(!pIoStream->WriteValue(Pos->Data))
      return false;
  return true;
}

// �� pIoStream �������м�����������
template <class ARG_TYPE>
bool TLIST<ARG_TYPE>::Load(BaseIO *pIoStream)
{
  assert(pIoStream != NULL);
  if(pIoStream == NULL)
    return false;

  RemoveAll();

  int Count = 0;
  if(!pIoStream->ReadValue(Count))
    return false;

  for(int i = 0; i < Count; i++)
  {
    NODE *pNewNode = new NODE(ARG_TYPE());
    if(!pIoStream->ReadValue(pNewNode->Data))
    {
      delete pNewNode;
      return false;
    }
    AddTail(pNewNode);
  }
  return true;
}
#endif // __BASEIO_H__

#ifdef _DEBUG

// ���ڵ���һ���㷨ʱ, �ж�����Ľṹ���Ƿ���ȷ
template <class ARG_TYPE>
bool TLIST<ARG_TYPE>::CheckList() const
{
  if(pHead == NULL)
    return (pTail == NULL && NodeCount == 0);

  if(pTail == NULL)
    return (pHead == NULL && NodeCount == 0);

  if(pHead->pPrev != NULL)
    return false;
  if(pTail->pNext != NULL)
    return false;

  int Count = 0;
  NODE *pNode;
  for(pNode = pHead; pNode != NULL; pNode = pNode->pNext)
    Count++;
  if(Count != GetCount())
    return false;

  Count = 0;
  for(pNode = pTail; pNode != NULL; pNode = pNode->pPrev)
    Count++;
  if(Count != GetCount())
    return false;
  return true;
}

#endif // _DEBUG

}
#endif // __TLIST_H__