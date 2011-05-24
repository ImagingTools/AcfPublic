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


#ifndef iser_CArchiveTag_included
#define iser_CArchiveTag_included


// STL includes
#include <string>


// ACF includes
#include "istd/istd.h"


namespace iser
{


class IArchive;


/**
	Process tag used to group data in archive stream.

	\ingroup Persistence
*/
class CArchiveTag
{
public:
	/**
		Constructor with parameter initialization.
		\param	id					ID of this tag.
		\param	comment				human readable and are used for diagnostic.
		\param	isTagSkippingUsed	true if it is needed to support tag skipping for this tag.
	*/
	CArchiveTag(	const std::string& id,
					const std::string& comment,
					bool isTagSkippingUsed = false);

	/**
		Get ID of this tag.
	*/
	const std::string& GetId() const;

	/**
		Get automatic generated binary ID.
	*/
	I_DWORD GetBinaryId() const;

	/**
		Get comment of this tag.
		Comments are human readable and are used for diagnostic.
	*/
	const std::string& GetComment() const;
	/**
		Check if it is needed to support tag skipping for this tag.
	*/
	bool IsTagSkippingUsed() const;

private:
	std::string m_id;
	I_DWORD m_binaryId;

	std::string m_comment;

	bool m_isTagSkippingUsed;
};


// inline methods

inline bool CArchiveTag::IsTagSkippingUsed() const
{
	return m_isTagSkippingUsed;
}


} // namespace iser



#endif // !iser_CArchiveTag_included



