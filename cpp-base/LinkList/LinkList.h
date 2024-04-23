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

//请使用这些名字
typedef LinkListDataType LLData;
typedef LinkList LList;