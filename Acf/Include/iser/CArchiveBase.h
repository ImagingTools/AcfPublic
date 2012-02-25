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


#ifndef iser_CArchiveBase_included
#define iser_CArchiveBase_included


#include <QObject>


// ACF includes
#include "istd/ILogger.h"

#include "iser/IArchive.h"
#include "iser/CArchiveTag.h"


namespace iser
{


/**
	Base implementation of iser::IArchive interface.
	It provides standard implementation of some methods and standard tags.
*/
class CArchiveBase:
			public QObject,
			virtual public IArchive,
			virtual protected istd::ILogger
{
public:
	// reimplemented (iser::IArchive)
	virtual bool IsTagSkippingSupported() const;
	virtual bool BeginMultiTag(const CArchiveTag& tag, const CArchiveTag& subTag, int& count);

	static const CArchiveTag& GetAcfRootTag();

protected:
	CArchiveBase(){}

	// list of standard tags used to serialize header
	static CArchiveTag s_acfRootTag;

private:
	/**
		Block of copy contructor for all derrived classes.
	*/
	CArchiveBase(const CArchiveBase&){}
};


} // namespace iser


#endif // !iser_CArchiveBase_included


