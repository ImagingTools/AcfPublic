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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef idoc_TMultiDocumentWrap_included
#define idoc_TMultiDocumentWrap_included


// ACF includes
#include "idoc/IMultiPageDocument.h"
#include "idoc/CStandardDocumentMetaInfo.h"


namespace idoc
{


/**
	Generic implementation of IMultiPageDocument interface.
*/
template <class Base, class PageInterface>
class TMultiDocumentWrap:
			virtual public Base,
			public CStandardDocumentMetaInfo
{
public:
	typedef Base BaseClass;
	typedef CStandardDocumentMetaInfo BaseClass2;
	typedef typename PageInterface PageInterface;

	const PageInterface* GetPageObject(int pageIndex) const;

	// pseudo-reimplemented (IMultiPageDocument)
	virtual int GetPagesCount() const;
	virtual const istd::IChangeable& GetDocumentPage(int pageIndex) const;
	virtual void ResetPages();
	virtual bool RemovePage(int pageIndex);
	virtual const IDocumentMetaInfo& GetDocumentMetaInfo() const;

protected:
	typedef istd::TPointerVector<PageInterface> Pages;

	Pages m_documentPages;
};


// public methods

template <class Base, class PageInterface>
const PageInterface* TMultiDocumentWrap<Base, PageInterface>::GetPageObject(int pageIndex) const
{
	Q_ASSERT(pageIndex < m_documentPages.GetCount());
	Q_ASSERT(pageIndex >= 0);

	return m_documentPages.GetAt(pageIndex);
}


// pseudo-reimplemented (IMultiPageDocument)

template <class Base, class PageInterface>
int TMultiDocumentWrap<Base, PageInterface>::GetPagesCount() const
{
	return m_documentPages.GetCount();
}


template <class Base, class PageInterface>
const istd::IChangeable& TMultiDocumentWrap<Base, PageInterface>::GetDocumentPage(int pageIndex) const
{
	return *GetPageObject(pageIndex);
}


template <class Base, class PageInterface>
void TMultiDocumentWrap<Base, PageInterface>::ResetPages()
{
	istd::CChangeNotifier changePtr(this);

	m_documentPages.Reset();
}


template <class Base, class PageInterface>
bool TMultiDocumentWrap<Base, PageInterface>::RemovePage(int pageIndex)
{
	Q_ASSERT(pageIndex < m_documentPages.GetCount());
	Q_ASSERT(pageIndex >= 0);

	istd::CChangeNotifier changePtr(this);

	m_documentPages.RemoveAt(pageIndex);

	return true;
}


template <class Base, class PageInterface>
const IDocumentMetaInfo& TMultiDocumentWrap<Base, PageInterface>::GetDocumentMetaInfo() const
{
	return *this;
}


} // namespace idoc


#endif // !idoc_TMultiDocumentWrap_included


