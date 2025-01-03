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

/* CVS $Id: t_chi1.c,v 1.21 2014/01/30 17:24:15 cxsc Exp $ */

#ifdef AIX
#include "/u/p88c/runtime/tbyte/t_defs.h"
#else
#include "t_defs.h"
#endif

#define IfNoErr(A)      \
   if (NoErr==(exc=A))

/*--------------------------------------------------------------*
 | Pruefe arg der IntervallFunktionen mit einem Argument        |
 *--------------------------------------------------------------*/
#ifdef ANSI_C
#ifdef LINT_ARGS
int chk_arg_i1(int fct, const IExtReal *arg, IExtReal *res)
#else
int chk_arg_i1(fct, arg, res)
      int      fct;        /* FunktionsNummer                   */
const IExtReal *arg;
      IExtReal *res;
#endif /* LINT_ARGS */
#else  /* NOT ANSI_C */
#ifdef LINT_ARGS
int chk_arg_i1(int fct, IExtReal *arg, IExtReal *res)
#else
int chk_arg_i1(fct, arg, res)
int      fct;        /* FunktionsNummer                         */
IExtReal *arg;
IExtReal *res;
#endif /* LINT_ARGS */
#endif /* ANSI_C */
{
   int      exc;

   IfNoErr( chk_1(fct, &(arg->u)) )
   IfNoErr( chk_1(fct, &(arg->l)) )
   IfNoErr( chk_ival(arg) )
      return NoErr;

   /* --- FehlerHandle --- */
   return exc_handle_i1(fct, exc, arg, res);

} /* chk_arg_i1() */




