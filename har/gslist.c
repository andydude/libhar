#include "gslist.h"

G_DEFINE_BOXED_TYPE(GSList, g_slist, g_slist_copy, g_slist_free)
