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


#ifndef iprm_IParameterStateProvider_included
#define iprm_IParameterStateProvider_included


// Qt includes
#include <QtCore/QByteArray>
#include <QtCore/QList>


// ACF includes
#include <istd/IChangeable.h>


namespace iprm
{


class IParamsSet;


/**
	Provider of the state information for a parameter inside of the parameter set.
*/
class IParameterStateProvider: virtual public istd::IChangeable
{
public:
	enum StateType
	{
		/**
			Get the "edit" status of the parameter.
		*/
		ST_EDIT
	};

	enum ParameterState
	{
		PS_UNKNOWN,
		PS_TRUE,
		PS_FALSE
	};

	/**
		Return state for the given parameter.
	*/
	virtual ParameterState GetState(
				const iprm::IParamsSet& paramSet,
				const QByteArray& parameterId,
				StateType stateType) const = 0;
};


} // namespace iprm


#endif // !iprm_IParameterStateProvider_included


