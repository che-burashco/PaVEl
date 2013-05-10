/*
 * TextInstance.cpp
 *
 *  Created on: 3 марта 2010
 *      Author: Pasha Shestak, Kyrylo Shegeda
 */

#include "TextInstance.h"

//FontSettings methods===========================================================================

FontSettings::FontSettings(	const std::string & fontName = "Purisa",
							const PangoWeight fontWeight = PANGO_WEIGHT_NORMAL,
							const gint fontHeight = 0,
							const gint fontWidth = 0,
							const gint escapementAngle = 0,
							const gint orientationAngle = 0,
							const bool underlined = false,
							const bool striken = false,
							const bool overlined=false) :

							FontFamily(fontName),
							FontStyle(PANGO_STYLE_NORMAL),
							FontWeight(fontWeight),
							FontHeight(fontHeight),
							EscapementAngle((escapementAngle % MAXIMUM_DEGREES) * DEGREES_INTO_RADIANS),
							OrientationAngle((orientationAngle % MAXIMUM_DEGREES) * DEGREES_INTO_RADIANS),
							FontWidth(fontWidth),
							Underlined(underlined),
							Striken(striken),
							Overlined(overlined)
{
	qDebug("Angle:%d",orientationAngle);
}

FontSettings::FontSettings():
	FontFamily("Purisa"),
	FontStyle(PANGO_STYLE_NORMAL),
	FontWeight(PANGO_WEIGHT_NORMAL),
	FontHeight(20),
	FontWidth(0),
	EscapementAngle(0),
	OrientationAngle(0),
	Underlined(false),
	Striken(false),
	Overlined(false)
	{

	}

void FontSettings::SetEscapementAngle(const gint escapementAngle)
{
	EscapementAngle=(escapementAngle % MAXIMUM_DEGREES) * DEGREES_INTO_RADIANS;
}

void FontSettings::SetOrientationAngle(const gint orientationAngle)
{
	OrientationAngle=(orientationAngle % MAXIMUM_DEGREES) * DEGREES_INTO_RADIANS;
}

//TextInstance methods===============================================================================
/*
TextInstance::TextInstance()
{
	PangoColor color;
	color.red = 0;
	color.green = 0;
	color.blue = 0;

	TextInstance(	std::string(""),
					color,
					FontSettings(),
					QPoint(0, 0),
					0,
					Left,
					Upper);
}

TextInstance::TextInstance(	const std::string &text,
							const PangoColor &textColor,
							const PangoColor &backgroundColor,
							const FontSettings &fontSettings,
							const QPoint &outputLocation,
							const int escapementAngle,
							const HorizontalAlignment HorP,
							const VerticalAlignment VertP):
	Text(text), TextColor(textColor), BackgroundColor(backgroundColor),
			FontProperties(fontSettings), OutputLocation(outputLocation),
			EscapementAngle(escapementAngle),
			HorizontalAlignmentOfReferencePoint(HorP),
			VerticalAlignmentOfReferencePoint(VertP), BackgroundColorFlag(true)
{
}

TextInstance::TextInstance(	const std::string &text,
							const PangoColor &textColor,
							const FontSettings &fontSettings,
							const QPoint &outputLocation,
							const int escapementAngle,
							const HorizontalAlignment HorP,
							const VerticalAlignment VertP) :
	Text(text), TextColor(textColor), FontProperties(fontSettings),
			OutputLocation(outputLocation), EscapementAngle(escapementAngle),
			HorizontalAlignmentOfReferencePoint(HorP),
			VerticalAlignmentOfReferencePoint(VertP),
			BackgroundColorFlag(false)
{
}

void TextInstance::SetText(const std::string &text)
{
	Text = text;
}

const std::string & TextInstance::GetText() const
{
	return Text;
}

void TextInstance::SetColor(const PangoColor &color)
{
	TextColor = color;
}

const PangoColor & TextInstance::GetColor() const
{
	return TextColor;
}

void TextInstance::SetBkColor(const PangoColor &color)
{
	BackgroundColor = color;
	BackgroundColorFlag = true;
}

const PangoColor & TextInstance::GetBkColor() const
{
	return BackgroundColor;
}

void TextInstance::UnSetBkColor()
{
	BackgroundColorFlag = false;
}

bool TextInstance::GetBkColorFlag() const
{
	return BackgroundColorFlag;
}

void TextInstance::SetFontName(const std::string &font_name)
{
	FontProperties.FontName = font_name;
}

const std::string & TextInstance::GetFontName() const
{
	return FontProperties.FontName;
}

void TextInstance::SetFontStyle(const PangoStyle font_style)
{
	FontProperties.FontStyle = font_style;
}

PangoStyle TextInstance::GetFontStyle() const
{
	return FontProperties.FontStyle;
}

void TextInstance::SetFontWeight(const PangoWeight font_weight)
{
	FontProperties.FontWeight = font_weight;
}

PangoWeight TextInstance::GetFontWeight() const
{
	return FontProperties.FontWeight;
}

void TextInstance::SetLocation(const QPoint location)
{
	OutputLocation = location;
}

QPoint TextInstance::GetLocation() const
{
	return OutputLocation;
}

void TextInstance::SetSize(const gint size)
{
	FontProperties.FontSize = size;
}

gint TextInstance::GetSize() const
{
	return FontProperties.FontSize;
}

void TextInstance::SetUnderlined(const bool underlined)
{
	FontProperties.Underlined = underlined;
}

bool TextInstance::GetUnderlined() const
{
	return FontProperties.Underlined;
}

void TextInstance::SetStriken(const bool striken)
{
	FontProperties.Striken = striken;
}

bool TextInstance::GetStriken() const
{
	return FontProperties.Striken;
}

void TextInstance::SetOverlined(const bool overlined)
{
	FontProperties.Overlined = overlined;
}

bool TextInstance::GetOverlined() const
{
	return FontProperties.Overlined;
}

void TextInstance::SetAngle(const int angle)
{
	EscapementAngle = angle;
}

int TextInstance::GetAngle(void) const
{
	return EscapementAngle;
}

void TextInstance::SetHorizontalReferencePoint(const HorizontalAlignment HorP)
{
	HorizontalAlignmentOfReferencePoint = HorP;
}

HorizontalAlignment TextInstance::GetHorizontalReferencePoint() const
{
	return HorizontalAlignmentOfReferencePoint;
}

void TextInstance::SetVerticalReferencePoint(const VerticalAlignment VertP)
{
	VerticalAlignmentOfReferencePoint = VertP;
}

VerticalAlignment TextInstance::GetVerticalReferencePoint() const
{
	return VerticalAlignmentOfReferencePoint;
}

TextInstance::~TextInstance()
{

}*/
