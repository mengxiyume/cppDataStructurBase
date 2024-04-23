#pragma once

//#define _SINGLELINK_

#ifdef _SINGLELINK_
#include "SingleLinkList.h"
typedef SingleLinkListDataType LinkListDataType;
typedef SLList LinkList;
#else
#include "DoubleLinkList.h"
typedef DoubleLinkListDataType LinkListDataType;
typedef DLList LinkList;
#endif

typedef LinkListDataType LLData, * pLLData;
typedef LinkList LList, * pLList;