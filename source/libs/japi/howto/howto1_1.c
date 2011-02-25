/*___INFO__MARK_BEGIN__*/
/*************************************************************************
 * 
 *  The Contents of this file are made available subject to the terms of
 *  the Sun Industry Standards Source License Version 1.2
 * 
 *  Sun Microsystems Inc., March, 2001
 * 
 * 
 *  Sun Industry Standards Source License Version 1.2
 *  =================================================
 *  The contents of this file are subject to the Sun Industry Standards
 *  Source License Version 1.2 (the "License"); You may not use this file
 *  except in compliance with the License. You may obtain a copy of the
 *  License at http://gridengine.sunsource.net/Gridengine_SISSL_license.html
 * 
 *  Software provided under this License is provided on an "AS IS" basis,
 *  WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING,
 *  WITHOUT LIMITATION, WARRANTIES THAT THE SOFTWARE IS FREE OF DEFECTS,
 *  MERCHANTABLE, FIT FOR A PARTICULAR PURPOSE, OR NON-INFRINGING.
 *  See the License for the specific provisions governing your rights and
 *  obligations concerning the Software.
 * 
 *   The Initial Developer of the Original Code is: Sun Microsystems, Inc.
 * 
 *   Copyright: 2001 by Sun Microsystems, Inc.
 * 
 *   All Rights Reserved.
 * 
 ************************************************************************/
/*___INFO__MARK_END__*/
#include <stdio.h>
#include "drmaa.h"

int main (int argc, char **argv) {
   char error[DRMAA_ERROR_STRING_BUFFER];
   int errnum = 0;
   char contact[DRMAA_CONTACT_BUFFER];

   errnum = drmaa_init (NULL, error, DRMAA_ERROR_STRING_BUFFER);

   if (errnum != DRMAA_ERRNO_SUCCESS) {
      fprintf (stderr, "Could not initialize the DRMAA library: %s\n", error);
      return 1;
   }

   printf ("DRMAA library was started successfully\n");

   errnum = drmaa_get_contact (contact, DRMAA_CONTACT_BUFFER, error,
                               DRMAA_ERROR_STRING_BUFFER);
   
   if (errnum != DRMAA_ERRNO_SUCCESS) {
      fprintf (stderr, "Could not get the contact string: %s\n", error);
      return 1;
   }

   errnum = drmaa_exit (error, DRMAA_ERROR_STRING_BUFFER);

   if (errnum != DRMAA_ERRNO_SUCCESS) {
      fprintf (stderr, "Could not shut down the DRMAA library: %s\n", error);
      return 1;
   }

   errnum = drmaa_init (contact, error, DRMAA_ERROR_STRING_BUFFER);

   if (errnum != DRMAA_ERRNO_SUCCESS) {
      fprintf (stderr, "Could not reinitialize the DRMAA library: %s\n", error);
      return 1;
   }

   printf ("DRMAA library was restarted successfully\n");

   errnum = drmaa_exit (error, DRMAA_ERROR_STRING_BUFFER);

   if (errnum != DRMAA_ERRNO_SUCCESS) {
      fprintf (stderr, "Could not shut down the DRMAA library: %s\n", error);
      return 1;
   }

   return 0;
}
