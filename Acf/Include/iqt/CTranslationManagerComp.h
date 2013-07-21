/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqt_CTranslationManagerComp_included
#define iqt_CTranslationManagerComp_included


// Qt includes
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QTranslator>

// ACF includes
#include "istd/TPointerVector.h"

#include "icomp/CComponentBase.h"

#include "imod/TSingleModelObserverBase.h"

#include "iprm/ISelectionParam.h"
#include "iprm/IOptionsList.h"

#include "iqt/ITranslationManager.h"

#include "ilog/TLoggerCompWrap.h"


namespace iqt
{


class CTranslationManagerComp:
			public ilog::CLoggerComponentBase, 
			virtual public iqt::ITranslationManager,
			virtual public iprm::IOptionsList
{
public:
	typedef ilog::CLoggerComponentBase BaseClass;

	I_BEGIN_COMPONENT(CTranslationManagerComp);
		I_REGISTER_INTERFACE(iqt::ITranslationManager);
		I_REGISTER_INTERFACE(iprm::IOptionsList);
		I_ASSIGN(m_translationFilePathAttrPtr, "TranslationFilePath", "Base file path got translations", true, "");
		I_ASSIGN(m_translationFilePrefixAttrPtr, "TranslationFilePrefix", "Prefix of the translation file", true, "");
		I_ASSIGN_MULTI_0(m_languagesAttrPtr, "LanguageIds", "List of language IDs in ISO-format", true);
		I_ASSIGN(m_slaveTranslationManagerCompPtr, "SlaveTranslationManager", "Slave translation manager", false, "SlaveTranslationManager");
		I_ASSIGN(m_languageSelectionCompPtr, "LanguageSelection", "Language selection provider", false, "LanguageSelection");
		I_ASSIGN_TO(m_languageSelectionModelCompPtr, m_languageSelectionCompPtr, false);
	I_END_COMPONENT;

	CTranslationManagerComp();

	// reimplemented (icomp:CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

	// reimplemented (iqt::ITranslationManager)
	virtual int GetLanguagesCount() const;
	virtual int GetCurrentLanguageIndex() const;
	virtual const QTranslator* GetLanguageTranslator(int languageIndex) const;
	virtual const ITranslationManager* GetSlaveTranslationManager() const;
	virtual void SwitchLanguage(int languageIndex);
	virtual void SetSystemLanguage();

	// reimplemented (iprm::IOptionsList)
	virtual int GetOptionsFlags() const;
	virtual int GetOptionsCount() const;
	virtual QString GetOptionName(int index) const;
	virtual QString GetOptionDescription(int index) const;
	virtual QByteArray GetOptionId(int index) const;
	virtual bool IsOptionEnabled(int index) const;

private:
	class LanguageSelectionObserver: public imod::TSingleModelObserverBase<iprm::ISelectionParam>
	{
	public:
		LanguageSelectionObserver(CTranslationManagerComp& parent);

	protected:
		// reimplemented (imod::CSingleModelObserverBase)
		virtual void OnUpdate(int updateFlags, istd::IPolymorphic* updateParamsPtr);

	private:
		CTranslationManagerComp& m_parent;
	};

private:
	I_ATTR(QString, m_translationFilePathAttrPtr);
	I_ATTR(QByteArray, m_translationFilePrefixAttrPtr);
	I_MULTIATTR(QByteArray, m_languagesAttrPtr);
	I_REF(iqt::ITranslationManager, m_slaveTranslationManagerCompPtr);
	I_REF(iprm::ISelectionParam, m_languageSelectionCompPtr);
	I_REF(imod::IModel, m_languageSelectionModelCompPtr);

	typedef istd::TPointerVector<QTranslator> TranslatorsList;

	TranslatorsList m_translatorsList;

	LanguageSelectionObserver m_selectionObserver;

	int m_currentLanguageIndex;
};


} // namespace iqt


#endif // !iqt_CTranslationManagerComp_included


