#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CanvasLabel.reset(new QLabel);
    CanvasLabel->setBackgroundRole(QPalette::Base);
    CanvasLabel->setScaledContents(true);
    ui->scrollArea->setWidget(CanvasLabel.get());

    DrawingLabel.reset(new QLabel);
    DrawingLabel->setBackgroundRole(QPalette::Base);
    CanvasLabel->setScaledContents(true);
    ui->scrollArea_2->setWidget(DrawingLabel.get());

    CanvasImage.reset(new QImage);

    CurrentTextColor = QColor(255,0,0);

    CurrentBackgroundColor = QColor(0,255,0);

    //ui->toolButton->palette().Background


    FontSettings mySettings("Times New Roman",
                                              PANGO_WEIGHT_NORMAL,
                                              20,
                                              0,
                                              0,
                                              2,
                                              true,
                                              true,
                                              true);

    drawer.reset(new TextDrawer(mySettings,
                                                    QColor(255,0,0),
                                                    QColor(0,255,0),
                                                    Left,
                                                    Upper));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    QPainter painter(CanvasImage.get());
    int x = ui->xField->text().toInt();
    int y = ui->yField->text().toInt();
    DrawOnImageWithCurrentSettings(painter,QPoint(x,y));
    CanvasLabel->setPixmap(QPixmap::fromImage(*CanvasImage));
}



void MainWindow::on_openAct_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                    tr("Open File"), QDir::currentPath());
    if (!fileName.isEmpty()) {
        CanvasImage.reset(new QImage(fileName));
        if (CanvasImage->isNull()) {
            QMessageBox::information(this, tr("Image Viewer"),
                                     tr("Cannot load %1.").arg(fileName));

            return;
        }

        CanvasLabel->setPixmap(QPixmap::fromImage(*CanvasImage));

        scaleFactor = 1.0;


        ui->fitToWindowAct->setEnabled(true);
        updateActions();


        //if (!ui->fitToWindowAct->isChecked())
//             DrawingLabel->adjustSize();
    }

}



void MainWindow::updateActions()
{
    ui->zoomInAct->setEnabled(!ui->fitToWindowAct->isChecked());
    ui->zoomOutAct->setEnabled(!ui->fitToWindowAct->isChecked());
    ui->normalSizeAct->setEnabled(!ui->fitToWindowAct->isChecked());
}



void MainWindow::scaleImage(double factor)
{
    Q_ASSERT(CanvasLabel->pixmap());
    scaleFactor *= factor;
    CanvasLabel->resize(scaleFactor * CanvasLabel->pixmap()->size());

    adjustScrollBar(ui->scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(ui->scrollArea->verticalScrollBar(), factor);

    ui->zoomInAct->setEnabled(scaleFactor < 3.0);
    ui->zoomOutAct->setEnabled(scaleFactor > 0.333);
}

void MainWindow::on_zoomInAct_triggered()
{
    scaleImage(1.25);
}

void MainWindow::on_zoomOutAct_triggered()
{
    scaleImage(0.75);
}

void MainWindow::on_fitToWindowAct_triggered()
{
    bool fitToWindow = ui->fitToWindowAct->isChecked();
    ui->scrollArea->setWidgetResizable(fitToWindow);
    if (!fitToWindow) {
        on_normalSizeAct_triggered();
    }
    updateActions();
}

void MainWindow::on_normalSizeAct_triggered()
{
    CanvasLabel->adjustSize();
    scaleFactor = 1.0;
}



void MainWindow::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}



void MainWindow::RedrawDrawingLabel()
{
    DrawingImage.reset(new QImage(500,500,QImage::Format_RGB32));
    DrawingImage->fill(150);
    QPainter painter(DrawingImage.get());


    DrawOnImageWithCurrentSettings(painter, QPoint(10,10));


    DrawingLabel->setPixmap(QPixmap::fromImage(*DrawingImage));

}



void MainWindow::DrawOnImageWithCurrentSettings(QPainter &painter, const QPoint &position)
{
    FontSettings mySettings(ui->fontComboBox->currentFont().family().toStdString(),
                                          PangoWeight(ui->spinBox_Weight->value()),
                                          ui->spinBox_Height->value(),
                                          ui->spinBox_Width->value(),
                                          ui->dial_Escapement->value(),
                                          ui->dial_Orientation->value(),
                                          ui->checkBox_Underlined->isChecked(),
                                          ui->checkBox_Stricken->isChecked(),
                                          ui->checkBox_Overlined->isChecked());



    drawer->SetFontParametrs(mySettings);
    if (ui->radioButton_DrawText->isChecked())
        drawer->DrawLetters(&painter, ui->textField_TextItself->text().utf16(), position);
    else if(ui->radioButton_DrawGlyphs->isChecked())
        drawer->DrawLetters(&painter, &(*GlyphIndexes)[0], position);
}



void MainWindow::on_fontComboBox_textChanged(QString )
{
    RedrawDrawingLabel();
}


void MainWindow::on_fontComboBox_currentIndexChanged(QString )
{
        RedrawDrawingLabel();
}



void MainWindow::on_ChangeColorButton_clicked()
{
    QColor cl = QColorDialog::getColor(QColor(0,0,0),this);
    drawer->FontColor = cl;
    RedrawDrawingLabel();
}


void MainWindow::on_spinBox_Height_valueChanged(int )
{
    RedrawDrawingLabel();
}

void MainWindow::on_textField_TextItself_textChanged(QString )
{
    RedrawDrawingLabel();
}

void MainWindow::on_spinBox_Width_valueChanged(int )
{
    RedrawDrawingLabel();
}

void MainWindow::on_spinBox_Weight_valueChanged(int )
{
    RedrawDrawingLabel();
}

void MainWindow::on_dial_Escapement_valueChanged(int)
{
    RedrawDrawingLabel();
}

void MainWindow::on_dial_Orientation_valueChanged(int)
{
    RedrawDrawingLabel();

}

void MainWindow::on_checkBox_Overlined_stateChanged(int )
{
    RedrawDrawingLabel();
}

void MainWindow::on_checkBox_Stricken_stateChanged(int )
{
    RedrawDrawingLabel();
}

void MainWindow::on_checkBox_Underlined_stateChanged(int )
{
    RedrawDrawingLabel();
}


void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                    tr("Open File"), QDir::currentPath());

    if (!fileName.isEmpty())
    {
        GlyphIndexes = readIntVectorFromFile(fileName);
    }

    ui->radioButton_DrawGlyphs->setEnabled(true);
    ui->radioButton_DrawGlyphs->setChecked(true);
    RedrawDrawingLabel();
}

void MainWindow::on_radioButton_DrawText_toggled(bool)
{
    RedrawDrawingLabel();
}

void MainWindow::on_radioButton_DrawGlyphs_toggled(bool)
{
    RedrawDrawingLabel();
}

void MainWindow::on_SaveAct_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                                      tr("Save File"), QDir::currentPath());

    if (!filename.isEmpty())
    {
        CanvasImage->save(filename,0,0);
    }

}

void MainWindow::on_pushButton_addRectangleToRegion_clicked()
{
    cairo_rectangle_t newRectangle;
    int allConversionsStatus = 0;
    bool lastConversionStatus = false;

    const int numberOfConversions = 4;

    newRectangle.x = ui->lineEdit_rectangleX->text().toInt(&lastConversionStatus);
    allConversionsStatus += lastConversionStatus;
    newRectangle.y = ui->lineEdit_rectangleY->text().toInt(&lastConversionStatus);
    allConversionsStatus += lastConversionStatus;
    newRectangle.width = ui->lineEdit_rectangleWidth->text().toInt(&lastConversionStatus);
    allConversionsStatus += lastConversionStatus;
    newRectangle.height = ui->lineEdit_rectangleHeight->text().toInt(&lastConversionStatus);
    allConversionsStatus += lastConversionStatus;

    if (allConversionsStatus == numberOfConversions)
    {
        drawer->AddClipRegion(newRectangle);
    }


}

void MainWindow::on_pushButton_3_clicked()
{
    DrawingImage.reset(new QImage(500,500,QImage::Format_RGB32));
    DrawingImage->fill(150);
    QPainter painter(DrawingImage.get());




    FontSettings mySettings("Sehnsecht Font Made By: AiR",
                                          PangoWeight(ui->spinBox_Weight->value()),
                                          ui->spinBox_Height->value(),
                                          ui->spinBox_Width->value(),
                                          ui->dial_Escapement->value(),
                                          ui->dial_Orientation->value(),
                                          ui->checkBox_Underlined->isChecked(),
                                          ui->checkBox_Stricken->isChecked(),
                                          ui->checkBox_Overlined->isChecked());



    //drawer->SetFontParametrs(mySettings);

    if (ui->radioButton_DrawText->isChecked())
        drawer->DrawLetters(&painter, ui->textField_TextItself->text().utf16(), QPoint(10,10));


    DrawingLabel->setPixmap(QPixmap::fromImage(*DrawingImage));


     bool ok;
    FcConfigAppFontAddFile(NULL, (FcChar8*)"/home/pasha/qt_workspace/Panguin/Panguin/sehnsecht_font.TTF");
    //QFont font = QFontDialog::getFont(&ok, QFont("Times", 12), this);
    QFont f;
    f.setFamily("Sehnsecht Font Made By: AiR");
    qDebug("sdasdasd:%d",f.exactMatch());

    QPainter painter2(CanvasImage.get());




    FontSettings mySettings1("Sehnsecht Font Made By: AiR",
                                          PangoWeight(ui->spinBox_Weight->value()),
                                          ui->spinBox_Height->value(),
                                          ui->spinBox_Width->value(),
                                          ui->dial_Escapement->value(),
                                          ui->dial_Orientation->value(),
                                          ui->checkBox_Underlined->isChecked(),
                                          ui->checkBox_Stricken->isChecked(),
                                          ui->checkBox_Overlined->isChecked());



    drawer->SetFontParametrs(mySettings1);

    if (ui->radioButton_DrawText->isChecked())
        drawer->DrawLetters(&painter2, ui->textField_TextItself->text().utf16(), QPoint(10,10));


    CanvasLabel->setPixmap(QPixmap::fromImage(*CanvasImage));
    //ui->fontComboBox->insertItem(;
}
