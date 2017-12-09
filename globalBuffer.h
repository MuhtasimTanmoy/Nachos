
#include "copyright.h"
#include "system.h"
#include "synch.h"

Lock* lock;
Condition* tableEmpty;
Condition* tableFull;
List<int>* items;

int itemCount;
int maxItems = 20
