/******************************************************************************
 *                                                                            *
 * This program is distributed in the hope that it will be useful, but        *
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY *
 * or FITNESS FOR A PARTICULAR PURPOSE. This file and program are licensed    *
 * under the GNU Lesser General Public License Version 3, 29 June 2007.       *
 * The complete license can be accessed from the following location:          *
 * http://opensource.org/licenses/lgpl-3.0.html                               *
 *                                                                            *
 * Author: Gavin Ding     (gavin_ding@sina.cn / fanfan.ding.ict@gmail.com)    *
 *   Date: 07/14/2013                                                         *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
  REVISION HISTORY
  ================
  
  Date         Version       Name              Description
  ----------   ------------  ----------------  --------------------------------
  
  ----------   ------------  ----------------  --------------------------------

 ******************************************************************************/
 
#include "unitest.h"
#include "atom.h"

#ifndef UNUSED(param)
#define UNUSED(param) (param) = (param)
#endif

int unitest_main(int argc, char *argv[])
{ 
    UNUSED(argc);
    UNUSED(argv);
    
    UNITEST_EQUALS(1, 1);
    
    return 0;
}

