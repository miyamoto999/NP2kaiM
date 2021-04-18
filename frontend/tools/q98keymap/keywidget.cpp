/**
 * @brief キーボード表示ウィジェットクラス
 *
 * PC-98キーボード表示ウィジェットクラス
 *
 * @file
 * @author Masanori Miyamoto.
 * @date 2021/4/18
 * @details
 *      PC-98キーボード表示ウィジェットクラスを定義する。
 * @copyright 2021, Masanori Miyamoto. All rights reserved.
 * @par 変更履歴
 * - 2021/4/18: M.Miyamoto.:
 */
#include "keywidget.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include "keydata.h"

/**
 * @brief コンストラクタ
 * @details
 *      コンストラクタ
 *
 * @param[in] 	    parent      	親ウィジェット
 *
 */
KeyWidget::KeyWidget(QWidget *parent) : QWidget(parent)
{
    m_keyboardRect = keydatas_getKeyboardWhole();

    QSize size(m_keyboardRect.width() + margen * 2, m_keyboardRect.height() + margen * 2);
    m_keyboardImage = new QImage(size, QImage::Format_RGB32);

    drawKeyboardImage();
}

/**
 * @brief デストラクタ
 * @details
 *      デストラクタ
 *
 */
KeyWidget::~KeyWidget()
{
    delete m_keyboardImage;
}

/**
 * @brief キーボードイメージの生成
 * @details
 *      キーボードのイメージを生成する。
 *
 */
void KeyWidget::drawKeyboardImage()
{
    QPainter painter;

    painter.begin(m_keyboardImage);

    painter.setPen(Qt::white);
    painter.fillRect(0, 0, m_keyboardImage->width(), m_keyboardImage->height(), Qt::white);

    int i = 0;
    while(!keydatas[i].keyname.isEmpty()) {
        QRect r = QRect(keydatas[i].rect.x() + margen, keydatas[i].rect.y() + margen, keydatas[i].rect.width(), keydatas[i].rect.height());
        painter.setPen(Qt::black);
        if(keydatas[i].flag & KEYDATA_INPUT_KEY) {
            painter.fillRect(r, Qt::cyan);
        } else if(keydatas[i].flag & KEYDATA_HAVE_DATA) {
            painter.fillRect(r, Qt::yellow);
        } else {
            painter.fillRect(r, Qt::white);
        }
        painter.drawRect(r);
        painter.drawText(r, Qt::AlignCenter, keydatas[i].keytop);
        i++;
    }
    painter.end();
}

/**
 * @brief 描画イベントの処理
 * @details
 *          描画イベント。ウィジェット内に入るようにキーボードイメージを描画する。
 *
 * @param[in] 	   event      描画イベントのパラメータ
 */
void	KeyWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;

    drawKeyboardImage();

    double ratex = (double)this->width() / m_keyboardImage->width();
    double ratey = (double)this->height() / m_keyboardImage->height();
    m_rate = ratex < ratey ? ratex:ratey;
    m_offx = (this->width() - m_keyboardImage->width() * m_rate) / 2;
    m_offy = (this->height() - m_keyboardImage->height() * m_rate) / 2;

    QRect dst(m_offx, m_offy, m_keyboardImage->width() * m_rate, m_keyboardImage->height() * m_rate);
    QRect src(0, 0, m_keyboardImage->width(), m_keyboardImage->height());

    painter.begin(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.drawImage(dst, *m_keyboardImage, src);
    painter.end();
}

/**
 * @brief マウスプレスイベントの処理
 * @details
 *      マウスプレスした座標位置のキーを検索してKeymapClick()シグナルを発生する。
 *
 * @param[in] 	    keyevent      	マウスプレスイベントパラメータ
 *
 */
void KeyWidget::mousePressEvent(QMouseEvent *event)
{
    int x = (int)((double)(event->x() - m_offx) / m_rate - margen);
    int y = (int)((double)(event->y() - m_offy) / m_rate - margen);

    int i = 0;
    while(!keydatas[i].keyname.isEmpty()) {
        if(keydatas[i].rect.contains(x, y)) {
            emit KeymapClick(i);
            break;
        }
        i++;
    }
}

