#include "CColorantColor.h"

// ACF includes
#include <icmm/CSubstractiveColorModel.h>

namespace icmm
{


CColorantColor::CColorantColor(const icmm::CFastColor& color, icmm::ColorModelPtr modelPtr)
	: m_color(color),
	  m_modelPtr(modelPtr)
{
}

// reimplemented (icmm::IColorantColor)

const icmm::CFastColor& CColorantColor::GetFastColor() const
{
	return m_color;
}

// reimplemented (icmm::IColorObject)

icmm::CVarColor CColorantColor::GetColor() const
{
	icmm::CVarColor varColor;
	varColor.SetElementsFrom(m_color);
	return varColor;
}


icmm::ConstColorModelPtr CColorantColor::GetColorModel() const
{
	return m_modelPtr;
}


std::unique_ptr<icmm::IColorObject> CColorantColor::CloneIntoUniquePtr() const
{
	return std::make_unique<CColorantColor>(*this);
}


// reimplemented (iser::ISerializable)

bool CColorantColor::Serialize(iser::IArchive& /*archive*/)
{
	return false;
}


} // namespace icmm
