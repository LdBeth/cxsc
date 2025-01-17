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

/* CVS $Id: cmatrix.hpp,v 1.37 2014/01/30 17:23:44 cxsc Exp $ */

#ifndef _CXSC_CMATRIX_HPP_INCLUDED
#define _CXSC_CMATRIX_HPP_INCLUDED

#include "xscclass.hpp"
#include "cdot.hpp"
#include "cidot.hpp"
#include "cvector.hpp"
#include "except.hpp"
#include "matrix.hpp"
#include "rmatrix.hpp"

namespace cxsc {

class cmatrix;
class cmatrix_slice;
class srmatrix;
class srmatrix_slice;
class srmatrix_subv;
class scmatrix;
class scmatrix_slice;
class scmatrix_subv;


//! The Data Type cmatrix_subv
/*!
This Data Type provides one column or row of a matrix as a vector.
*/
class cmatrix_subv
{
	friend class cvector;
	friend class civector;
	friend class cmatrix;
	friend class cmatrix_slice;
	private:
	complex *dat;
	int lb,ub;
	int size,start,offset; // start=first element index 0..n-1
	
	public:
	//! Returns one row of the matrix as a vector
	friend INLINE cmatrix_subv Row(cmatrix &m,const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Returns one column of the matrix as a vector
	friend INLINE cmatrix_subv Col(cmatrix &m,const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	friend INLINE cmatrix_subv Row(const cmatrix &m,const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Returns one column of the matrix as a vector
	friend INLINE cmatrix_subv Col(const cmatrix &m,const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
//#if(CXSC_INDEX_CHECK)
#ifdef _CXSC_FRIEND_TPL
	//----------------- Templates ---------------------------------------
template <class MV1,class MV2> friend  MV1 &_mvmvassign(MV1 &v,const MV2 &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
template <class MV,class S> friend  MV &_mvsassign(MV &v,const  S &r) noexcept;
template <class MV,class V> friend  MV &_mvvassign(MV &v,const V &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
template <class V,class MV2,class S> friend  V &_vmvassign(V &v,const MV2 &rv) noexcept;
template <class MV,class V> friend  V _mvabs(const MV &mv) noexcept;
template <class MV,class V> friend  V _mvim(const MV &mv) noexcept;
template <class MV,class V> friend  V _mvre(const MV &mv) noexcept;
template <class MV,class V> friend  MV &_mvvsetim(MV &v,const V &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
template <class MV,class V> friend  MV &_mvvsetre(MV &v,const V &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
 template <class MV,class S> friend 	 MV &_mvssetim(MV &mv, const S &s) noexcept;
 template <class MV,class S> friend 	 MV &_mvssetre(MV &mv, const S &s) noexcept;
template <class DP,class V,class SV> friend 	void _vmvaccu(DP &dp, const V & rv1, const SV &rv2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
template <class DP,class MV1,class MV2> friend 	void _mvmvaccu(DP &dp, const MV1 & rv1, const MV2 &rv2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif

 template <class MV1,class MV2,class S> friend 	 S _mvmvcmult(const MV1 & rv1, const MV2 &rv2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MV1,class MV2,class S> friend 	 S _mvmvcimult(const MV1 & rv1, const MV2 &rv2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class V,class MV,class S> friend 	 S _vmvcmult(const V &rv1, const MV &rv2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class V,class MV,class S> friend 	 S _vmvcimult(const V &rv1, const MV &rv2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MV,class S,class E> friend 	 E _mvsmult(const MV &rv, const S &s) noexcept;
 template <class MV1,class MV2,class E> friend 	 E _mvmvplus(const MV1 &rv1, const MV2 &rv2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MV1,class MV2,class E> friend 	 E _mvmvminus(const MV1 &rv1, const MV2 &rv2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MV,class V,class E> friend 	 E _mvvplus(const MV &rv1, const V &rv2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MV,class V,class E> friend 	 E _mvvminus(const MV &rv1, const V &rv2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class V,class MV,class E> friend 	 E _vmvminus(const V &rv1, const MV &rv2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MV,class S,class E> friend 	 E _mvsdiv(const MV &rv, const S &s) noexcept;
template <class MV,class S> friend  MV &_mvsmultassign(MV &v,const S &r) noexcept;
template <class MV, class S> friend  MV &_mvsplusassign(MV &v,const S &r) noexcept;
template <class MV,class S> friend  MV &_mvsminusassign(MV &v,const S &r) noexcept;
template <class MV,class S> friend  MV &_mvsdivassign(MV &v,const S &r) noexcept;
template <class MV,class V> friend  MV &_mvvplusassign(MV &v,const V &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
template <class V,class MV> friend  V &_vmvplusassign(V &rv,const MV &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
template <class MV,class V> friend  MV &_mvvminusassign(MV &v,const V &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
template <class V,class MV> friend  V &_vmvminusassign(V &rv,const MV &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	// Real


	// interval

template <class V,class MV> friend  V &_vmvsetinf(V &rv,const MV &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
template <class V,class MV> friend  V &_vmvsetsup(V &rv,const MV &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
template <class V,class MV> friend  V &_vmvusetinf(V &rv,const MV &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
template <class V,class MV> friend  V &_vmvusetsup(V &rv,const MV &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

#endif

	//----------------- Konstruktoren ----------------------------------

	//! Constructor of class cmatrix_subv
	explicit INLINE cmatrix_subv (complex *d, const int &l, const int &u, const int &s, const int &st, const int &o) noexcept:dat(d),lb(l),ub(u),size(s),start(st),offset(o) { }
        public:
	//! Constructor of class cmatrix_subv
	INLINE cmatrix_subv(const cmatrix_subv &v) noexcept:dat(v.dat),lb(v.lb),ub(v.ub),size(v.size),start(v.start),offset(v.offset) { }
	public:

	//---------------------- Standardfunktionen ------------------------
	//! Returns the lower bound of the vector
	friend INLINE int Lb(const cmatrix_subv &rv) noexcept { return rv.lb; }
	//! Returns the upper bound of the vector
	friend INLINE int Ub(const cmatrix_subv &rv) noexcept { return rv.ub; }
	//! Returns the size of the vector
	friend INLINE int VecLen(const cmatrix_subv &rv) noexcept { return rv.size; }

	//! Operator for accessing the single elements of the vector (read-only)
	INLINE complex& operator [](const int &i) const
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

	//! Operator for accessing the single elements of the vector 
	INLINE complex& operator [](const int &i) 
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

	//! Operator for accessing the whole vector
	INLINE cmatrix_subv &operator ()() noexcept { return *this; }
	//! Operator for accessing a part of the vector
	INLINE cmatrix_subv operator ()(const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Operator for accessing a part of the vector
	INLINE cmatrix_subv operator ()(const int &i1,const int &i2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const scmatrix_subv &rv);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const scvector &r);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const scvector_slice &r);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const srmatrix_subv &rv);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const srvector &r);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const srvector_slice &r);

	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const cmatrix_subv &rv) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const complex &r) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const cmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const cmatrix_slice &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const cvector &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const cvector_slice &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

        //Sparse
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator +=(const scmatrix_subv &rv);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator +=(const scvector &r);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator +=(const scvector_slice &r);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator +=(const srmatrix_subv &rv);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator +=(const srvector &r);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator +=(const srvector_slice &r);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator -=(const scmatrix_subv &rv);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator -=(const scvector &r);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator -=(const scvector_slice &r);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator -=(const srmatrix_subv &rv);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator -=(const srvector &r);
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator -=(const srvector_slice &r);

	//! Implementation of multiplication and allocation operation
	INLINE cmatrix_subv &operator *=(const complex &c) noexcept;
	//! Implementation of addition and allocation operation
	INLINE cmatrix_subv &operator +=(const complex &c) noexcept;
	//! Implementation of subtraction and allocation operation
	INLINE cmatrix_subv &operator -=(const complex &c) noexcept;
	//! Implementation of division and allocation operation
	INLINE cmatrix_subv &operator /=(const complex &c) noexcept;
	//! Implementation of subtraction and allocation operation
	INLINE cmatrix_subv &operator -=(const cvector &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE cmatrix_subv &operator +=(const cvector &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE cmatrix_subv &operator -=(const cvector_slice &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE cmatrix_subv &operator +=(const cvector_slice &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	// Real
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const rmatrix_subv &rv) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const real &r) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const rmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const rmatrix_slice &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const rvector &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE cmatrix_subv &operator =(const rvector_slice &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

	//! Implementation of multiplication and allocation operation
	INLINE cmatrix_subv &operator *=(const real &c) noexcept;
	//! Implementation of addition and allocation operation
	INLINE cmatrix_subv &operator +=(const real &c) noexcept;
	//! Implementation of subtraction and allocation operation
	INLINE cmatrix_subv &operator -=(const real &c) noexcept;
	//! Implementation of division and allocation operation
	INLINE cmatrix_subv &operator /=(const real &c) noexcept;
	//! Implementation of subtraction and allocation operation
	INLINE cmatrix_subv &operator -=(const rvector &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE cmatrix_subv &operator +=(const rvector &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE cmatrix_subv &operator -=(const rvector_slice &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE cmatrix_subv &operator +=(const rvector_slice &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
//#else
//#endif	

};

//! Returns one row of the matrix as a vector
INLINE cmatrix_subv Row(cmatrix &m,const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
//! Returns one column of the matrix as a vector
INLINE cmatrix_subv Col(cmatrix &m,const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif



//----------------------- Matrix -----------------------------------------------

class cmatrix_slice;

//! The Data Type cmatrix
/*!
\sa rmatrix
*/
class cmatrix
{
	friend class cmatrix_slice;
	friend class cmatrix_subv;
	friend class cimatrix;
	private:
	complex *dat;
	int lb1,ub1,lb2,ub2,xsize,ysize;

	public:
	double* to_blas_array() const { return (double*)dat; }
//#if(CXSC_INDEX_CHECK)
#ifdef _CXSC_FRIEND_TPL
	//----------------- Templates ---------------------------------------
template <class S,class M> friend void _smconstr(S &s,const M &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
template <class V,class M,class S> friend void _vmconstr(V &v,const M &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class M2,class S> friend 	 M1 &_mmassign(M1 &m1,const M2 &m,S ms) noexcept;
 template <class M,class MS2,class S> friend 	 M &_mmsassign(M &m,const MS2 &ms) noexcept;
 template <class MS,class M> friend 	 MS &_msmassign(MS &ms,const M &m)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class S> friend 	 M &_msassign(M &m,const S &r) noexcept;
template <class V,class M,class S> friend  V &_vmassign(V &v,const M &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
template <class M,class V,class S> friend  M &_mvassign(M &m,const V &v) noexcept;
 template <class M> friend 	 int _mlb(const M &m, const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
 template <class M> friend 	 int _mub(const M &m, const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
 template <class M> friend 	 M &_msetlb(M &m, const int &i,const int &j)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
 template <class M> friend 	 M &_msetub(M &m, const int &i,const int &j)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
 template <class M,class E> friend 	 E _mre(const M &m) noexcept;
 template <class M,class E> friend 	 E _mim(const M &m) noexcept;
 template <class M1,class M2> friend 	 M1 &_mmsetre(M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class M2> friend 	 M1 &_mmsetim(M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class MS2> friend 	 M1 &_mmssetre(M1 &m1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class MS2> friend 	 M1 &_mmssetim(M1 &m1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M> friend 	void _mresize(M &A) noexcept;
 template <class M,class S> friend 	void _mresize(M &A,const int &m, const int &n)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class S> friend 	void _mresize(M &A,const int &m1, const int &m2,const int &n1,const int &n2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class E> friend 	 E _mabs(const M &m) noexcept;
	//-------------- matrix-matrix -------------
 template <class M1,class M2,class E> friend 	 E _mmplus(const M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS,class E> friend 	 E _mmsplus(const M &m,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M> friend 	 M _mminus(const M &m) noexcept;
 template <class MS,class E> friend 	 E _msminus(const MS &ms) noexcept;
 template <class M1,class M2,class E> friend 	 E _mmminus(const M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class M2> friend 	 M1 &_mmplusassign(M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS> friend 	 M &_mmsplusassign(M &m1,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class M> friend 	 MS &_msmplusassign(MS &ms,const M &m1)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2,class E> friend 	 E _msmsplus(const MS1 &m1,const MS2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS,class E> friend 	 E _mmsminus(const M &m,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class M,class E> friend 	 E _msmminus(const MS &ms,const M &m)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2,class E> friend 	 E _msmsminus(const MS1 &ms1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class M2> friend 	 M1 &_mmminusassign(M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS> friend 	 M &_mmsminusassign(M &m1,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class M> friend 	 MS &_msmminusassign(MS &ms,const M &m1)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class M2,class E> friend 	 E _mmcmult(const M1 &m1, const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class M2,class E> friend 	 E _mmcimult(const M1 &m1, const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class M2,class S> friend 	 M1 &_mmcmultassign(M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class M2,class S> friend 	 M1 &_mmcimultassign(M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS,class E> friend 	 E _mmscmult(const M &m1, const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS,class E> friend 	 E _mmscimult(const M &m1, const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class M,class E> friend 	 E _msmcmult(const MS &ms, const M &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class M,class E> friend 	 E _msmcimult(const MS &ms, const M &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS,class S> friend 	 M &_mmscmultassign(M &m1,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS,class S> friend 	 M &_mmscimultassign(M &m1,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2,class E> friend 	 E _msmscmult(const MS1 &ms1, const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2,class E> friend 	 E _msmscimult(const MS1 &ms1, const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class M2,class E> friend 	 E _mmconv(const M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS,class E> friend 	 E _mmsconv(const M &m,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
	//-------- matrix-scalar -----------------
 template <class S,class M,class E> friend 	 E _smmult(const S &c, const M &m) noexcept;
 template <class M,class S> friend 	 M &_msmultassign(M &m,const S &c) noexcept;
 template <class S,class MS,class E> friend 	 E _smsmult(const S &c, const MS &ms) noexcept;
 template <class M,class S,class E> friend 	 E _msdiv(const M &m,const S &c) noexcept;
 template <class M,class S> friend 	 M &_msdivassign(M &m,const S &c) noexcept;
 template <class MS,class S,class E> friend 	 E _mssdiv(const MS &ms, const S &c) noexcept;
	//-------- matrix-vector ---------------------
 template <class M,class V,class E> friend 	 E _mvcmult(const M &m,const V &v)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class V,class E> friend 	 E _mvcimult(const M &m,const V &v)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class V,class M,class E> friend 	 E _vmcmult(const V &v,const M &m)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class V,class M,class E> friend 	 E _vmcimult(const V &v,const M &m)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class V,class M,class S> friend 	 V &_vmcmultassign(V &v,const M &m)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class V,class M,class S> friend 	 V &_vmcimultassign(V &v,const M &m)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class VS,class M,class S> friend 	 VS &_vsmcmultassign(VS &v,const M &m)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class VS,class M,class S> friend 	 VS &_vsmcimultassign(VS &v,const M &m)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
	
 template <class M> friend 	void *_mvoid(const M &m) noexcept;
 template <class M> friend 	 bool _mnot(const M &m) noexcept;
 template <class MS> friend 	void *_msvoid(const MS &ms) noexcept;
 template <class MS> friend 	 bool _msnot(const MS &ms) noexcept;
 template <class M1,class M2> friend 	 bool _mmeq(const M1 &m1,const M2 &m2) noexcept;
 template <class M1,class M2> friend 	 bool _mmneq(const M1 &m1,const M2 &m2) noexcept;
 template <class M1,class M2> friend 	 bool _mmless(const M1 &m1,const M2 &m2) noexcept;
 template <class M1,class M2> friend 	 bool _mmleq(const M1 &m1,const M2 &m2) noexcept;
 template <class M,class MS> friend 	 bool _mmseq(const M &m1,const MS &ms) noexcept;
 template <class M,class MS> friend 	 bool _mmsneq(const M &m1,const MS &ms) noexcept;
 template <class M,class MS> friend 	 bool _mmsless(const M &m1,const MS &ms) noexcept;
 template <class M,class MS> friend 	 bool _mmsleq(const M &m1,const MS &ms) noexcept;
 template <class MS,class M> friend 	 bool _msmless(const MS &ms,const M &m1) noexcept;
 template <class MS,class M> friend 	 bool _msmleq(const MS &ms,const M &m1) noexcept;
 template <class M> friend 	std::ostream &_mout(std::ostream &s,const M &r) noexcept;
 template <class M> friend 	std::istream &_min(std::istream &s,M &r) noexcept;

	// Real

	//--- Real --------- matrix-matrix ----------------------

	//--- Real --------- matrix-scalar ----------------------

	//--- Real --------- matrix-vector ----------------------
 template <class MS,class V,class E> friend 	 E _msvcmult(const MS &ms,const V &v)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class V,class E> friend 	 E _msvcimult(const MS &ms,const V &v)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class V,class MS,class E> friend 	 E _vmscmult(const V &v,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class V,class MS,class E> friend 	 E _vmscimult(const V &v,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif

	// interval --------
	// matrix-matrix

 template <class MS1,class MS2,class E> friend 	 E _msmsconv(const MS1 &m1,const MS2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class M2,class E> friend 	 E _mmsect(const M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS,class E> friend 	 E _mmssect(const M &m,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif

 template <class MS1,class MS2,class E> friend 	 E _msmssect(const MS1 &m1,const MS2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
	// matrix-scalar

	// matrix-vector

	// cinterval ----------

 template <class M,class E> friend 	 E _mdiam(const M &m) noexcept;
 template <class M,class E> friend 	 E _mmid(const M &m) noexcept;
 template <class MS,class E> friend 	 E _msdiam(const MS &ms) noexcept;
 template <class MS,class E> friend 	 E _msmid(const MS &ms) noexcept;
 template <class M,class E> friend 	 E _minf(const M &m) noexcept;
 template <class MS,class E> friend 	 E _msinf(const MS &ms) noexcept;
 template <class M,class E> friend 	 E _msup(const M &m) noexcept;
 template <class MS,class E> friend 	 E _mssup(const MS &ms) noexcept;
 template <class M1,class M2> friend 	 M1 &_mmsetinf(M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class M2> friend 	 M1 &_mmsetsup(M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class M2> friend 	 M1 &_mmusetinf(M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class M2> friend 	 M1 &_mmusetsup(M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class M2> friend 	 MS1 &_msmsetinf(MS1 &ms1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class M2> friend 	 MS1 &_msmsetsup(MS1 &ms1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class M2> friend 	 MS1 &_msmusetinf(MS1 &ms1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class M2> friend 	 MS1 &_msmusetsup(MS1 &ms1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
	
	// matrix-matrix

 template <class M1,class M2> friend 	 M1 &_mmconvassign(M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS> friend 	 M &_mmsconvassign(M &m1,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class M> friend 	 MS &_msmconvassign(MS &ms,const M &m1)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif

 template <class M1,class M2> friend 	 M1 &_mmsectassign(M1 &m1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS> friend 	 M &_mmssectassign(M &m1,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class M> friend 	 MS &_msmsectassign(MS &ms,const M &m1)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
	// matrix-scalar

	// matrix-vector

#endif
	
	//--------------------------  Konstruktoren ----------------------------

// complex
	//! Constructor of class cmatrix
	INLINE cmatrix(const cmatrix &rm) noexcept;
	//! Constructor of class cmatrix
	INLINE cmatrix(const cmatrix_slice &rm) noexcept;
	//! Constructor of class cmatrix
	INLINE cmatrix(const scmatrix &rm);
	//! Constructor of class cmatrix
	INLINE cmatrix(const scmatrix_slice &rm);
	//! Constructor of class cmatrix
	INLINE cmatrix() noexcept;
	//! Constructor of class cmatrix
	explicit INLINE cmatrix(const int &m, const int &n)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Constructor of class cmatrix
	explicit INLINE cmatrix(const int &m1, const int &n1, const int &m2, const int &n2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Constructor of class cmatrix
	explicit INLINE cmatrix(const cvector &v) noexcept;
	//! Constructor of class cmatrix
	explicit INLINE cmatrix(const cvector_slice &v) noexcept;
	//! Constructor of class cmatrix
	explicit INLINE cmatrix(const complex &r) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix &operator =(const complex &r) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix &operator =(const cmatrix &m) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix &operator =(const cmatrix_slice &ms) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix &operator =(const scmatrix &m);
	//! Implementation of standard assigning operator
	INLINE cmatrix &operator =(const scmatrix_slice &ms);
	//! Implementation of standard assigning operator
	INLINE cmatrix &operator =(const cvector &v) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix &operator =(const cvector_slice &v) noexcept;
//  real
	//! Constructor of class cmatrix
	explicit INLINE cmatrix(const real &) noexcept;
	//! Constructor of class cmatrix
	explicit INLINE cmatrix(const rmatrix &rm) noexcept;
	//! Constructor of class cmatrix
	explicit INLINE cmatrix(const rmatrix_slice &rm) noexcept;
	//! Constructor of class cmatrix
	explicit INLINE cmatrix(const srmatrix &rm);
	//! Constructor of class cmatrix
	explicit INLINE cmatrix(const srmatrix_slice &rm);
	//! Constructor of class cmatrix
	explicit INLINE cmatrix(const rvector &v) noexcept;
	//! Constructor of class cmatrix
	explicit INLINE cmatrix(const rvector_slice &v) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix &operator =(const real &r) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix &operator =(const rmatrix &m) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix &operator =(const rmatrix_slice &ms) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix &operator =(const srmatrix &m);
	//! Implementation of standard assigning operator
	INLINE cmatrix &operator =(const srmatrix_slice &ms);
	//! Implementation of standard assigning operator
	INLINE cmatrix &operator =(const rvector &v) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix &operator =(const rvector_slice &v) noexcept;

	//--------------------------- Destruktoren -----------------------------

	INLINE ~cmatrix() noexcept { delete [] dat; }


	//--------------------------- Operatoren -----------------------------
	//! Implementation of addition and assignment operator
	INLINE cmatrix &operator +=(const srmatrix &m);
	//! Implementation of addition and assignment operator
	INLINE cmatrix &operator +=(const srmatrix_slice &ms);
	//! Implementation of addition and assignment operator
	INLINE cmatrix &operator +=(const scmatrix &m);
	//! Implementation of addition and assignment operator
	INLINE cmatrix &operator +=(const scmatrix_slice &ms);
	//! Implementation of addition and assignment operator
	INLINE cmatrix &operator -=(const srmatrix &m);
	//! Implementation of addition and assignment operator
	INLINE cmatrix &operator -=(const srmatrix_slice &ms);
	//! Implementation of addition and assignment operator
	INLINE cmatrix &operator -=(const scmatrix &m);
	//! Implementation of addition and assignment operator
	INLINE cmatrix &operator -=(const scmatrix_slice &ms);
	//! Implementation of addition and assignment operator
	INLINE cmatrix &operator *=(const srmatrix &m);
	//! Implementation of addition and assignment operator
	INLINE cmatrix &operator *=(const srmatrix_slice &ms);
	//! Implementation of addition and assignment operator
	INLINE cmatrix &operator *=(const scmatrix &m);
	//! Implementation of addition and assignment operator
	INLINE cmatrix &operator *=(const scmatrix_slice &ms);

        //! Computes permutation of matrix according to permutation vectors, C=PAQ
        INLINE cmatrix operator()(const intvector& p, const intvector& q);
        //! Computes permutation of matrix according to permutation matrices, C=PAQ
        INLINE cmatrix operator()(const intmatrix& P, const intmatrix& Q);
        //! Computes permutation of matrix according to permutation vector, C=PA
        INLINE cmatrix operator()(const intvector& p);
        //! Computes permutation of matrix according to permutation matrix, C=PAQ
        INLINE cmatrix operator()(const intmatrix& P);


	//------------------------- Standardfunktionen -------------------------

	//! Operator for accessing a single row of the matrix
	INLINE cmatrix_subv operator [](const int &i) const
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Operator for accessing a single column of the matrix
	INLINE cmatrix_subv operator [](const cxscmatrix_column &i) const
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Operator for accessing a single row of the matrix
	INLINE cmatrix_subv operator [](const int &i) 
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Operator for accessing a single column of the matrix
	INLINE cmatrix_subv operator [](const cxscmatrix_column &i) 
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Operator for accessing the whole matrix
	INLINE cmatrix &operator ()() noexcept { return *this; }
	//! Operator for accessing a part of the matrix
	INLINE cmatrix_slice operator ()(const int &m, const int &n)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Operator for accessing a part of the matrix
	INLINE cmatrix_slice operator ()(const int &m1, const int &m2, const int &n1, const int &n2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	INLINE operator void*() noexcept;
//#else
//#endif
};

	
//! The Data Type cmatrix_slice
/*!
This data type represents a partial cmatrix.

\sa cmatrix
*/
class cmatrix_slice
{
	friend class cmatrix;
	friend class cimatrix;
	private:
	complex *dat;
	int offset1,offset2,mxsize,mysize;
	int start1,end1,start2,end2,sxsize,sysize;     // slice size

	public:
//#if(CXSC_INDEX_CHECK)
#ifdef _CXSC_FRIEND_TPL
	//----------------- Templates ---------------------------------------
template <class V,class MS,class S> friend void _vmsconstr(V &v,const MS &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class M> friend 	 MS &_msmassign(MS &ms,const M &m)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2> friend 	 MS1 &_msmsassign(MS1 &ms1,const MS2 &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS2,class S> friend 	 M &_mmsassign(M &m,const MS2 &ms) noexcept;
 template <class MS,class S> friend 	 MS &_mssassign(MS &ms,const S &r) noexcept;

 template <class MS> friend 	 int _mslb(const MS &ms, const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
 template <class MS> friend 	 int _msub(const MS &ms, const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class E> friend 	 E _msre(const MS &ms) noexcept;
 template <class MS,class E> friend 	 E _msim(const MS &ms) noexcept;
 template <class MS1,class M2> friend 	 MS1 &_msmsetre(MS1 &ms1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class M2> friend 	 MS1 &_msmsetim(MS1 &ms1,const M2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2> friend 	 MS1 &_msmssetre(MS1 &ms1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2> friend 	 MS1 &_msmssetim(MS1 &ms1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class E> friend 	 E _msabs(const MS &ms) noexcept;
	//-------- matrix-matrix --------------
 template <class MS,class E> friend 	 E _msminus(const MS &ms) noexcept;
 template <class M,class MS,class E> friend 	 E _mmsplus(const M &m,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2,class E> friend 	 E _msmsplus(const MS1 &m1,const MS2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS> friend 	 M &_mmsplusassign(M &m1,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class M> friend 	 MS &_msmplusassign(MS &ms,const M &m1)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2> friend 	 MS1 &_msmsplusassign(MS1 &ms1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS,class E> friend 	 E _mmsminus(const M &m,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class M,class E> friend 	 E _msmminus(const MS &ms,const M &m)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2,class E> friend 	 E _msmsminus(const MS1 &ms1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS> friend 	 M &_mmsminusassign(M &m1,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class M> friend 	 MS &_msmminusassign(MS &ms,const M &m1)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2> friend 	 MS1 &_msmsminusassign(MS1 &ms1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS,class E> friend 	 E _mmscmult(const M &m1, const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS,class E> friend 	 E _mmscimult(const M &m1, const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class M,class E> friend 	 E _msmcmult(const MS &ms, const M &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class M,class E> friend 	 E _msmcimult(const MS &ms, const M &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS,class S> friend 	 M &_mmscmultassign(M &m1,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS,class S> friend 	 M &_mmscimultassign(M &m1,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2,class E> friend 	 E _msmscmult(const MS1 &ms1, const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2,class E> friend 	 E _msmscimult(const MS1 &ms1, const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M,class MS,class E> friend 	 E _mmsconv(const M &m,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2,class E> friend 	 E _msmsconv(const MS1 &m1,const MS2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
	//--------- matrix-vector --------------
 template <class MS,class V,class E> friend 	 E _msvcmult(const MS &ms,const V &v)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS,class V,class E> friend 	 E _msvcimult(const MS &ms,const V &v)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class V,class MS,class E> friend 	 E _vmscmult(const V &v,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class V,class MS,class E> friend 	 E _vmscimult(const V &v,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class V,class MS,class S> friend 	 V &_vmscmultassign(V &v,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class V,class MS,class S> friend 	 V &_vmscimultassign(V &v,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
	//--------- matrix-scalar --------------
 template <class S,class MS,class E> friend 	 E _smsmult(const S &c, const MS &ms) noexcept;
 template <class MS,class S> friend 	 MS &_mssmultassign(MS &ms,const S &c) noexcept;
 template <class MS,class S,class E> friend 	 E _mssdiv(const MS &ms, const S &c) noexcept;
 template <class MS,class S> friend 	 MS &_mssdivassign(MS &ms,const S &c) noexcept;
	
 template <class MS> friend 	void *_msvoid(const MS &ms) noexcept;
 template <class MS> friend 	 bool _msnot(const MS &ms) noexcept;
 template <class M,class MS> friend 	 bool _mmseq(const M &m1,const MS &ms) noexcept;
 template <class M,class MS> friend 	 bool _mmsneq(const M &m1,const MS &ms) noexcept;
 template <class M,class MS> friend 	 bool _mmsless(const M &m1,const MS &ms) noexcept;
 template <class M,class MS> friend 	 bool _mmsleq(const M &m1,const MS &ms) noexcept;
 template <class MS,class M> friend 	 bool _msmless(const MS &ms,const M &m1) noexcept;
 template <class MS,class M> friend 	 bool _msmleq(const MS &ms,const M &m1) noexcept;
 template <class MS1,class MS2> friend 	 bool _msmseq(const MS1 &ms1,const MS2 &ms2) noexcept;
 template <class MS1,class MS2> friend 	 bool _msmsneq(const MS1 &ms1,const MS2 &ms2) noexcept;
 template <class MS1,class MS2> friend 	 bool _msmsless(const MS1 &ms1,const MS2 &ms2) noexcept;
 template <class MS1,class MS2> friend 	 bool _msmsleq(const MS1 &ms1,const MS2 &ms2) noexcept;
 template <class MS> friend 	std::ostream &_msout(std::ostream &s,const MS &r) noexcept;
 template <class MS> friend 	std::istream &_msin(std::istream &s,MS &r) noexcept;

	// Real

	//--- Real ------------ matrix-scalar ----------- 
	//--- Real ------------ matrix-vector -----------
	//--- Real ------------ matrix-matrix -----------
	// interval ----------------
	// matrix-matrix

 template <class M,class MS,class E> friend 	 E _mmssect(const M &m,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2,class E> friend 	 E _msmssect(const MS1 &m1,const MS2 &m2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
	// matrix-scalar
	// matrix-vector

	// cinterval --------------

 template <class M1,class MS2> friend 	 M1 &_mmssetinf(M1 &m1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class MS2> friend 	 M1 &_mmssetsup(M1 &m1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class MS2> friend 	 M1 &_mmsusetinf(M1 &m1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class M1,class MS2> friend 	 M1 &_mmsusetsup(M1 &m1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2> friend 	 MS1 &_msmssetinf(MS1 &ms1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2> friend 	 MS1 &_msmssetsup(MS1 &ms1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2> friend 	 MS1 &_msmsusetinf(MS1 &ms1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2> friend 	 MS1 &_msmsusetsup(MS1 &ms1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif

	// matrix-matrix

 template <class M,class MS> friend 	 M &_mmsconvassign(M &m1,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2> friend 	 MS1 &_msmsconvassign(MS1 &ms1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif

 template <class M,class MS> friend 	 M &_mmssectassign(M &m1,const MS &ms)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif
 template <class MS1,class MS2> friend 	 MS1 &_msmssectassign(MS1 &ms1,const MS2 &ms2)
#if(CXSC_INDEX_CHECK)
		noexcept(false);
#else
	noexcept;
#endif

	// matrix-scalar
	// cinterval -- matrix-vector


  /*   friend TINLINE civector &_vsmscimultassign<civector_slice,cmatrix_slice,cinterval>(civector_slice &v,const cmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
	#endif */

#endif

	//--------------- Konstruktoren ----------------------------------------

	//! Constructor of class cmatrix_slice
	explicit INLINE cmatrix_slice(cmatrix &a,const int &l1,const int &u1,const int &l2, const int &u2) noexcept:dat(a.dat),offset1(l1-a.lb1),offset2(l2-a.lb2),mxsize(a.xsize),mysize(a.ysize),start1(l1),end1(u1),start2(l2),end2(u2),sxsize(u2-l2+1),sysize(u1-l1+1) { }
	//! Constructor of class cmatrix_slice
	explicit INLINE cmatrix_slice(cmatrix_slice &a,const int &l1,const int &u1,const int &l2, const int &u2) noexcept:dat(a.dat),offset1(a.offset1+l1-a.start1),offset2(a.offset2+l2-a.start2),mxsize(a.mxsize),mysize(a.mysize),start1(l1),end1(u1),start2(l2),end2(u2),sxsize(u2-l2+1),sysize(u1-l1+1) { }
	public: 
	//! Constructor of class cmatrix_slice
	INLINE cmatrix_slice(const cmatrix_slice &ms) noexcept:dat(ms.dat),offset1(ms.offset1),offset2(ms.offset2),mxsize(ms.mxsize),mysize(ms.mysize),start1(ms.start1),end1(ms.end1),start2(ms.start2),end2(ms.end2),sxsize(ms.sxsize),sysize(ms.sysize) { }
	public:

	//---------------- Standardfunktionen -----------------------------------

	friend  cvector::cvector(const cmatrix_slice &sl)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	friend INLINE cmatrix::cmatrix(const cmatrix_slice &) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix_slice &operator =(const cmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

        //Sparse
	//! Implementation of standard assigning operator
	INLINE cmatrix_slice &operator =(const scmatrix &ms);
	//! Implementation of standard assigning operator
	INLINE cmatrix_slice &operator =(const scmatrix_slice &ms);
	//! Implementation of standard assigning operator
	INLINE cmatrix_slice &operator =(const srmatrix &ms);
	//! Implementation of standard assigning operator
	INLINE cmatrix_slice &operator =(const srmatrix_slice &ms);


	//! Implementation of standard assigning operator
	INLINE cmatrix_slice &operator =(const cmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE cmatrix_slice &operator =(const complex &r) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix_slice &operator =(const cvector &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE cmatrix_slice &operator =(const cvector_slice &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE cmatrix_slice &operator =(const rmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE cmatrix_slice &operator =(const rmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE cmatrix_slice &operator =(const real &r) noexcept;
	//! Implementation of standard assigning operator
	INLINE cmatrix_slice &operator =(const rvector &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE cmatrix_slice &operator =(const rvector_slice &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Operator for accessing a single row of the matrix
	INLINE cmatrix_subv operator [](const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Operator for accessing a single column of the matrix
	INLINE cmatrix_subv operator [](const cxscmatrix_column &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

	//! Operator for accessing a single row of the matrix
	INLINE cmatrix_subv operator [](const int &i) const
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Operator for accessing a single column of the matrix
	INLINE cmatrix_subv operator [](const cxscmatrix_column &i) const
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Operator for accessing the whole matrix
	INLINE cmatrix_slice &operator ()() noexcept { return *this; }
	//! Operator for accessing a part of the matrix
	INLINE cmatrix_slice operator ()(const int &m, const int &n)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Operator for accessing a part of the matrix
	INLINE cmatrix_slice operator ()(const int &m1, const int &m2, const int &n1, const int &n2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

        //Sparse
	//! Implementation of addition and assignment operator
	INLINE cmatrix_slice &operator +=(const srmatrix &m);
	//! Implementation of addition and assignment operator
	INLINE cmatrix_slice &operator +=(const srmatrix_slice &ms);
	//! Implementation of addition and assignment operator
	INLINE cmatrix_slice &operator +=(const scmatrix &m);
	//! Implementation of addition and assignment operator
	INLINE cmatrix_slice &operator +=(const scmatrix_slice &ms);
	//! Implementation of addition and assignment operator
	INLINE cmatrix_slice &operator -=(const srmatrix &m);
	//! Implementation of addition and assignment operator
	INLINE cmatrix_slice &operator -=(const srmatrix_slice &ms);
	//! Implementation of addition and assignment operator
	INLINE cmatrix_slice &operator -=(const scmatrix &m);
	//! Implementation of addition and assignment operator
	INLINE cmatrix_slice &operator -=(const scmatrix_slice &ms);
	//! Implementation of addition and assignment operator
	INLINE cmatrix_slice &operator *=(const srmatrix &m);
	//! Implementation of addition and assignment operator
	INLINE cmatrix_slice &operator *=(const srmatrix_slice &ms);
	//! Implementation of addition and assignment operator
	INLINE cmatrix_slice &operator *=(const scmatrix &m);
	//! Implementation of addition and assignment operator
	INLINE cmatrix_slice &operator *=(const scmatrix_slice &ms);

	//! Implementation of multiplication and allocation operation
	INLINE cmatrix_slice &operator *=(const cmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication and allocation operation
	INLINE cmatrix_slice &operator *=(const rmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication and allocation operation
	INLINE cmatrix_slice &operator *=(const cmatrix_slice &ms2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication and allocation operation
	INLINE cmatrix_slice &operator *=(const rmatrix_slice &ms2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE cmatrix_slice &operator +=(const cmatrix &m1)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE cmatrix_slice &operator +=(const rmatrix &m1)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE cmatrix_slice &operator +=(const cmatrix_slice &ms2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE cmatrix_slice &operator +=(const rmatrix_slice &ms2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE cmatrix_slice &operator -=(const cmatrix &m1)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE cmatrix_slice &operator -=(const rmatrix &m1)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE cmatrix_slice &operator -=(const cmatrix_slice &ms2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE cmatrix_slice &operator -=(const rmatrix_slice &ms2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Allocates the convex hull of the arguments to the first argument
	INLINE cmatrix_slice &operator |=(const cmatrix &m1)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Allocates the convex hull of the arguments to the first argument
	INLINE cmatrix_slice &operator |=(const rmatrix &m1)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Allocates the convex hull of the arguments to the first argument
	INLINE cmatrix_slice &operator |=(const cmatrix_slice &ms2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Allocates the convex hull of the arguments to the first argument
	INLINE cmatrix_slice &operator |=(const rmatrix_slice &ms2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication and allocation operation
	INLINE cmatrix_slice &operator *=(const complex &c) noexcept;
	//! Implementation of multiplication and allocation operation
	INLINE cmatrix_slice &operator *=(const real &c) noexcept;
	//! Implementation of division and allocation operation
	INLINE cmatrix_slice &operator /=(const complex &c) noexcept;
	//! Implementation of division and allocation operation
	INLINE cmatrix_slice &operator /=(const real &c) noexcept;
	INLINE operator void*() noexcept;
//#else
//#endif
};

//================================================================
//====================== Subvector Functions =====================

//=======================Vector / Scalar =========================

	//! Implementation of division operation
	INLINE cvector operator /(const cmatrix_subv &rv, const complex &s) noexcept;
	//! Implementation of multiplication operation
	INLINE cvector operator *(const cmatrix_subv &rv, const complex &s) noexcept;
	//! Implementation of multiplication operation
	INLINE cvector operator *(const complex &s, const cmatrix_subv &rv) noexcept;

//======================== Vector / Vector ========================
	
	//! Returns the absolute value of the matrix
	INLINE rvector abs(const cmatrix_subv &mv) noexcept;
	//! Returns the imaginary part of the matrix
	INLINE rvector Im(const cmatrix_subv &mv) noexcept;
	//! Returns the real part of the matrix
	INLINE rvector Re(const cmatrix_subv &mv) noexcept;
	//! Sets componentwise the imaginary parts of the matrix
	INLINE cmatrix_subv &SetIm(cmatrix_subv &mv,const rvector &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Sets componentwise the real parts of the matrix
	INLINE cmatrix_subv &SetRe(cmatrix_subv &mv,const rvector &rv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Sets componentwise the real parts of the matrix
	INLINE cmatrix_subv &SetRe(cmatrix_subv &iv,const real &r) noexcept;
	//! Sets componentwise the imaginary parts of the matrix
	INLINE cmatrix_subv &SetIm(cmatrix_subv &iv,const real &r) noexcept;

	
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	void accumulate(cdotprecision &dp, const cmatrix_subv & rv1, const cmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

	//! The accurate scalar product of the last two arguments added to the value of the first argument (without error bound)
	void accumulate_approx(cdotprecision &dp, const cmatrix_subv & rv1, const cmatrix_subv &rv2);

	//! The accurate scalar product of the last two arguments added to the value of the first argument
	void accumulate(cdotprecision &dp, const cvector & rv1, const cmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

	//! The accurate scalar product of the last two arguments added to the value of the first argument (without error bound)
	void accumulate_approx(cdotprecision &dp, const cvector & rv1, const cmatrix_subv &rv2);

	//! The accurate scalar product of the last two arguments added to the value of the first argument
	void accumulate(cdotprecision &dp, const cmatrix_subv & rv1, const cvector &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

	//! The accurate scalar product of the last two arguments added to the value of the first argument (without error bound)
	void accumulate_approx(cdotprecision &dp, const cmatrix_subv & rv1, const cvector &rv2);

	//! The accurate scalar product of the last two arguments added to the value of the first argument
	void accumulate(cdotprecision &dp, const cvector_slice & sl1, const cmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

	//! The accurate scalar product of the last two arguments added to the value of the first argument (without error bound)
	void accumulate_approx(cdotprecision &dp, const cvector_slice & sl1, const cmatrix_subv &rv2);

	//! The accurate scalar product of the last two arguments added to the value of the first argument
	void accumulate(cdotprecision &dp, const cmatrix_subv & rv1, const cvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

	//! The accurate scalar product of the last two arguments added to the value of the first argument (without error bound)
	void accumulate_approx(cdotprecision &dp, const cmatrix_subv & rv1, const cvector_slice &sl2);

	
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	void accumulate(cidotprecision &dp, const cmatrix_subv & rv1, const cmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	void accumulate(cidotprecision &dp, const cvector & rv1, const cmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	void accumulate(cidotprecision &dp, const cmatrix_subv & rv1, const cvector &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	void accumulate(cidotprecision &dp, const cvector_slice & sl1, const cmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	void accumulate(cidotprecision &dp, const cmatrix_subv & rv1, const cvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	
	//! Implementation of multiplication operation
	INLINE complex operator *(const cmatrix_subv & rv1, const cmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE complex operator *(const cvector & rv1, const cmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE complex operator *(const cmatrix_subv &rv1,const cvector &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE complex operator *(const cvector_slice &sl,const cmatrix_subv &sv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE complex operator *(const cmatrix_subv &mv,const cvector_slice &vs)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

	//! Implementation of addition operation
	INLINE cvector operator +(const cmatrix_subv & rv1, const cmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE cvector operator +(const cmatrix_subv &rv1,const cvector &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE cvector operator +(const cvector & rv1, const cmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE cvector operator +(const cvector_slice &sl,const cmatrix_subv &mv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE cvector operator +(const cmatrix_subv &mv,const cvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	
	//! Implementation of subtraction operation
	INLINE cvector operator -(const cmatrix_subv & rv1, const cmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE cvector operator -(const cvector & rv1, const cmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE cvector operator -(const cmatrix_subv &rv1,const cvector &rv2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE cvector operator -(const cvector_slice &sl,const cmatrix_subv &mv)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE cvector operator -(const cmatrix_subv &mv,const cvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

//====================================================================
//===================== Matrix Functions =============================

	//! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
	INLINE cmatrix _cmatrix(const cmatrix &rm) noexcept;
	//! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
	INLINE cmatrix _cmatrix(const cvector &v) noexcept;
	//! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
	INLINE cmatrix _cmatrix(const cvector_slice &v) noexcept;
	//! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
	INLINE cmatrix _cmatrix(const complex &r) noexcept;

	//! Returns the lower bound index
	INLINE int Lb(const cmatrix &rm, const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Returns the upper bound index
	INLINE int Ub(const cmatrix &rm, const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Returns the lower bound index
	INLINE int Lb(const cmatrix_slice &rm, const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Returns the upper bound index
	INLINE int Ub(const cmatrix_slice &rm, const int &i)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Sets the lower bound index
	INLINE cmatrix &SetLb(cmatrix &m, const int &i,const int &j)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Sets the upper bound index
	INLINE cmatrix &SetUb(cmatrix &m, const int &i,const int &j)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Resizes the matrix
	INLINE void Resize(cmatrix &A) noexcept;
	//! Resizes the matrix
	INLINE void Resize(cmatrix &A,const int &m, const int &n)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Resizes the matrix
	INLINE void Resize(cmatrix &A,const int &m1, const int &m2,const int &n1,const int &n2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

	//! Returns the absolute value of the matrix
	INLINE rmatrix abs(const cmatrix &m) noexcept;
	//! Returns the absolute value of the matrix
	INLINE rmatrix abs(const cmatrix_slice &ms) noexcept;
	//! Returns the imaginary part of the matrix
	INLINE rmatrix Im(const cmatrix &m) noexcept;
	//! Returns the real part of the matrix
	INLINE rmatrix Re(const cmatrix &m) noexcept;
	//! Returns the imaginary part of the matrix
	INLINE rmatrix Im(const cmatrix_slice &m) noexcept;
	//! Returns the real part of the matrix
	INLINE rmatrix Re(const cmatrix_slice &m) noexcept;
	//! Sets componentwise the imaginary parts of the matrix
	INLINE cmatrix &SetIm(cmatrix &cm,const rmatrix &rm)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Sets componentwise the imaginary parts of the matrix
	INLINE cmatrix_slice &SetIm(cmatrix_slice &cm,const rmatrix &rm)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Sets componentwise the imaginary parts of the matrix
	INLINE cmatrix &SetIm(cmatrix &cm,const rmatrix_slice &rm)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Sets componentwise the imaginary parts of the matrix
	INLINE cmatrix_slice &SetIm(cmatrix_slice &cm,const rmatrix_slice &rm)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Sets componentwise the real parts of the matrix
	INLINE cmatrix &SetRe(cmatrix &cm,const rmatrix &rm)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Sets componentwise the real parts of the matrix
	INLINE cmatrix_slice &SetRe(cmatrix_slice &cm,const rmatrix &rm)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Sets componentwise the real parts of the matrix
	INLINE cmatrix &SetRe(cmatrix &cm,const rmatrix_slice &rm)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Sets componentwise the real parts of the matrix
	INLINE cmatrix_slice &SetRe(cmatrix_slice &cm,const rmatrix_slice &rm)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

//===================== Matrix / Scalar ===============================

	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const complex &c, const cmatrix &m) noexcept;
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const complex &c, const cmatrix_slice &ms) noexcept;
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const cmatrix &m,const complex &c) noexcept;
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const cmatrix_slice &ms,const complex &c) noexcept;
	//! Implementation of multiplication and allocation operation
	INLINE cmatrix &operator *=(cmatrix &m,const complex &c) noexcept;
	//! Implementation of division operation
	INLINE cmatrix operator /(const cmatrix &m,const complex &c) noexcept;
	//! Implementation of division operation
	INLINE cmatrix operator /(const cmatrix_slice &ms, const complex &c) noexcept;
	//! Implementation of division and allocation operation
	INLINE cmatrix &operator /=(cmatrix &m,const complex &c) noexcept;
	
//------------ real - cmatrix -----------------------------------------------

	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const real &c, const cmatrix &m) noexcept;
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const real &c, const cmatrix_slice &ms) noexcept;
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const cmatrix &m,const real &c) noexcept;
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const cmatrix_slice &ms,const real &c) noexcept;
	//! Implementation of multiplication and allocation operation
	INLINE cmatrix &operator *=(cmatrix &m,const real &c) noexcept;
	//! Implementation of division operation
	INLINE cmatrix operator /(const cmatrix &m,const real &c) noexcept;
	//! Implementation of division operation
	INLINE cmatrix operator /(const cmatrix_slice &ms, const real &c) noexcept;
	//! Implementation of division and allocation operation
	INLINE cmatrix &operator /=(cmatrix &m,const real &c) noexcept;
//----------------- rmatrix - complex ----------------

	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const complex &c, const rmatrix &m) noexcept;
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const complex &c, const rmatrix_slice &ms) noexcept;
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const rmatrix &m,const complex &c) noexcept;
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const rmatrix_slice &ms,const complex &c) noexcept;
	//! Implementation of division operation
	INLINE cmatrix operator /(const rmatrix &m,const complex &c) noexcept;
	//! Implementation of division operation
	INLINE cmatrix operator /(const rmatrix_slice &ms, const complex &c) noexcept;
	

//============================ Matrix / Vector ===================================

	
	//! Implementation of multiplication operation
	INLINE cvector operator *(const cmatrix &m,const cvector &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cvector operator *(const cmatrix_slice &ms,const cvector &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cvector operator *(const cvector &v,const cmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cvector operator *(const cvector &v,const cmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication and allocation operation
	INLINE cvector &operator *=(cvector &v,const cmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication and allocation operation
	INLINE cvector &operator *=(cvector &v,const cmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif

	//! Implementation of multiplication operation
	INLINE cvector operator *(const cvector_slice &v,const cmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cvector operator *(const cvector_slice &v,const cmatrix_slice &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	
//----------------- real -------------------------------------

	//! Implementation of multiplication operation
	INLINE cvector operator *(const rvector &v,const cmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cvector operator *(const rvector &v,const cmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cvector operator *(const rvector_slice &v,const cmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	
	//! Implementation of multiplication operation
	INLINE cvector operator *(const cmatrix &m,const rvector &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cvector operator *(const cmatrix_slice &ms,const rvector &v)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	

//================ Matrix / Matrix ============================

	//! Implementation of positive sign operation
	INLINE const cmatrix &operator +(const cmatrix &m1) noexcept;
	//! Implementation of positive sign operation
	INLINE cmatrix operator +(const cmatrix_slice &ms) noexcept;
	//! Implementation of addition operation
	INLINE cmatrix operator +(const cmatrix &m1,const cmatrix &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE cmatrix operator +(const cmatrix &m,const cmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE cmatrix operator +(const cmatrix_slice &ms,const cmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE cmatrix operator +(const cmatrix_slice &m1,const cmatrix_slice &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE cmatrix &operator +=(cmatrix &m1,const cmatrix &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE cmatrix &operator +=(cmatrix &m1,const cmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	
	//! Implementation of negative sign operation
	INLINE cmatrix operator -(const cmatrix &m) noexcept;
	//! Implementation of negative sign operation
	INLINE cmatrix operator -(const cmatrix_slice &ms) noexcept;
	//! Implementation of subtraction operation
	INLINE cmatrix operator -(const cmatrix &m1,const cmatrix &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE cmatrix operator -(const cmatrix &m,const cmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE cmatrix operator -(const cmatrix_slice &ms,const cmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE cmatrix operator -(const cmatrix_slice &ms1,const cmatrix_slice &ms2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE cmatrix &operator -=(cmatrix &m1,const cmatrix &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE cmatrix &operator -=(cmatrix &m1,const cmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const cmatrix &m1, const cmatrix &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const cmatrix &m1, const cmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const cmatrix_slice &ms, const cmatrix &m1)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const cmatrix_slice &ms1, const cmatrix_slice &ms2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication and allocation operation
	INLINE cmatrix &operator *=(cmatrix &m1,const cmatrix &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication and allocation operation
	INLINE cmatrix &operator *=(cmatrix &m1,const cmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	
	
	//---------- rmatrix-cmatrix ------------------
	//! Implementation of addition operation
	INLINE cmatrix operator +(const rmatrix &m1,const cmatrix &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE cmatrix operator +(const cmatrix &m1,const rmatrix &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE cmatrix operator +(const rmatrix &m,const cmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE cmatrix operator +(const cmatrix &m,const rmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE cmatrix operator +(const rmatrix_slice &ms,const cmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE cmatrix operator +(const cmatrix_slice &ms,const rmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE cmatrix operator +(const rmatrix_slice &m1,const cmatrix_slice &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE cmatrix operator +(const cmatrix_slice &m1,const rmatrix_slice &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE cmatrix &operator +=(cmatrix &m1,const rmatrix &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE cmatrix &operator +=(cmatrix &m1,const rmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	
	//! Implementation of subtraction operation
	INLINE cmatrix operator -(const rmatrix &m1,const cmatrix &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE cmatrix operator -(const cmatrix &m1,const rmatrix &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE cmatrix operator -(const rmatrix &m,const cmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE cmatrix operator -(const cmatrix &m,const rmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE cmatrix operator -(const rmatrix_slice &ms,const cmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE cmatrix operator -(const cmatrix_slice &ms,const rmatrix &m)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE cmatrix operator -(const rmatrix_slice &ms1,const cmatrix_slice &ms2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE cmatrix operator -(const cmatrix_slice &ms1,const rmatrix_slice &ms2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE cmatrix &operator -=(cmatrix &m1,const rmatrix &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE cmatrix &operator -=(cmatrix &m1,const rmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const rmatrix &m1, const cmatrix &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const cmatrix &m1, const rmatrix &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const rmatrix &m1, const cmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const cmatrix &m1, const rmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const rmatrix_slice &ms, const cmatrix &m1)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const cmatrix_slice &ms, const rmatrix &m1)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const rmatrix_slice &ms1, const cmatrix_slice &ms2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE cmatrix operator *(const cmatrix_slice &ms1, const rmatrix_slice &ms2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication and allocation operation
	INLINE cmatrix &operator *=(cmatrix &m1,const rmatrix &m2)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	//! Implementation of multiplication and allocation operation
	INLINE cmatrix &operator *=(cmatrix &m1,const rmatrix_slice &ms)
#if(CXSC_INDEX_CHECK)
	noexcept(false);
#else
	noexcept;
#endif
	

//============== Compare Operator ==========================

//-------------- Matrix - Matrix   -------------------------

	//! Implementation of standard equality operation
	INLINE bool operator ==(const cmatrix &m1,const cmatrix &m2) noexcept;
	//! Implementation of standard negated equality operation
	INLINE bool operator !=(const cmatrix &m1,const cmatrix &m2) noexcept;
/*	INLINE bool operator <(const cmatrix &m1,const cmatrix &m2) noexcept;
	INLINE bool operator <=(const cmatrix &m1,const cmatrix &m2) noexcept;
	INLINE bool operator >(const cmatrix &m1,const cmatrix &m2) noexcept;
	INLINE bool operator >=(const cmatrix &m1,const cmatrix &m2) noexcept;*/
	//! Implementation of standard equality operation
	INLINE bool operator ==(const cmatrix &m1,const cmatrix_slice &ms) noexcept;
	//! Implementation of standard negated equality operation
	INLINE bool operator !=(const cmatrix &m1,const cmatrix_slice &ms) noexcept;
/*	INLINE bool operator <(const cmatrix &m1,const cmatrix_slice &ms) noexcept;
	INLINE bool operator <=(const cmatrix &m1,const cmatrix_slice &ms) noexcept;
	INLINE bool operator >(const cmatrix &m1,const cmatrix_slice &ms) noexcept;
	INLINE bool operator >=(const cmatrix &m1,const cmatrix_slice &ms) noexcept;
*/
//---------------- Matrix - Matrix_slice ----------------------

	//! Implementation of standard equality operation
	INLINE bool operator ==(const cmatrix_slice &m1,const cmatrix_slice &m2) noexcept;
	//! Implementation of standard negated equality operation
	INLINE bool operator !=(const cmatrix_slice &m1,const cmatrix_slice &m2) noexcept;
/*	INLINE bool operator <(const cmatrix_slice &m1,const cmatrix_slice &m2) noexcept;
	INLINE bool operator <=(const cmatrix_slice &m1,const cmatrix_slice &m2) noexcept;
	INLINE bool operator >(const cmatrix_slice &m1,const cmatrix_slice &m2) noexcept;
	INLINE bool operator >=(const cmatrix_slice &m1,const cmatrix_slice &m2) noexcept;
*/
//=================== Not Operator =============================

	//! Implementation of standard negation operation
	INLINE bool operator !(const cmatrix &ms) noexcept;
	//! Implementation of standard negation operation
	INLINE bool operator !(const cmatrix_slice &ms) noexcept;

//======================== Input / Output ========================

	//! Implementation of standard output method
	INLINE std::ostream &operator <<(std::ostream &s,const cmatrix &r) noexcept;
	//! Implementation of standard output method
	INLINE std::ostream &operator <<(std::ostream &s,const cmatrix_slice &r) noexcept;
	//! Implementation of standard input method
	INLINE std::istream &operator >>(std::istream &s,cmatrix &r) noexcept;
	//! Implementation of standard input method
	INLINE std::istream &operator >>(std::istream &s,cmatrix_slice &r) noexcept;

        //! Returns the row dimension
        INLINE int      RowLen     ( const cmatrix& );
        //! Returns the column dimension
        INLINE int      ColLen     ( const cmatrix& );
        //! Returns the row dimension
        INLINE int      RowLen     ( const cmatrix_slice& );
        //! Returns the column dimension
        INLINE int      ColLen     ( const cmatrix_slice& );
        //! Returns Ostrowski's comparsion matrix
        rmatrix  CompMat    ( const cmatrix& );
        //! Returns the Identity matrix
        cmatrix  Id         ( cmatrix& );
        //! Returns the transposed matrix
        cmatrix  transp     ( const cmatrix& );
        //! Doubles the size of the matrix
        void     DoubleSize ( cmatrix& );

} // namespace cxsc 


#ifdef _CXSC_INCL_INL
#include "matrix.inl"
#include "cmatrix.inl"
#endif

#ifdef _CXSC_CIVECTOR_HPP_INCLUDED
# ifdef _CXSC_INCL_INL
#  include "civeccmat.inl"
# else
#  include "civeccmat.hpp"
# endif
#endif

#ifdef _CXSC_IVECTOR_HPP_INCLUDED
# ifdef _CXSC_INCL_INL
#  include "iveccmat.inl"
# else
#  include "iveccmat.hpp"
# endif
#endif

#ifdef _CXSC_IMATRIX_HPP_INCLUDED
# ifdef _CXSC_INCL_INL
#  include "cmatimat.inl"
# else
#  include "cmatimat.hpp"
# endif
#endif


#ifdef CXSC_USE_BLAS
#define _CXSC_BLAS_CMATRIX
#include "cxsc_blas.inl"
#endif

#endif
