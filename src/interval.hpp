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

/* CVS $Id: interval.hpp,v 1.48 2014/01/30 18:13:52 cxsc Exp $ */

#ifndef _CXSC_INTERVAL_H_INCLUDED
#define _CXSC_INTERVAL_H_INCLUDED

#include <iostream>
#include <string>
#include "real.hpp"
#include "except.hpp"

namespace cxsc {

class ivector;
class ivector_slice;
class imatrix;
class imatrix_slice;


//!The Scalar Type interval
/*!
The data type interval is used to represent intervals over the real floating-point numbers:

\f[
\left[ a \right] = \left[ \underline a , \overline a \right] := \left\{ x \in R | \underline a \le x \le \overline a \right\} \in R
\f]

i.e. \f$ \left[ a \right]\f$ represents the set of all real numbers enclosed within the bounds \f$ \underline a , \overline a \in R \f$ .

The notation \f$ \underline a \f$ denotes the lower bound (infimum), and \f$ \overline a \f$ denotes the upper bound (supremum) of the interval \f$ \left[ a \right]\f$. 
*/
class interval
{
   private:
      // ---- Datenelemente ---------------------------------------
      real inf;
      real sup;

   public:
      // ---- Konstruktoren ---------------------------------------
      //! Constructor of class interval
      interval() {}
      //! Constructor of class interval
      inline interval(const real&, const real&) noexcept(false);
      //! Implementation of standard assigning operator
      inline interval& operator= (const real& a);

      // ---- Typecasts     ---------------------------------------
      
      //! Typecast for converting a real value in an interval
      explicit inline interval(const real &r) noexcept :inf(r),sup(r) { }
      
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline interval _unchecked_interval(const real&, const real&);

#if(CXSC_INDEX_CHECK)
      //! Constructor of class interval
      explicit INLINE interval(const ivector &) noexcept(false);
      //! Constructor of class interval
      explicit INLINE interval(const ivector_slice &) noexcept(false);
      //! Constructor of class interval
      explicit INLINE interval(const imatrix &m) noexcept(false);
      //! Constructor of class interval
      explicit INLINE interval(const imatrix_slice &m) noexcept(false);
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend INLINE interval _interval(const ivector &) noexcept(false);
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend INLINE interval _interval(const ivector_slice &) noexcept(false);
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend INLINE interval _interval(const imatrix &m) noexcept(false);
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend INLINE interval _interval(const imatrix_slice &m) noexcept(false);
#else
      //! Constructor of class interval
      explicit INLINE interval(const ivector &) noexcept;
      //! Constructor of class interval
      explicit INLINE interval(const ivector_slice &) noexcept;
      //! Constructor of class interval
      explicit INLINE interval(const imatrix &m) noexcept;
      //! Constructor of class interval
      explicit INLINE interval(const imatrix_slice &m) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend INLINE interval _interval(const ivector &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend INLINE interval _interval(const ivector_slice &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend INLINE interval _interval(const imatrix &m) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend INLINE interval _interval(const imatrix_slice &m) noexcept;
#endif
      //! Constructor of class interval
      explicit        interval(const l_real &) noexcept;     // in l_real.cpp
      //! Constructor of class interval
                      interval(const l_real &,const l_real &) noexcept(false);
      //! Constructor of class interval
      explicit        interval(const l_interval &) noexcept; // in l_interval.cpp
      //! Constructor of class interval
      explicit        interval(const dotprecision &) noexcept;
      //! Constructor of class interval
                      interval(const dotprecision &,const dotprecision &) noexcept(false);
      //! Constructor of class interval
      explicit        interval(const idotprecision &) noexcept;
      
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline interval _interval(const l_real &a) noexcept; // in l_interval.inl
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline interval _interval(const l_real &a,const l_real &b) noexcept(false) { return interval(a,b); }
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend        interval _interval(const l_interval &a) noexcept; // in l_interv.inl
//      friend inline interval _interval(const dotprecision &a) noexcept { return interval(a); } 
//      friend inline interval _interval(const dotprecision &a,const dotprecision &b) noexcept(false) { return interval(a,b); }
//      friend inline interval _interval(const idotprecision &a) noexcept { return interval(a); }
      
      // interval & operator= (const interval& a); Default passt
      //! Implementation of standard assigning operator
      interval & operator =(const l_real &) noexcept;
      //! Implementation of standard assigning operator
      interval & operator =(const l_interval &) noexcept;
      //! Implementation of standard assigning operator
      interval & operator = (const lx_interval &) noexcept;
      //! Implementation of standard assigning operator
      interval & operator =(const dotprecision &) noexcept;
      //! Implementation of standard assigning operator
      interval & operator =(const idotprecision &) noexcept;

      // ---- Destruktor    ----
      // ~interval() {} unnoetig

      // ---- Typwandlungen ----
      
      // ---- Ausgabefunkt. ---------------------------------------
      //! Implementation of standard input method
      friend std::istream& operator >> (std::istream &, interval &)       noexcept;
      //! Implementation of standard output method
      friend std::ostream& operator << (std::ostream &, const interval &) noexcept;
      //! Implementation of standard input method
      friend std::string & operator >> (std::string &, interval &)       noexcept;
      //! Implementation of standard output method
      friend std::string & operator << (std::string &, const interval &) noexcept;	  
      //! Implementation of standard input method
      friend void          operator >> (const std::string&,interval &)   noexcept;
      //! Implementation of standard input method
      friend void          operator >> (const char *,interval &)   noexcept;      

      // ---- Standardfunkt ---- (arithmetische Operatoren)
      //! Implementation of standard algebraic negative sign operation
      friend     inline interval operator -(const interval &) noexcept;
      //! Implementation of standard algebraic positive sign operation
      friend     inline interval operator +(const interval &) noexcept;

      //! Implementation of standard algebraic addition operation
      friend     inline interval operator +(const interval &,const interval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend     inline interval operator -(const interval &,const interval &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend     inline interval operator *(const interval &,const interval &) noexcept;
      //! Implementation of standard algebraic division operation
      friend     inline interval operator /(const interval &,const interval &) noexcept(false);
      //! Returns the convex hull of the arguments
      friend     inline interval operator |(const interval &,const interval &) noexcept;
      //! Returns the intersection of the arguments
      friend     inline interval operator &(const interval &,const interval &) noexcept(false);

      //! Implementation of standard algebraic addition operation
      friend     inline interval operator +(const interval &,const real &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend     inline interval operator +(const real &,const interval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend     inline interval operator -(const interval &,const real &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend     inline interval operator -(const real &,const interval &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend     inline interval operator *(const interval &,const real &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend     inline interval operator *(const real &,const interval &) noexcept;
      //! Implementation of standard algebraic division operation
      friend     inline interval operator /(const interval &,const real &) noexcept;
      //! Implementation of standard algebraic division operation
      friend     inline interval operator /(const real &,const interval &) noexcept;
      //! Returns the convex hull of the arguments
      friend     inline interval operator |(const real &,const interval &) noexcept;
      //! Returns the convex hull of the arguments
      friend     inline interval operator |(const interval &,const real &) noexcept;
      //! Returns the convex hull of the arguments
      friend     inline interval operator |(const real &,const real &)     noexcept;
      //! Returns the intersection of the arguments
      friend     inline interval operator &(const real &,const interval &) noexcept(false);
      //! Returns the intersection of the arguments
      friend     inline interval operator &(const interval &,const real &) noexcept(false);


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
      friend     inline interval & operator +=(interval &,const interval &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend     inline interval & operator -=(interval &,const interval &) noexcept;
      //! Implementation of standard algebraic multiplication and allocation operation
      friend     inline interval & operator *=(interval &,const interval &) noexcept;
      //! Implementation of standard algebraic division and allocation operation
      friend     inline interval & operator /=(interval &,const interval &) noexcept;
      //! Allocates the convex hull of the arguments to the first argument
      friend     inline interval & operator |=(interval &,const interval &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend     inline interval & operator &=(interval &,const interval &) noexcept(false);

      //! Implementation of standard algebraic addition and allocation operation
      friend     inline interval & operator +=(interval &,const real &) noexcept;   
      //! Implementation of standard algebraic subtraction and allocation operation   
      friend     inline interval & operator -=(interval &,const real &) noexcept;
      //! Implementation of standard algebraic multiplication and allocation operation
      friend     inline interval & operator *=(interval &,const real &) noexcept;
      //! Implementation of standard algebraic division and allocation operation
      friend     inline interval & operator /=(interval &,const real &) noexcept;
      //! Allocates the convex hull of the arguments to the first argument
      friend     inline interval & operator |=(interval &,const real &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend     inline interval & operator &=(interval &,const real &) noexcept(false);
 
      // ---- Vergleichsop. ----

      //! Implementation of standard equality operation
      friend inline bool operator ==(const interval &,const interval &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const interval &,const interval &) noexcept;

      //! Implementation of standard negation operation
      friend inline bool operator !(const interval &) noexcept;
//             inline      operator void*(void) const noexcept { return (void*)(!(!*this)); } 

      //! Implementation of standard equality operation
      friend inline bool operator ==(const real &,const interval &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const real &,const interval &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const interval &,const real &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const interval &,const real &) noexcept;

      //! Implementation of standard equality operation
      friend        bool operator ==(const dotprecision &,const interval &) noexcept;
      //! Implementation of standard negated equality operation
      friend        bool operator !=(const dotprecision &,const interval &) noexcept;

      //! Implementation of standard equality operation
      friend        bool operator ==(const interval &,const dotprecision &) noexcept;
      //! Implementation of standard negated equality operation
      friend        bool operator !=(const interval &,const dotprecision &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const int &,const interval &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const int &,const interval &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const interval &,const int &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const interval &,const int &) noexcept;
 
      //! Implementation of standard equality operation
      friend inline bool operator ==(const long &,const interval &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const long &,const interval &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const interval &,const long &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const interval &,const long &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const double &,const interval &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const double &,const interval &) noexcept;

      //! Implementation of standard equality operation
      friend inline bool operator ==(const interval &,const double &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const interval &,const double &) noexcept;

      // ---- Mengenvergle. ----

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const interval &,const interval &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const interval &,const interval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const interval &,const interval &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const interval &,const interval &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const real &,const interval &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const real &,const interval &) noexcept { return false; }
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const real &,const interval &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const real &,const interval &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const interval &,const real &) noexcept { return false; }
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const interval &,const real &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const interval &,const real &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const interval &,const real &) noexcept;

      //! Implementation of standard less-than operation
      friend        bool operator  <(const dotprecision &,const interval &) noexcept;
      //! Implementation of standard greater-than operation
      friend        bool operator  >(const dotprecision &,const interval &) noexcept { return false; }
      //! Implementation of standard less-or-equal-than operation
      friend        bool operator <=(const dotprecision &,const interval &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend        bool operator >=(const dotprecision &,const interval &) noexcept;

      //! Implementation of standard less-than operation
      friend        bool operator  <(const interval &,const dotprecision &) noexcept { return false; }
      //! Implementation of standard greater-than operation
      friend        bool operator  >(const interval &,const dotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend        bool operator <=(const interval &,const dotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend        bool operator >=(const interval &,const dotprecision &) noexcept;

      // ---- Funktionen    ----
      
      //! Returns the infimum of an interval
      friend inline       real & Inf (interval &)       noexcept;
      //! Returns the infimum of an interval
      friend inline const real & Inf (const interval &) noexcept;
      //! Returns the supremum of an interval
      friend inline       real & Sup (interval &)       noexcept;
      //! Returns the supremum of an interval
      friend inline const real & Sup (const interval &) noexcept;
      
      //! Returns the interval with the new given infimum value
      friend inline interval& SetInf (interval &, const real &) noexcept;
      //! Returns the interval with the new given supremum value
      friend inline interval& SetSup (interval &, const real &) noexcept;
      //! Returns the interval with the unchecked new given infimum value
      friend inline interval& UncheckedSetInf (interval &, const real &) noexcept;
      //! Returns the interval with the unchecked new given supremum value
      friend inline interval& UncheckedSetSup (interval &, const real &) noexcept;

      //! Returns true if the interval is empty
      friend inline bool IsEmpty (const interval &) noexcept;

      //! Returns the absolute value of the interval
      friend inline interval abs  (const interval &) noexcept;
      //! Returns the rounded middle of the interval
      friend        real     mid  (const interval &) noexcept;	  
      // Returns the rounded middle of the interval (faster version for tests)
      friend        real     Mid  (const interval &) noexcept;	  
      //! Returns the rounded diameter of the interval
      friend inline real     diam (const interval &) noexcept;	  
      //! Multiplication of interval with \f$ 2^n \f$
      friend inline void times2pown(interval &, const int&) noexcept; // Blomquist, 28.11.02
};

/*!
\deprecated use standard contructors for typecasting

\sa cxsc::interval::interval(const real &r)
*/
inline interval _interval(const real & r) noexcept { return interval(r); }
/*!
\deprecated use standard contructors for typecasting

\sa cxsc::interval::interval(const real&, const real&)
*/
inline interval _interval(const real & a, const real & b) noexcept(false) { return interval(a,b); }
/*!
\deprecated use standard contructors for typecasting

\sa cxsc::interval::interval(const dotprecision &)
*/
inline interval _interval(const dotprecision &a) noexcept { return interval(a); }
/*!
\deprecated use standard contructors for typecasting

\sa cxsc::interval::interval(const dotprecision &,const dotprecision &)
*/
inline interval _interval(const dotprecision &a,const dotprecision &b) noexcept(false) { return interval(a,b); }
/*!
\deprecated use standard contructors for typecasting

\sa cxsc::interval::interval(const idotprecision &)
*/
inline interval _interval(const idotprecision &a) noexcept { return interval(a); }

// for compatibility with CToolbox library - from former i_util.hpp
//! Checks if first argument is part of second argument
extern int      in         ( const real&, const interval& );
//! Checks if first argument is part of second argument
extern int      in         ( const interval&, const interval& );
//extern void     rnd        ( const dotprecision&, interval& );
//! Performs an epsilon inflation
extern interval Blow       ( const interval&, const real& );
//! Checks arguments for disjointness
extern int      Disjoint   ( const interval&, const interval& );
//! Computes the smallest absolute value \f$ \left< \left[ x \right] \right> \f$
extern real     AbsMin     ( const interval& );
//! Computes the greatest absolute value \f$ \left| \left[ x \right] \right| \f$
extern real     AbsMax     ( const interval& );
//! Computes the relative diameter \f$ d_{rel}([x]) \f$
extern real     RelDiam    ( const interval& );
//! Checks if the diameter of the interval \f$ \left[ x \right] \f$ is \f$ \le n \f$ ulps
extern int      UlpAcc     ( const interval&, int );

// Additional declaration of friend functions outside class interval
real     mid  (const interval& a) noexcept;	  

// Interval constants, optimal inclusions:
//! Enclosure-Interval for \f$ \pi \f$
extern const interval Pi_interval;        // Pi
//! Enclosure-Interval for \f$ 2\pi \f$
extern const interval Pi2_interval;       // 2*Pi
//! Enclosure-Interval for \f$ 3\pi \f$
extern const interval Pi3_interval;       // 3*Pi
//! Enclosure-Interval for \f$ \frac{\pi}{2} \f$
extern const interval Pid2_interval;      // Pi/2
//! Enclosure-Interval for \f$ \frac{\pi}{3} \f$
extern const interval Pid3_interval;      // Pi/3
//! Enclosure-Interval for \f$ \frac{\pi}{4} \f$
extern const interval Pid4_interval;      // Pi/4
//! Enclosure-Interval for \f$ \frac{1}{\pi} \f$
extern const interval Pir_interval;       // 1/Pi
//! Enclosure-Interval for \f$ \frac{1}{2\pi} \f$
extern const interval Pi2r_interval;      // 1/(2*Pi)
//! Enclosure-Interval for \f$ 2^\pi \f$
extern const interval Pip2_interval;      // Pi^2
//! Enclosure-Interval for \f$ \sqrt{\pi} \f$
extern const interval SqrtPi_interval;    // sqrt(Pi)
//! Enclosure-Interval for \f$ \sqrt{2\pi} \f$
extern const interval Sqrt2Pi_interval;   // sqrt(2Pi)
//! Enclosure-Interval for \f$ \frac{1}{\sqrt{\pi}} \f$
extern const interval SqrtPir_interval;   // 1/sqrt(Pi)
//! Enclosure-Interval for \f$ \frac{1}{\sqrt{2\pi}} \f$
extern const interval Sqrt2Pir_interval;  // 1/sqrt(2Pi)
//! Enclosure-Interval for \f$ \sqrt{2} \f$
extern const interval Sqrt2_interval;     // sqrt(2)
//! Enclosure-Interval for \f$ \sqrt{5} \f$
extern const interval Sqrt5_interval;     // sqrt(5)
//! Enclosure-Interval for \f$ \sqrt{7} \f$
extern const interval Sqrt7_interval;     // sqrt(7)
//! Enclosure-Interval for \f$ \frac{1}{\sqrt{2}} \f$
extern const interval Sqrt2r_interval;    // 1/sqrt(2)
//! Enclosure-Interval for \f$ \sqrt{3} \f$
extern const interval Sqrt3_interval;     // sqrt(3)
//! Enclosure-Interval for \f$ \frac{\sqrt{3}}{2} \f$
extern const interval Sqrt3d2_interval;   // sqrt(3)/2
//! Enclosure-Interval for \f$ \frac{1}{\sqrt{3}} \f$
extern const interval Sqrt3r_interval;    // 1/sqrt(3)
//! Enclosure-Interval for \f$ \ln 2 \f$
extern const interval Ln2_interval;       // ln(2)
//! Enclosure-Interval for \f$ \frac{1}{\ln 2} \f$
extern const interval Ln2r_interval;      // 1/ln(2)
//! Enclosure-Interval for \f$ \ln 10 \f$
extern const interval Ln10_interval;      // ln(10)
//! Enclosure-Interval for \f$ \frac{1}{\ln 10} \f$
extern const interval Ln10r_interval;     // 1/ln(10)
//! Enclosure-Interval for \f$ \ln \pi \f$
extern const interval LnPi_interval;      // ln(Pi)
//! Enclosure-Interval for \f$ \ln 2\pi \f$
extern const interval Ln2Pi_interval;     // ln(2Pi)
//! Enclosure-Interval for \f$ e \f$
extern const interval E_interval;         // e
//! Enclosure-Interval for \f$ \frac{1}{e} \f$
extern const interval Er_interval;        // 1/e
//! Enclosure-Interval for \f$ e^2 \f$
extern const interval Ep2_interval;       // e^2
//! Enclosure-Interval for \f$ \frac{1}{e^2} \f$
extern const interval Ep2r_interval;      // 1/e^2
//! Enclosure-Interval for \f$ e^\pi \f$
extern const interval EpPi_interval;      // e^(Pi)
//! Enclosure-Interval for \f$ e^{2\pi} \f$
extern const interval Ep2Pi_interval;     // e^(2Pi)
//! Enclosure-Interval for \f$ e^{\frac{\pi}{2}} \f$
extern const interval EpPid2_interval;    // e^(Pi/2)
//! Enclosure-Interval for \f$ e^{\frac{\pi}{4}} \f$
extern const interval EpPid4_interval;    // e^(Pi/4)


} // namespace cxsc 

#include "interval.inl"
#include "imath.hpp"

#endif // _CXSC_INTERVAL_H_INCLUDED
