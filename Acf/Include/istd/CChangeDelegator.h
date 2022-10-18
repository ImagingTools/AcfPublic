/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef istd_CChangeDelegator_included
#define istd_CChangeDelegator_included


// ACF includes
#include <istd/IChangeDelegator.h>


namespace istd
{


/**
	Delegates calls of IChangeable methods to the given slave.

	\ingroup DataModel
*/
class CChangeDelegator: virtual public IChangeDelegator
{
public:
	typedef istd::IChangeable BaseClass;

	CChangeDelegator();
	explicit CChangeDelegator(istd::IChangeable* slavePtr);

	// reimplemented (istd::IChangeDelegator)
	virtual void SetSlavePtr(istd::IChangeable* slavePtr);
	virtual istd::IChangeable* GetSlavePtr() const;

	// reimplemented (istd::IChangeable)
	virtual void OnBeginChanges();
	virtual void OnEndChanges(const ChangeSet& changeSet);
	
private:
	istd::IChangeable* m_slavePtr;
};


// inline methods

inline void CChangeDelegator::SetSlavePtr(istd::IChangeable* slavePtr)
{
	m_slavePtr = slavePtr;
}


inline istd::IChangeable* CChangeDelegator::GetSlavePtr() const
{
	return m_slavePtr;
}


} // namespace istd


#endif // !istd_CChangeDelegator_included

