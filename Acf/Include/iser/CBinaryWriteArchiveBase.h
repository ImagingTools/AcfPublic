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


#ifndef iser_CBinaryWriteArchiveBase_included
#define iser_CBinaryWriteArchiveBase_included


// ACF includes
#include <iser/CWriteArchiveBase.h>


namespace iser
{


/**
	Base class for archive implementations writting data based on its binary representation.
*/
class CBinaryWriteArchiveBase: public CWriteArchiveBase
{
public:
	typedef CWriteArchiveBase BaseClass;

	// reimplemented (iser::IArchive)
	virtual bool BeginTag(const CArchiveTag& tag) override;
	virtual bool EndTag(const CArchiveTag& tag) override;
	virtual bool Process(bool& value) override;
	virtual bool Process(char& value) override;
	virtual bool Process(quint8& value) override;
	virtual bool Process(qint8& value) override;
	virtual bool Process(quint16& value) override;
	virtual bool Process(qint16& value) override;
	virtual bool Process(quint32& value) override;
	virtual bool Process(qint32& value) override;
	virtual bool Process(quint64& value) override;
	virtual bool Process(qint64& value) override;
	virtual bool Process(float& value) override;
	virtual bool Process(double& value) override;
	virtual bool Process(QByteArray& value) override;
	virtual bool Process(QString& value) override;

protected:
	explicit CBinaryWriteArchiveBase(const IVersionInfo* versionInfoPtr);
};


} // namespace iser


#endif // !iser_CBinaryWriteArchiveBase_included

