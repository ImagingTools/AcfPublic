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


#ifndef istd_CChangeDelegator_included
#define istd_CChangeDelegator_included


#include "istd/IChangeable.h"


namespace istd
{


/**
	Delegates calls of IChangeable methods to the given slave.
*/
class CChangeDelegator: virtual public istd::IChangeable
{
public:
	typedef istd::IChangeable BaseClass;

	CChangeDelegator();
	explicit CChangeDelegator(istd::IChangeable* slavePtr);

	/**
		Sets the slave object pointer. 
		Its IChangeable methods will be called, if this object is updated.
	*/
	virtual void SetSlavePtr(istd::IChangeable* slavePtr);

	/**
		Gets the slave object pointer. 
	*/
	virtual istd::IChangeable* GetSlavePtr() const;

	// reimplemented (istd::IChangeable)
	virtual void BeginChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr = NULL);
	virtual void EndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr = NULL);
	
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

