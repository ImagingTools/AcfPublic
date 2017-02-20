/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef iphonon_CPhononVideoViewGuiComp_included
#define iphonon_CPhononVideoViewGuiComp_included


// Qt includes
#include <QtMultiMediaWidgets/QVideoWidget>
#include <QtMultiMedia/QMediaPlayer>

// ACF includes
#include <imm/IVideoController.h>
#include <iqtgui/TGuiComponentBase.h>


namespace iphonon
{


class CPhononVideoViewGuiComp:
			public iqtgui::TGuiComponentBase<QVideoWidget>,
			virtual public imm::IVideoController
{
	Q_OBJECT
public:
	typedef iqtgui::TGuiComponentBase<QVideoWidget> BaseClass;

	I_BEGIN_COMPONENT(CPhononVideoViewGuiComp);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_REGISTER_INTERFACE(imm::IMediaController);
		I_REGISTER_INTERFACE(imm::IVideoInfo);
		I_REGISTER_INTERFACE(imm::IVideoController);
		I_ASSIGN(m_framesPerSecondAttrPtr, "FramesPerSecond", "Default number of frames per second if this info is unavailable from video", true, 25.0);
	I_END_COMPONENT;

	CPhononVideoViewGuiComp();

	// reimplemented (imm::IMediaController)
	virtual QString GetOpenedMediumUrl() const;
	virtual bool OpenMediumUrl(const QString& url, bool autoPlay = true);
	virtual void CloseMedium();
	virtual bool IsPlaying() const;
	virtual bool SetPlaying(bool state = true);
	virtual double GetMediumLength() const;
	virtual double GetCurrentPosition() const;
	virtual bool SetCurrentPosition(double position);
	virtual int	GetSupportedFeatures() const;
	
	// reimplemented (imm::IVideoInfo)
	virtual int GetFramesCount() const;
	virtual double GetFrameIntervall() const;
	virtual istd::CIndex2d GetFrameSize() const;
	virtual double GetPixelAspectRatio() const;

	// reimplemented (imm::IVideoController)
	virtual int GetCurrentFrame() const;
	virtual bool SetCurrentFrame(int frameIndex);

	// reimplemented (ifile::IFileTypeInfo)
	virtual bool GetFileExtensions(QStringList& result, const istd::IChangeable* dataObjectPtr = NULL, int flags = -1, bool doAppend = false) const;
	virtual QString GetTypeDescription(const QString* extensionPtr = NULL) const;

protected:
	void EnsureSync() const;

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

private:
	QMediaPlayer m_mediaPlayer;

	double m_currentPosition;

	I_ATTR(double, m_framesPerSecondAttrPtr);
};


} // namespace iphonon


#endif // !iphonon_CPhononVideoViewGuiComp_included

