/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqt2d_ISceneProvider_included
#define iqt2d_ISceneProvider_included


// Qt includes
#include <QGraphicsScene>


// ACF includes
#include "istd/IPolymorphic.h"

#include "iqt2d/iqt2d.h"


namespace iqt2d
{


/**
	Interface for GUI objects managing scene.
*/
class ISceneProvider: virtual public istd::IPolymorphic
{
public:

	enum SceneFlags
	{
		/**
			Scene has a fixed size and cannot be resized by user.
		*/
		SF_FIXED_SIZE = 1,

		/**
			Scene has a grid alignment
			\sa GetSceneAlignment
		*/
		SF_ALIGNED = 2
	};


	/**
		Get ID indentifing this scene.
		Typically this ID is 0 for first scene, 1 for the second etc.
	*/
	virtual int GetSceneId() const = 0;

	/**
		Called when items should be removed from specified scene.
	*/
	virtual QGraphicsScene* GetScene() const = 0;

	/**
		Get parameters of grid alignment.
		\param	distance	distance between nearest alignment positions.
		\return	true if grid alignment is enabled.
		\sa SceneFlags
	*/
	virtual bool GetSceneAlignment(double& distance) const = 0;

	/**
		Get scene's paremeter info.
		\sa SceneFlags
	*/
	virtual int GetSceneFlags() const = 0;
};


} // namespace iqt2d


#endif // !iqt2d_ISceneProvider_included


