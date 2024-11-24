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


#pragma once


// Qt includes
#include <QtCore/QObject>
#include <QtTest/QtTest>

// ACF includes
#include <iser/CJsonMemReadArchive.h>
#include <iser/ISerializable.h>
#include <iser/IArchive.h>
#include <iser/CArchiveTag.h>


class CJsonMemoryReadArchiveTest: public QObject
{
	Q_OBJECT

private Q_SLOTS:
	void DoTest();

private:
	class Model: virtual public iser::ISerializable
	{
	public:
		virtual bool Serialize(iser::IArchive& archive) override
		{
			static iser::CArchiveTag typeTag("Type", "Type of the meta information");
			bool retVal = archive.BeginTag(typeTag);
			retVal = retVal && archive.Process(value);
			retVal = retVal && archive.EndTag(typeTag);

			return retVal;
		}

		int value = 42;
	};
};


