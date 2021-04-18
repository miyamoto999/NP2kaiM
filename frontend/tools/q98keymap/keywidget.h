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
#ifndef KEYWIDGET_H
#define KEYWIDGET_H

#include <QWidget>
#include <QPaintEvent>

/**
* @brief キーボード表示ウィジェットクラス
* @details
*       キーボード表示ウィジェットクラス
*/
class KeyWidget : public QWidget
{
    Q_OBJECT
public:
    // コンストラクタ
    explicit KeyWidget(QWidget *parent = nullptr);
    // デストラクタ
    ~KeyWidget();

private:
    /**
    * キーボード全体の矩形
    */
    QRect m_keyboardRect;
    /**
    * キーボードのイメージ
    */
    QImage *m_keyboardImage;

    /**
    * マージン
    */
    const int margen = 10;
    /**
    * 表示拡縮率
    */
    double m_rate;
    /**
    * 表示位置の座標
    */
    int m_offx, m_offy;

    // イメージにキーボードを描画する
    void drawKeyboardImage();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;

signals:
    void KeymapClick(int index);

};

#endif // KEYWIDGET_H
