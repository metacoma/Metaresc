#include <metaresc.h>

TYPEDEF_STRUCT (mr_array_t,
		(int, array1d, [2]),
		(int, array2d, [2][3]),
		(int, array3d, [2][3][4]),
		)

mr_array_t mr_array;

TYPEDEF_STRUCT (mr_bitfields_t,
		BITFIELD (int, _8bits, : __CHAR_BIT__),
		BITFIELD (int, _7bits, : __CHAR_BIT__ - 1),
		)

mr_bitfields_t mr_bitfields;
