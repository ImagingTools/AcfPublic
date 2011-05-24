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


#ifndef ifpf_CHotfolderProcessingItem_included
#define ifpf_CHotfolderProcessingItem_included


// ACF includes
#include "imod/TModelWrap.h"

#include "isys/CSimpleDateTime.h"


// AcfSln includes
#include "ifpf/IHotfolderProcessingItem.h"


namespace ifpf
{


/**
	Interface for a single processing item in the hotfolder.
*/
class CHotfolderProcessingItem: virtual public ifpf::IHotfolderProcessingItem
{
public:
	CHotfolderProcessingItem();

	// reimplemented (ifpf::IHotfolderProcessingItem)
	virtual std::string GetItemUuid() const;
	virtual int GetProcessingState() const;
	virtual void SetProcessingState(int processingState);
	virtual istd::CString GetInputFile() const;
	virtual void SetInputFile(const istd::CString& inputFile);
	virtual istd::CString GetOutputFile() const;
	virtual void SetOutputFile(const istd::CString& outputFile);
	virtual double GetProcessingTime() const;
	virtual void SetProcessingTime(double processingTime);
	virtual const isys::IDateTime& GetStartTime() const;
	virtual void SetStartTime(const isys::IDateTime& startTime);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	istd::CString m_inputFile;
	istd::CString m_outputFile;
	int m_processingState;
	double m_processingTime;
	isys::CSimpleDateTime m_startTime;

	mutable std::string m_itemId;
};


} // namespace ifpf


#endif // !ifpf_CHotfolderProcessingItem_included


