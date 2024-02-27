﻿
//! @file      boot_mode.h
//! @author    Hasegawa
//! @copyright © 埼玉大学 設計工学研究室 2023. All right reserved.

#ifndef DESIGNLAB_BOOT_MODE_H_
#define DESIGNLAB_BOOT_MODE_H_


namespace designlab::enums
{

//! @enum BootMode
//! @brief 起動モードを表す列挙型．
//! @see BootModeSelector
enum class BootMode : int
{
    kSimulation = 0,    //!< シミュレーションモード．
    kViewer,            //!< ビューワーモード．
    kDisplayModel,      //!< ディスプレイモード．
    kResultViewer,      //!< リザルトビューワーモード．
    kRobotControl,      //!< ロボットコントロールモード．
};

}  // namespace designlab::enums


#endif  // DESIGNLAB_BOOT_MODE_H_