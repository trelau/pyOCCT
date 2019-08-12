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
#include <IFSelect_EditValue.hxx>

void bind_IFSelect_EditValue(py::module &mod){

py::enum_<IFSelect_EditValue>(mod, "IFSelect_EditValue", "Controls access on Values by an Editor EditOptional : normal access, in addition may be removed Editable : normal access, must be present EditProtected : access must be validated EditComputed : why write it ? it will be recomputed EditRead : no way to write it, only for read EditDynamic : not a field, only to be displayed")
	.value("IFSelect_Optional", IFSelect_EditValue::IFSelect_Optional)
	.value("IFSelect_Editable", IFSelect_EditValue::IFSelect_Editable)
	.value("IFSelect_EditProtected", IFSelect_EditValue::IFSelect_EditProtected)
	.value("IFSelect_EditComputed", IFSelect_EditValue::IFSelect_EditComputed)
	.value("IFSelect_EditRead", IFSelect_EditValue::IFSelect_EditRead)
	.value("IFSelect_EditDynamic", IFSelect_EditValue::IFSelect_EditDynamic)
	.export_values();


}