/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
**
**	This file may be used under the terms of the GNU Lesser
**	General Public License version 2.1 as published by the Free Software
**	Foundation and appearing in the file LicenseLGPL.txt included in the
**	packaging of this file.  Please review the following information to
**	ensure the GNU Lesser General Public License version 2.1 requirements
**	will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef isys_CSectionBlocker_included
#define isys_CSectionBlocker_included


#include "istd/istd.h"
#include "isys/ICriticalSection.h"


namespace isys
{


/**
	Simple helper class entering critical section during object construction and leaving it during destruction.
*/
class CSectionBlocker
{
public:
	CSectionBlocker(const isys::ICriticalSection* sectionPtr);
	~CSectionBlocker();

	void Reset();

private:
	const isys::ICriticalSection* m_sectionPtr;
};


// public inline methods

inline CSectionBlocker::CSectionBlocker(const isys::ICriticalSection* sectionPtr)
:	m_sectionPtr(sectionPtr)
{
	I_ASSERT(m_sectionPtr != NULL);
	if (m_sectionPtr != NULL){
		(const_cast<isys::ICriticalSection*>(m_sectionPtr))->Enter();
	}
}


inline CSectionBlocker::~CSectionBlocker()
{
	Reset();
}


inline void CSectionBlocker::Reset()
{	
	if (m_sectionPtr != NULL){
		(const_cast<isys::ICriticalSection*>(m_sectionPtr))->Leave();
	}

	m_sectionPtr = NULL;
}


} // namespace isys


#endif // !isys_CSectionBlocker_included


