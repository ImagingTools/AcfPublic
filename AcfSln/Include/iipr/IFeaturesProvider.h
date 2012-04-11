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


#ifndef iipr_IFeaturesProvider_included
#define iipr_IFeaturesProvider_included


// Qt includes
#include <QtCore/QVector>

// ACF includes
#include "istd/IChangeable.h"


namespace iipr
{


class IFeature;


/**
	Common interface for someone who can provide access to list of features.
*/
class IFeaturesProvider: virtual public istd::IChangeable
{
public:
	typedef QVector<const iipr::IFeature*> Features;

	/**
		Get container features.
	*/
	virtual Features GetFeatures() const = 0;
};


} // namespace iipr


#endif // !iipr_IFeaturesProvider_included

