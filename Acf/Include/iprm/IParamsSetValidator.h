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


// ACF includes
#include <ilog/IMessageConsumer.h>


namespace iprm
{


class IParamsSet;


/**
	Interface for consistency checking of a parameter set.
*/
class IParamsSetValidator: virtual public istd::IPolymorphic
{
public:
	typedef QSet<QByteArray> Ids;

	/**
		Get list of parameter type IDs which can be checked by the validator.
	*/
	virtual Ids	GetSupportedTypeIds() const = 0;

	/**
		Return \c true if the parameter set is consistent or \c false otherwise.
		\param validationContextId				ID of the validation context
		\param paramsSet						Parameter set to be validated
		\param validationMessagesConsumerPtr	(optional) Consumer for validation messages.
	*/
	virtual bool IsParamsSetConsistent(
				const QByteArray& validationContextId,
				const IParamsSet& paramsSet,
				ilog::IMessageConsumer* validationMessagesConsumerPtr = NULL) const = 0;
};


} // namespace iprm


