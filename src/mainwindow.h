#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "TextDrawer.h"
#include "TextInstance.h"
#include "readFromFile.h"
#include <memory>
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#include <QScrollBar>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>
#endif


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    double scaleFactor;

    std::auto_ptr<TextDrawer> drawer;
    //FontSettings CurrentFontSettings;
    QColor CurrentTextColor;
    QColor CurrentBackgroundColor;

    std::auto_ptr< std::vector<unsigned int> > GlyphIndexes;

    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);
    void updateActions();
    void RedrawDrawingLabel();
    void DrawOnImageWithCurrentSettings(QPainter & painter, const QPoint & position);

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    std::auto_ptr<QImage> DrawingImage;
    std::auto_ptr<QImage> CanvasImage;
    std::auto_ptr<QLabel> DrawingLabel;
    std::auto_ptr<QLabel> CanvasLabel;

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_addRectangleToRegion_clicked();
    void on_SaveAct_triggered();
    void on_radioButton_DrawGlyphs_toggled(bool checked);
    void on_radioButton_DrawText_toggled(bool checked);
    void on_pushButton_2_clicked();
    void on_checkBox_Underlined_stateChanged(int );
    void on_checkBox_Stricken_stateChanged(int );
    void on_checkBox_Overlined_stateChanged(int );
    void on_dial_Orientation_valueChanged(int value);
    void on_dial_Escapement_valueChanged(int value);
    void on_spinBox_Weight_valueChanged(int );
    void on_spinBox_Width_valueChanged(int );
    void on_textField_TextItself_textChanged(QString );
    void on_spinBox_Height_valueChanged(int );
    void on_ChangeColorButton_clicked();
    void on_fontComboBox_currentIndexChanged(QString );
    void on_fontComboBox_textChanged(QString );
    void on_normalSizeAct_triggered();
    void on_fitToWindowAct_triggered();
    void on_zoomOutAct_triggered();
    void on_zoomInAct_triggered();
    void on_openAct_triggered();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
