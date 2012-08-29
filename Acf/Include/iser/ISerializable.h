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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iser_ISerializable_included
#define iser_ISerializable_included


// ACF includes
#include "istd/IChangeable.h"

#include "iser/IVersionInfo.h"


namespace iser
{


class IArchive;


/**
	Common class for all classes which objects can be archived or restored from archive.

	\ingroup Persistence
	\ingroup Main
*/
class ISerializable: virtual public istd::IChangeable
{
public:
	/**
		Load or store state of this object as a archive stream.
		Type of operation is depending on archive type.
		\sa iser::IArchive
	*/
	virtual bool Serialize(IArchive& archive) = 0;
	/**
		Get minimal needed version to correct storing of this data.
		In implementation shold be calculated maximum version of this and composed component.
	*/
	virtual quint32 GetMinimalVersion(int versionId) const;
};


// inline methods

inline quint32 ISerializable::GetMinimalVersion(int /*versionId*/) const
{
	return 0;
}


} // namespace iser


#endif // !iser_ISerializable_included


