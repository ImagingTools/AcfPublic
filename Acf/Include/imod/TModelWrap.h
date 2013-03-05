/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef imod_TModelWrap_included
#define imod_TModelWrap_included


#include "istd/TDelPtr.h"
#include "istd/IChangeable.h"

#include "iser/TCopySerializedWrap.h"

#include "imod/CModelBase.h"


namespace imod
{


/**
	This model wrapper provides a simple connection between a concrete
	\c istd::IChangeable implementation and a model.

	\ingroup ModelObserver
	\ingroup Helpers
*/
template <class Base>
class TModelWrap: public iser::TCopySerializedWrap<Base>, public imod::CModelBase
{
public:
	typedef iser::TCopySerializedWrap<Base> BaseClass;
	typedef imod::CModelBase BaseClass2;

	void SetBaseObject(const Base& baseObject);

	// pseudo-reimplemented (istd::IChangeable)
	virtual int GetSupportedOperations() const;
	virtual istd::IChangeable* CloneMe(istd::IChangeable::CompatibilityMode mode = istd::IChangeable::CM_WITHOUT_REFS) const;

protected:
	// pseudo-reimplemented (istd::IChangeable)
	virtual void OnBeginChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr);
	virtual void OnEndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr);
};


// public methods

template <class Base>
void TModelWrap<Base>::SetBaseObject(const Base& baseObject)
{
	Base::operator=(baseObject);
}


// pseudo-reimplemented (istd::IChangeable)

template <class Base>
int TModelWrap<Base>::GetSupportedOperations() const
{
	int baseOperations = Base::GetSupportedOperations();

	if ((baseOperations & istd::IChangeable::SO_COPY) != 0){
		return baseOperations | istd::IChangeable::SO_CLONE | istd::IChangeable::SO_OBSERVE | istd::IChangeable::SO_COMPARE;
	}
	else{
		return baseOperations | istd::IChangeable::SO_OBSERVE | istd::IChangeable::SO_COMPARE;
	}
}


template <class Base>
istd::IChangeable* TModelWrap<Base>::CloneMe(istd::IChangeable::CompatibilityMode mode) const
{
	istd::TDelPtr< TModelWrap<Base> > clonePtr(new TModelWrap<Base>());

	if (clonePtr->CopyFrom(*this, mode)){
		return clonePtr.PopPtr();
	}

	return NULL;
}


// protected methods

// pseudo-reimplemented (istd::IChangeable)

template <class Base>
void TModelWrap<Base>::OnBeginChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr)
{
	BaseClass::OnBeginChanges(changeFlags, changeParamsPtr);

	NotifyBeforeUpdate(changeFlags, changeParamsPtr);
}


template <class Base>
void TModelWrap<Base>::OnEndChanges(int changeFlags, istd::IPolymorphic* changeParamsPtr)
{
	BaseClass::OnEndChanges(changeFlags, changeParamsPtr);

	NotifyAfterUpdate(changeFlags, changeParamsPtr);
}


} // namespace imod


#endif // !imod_TModelWrap_included


