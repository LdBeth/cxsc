/*
**  CXSC is a C++ library for eXtended Scientific Computing (V 2.5.4)
**
**  Copyright (C) 1990-2000 Institut fuer Angewandte Mathematik,
**                          Universitaet Karlsruhe, Germany
**            (C) 2000-2014 Wiss. Rechnen/Softwaretechnologie
**                          Universitaet Wuppertal, Germany   
**
**  This library is free software; you can redistribute it and/or
**  modify it under the terms of the GNU Library General Public
**  License as published by the Free Software Foundation; either
**  version 2 of the License, or (at your option) any later version.
**
**  This library is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
**  Library General Public License for more details.
**
**  You should have received a copy of the GNU Library General Public
**  License along with this library; if not, write to the Free
**  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* CVS $Id: idot.hpp,v 1.31 2014/01/30 17:23:45 cxsc Exp $ */

#ifndef _CXSC_IDOT_HPP_INCLUDED
#define _CXSC_IDOT_HPP_INCLUDED

#include <iostream>
#include <string>
#include "dot.hpp"
#include "interval.hpp"

namespace cxsc {

//!The Data Type idotprecision
/*!
The data types dotprecision, idotprecision, cdotprecision and cidotprecision are based on the scalar data types real, interval, complex, and
cinterval, respectively. Variables of these data types permit the exact representation of products of two arbitrary numbers of the
corresponding scalar base type and the exact summation of an arbitrary number of such products in a dotprecision accumulator,
i.e. in a fixed-point format of suitable size.

Since C-XSC Version 2.3.0, the precision for dot products computed with the dotprecision types can be choosen by the user. The default is precision k=0, which means maximum precision (the behaviour of older C-XSC Versions). For k=1, pure floating point operations are used and an error bound is computed using manipulation of the rounding mode of the processor. For k>=2, the so called DotK algorithm is used, simulating higher precision computations and also computing an error bound. When calling the rnd() function, the error bound will be added to the result interval. The resulting intervals will be wider for lower k, but computations will be significantly faster than with maximum precision (k=0).

\sa cxsc::dotprecision
*/
class idotprecision
{
   private:
      // ---- Datenelemente ---------------------------------------
      dotprecision inf,sup;
      int k; //precision

   public:
      // ---- Constructors  ---------------------------------------
      //! Constructor of class idotprecision
      idotprecision() : k(0) {}
      //! Constructor of class idotprecision
      inline idotprecision(const dotprecision&, const dotprecision&) noexcept(false);
      //! Constructor of class idotprecision
      inline idotprecision(const idotprecision&);
      
//      explicit inline idotprecision(int n) : inf(n), sup(n)      { }
//      explicit inline idotprecision(int a,int b) : inf(a), sup(b) { }
//      explicit inline idotprecision(const float &d) : inf(double(d)), sup(double(d)) { }
//      explicit inline idotprecision(const float &a, const float &b) : inf(double(a)),
//      sup(double(b)) { }
//      explicit inline idotprecision(const double &d) : inf(d), sup(d) { }
//      explicit inline idotprecision(const double &a, const double &b) : inf(a), sup(b) { }
      //! Constructor of class idotprecision
      explicit inline idotprecision(const real & a) : inf(a), sup(a), k(0) { }
      //! Constructor of class idotprecision
      explicit inline idotprecision(const real & a,const real & b) : inf(a), sup(b), k(0) { }
      //! Constructor of class idotprecision
      explicit inline idotprecision(const interval & a) : inf(Inf(a)), sup(Sup(a)), k(0) { }
      //! Constructor of class idotprecision
      explicit inline idotprecision(const dotprecision &r) : inf(r), sup(r), k(0)  { inf.set_k(0); sup.set_k(0);  }
      //! Constructor of class idotprecision
      explicit        idotprecision(const l_real &) noexcept;     // In l_real.cpp
      //! Constructor of class idotprecision
      explicit        idotprecision(const l_real &,const l_real &); // in l_real.cpp
      //! Constructor of class idotprecision
      explicit        idotprecision(const l_interval &) noexcept; // In l_interval.cpp

      //! Get currently set precision for computation of dot products
      inline int get_k() const { return k; }
      //! Set precision for computation of dot products
      inline void set_k(unsigned int i) { k=i; inf.set_k(i); sup.set_k(i); }
      //! Get currently set precision for computation of dot products
      inline int get_dotprec() const { return k; }
      //! Set precision for computation of dot products
      inline void set_dotprec(unsigned int i) { k=i; inf.set_k(i); sup.set_k(i); }
      
      // inline idotprecision& operator= (const double& a)       { inf=sup=a; return *this; }
      //! Implementation of standard assigning operator
      inline idotprecision& operator= (const real& a)         { inf=sup=a; return *this; }
      //! Implementation of standard assigning operator
      inline idotprecision& operator= (const interval& a)     { inf=Inf(a); sup=Sup(a); return *this; }
      // inline idotprecision& operator= (const int& a)          { inf=sup=a; return *this; }
      //! Implementation of standard assigning operator
      inline idotprecision& operator= (const dotprecision& a) { inf=sup=a; return *this; }
      //! Implementation of standard assigning operator
      inline idotprecision& operator= (const idotprecision& a){ inf=a.inf; sup=a.sup; return *this; }
      //! Implementation of standard assigning operator
      inline idotprecision& operator= (const l_real & a)      { inf=sup=a; return *this; }
      //! Implementation of standard assigning operator
             idotprecision& operator= (const l_interval &) noexcept; // in l_interv.cpp

      // ---- Destruktor    ----
      // ~idotprecision() {} unnoetig

      // ---- Typwandlungen ----
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline idotprecision _idotprecision(const real &);
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline idotprecision _idotprecision(const real &,const real &);
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline idotprecision _unchecked_idotprecision(const real &,const real &);
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline idotprecision _idotprecision(const dotprecision&);
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline idotprecision _idotprecision(const dotprecision&, const dotprecision&);
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline idotprecision _unchecked_idotprecision(const dotprecision&, const dotprecision&);

      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline idotprecision _idotprecision(const l_real &a) noexcept { return idotprecision(a); }
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline idotprecision _idotprecision(const l_real &a,const l_real &b) { return idotprecision(a,b); }


      // ---- Ausgabefunkt. ---------------------------------------
      //! Implementation of standard input method
      friend std::istream& operator >> (std::istream& s, idotprecision& a)       noexcept;
      //! Implementation of standard output method
      friend std::ostream& operator << (std::ostream& s, const idotprecision& a) noexcept;
      //! Implementation of standard input method
      friend std::string&  operator >> (std::string&  s, idotprecision& a)       noexcept;
      //! Implementation of standard output method
      friend std::string&  operator << (std::string&  s, const idotprecision& a) noexcept;
      //! Implementation of standard input method
      friend void          operator >> (const std::string &s,idotprecision& a)   noexcept;
      //! Implementation of standard input method
      friend void          operator >> (const char *s       ,idotprecision& a)   noexcept;

      // ---- Standardfunkt ---- (arithmetische Operatoren)
      //! Implementation of standard algebraic negative sign operation
      friend     inline idotprecision operator -(const idotprecision &) noexcept;
      //! Implementation of standard algebraic positive sign operation
      friend     inline idotprecision operator +(const idotprecision &) noexcept;

      //! Implementation of standard algebraic addition operation
      friend     inline idotprecision operator +(const idotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend     inline idotprecision operator -(const idotprecision &,const idotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend     inline idotprecision operator |(const idotprecision &,const idotprecision &) noexcept;
      //! Returns the intersection of the arguments
      friend     inline idotprecision operator &(const idotprecision &,const idotprecision &) noexcept(false);

      //! Implementation of standard algebraic addition operation
      friend     inline idotprecision operator +(const idotprecision &,const dotprecision &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend     inline idotprecision operator +(const dotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend     inline idotprecision operator -(const idotprecision &,const dotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend     inline idotprecision operator -(const dotprecision &,const idotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend     inline idotprecision operator |(const dotprecision &,const idotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend     inline idotprecision operator |(const idotprecision &,const dotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend     inline idotprecision operator |(const dotprecision &,const dotprecision &)  noexcept;
      //! Returns the intersection of the arguments
      friend     inline idotprecision operator &(const dotprecision &,const idotprecision &) noexcept(false);
      //! Returns the intersection of the arguments
      friend     inline idotprecision operator &(const idotprecision &,const dotprecision &) noexcept(false);

      //! Implementation of standard algebraic addition operation
      friend     inline idotprecision operator +(const idotprecision &,const long &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend     inline idotprecision operator +(const long &,const idotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend     inline idotprecision operator -(const idotprecision &,const long &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend     inline idotprecision operator -(const long &,const idotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend     inline idotprecision operator |(const long &,const idotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend     inline idotprecision operator |(const idotprecision &,const long &) noexcept;
      //! Returns the intersection of the arguments
      friend     inline idotprecision operator &(const long &,const idotprecision &) noexcept(false);
      //! Returns the intersection of the arguments
      friend     inline idotprecision operator &(const idotprecision &,const long &) noexcept(false);

      //! Implementation of standard algebraic addition operation
      friend     inline idotprecision operator +(const idotprecision &,const real &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend     inline idotprecision operator +(const real &,const idotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend     inline idotprecision operator -(const idotprecision &,const real &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend     inline idotprecision operator -(const real &,const idotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend     inline idotprecision operator |(const real &,const idotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend     inline idotprecision operator |(const idotprecision &,const real &) noexcept;
      //! Returns the intersection of the arguments
      friend     inline idotprecision operator &(const real &,const idotprecision &) noexcept(false);
      //! Returns the intersection of the arguments
      friend     inline idotprecision operator &(const idotprecision &,const real &) noexcept(false);
      
      //! Implementation of standard algebraic addition operation
      friend            idotprecision operator +(const idotprecision &,const l_real &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend            idotprecision operator +(const l_real &,const idotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend            idotprecision operator -(const idotprecision &,const l_real &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend            idotprecision operator -(const l_real &,const idotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend            idotprecision operator |(const l_real &,const idotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend            idotprecision operator |(const idotprecision &,const l_real &) noexcept;
      //! Returns the intersection of the arguments
      friend            idotprecision operator &(const l_real &,const idotprecision &) noexcept(false);
      //! Returns the intersection of the arguments
      friend            idotprecision operator &(const idotprecision &,const l_real &) noexcept(false);

      //! Implementation of standard algebraic addition operation
      friend     inline idotprecision operator +(const idotprecision &,const interval &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend     inline idotprecision operator +(const interval &,const idotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend     inline idotprecision operator -(const idotprecision &,const interval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend     inline idotprecision operator -(const interval &,const idotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend     inline idotprecision operator |(const interval &,const idotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend     inline idotprecision operator |(const idotprecision &,const interval &) noexcept;
      //! Returns the intersection of the arguments
      friend     inline idotprecision operator &(const interval &,const idotprecision &) noexcept(false);
      //! Returns the intersection of the arguments
      friend     inline idotprecision operator &(const idotprecision &,const interval &) noexcept(false);

      //! Implementation of standard algebraic addition and allocation operation
      friend     inline idotprecision & operator +=(idotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend     inline idotprecision & operator -=(idotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard algebraic addition and allocation operation
      friend     inline idotprecision & operator +=(idotprecision &,const interval &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend     inline idotprecision & operator -=(idotprecision &,const interval &) noexcept;
      //! Implementation of standard algebraic addition and allocation operation
      friend     inline idotprecision & operator +=(idotprecision &,const real &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend     inline idotprecision & operator -=(idotprecision &,const real &) noexcept;
      //! Implementation of standard algebraic addition and allocation operation
      friend            idotprecision & operator +=(idotprecision &,const l_real &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend            idotprecision & operator -=(idotprecision &,const l_real &) noexcept;
      //! Implementation of standard algebraic addition and allocation operation
      friend     inline idotprecision & operator +=(idotprecision &,const l_interval &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend     inline idotprecision & operator -=(idotprecision &,const l_interval &) noexcept;
      
      //! Allocates the convex hull of the arguments to the first argument
      friend     inline idotprecision & operator |=(idotprecision &,const idotprecision &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend     inline idotprecision & operator &=(idotprecision &,const idotprecision &) noexcept(false);

      //! Implementation of standard algebraic addition and allocation operation
      friend     inline idotprecision & operator +=(idotprecision &,const dotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend     inline idotprecision & operator -=(idotprecision &,const dotprecision &) noexcept;

      //! Allocates the convex hull of the arguments to the first argument
      friend     inline idotprecision & operator |=(idotprecision &,const dotprecision &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend     inline idotprecision & operator &=(idotprecision &,const dotprecision &) noexcept(false);

//      friend     inline idotprecision & operator |=(idotprecision & i,const long & l) noexcept { return i|=_dotprecision(l); }
//      friend     inline idotprecision & operator &=(idotprecision & i,const long & l) noexcept(false) { return i&=_dotprecision(l); }
      //! Allocates the convex hull of the arguments to the first argument
      friend     inline idotprecision & operator |=(idotprecision & i,const real & l) noexcept { return i|=dotprecision(l); }
      //! Allocates the intersection of the arguments to the first argument
      friend     inline idotprecision & operator &=(idotprecision & i,const real & l) noexcept(false) { return i&=dotprecision(l); }

      //! Allocates the convex hull of the arguments to the first argument
      friend            idotprecision & operator |=(idotprecision & i,const l_real & l) noexcept; // in l_real.cpp
      //! Allocates the intersection of the arguments to the first argument
      friend            idotprecision & operator &=(idotprecision & i,const l_real & l) noexcept(false); // in l_real.cpp

      //! Allocates the convex hull of the arguments to the first argument
      friend     inline idotprecision & operator |=(idotprecision & i,const l_interval & l) noexcept; // in l_interv.inl
      //! Allocates the intersection of the arguments to the first argument
      friend     inline idotprecision & operator &=(idotprecision & i,const l_interval & l) noexcept(false); // in l_interv.inl

      // ---- Vergleichsop. ----

      //! Implementation of standard equality operation
      friend inline bool operator ==(const idotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const idotprecision &,const idotprecision &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const dotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const dotprecision &,const idotprecision &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const idotprecision &,const dotprecision &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const idotprecision &,const dotprecision &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const real &,const idotprecision &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const real &,const idotprecision &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const idotprecision &,const real &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const idotprecision &,const real &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const interval &,const idotprecision &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const interval &,const idotprecision &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const idotprecision &,const interval &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const idotprecision &,const interval &) noexcept;

      // ---- Mengenvergle. ----

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const idotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const idotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const idotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const idotprecision &,const idotprecision &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const dotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard more-than operation
      friend inline bool operator  >(const dotprecision &,const idotprecision &) noexcept { return false; }
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const dotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const dotprecision &,const idotprecision &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const idotprecision &,const dotprecision &) noexcept { return false; }
      //! Implementation of standard more-than operation
      friend inline bool operator  >(const idotprecision &,const dotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const idotprecision &,const dotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const idotprecision &,const dotprecision &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const real &,const idotprecision &) noexcept;
      //! Implementation of standard more-than operation
      friend inline bool operator  >(const real &,const idotprecision &) noexcept { return false; }
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const real &,const idotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const real &,const idotprecision &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const idotprecision &,const real &) noexcept { return false; }
      //! Implementation of standard more-than operation
      friend inline bool operator  >(const idotprecision &,const real &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const idotprecision &,const real &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const idotprecision &,const real &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const interval &,const idotprecision &) noexcept;
      //! Implementation of standard more-than operation
      friend inline bool operator  >(const interval &,const idotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const interval &,const idotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const interval &,const idotprecision &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const idotprecision &,const interval &) noexcept;
      //! Implementation of standard more-than operation
      friend inline bool operator  >(const idotprecision &,const interval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const idotprecision &,const interval &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const idotprecision &,const interval &) noexcept;

      //! Implementation of standard negation operation
      friend inline bool operator !(const idotprecision&) noexcept;
//                         operator void *(void) noexcept { return (void *)(!*this); }
      
      // ---- Funktionen    ----
      
      //! Returns the infimum of a dotprecison interval
      friend dotprecision & Inf(idotprecision& a)  noexcept { return a.inf; }
      //! Returns the supremum of a dotprecison interval
      friend dotprecision & Sup(idotprecision& a)  noexcept { return a.sup; }
      //! Returns the infimum of a dotprecison interval
      friend const dotprecision & Inf(const idotprecision& a)  noexcept { return a.inf; }
      //! Returns the supremum of a dotprecison interval
      friend const dotprecision & Sup(const idotprecision& a)  noexcept { return a.sup; }
      
      //! Returns the dotprecison interval with the new given infimum value
      friend inline idotprecision& SetInf (idotprecision &, const dotprecision &) noexcept;
      //! Returns the dotprecison interval with the new given supremum value
      friend inline idotprecision& SetSup (idotprecision &, const dotprecision &) noexcept;
      //! Returns the dotprecison interval with the new given infimum value
      friend inline idotprecision& SetInf (idotprecision &, const real &) noexcept;
      //! Returns the dotprecison interval with the new given supremum value
      friend inline idotprecision& SetSup (idotprecision &, const real &) noexcept;
      //! Returns the dotprecison interval with the unchecked new given infimum value
      friend inline idotprecision& UncheckedSetInf (idotprecision &, const dotprecision &) noexcept;
      //! Returns the dotprecison interval with the unchecked new given supremum value
      friend inline idotprecision& UncheckedSetSup (idotprecision &, const dotprecision &) noexcept;
      //! Returns the dotprecison interval with the unchecked new given infimum value
      friend inline idotprecision& UncheckedSetInf (idotprecision &, const real &) noexcept;
      //! Returns the dotprecison interval with the unchecked new given supremum value
      friend inline idotprecision& UncheckedSetSup (idotprecision &, const real &) noexcept;

      //! Returns if the dotprecision interval is empty
      friend inline bool IsEmpty (const idotprecision& a) noexcept;

      //! Returns the absolute value of a dotprecision interval
      friend inline idotprecision   abs  (const idotprecision& a) noexcept;
      //! Returns the middle of the dotprecision interval
      friend inline dotprecision    mid  (const idotprecision& a) noexcept;
      //! Returns the rounded diameter of the dotprecision interval
      friend inline dotprecision    diam (const idotprecision& a) noexcept;
      
      friend void rnd(const idotprecision &,interval &) noexcept;
      friend interval rnd(const idotprecision &) noexcept;
      
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend        void accumulate  (idotprecision&, const interval&, const interval&) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (idotprecision&, const interval&, const real&) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (idotprecision&, const real&, const interval&) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (idotprecision&, const real&, const real&) noexcept;
};

//----------------------------------------------------------------------
// global verfuegbare IDotprecision Akku's   

//#define MAXIDOTAKKU     3
//extern idotprecision idotakku[MAXIDOTAKKU];
  
//----------------------------------------------------------------------

} // namespace cxsc 

#include "idot.inl"

#endif 

