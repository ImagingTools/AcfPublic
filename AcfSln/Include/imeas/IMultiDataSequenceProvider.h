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


#ifndef imeas_IMultiDataSequenceProvider_included
#define imeas_IMultiDataSequenceProvider_included


// ACF includes
#include "imeas/IDataSequenceProvider.h"


namespace imeas
{


/**
	Interface for a provider of more data sequence objects.
*/
class IMultiDataSequenceProvider: virtual public istd::IChangeable
{
public:
	/**
		Get the number of available data sequences.
	*/
	virtual int GetSequencesCount() const = 0;

	/**
		Get data sequence with the given index.
	*/
	virtual const imeas::IDataSequence* GetDataSequence(int index) const = 0;
};


} // namespace imeas


#endif // !imeas_IMultiDataSequenceProvider_included


