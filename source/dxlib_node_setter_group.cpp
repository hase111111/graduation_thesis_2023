﻿
//! @author    Hasegawa
//! @copyright (C) 2023 Design Engineering Laboratory, Saitama University All right reserved.

#include "dxlib_node_setter_group.h"

#include "cassert_define.h"


namespace designlab
{

void DxlibNodeSetterGroup::Register(const std::shared_ptr<IDxlibNodeSetter>& setter)
{
    assert(setter != nullptr);

    setters_.push_back(setter);
}

void DxlibNodeSetterGroup::SetNode(const RobotStateNode& node)
{
    for (auto& setter : setters_)
    {
        setter->SetNode(node);
    }
}

}  // namespace designlab
