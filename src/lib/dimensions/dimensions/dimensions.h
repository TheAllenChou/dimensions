/******************************************************************************/
/*
  Author  - Ming-Lun "Allen" Chou
  Web     - http://AllenChou.net
  Twitter - @TheAllenChou
*/
/******************************************************************************/

#ifndef DIMENSIONS_H
#define DIMENSIONS_H


#include <cinttypes>
#include <limits>

#define MACRO_CONCAT(x, y) x ## y


template
<
  #include "dimensions-template-params.inc"
>
class Units
{
  public:
    typedef float Storage;

    static const Units PosInfinity() { return Units(std::numeric_limits<Storage>::max()); }
    static const Units NegInfinity() { return Units(std::numeric_limits<Storage>::lowest()); }
    static const Units Zero() { return From(0.0); }

    template <typename V> static const Units From(V value) { return Units(static_cast<Storage>(value)); }
    template <typename V> const V To() const { return static_cast<V>(m_data); }

    Units() { }
    template <typename V> Units(V value) : m_data(static_cast<Storage>(value)) { }

    const Storage GetRaw() const { return m_data; }

    const Units operator+() const { return Units(+m_data); }
    const Units operator-() const { return Units(-m_data); }

    template <typename V> Units &operator*=(const V rhs) { m_data *= static_cast<Storage>(rhs); return *this; }
    template <typename V> Units &operator/=(const V rhs) { m_data /= static_cast<Storage>(rhs); return *this; }

  private:
    Storage m_data;
};


// operator+(Units, Units)
template
<
  #include "dimensions-template-params.inc"
>
const Units
<
  #include "dimensions-template-args.inc"
>
operator+
(
  Units
  <
    #include "dimensions-template-args.inc"
  > lhs, 
  Units
  <
    #include "dimensions-template-args.inc"
  > rhs
)
{ return lhs.GetRaw() + rhs.GetRaw(); }


// operator-(Units, Units)
template
<
  #include "dimensions-template-params.inc"
>
const Units
<
  #include "dimensions-template-args.inc"
>
operator-
(
  Units
  <
    #include "dimensions-template-args.inc"
  > lhs, 
  Units
  <
    #include "dimensions-template-args.inc"
  > rhs
)
{ return lhs.GetRaw() - rhs.GetRaw(); }


// operator*(Units, Units::Storage)
template
<
  #include "dimensions-template-params.inc"
>
const Units
<
  #include "dimensions-template-args.inc"
>
operator*
(
  Units
  <
    #include "dimensions-template-args.inc"
  > lhs, 
  typename Units
  <
    #include "dimensions-template-args.inc"
  >::Storage rhs
)
{
  return
    Units
    <
      #include "dimensions-template-args.inc"
    >::From(lhs.GetRaw() * rhs);
}


// operator*(Units::Storage, Units)
template
<
  #include "dimensions-template-params.inc"
>
const Units
<
  #include "dimensions-template-args.inc"
>
operator*
(
  typename Units
  <
    #include "dimensions-template-args.inc"
  >::Storage lhs, 
  Units
  <
    #include "dimensions-template-args.inc"
  > rhs
)
{
  return
    Units
    <
      #include "dimensions-template-args.inc"
    >::From(lhs * rhs.GetRaw());
}


// operator/(Units, Units::Storage)
template
<
#include "dimensions-template-params.inc"
>
const Units
<
#include "dimensions-template-args.inc"
>
operator/
(
  Units
  <
#include "dimensions-template-args.inc"
  > lhs, 
  typename Units
  <
#include "dimensions-template-args.inc"
  >::Storage rhs
  )
{
  return
    Units
    <
#include "dimensions-template-args.inc"
    >::From(lhs.GetRaw() / rhs);
}


// operator<(Units, Units)
template
<
  #include "dimensions-template-params.inc"
>
const bool operator<
(
  Units
  <
    #include "dimensions-template-args.inc"
  > lhs, 
  Units
  <
    #include "dimensions-template-args.inc"
  > rhs
)
{ return lhs.GetRaw() < rhs.GetRaw(); }


// operator<=(Units, Units)
template
<
  #include "dimensions-template-params.inc"
>
const bool operator<=
(
  Units
  <
    #include "dimensions-template-args.inc"
  > lhs, 
  Units
  <
    #include "dimensions-template-args.inc"
  > rhs
)
{ return lhs.GetRaw() <= rhs.GetRaw(); }


// operator>(Units, Units)
template
<
  #include "dimensions-template-params.inc"
>
const bool operator>
(
  Units
  <
    #include "dimensions-template-args.inc"
  > lhs, 
  Units
  <
    #include "dimensions-template-args.inc"
  > rhs
)
{ return lhs.GetRaw() > rhs.GetRaw(); }



// operator>=(Units, Units)
template
<
  #include "dimensions-template-params.inc"
>
const bool operator>=
(
  Units
  <
    #include "dimensions-template-args.inc"
  > lhs, 
  Units
  <
    #include "dimensions-template-args.inc"
  > rhs
)
{ return lhs.GetRaw() >= rhs.GetRaw(); }


// operator==(Units, Units)
template
<
  #include "dimensions-template-params.inc"
>
const bool operator==
(
  Units
  <
    #include "dimensions-template-args.inc"
  > lhs, 
  Units
  <
    #include "dimensions-template-args.inc"
  > rhs
)
{ return lhs.GetRaw() == rhs.GetRaw(); }


// operator!=(Units, Units)
template
<
  #include "dimensions-template-params.inc"
>
const bool operator!=
(
  Units
  <
    #include "dimensions-template-args.inc"
  > lhs, 
  Units
  <
    #include "dimensions-template-args.inc"
  > rhs
)
{ return lhs.GetRaw() != rhs.GetRaw(); }


// operator*(Units1, Units2)
template
<
  #include "dimensions-template-params-op.inc"
>
const Units
<
  #include "dimensions-template-args-add.inc"
>
operator*
(
  Units
  <
    #include "dimensions-template-args-op1.inc"
  > lhs,
  Units
  <
    #include "dimensions-template-args-op2.inc"
  > rhs
)
{
  return
    Units
    <
      #include "dimensions-template-args-add.inc"
    >
    (lhs.GetRaw() * rhs.GetRaw());
}


// operator/(Units1, Units2)
template
<
  #include "dimensions-template-params-op.inc"
>
const Units
<
  #include "dimensions-template-args-sub.inc"
>
operator/
(
  Units
  <
    #include "dimensions-template-args-op1.inc"
  > lhs,
  Units
  <
    #include "dimensions-template-args-op2.inc"
  > rhs
)
{
  return
    Units
    <
      #include "dimensions-template-args-sub.inc"
    >
    (lhs.GetRaw() / rhs.GetRaw());
}


#undef MACRO_CONCAT


#endif
