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


#ifndef icomp_IElementStaticInfo_included
#define icomp_IElementStaticInfo_included


// Qt includes
#include <QtCore/QByteArray>
#include <QtCore/QSet>

// ACF includes
#include "istd/IPolymorphic.h"


namespace icomp
{


/**
	This interface provide static information about element meta info.
	Elements are defined as weaker abstraction of components, without attributes etc.
	\ingroup ComponentConcept
*/
class IElementStaticInfo: virtual public istd::IPolymorphic
{
public:
	enum MetaGroupId
	{
		/**
			ID of meta group storing list of supported interfaces.
		*/
		MGI_INTERFACES = 0,
		/**
			ID of group for component subelements.
		*/
		MGI_SUBELEMENTS,
		/**
			Last used ID.
		*/
		MGI_LAST = MGI_SUBELEMENTS
	};

	typedef QSet<QByteArray> Ids;

	/**
		Return number of interfaces for specific slot.
		\param	subcomponentId	ID of subcomponent.
								\sa	GetMetaIds() and MGI_SUBELEMENTS.
	*/
	virtual const IElementStaticInfo* GetSubelementInfo(const QByteArray& subcomponentId) const = 0;

	/**
		Get list of meta IDs associated with some meta key.
		\sa MetaGroupId
	*/
	virtual Ids GetMetaIds(int metaGroupId) const = 0;
};


} // namespace icomp


#endif // !icomp_IElementStaticInfo_included


