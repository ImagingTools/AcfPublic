/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iipr_TFeatureWrap_included
#define iipr_TFeatureWrap_included


// ACF includes
#include "istd/TChangeNotifier.h"

// IACF includes
#include "iipr/CFeatureBase.h"


namespace iipr
{


/**
	Wrapper allowing to create feature object from some another serializable one.
*/
template <class BaseObject>
class TFeatureWrap:
			public CFeatureBase,
			public BaseObject
{
public:
	typedef CFeatureBase BaseClass;
	typedef BaseObject BaseClass2;

	TFeatureWrap(double weight = 1.0);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);
};


// public methods

template <class BaseObject>
TFeatureWrap<BaseObject>::TFeatureWrap(double weight)
:	BaseClass(weight)
{
}


// reimplemented (iser::ISerializable)

template <class BaseObject>
bool TFeatureWrap<BaseObject>::Serialize(iser::IArchive& archive)
{
	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this);

	bool retVal = true;

	retVal = retVal && BaseClass::Serialize(archive);
	retVal = retVal && BaseClass2::Serialize(archive);

	return retVal;
}


} // namespace iipr


#endif // !iipr_TFeatureWrap_included


