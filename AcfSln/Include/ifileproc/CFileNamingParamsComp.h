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


#ifndef ifileproc_CFileNamingParamsComp_included
#define ifileproc_CFileNamingParamsComp_included


// Qt includes
#include <QStringList>

// ACF includes
#include "icomp/CComponentBase.h"

// AcfSln includes
#include "ifileproc/IFileNamingParams.h"


namespace ifileproc
{


class CFileNamingParamsComp:
			public icomp::CComponentBase,
			virtual public ifileproc::IFileNamingParams
{
public:
	typedef icomp::CComponentBase BaseClass;

	CFileNamingParamsComp();

	I_BEGIN_COMPONENT(ifileproc::CFileNamingParamsComp);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(ifileproc::IFileNamingParams);
		I_ASSIGN(m_prefixAttrPtr, "Prefix", "Prefix attached to the output file name", true, "");
		I_ASSIGN(m_suffixAttrPtr, "Suffix", "Suffix attached to the output file name", true, "");
		I_ASSIGN(m_overwriteStrategyAttrPtr, "OverwriteStrategy", "Strategy for overwriting of existing files.\n0 - Overwrite existing file\n1 - Add auto generated numbered suffix to the output file name", true, 0);
		I_ASSIGN_MULTI_0(m_patternsToRemoveAttrPtr, "PatternsToRemove", "List of patterns that will be removed from the output file name", false);
	I_END_COMPONENT;

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

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	OverwriteStrategy m_overwriteStrategy;
	QString m_suffix;
	QString m_prefix;
	QStringList m_patternsToRemove;

	I_ATTR(QString, m_prefixAttrPtr);
	I_ATTR(QString, m_suffixAttrPtr);
	I_ATTR(int, m_overwriteStrategyAttrPtr);
	I_MULTIATTR(QString, m_patternsToRemoveAttrPtr);
};


} // namespace ifileproc


#endif // !ifileproc_CFileNamingParamsComp_included


