/******************************************************************************/
/*
  Author  - Ming-Lun "Allen" Chou
  Web     - http://AllenChou.net
  Twitter - @TheAllenChou
*/
/******************************************************************************/

#define DIMENSION(D) std::int64_t MACRO_CONCAT(D, Exp1), std::int64_t MACRO_CONCAT(D, Exp2)
#include "dimensions-enum.inc"
#undef DIMENSION
