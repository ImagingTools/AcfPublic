/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


#ifndef isvn_AcfVersion_included
#define isvn_AcfVersion_included


namespace istd
{


enum RepositoryState
{
	RS_ORIGINAL_VERSION =  283,
	RS_DIRTY_FLAG = 0,
	RS_USE_VERSION = RS_ORIGINAL_VERSION + RS_DIRTY_FLAG
};


} // namespace istd


#endif // !isvn_AcfVersion_included


