/*
 * TextDrawer.cpp
 *
 *  Created on: 10 марта 2010
 *      Author: Pasha Shestak, Kyrylo Shegeda
 */

#include "TextDrawer.h"
#include <glibconfig.h>

/* The function configures a "PangoFontDescription" structure according to the font settings
 * of the "TextInstance"
 */
void
SetFontDescription(PangoFontDescription* desc, const FontSettings & fontParameters)
{
    pango_font_description_set_family(desc, fontParameters.FontFamily.c_str());
    pango_font_description_set_style(desc, fontParameters.FontStyle);
    pango_font_description_set_weight(desc, fontParameters.FontWeight);
    pango_font_description_set_size(desc, fontParameters.FontHeight*PANGO_SCALE);
}

/* The function performs Affine transformation of a point with following properties:
 *  "angle" - rotation angle in radians, counted from horizontal line clockwise;
 *  "offset_x", "offset_y" - translation offsets
 *  "pointToTransform" - the point, that should be transformed
 */
QPoint
AffineTransformation(const double angle,
        const int xOffset,
        const int yOffset,
        const QPoint pointToTransform)
{
    //Calculating components of the transformation matrix
    double xx = cos(-angle);
    double yx = -sin(-angle);
    double xy = sin(-angle);
    double yy = cos(-angle);
    double x0 = xOffset;
    double y0 = yOffset;

    //Applying transformations
    QPoint res(-(xx * pointToTransform.x() + xy * pointToTransform.y() + x0), -(yx
            * pointToTransform.x() + yy * pointToTransform.y() + y0));
    return res;
}

std::string UTF16ToUTF8(const ushort* text)
{

	gchar* UTF8=g_utf16_to_utf8((gunichar2*)text,-1,NULL,NULL,NULL);
	std::string out=UTF8;
	g_free(UTF8);
	return out;
}





//TextDrawer Implementation========================================================================================
TextDrawer::TextDrawer(const FontSettings & fontParameters,
					   const QColor & fontColor,
					   const QColor & backgroundColor,
					   const HorizontalAlignment referancePointAbscissa,
					   const VerticalAlignment referencePointOrdinate):

					   FontParameters(fontParameters),
					   FontColor(fontColor),
					   BackgroundColor(backgroundColor),
					   ReferencePointAbscissa(referancePointAbscissa),
					   ReferencePointOrdinate(referencePointOrdinate)
{
	FontAttributes = pango_attr_list_new();
	FontMetrics=pango_font_metrics_ref(NULL);
	DrawingContext = pango_font_map_create_context(pango_cairo_font_map_get_default());
	FillClipIsSet=false;

	SetPangoFontParameters();

	FillClipSwitcher=Fill;
	FillClipIsSet=false;
	FillClipRectangle.x=0;
	FillClipRectangle.y=0;
	FillClipRectangle.width=0;
	FillClipRectangle.height=0;
}


TextDrawer::~TextDrawer()
{
	pango_attr_list_unref(FontAttributes);
	pango_font_metrics_unref(FontMetrics);
	g_object_unref(DrawingContext);
}


void TextDrawer::SetPangoFontParameters()
{
	PangoFontMap* defaultFontMap = pango_cairo_font_map_get_default();
	PangoFontDescription * desc = pango_font_description_new();
	SetFontDescription(desc, FontParameters);

	g_object_unref(DrawingContext);
	DrawingContext = pango_font_map_create_context(defaultFontMap);
	DrawingFont = pango_font_map_load_font(defaultFontMap, DrawingContext, desc);

	pango_attr_list_unref(FontAttributes);
	FontAttributes = pango_attr_list_new();
	pango_attr_list_change(FontAttributes, pango_attr_font_desc_new(desc));

	pango_font_metrics_unref(FontMetrics);
	FontMetrics=pango_font_get_metrics(DrawingFont,NULL);


	pango_font_description_free(desc);
}





//Adding clipping region
void
TextDrawer::AddClipRegion(const cairo_rectangle_t & region)
{
    ClipRegions.push_back(region);
}


/*The function calculates size of the rectangle, drawn exactly around the rotated text
 *
 *
 *RectangleForRotatedText.width()
 * <----->
 *
 * -------  ^
 * | /\  |  |
 * |/  \ |  |
 * |\   \|  |RectangleForRotatedText.height()
 * | \  /|  |
 * |  \/ |  |
 * -------  v
 *
 */

QSize
TextDrawer::CalculateSizeOfTheRectangleForTextRotatedOnEscapementAngle(const QSize size)
{
	QSize RectangleForRotatedText(size.width() * fabs(cos(FontParameters.EscapementAngle)) +
								  size.height() * fabs(sin(FontParameters.EscapementAngle)),
								  size.width() * fabs(sin(FontParameters.EscapementAngle)) +
								  size.height() * fabs(cos(FontParameters.EscapementAngle)));
	return RectangleForRotatedText;
}

/* The function calculates coordinates("offset.x" and "offset.y") of the upper
 * left corner of the rotated text,so the text lies exactly in the rectangle,
 * drawn around it
 *
 *
 *
 *      \                                               /
 *       \                                             /
 * -----------------------------    -----------------------------
 *         \)                                        /_)
 *          \                                       /
 *           \upper left corner                    /
 *          --*----                       ------- /                 ^
 *          | /\  |                       |  /\ |/                  |
 *          |/Ш \ |                       | /Е \*upper left corner  |outerRectangle.height()
 *          |\   \|                       |/   /|                   |
 *          | \  /|                       |\  / |                   |
 *          |  \/ |                       | \/  |                   v
 *          -------                       -------
 *
 *                                        <----->
 *                                   outerRectangleSize.width()
 *
 */
QPoint
TextDrawer::CalculateOffsetForOutputPointInPangoOutput(const QSize textSize,
        const QSize outerRectangleSize)
{
	QPoint offset;

    if (FontParameters.EscapementAngle <= G_PI / 2)//text in the 4th quarter
    {
        offset.setX(((double) textSize.height() * fabs(sin(FontParameters.EscapementAngle))));
		offset.setY(0);
    }
    else if (FontParameters.EscapementAngle <= G_PI)//text in the 3rd quarter
    {
    	offset.setX(outerRectangleSize.width());
    	offset.setY(textSize.height() * fabs(cos(FontParameters.EscapementAngle)));
    }
    else if (FontParameters.EscapementAngle <= 3 * G_PI / 2)//text in the 2nd quarter
    {
    	offset.setX(textSize.width() * fabs(cos(FontParameters.EscapementAngle - G_PI)));
    	offset.setY(outerRectangleSize.height());
    }
    else//text in the 1st quarter
    {
    	offset.setX(0);
    	offset.setY(textSize.width() * fabs(sin(2 * G_PI - FontParameters.EscapementAngle)));
    }
    return offset;
}

/*Setting clipping region which is described by a set of rectangles
 * The method retrieves:
 * 	canvas - cairo context
 * 	outputLocation - the position of the output point in pixels
 * 	qImageOffset - the offset of the QImage, with the text drawn on it, in order to
 * 					put the text in specified outputLocation
 */
void
TextDrawer::SetClippingRegion(cairo_t* canvas, QPoint outputLocation, QPoint qImageOffset)
{
    if (ClipRegions.size() > 0)
    {

    	std::list<cairo_rectangle_t>::iterator end=ClipRegions.end();
        for (std::list<cairo_rectangle_t>::iterator it=ClipRegions.begin(); it !=end; it++)
            cairo_rectangle(canvas,
            		(*it).x - outputLocation.x() - qImageOffset.x(),
            		(*it).y - outputLocation.y() - qImageOffset.y(),
            		(*it).width,
            		(*it).height);

        cairo_clip(canvas);
    }
}

/*Calculating coordinates of the reference point
 * The method retrieves width and height of the text before rotation
 */
QPoint
TextDrawer::CalculateReferencePointCoordinates(const QSize textSize, const int baseline)
{
    QPoint refpoint;
    if (ReferencePointAbscissa == Right)//Horizontally:Right point
    {
        refpoint.setX(textSize.width());
    }
    else if (ReferencePointAbscissa == Middle)//Horizontally: Middle point
    {
        refpoint.setX(textSize.width() / 2);
    }
    else
        //Horizontally: Left point
        refpoint.setX(0);

    if (ReferencePointOrdinate == Upper)//Vertically: Upper point
        refpoint.setY(0);
    else if (ReferencePointOrdinate == Baseline)//Vertically: Middle point
        refpoint.setY(baseline);
    else
        //Vertically: Lower point
        refpoint.setY(textSize.height());

    return refpoint;
}

/*
 * Adding font file specified by fileName to application
 */
bool
TextDrawer::AddFontToApplication(const FcChar8* fileName)
{
    return (FcConfigAppFontAddFile(NULL, fileName) == FcTrue);
}

/*
 * Adding all font files found in directory specified by directoryName to application
 */
bool
TextDrawer::AddFontDirectoryToApplication(const FcChar8* directoryName)
{
    return (FcConfigAppFontAddDir(NULL, directoryName) == FcTrue);
}

/*
 * Deleting from application all fonts added previously by AddFontToApplication and
 * 			AddFontDirectoryToApplication
 */
void
TextDrawer::DeleteUserFonts()
{
    FcConfigAppFontClear( NULL);
}

std::auto_ptr<std::vector<int> >
CalculateGlyphsPositions(const PangoGlyphString & glyphString,
        const int ascent,
        const int descent,
        const double angle)
{
    double cosAngle = fabs(cos(angle));
    double sinAngle = fabs(sin(angle));

    const int height = ascent + descent;

    int glyphsCount = glyphString.num_glyphs;
    std::auto_ptr<std::vector<int> > positionsOfGlyphs(new std::vector<int>(glyphsCount));

    if (angle < M_PI_2)
    {
        (*positionsOfGlyphs)[0] = descent * sinAngle;

        for (int i = 1; i < glyphsCount; ++i)
        {
            (*positionsOfGlyphs)[i] = (*positionsOfGlyphs)[i - 1] + std::min(double(glyphString.glyphs[i
                    - 1].geometry.width) / cosAngle / PANGO_SCALE, double(height) / sinAngle);
        }
    }
    else if (angle < M_PI)
    {
        (*positionsOfGlyphs)[0] = glyphString.glyphs[0].geometry.width / PANGO_SCALE * cosAngle
                + descent * (cosAngle + sinAngle);

        for (int i = 1; i < glyphsCount; ++i)
        {
            (*positionsOfGlyphs)[i] = (*positionsOfGlyphs)[i - 1]
                    + std::min(double(glyphString.glyphs[i].geometry.width) / cosAngle / PANGO_SCALE,
                            double(height) / sinAngle);
        }
    }
    else if (angle < M_3PI_2)
    {
        (*positionsOfGlyphs)[0] = ascent * sinAngle + glyphString.glyphs[0].geometry.width
                / PANGO_SCALE * cosAngle + descent * cosAngle;

        for (int i = 1; i < glyphsCount; ++i)
        {
            (*positionsOfGlyphs)[i] = (*positionsOfGlyphs)[i - 1]
                    + std::min(double(glyphString.glyphs[i].geometry.width) / cosAngle / PANGO_SCALE,
                            double(height) / sinAngle);
        }
    }
    else
    {
        (*positionsOfGlyphs)[0] = ascent * sinAngle;

        for (int i = 1; i < glyphsCount; ++i)
        {
            (*positionsOfGlyphs)[i] = (*positionsOfGlyphs)[i - 1] + std::min(double(glyphString.glyphs[i
                    - 1].geometry.width) / cosAngle / PANGO_SCALE, double(height) / sinAngle);
        }
    }

    return positionsOfGlyphs;

}

void TextDrawer::SetFontParametrs(const FontSettings & fontParameters)
{
	FontParameters=fontParameters;
	SetPangoFontParameters();
}

void TextDrawer::DrawLetters(QPainter * painter,
		const ushort* textForOutput,
		const QPoint & location)
{
    std::string stringForOutput=UTF16ToUTF8(textForOutput);

    if (!stringForOutput.empty())
    {
        const char * text = stringForOutput.c_str();


        GList *list = pango_itemize(DrawingContext, text, 0, strlen(text), FontAttributes, NULL);
        PangoItem *item = (PangoItem*) list->data;

        PangoGlyphString * glyphStringForText = pango_glyph_string_new();

        int textLength=g_utf8_strlen((const gchar*)text,stringForOutput.length());
        pango_glyph_string_set_size(glyphStringForText, textLength);

        pango_shape(text, strlen(text), &item->analysis, glyphStringForText);

        DrawGlyphString(painter,glyphStringForText,location);

        pango_glyph_string_free(glyphStringForText);

        pango_item_free(item);
        g_list_free(list);
    }
}

void TextDrawer::DrawLetters(QPainter * painter,
		const unsigned int* textForOutput,
		const QPoint & location)
{
    int glyphs_count=0;
    while (textForOutput[glyphs_count])
        ++glyphs_count;

    PangoGlyphString * glyphStringForText = pango_glyph_string_new();
    pango_glyph_string_set_size(glyphStringForText, glyphs_count);

    for (int i = 0; i < glyphs_count; ++i)
    {
        glyphStringForText->glyphs[i].glyph = textForOutput[i];
        PangoRectangle logical_rect;
        pango_font_get_glyph_extents(DrawingFont, textForOutput[i], NULL, &logical_rect);
        glyphStringForText->glyphs[i].geometry.x_offset = 0;
        glyphStringForText->glyphs[i].geometry.y_offset = 0;
        glyphStringForText->glyphs[i].geometry.width = logical_rect.width;
    }

   DrawGlyphString(painter,glyphStringForText,location);

    pango_glyph_string_free(glyphStringForText);
}

int TextDrawer::CalculateNewAscent(const int ascent, const int descent, const int nHeight)
{
    const double cosAngle = fabs(cos(FontParameters.OrientationAngle));
    int nAscent;
    if (FontParameters.OrientationAngle <= G_PI / 2)
    {
        nAscent = ascent * fabs(cosAngle);
    }
    else if (FontParameters.OrientationAngle <= G_PI)
    {
        nAscent = descent * fabs(cosAngle);
    }
    else if (FontParameters.OrientationAngle <= M_3PI_2)
    {
        nAscent = nHeight - ascent * fabs(cosAngle);
    }
    else
    {
        nAscent = nHeight - descent * cosAngle;
    }
    return nAscent;
}

void TextDrawer::FillingBackgroundByMetrics(const int textLength,
											cairo_t * canvas,
											const std::vector<int> * positionsOfGlyphs,
											const int nAscent,
											const int ascent,
											const PangoGlyphString * glyphStringForText,
											const int height)
{
	cairo_set_source_rgba(canvas, BackgroundColor.redF(), BackgroundColor.greenF(), BackgroundColor.blueF(),BackgroundColor.alphaF());

	for (int i = 0; i < textLength; ++i)
    {
        cairo_save(canvas);
        cairo_translate(canvas, (*positionsOfGlyphs)[i], nAscent);
        cairo_rotate(canvas, FontParameters.OrientationAngle);

        cairo_translate(canvas, 0, -ascent);
        cairo_rectangle(canvas, 0, 0, glyphStringForText->glyphs[i].geometry.width / PANGO_SCALE, height);
        cairo_fill(canvas);

        cairo_restore(canvas);
    }
}

void TextDrawer::FillingBackgroundByMetricsConsideringFillClipRegion(const int textLength,
                                                                     cairo_t * canvas,
                                                                     const std::vector<int> * positionsOfGlyphs,
                                                                     const int nAscent,
                                                                     const int ascent,
                                                                     const PangoGlyphString * glyphStringForText,
                                                                     const int height,
                                                                     const QPoint offset)
{
	if (FillClipIsSet)
	{
		if(FillClipSwitcher==Fill)
		{
			FillingBackgroundByMetrics(textLength, canvas, positionsOfGlyphs, nAscent, ascent, glyphStringForText, height);
			cairo_restore(canvas);

			//translating and rotating because right now we're at the state before we did it
			//-----------Rotation for escapment angle
			cairo_translate(canvas, offset.x(), offset.y());

			//Rotating text: escapement angle
			cairo_rotate(canvas, FontParameters.EscapementAngle);
		}
	}
	else
		FillingBackgroundByMetrics(textLength, canvas, positionsOfGlyphs, nAscent, ascent, glyphStringForText, height);
}

void TextDrawer::SettingFillClipRegionOnCanvas(cairo_t * canvas,
									   QPoint location,
									   QPoint qImageOffset)
{
	if (FillClipSwitcher==Fill)
		cairo_save(canvas);
	cairo_rectangle(canvas,FillClipRectangle.x-(location.x() + qImageOffset.x()),FillClipRectangle.y-(location.y() + qImageOffset.y()),
			FillClipRectangle.width,FillClipRectangle.height);
	cairo_clip(canvas);
}

void TextDrawer::DrawUnderline(cairo_t * canvas,
				   const PangoGlyphString * glyphStringForText,
				   const double & currentX,
				   const double & currentY,
				   const int & glyphNumber)
{
	cairo_set_line_width(canvas,pango_font_metrics_get_underline_thickness(FontMetrics)/PANGO_SCALE);
	int underlinePosition=pango_font_metrics_get_underline_position(FontMetrics)/PANGO_SCALE;
	cairo_move_to(canvas,currentX,currentY-underlinePosition);
	cairo_line_to(canvas,currentX+glyphStringForText->glyphs[glyphNumber].geometry.width/PANGO_SCALE,currentY-underlinePosition);
	cairo_move_to(canvas,currentX,currentY);
}

void TextDrawer::DrawStrikethrough(cairo_t * canvas,
				   const PangoGlyphString * glyphStringForText,
				   const double & currentX,
				   const double & currentY,
				   const int & glyphNumber)
{
	cairo_set_line_width(canvas,pango_font_metrics_get_strikethrough_thickness(FontMetrics)/PANGO_SCALE);
	int strikethroughPosition=pango_font_metrics_get_strikethrough_position(FontMetrics)/PANGO_SCALE;
	cairo_move_to(canvas,currentX,currentY-strikethroughPosition);
	cairo_line_to(canvas,currentX+glyphStringForText->glyphs[glyphNumber].geometry.width/PANGO_SCALE,currentY-strikethroughPosition);
	cairo_move_to(canvas,currentX,currentY);
}

void TextDrawer::DrawOverline(cairo_t * canvas,
							  const PangoGlyphString * glyphStringForText,
							  const double & currentX,
							  const double & currentY,
							  const int & glyphNumber)
{
	cairo_set_line_width(canvas,pango_font_metrics_get_underline_thickness(FontMetrics)/PANGO_SCALE);
	int overlinePosition=pango_font_metrics_get_ascent(FontMetrics)/PANGO_SCALE;
	cairo_move_to(canvas,currentX,currentY-overlinePosition);
	cairo_line_to(canvas,currentX+glyphStringForText->glyphs[glyphNumber].geometry.width/PANGO_SCALE,currentY-overlinePosition);
	cairo_move_to(canvas,currentX,currentY);
}

void TextDrawer::DrawRotatedLetters(cairo_t * canvas,
									const int textLength,
									const PangoGlyphString * glyphStringForText,
									const std::vector<int>* positionsOfGlyphs,
									const int nAscent)
{
    PangoGlyphString *outputGlyphString = pango_glyph_string_new();
    pango_glyph_string_set_size(outputGlyphString, 1);
    outputGlyphString->glyphs[0].geometry.x_offset = 0;
    outputGlyphString->glyphs[0].geometry.y_offset = 0;
    cairo_set_source_rgb(canvas, FontColor.redF(), FontColor.greenF(), FontColor.blueF());


	double scalingWidthFactor;//scalingFactor for width

	if (FontParameters.FontWidth!=0)
		scalingWidthFactor=(double)FontParameters.FontWidth * PANGO_SCALE / pango_font_metrics_get_approximate_char_width(FontMetrics);
	else
		scalingWidthFactor = 1;

    for(int i = 0;i < textLength;++i){
        outputGlyphString->glyphs[0].glyph = glyphStringForText->glyphs[i].glyph;
        cairo_save(canvas);
        cairo_translate(canvas, (*positionsOfGlyphs)[i], nAscent);
        cairo_rotate(canvas, FontParameters.OrientationAngle);


        double currentX,currentY;
		cairo_get_current_point(canvas,&currentX,&currentY);

        if (FontParameters.Underlined)
		{
                    DrawUnderline(canvas,glyphStringForText,currentX,currentY,i);
		}

		if (FontParameters.Striken)
		{
                    DrawStrikethrough(canvas,glyphStringForText,currentX,currentY,i);
		}

		if (FontParameters.Overlined)
		{
                    DrawOverline(canvas,glyphStringForText,currentX,currentY,i);
		}
        cairo_stroke(canvas);

        cairo_scale(canvas,scalingWidthFactor,1);
        pango_cairo_show_glyph_string(canvas, DrawingFont, outputGlyphString);

        cairo_restore(canvas);
    }

    pango_glyph_string_free(outputGlyphString);
}

void TextDrawer::DataToPainter(cairo_surface_t *surface,
							   const QSize nSize,
							   QPainter *painter,
							   const QPoint & location,
							   const QPoint & qImageOffset)
{
    QImage image2 = QImage(cairo_image_surface_get_data(surface), nSize.width(), nSize.height(), QImage::Format_RGB32);

    //Setting composition mode of the QPainter and drawing image
    painter->setCompositionMode(QPainter::CompositionMode_SourceAtop);
    painter->drawImage(location.x() + qImageOffset.x(), location.y() + qImageOffset.y(), image2, Qt::ThresholdDither & Qt::AutoColor & Qt::ThresholdAlphaDither);
}

void
TextDrawer::DrawGlyphString(QPainter *painter,
		const PangoGlyphString *glyphStringForText,
		const QPoint & location)
{
    int ascent = pango_font_metrics_get_ascent(FontMetrics) / PANGO_SCALE;

    int descent = pango_font_metrics_get_descent(FontMetrics) / PANGO_SCALE;
    int height = ascent + descent;

    int textLength=glyphStringForText->num_glyphs;

	double scalingWidthFactor;//scalingFactor for width

	if (FontParameters.FontWidth!=0)
		scalingWidthFactor=(double)FontParameters.FontWidth * PANGO_SCALE / pango_font_metrics_get_approximate_char_width(FontMetrics);
	else
		scalingWidthFactor = 1;
    int maximalWidth = 0;
    for (int i = 0; i < textLength; ++i)
    {

        if (glyphStringForText->glyphs[i].geometry.width > maximalWidth)
        {
            maximalWidth = glyphStringForText->glyphs[i].geometry.width;
        }
        glyphStringForText->glyphs[i].geometry.width *= scalingWidthFactor;
    }
    maximalWidth /= PANGO_SCALE;

    std::auto_ptr<std::vector<int> > positionsOfGlyphs =
                CalculateGlyphsPositions(*glyphStringForText, ascent, descent, FontParameters.OrientationAngle);

    const QSize nSize((*positionsOfGlyphs)[textLength - 1] + height,
					  height * fabs(cos(FontParameters.OrientationAngle)) + maximalWidth * fabs(sin(FontParameters.OrientationAngle)));

	//New width and new height of the surface that contains text rotated on escapement angle(size of rectangle circumscribed around the text)
    QSize surfaceSize=CalculateSizeOfTheRectangleForTextRotatedOnEscapementAngle(nSize);

    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, surfaceSize.width(), surfaceSize.height());
    cairo_t *canvas = cairo_create(surface);
   // PangoLayout *layout = pango_cairo_create_layout(canvas);
   // pango_layout_set_attributes(layout, FontAttributes);

    const int nAscent = CalculateNewAscent(ascent, descent, nSize.height());

    //The offset of the coordinates of the text (top-left corner of the rotated text)
    const QPoint offset = CalculateOffsetForOutputPointInPangoOutput(nSize,surfaceSize);

    //Calculating reference point of the text
	const QPoint referencePoint = CalculateReferencePointCoordinates(nSize, ascent);
	const QPoint qImageOffset=AffineTransformation(FontParameters.EscapementAngle,offset.x(),offset.y(),
			referencePoint);

    SetClippingRegion(canvas,location,qImageOffset);

    if (BackgroundColor.alpha()!=0)
    	if (FillClipIsSet)
			SettingFillClipRegionOnCanvas(canvas,location,qImageOffset);


	//-----------Rotation for escapment angle
	cairo_translate(canvas, offset.x(), offset.y());

	//Rotating text: escapement angle
	cairo_rotate(canvas, FontParameters.EscapementAngle);
	//---------------------------------------

    if (BackgroundColor.alpha()!=0)
    	FillingBackgroundByMetricsConsideringFillClipRegion(textLength, canvas, positionsOfGlyphs.get(), nAscent, ascent, glyphStringForText, height,offset);

    DrawRotatedLetters(canvas, textLength, glyphStringForText, positionsOfGlyphs.get(), nAscent);

    DataToPainter(surface, surfaceSize, painter, location,qImageOffset);

    //freeing allocated resources
    cairo_destroy(canvas);
    cairo_surface_destroy(surface);
}

