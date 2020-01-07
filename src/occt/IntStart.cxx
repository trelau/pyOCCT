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
#include <Standard_Transient.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Std.hxx>
#include <IntStart_SITopolTool.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>

PYBIND11_MODULE(IntStart, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.gp");

// CLASS: INTSTART_SITOPOLTOOL
py::class_<IntStart_SITopolTool, opencascade::handle<IntStart_SITopolTool>, Standard_Transient> cls_IntStart_SITopolTool(mod, "IntStart_SITopolTool", "template class for a topological tool. This tool is linked with the surface on which the classification has to be made.");

// Methods
cls_IntStart_SITopolTool.def("Classify", (TopAbs_State (IntStart_SITopolTool::*)(const gp_Pnt2d &, const Standard_Real)) &IntStart_SITopolTool::Classify, "None", py::arg("P"), py::arg("Tol"));
cls_IntStart_SITopolTool.def_static("get_type_name_", (const char * (*)()) &IntStart_SITopolTool::get_type_name, "None");
cls_IntStart_SITopolTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntStart_SITopolTool::get_type_descriptor, "None");
cls_IntStart_SITopolTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntStart_SITopolTool::*)() const) &IntStart_SITopolTool::DynamicType, "None");


}
