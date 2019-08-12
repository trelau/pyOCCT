/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <V3d_TypeOfOrientation.hxx>

void bind_V3d_TypeOfOrientation(py::module &mod){

py::enum_<V3d_TypeOfOrientation>(mod, "V3d_TypeOfOrientation", "Determines the type of orientation.")
	.value("V3d_Xpos", V3d_TypeOfOrientation::V3d_Xpos)
	.value("V3d_Ypos", V3d_TypeOfOrientation::V3d_Ypos)
	.value("V3d_Zpos", V3d_TypeOfOrientation::V3d_Zpos)
	.value("V3d_Xneg", V3d_TypeOfOrientation::V3d_Xneg)
	.value("V3d_Yneg", V3d_TypeOfOrientation::V3d_Yneg)
	.value("V3d_Zneg", V3d_TypeOfOrientation::V3d_Zneg)
	.value("V3d_XposYpos", V3d_TypeOfOrientation::V3d_XposYpos)
	.value("V3d_XposZpos", V3d_TypeOfOrientation::V3d_XposZpos)
	.value("V3d_YposZpos", V3d_TypeOfOrientation::V3d_YposZpos)
	.value("V3d_XnegYneg", V3d_TypeOfOrientation::V3d_XnegYneg)
	.value("V3d_XnegYpos", V3d_TypeOfOrientation::V3d_XnegYpos)
	.value("V3d_XnegZneg", V3d_TypeOfOrientation::V3d_XnegZneg)
	.value("V3d_XnegZpos", V3d_TypeOfOrientation::V3d_XnegZpos)
	.value("V3d_YnegZneg", V3d_TypeOfOrientation::V3d_YnegZneg)
	.value("V3d_YnegZpos", V3d_TypeOfOrientation::V3d_YnegZpos)
	.value("V3d_XposYneg", V3d_TypeOfOrientation::V3d_XposYneg)
	.value("V3d_XposZneg", V3d_TypeOfOrientation::V3d_XposZneg)
	.value("V3d_YposZneg", V3d_TypeOfOrientation::V3d_YposZneg)
	.value("V3d_XposYposZpos", V3d_TypeOfOrientation::V3d_XposYposZpos)
	.value("V3d_XposYnegZpos", V3d_TypeOfOrientation::V3d_XposYnegZpos)
	.value("V3d_XposYposZneg", V3d_TypeOfOrientation::V3d_XposYposZneg)
	.value("V3d_XnegYposZpos", V3d_TypeOfOrientation::V3d_XnegYposZpos)
	.value("V3d_XposYnegZneg", V3d_TypeOfOrientation::V3d_XposYnegZneg)
	.value("V3d_XnegYposZneg", V3d_TypeOfOrientation::V3d_XnegYposZneg)
	.value("V3d_XnegYnegZpos", V3d_TypeOfOrientation::V3d_XnegYnegZpos)
	.value("V3d_XnegYnegZneg", V3d_TypeOfOrientation::V3d_XnegYnegZneg)
	.export_values();


}