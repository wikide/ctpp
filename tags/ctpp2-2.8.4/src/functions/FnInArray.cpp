/*-
 * Copyright (c) 2004 - 2014 CTPP Team
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the CTPP Team nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *      FnInArray.cpp
 *
 * $CTPP$
 */

#include "CDT.hpp"
#include "CTPP2Logger.hpp"
#include "FnInArray.hpp"

namespace CTPP // C++ Template Engine
{

//
// Constructor
//
FnInArray::FnInArray()
{
	;;
}

//
// Handler
//
INT_32 FnInArray::Handler(CDT            * aArguments,
                        const UINT_32    iArgNum,
                        CDT            & oCDTRetVal,
                        Logger         & oLogger)
{
	// Only 2 args allowed
	if (iArgNum != 2)
	{
		oLogger.Emerg("Usage: IN_ARRAY(x, array)");
		return -1;
	}

	// Second argument *MUST* be an ARRAY
    if (aArguments[0].GetType() == CDT::UNDEF)
    {
        oCDTRetVal = 0;
        return 0;
    }
    else if (aArguments[0].GetType() != CDT::ARRAY_VAL)
	{
        oLogger.Error("Second argument MUST be ARRAY");
        return -1;
	}

	INT_32 iSize = aArguments[0].Size();
	for (INT_32 iI = 0; iI < iSize; ++iI)
	{
		if (aArguments[1].Equal(aArguments[0][iI]))
		{
			oCDTRetVal = 1;
			return 0;
		}
	}

	oCDTRetVal = 0;
return 0;
}

//
// Get function name
//
CCHAR_P FnInArray::GetName() const { return "in_array"; }

//
// A destructor
//
FnInArray::~FnInArray() throw() { ;; }

} // namespace CTPP
// End.
