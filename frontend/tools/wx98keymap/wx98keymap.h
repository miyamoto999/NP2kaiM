/**
 * @brief メインウィンドウクラス
 *
 *　メインウィンドウクラス
 *
 * @file
 * @author Masanori Miyamoto.
 * @date 2021/5/22
 * @details
 *      メインウィンドウクラスを定義する。
 * @copyright 2021, Masanori Miyamoto. All rights reserved.
 *
 * @par 変更履歴
 * - 2021/5/22: M.Miyamoto.:
 */
#ifndef __WX98KEYMAP_H__
#define __WX98KEYMAP_H__

#include "wx98keymapForms.h"
#include "keywidget.h"

/**
* @brief メインウィンドウクラス
* @details
*       メインウィンドウクラス
*/
class wx98keymap : public wx98keymapBase
{
private:
	/**
	 * @brief オープンしてるファイルのファイル名
	 */
	wxString m_openFilename;

protected:
	virtual void OnKeyUp( wxKeyEvent& event );
	virtual void OnKeyDown( wxKeyEvent& event );
	virtual void OnMenuOpen( wxCommandEvent& event );
	virtual void OnMenuSave( wxCommandEvent& event );
	virtual void OnMenuSaveAs( wxCommandEvent& event );
	virtual void OnMenuClose( wxCommandEvent& event );
	virtual void OnMenuQuit( wxCommandEvent& event );
	virtual void OnClose( wxCloseEvent& event );

	void OnKeymapClick(KeymapClickEvent &event);

public:
	wx98keymap(wxWindow* parent);
	~wx98keymap();
};


#endif