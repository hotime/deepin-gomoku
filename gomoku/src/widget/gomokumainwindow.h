/*
   * Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd.
   *
   * Author:     zhengxiaokang <zhengxiaokang@uniontech.com>
   *
   * Maintainer: zhengxiaokang <zhengxiaokang@uniontech.com>
   *
   * This program is free software: you can redistribute it and/or modify
   * it under the terms of the GNU General Public License as published by
   * the Free Software Foundation, either version 3 of the License, or
   * any later version.
   *
   * This program is distributed in the hope that it will be useful,
   * but WITHOUT ANY WARRANTY; without even the implied warranty of
   * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   * GNU General Public License for more details.
   *
   * You should have received a copy of the GNU General Public License
   * along with this program.  If not, see <http://www.gnu.org/licenses/>.
   */
#ifndef GOMOKUMAINWINDOW_H
#define GOMOKUMAINWINDOW_H

#include "checkerboard/checkerboardscene.h"
#include "judge/gamecontrol.h"

#include <DMainWindow>

DWIDGET_USE_NAMESPACE

class GomokuMainWindow : public DMainWindow
{
    Q_OBJECT
public:
    explicit GomokuMainWindow(QWidget *parent = nullptr);
    ~GomokuMainWindow() override;

public:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void initUI();
    void initGame();
    void paintTitleBar(QWidget *titlebar);
    /**
     * @brief playWinMusic 播放胜利音乐
     */
    void playWinMusic();
    /**
     * @brief playFailMusic 播放失败音乐
     */
    void playFailMusic();

private slots:
    /**
     * @brief slotPopupResult 游戏结果弹窗
     * @param result 游戏结果
     */
    void slotPopupResult(ChessResult result);

private:
    DTitlebar *mTitleBar = nullptr;
    CheckerboardScene *checkerboardScene = nullptr;
    int userChess; //用户棋子颜色
    bool musicControlStatus = true; //是否可以播放音乐
};

#endif // GOMOKUMAINWINDOW_H
