/*
 * TextInstance.h
 *
 *  Created on: 3 марта 2010
 *      Author: Pasha Shestak, Kyrylo Shegeda
 */

#ifndef TEXTINSTANCE_H_
#define TEXTINSTANCE_H_

#include <cairo.h>
#include <pango/pangocairo.h>
#include <string>
#include <qpoint.h>

#define MAXIMUM_DEGREES 3600
#define DEGREES_INTO_RADIANS G_PI/1800

struct FontSettings
{
//private:


public:
    std::string FontFamily;
    PangoStyle FontStyle;
    PangoWeight FontWeight;
    gint FontHeight;
    gint FontWidth;
    double EscapementAngle;
    double OrientationAngle;
    bool Underlined;
    bool Striken;
    bool Overlined;

    FontSettings(const std::string & fontName,
                 const PangoWeight fontWeight,
                 const gint fontHeight,
                 const gint fontWidth,
                 const gint escapementAngle,
                 const gint orientationAngle,
                 const bool underlined,
                 const bool striken,
                 const bool overlined);

    FontSettings();

    void SetEscapementAngle(const gint escapementAngle);
    void SetOrientationAngle(const gint orientationAngle);
};

/* Enums for determination of output point of the text
 *
 * "VerticalOutputPoint" specifies whether the y-coordinate of the text
 * is the y-coordinate for Upper line, Baseline, or Lower line
 *
 * "HorizontalOutputPoint" specifies whether the x-coordinate of the text
 * is the x-coordinate for left border, middle, or right border
 *
 * It is also specifies a point, which the text should be rotated around
 */
enum VerticalAlignment
{
    Upper = 0, Baseline = 1, Lower = 2
};

enum HorizontalAlignment
{
    Left = 0, Middle = 4, Right = 8
};

/* A class that contains information about an instance of the text
 * that should be drawn.
 */
/*
class TextInstance
{
private:
    std::string Text; //The text itself
    PangoColor TextColor;
    PangoColor BackgroundColor;
    bool BackgroundColorFlag; //Specifies, whether background is transparent(false)
    //or has a color(true)

    FontSettings FontProperties;

    QPoint OutputLocation;

    int EscapementAngle;

    //Specifies the reference point of the text
    HorizontalAlignment HorizontalAlignmentOfReferencePoint;
    VerticalAlignment VerticalAlignmentOfReferencePoint;

public:
    TextInstance();

    //Constructor with setting background color
    TextInstance(//const std::string &text,
                 const PangoColor &textColor,
                 const PangoColor &backgroundColor,
                 const FontSettings &fontSettings,
                // const QPoint &outputLocation,
                 //const int escapementAngle,
                 const HorizontalAlignment HorP,
                 const VerticalAlignment VertP);

    //Constructor without setting background color
    TextInstance(const std::string &text,
                 const PangoColor &color,
                 const FontSettings &settings,
                 const QPoint &location,
                 const int escapmentAngle,
                 const HorizontalAlignment horizontalAlignment,
                 const VerticalAlignment verticalAlignment);

    void SetText(const std::string &text);

    const std::string & GetText() const;

    void SetColor(const PangoColor & color);

    const PangoColor & GetColor() const;

    void SetBkColor(const PangoColor & color);

    const PangoColor & GetBkColor() const;

    void UnSetBkColor();

    bool GetBkColorFlag() const;

    void SetFontName(const std::string & font_name);

    const std::string & GetFontName() const;

    void SetFontStyle(const PangoStyle font_style);

    PangoStyle GetFontStyle() const;

    void SetFontWeight(const PangoWeight font_weight);

    PangoWeight GetFontWeight() const;

    void SetSize(const gint size);

    gint GetSize() const;

    void SetUnderlined(const bool underlined);

    bool GetUnderlined() const;

    void SetStriken(const bool striken);

    bool GetStriken() const;

    void SetOverlined(const bool overlined);

    bool GetOverlined() const;

    void SetLocation(const QPoint location);

    QPoint GetLocation() const;

    void SetAngle(const int angle);

    int GetAngle() const;

    void
            SetHorizontalReferencePoint(const HorizontalAlignment horizontalReferencePoint);

    HorizontalAlignment GetHorizontalReferencePoint() const;

    void
            SetVerticalReferencePoint(const VerticalAlignment verticalReferencePoint);

    VerticalAlignment GetVerticalReferencePoint() const;

    virtual ~TextInstance();
};*/

#endif /* TEXTINSTANCE_H_ */
