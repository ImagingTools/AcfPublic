/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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


#ifndef imebase_CChannelSelectionNode_included
#define imebase_CChannelSelectionNode_included


#include <istd/TDelPtr.h>
#include <istd/TPointerVector.h>

#include <iser/CArchiveTag.h>

#include <iprm/ISelectionParam.h>
#include <iprm/IOptionsList.h>

#include <imebase.h>


namespace imebase
{


class CChannelSelectionNode:
			virtual public iprm::ISelectionParam,
			virtual public iprm::IOptionsList
{
public:
	CChannelSelectionNode();

	/**
		Insert new node at the end of selection list.
		This node will be automatically deleted during destruction.
	*/
	void InsertNode(const QString& name, int physicalAddress, CChannelSelectionNode* nodePtr);
	/**
		Get physical address associated with active selection.
	*/
	int GetActivePhysicalAddress() const;

	/**
		Remove all option nodes.
	*/
	void ResetNodes();

	// reimplemented (iprm::ISelectionParam)
	virtual const iprm::IOptionsList* GetSelectionConstraints() const;
	virtual int GetSelectedOptionIndex() const;
	virtual bool SetSelectedOptionIndex(int index);
	virtual iprm::ISelectionParam* GetSubselection(int index) const;

	// reimplemented (iprm::IOptionsList)
	virtual int GetOptionsFlags() const;
	virtual int GetOptionsCount() const;
	virtual QString GetOptionName(int index) const;
	virtual QString GetOptionDescription(int index) const;
	virtual QByteArray GetOptionId(int index) const;
	virtual bool IsOptionEnabled(int index) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	int CalcSelectionDepth() const;
	bool SerializeNode(iser::IArchive& archive, const iser::CArchiveTag& nodeTag, int count);

private:
	struct SelectionInfo
	{
		QString name;
		istd::TDelPtr<ISelectionParam> selectionPtr;
		int physicalIndex;
	};

	istd::TPointerVector<SelectionInfo> m_subselections;
	int m_selectedIndex;
};

	
} // namespace imebase


#endif // !imebase_CChannelSelectionNode_included


