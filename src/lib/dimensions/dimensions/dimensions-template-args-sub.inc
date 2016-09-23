/******************************************************************************/
/*
  Author  - Ming-Lun "Allen" Chou
  Web     - http://AllenChou.net
  Twitter - @TheAllenChou
*/
/******************************************************************************/

#define DIMENSION(D) MACRO_CONCAT(D, Exp1) - MACRO_CONCAT(D, Exp2)
#include "dimensions-enum.inc"
#undef DIMENSION
