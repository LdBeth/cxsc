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

/* CVS $Id: l_interval.hpp,v 1.36 2014/01/30 17:23:46 cxsc Exp $ */

#ifndef _CXSC_L_INTERVAL_HPP_INCLUDED
#define _CXSC_L_INTERVAL_HPP_INCLUDED

#include <iostream>
#include <string>
#include "real.hpp"
#include "interval.hpp"
#include "l_real.hpp"
#include "except.hpp"
#include "idot.hpp"

namespace cxsc {

class l_interval_Inf;
class l_interval_Sup;

//! The Multiple-Precision Data Type l_interval
/*!
The multiple-precision data type l_interval is a variant of the scalar 
type interval, which provides support for longer numbers, thus increasing 
the accuracy of the data type.

The external variable stagprec(=p) defines the precision of the
staggered arithmetic. An interval x of type l_interval is realized by

\f$ x = x_1 + x_2 + ... + x_p + x_{(p+1)};  p = 1,2,3, ...;\f$

\f$ \mbox{Inf}(x) = x_1 + x_2 + ... + x_p;\f$

\f$ \mbox{Sup}(x) = x_1 + x_2 + ... + x_{(p-1)} + x_{(p+1)};\f$

\f$ \mbox{diam}(x) = x_{(p+1)} - x_{(p-1)};\f$


Staggered interval computations with precision p are only sensible, if

        \f$ RelDiam(x) < 10^{-16*(p-1)}\f$

is fulfilled. Interim results with \f$|x|-->10^{-300}\f$ should be avoided in
order to keep  a hight accuracy of the final result.



\sa interval
*/
class l_interval
{
      friend class l_interval_Inf;
      friend class l_interval_Sup;
   
   private:
      // ---- Datenelemente ---------------------------------------

         // die eigentliche Datenstruktur
         // ein l_interval der Praezision n besteht aus n+1 reals , wobei die reals
         // 1..n das inf,
         // 1..n-1,n+1 das sup darstellen!
         // Ein echtes interval liegt also nur in den letzten beiden reals vor!
      int prec;
      real *data;
  

   public:
      // ---- Konstruktoren ---------------------------------------
#if (CXSC_INDEX_CHECK)
      //! Constructor of class l_interval
      inline l_interval()                              noexcept(false);
      //! Constructor of class l_interval
      inline l_interval(const l_interval &)            noexcept(false); 

      //! Constructor of class l_interval
             l_interval(const l_real &, const l_real &) noexcept(false);
      //! Constructor of class l_interval
             l_interval(const real &, const l_real &)   noexcept(false);
      //! Constructor of class l_interval
             l_interval(const l_real &, const real &)   noexcept(false);
      //! Constructor of class l_interval
      inline l_interval(const real &, const real &)     noexcept(false);

      //! Constructor of class l_interval
      explicit        l_interval(const dotprecision &) noexcept(false);
      //! Constructor of class l_interval
      explicit        l_interval(const dotprecision &,const dotprecision &) noexcept(false);
      //! Constructor of class l_interval
      explicit        l_interval(const idotprecision &) noexcept(false);
#else
      //! Constructor of class l_interval
      inline l_interval()                              noexcept;
      //! Constructor of class l_interval
      inline l_interval(const l_interval &)            noexcept; 

      //! Constructor of class l_interval
      l_interval(const l_real &, const l_real &) noexcept(false);
      //! Constructor of class l_interval
      l_interval(const real &, const l_real &)   noexcept(false);
      //! Constructor of class l_interval
      l_interval(const l_real &, const real &)   noexcept(false);
      //! Constructor of class l_interval
      l_interval(const real &, const real &)     noexcept(false);

      //! Constructor of class l_interval
      explicit        l_interval(const dotprecision &) noexcept;
      //! Constructor of class l_interval
      explicit        l_interval(const dotprecision &,const dotprecision &) noexcept(false);
      //! Constructor of class l_interval
      explicit        l_interval(const idotprecision &) noexcept;
#endif 

      //! Constructor of class l_interval
      explicit inline l_interval(const real &) noexcept;
      //! Constructor of class l_interval
      explicit inline l_interval(const l_real &) noexcept;

#if(CXSC_INDEX_CHECK)
      //! Constructor of class l_interval
      explicit INLINE l_interval(const l_ivector &) noexcept(false);      
      //! Constructor of class l_interval
      explicit INLINE l_interval(const l_ivector_slice &) noexcept(false);      
      //! Constructor of class l_interval
      explicit INLINE l_interval(const l_imatrix &m) noexcept(false);
      //! Constructor of class l_interval
      explicit INLINE l_interval(const l_imatrix_slice &m) noexcept(false);
      //! Constructor of class l_interval
      friend INLINE interval _l_interval(const l_ivector &) noexcept(false);      
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend INLINE interval _l_interval(const l_ivector_slice &) noexcept(false);      
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend INLINE interval _l_interval(const l_imatrix &m) noexcept(false);
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend INLINE interval _l_interval(const l_imatrix_slice &m) noexcept(false);
#else
      //! Constructor of class l_interval
      explicit INLINE l_interval(const l_ivector &) noexcept;
      //! Constructor of class l_interval
      explicit INLINE l_interval(const l_ivector_slice &) noexcept;
      //! Constructor of class l_interval
      explicit INLINE l_interval(const l_imatrix &m) noexcept;
      //! Constructor of class l_interval
      explicit INLINE l_interval(const l_imatrix_slice &m) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend INLINE interval _l_interval(const l_ivector &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend INLINE interval _l_interval(const l_ivector_slice &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend INLINE interval _l_interval(const l_imatrix &m) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend INLINE interval _l_interval(const l_imatrix_slice &m) noexcept;
#endif



      //! Implementation of standard assigning operator
      inline l_interval & operator= (const real & a)    noexcept;
      //! Implementation of standard assigning operator
      inline l_interval & operator= (const l_real &a)  noexcept;
      //! Implementation of standard assigning operator
      inline l_interval & operator= (const interval & a)noexcept;
      //! Implementation of standard assigning operator
             l_interval & operator= (const l_interval &a)noexcept;
      //! Implementation of standard assigning operator
             l_interval& operator = (const lx_interval&) noexcept;
#if (CXSC_INDEX_CHECK)
      //! Implementation of standard assigning operator
             l_interval & operator= (const dotprecision &a) noexcept(false);
      //! Implementation of standard assigning operator
             l_interval & operator= (const idotprecision &) noexcept(false);
#else
      //! Implementation of standard assigning operator
             l_interval & operator= (const dotprecision &a) noexcept;
      //! Implementation of standard assigning operator
             l_interval & operator= (const idotprecision &) noexcept;
#endif             

      // ---- Destruktor    ----
      inline ~l_interval() noexcept;

      // ---- Typwandlungen ----
      //! Constructor of class l_interval
      explicit inline l_interval(const interval &) noexcept;

      friend        interval::interval(const l_interval &) noexcept;
      friend        interval _interval(const l_interval &) noexcept;
      friend interval & interval::operator =(const l_interval &) noexcept;
            
      friend inline interval _interval(const real &, const l_real &) noexcept; // Sollte in l_real!!!
      friend inline interval _interval(const l_real &, const real &) noexcept;
      friend inline interval _interval(const l_real &) noexcept;
      friend        interval _unchecked_interval(const l_real &, const l_real &) noexcept;

//      friend inline l_interval _l_interval(const real & a) noexcept { return l_interval(a); }
//      friend inline l_interval _l_interval(const real & a, const real & b) noexcept(false) { return l_interval(a,b); }
//      friend inline l_interval _l_interval(const l_real & a) noexcept { return l_interval(a); }
//      friend inline l_interval _l_interval(const l_real & a,const l_real & b) noexcept(false) { return l_interval(a,b); }
//      friend inline l_interval _l_interval(const real & a, const l_real & b) noexcept(false) { return l_interval(a,b); }
//      friend inline l_interval _l_interval(const l_real & a, const real & b) noexcept(false) { return l_interval(a,b); }

//      friend inline l_interval _l_interval(const interval & a) noexcept { return l_interval(a); }
//      friend inline l_interval _l_interval(const dotprecision & a) noexcept { return l_interval(a); }
//      friend inline l_interval _l_interval(const dotprecision & a,const dotprecision & b) noexcept(false) { return l_interval(a,b); }
//      friend inline l_interval _l_interval(const idotprecision & a) noexcept { return l_interval(a); }

      friend        l_interval _unchecked_l_interval(const l_real &, const l_real &) noexcept;      
      friend        idotprecision _idotprecision(const l_interval &) noexcept;
      friend        idotprecision::idotprecision(const l_interval &) noexcept;
      friend idotprecision & idotprecision::operator =(const l_interval &) noexcept;
      
      // ---- Ausgabefunkt. ---------------------------------------
      //! Implementation of standard input method
      friend std::istream& operator >> (std::istream& s, l_interval & a)       noexcept;
      //! Implementation of standard output method
      friend std::ostream& operator << (std::ostream& s, const l_interval & a) noexcept;
      //! Implementation of standard input method
      friend std::string & operator >> (std::string&  s, l_interval & a)       noexcept;
      //! Implementation of standard output method
      friend std::string & operator << (std::string&  s, const l_interval & a) noexcept;
      //! Implementation of standard input method
      friend void          operator >> (const std::string& s,l_interval &a)   noexcept;
      //! Implementation of standard input method
      friend void          operator >> (const char *       s,l_interval &a)   noexcept;      

      // ---- Standardfunkt ---- (arithmetische Operatoren)
      // LI
      //! Implementation of standard algebraic negative sign operation
      friend        l_interval operator -(const l_interval &) noexcept;
      //! Implementation of standard algebraic positive sign operation
      friend inline l_interval operator +(const l_interval &) noexcept;

      // LI-LI
      //! Implementation of standard algebraic addition operation
      friend l_interval operator +(const l_interval &,const l_interval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend l_interval operator -(const l_interval &,const l_interval &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend l_interval operator *(const l_interval &,const l_interval &) noexcept;
      //! Implementation of standard algebraic division operation
      friend l_interval operator /(const l_interval &,const l_interval &) noexcept(false);
      //! Returns the convex hull of the arguments
      friend inline l_interval operator |(const l_interval &,const l_interval &) noexcept(false);
      //! Returns the intersection of the arguments
      friend inline l_interval operator &(const l_interval &,const l_interval &) noexcept(false);

      //! Implementation of standard algebraic addition and allocation operation
      friend inline l_interval & operator +=(l_interval &,const l_interval &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline l_interval & operator -=(l_interval &,const l_interval &) noexcept;
      //! Implementation of standard algebraic multiplication and allocation operation
      friend inline l_interval & operator *=(l_interval &,const l_interval &) noexcept;
      //! Implementation of standard algebraic division and allocation operation
      friend inline l_interval & operator /=(l_interval &,const l_interval &) noexcept;
      //! Allocates the convex hull of the arguments to the first argument
      friend inline l_interval & operator |=(l_interval &,const l_interval &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline l_interval & operator &=(l_interval &,const l_interval &) noexcept(false);

      // LI-ID
      //! Implementation of standard algebraic addition operation
      friend inline idotprecision operator +(const l_interval &,const idotprecision &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline idotprecision operator +(const idotprecision &,const l_interval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline idotprecision operator -(const l_interval &,const idotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline idotprecision operator -(const idotprecision &,const l_interval &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline idotprecision operator |(const idotprecision &,const l_interval &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline idotprecision operator |(const l_interval &,const idotprecision &) noexcept;
      //! Returns the intersection of the arguments
      friend inline idotprecision operator &(const idotprecision &,const l_interval &) noexcept(false);
      //! Returns the intersection of the arguments
      friend inline idotprecision operator &(const l_interval &,const idotprecision &) noexcept(false);

      //! Allocates the convex hull of the arguments to the first argument
      friend inline l_interval & operator |=(l_interval &,const idotprecision &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline l_interval & operator &=(l_interval &,const idotprecision &) noexcept(false);
 
      // LI-LR
      //! Implementation of standard algebraic addition operation
      friend inline l_interval operator +(const l_interval &,const l_real &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline l_interval operator +(const l_real &,const l_interval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline l_interval operator -(const l_interval &,const l_real &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline l_interval operator -(const l_real &,const l_interval &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline l_interval operator *(const l_interval &,const l_real &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline l_interval operator *(const l_real &,const l_interval &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline l_interval operator /(const l_interval &,const l_real &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline l_interval operator /(const l_real &,const l_interval &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline l_interval operator |(const l_real &,const l_interval &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline l_interval operator |(const l_interval &,const l_real &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline l_interval operator |(const l_real &,const l_real &)     noexcept;
      //! Returns the intersection of the arguments
      friend inline l_interval operator &(const l_real &,const l_interval &) noexcept(false);
      //! Returns the intersection of the arguments
      friend inline l_interval operator &(const l_interval &,const l_real &) noexcept(false);

      //! Implementation of standard algebraic addition and allocation operation
      friend inline l_interval & operator +=(l_interval &,const l_real &) noexcept;      
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline l_interval & operator -=(l_interval &,const l_real &) noexcept;
      //! Implementation of standard algebraic multiplication and allocation operation
      friend inline l_interval & operator *=(l_interval &,const l_real &) noexcept;              
      //! Implementation of standard algebraic division and allocation operation
      friend inline l_interval & operator /=(l_interval &,const l_real &) noexcept; 
      //! Allocates the convex hull of the arguments to the first argument
      friend inline l_interval & operator |=(l_interval &,const l_real &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline l_interval & operator &=(l_interval &,const l_real &) noexcept(false);
 
      // LI-I
      //! Implementation of standard algebraic addition operation
      friend inline l_interval operator +(const l_interval &,const interval &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline l_interval operator +(const interval &,const l_interval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline l_interval operator -(const l_interval &,const interval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline l_interval operator -(const interval &,const l_interval &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline l_interval operator *(const l_interval &,const interval &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline l_interval operator *(const interval &,const l_interval &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline l_interval operator /(const l_interval &,const interval &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline l_interval operator /(const interval &,const l_interval &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline l_interval operator |(const interval &,const l_interval &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline l_interval operator |(const l_interval &,const interval &) noexcept;
      //! Returns the intersection of the arguments
      friend inline l_interval operator &(const interval &,const l_interval &) noexcept(false);
      //! Returns the intersection of the arguments
      friend inline l_interval operator &(const l_interval &,const interval &) noexcept(false);

      //! Implementation of standard algebraic addition and allocation operation
      friend inline l_interval & operator +=(l_interval &,const interval &) noexcept;      
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline l_interval & operator -=(l_interval &,const interval &) noexcept;
      //! Implementation of standard algebraic multiplication and allocation operation
      friend inline l_interval & operator *=(l_interval &,const interval &) noexcept;              
      //! Implementation of standard algebraic division and allocation operation
      friend inline l_interval & operator /=(l_interval &,const interval &) noexcept; 
      //! Allocates the convex hull of the arguments to the first argument
      friend inline l_interval & operator |=(l_interval &,const interval &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline l_interval & operator &=(l_interval &,const interval &) noexcept(false);
 
      // LI-R
      //! Implementation of standard algebraic addition operation
      friend inline l_interval operator +(const l_interval &,const real &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline l_interval operator +(const real &,const l_interval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline l_interval operator -(const l_interval &,const real &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline l_interval operator -(const real &,const l_interval &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline l_interval operator *(const l_interval &,const real &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline l_interval operator *(const real &,const l_interval &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline l_interval operator /(const l_interval &,const real &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline l_interval operator /(const real &,const l_interval &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline l_interval operator |(const real &,const l_interval &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline l_interval operator |(const l_interval &,const real &) noexcept;
      //! Returns the intersection of the arguments
      friend inline l_interval operator &(const real &,const l_interval &) noexcept(false);
      //! Returns the intersection of the arguments
      friend inline l_interval operator &(const l_interval &,const real &) noexcept(false);

      //! Implementation of standard algebraic addition and allocation operation
      friend inline l_interval & operator +=(l_interval &,const real &) noexcept;      
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline l_interval & operator -=(l_interval &,const real &) noexcept;
      //! Implementation of standard algebraic multiplication and allocation operation
      friend inline l_interval & operator *=(l_interval &,const real &) noexcept;              
      //! Implementation of standard algebraic division and allocation operation
      friend inline l_interval & operator /=(l_interval &,const real &) noexcept; 
      //! Allocates the convex hull of the arguments to the first argument
      friend inline l_interval & operator |=(l_interval &,const real &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline l_interval & operator &=(l_interval &,const real &) noexcept(false);

      // LR-I
      //! Implementation of standard algebraic addition operation
      friend inline l_interval operator +(const l_real &,const interval &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline l_interval operator +(const interval &,const l_real &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline l_interval operator -(const l_real &,const interval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline l_interval operator -(const interval &,const l_real &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline l_interval operator *(const l_real &,const interval &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline l_interval operator *(const interval &,const l_real &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline l_interval operator /(const l_real &,const interval &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline l_interval operator /(const interval &,const l_real &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline l_interval operator |(const interval &,const l_real &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline l_interval operator |(const l_real &,const interval &) noexcept;
      //! Returns the intersection of the arguments
      friend inline l_interval operator &(const interval &,const l_real &) noexcept(false);
      //! Returns the intersection of the arguments
      friend inline l_interval operator &(const l_real &,const interval &) noexcept(false);
 
      // ---- Vergleichsop. ----
      //! Implementation of standard negation operation
      friend        bool operator !(const l_interval &) noexcept;
//                         operator void *(void) noexcept;

      //! Implementation of standard equality operation
      friend        bool operator ==(const l_interval &,const l_interval &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const l_interval &,const l_interval &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const l_real &,const l_interval &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const l_real &,const l_interval &) noexcept;
      //! Implementation of standard equality operation
      friend inline bool operator ==(const l_interval &,const l_real &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const l_interval &,const l_real &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const interval &,const l_interval &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const interval &,const l_interval &) noexcept;
      //! Implementation of standard equality operation
      friend inline bool operator ==(const l_interval &,const interval &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const l_interval &,const interval &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const real &,const l_interval &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const real &,const l_interval &) noexcept;
      //! Implementation of standard equality operation
      friend inline bool operator ==(const l_interval &,const real &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const l_interval &,const real &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const idotprecision &,const l_interval &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const idotprecision &,const l_interval &) noexcept;
      //! Implementation of standard equality operation
      friend inline bool operator ==(const l_interval &,const idotprecision &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const l_interval &,const idotprecision &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const dotprecision &,const l_interval &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const dotprecision &,const l_interval &) noexcept;
      //! Implementation of standard equality operation
      friend inline bool operator ==(const l_interval &,const dotprecision &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const l_interval &,const dotprecision &) noexcept;
   
      // ---- Mengenvergle. ----
      //! Implementation of standard less-than operation
      friend        bool operator  <(const l_interval &,const l_interval &) noexcept;
      //! Implementation of standard greater-than operation
      friend        bool operator  >(const l_interval &,const l_interval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend        bool operator <=(const l_interval &,const l_interval &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend        bool operator >=(const l_interval &,const l_interval &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const l_real &,const l_interval &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const l_real &,const l_interval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const l_real &,const l_interval &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const l_real &,const l_interval &) noexcept;
      //! Implementation of standard less-than operation
      friend inline bool operator  <(const l_interval &,const l_real &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const l_interval &,const l_real &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const l_interval &,const l_real &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const l_interval &,const l_real &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const interval &,const l_interval &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const interval &,const l_interval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const interval &,const l_interval &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const interval &,const l_interval &) noexcept;
      //! Implementation of standard less-than operation
      friend inline bool operator  <(const l_interval &,const interval &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const l_interval &,const interval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const l_interval &,const interval &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const l_interval &,const interval &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const real &,const l_interval &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const real &,const l_interval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const real &,const l_interval &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const real &,const l_interval &) noexcept;
      //! Implementation of standard less-than operation
      friend inline bool operator  <(const l_interval &,const real &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const l_interval &,const real &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const l_interval &,const real &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const l_interval &,const real &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const idotprecision &,const l_interval &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const idotprecision &,const l_interval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const idotprecision &,const l_interval &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const idotprecision &,const l_interval &) noexcept;
      //! Implementation of standard less-than operation
      friend inline bool operator  <(const l_interval &,const idotprecision &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const l_interval &,const idotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const l_interval &,const idotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const l_interval &,const idotprecision &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const dotprecision &,const l_interval &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const dotprecision &,const l_interval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const dotprecision &,const l_interval &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const dotprecision &,const l_interval &) noexcept;
      //! Implementation of standard less-than operation
      friend inline bool operator  <(const l_interval &,const dotprecision &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const l_interval &,const dotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const l_interval &,const dotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const l_interval &,const dotprecision &) noexcept;

      // ---- Funktionen    ----
      
//      friend inline l_interval_Inf Inf (l_interval &)  noexcept;
//      friend inline l_interval_Sup Sup (l_interval &)  noexcept;
      //! Returns the infimum of an interval
      friend inline l_real         Inf (const l_interval &) noexcept;
      //! Returns the supremum of an interval
      friend inline l_real         Sup (const l_interval &) noexcept;

      //! Returns the minimum of the expo-function
      friend inline int expo_sm(const l_interval&);
      // Calculating expo(x[k]) of the smallest |x[k]|<>0.

      //! Returns the maximum of the expo-function
      friend inline int expo_gr(const l_interval&);
      // Calculating expo(x[k]) of the greatest |x[k]|.
      
      //! Returns the precision of the long datatype value
      friend inline int StagPrec(const l_interval &) noexcept;

      //! Returns the interval with the new given infimum value
      friend inline l_interval & SetInf (l_interval & a, const l_real & b)  noexcept(false);
      //! Returns the interval with the new given supremum value
      friend inline l_interval & SetSup (l_interval & a, const l_real & b) noexcept(false);
      //! Returns the interval with the new given infimum value
      friend inline l_interval & SetInf (l_interval & a, const real & b)  noexcept(false);
      //! Returns the interval with the new given supremum value
      friend inline l_interval & SetSup (l_interval & a, const real & b) noexcept(false);
      //! Sets the precision of a specific long datatype value
      friend inline l_interval  adjust (const l_interval &) noexcept;         

      //! Returns the interval with the unchecked new given infimum value
      friend inline l_interval & UncheckedSetInf (l_interval & a, const l_real & b) noexcept;
      //! Returns the interval with the unchecked new given supremum value
      friend inline l_interval & UncheckedSetSup (l_interval & a, const l_real & b) noexcept;
      //! Returns the interval with the unchecked new given infimum value
      friend inline l_interval & UncheckedSetInf (l_interval & a, const real & b) noexcept;
      //! Returns the interval with the unchecked new given supremum value
      friend inline l_interval & UncheckedSetSup (l_interval & a, const real & b) noexcept;
      
      //! Allocates the convex hull of the arguments to the first argument
      friend void ConvexHull(const l_interval &, const l_interval &, l_interval &, l_interval &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend void Intersection(const l_interval &, const l_interval &, l_interval &, l_interval &) noexcept(false);
   
      //! Returns the absolute value of the interval
      friend inline l_interval abs  (const l_interval & a) noexcept;
      //! Returns the rounded middle of the interval
      friend        l_real     mid  (const l_interval & a) noexcept;
      //! Returns the rounded diameter of the interval
      friend inline l_real     diam (const l_interval & a) noexcept;

      //! Calculates \f$ [x]^{[y]} \f$
      friend l_interval pow(const l_interval &, const l_interval &) noexcept(false); // Pow(x,y)
      //! Calculates \f$ [x]^n \f$
      friend l_interval power(const l_interval &, int);       // Power(x,n)
      //! Calculates \f$ [x]^2  \f$
      friend l_interval sqr(const l_interval &);              // Sqr(x)

      //! Calculates \f$ \sqrt{[x]}  \f$
      friend l_interval sqrt(const l_interval &) noexcept(false);             // Sqrt(x)
      //! Calculates \f$ \sqrt[n]{[x]} \f$
      friend l_interval sqrt(const l_interval &, int) noexcept(false);        // NSqrt(n,x)

      //! Calculates \f$ \sin([x]) \f$
      friend l_interval sin(const l_interval &) noexcept(false);    // Sin(x)
      //! Calculates \f$ \cos([x]) \f$
      friend l_interval cos(const l_interval &) noexcept(false);    // Cos(x)
      //! Calculates \f$ \tan([x]) \f$
      friend l_interval tan(const l_interval &) noexcept(false);    // Tan(x)
      //! Calculates \f$ \cot([x]) \f$
      friend l_interval cot(const l_interval &) noexcept(false);    // Cot(x)

      //! Calculates \f$ \arcsin([x]) \f$
      friend l_interval asin(const l_interval &) noexcept(false);   // ASin(x)
      //! Calculates \f$ \arccos([x]) \f$
      friend l_interval acos(const l_interval &) noexcept(false);   // ACos(x)
      //! Calculates \f$ \arctan([x]) \f$
      friend l_interval atan(const l_interval &) noexcept;   // ATan(x)
      //! Calculates \f$ \mbox{arccot}([x]) \f$
      friend l_interval acot(const l_interval &) noexcept;   // ACot(x)

      //! Calculates \f$ \exp([x]) \f$
      friend l_interval exp(const l_interval &) noexcept(false);    // Exp(x)
      //! Calculates \f$ \exp2([x]) \f$
      friend l_interval exp2(const l_interval &); // 2^x
      //! Calculates \f$ \exp10([x]) \f$
      friend l_interval exp10(const l_interval &); // 10^x		 
      //! Calculates \f$ \ln([x]) \f$
      friend l_interval ln(const l_interval &) noexcept(false);     // Ln(x)
      //! Calculates \f$ \log2([x]) \f$
      friend l_interval log2(const l_interval &);
      //! Calculates \f$ \log10([x]) \f$
      friend l_interval log10(const l_interval &);
      //! Calculates \f$ \sinh([x]) \f$
      friend l_interval sinh(const l_interval &) noexcept(false);   // Sinh(x)
      //! Calculates \f$ \cosh([x]) \f$
      friend l_interval cosh(const l_interval &) noexcept(false);   // Cosh(x)
      //! Calculates \f$ \tanh([x]) \f$
      friend l_interval tanh(const l_interval &) noexcept;   // Tanh(x)
      //! Calculates \f$ \coth([x]) \f$
      friend l_interval coth(const l_interval &) noexcept;   // Coth(x)           
 
      //! Calculates \f$ \mbox{arcsinh}([x]) \f$
      friend l_interval asinh(const l_interval &) noexcept(false);  // ASinh(x)
      //! Calculates \f$ \mbox{arccosh}([x]) \f$
      friend l_interval acosh(const l_interval &) noexcept;  // ACosh(x)
      //! Calculates \f$ \mbox{arctanh}([x]) \f$
      friend l_interval atanh(const l_interval &) noexcept(false);  // ATanh(x)
      //! Calculates \f$ \mbox{arccoth}([x]) \f$
      friend l_interval acoth(const l_interval &) noexcept(false);  // ACoth(x)

      //! Enclosure-Interval for \f$ \ln 2 \f$
      friend l_interval Ln2_l_interval() noexcept;     // ln(2)
      //! Enclosure-Interval for \f$ \ln 10 \f$
      friend l_interval Ln10_l_interval() noexcept;  // ln(10)
      //! Enclosure-Interval for \f$ \frac{1}{\ln 10} \f$
      friend l_interval Ln10r_l_interval() noexcept; // 1/ln(10)
      //! Enclosure-Interval for \f$ \frac{\pi}{4} \f$
      friend l_interval Pid4_l_interval() noexcept;  // Pi/4
      //! Enclosure-Interval for \f$ \sqrt{2} \f$
      friend l_interval Sqrt2_l_interval() noexcept; // sqrt(2)
      //! Enclosure-Interval for \f$ \sqrt{5} \f$
      friend l_interval Sqrt5_l_interval() noexcept; // sqrt(5)
      //! Enclosure-Interval for \f$ \sqrt{7} \f$
      friend l_interval Sqrt7_l_interval() noexcept; // sqrt(7)
		
      // obsolete, see also l_imath.hpp and l_imath.cpp
      //! Enclosure-Interval for \f$ \ln 2 \f$
      friend inline l_interval li_ln2();   // ln(2) 
      //! Enclosure-Interval for \f$ \ln 10 \f$
      friend inline l_interval li_ln10();  // ln(10)
      //! Enclosure-Interval for \f$ \frac{1}{\ln 10} \f$
      friend inline l_interval li_Rln10(); // 1/ln(10)
      //! Enclosure-Interval for \f$ \frac{\pi}{4} \f$
      friend inline l_interval li_pi4();   // Pi/4
      //! Enclosure-Interval for \f$ \sqrt{2} \f$
      friend inline l_interval li_sqrt2(); // sqrt(2)

      //! Enclosure-Interval for \f$ \frac{1}{\ln 2} \f$
      friend l_interval Ln2r_l_interval() noexcept;     // 1/ln(2)
      //! Enclosure-Interval for \f$ \pi \f$
      friend l_interval Pi_l_interval() noexcept;       // Pi
      //! Enclosure-Interval for \f$ \frac{\pi}{2} \f$
      friend l_interval Pid2_l_interval() noexcept;     // Pi/2
      //! Enclosure-Interval for \f$ 2\pi \f$
      friend l_interval Pi2_l_interval() noexcept;      // 2*Pi
      //! Enclosure-Interval for \f$ \frac{\pi}{3} \f$
      friend l_interval Pid3_l_interval() noexcept;     // Pi/3
      //! Enclosure-Interval for \f$ \frac{1}{\pi} \f$
      friend l_interval Pir_l_interval() noexcept;      // 1/Pi
      //! Enclosure-Interval for \f$ \frac{1}{2\pi} \f$
      friend l_interval Pi2r_l_interval() noexcept;     // 1/(2*Pi)
      //! Enclosure-Interval for \f$ \sqrt{\pi} \f$
      friend l_interval SqrtPi_l_interval() noexcept;   // sqrt(Pi)
      //! Enclosure-Interval for \f$ \sqrt{2\pi} \f$
      friend l_interval Sqrt2Pi_l_interval() noexcept;  // sqrt(2*Pi)
      //! Enclosure-Interval for \f$ \frac{1}{\sqrt{\pi}} \f$
      friend l_interval SqrtPir_l_interval() noexcept;  // 1/sqrt(Pi)
      //! Enclosure-Interval for \f$ \frac{1}{\sqrt{2\pi}} \f$
      friend l_interval Sqrt2Pir_l_interval() noexcept; // 1/sqrt(2*Pi)
      //! Enclosure-Interval for \f$ 2^\pi \f$
      friend l_interval Pip2_l_interval() noexcept;     // Pi^2
      //! Enclosure-Interval for \f$ \frac{1}{\sqrt{2}} \f$
      friend l_interval Sqrt2r_l_interval() noexcept;   // 1/sqrt(2)
      //! Enclosure-Interval for \f$ \sqrt{3} \f$
      friend l_interval Sqrt3_l_interval() noexcept;    // sqrt(3)
      //! Enclosure-Interval for \f$ \frac{\sqrt{3}}{2} \f$
      friend l_interval Sqrt3d2_l_interval() noexcept;  // sqrt(3)/2
      //! Enclosure-Interval for \f$ \frac{1}{\sqrt{3}} \f$
      friend l_interval Sqrt3r_l_interval() noexcept;   // 1/sqrt(3)
      //! Enclosure-Interval for \f$ \ln \pi \f$
      friend l_interval LnPi_l_interval() noexcept;     // ln(Pi)
      //! Enclosure-Interval for \f$ \ln 2\pi \f$
      friend l_interval Ln2Pi_l_interval() noexcept;    // ln(2*Pi)
      //! Enclosure-Interval for \f$ e \f$
      friend l_interval E_l_interval() noexcept;        // e = exp(1)
      //! Enclosure-Interval for \f$ \frac{1}{e} \f$
      friend l_interval Er_l_interval() noexcept;       // 1/e
      //! Enclosure-Interval for \f$ e^2 \f$
      friend l_interval Ep2_l_interval() noexcept;      // e^2
      //! Enclosure-Interval for \f$ \frac{1}{e^2} \f$
      friend l_interval Ep2r_l_interval() noexcept;     // 1/e^2
      //! Enclosure-Interval for \f$ e^\pi \f$
      friend l_interval EpPi_l_interval() noexcept;     // e^Pi
      //! Enclosure-Interval for \f$ e^{2\pi} \f$
      friend l_interval Ep2Pi_l_interval() noexcept;    // e^(2*Pi)
      //! Enclosure-Interval for \f$ e^{\frac{\pi}{2}} \f$
      friend l_interval EpPid2_l_interval() noexcept;   // e^(Pi/2)
      //! Enclosure-Interval for \f$ e^{\frac{\pi}{4}} \f$
      friend l_interval EpPid4_l_interval() noexcept;   // e^(Pi/4)
      //! Enclosure-Interval for Euler Gamma
      friend l_interval EulerGa_l_interval() noexcept;  // EulerGamma
      //! Enclosure-Interval for Catalan Numbers
      friend l_interval Catalan_l_interval() noexcept;  // Catalan

      // Operatoren: l/real op idotprecision
      //      
      // friend inline void accumulate(idotprecision &, const real &, const l_real &) noexcept;
      // friend inline void accumulate(idotprecision &, const l_real &, const real &) noexcept;

      // Operatoren: l_real op idotprecision
      //
      // friend inline void accumulate(idotprecision &, const l_real &, const l_real &) noexcept;

      // Operatoren: real, l_interval op idotprecision
      //
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate(idotprecision &, const real &, const l_interval &) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate(idotprecision &, const l_interval &, const real &) noexcept;

      // Operatoren: interval, l_real op idotprecision
      //
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate(idotprecision &, const interval &, const l_real &) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate(idotprecision &, const l_real &, const interval &) noexcept;    

      // Operatoren: l_interval, l_real op idotprecision
      //
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate(idotprecision &, const l_interval &, const l_real &) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate(idotprecision &, const l_real &, const l_interval &) noexcept;

      // Operatoren: l_interval, interval op idotprecision
      //
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate(idotprecision &, const l_interval &, const interval &) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate(idotprecision &, const interval &, const l_interval &) noexcept;

      // Operatoren: l_interval op idotprecision
      //
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend void accumulate(idotprecision &, const l_interval &, const l_interval &) noexcept;

      //! Checks if the argument is a point interval
      friend inline bool point_intv(const l_interval &);  // bool delivers: a is a point interval;
      //! Checks if the argument is zero
      friend inline bool zero_(const l_interval& ) noexcept; // Blomquist,27.11.02
      //! Multiplication of interval with \f$ 2^n \f$
      friend void times2pown(l_interval&, int) noexcept;    // Blomquist,28.11.02
      //! Multiplication of interval with \f$ 2^n \f$
      friend void Times2pown(l_interval&, const real&) noexcept;
      friend void l_realz2l_interval(const l_real&, const interval&,
			       l_interval&) noexcept; // Blomquist,28.11.02
      
#if (CXSC_INDEX_CHECK)
      //! Access to the single components used to store the long data type value
      inline real & operator [](int) noexcept(false);
#else
      //! Access to the single components used to store the long data type value
      inline real & operator [](int) noexcept;
#endif
            
   private:
#if (CXSC_INDEX_CHECK)
      inline void _allo(int) noexcept(false);
#else
      inline void _allo(int) noexcept;
#endif
      inline void _clear(int) noexcept;
      void _akku_out(idotprecision&) noexcept;
      void _akku_out_inn(idotprecision&) noexcept;
      void _akku_add(idotprecision &) const noexcept;
      void _akku_sub(idotprecision &) const noexcept;
      //void _create_l_interval(l_real &, l_real &);
      inline real & elem(int i)       { return data[i-1]; }
      inline real   elem(int i) const { return data[i-1]; }
             
};

interval _unchecked_interval(const l_real &, const l_real &) noexcept;

/*!
\deprecated use standard contructors for typecasting

\sa cxsc::l_interval::l_interval(const real &)
*/
inline l_interval _l_interval(const real & a) noexcept { return l_interval(a); }
/*!
\deprecated use standard contructors for typecasting

\sa cxsc::l_interval::l_interval(const real &, const real &) 
*/
inline l_interval _l_interval(const real & a, const real & b) noexcept(false) { return l_interval(a,b); }
/*!
\deprecated use standard contructors for typecasting

\sa cxsc::l_interval::l_interval(const l_real &)
*/
inline l_interval _l_interval(const l_real & a) noexcept { return l_interval(a); }
/*!
\deprecated use standard contructors for typecasting

\sa cxsc::l_interval::l_interval(const l_real &, const l_real &)
*/
inline l_interval _l_interval(const l_real & a,const l_real & b) noexcept(false) { return l_interval(a,b); }
/*!
\deprecated use standard contructors for typecasting

\sa cxsc::l_interval::l_interval(const real &, const l_real &)
*/
inline l_interval _l_interval(const real & a, const l_real & b) noexcept(false) { return l_interval(a,b); }
/*!
\deprecated use standard contructors for typecasting

\sa cxsc::l_interval::l_interval(const l_real &, const real &)
*/
inline l_interval _l_interval(const l_real & a, const real & b) noexcept(false) { return l_interval(a,b); }

/*!
\deprecated use standard contructors for typecasting

\sa cxsc::l_interval::l_interval(const interval &)
*/
inline l_interval _l_interval(const interval & a) noexcept { return l_interval(a); }
/*!
\deprecated use standard contructors for typecasting

\sa cxsc::l_interval::l_interval(const dotprecision &)
*/
inline l_interval _l_interval(const dotprecision & a) noexcept { return l_interval(a); }
/*!
\deprecated use standard contructors for typecasting

\sa cxsc::l_interval::l_interval(const dotprecision &,const dotprecision &)
*/
inline l_interval _l_interval(const dotprecision & a,const dotprecision & b) noexcept(false) { return l_interval(a,b); }
/*!
\deprecated use standard contructors for typecasting

\sa cxsc::l_interval::l_interval(const idotprecision &)
*/
inline l_interval _l_interval(const idotprecision & a) noexcept { return l_interval(a); }
l_interval _unchecked_l_interval(const l_real &, const l_real &) noexcept;      
 
//inline l_interval_Inf Inf (l_interval &)  noexcept;
//inline l_interval_Sup Sup (l_interval &)  noexcept;
inline l_real         Inf (const l_interval &) noexcept;
inline l_real         Sup (const l_interval &) noexcept;

int in ( const real& x, const l_interval& y );        // Contained-in relation
int in ( const l_real& x, const l_interval& y );      // Contained-in relation
int in ( const interval& x, const l_interval& y );    // Contained-in relation
int in ( const l_interval& x, const l_interval& y );  // Contained-in relation
l_interval Blow (const l_interval& x, const real& eps );
int Disjoint (const l_interval& a, const l_interval& b ); // Test for disjointedness
l_real AbsMin ( const l_interval& x );           // Absolute minimum of
                                                 // an interval
l_real AbsMax (const l_interval& x );            // Absolute maximum of
                                                 // an interval
l_real RelDiam ( const l_interval x );           // Relative diameter
                                                 // of an interval
inline bool point_intv(const l_interval &a );  // bool delivers: a is a point interval;

void times2pown(l_interval&, int) noexcept;    // Blomquist,28.11.02
void Times2pown(l_interval&, const real&) noexcept;

//! The Multiple-Precision Data Type l_interval_Inf
/*!

*/
class l_interval_Inf
{
   private:
      l_interval & my_l_interval;
   public:
      // l_interval_Inf(const l_interval_Inf &a) noexcept : my_l_interval(a.my_l_interval) {}
      //! Constructor of class l_interval_Inf
      l_interval_Inf(l_interval &a) noexcept : my_l_interval(a) {}
                   operator l_real(void) const { return Inf((const l_interval)my_l_interval); }  
      //! Implementation of standard assigning operator
      l_interval & operator =(const l_real & a) noexcept(false)  { SetInf(my_l_interval,a); return my_l_interval; }
      //! Implementation of standard assigning operator
      l_interval & operator =(const real & a) noexcept(false)    { SetInf(my_l_interval,_l_real(a)); return my_l_interval; }
      // l_interval & operator =(int a) noexcept(false)             { SetInf(my_l_interval,_l_real(a)); return my_l_interval; }
};
//! The Multiple-Precision Data Type l_interval_Sup
/*!

*/
class l_interval_Sup
{
   private:
      l_interval & my_l_interval;
   public:
      //! Constructor of class l_interval_Sup
      l_interval_Sup(l_interval &a) noexcept : my_l_interval(a) {}
                   operator l_real(void) const { return Sup((const l_interval)my_l_interval); }
      //! Implementation of standard assigning operator
      l_interval & operator =(const l_real & a) noexcept(false)  { SetSup(my_l_interval,a); return my_l_interval; }
      //! Implementation of standard assigning operator
      l_interval & operator =(const real & a) noexcept(false)    { SetSup(my_l_interval,_l_real(a)); return my_l_interval; }
      // l_interval & operator =(int a) noexcept(false)             { SetSup(my_l_interval,_l_real(a)); return my_l_interval; }    
};

} // namespace cxsc 

#include "l_interval.inl"

#endif // _CXSC_L_INTERVAL_HPP_INCLUDED
