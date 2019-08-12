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
#include <gp_TrsfForm.hxx>

void bind_gp_TrsfForm(py::module &mod){

py::enum_<gp_TrsfForm>(mod, "gp_TrsfForm", "Identifies the type of a geometric transformation.")
	.value("gp_Identity", gp_TrsfForm::gp_Identity)
	.value("gp_Rotation", gp_TrsfForm::gp_Rotation)
	.value("gp_Translation", gp_TrsfForm::gp_Translation)
	.value("gp_PntMirror", gp_TrsfForm::gp_PntMirror)
	.value("gp_Ax1Mirror", gp_TrsfForm::gp_Ax1Mirror)
	.value("gp_Ax2Mirror", gp_TrsfForm::gp_Ax2Mirror)
	.value("gp_Scale", gp_TrsfForm::gp_Scale)
	.value("gp_CompoundTrsf", gp_TrsfForm::gp_CompoundTrsf)
	.value("gp_Other", gp_TrsfForm::gp_Other)
	.export_values();


}