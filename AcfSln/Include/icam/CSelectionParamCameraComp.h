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


#ifndef iprm_CSelectionParamCameraComp_included
#define iprm_CSelectionParamCameraComp_included


// Qt includes
#include <QtCore/QMap>

// ACF includes
#include "istd/TDelPtr.h"
#include <QtCore/QString>
#include "iprm/IParamsManager.h"

// ACF-Solutions include
#include "icam/CCameraDelegatorBase.h"


namespace icam
{


class CSelectionParamCameraComp: public CCameraDelegatorBase
{
public:
	typedef CCameraDelegatorBase BaseClass;

	I_BEGIN_COMPONENT(CSelectionParamCameraComp);
		I_ASSIGN(m_selectionIdAttrPtr, "SelectionId", "ID of selection in parameter set", true, "Input");
		I_ASSIGN(m_defaultIndexAttrPtr, "DefaultIndex", "Default selected index, if negative no selected parameter ID will be used", true, 0);
		I_ASSIGN(m_paramsManagerCompPtr, "ParamsManager", "Manager of parameter set used to realize selection", true, "ParamsManager");
	I_END_COMPONENT;

	// reimplemented (iipr::IBitmapAcquisition)
	virtual istd::CIndex2d GetBitmapSize(const iprm::IParamsSet* paramsPtr) const;

	// reimplemented (iproc::IProcessor)
	virtual int GetProcessorState(const iprm::IParamsSet* paramsPtr) const;
	virtual bool AreParamsAccepted(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				const istd::IChangeable* outputPtr) const;
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				iproc::IProgressManager* progressManagerPtr = NULL);
	virtual int BeginTask(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				iproc::IProgressManager* progressManagerPtr = NULL);
	virtual int WaitTaskFinished(
					int taskId = -1,
					double timeoutTime = -1,
					bool killOnTimeout = true);
	virtual void CancelTask(int taskId = -1);
	virtual void InitProcessor(const iprm::IParamsSet* paramsPtr);

protected:
	const iprm::IParamsSet* CreateParamsSet(const iprm::IParamsSet* paramsPtr) const;

	class JoinParamsSet: virtual public iprm::IParamsSet
	{
	public:
		JoinParamsSet(const iprm::IParamsSet* origParamsPtr, const iprm::IParamsSet* selectedParamsPtr);

		// reimplemented (iprm::IParamsSet)
		virtual const iser::ISerializable* GetParameter(const QByteArray& id) const;
		virtual iser::ISerializable* GetEditableParameter(const QByteArray& id);

		// reimplemented (iser::ISerializable)
		virtual bool Serialize(iser::IArchive& archive);

	private:
		const iprm::IParamsSet* m_origParamsPtr;
		const iprm::IParamsSet* m_selectedParamsPtr;
	};

private:
	I_ATTR(QByteArray, m_selectionIdAttrPtr);
	I_ATTR(int, m_defaultIndexAttrPtr);
	I_REF(iprm::IParamsManager, m_paramsManagerCompPtr);

	typedef istd::TDelPtr<const iprm::IParamsSet> ParamSetPtr;
	/**
		Map task ID to parameter set.
	*/
	typedef QMap<int, ParamSetPtr> ParamsMap;

	ParamsMap m_paramsMap;
};


} // namespace icam


#endif // !iprm_CSelectionParamCameraComp_included


