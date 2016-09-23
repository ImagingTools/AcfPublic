/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef ifileproc_CFileNamingParams_included
#define ifileproc_CFileNamingParams_included


// Qt includes
#include <QtCore/QStringList>

// ACF includes
#include <icomp/CComponentBase.h>

// AcfSln includes
#include <ifileproc/IFileNamingParams.h>


namespace ifileproc
{


class CFileNamingParams: virtual public ifileproc::IFileNamingParams
{
public:
	CFileNamingParams();

	// reimplemented (ifileproc::IFileNamingParams)
	virtual OverwriteStrategy GetOverwriteStrategy() const;
	virtual void SetOverwriteStrategy(OverwriteStrategy overwriteStrategy);
	virtual QString GetPrefix() const;
	virtual void SetPrefix(const QString& prefix);
	virtual QString GetSuffix() const;
	virtual void SetSuffix(const QString& suffix);
	virtual QStringList GetPatternsToRemove() const;
	virtual void SetPatternsToRemove(const QStringList& patternsToRemove);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	// reimplemented (istd::IChangeable)
	virtual int GetSupportedOperations() const;
	virtual bool CopyFrom(const istd::IChangeable& object, istd::IChangeable::CompatibilityMode mode = istd::IChangeable::CM_WITHOUT_REFS);
	virtual bool IsEqual(const istd::IChangeable& object) const;
	virtual istd::IChangeable* CloneMe(istd::IChangeable::CompatibilityMode mode = istd::IChangeable::CM_WITHOUT_REFS) const;
	virtual bool ResetData(CompatibilityMode mode = CM_WITHOUT_REFS);

protected:
	OverwriteStrategy m_overwriteStrategy;
	QString m_suffix;
	QString m_prefix;
	QStringList m_patternsToRemove;
};


} // namespace ifileproc


#endif // !ifileproc_CFileNamingParams_included


