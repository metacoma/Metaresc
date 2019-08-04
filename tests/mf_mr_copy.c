#include <metaresc.h>

#include <check.h>
#include <regression.h>

#include <mem_failures.h>

mr_status_t
mr_copy_method (void * arg)
{
  mr_ra_ptrdes_t * ptrs = arg;
  mr_conf_t _mr_conf;
  mr_status_t status = mr_copy_recursively (ptrs, &_mr_conf);
  if (MR_SUCCESS == status)
    {
      mr_conf.mr_mem = mr_mem;
      mr_ra_ptrdes_t ptrs = MR_SAVE (mr_conf_t, &_mr_conf);
      mr_conf.mr_mem = _mr_mem;
      if (ptrs.ra != NULL)
	{
	  mr_free_recursively (&ptrs);
	  mr_mem.free (NULL, NULL, 0, ptrs.ra);
	}
      return (MR_SUCCESS);
    }
  return (MR_FAILURE);
}

MR_START_TEST (mem_failures_mr_copy, "test memory operations failures for MR_COPY_RECURSIVELY") { 
  mr_detect_type (NULL);
  mr_ra_ptrdes_t ptrs = MR_SAVE (mr_conf_t, &mr_conf);
  ck_assert_msg (ptrs.ra != NULL, "Failed to save mr_conf for tests of MR_COPY_RECURSIVELY");
  mem_failures_method (mr_copy_method, &ptrs);
  MR_FREE (ptrs.ra);
} END_TEST

