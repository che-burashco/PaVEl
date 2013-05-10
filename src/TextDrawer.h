/*
 * TextDrawer.h
 *
 *  Created on: 10 марта 2010
 *      Author: Pasha Shestak, Kyrylo Shegeda
 */

#ifndef TEXTDRAWER_H_
#define TEXTDRAWER_H_

#include <QtGui/QImage>
#include <QtGui/QPainter>

#include <pango/pangocairo.h>
#include <pango/pango.h>
#include <pango/pangofc-font.h>
#include <cairo.h>

#include <vector>
#include <memory>
#include <cmath>
#include <stdexcept>
#include <fontconfig.h>
#include <algorithm>

#include <pango/pangoft2.h>

#include "TextInstance.h"

#define _TEXT_DRAWER_DEBUG_//Shows the bounds of the text and its baseline
#define SCALE_COLOR 65535.0//constant for scaling color from 0..65535 range to 0..1

#define M_3PI_2 4.71238898038468985769

/*

*/

	QPoint AffineTransformation(const double angle,
                                   const int xOffset,
                                   const int yOffset,
                                   const QPoint pointToTranslate);

	void SetFontDescription(PangoFontDescription* desc,
                               const FontSettings & fontParameters);

	std::string UTF16ToUTF8(const ushort* text);

	enum FillClip
	{
		Fill=0,Clip=1
	};

class TextDrawer
{
private:

	PangoFont* DrawingFont;
	PangoAttrList* FontAttributes;
	PangoFontMetrics* FontMetrics;
	PangoContext* DrawingContext;

    std::list<cairo_rectangle_t> ClipRegions;

    FontSettings FontParameters;


    HorizontalAlignment ReferencePointAbscissa;
    VerticalAlignment ReferencePointOrdinate;


    void SetPangoFontParameters();

    QSize CalculateSizeOfTheRectangleForTextRotatedOnEscapementAngle(const QSize size);

    QPoint CalculateOffsetForOutputPointInPangoOutput(const QSize textSize,
													   const QSize outerRectangleSize);

    QPoint CalculateReferencePointCoordinates(const QSize textSize, const int baseline);

    void SetClippingRegion(cairo_t* canvas, QPoint outputLocation, QPoint qImageOffset);

    void DrawGlyphString(QPainter * painter,
    		const PangoGlyphString* glyphStringForText,
    		const QPoint & location);
    int CalculateNewAscent(const int ascent, const int descent, const int nHeight);
    void FillingBackgroundByMetrics(const int textLength,
									cairo_t * canvas,
									const std::vector<int> * positionsOfGlyphs,
									const int nAscent,
									const int ascent,
									const PangoGlyphString * glyphStringForText,
                                                                        const int height);
    void DrawRotatedLetters(cairo_t * canvas,
							const int textLength,
							const PangoGlyphString * glyphStringForText,
							const std::vector<int> * positionsOfGlyphs,
							const int nAscent);
    void DrawUnderline(cairo_t * canvas,
					   const PangoGlyphString * glyphStringForText,
					   const double & currentX,
					   const double & currentY,
					   const int & glyphNumber);
    void DrawStrikethrough(cairo_t * canvas,
						  const PangoGlyphString * glyphStringForText,
						  const double & currentX,
						  const double & currentY,
						  const int & glyphNumber);
    void DrawOverline(cairo_t * canvas,
    				  const PangoGlyphString * glyphStringForText,
    				  const double & currentX,
    				  const double & currentY,
    				  const int & glyphNumber);
    void DataToPainter(cairo_surface_t *surface,
					   const QSize nSize,
					   QPainter *painter,
					   const QPoint & location,
					   const QPoint & qImageOffset);
    void SettingFillClipRegionOnCanvas(cairo_t * canvas,
									   QPoint location,
									   QPoint qImageOffset);
    void FillingBackgroundByMetricsConsideringFillClipRegion(const int textLength,
                                                             cairo_t * canvas,
                                                             const std::vector<int> * positionsOfGlyphs,
                                                             const int nAscent,
                                                             const int ascent,
                                                             const PangoGlyphString * glyphStringForText,
                                                             const int height,
                                                             const QPoint offset);


public:

    QColor FontColor;
    QColor BackgroundColor;

    FillClip FillClipSwitcher;
    bool FillClipIsSet;
    cairo_rectangle_t FillClipRectangle;


    TextDrawer(const FontSettings & fontParameters,
    		   const QColor & fontColor,
    		   const QColor & backgroundColor,
    		   const HorizontalAlignment referencePointAbscissa,
    		   const VerticalAlignment referencePointOrdinate);

    void DrawLetters(QPainter * painter,
    		const ushort* text,
    		const QPoint & location);

    void DrawLetters(QPainter * painter,
                    const unsigned int* textForOutput,
                    const QPoint & location);
    void SetFontParametrs(const FontSettings & fontParameters);
    bool AddFontToApplication(const FcChar8* fileName);
    bool AddFontDirectoryToApplication(const FcChar8* directoryName);
    void DeleteUserFonts();

    void AddClipRegion(const cairo_rectangle_t & region);
    virtual ~TextDrawer();
};

#endif /* TEXTDRAWER_H_ */
