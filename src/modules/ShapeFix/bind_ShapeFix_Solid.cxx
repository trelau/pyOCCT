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
#include <ShapeFix_Root.hxx>
#include <TopoDS_Solid.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Message_ProgressIndicator.hxx>
#include <TopoDS_Shell.hxx>
#include <ShapeExtend_Status.hxx>
#include <TopoDS_Shape.hxx>
#include <ShapeFix_Shell.hxx>
#include <ShapeExtend_BasicMsgRegistrator.hxx>
#include <ShapeFix_Solid.hxx>
#include <Standard_Type.hxx>

void bind_ShapeFix_Solid(py::module &mod){

py::class_<ShapeFix_Solid, opencascade::handle<ShapeFix_Solid>, ShapeFix_Root> cls_ShapeFix_Solid(mod, "ShapeFix_Solid", "Provides method to build a solid from a shells and orients them in order to have a valid solid with finite volume");

// Constructors
cls_ShapeFix_Solid.def(py::init<>());
cls_ShapeFix_Solid.def(py::init<const TopoDS_Solid &>(), py::arg("solid"));

// Fields

// Methods
cls_ShapeFix_Solid.def("Init", (void (ShapeFix_Solid::*)(const TopoDS_Solid &)) &ShapeFix_Solid::Init, "Initializes by solid .", py::arg("solid"));
cls_ShapeFix_Solid.def("Perform", [](ShapeFix_Solid &self) -> Standard_Boolean { return self.Perform(); });
cls_ShapeFix_Solid.def("Perform", (Standard_Boolean (ShapeFix_Solid::*)(const opencascade::handle<Message_ProgressIndicator> &)) &ShapeFix_Solid::Perform, "Iterates on shells and performs fixes (calls ShapeFix_Shell for each subshell). The passed progress indicator allows user to consult the current progress stage and abort algorithm if needed.", py::arg("theProgress"));
cls_ShapeFix_Solid.def("SolidFromShell", (TopoDS_Solid (ShapeFix_Solid::*)(const TopoDS_Shell &)) &ShapeFix_Solid::SolidFromShell, "Calls MakeSolid and orients the solid to be 'not infinite'", py::arg("shell"));
cls_ShapeFix_Solid.def("Status", (Standard_Boolean (ShapeFix_Solid::*)(const ShapeExtend_Status) const) &ShapeFix_Solid::Status, "Returns the status of the last Fix.", py::arg("status"));
cls_ShapeFix_Solid.def("Solid", (TopoDS_Shape (ShapeFix_Solid::*)() const) &ShapeFix_Solid::Solid, "Returns resulting solid.");
cls_ShapeFix_Solid.def("FixShellTool", (opencascade::handle<ShapeFix_Shell> (ShapeFix_Solid::*)() const) &ShapeFix_Solid::FixShellTool, "Returns tool for fixing shells.");
cls_ShapeFix_Solid.def("SetMsgRegistrator", (void (ShapeFix_Solid::*)(const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeFix_Solid::SetMsgRegistrator, "Sets message registrator", py::arg("msgreg"));
cls_ShapeFix_Solid.def("SetPrecision", (void (ShapeFix_Solid::*)(const Standard_Real)) &ShapeFix_Solid::SetPrecision, "Sets basic precision value (also to FixShellTool)", py::arg("preci"));
cls_ShapeFix_Solid.def("SetMinTolerance", (void (ShapeFix_Solid::*)(const Standard_Real)) &ShapeFix_Solid::SetMinTolerance, "Sets minimal allowed tolerance (also to FixShellTool)", py::arg("mintol"));
cls_ShapeFix_Solid.def("SetMaxTolerance", (void (ShapeFix_Solid::*)(const Standard_Real)) &ShapeFix_Solid::SetMaxTolerance, "Sets maximal allowed tolerance (also to FixShellTool)", py::arg("maxtol"));
cls_ShapeFix_Solid.def("FixShellMode", (Standard_Integer & (ShapeFix_Solid::*)()) &ShapeFix_Solid::FixShellMode, "Returns (modifiable) the mode for applying fixes of ShapeFix_Shell, by default True.");
cls_ShapeFix_Solid.def("FixShellOrientationMode", (Standard_Integer & (ShapeFix_Solid::*)()) &ShapeFix_Solid::FixShellOrientationMode, "Returns (modifiable) the mode for applying analysis and fixes of orientation of shells in the solid; by default True.");
cls_ShapeFix_Solid.def("CreateOpenSolidMode", (Standard_Boolean & (ShapeFix_Solid::*)()) &ShapeFix_Solid::CreateOpenSolidMode, "Returns (modifiable) the mode for creation of solids. If mode myCreateOpenSolidMode is equal to true solids are created from open shells else solids are created from closed shells only. ShapeFix_Shell, by default False.");
cls_ShapeFix_Solid.def("Shape", (TopoDS_Shape (ShapeFix_Solid::*)()) &ShapeFix_Solid::Shape, "In case of multiconnexity returns compound of fixed solids else returns one solid.");
cls_ShapeFix_Solid.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Solid::get_type_name, "None");
cls_ShapeFix_Solid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Solid::get_type_descriptor, "None");
cls_ShapeFix_Solid.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Solid::*)() const) &ShapeFix_Solid::DynamicType, "None");

// Enums

}