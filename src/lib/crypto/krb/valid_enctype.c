/*
 * Copyright (C) 1998 by the FundsXpress, INC.
 * 
 * All rights reserved.
 * 
 * Export of this software from the United States of America may require
 * a specific license from the United States Government.  It is the
 * responsibility of any person or organization contemplating export to
 * obtain such a license before exporting.
 * 
 * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and
 * distribute this software and its documentation for any purpose and
 * without fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation, and that
 * the name of FundsXpress. not be used in advertising or publicity pertaining
 * to distribution of the software without specific, written prior
 * permission.  FundsXpress makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 * 
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#include "k5-int.h"
#include "etypes.h"

krb5_boolean KRB5_CALLCONV
krb5_c_valid_enctype(krb5_enctype etype)
{
    return (find_enctype(etype) != NULL);
}

krb5_boolean KRB5_CALLCONV
valid_enctype(krb5_enctype etype)
{
    return krb5_c_valid_enctype(etype);
}

krb5_boolean KRB5_CALLCONV
krb5_c_weak_enctype(krb5_enctype etype)
{
    const struct krb5_keytypes *ktp;

    ktp = find_enctype(etype);
    return ((ktp->flags & ETYPE_WEAK) != 0);
}
