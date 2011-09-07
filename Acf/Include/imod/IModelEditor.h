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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef imod_IModelEditor_included
#define imod_IModelEditor_included


#include "istd/IPolymorphic.h"

#include "imod/imod.h"


namespace imod
{

/**
	Common interface for an model editor.

	\ingroup ModelObserver
*/
class IModelEditor: virtual public istd::IPolymorphic
{
public:
	enum ChangeFlags
	{
		/**
			Called at begin of editor initialization.
		*/
		CF_INIT_EDITOR = 1 << 4
	};

	/**
		Updates editor with model data.
		This method will be called only if GUI is connected.
		\param	updateFlags	the same as \c changeFlag in istd::IChangeable.
	*/
	virtual void UpdateEditor(int updateFlags = 0) = 0;

	/**
		Updates model from editor.
		This method will be called only if GUI is connected and model is attached.
	*/
	virtual void UpdateModel() const = 0;

	/**
		Returns \c true if the model data can be changed.
	*/
	virtual bool IsReadOnly() const = 0;

	/**
		Set flag that the model data can be changed.
		\return	true, if this feature is supported.
	*/
	virtual void SetReadOnly(bool state) = 0;
};


} // namespace imod


#endif // !imod_IModelEditor_included

