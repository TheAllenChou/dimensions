/******************************************************************************/
/*
  Author  - Ming-Lun "Allen" Chou
  Web     - http://AllenChou.net
  Twitter - @TheAllenChou
 */
/******************************************************************************/

#include "unit-test.h"

#include "dimensions/dimensions.h"

void UnitTest::TestBasicUnits()
{
  typedef Units<1, 0, 0> Length;
  typedef Units<0, 1, 0> Time;
  typedef Units<0, 0, 1> Mass;

  typedef decltype(Length() / Time()) Velocity;
  typedef decltype(Velocity() / Time()) Acceleration;

  const Length m(1);
  const Time s(1);
  const Mass kg(1);

  const Velocity v = m / s / s * s;
}
