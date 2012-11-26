#ifndef _MR_TSEARCH_H_
#define _MR_TSEARCH_H_

#include <metaresc.h>

typedef int (*mr_compar_fn_t) (__const mr_ptr_t __x, __const mr_ptr_t __y, __const void * __context);
typedef void (*mr_action_fn_t) (__const mr_ptr_t __nodep, mr_rb_visit_order_t __value, int __level, __const void * __context);
typedef void (*mr_free_fn_t) (mr_ptr_t __nodep, __const void * __context);

/* Search for an entry matching the given KEY in the tree pointed to
   by *ROOTP and insert a new element if not found.  */
extern void *mr_tsearch (__const mr_ptr_t __key, mr_red_black_tree_node_t **__rootp,
			 mr_compar_fn_t __compar, __const void * __context);

/* Search for an entry matching the given KEY in the tree pointed to
   by *ROOTP.  If no matching entry is available return NULL.  */
extern void *mr_tfind (__const mr_ptr_t __key, mr_red_black_tree_node_t *__const *__rootp,
		       mr_compar_fn_t __compar, __const void * __context);

/* Remove the element matching KEY from the tree pointed to by *ROOTP.  */
extern void *mr_tdelete (__const mr_ptr_t __key,
			 mr_red_black_tree_node_t **__restrict __rootp,
			 mr_compar_fn_t __compar,
			 __const void * __context);

/* Walk through the whole tree and call the ACTION callback for every node
   or leaf.  */
extern void mr_twalk (__const mr_red_black_tree_node_t *__root, mr_action_fn_t __action, __const void * __context);

/* Destroy the whole tree, call FREEFCT for each node or leaf.  */
extern void mr_tdestroy (mr_red_black_tree_node_t *__root, mr_free_fn_t __freefct, __const void * __context);

#endif /* _MR_TSEARCH_H_ */
