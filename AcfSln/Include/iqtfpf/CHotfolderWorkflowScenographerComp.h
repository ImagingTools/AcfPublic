/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iqtfpf_CHotfolderWorkflowScenographerComp_included
#define iqtfpf_CHotfolderWorkflowScenographerComp_included


// ACF includes
#include "imod/TSingleModelObserverBase.h"


#include "i2d/CVector2d.h"

#include "iqt2d/TScenographerCompBase.h"
#include "iqt2d/CSceneProviderGuiComp.h"


// AcfSln includes
#include "ifpf/IHotfolderWorkflow.h"


namespace iqtfpf
{


/**
	Hotfolder workflow user interface.
*/
class CHotfolderWorkflowScenographerComp:
			public QObject,
			public iqt2d::TScenographerCompBase<
						imod::TSingleModelObserverBase<ifpf::IHotfolderWorkflow> >
{
	Q_OBJECT
public:
	typedef iqt2d::TScenographerCompBase<
				imod::TSingleModelObserverBase<ifpf::IHotfolderWorkflow> > BaseClass;

	I_BEGIN_COMPONENT(CHotfolderWorkflowScenographerComp);
	I_END_COMPONENT();

	CHotfolderWorkflowScenographerComp();

protected:
	bool TryCreateHotfolder(const istd::CString& hofolderId, const i2d::CVector2d& position);
	QGraphicsItem* CHotfolderWorkflowScenographerComp::AddShapeToScene(istd::IPolymorphic* elementPtr) const;

	// reimplemented (iqt2d::TScenographerCompBase)
	virtual bool OnDropObject(const QMimeData& mimeData, QGraphicsSceneDragDropEvent* eventPtr);
	virtual void UpdateScene(int updateFlags);
};


} // namespace iqtfpf


#endif // !iqtfpf_CHotfolderWorkflowScenographerComp_included


