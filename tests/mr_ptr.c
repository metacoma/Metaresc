#include <math.h>
#include <check.h>
#include <metaresc.h>
#include <regression.h>

#include <union.h>

#define ASSERT_SAVE_LOAD_MR_PTR(METHOD, TYPE, VALUE, ...) ({		\
      struct_mr_ptr_t x = { 0, { (TYPE[]){ { 0, { M_PI }, VALUE } } }, #TYPE }; \
      ASSERT_SAVE_LOAD (METHOD, struct_mr_ptr_t, &x, __VA_ARGS__);	\
    })

MR_START_TEST (union_mr_ptr_int, "mr_ptr_t is a pointer on any Metaresc type") {
  ALL_METHODS (ASSERT_SAVE_LOAD_MR_PTR, struct_union_int8_t, 1);
  ALL_METHODS (ASSERT_SAVE_LOAD_MR_PTR, struct_union_int16_t, 1);
  ALL_METHODS (ASSERT_SAVE_LOAD_MR_PTR, struct_union_int32_t, 1);
  ALL_METHODS (ASSERT_SAVE_LOAD_MR_PTR, struct_union_int64_t, 1);
} END_TEST

MR_START_TEST (union_mr_ptr_enum, "mr_ptr_t is a pointer on any Metaresc type") {
  ALL_METHODS (ASSERT_SAVE_LOAD_MR_PTR, struct_union_enum8_t, U8D_INT32);
  ALL_METHODS (ASSERT_SAVE_LOAD_MR_PTR, struct_union_enum16_t, U16D_INT32);
  ALL_METHODS (ASSERT_SAVE_LOAD_MR_PTR, struct_union_enum32_t, U32D_INT32);
  ALL_METHODS (ASSERT_SAVE_LOAD_MR_PTR, struct_union_enum64_t, U64D_INT32);
  ALL_METHODS (ASSERT_SAVE_LOAD_MR_PTR, struct_union_enum_t, UD_INT32);
} END_TEST

MR_START_TEST (union_mr_ptr_enum_ptr, "mr_ptr_t is a pointer on any Metaresc type") {
  ALL_METHODS (ASSERT_SAVE_LOAD_MR_PTR, struct_union_enum_ptr_t, (enum_discriminator_t[]){ UD_INT32 });
} END_TEST

MR_START_TEST (union_mr_ptr_string_y, "mr_ptr_t is a pointer on any Metaresc type") {
  ALL_METHODS (ASSERT_SAVE_LOAD_MR_PTR, struct_union_string_t, "y");
  ALL_METHODS (ASSERT_SAVE_LOAD_MR_PTR, struct_union_ca_t, "y");
  ALL_METHODS (ASSERT_SAVE_LOAD_MR_PTR, struct_union_string_ptr_t, (string_t[]){ "y" });
  ALL_METHODS (ASSERT_SAVE_LOAD_MR_PTR, struct_union_ca_ptr_t, (ca2_t[]){ "y" });
} END_TEST

MR_START_TEST (union_mr_ptr_string, "mr_ptr_t is a pointer on any Metaresc type") {
  struct_mr_ptr_t x = { 0, { "string_t" }, "string_t" };	
  ALL_METHODS (ASSERT_SAVE_LOAD, struct_mr_ptr_t, &x);
  x.ptr.ptr = "string longer then sizeof (void*)";
  ALL_METHODS (ASSERT_SAVE_LOAD, struct_mr_ptr_t, &x);	
} END_TEST

MAIN ();
