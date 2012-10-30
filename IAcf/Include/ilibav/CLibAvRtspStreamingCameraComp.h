#ifndef ilibav_CLibAvRtspStreamingCameraComp_included
#define ilibav_CLibAvRtspStreamingCameraComp_included

// LIBAV includes
extern "C"{
#define inline _inline
#define __STDC_CONSTANT_MACROS
#include <libavformat/avformat.h>
#undef inline
}

// Qt includes
#include <QMutex>

// ACF includes
#include "ibase/TLoggerCompWrap.h"
#include "iproc/TSyncProcessorWrap.h"
#include "iprm/IFileNameParam.h"

// ACF-Solutions includes
#include "icam/IBitmapAcquisition.h"
#include "icam/IExposureConstraints.h"
#include "icam/IExposureParams.h"

//#include "imeas/ILinearAdjustParams.h"
//#include "imeas/ILinearAdjustConstraints.h"
//#include "icam/IBitmapAcquisition.h"
//#include "icam/IExposureConstraints.h"

#include "CLibAvRtspStreamingClient.h"


namespace ilibav
{

class CLibAvRtspStreamingCameraCompBase: public ibase::CLoggerComponentBase,
	public QObject
{	
public:
	typedef ibase::CLoggerComponentBase BaseClass;

	I_BEGIN_BASE_COMPONENT(CLibAvRtspStreamingCameraCompBase);
		I_ASSIGN(m_defaultUrlParamCompPtr, "DefaultUrlParam", "Default m_camera URL used if no URL is defined", false, "DefaultUrlParam");
		//There is only one device - ? 
		//I_ASSIGN(m_defaultSelectionParamCompPtr, "DefaultSelectionParam", "Default m_camera selection params used if no selection nor URL is found", false, "DefaultSelectionParam");
		
		
		I_ASSIGN(m_defaultExposureParamsCompPtr, "DefaultExposureParams", "Default exposure parameters will be used if no parameters are found", false, "DefaultExposureParams");
		//I_ASSIGN(m_defaultTriggerParamsCompPtr, "DefaultTriggerParams", "Default trigger parameters that will be used", false, "DefaultTriggerParams");	
		//I_ASSIGN(m_defaultAdjustParamsCompPtr, "DefaultAdjustParams", "Default m_contrast and m_brightness adjust parameters that will be used", false, "DefaultAdjustParams");
		//I_ASSIGN(m_defaultRoiParamCompPtr, "DefaultRoiParam", "Default region of interest (ROI) that will be used if no defined", false, "DefaultImageRegionParams");
		//I_ASSIGN(m_defaultFeaturePathCompPtr, "DefaultFeatureFilePath", "Object containing m_camera feature file path stored with Basler Pylon Viewer application", false, "DefaultFeatureFilePath");
	I_END_COMPONENT;

protected:
	I_REF(iprm::IFileNameParam, m_defaultUrlParamCompPtr);
	//I_REF(iprm::ISelectionParam, m_defaultSelectionParamCompPtr);
	I_REF(icam::IExposureParams, m_defaultExposureParamsCompPtr);
	//I_REF(isig::ITriggerParams, m_defaultTriggerParamsCompPtr);
	//I_REF(imeas::ILinearAdjustParams, m_defaultAdjustParamsCompPtr);
	//I_REF(i2d::CRectangle, m_defaultRoiParamCompPtr);
	//I_REF(iprm::IFileNameParam, m_defaultFeaturePathCompPtr);
};


/**
	Implementation of icam::IBitmapAcquisition interface for streaming video using LibAv library.
*/
class CLibAvRtspStreamingCameraComp: 
	public CLibAvRtspStreamingCameraCompBase,
	public iproc::TSyncProcessorWrap<icam::IBitmapAcquisition>	
			//virtual public icam::IExposureConstraints			
{
	Q_OBJECT
		
public:
	typedef CLibAvRtspStreamingCameraCompBase BaseClass;

	enum MessageId
	{
		MI_CANNOT_OPEN = 0x56a20,
		MI_FORMAT_PROBLEM
	};

	I_BEGIN_COMPONENT(CLibAvRtspStreamingCameraComp);
		I_REGISTER_INTERFACE(icam::IBitmapAcquisition);
		I_REGISTER_INTERFACE(icam::IExposureConstraints);		
		I_ASSIGN(m_urlParamsIdAttrPtr, "UrlParamId", "ID used to get m_camera URL from the parameter set", false, "UrlParamId");
		I_ASSIGN(m_selectionParamIdPtr, "SelectionParamId", "ID used to get selected m_camera index from the parameter set", false, "UrlParamId");
		I_ASSIGN(m_exposureParamsIdAttrPtr, "ExposureParamsId", "ID used to get exposure parameters from the parameter set", false, "ExposureParams");
		I_ASSIGN(m_adjustParamsIdAttrPtr, "AdjustParamsId", "ID used to get m_brightness and m_contrast adjust parameters from the parameter set", false, "AdjustParams");
		I_ASSIGN(m_roiParamIdPtr, "RoiParamId", "ID used to get region of interest (ROI) from the parameter set", false, "DefaultImageRegionParams");
		I_ASSIGN(m_triggerParamsIdAttrPtr, "TriggerParamsId", "ID used to get trigger parameters from the parameter set", false, "TriggerParams");
		I_ASSIGN(m_timeoutAttrPtr, "Timeout", "Acquisition timeout", true, 5.0);
		I_ASSIGN(m_triggerDifferenceAttrPtr, "TriggerDifference", "Time difference between trigger signal and image time stamp used for synchronized trigger (in seconds)", false, 0.01);
		I_ASSIGN(m_triggerToleranceAttrPtr, "TriggerTolerance", "Tolerance of trigger time difference used for synchronized trigger (in seconds)", false, 0.02);
		I_ASSIGN(m_connectOnStartAttrPtr, "ConnectOnStart", "If true connection on start will be done, if false only connection on demand is done", true, true);
		I_ASSIGN(m_imageBufferSizeAttrPtr, "BufferSize", "Size of the image buffer, if not set, no buffered mode will be used", false, 10);
		I_ASSIGN(m_forceClearBufferAttrPtr, "ClearBuffer", "Force cleaning image buffer after acquisition", false, false);
	I_END_COMPONENT;

	CLibAvRtspStreamingCameraComp();
	virtual ~CLibAvRtspStreamingCameraComp();	

	// reimplemented (icam::IBitmapAcquisition)
	virtual istd::CIndex2d GetBitmapSize(const iprm::IParamsSet* paramsPtr) const;

	// reimplemented (iproc::IProcessor)
	virtual int DoProcessing(
				const iprm::IParamsSet* paramsPtr,
				const istd::IPolymorphic* inputPtr,
				istd::IChangeable* outputPtr,
				ibase::IProgressManager* progressManagerPtr = NULL);
	
	// reimplemented (icam::IExposureConstraints)
	//virtual istd::CRange GetShutterTimeRange() const;
	//virtual istd::CRange GetDelayTimeRange() const;
	//virtual istd::CRange GetEenDelayRange() const;

public Q_SLOTS:
	void frameArrived(AVFrame*, int , int, int);	

protected:
	/**
		Reads parameters from set 
	*/
	void readParams(const iprm::IParamsSet* paramsPtr);	

	// reimplemented (icomp::CComponentBase)
	void OnComponentCreated();
	void OnComponentDestroyed();

private:
	I_ATTR(QByteArray, m_urlParamsIdAttrPtr);
	I_ATTR(QByteArray, m_selectionParamIdPtr);
	I_ATTR(QByteArray, m_exposureParamsIdAttrPtr);
	I_ATTR(QByteArray, m_adjustParamsIdAttrPtr);
	I_ATTR(QByteArray, m_triggerParamsIdAttrPtr);
	I_ATTR(QByteArray, m_roiParamIdPtr);
	I_ATTR(double, m_timeoutAttrPtr);
	I_ATTR(double, m_triggerToleranceAttrPtr);
	I_ATTR(double, m_triggerDifferenceAttrPtr);
	I_ATTR(bool, m_connectOnStartAttrPtr);
	I_ATTR(int, m_imageBufferSizeAttrPtr);
	I_ATTR(bool, m_forceClearBufferAttrPtr);

	double m_exposureTime;

	QString m_rtspUrl;
	QString m_httpUrl;
	istd::TDelPtr<CLibAvRtspStreamingClient> m_streamingClientPtr;

	istd::CIndex2d frameSize;
	iimg::IBitmap* m_frameBitmapPtr;

	QMutex mutex;
};

} // namespace ilibav

#endif // !ilibav_CLibAvRtspStreamingCameraComp_included


