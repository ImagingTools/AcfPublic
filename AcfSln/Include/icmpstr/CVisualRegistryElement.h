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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef icmpstr_CVisualRegistryElement_included
#define icmpstr_CVisualRegistryElement_included


// Qt includes
#include <QtGui/QIcon>


// ACF includes
#include "i2d/CObject2dBase.h"

#include "icomp/IRegistry.h"
#include "icomp/CComponentAddress.h"
#include "icomp/CRegistryElement.h"

#include "icmpstr/icmpstr.h"


namespace icmpstr
{


class CVisualRegistryElement: public icomp::CRegistryElement, public i2d::CObject2dBase
{
public:
	typedef icomp::CRegistryElement BaseClass;

	CVisualRegistryElement();

	const icomp::IRegistry* GetRegistry() const;
	const icomp::CComponentAddress& GetAddress() const;
	const QByteArray& GetName() const;
	void SetName(const QByteArray& name);
	const QString& GetNote() const;
	void SetNote(const QString& note);

	// overloaded (icomp::CRegistryElement)
	void Initialize(
				const icomp::IRegistry* parentPtr,
				const icomp::CComponentAddress& address);

	// reimplemented (i2d::IObject2d)
	virtual i2d::CVector2d GetCenter() const;
	virtual void MoveCenterTo(const i2d::CVector2d& position);
	virtual i2d::CRectangle GetBoundingBox() const;
	virtual bool Transform(
				const i2d::ITransformation2d& transformation,
				i2d::ITransformation2d::ExactnessMode mode = i2d::ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL);
	virtual bool InvTransform(
				const i2d::ITransformation2d& transformation,
				i2d::ITransformation2d::ExactnessMode mode = i2d::ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL);
	virtual bool GetTransformed(
				const i2d::ITransformation2d& transformation,
				i2d::IObject2d& result,
				i2d::ITransformation2d::ExactnessMode mode = i2d::ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL) const;
	virtual bool GetInvTransformed(
				const i2d::ITransformation2d& transformation,
				i2d::IObject2d& result,
				i2d::ITransformation2d::ExactnessMode mode = i2d::ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL) const;

private:
	i2d::CVector2d m_center;
	const icomp::IRegistry* m_registryPtr;
	icomp::CComponentAddress m_address;
	QByteArray m_name;
	QString m_note;
};


// inline methods

inline const icomp::IRegistry* CVisualRegistryElement::GetRegistry() const
{
	return m_registryPtr;
}


inline const icomp::CComponentAddress& CVisualRegistryElement::GetAddress() const
{
	return m_address;
}


inline const QByteArray& CVisualRegistryElement::GetName() const
{
	return m_name;
}


} // namespace icmpstr


#endif //!icmpstr_CVisualRegistryElement_included


